#include "rev4.h"

void matrix_init_kb(void) {
    led_init_ports();

    matrix_init_user();
}

void led_init_ports() {
    // Set our LED pins as output
<<<<<<< HEAD
<<<<<<< HEAD
    setPinOutput(B13); // LED1
    writePinLow(B13);

    setPinOutput(B14); // LED2
    writePinLow(B14);

    setPinOutput(B8); // LED3
    writePinLow(B8);

    setPinOutput(B0); // Capslock LED
    writePinLow(B0);
=======
    palSetPadMode(GPIOB, 13, PAL_MODE_OUTPUT_PUSHPULL); // LED1
    palClearPad(GPIOB, 13);
    palSetPadMode(GPIOB, 14, PAL_MODE_OUTPUT_PUSHPULL); // LED2
    palClearPad(GPIOB, 14);
    palSetPadMode(GPIOA, 8, PAL_MODE_OUTPUT_PUSHPULL); // LED3
    palClearPad(GPIOA, 8);
    palSetPadMode(GPIOA, 0, PAL_MODE_OUTPUT_PUSHPULL); // Capslock LED
    palClearPad(GPIOA, 0);
>>>>>>> upstream/master
=======
    setPinOutput(B13); // LED1
    writePinLow(B13);
    setPinOutput(B14); // LED2
    writePinLow(B14);
    setPinOutput(A8); // LED3
    writePinLow(A8);
    setPinOutput(A0); // Capslock LED
    writePinLow(A0);
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        writePin(B13, led_state.num_lock);
        writePin(A0, led_state.caps_lock);
        writePin(B14, led_state.caps_lock);
        writePin(A8, led_state.scroll_lock);
    }
    return res;
}
