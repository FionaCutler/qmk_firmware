#include "ymd75.h"
<<<<<<< HEAD

void keyboard_pre_init_kb(void) {
    led_init_ports();
    keyboard_pre_init_user();
}

void led_init_ports(void) {
    setPinOutput(D1);
    writePinHigh(D1);
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        writePin(D1, !led_state.caps_lock);
    }
    return true;
}
=======
>>>>>>> upstream/master
