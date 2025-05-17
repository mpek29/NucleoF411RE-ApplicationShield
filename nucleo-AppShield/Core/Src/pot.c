/*
 * pot.c - Potentiometer reading via ADC
 * Created: 2025-04-17
 * Author: Flori
 * Refactored to comply with GNU coding standards and conventions
 */

#include "pot.h"
#include "adc.h"   /* Access to hadc1 */

extern ADC_HandleTypeDef hadc1;

/*
 * Perform ADC conversion on the specified channel and store the result.
 * This function is static and limited to this compilation unit.
 *
 * @param[out] value  Pointer to the variable receiving the ADC value.
 * @param[in]  channel    ADC channel to configure and read.
 */
void read_adc(uint32_t *value, uint32_t channel)
{
    ADC_ChannelConfTypeDef s_config = {0};

    s_config.Channel = channel;
    s_config.Rank = 1;
    s_config.SamplingTime = ADC_SAMPLETIME_3CYCLES; /* Per CubeMX configuration */

    if (HAL_ADC_ConfigChannel(&hadc1, &s_config) != HAL_OK) {
        Error_Handler();
    }

    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK) {
        *value = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);
}

/* Read potentiometer connected to ADC channel 0 (e.g., PA0) */
void pot_1(uint32_t *value_pot)
{
    read_adc(value_pot, ADC_CHANNEL_0);
}

/* Read potentiometer connected to ADC channel 1 (e.g., PA1) */
void pot_2(uint32_t *value_pot)
{
    read_adc(value_pot, ADC_CHANNEL_1);
}

/* Read both potentiometers and store results in provided array */
void pots(uint32_t values[2])
{
    pot_1(&values[0]);
    pot_2(&values[1]);
}
