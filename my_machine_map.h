/*
  my_machine_map.h - driver code for RP2040 ARM processors
  JAF Graphics - 3 axis test board
  Part of grblHAL

  Copyright (c) 2021 Terje Io
  Copyright (c) 2021 Volksolive

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if TRINAMIC_ENABLE
#error Trinamic plugin not supported!
#endif

#if N_ABC_MOTORS > 1
#error "Axis configuration is not supported!"
#endif

// Define step pulse output pins.
#define STEP_PORT                   GPIO_PIO  // N_AXIS pin PIO SM
#define STEP_PINS_BASE 6 // N_AXIS number of consecutive pins are used by PIO

// Define step direction output pins.
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         10
#define Y_DIRECTION_PIN         11
#define Z_DIRECTION_PIN         12
#define DIRECTION_OUTMODE       GPIO_MAP

// Define stepper driver enable/disable output pin
#define ENABLE_PORT    GPIO_OUTPUT
#define STEPPERS_ENABLE_PIN     14
#define STEPPERS_ENABLE_MASK    STEPPERS_ENABLE_BIT

// Define homing/hard limit switch input pins.
#define LIMIT_PORT              GPIO_IN
#define X_LIMIT_PIN             2
#define Y_LIMIT_PIN             3
#define Z_LIMIT_PIN             4
#define LIMIT_INMODE            GPIO_MAP

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0       
#define M3_AVAILABLE  
#define M3_STEP_PIN             5
#define M3_DIRECTION_PIN        (Z_DIRECTION_PIN + 1)
#define M3_LIMIT_PIN            (Z_LIMIT_PIN + 1)
#endif


// Define spindle enable and spindle direction output pins.
#define SPINDLE_PORT     GPIO_OUTPUT
#define SPINDLE_ENABLE_PIN      16
#define SPINDLE_DIRECTION_PORT  GPIO_OUTPUT
#define SPINDLE_DIRECTION_PIN   17

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT        GPIO_OUTPUT
#define SPINDLE_PWM_PIN         22
#define SPINDLE_PWM_BIT         (1<<SPINDLE_PWM_PIN)

// Define flood and mist coolant enable output pins.
#define COOLANT_PORT      GPIO_OUTPUT
#define COOLANT_FLOOD_PIN       26
#define COOLANT_MIST_PORT       GPIO_OUTPUT
#define COOLANT_MIST_PIN        27
#define COOLANT_OUTMODE         GPIO_MAP

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PIN               18
#define FEED_HOLD_PIN           19
#define CYCLE_START_PIN         20
#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         21
#endif
#define CONTROL_INMODE          GPIO_MAP

// Define probe switch input pin.
#define PROBE_PORT              GPIO_INPUT
#define PROBE_PIN               0
#define PROBE_BIT             (1<<PROBE_PIN)


#if KEYPAD_ENABLE
#define KEYPAD_STROBE_PIN       1
#endif
