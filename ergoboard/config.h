/* Copyright 2024 Juho T. (@Squalius-cephalus)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define SOFT_SERIAL_PIN D2
#define EE_HANDS

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

#define JOYSTICK_BUTTON_COUNT 1
#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_AXIS_RESOLUTION 10

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define PMW33XX_CS_PIN B6
#define ROTATIONAL_TRANSFORM_ANGLE 80
#define POINTING_DEVICE_INVERT_Y

#define MATRIX_COL_PINS_RIGHT { D3, D5, F7, F6, F5, F4 }
#define MATRIX_ROW_PINS_RIGHT { D1, D0, D4, C6, D7, E6, NO_PIN }
