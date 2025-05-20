/*
 * spk.c
 *
 *  Created on: May 19, 2025
 *      Author: Flori
 */

#include "pwm.h"
#include "spk.h"

extern TIM_HandleTypeDef htim2;

// Exemple d'émission d'une onde sonore sur un haut-parleur
void speaker_tone(uint32_t frequency_hz) {
  set_pwm_device(&htim2, TIM_CHANNEL_3, frequency_hz, 50);  // 50 % duty pour signal carré
}

// Pour arrêter le son
void speaker_off(void) {
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
}
