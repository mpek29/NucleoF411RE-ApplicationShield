/* leds.h - Interface for RGB LED control using PWM
   Created: April 12, 2025
   Author: Flori (refactored per GNU standards)
*/

#ifndef INC_LEDS_H_
#define INC_LEDS_H_

#include <stdint.h>
#include <main.h>

/* Set the brightness of the red LED.
   BRIGHTNESS: value in percent (0–100), clamped internally.  */
void red_led (int8_t brightness);

/* Set the brightness of the green LED.
   BRIGHTNESS: value in percent (0–100), clamped internally.  */
void green_led (int8_t brightness);

/* Set the brightness of the blue LED.
   BRIGHTNESS: value in percent (0–100), clamped internally.  */
void blue_led (int8_t brightness);

/* Set the brightness of all RGB LEDs equally.
   BRIGHTNESS: value in percent (0–100), clamped internally.  */
void leds (int8_t brightness);

void leds_rgb(uint8_t R, uint8_t G, uint8_t B);
#endif /* LEDS_H */
