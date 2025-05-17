/*
 * pot.h - Potentiometer ADC interface header
 * Created: 2025-05-17
 * Author: Flori
 * Description: Public interface for reading potentiometer values using ADC.
 */

#ifndef INC_POT_H_
#define INC_POT_H_

#include <stdint.h>
/*
 * Perform ADC conversion on the specified channel and store the result.
 * This function is static and limited to this compilation unit.
 *
 * @param[out] value  Pointer to the variable receiving the ADC value.
 * @param[in]  channel    ADC channel to configure and read.
 */
void read_adc(uint32_t *value, uint32_t channel);

/* Read potentiometer connected to ADC channel 0 (e.g., PA0) */
void pot_1(uint32_t *value_pot);

/* Read potentiometer connected to ADC channel 1 (e.g., PA1) */
void pot_2(uint32_t *value_pot);

/* Read both potentiometers and store results in provided array */
void pots(uint32_t values[2]);


#endif /* INC_POT_H_ */
