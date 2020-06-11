// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool_effect2)
RGB_MATRIX_EFFECT(custom_effect2)
RGB_MATRIX_EFFECT(custom_seesaw)
RGB_MATRIX_EFFECT(custom_seesaw_vertical)
RGB_MATRIX_EFFECT(heartbeat)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max)

    //rgb_matrix_set_color(23, 0xff, 0xff, 0xff);


/*
  //P
  for (uint8_t i = 0; i <= 24; i++) {
    rgb_matrix_set_color(i, 0x70, 0x00, 0x70);
  }
  //B
  for (uint8_t i = 36; i <= 67; i++) {
    rgb_matrix_set_color(i, 0x00, 0x00, 0x70);
  }
*/

  /*
  //B
  for (uint8_t i = 9; i <= 23; i++) {
    rgb_matrix_set_color(i, 0x40, 0x40, 0xff);
  }
  //P
  for (uint8_t i = 0; i <= 7; i++) {
    rgb_matrix_set_color(i, 0xff, 0x50, 0xff);
  }
  for (uint8_t i = 26; i <= 31; i++) {
    rgb_matrix_set_color(i, 0xff, 0x50, 0xff);
  }
    rgb_matrix_set_color(24, 0xff, 0x50, 0xff);
  //W
  for (uint8_t i = 43; i <= 48; i++) {
    rgb_matrix_set_color(i, 0xef, 0xff, 0xef);
  }
  for (uint8_t i = 51; i <= 56; i++) {
    rgb_matrix_set_color(i, 0xef, 0xff, 0xef);
  }
    rgb_matrix_set_color(25, 0xef, 0xff, 0xef);
    rgb_matrix_set_color(8, 0xef, 0xff, 0xef);
  //P
  for (uint8_t i = 36; i <= 49; i++) {
    rgb_matrix_set_color(i, 0xff, 0x50, 0xff);
  }
  for (uint8_t i = 57; i <= 63; i++) {
    rgb_matrix_set_color(i, 0xff, 0x50, 0xff);
  }
    rgb_matrix_set_color(32, 0xff, 0x50, 0xff);
  //B
  for (uint8_t i = 64; i <= 67; i++) {
    rgb_matrix_set_color(i, 0x50, 0x50, 0xff);
  }
  for (uint8_t i = 33; i <= 35; i++) {
    rgb_matrix_set_color(i, 0x50, 0x50, 0xff);
  }
  rgb_matrix_set_color(41, 0x40, 0x40, 0xff);
  rgb_matrix_set_color(42, 0x40, 0x40, 0xff);
  rgb_matrix_set_color(50, 0x40, 0x40, 0xff);
  */
  return led_max < DRIVER_LED_TOTAL;
}

// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods
static uint32_t some_global_state;
static uint8_t direction;

static void my_cool_effect2_complex_init(effect_params_t* params) {
  some_global_state = 0;
  direction = 0;
}
static bool my_cool_effect2_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);


  if(direction == 0) {
    some_global_state++;
  }
  if(direction == 1){
      some_global_state--;
  }
  if (some_global_state > (50*10)){
      direction = 1;
  }
  if (some_global_state < 1){
      direction = 0;
  }
  uint8_t value = some_global_state / 10;
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, value,0x00,0x10);
  }


  return led_max < DRIVER_LED_TOTAL;
}
static bool my_cool_effect2(effect_params_t* params) {
  if (params->init) my_cool_effect2_complex_init(params);
  return my_cool_effect2_complex_run(params);
}


static HSV custom_effect2_math(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    hsv.h = 5-(4*dy/3);
    return hsv;
}

bool custom_effect2(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_effect2_math);
}

static HSV custom_seesaw_math(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    uint16_t middle = (MATRIX_ROWS/2);
    int16_t coord = ((dx-middle)/2);
    hsv.h = (coord*(127-cos8(time))/127)+ rgb_matrix_config.hsv.h;
    return hsv;
}

bool custom_seesaw(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_seesaw_math);
}


static HSV custom_seesaw_vertical_math(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    uint16_t middle = (MATRIX_COLS/2);
    int16_t coord = ((dy-middle)/2);
    hsv.h = (coord*(127-cos8(time))/127)+ rgb_matrix_config.hsv.h;
    return hsv;
}

bool custom_seesaw_vertical(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_seesaw_vertical_math);
}

static HSV heartbeat_math(HSV hsv, uint8_t i, uint8_t time){
    uint8_t heartbeat[256] ={ 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39, 39, 39, 40, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 52, 53, 55, 56, 57, 57, 58, 58, 58, 57, 57, 56, 55, 53, 52, 50, 49, 48, 46, 45, 44, 43, 42, 41, 40, 39, 39, 38, 37, 37, 36, 35, 34, 33, 31, 30, 28, 26, 23, 21, 18, 16, 13, 11, 10, 9, 9, 10, 13, 18, 24, 33, 44, 57, 73, 90, 110, 130, 152, 175, 197, 218, 238, 216, 193, 169, 145, 122, 100, 79, 61, 45, 32, 21, 13, 6, 3, 0, 0, 1, 3, 5, 8, 11, 15, 18, 21, 24, 26, 28, 30, 32, 33, 34, 35, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39, 39, 39, 40, 41, 42, 43, 44, 46, 48, 50, 53, 56, 59, 62, 66, 69, 73, 76, 80, 82, 85, 86, 87, 88, 87, 86, 85, 82, 80, 76, 73, 69, 66, 62, 59, 56, 53, 50, 48, 46, 44, 43, 42, 41, 40, 39, 39, 39, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38};
    hsv.v = heartbeat[time];
    return hsv;
}
bool heartbeat(effect_params_t* params){
    return effect_runner_i(params, &heartbeat_math);

}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
