/*
 * pwm.c
 *
 *  Created on: May 19, 2025
 *      Author: Flori
 */

#include "pwm.h"

// Configure le PWM avec fréquence (Hz) et duty cycle (%).
void set_pwm_device(TIM_HandleTypeDef *htim, uint32_t channel, uint32_t freq_hz, uint8_t duty_percent) {
    if (freq_hz == 0 || duty_percent > 100) return;  // Paramètres invalides

    // Récupère la fréquence d’horloge du timer (ici on suppose APB1 x2 pour TIM2/3/4/5, sinon adapter)
    uint32_t timer_clk = HAL_RCC_GetPCLK1Freq() * 2;

    // Calcule l'auto-reload value (ARR) pour la fréquence souhaitée
    uint32_t arr = (timer_clk / freq_hz) - 1;

    // Met à jour le registre ARR
    __HAL_TIM_SET_AUTORELOAD(htim, arr);

    // Calcule la valeur du registre CCR (rapport cyclique)
    uint32_t pulse = (arr + 1) * duty_percent / 100;

    // Démarre le PWM
    HAL_TIM_PWM_Start(htim, channel);

    // Met à jour la valeur du duty cycle
    __HAL_TIM_SET_COMPARE(htim, channel, pulse);
}

