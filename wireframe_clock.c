#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define DIGITS_GPIO_START 8 // 8-15 inclusive
#define COLON_GPIO 7
#define DEGREE_GPIO 6
#define DIGIT_CONTROL_GPIO_START 18 // 18-21 inclusive

#define LED_PIN 25

int main() {

    // INIT HARDWARE ---------------------------------------------------------------

    // init serial connection
    stdio_init_all();

    // init rev indicator LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // init 7 seg gpios
    // for (int gpio = SEG_FIRST_GPIO; gpio < SEG_FIRST_GPIO + 14; gpio++) {
    //     gpio_init(gpio);
    //     gpio_set_dir(gpio, GPIO_OUT);
    // }

}