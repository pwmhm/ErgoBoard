#include "ergoboard.h"

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_scroll;
        uint16_t cpi_mouse;
    };
} user_config_t;

user_config_t user_config;

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(B4, 1024, 650, 125),
    JOYSTICK_AXIS_IN(B5, 1024, 850, 125)
};

int16_t global_scroll_buffer_x = 0;
int16_t global_scroll_buffer_y = 0;
bool toggle_trackball_scrolling = false;

static void pointing_device_task_custom(report_mouse_t* mouse_report) {
    int16_t scroll_buffer_x = joystick_read_axis(0);
    int16_t scroll_buffer_y = joystick_read_axis(1);
    int8_t buffer_threshold = 100;
    if (toggle_trackball_scrolling){
        // To simplify things, only one scrolling mesdia can be active at a
        // time. Hence it trackball will override joycon.
        // NOTE: X axis is inverted.
        scroll_buffer_x = -mouse_report->x;
        scroll_buffer_y = mouse_report->y;
        buffer_threshold = 6;
        mouse_report->x = 0;
        mouse_report->y = 0;
    };

    if (abs(scroll_buffer_x) > buffer_threshold){
        global_scroll_buffer_x += 1;
    };
    if (abs(scroll_buffer_y) > buffer_threshold){
        global_scroll_buffer_y += 1;
    };

    if (global_scroll_buffer_x > user_config.cpi_scroll){
        mouse_report->h = scroll_buffer_x > 0 ? -1 : 1 ;
        global_scroll_buffer_x = 0;
    };
    if (global_scroll_buffer_y > user_config.cpi_scroll){
        mouse_report->v = scroll_buffer_y > 0 ? -1 : 1 ;
        global_scroll_buffer_y = 0;
    };
};

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (!is_keyboard_left()) {
        pointing_device_task_custom(&mouse_report);
        mouse_report = pointing_device_task_user(mouse_report);
    };
    return mouse_report;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCROLL_CPI_UP:
      if (record->event.pressed) {
        if (user_config.cpi_scroll > 10){
          user_config.cpi_scroll -=  10;
          eeconfig_update_user(user_config.raw);
        };
      };
      return false;
    case SCROLL_CPI_DOWN:
      if (record->event.pressed) {
        if (user_config.cpi_scroll < 200){
          user_config.cpi_scroll +=  10;
          eeconfig_update_user(user_config.raw);
        };
      };
      return false;
    case MOUSE_CPI_UP:
      if (record->event.pressed) {
        if (user_config.cpi_mouse < 12000){
          user_config.cpi_mouse +=  100;
          eeconfig_update_user(user_config.raw);
          pointing_device_set_cpi(user_config.cpi_mouse);
        };
      };
      return false;
    case MOUSE_CPI_DOWN:
      if (record->event.pressed) {
        if (user_config.cpi_mouse > 100){
          user_config.cpi_mouse -=  100;
          eeconfig_update_user(user_config.raw);
          pointing_device_set_cpi(user_config.cpi_mouse);
        };
      };
      return false;
    case SCROLL_MODE_TB:
      if (record->event.pressed) {
        toggle_trackball_scrolling = !toggle_trackball_scrolling;
      };
      return false;
    case SCROLL_MODE_TB_MO:
      if (record->event.pressed) {
        toggle_trackball_scrolling = true;
      } else {
        toggle_trackball_scrolling = false;
      };
      return false;
    default:
      return true; // Process all other keycodes normally
  };
};

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  pointing_device_set_cpi(user_config.cpi_mouse);
};

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.cpi_mouse = 1600;
  user_config.cpi_scroll = 50;
};