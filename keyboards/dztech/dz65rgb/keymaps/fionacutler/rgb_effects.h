// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool_effect2)
RGB_MATRIX_EFFECT(custom_effect)
RGB_MATRIX_EFFECT(custom_effect2)
RGB_MATRIX_EFFECT(custom_effect3)
RGB_MATRIX_EFFECT(custom_seesaw)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max)

    rgb_matrix_set_color(23, 0xff, 0xff, 0xff);


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


static void custom_effect_math(HSV* hsv, int16_t dx, int16_t dy, uint8_t time) {
    int16_t coord = ((8-dx)/2);
    hsv->h = (coord*(127-cos8(time))/127) + 200;
}

bool custom_effect(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_effect_math);
}


static void custom_effect2_math(HSV* hsv, int16_t dx, int16_t dy, uint8_t time) {
    hsv->h = 5-(4*dy/3);
}

bool custom_effect2(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_effect2_math);
}



static void custom_effect_math3(HSV* hsv, int16_t dx, int16_t dy, uint8_t time) {
    int16_t coord = ((8-dx)/2);
    hsv->h = (coord*(127-cos8(time))/127)-10;
}

bool custom_effect3(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_effect_math3);
}


static void custom_seesaw_math(HSV* hsv, int16_t dx, int16_t dy, uint8_t time) {
    int16_t coord = ((8-dx)/2);
    hsv->h = (coord*(127-cos8(time))/127)+ rgb_matrix_config.hue;
}

bool custom_seesaw(effect_params_t* params) {
    return effect_runner_dx_dy(params, &custom_seesaw_math);
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
