#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define DIGITS_GPIO_START 8 // 8-15 inclusive
#define COLON_GPIO 7
#define DEGREE_GPIO 6
#define DIGIT_CONTROL_GPIO_START 18 // 18-21 inclusive

#define LATCH_TIME 100 // milliseconds

#define LED_PIN PICO_DEFAULT_LED_PIN

void set_digit(char digit, char value) {
    if (digit >= 0 && digit < 4) {
        // make sure state is reset
        for (int gpio = DIGIT_CONTROL_GPIO_START; gpio < DIGIT_CONTROL_GPIO_START + 4; gpio++) {
            gpio_put(gpio, 0);
        }
        char segments = 0b11101110;
        for (char x = 0; x < 8; x++) {
            gpio_put(DIGITS_GPIO_START+x, (segments>>x)&1);
        }
        gpio_put(DIGIT_CONTROL_GPIO_START+digit, 1);
        sleep_ms(LATCH_TIME);
        gpio_put(DIGIT_CONTROL_GPIO_START+digit, 0);
    }
}

int main() {
    // init serial connection
    stdio_init_all();

    // init rev indicator LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // init 7 seg gpios
    for (int gpio = DIGITS_GPIO_START; gpio < DIGITS_GPIO_START + 8; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);
    }
    //init colon and degreese
    gpio_init(COLON_GPIO);
    gpio_set_dir(COLON_GPIO, GPIO_OUT);
    gpio_put(COLON_GPIO, 1);
    gpio_init(DEGREE_GPIO);
    gpio_set_dir(DEGREE_GPIO, GPIO_OUT);
    gpio_put(DEGREE_GPIO, 0); // TODO change
    // init digit control
    for (int gpio = DIGIT_CONTROL_GPIO_START; gpio < DIGIT_CONTROL_GPIO_START + 4; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);
    }

    set_digit(0, 0);

}