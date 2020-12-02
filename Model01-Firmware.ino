// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

#include "Kaleidoscope-LED-ActiveModColor.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for shared palettes for other plugins, like Colormap below
#include "Kaleidoscope-LED-Palette-Theme.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
//#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Support for One Shot plugins
#include <Kaleidoscope-OneShot.h>

// Support for QuKeys
#include <Kaleidoscope-Qukeys.h>

// Support for Leader
#include <Kaleidoscope-Leader.h>

// Support for Magic Combo
#include <Kaleidoscope-MagicCombo.h>

/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_0,
       MACRO_1,
       MACRO_2,
       MACRO_3,
       MACRO_4,
       MACRO_5,
       MACRO_6,
       MACRO_7,
       MACRO_8,
       MACRO_9,
       MACRO_ALT_1,
       MACRO_ALT_ENTER,
       MACRO_ALT_F4,
       MACRO_ALT_F7,
       MACRO_ALT_GR_1,
       MACRO_ALT_GR_2,
       MACRO_ALT_GR_3,
       MACRO_ALT_GR_4,
       MACRO_ALT_GR_5,
       MACRO_ALT_GR_A,
       MACRO_ALT_GR_A_AIGU,
       MACRO_ALT_GR_B,
       MACRO_ALT_GR_DOLLAR,
       MACRO_ALT_GR_E,
       MACRO_ALT_GR_EQUALS,
       MACRO_ALT_GR_E_AIGU,
       MACRO_ALT_GR_E_GRAVE,
       MACRO_ALT_GR_I,
       MACRO_ALT_GR_K,
       MACRO_ALT_GR_O,
       MACRO_ALT_GR_P,
       MACRO_ALT_GR_SPACE,
       MACRO_ALT_GR_U,
       MACRO_ALT_GR_X,
       MACRO_ALT_GR_Y,
       MACRO_ALT_DOWN,
       MACRO_ALT_LEFT,
       MACRO_ALT_RIGHT,
       MACRO_ALT_UP,
       MACRO_ALT_SPACE,
       MACRO_COLON,
       MACRO_CTRL_A,
       MACRO_CTRL_C,
       MACRO_CTRL_COLON,
       MACRO_CTRL_DIVIDE,
       MACRO_CTRL_DOWN,
       MACRO_CTRL_END,
       MACRO_CTRL_F,
       MACRO_CTRL_F3,
       MACRO_CTRL_G,
       MACRO_CTRL_H,
       MACRO_CTRL_HOME,
       MACRO_CTRL_LEFT,
       MACRO_CTRL_LEFT_LEFT_LEFT_LEFT,
       MACRO_CTRL_LEFT_PARENTHESIS,
       MACRO_CTRL_N,
       MACRO_CTRL_P,
       MACRO_CTRL_U,
       MACRO_CTRL_UP,
       MACRO_CTRL_RIGHT,
       MACRO_CTRL_RIGHT_PARENTHESIS,
       MACRO_CTRL_RIGHT_RIGHT_RIGHT_RIGHT,
       MACRO_CTRL_S,
       MACRO_CTRL_SHIFT_ENTER,
       MACRO_CTRL_SHIFT_SPACE,
       MACRO_CTRL_T,
       MACRO_CTRL_V,
       MACRO_CTRL_W,
       MACRO_CTRL_X,
       MACRO_CTRL_Z,
       MACRO_EXCLAMATION_POINT,
       MACRO_SEMICOLON,
       MACRO_SHIFT_CTRL_DOWN_X,
       MACRO_SHIFT_CTRL_END_X,
       MACRO_SHIFT_CTRL_HOME_X,
       MACRO_SHIFT_CTRL_LEFT_X,
       MACRO_SHIFT_CTRL_LEFT_LEFT_LEFT_LEFT_X,
       MACRO_SHIFT_CTRL_RIGHT_X,
       MACRO_SHIFT_CTRL_RIGHT_RIGHT_RIGHT_RIGHT_X,
       MACRO_SHIFT_CTRL_UP_X,
       MACRO_SHIFT_DOWN_CTRL_X,
       MACRO_SHIFT_END_CTRL_X,
       MACRO_SHIFT_HOME_CTRL_X,
       MACRO_SHIFT_PG_DOWN_CTRL_X,
       MACRO_SHIFT_PG_UP_CTRL_X,
       MACRO_SHIFT_UP_CTRL_X,
       MACRO_SHIFT_SUPER_Z,
       MACRO_SPACE,
       MACRO_SUPER_CTRL_DOWN,
       MACRO_SUPER_CTRL_END,
       MACRO_SUPER_CTRL_HOME,
       MACRO_SUPER_CTRL_LEFT,
       MACRO_SUPER_CTRL_PAGE_DOWN,
       MACRO_SUPER_CTRL_PAGE_UP,
       MACRO_SUPER_CTRL_SHIFT_ALT_DOWN,
       MACRO_SUPER_CTRL_SHIFT_ALT_LEFT,
       MACRO_SUPER_CTRL_SHIFT_ALT_RIGHT,
       MACRO_SUPER_CTRL_SHIFT_ALT_UP,
       MACRO_SUPER_CTRL_SHIFT_DOWN,
       MACRO_SUPER_CTRL_SHIFT_END,
       MACRO_SUPER_CTRL_SHIFT_HOME,
       MACRO_SUPER_CTRL_SHIFT_LEFT,
       MACRO_SUPER_CTRL_SHIFT_RIGHT,
       MACRO_SUPER_CTRL_SHIFT_PAGE_DOWN,
       MACRO_SUPER_CTRL_SHIFT_PAGE_UP,
       MACRO_SUPER_CTRL_SHIFT_UP,
       MACRO_SUPER_CTRL_RIGHT,
       MACRO_SUPER_CTRL_UP,
       MACRO_VI
     };



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { PRIMARY, FUNCTION, NUMPAD, ALTGR, CUT}; // layers


/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

//#define PRIMARY_KEYMAP_QWERTY
// #define PRIMARY_KEYMAP_COLEMAK
// #define PRIMARY_KEYMAP_DVORAK
// #define PRIMARY_KEYMAP_BEPO
#define PRIMARY_KEYMAP_CUSTOM



/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(

#if defined (PRIMARY_KEYMAP_QWERTY)
  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   ___,           Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_DVORAK)

  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1,         Key_2,     Key_3,      Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Quote,     Key_Comma, Key_Period, Key_P, Key_Y, Key_Tab,
   Key_PageUp,   Key_A,         Key_O,     Key_E,      Key_U, Key_I,
   Key_PageDown, Key_Semicolon, Key_Q,     Key_J,      Key_K, Key_X, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   ___,            Key_6, Key_7, Key_8, Key_9, Key_0, LockLayer(NUMPAD),
   Key_Enter,      Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash,
                   Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus,
   Key_RightAlt,   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_COLEMAK)

  [PRIMARY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_F, Key_P, Key_G, Key_Tab,
   Key_PageUp,   Key_A, Key_R, Key_S, Key_T, Key_D,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   ___,  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_J, Key_L, Key_U,     Key_Y,         Key_Semicolon, Key_Equals,
                  Key_H, Key_N, Key_E,     Key_I,         Key_O,         Key_Quote,
   Key_RightAlt,  Key_K, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#elif defined (PRIMARY_KEYMAP_BEPO)
// All keys are located standard bépo layout
// Nevertheless some adaptations from standard 105 azerty keyboard / keyboardio model 01 because some keys do not exist on keyboardio model 01 and bépo layout needs RightAlt on right thumb.
// The changes are % on `, w on pgup, ê on pgdown, ç on |, = on num, LeftGui on bksp, LeftAlt on cmd, RightLeft on alt key, NumPad on any.
  [PRIMARY] = KEYMAP_STACKED
  (Key_Backtick,              Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Equals,                Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_RightBracket,          Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_NonUsBackslashAndPipe, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_LeftGui, Key_LeftAlt, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   LockLayer(NUMPAD), Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Minus,
   Key_Enter,         Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_LeftBracket,
                      Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_Backspace,     Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Backslash,
   Key_RightShift, Key_RightAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),


#elif defined (PRIMARY_KEYMAP_CUSTOM)
  // Edit this keymap to make a custom layout
  [PRIMARY] = KEYMAP_STACKED
  (Key_Insert,                             Key_1,                                          M(MACRO_ALT_GR_2),                      M(MACRO_ALT_GR_3),                      Key_4,                                  Key_5,                                       Key_Enter,
   Key_Backtick,                           Key_Q,                                          Key_W,                                  Key_E,                                  Key_R,                                  Key_T,                                       Key_Tab,
   Key_RightBracket,                       Key_A,                                          Key_S,                                  Key_D,                                  Key_F,                                  Key_G,
   Key_Minus,                              Key_Z,                                          Key_X,                                  Key_C,                                  Key_V,                                  Key_B,                                       Key_Escape,
   OSM(LeftShift),                         Key_Backspace,                                  OSM(LeftControl),                       OSM(LeftAlt),
   LEAD(0),

   M(MACRO_EXCLAMATION_POINT),             Key_6,                                          Key_7,                                  Key_8,                                  Key_9,                                  Key_0,                                       Key_Equals,
   M(MACRO_COLON),                         Key_Y,                                          Key_U,                                  Key_I,                                  Key_O,                                  Key_P,                                       Key_LeftBracket,
                                           Key_H,                                          Key_J,                                  Key_K,                                  Key_L,                                  Key_Semicolon,                               Key_Quote,
   M(MACRO_ALT_SPACE),                     Key_N,                                          Key_M,                                  Key_Comma,                              Key_Period,                             Key_Slash,                                   Key_Backslash,
   Key_LeftGui,                            Key_Enter,                                      M(MACRO_SPACE),                         OSM(LeftShift),
   M(MACRO_SHIFT_SUPER_Z)),

#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif
  [FUNCTION] =  KEYMAP_STACKED
  (M(MACRO_CTRL_P),                        Key_F1,                                         Key_F2,                                 Key_F3,                                 Key_F4,                                 Key_F5,                                      M(MACRO_CTRL_A),
   M(MACRO_CTRL_S),                        M(MACRO_CTRL_N),                                M(MACRO_CTRL_T),                        M(MACRO_CTRL_F3),                       M(MACRO_CTRL_W),                        M(MACRO_ALT_F4),                             M(MACRO_CTRL_H),
   Key_Delete,                             M(MACRO_CTRL_Z),                                M(MACRO_CTRL_X),                        M(MACRO_CTRL_C),                        M(MACRO_CTRL_V),                        M(MACRO_CTRL_F),
   M(MACRO_CTRL_DIVIDE),                   M(MACRO_ALT_LEFT),                              M(MACRO_ALT_DOWN),                      M(MACRO_ALT_UP),                        M(MACRO_ALT_RIGHT),                     Key_F4,                                      M(MACRO_ALT_F7),
   Key_LeftShift,                          Key_Backspace,                                  Key_LeftControl,                        Key_LeftAlt,
   ___,

   Key_F12,                                Key_F6,                                         Key_F7,                                 Key_F8,                                 Key_F9,                                 Key_F10,                                     Key_F11,
   M(MACRO_CTRL_COLON),                    M(MACRO_CTRL_HOME),                             M(MACRO_CTRL_LEFT_PARENTHESIS),         Key_PageDown,                           Key_PageUp,                             M(MACRO_CTRL_RIGHT_PARENTHESIS),             M(MACRO_CTRL_END),
                                           Key_Home,                                       Key_LeftArrow,                          Key_DownArrow,                          Key_UpArrow,                            Key_RightArrow,                              Key_End,
   Key_PcApplication,                      M(MACRO_CTRL_LEFT_LEFT_LEFT_LEFT),              M(MACRO_CTRL_LEFT),                     M(MACRO_CTRL_DOWN),                     M(MACRO_CTRL_UP),                       M(MACRO_CTRL_RIGHT),                         M(MACRO_CTRL_RIGHT_RIGHT_RIGHT_RIGHT),
   ___,                                    M(MACRO_CTRL_SHIFT_ENTER),                      M(MACRO_CTRL_SHIFT_SPACE),              ___,
   M(MACRO_ALT_1)),

  [NUMPAD] =  KEYMAP_STACKED
  (___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         M(MACRO_ALT_ENTER),
   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   M(MACRO_CTRL_G),                        M(MACRO_1),                                     M(MACRO_2),                             M(MACRO_3),                             M(MACRO_4),                             M(MACRO_5),
   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   ___, ___, ___, ___,
   Key_Backspace,

   ___,                                    ___,                                            Key_KeypadAdd,                          Key_KeypadSubtract,                     Key_KeypadDivide,                       Key_KeypadMultiply,                          ___,
   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
                                           M(MACRO_6),                                     M(MACRO_7),                             M(MACRO_8),                             M(MACRO_9),                             M(MACRO_0),                                  Key_V,
   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   ___,                                    M(MACRO_ALT_ENTER),                             M(MACRO_ALT_GR_SPACE),                  ___,
   ___),

  [ALTGR] =  KEYMAP_STACKED
  (___,                                    M(MACRO_ALT_GR_1),                              Key_2,                                  Key_3,                                  M(MACRO_ALT_GR_4),                      M(MACRO_ALT_GR_5),                           ___,
   M(MACRO_ALT_GR_DOLLAR),                 M(MACRO_ALT_GR_B),                              M(MACRO_ALT_GR_E_AIGU),                 M(MACRO_ALT_GR_P),                      M(MACRO_ALT_GR_O),                      M(MACRO_ALT_GR_E_GRAVE),                     ___,
   M(MACRO_EXCLAMATION_POINT),             M(MACRO_ALT_GR_A),                              M(MACRO_ALT_GR_U),                      M(MACRO_COLON),                         M(MACRO_SEMICOLON),                     M(MACRO_ALT_GR_E),
   M(MACRO_ALT_GR_EQUALS),                 M(MACRO_ALT_GR_A_AIGU),                         M(MACRO_ALT_GR_Y),                      M(MACRO_ALT_GR_X),                      M(MACRO_ALT_GR_I),                      M(MACRO_ALT_GR_K),                           ___,
   ___, ___, ___, ___,
   ___,

   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
                                           ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   ___,                                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   ___,                                    ___,                                            ___,                                    ___,
   Key_Spacebar),

  [CUT] =  KEYMAP_STACKED
  (Key_PrintScreen,                        ___,                                            M(MACRO_SUPER_CTRL_SHIFT_ALT_DOWN),     M(MACRO_SUPER_CTRL_SHIFT_ALT_UP),       ___,                                    ___,                                         ___,
   M(MACRO_SUPER_CTRL_SHIFT_HOME),         M(MACRO_SUPER_CTRL_HOME),                       M(MACRO_SUPER_CTRL_SHIFT_DOWN),         M(MACRO_SUPER_CTRL_SHIFT_UP),           M(MACRO_SUPER_CTRL_PAGE_UP),            M(MACRO_SUPER_CTRL_SHIFT_PAGE_UP),           ___,
   M(MACRO_SUPER_CTRL_SHIFT_LEFT),         M(MACRO_SUPER_CTRL_LEFT),                       M(MACRO_SUPER_CTRL_DOWN),               M(MACRO_SUPER_CTRL_UP),                 M(MACRO_SUPER_CTRL_RIGHT),              M(MACRO_SUPER_CTRL_SHIFT_RIGHT),
   M(MACRO_SUPER_CTRL_SHIFT_END),          M(MACRO_SUPER_CTRL_END),                        M(MACRO_SUPER_CTRL_SHIFT_ALT_LEFT),     M(MACRO_SUPER_CTRL_SHIFT_ALT_RIGHT),    M(MACRO_SUPER_CTRL_PAGE_DOWN),          M(MACRO_SUPER_CTRL_SHIFT_PAGE_DOWN),         ___,
   ___, ___, ___, ___,
   ___,

   M(MACRO_CTRL_COLON),                    ___,                                            ___,                                    ___,                                    ___,                                    ___,                                         ___,
   ___,                                    M(MACRO_SHIFT_CTRL_HOME_X),                     ___,                                    M(MACRO_SHIFT_PG_DOWN_CTRL_X),          M(MACRO_SHIFT_PG_UP_CTRL_X),            ___,                                         M(MACRO_SHIFT_CTRL_END_X),
                                           M(MACRO_SHIFT_HOME_CTRL_X),                     Key_Backspace,                          M(MACRO_SHIFT_DOWN_CTRL_X),             M(MACRO_SHIFT_UP_CTRL_X),               Key_Delete,                                  M(MACRO_SHIFT_END_CTRL_X),
   ___,                                    M(MACRO_SHIFT_CTRL_LEFT_LEFT_LEFT_LEFT_X),      M(MACRO_SHIFT_CTRL_LEFT_X),             M(MACRO_SHIFT_CTRL_DOWN_X),             M(MACRO_SHIFT_CTRL_UP_X),               M(MACRO_SHIFT_CTRL_RIGHT_X),                 M(MACRO_SHIFT_CTRL_RIGHT_RIGHT_RIGHT_RIGHT_X),
   ___,                                    ___,                                            Key_Spacebar,                           ___,
   ___)

) // KEYMAPS(


// Leader plugin to have Vi mode

//moveFileStart
static void moveFileStart(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift), D(LeftControl), T(Home), U(LeftControl)));
}

//moveNPagesBefore
static void moveNPagesBefore(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(PageUp), U(LeftControl)));
    }
}

static void move1PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 1);}
static void move2PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 2);}
static void move3PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 3);}
static void move4PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 4);}
static void move5PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 5);}
static void move6PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 6);}
static void move7PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 7);}
static void move8PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 8);}
static void move9PagesBefore(uint8_t seq_index) { moveNPagesBefore(seq_index, 9);}


//moveNParagraphsBefore
static void moveNParagraphsBefore(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(UpArrow), U(LeftControl)));
    }
}

static void move1ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 1);}
static void move2ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 2);}
static void move3ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 3);}
static void move4ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 4);}
static void move5ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 5);}
static void move6ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 6);}
static void move7ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 7);}
static void move8ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 8);}
static void move9ParagraphsBefore(uint8_t seq_index) { moveNParagraphsBefore(seq_index, 9);}


//moveNLinesBefore
static void moveNLinesBefore(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(T(UpArrow)));
    }
}

static void move1LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 1);}
static void move2LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 2);}
static void move3LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 3);}
static void move4LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 4);}
static void move5LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 5);}
static void move6LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 6);}
static void move7LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 7);}
static void move8LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 8);}
static void move9LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 9);}
static void move10LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 10);}
static void move11LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 11);}
static void move12LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 12);}
static void move13LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 13);}
static void move14LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 14);}
static void move15LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 15);}
static void move16LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 16);}
static void move17LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 17);}
static void move18LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 18);}
static void move19LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 19);}
static void move20LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 20);}
static void move21LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 21);}
static void move22LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 22);}
static void move23LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 23);}
static void move24LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 24);}
static void move25LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 25);}
static void move26LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 26);}
static void move27LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 27);}
static void move28LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 28);}
static void move29LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 29);}
static void move30LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 30);}
static void move31LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 31);}
static void move32LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 32);}
static void move33LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 33);}
static void move34LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 34);}
static void move35LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 35);}
static void move36LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 36);}
static void move37LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 37);}
static void move38LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 38);}
static void move39LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 39);}
static void move40LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 40);}
static void move41LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 41);}
static void move42LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 42);}
static void move43LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 43);}
static void move44LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 44);}
static void move45LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 45);}
static void move46LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 46);}
static void move47LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 47);}
static void move48LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 48);}
static void move49LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 49);}
static void move50LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 50);}
static void move51LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 51);}
static void move52LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 52);}
static void move53LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 53);}
static void move54LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 54);}
static void move55LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 55);}
static void move56LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 56);}
static void move57LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 57);}
static void move58LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 58);}
static void move59LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 59);}
static void move60LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 60);}
static void move61LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 61);}
static void move62LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 62);}
static void move63LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 63);}
static void move64LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 64);}
static void move65LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 65);}
static void move66LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 66);}
static void move67LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 67);}
static void move68LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 68);}
static void move69LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 69);}
static void move70LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 70);}
static void move71LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 71);}
static void move72LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 72);}
static void move73LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 73);}
static void move74LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 74);}
static void move75LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 75);}
static void move76LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 76);}
static void move77LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 77);}
static void move78LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 78);}
static void move79LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 79);}
static void move80LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 80);}
static void move81LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 81);}
static void move82LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 82);}
static void move83LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 83);}
static void move84LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 84);}
static void move85LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 85);}
static void move86LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 86);}
static void move87LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 87);}
static void move88LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 88);}
static void move89LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 89);}
static void move90LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 90);}
static void move91LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 91);}
static void move92LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 92);}
static void move93LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 93);}
static void move94LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 94);}
static void move95LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 95);}
static void move96LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 96);}
static void move97LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 97);}
static void move98LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 98);}
static void move99LinesBefore(uint8_t seq_index) { moveNLinesBefore(seq_index, 99);}


//moveLineStart
static void moveLineStart(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift)));
    Macros.play(MACRO(T(Home)));
}


//moveNWordsBefore
static void moveNWordsBefore(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(LeftArrow), U(LeftControl)));
    }
}

static void move1WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 1);}
static void move2WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 2);}
static void move3WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 3);}
static void move4WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 4);}
static void move5WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 5);}
static void move6WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 6);}
static void move7WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 7);}
static void move8WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 8);}
static void move9WordsBefore(uint8_t seq_index) { moveNWordsBefore(seq_index, 9);}


//moveNCharsBefore
static void moveNCharsBefore(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(T(LeftArrow)));
    }
}

static void move1CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 1);}
static void move2CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 2);}
static void move3CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 3);}
static void move4CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 4);}
static void move5CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 5);}
static void move6CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 6);}
static void move7CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 7);}
static void move8CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 8);}
static void move9CharsBefore(uint8_t seq_index) { moveNCharsBefore(seq_index, 9);}


//moveNCharsAfter
static void moveNCharsAfter(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(T(RightArrow)));
    }
}

static void move1CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 1);}
static void move2CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 2);}
static void move3CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 3);}
static void move4CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 4);}
static void move5CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 5);}
static void move6CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 6);}
static void move7CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 7);}
static void move8CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 8);}
static void move9CharsAfter(uint8_t seq_index) { moveNCharsAfter(seq_index, 9);}


//moveNWordsAfter
static void moveNWordsAfter(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(RightArrow), U(LeftControl)));
    }
}

static void move1WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 1);}
static void move2WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 2);}
static void move3WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 3);}
static void move4WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 4);}
static void move5WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 5);}
static void move6WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 6);}
static void move7WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 7);}
static void move8WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 8);}
static void move9WordsAfter(uint8_t seq_index) { moveNWordsAfter(seq_index, 9);}


//moveLineEnd
static void moveLineEnd(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift)));
    Macros.play(MACRO(T(End)));
}

//moveNLinesAfter
static void moveNLinesAfter(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(T(DownArrow)));
    }
}

static void move1LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 1);}
static void move2LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 2);}
static void move3LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 3);}
static void move4LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 4);}
static void move5LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 5);}
static void move6LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 6);}
static void move7LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 7);}
static void move8LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 8);}
static void move9LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 9);}
static void move10LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 10);}
static void move11LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 11);}
static void move12LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 12);}
static void move13LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 13);}
static void move14LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 14);}
static void move15LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 15);}
static void move16LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 16);}
static void move17LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 17);}
static void move18LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 18);}
static void move19LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 19);}
static void move20LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 20);}
static void move21LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 21);}
static void move22LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 22);}
static void move23LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 23);}
static void move24LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 24);}
static void move25LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 25);}
static void move26LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 26);}
static void move27LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 27);}
static void move28LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 28);}
static void move29LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 29);}
static void move30LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 30);}
static void move31LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 31);}
static void move32LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 32);}
static void move33LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 33);}
static void move34LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 34);}
static void move35LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 35);}
static void move36LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 36);}
static void move37LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 37);}
static void move38LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 38);}
static void move39LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 39);}
static void move40LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 40);}
static void move41LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 41);}
static void move42LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 42);}
static void move43LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 43);}
static void move44LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 44);}
static void move45LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 45);}
static void move46LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 46);}
static void move47LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 47);}
static void move48LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 48);}
static void move49LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 49);}
static void move50LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 50);}
static void move51LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 51);}
static void move52LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 52);}
static void move53LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 53);}
static void move54LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 54);}
static void move55LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 55);}
static void move56LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 56);}
static void move57LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 57);}
static void move58LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 58);}
static void move59LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 59);}
static void move60LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 60);}
static void move61LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 61);}
static void move62LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 62);}
static void move63LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 63);}
static void move64LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 64);}
static void move65LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 65);}
static void move66LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 66);}
static void move67LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 67);}
static void move68LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 68);}
static void move69LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 69);}
static void move70LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 70);}
static void move71LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 71);}
static void move72LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 72);}
static void move73LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 73);}
static void move74LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 74);}
static void move75LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 75);}
static void move76LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 76);}
static void move77LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 77);}
static void move78LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 78);}
static void move79LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 79);}
static void move80LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 80);}
static void move81LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 81);}
static void move82LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 82);}
static void move83LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 83);}
static void move84LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 84);}
static void move85LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 85);}
static void move86LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 86);}
static void move87LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 87);}
static void move88LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 88);}
static void move89LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 89);}
static void move90LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 90);}
static void move91LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 91);}
static void move92LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 92);}
static void move93LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 93);}
static void move94LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 94);}
static void move95LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 95);}
static void move96LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 96);}
static void move97LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 97);}
static void move98LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 98);}
static void move99LinesAfter(uint8_t seq_index) { moveNLinesAfter(seq_index, 99);}


//nmoveNParagraphsAfter
static void moveNParagraphsAfter(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(DownArrow), U(LeftControl)));
    }
}
static void move1ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 1);}
static void move2ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 2);}
static void move3ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 3);}
static void move4ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 4);}
static void move5ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 5);}
static void move6ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 6);}
static void move7ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 7);}
static void move8ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 8);}
static void move9ParagraphsAfter(uint8_t seq_index) { moveNParagraphsAfter(seq_index, 9);}

//moveNPagesAfter
static void moveNPagesAfter(uint8_t seq_index, int n) {
    Macros.play(MACRO(D(LeftShift)));
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(PageDown), U(LeftControl)));
    }
}
static void move1PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 1);}
static void move2PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 2);}
static void move3PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 3);}
static void move4PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 4);}
static void move5PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 5);}
static void move6PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 6);}
static void move7PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 7);}
static void move8PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 8);}
static void move9PagesAfter(uint8_t seq_index) { moveNPagesAfter(seq_index, 9);}

//moveFileEnd
static void moveFileEnd(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift), D(LeftControl), T(End), U(LeftControl)));
}

//moveCodeBlockStart
static void moveCodeBlockStart(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift), D(LeftControl), T(4), U(LeftControl)));
}

//moveCodeBlockEnd
static void moveCodeBlockEnd(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift), D(LeftControl), T(5), U(LeftControl)));
}


 static const kaleidoscope::plugin::Leader::dictionary_t leader_dictionary[] PROGMEM =
 LEADER_DICT(

    // Move

    // 1 key sequence : Caution need to have first, 1 keys sequences, after 2, 3 because the sequence will be matched first and wait the timeout notably if you some sequence with the same first keys

    // moveFileStart
    { LEADER_SEQ(LEAD(0), Key_Y), moveFileStart},

    // move1PagesBefore
    { LEADER_SEQ(LEAD(0), Key_O), move1PagesBefore},

    // move1ParagraphsBefore
    { LEADER_SEQ(LEAD(0), Key_Period), move1ParagraphsBefore},

    // move1LinesBefore
    { LEADER_SEQ(LEAD(0), Key_L), move1LinesBefore},

    //moveLineStart
    { LEADER_SEQ(LEAD(0), Key_H), moveLineStart},

    // move4WordsBefore
    { LEADER_SEQ(LEAD(0), Key_N), move2WordsBefore},

    // move1WordsBefore
    { LEADER_SEQ(LEAD(0), Key_M), move1WordsBefore},

    // move1CharsBefore
    { LEADER_SEQ(LEAD(0), Key_J), move1CharsBefore},

    // move1CharsAfter
    { LEADER_SEQ(LEAD(0), Key_Semicolon), move1CharsAfter},

    // move1WordsAfter
    { LEADER_SEQ(LEAD(0), Key_Slash), move1WordsAfter},

    // move4WordsAfter
    { LEADER_SEQ(LEAD(0), Key_Backslash), move4WordsAfter},

    // moveLineEnd
    { LEADER_SEQ(LEAD(0), Key_Quote), moveLineEnd},

    // move1LinesAfter
    { LEADER_SEQ(LEAD(0), Key_K), move1LinesAfter},

    // moveNParagraphsAfter
    { LEADER_SEQ(LEAD(0), Key_Comma), move1ParagraphsAfter},

    // moveNPagesAfter
    { LEADER_SEQ(LEAD(0), Key_I), move1PagesAfter},

    // moveFileEnd
    { LEADER_SEQ(LEAD(0), Key_LeftBracket), moveFileEnd},

    // moveCodeBlockStart
    { LEADER_SEQ(LEAD(0), Key_U), moveCodeBlockStart},

    // moveCodeBlockEnd
    { LEADER_SEQ(LEAD(0), Key_P), moveCodeBlockEnd},

    // 2 keys sequences

// Commented because of memory usage and not really useful in real life and when I tapped fn1 23 down, the keyboard does not work after (I don't know why)
//     // moveNPagesBefore
//     { LEADER_SEQ(LEAD(0), Key_A, Key_O), move1PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_S, Key_O), move2PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_D, Key_O), move3PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_O), move4PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_O), move5PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_O), move6PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_O), move7PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_O), move8PagesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_O), move9PagesBefore},
//
//     // moveNParagraphsBefore
//     { LEADER_SEQ(LEAD(0), Key_A, Key_Period), move1ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_S, Key_Period), move2ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_D, Key_Period), move3ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_Period), move4ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_Period), move5ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_Period), move6ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_Period), move7ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_Period), move8ParagraphsBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_Period), move9ParagraphsBefore},

    // moveNLinesBefore
    { LEADER_SEQ(LEAD(0), Key_A, Key_L), move1LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_L), move2LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_L), move3LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_F, Key_L), move4LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_G, Key_L), move5LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_H, Key_L), move6LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_J, Key_L), move7LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_K, Key_L), move8LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_L, Key_L), move9LinesBefore},

    // moveNWordsBefore
    { LEADER_SEQ(LEAD(0), Key_A, Key_M), move1WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_M), move2WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_M), move3WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_F, Key_M), move4WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_G, Key_M), move5WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_H, Key_M), move6WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_J, Key_M), move7WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_K, Key_M), move8WordsBefore},
    { LEADER_SEQ(LEAD(0), Key_L, Key_M), move9WordsBefore},

    // moveNCharsBefore
    { LEADER_SEQ(LEAD(0), Key_A, Key_J), move1CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_J), move2CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_J), move3CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_F, Key_J), move4CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_G, Key_J), move5CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_H, Key_J), move6CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_J, Key_J), move7CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_K, Key_J), move8CharsBefore},
    { LEADER_SEQ(LEAD(0), Key_L, Key_J), move9CharsBefore},

    // moveNCharsAfter
    { LEADER_SEQ(LEAD(0), Key_A, Key_Semicolon), move1CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_Semicolon), move2CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_Semicolon), move3CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_F, Key_Semicolon), move4CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_G, Key_Semicolon), move5CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_H, Key_Semicolon), move6CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_J, Key_Semicolon), move7CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_K, Key_Semicolon), move8CharsAfter},
    { LEADER_SEQ(LEAD(0), Key_L, Key_Semicolon), move9CharsAfter},

    // moveNWordsAfter
    { LEADER_SEQ(LEAD(0), Key_A, Key_Slash), move1WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_Slash), move2WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_Slash), move3WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_F, Key_Slash), move4WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_G, Key_Slash), move5WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_H, Key_Slash), move6WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_J, Key_Slash), move7WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_K, Key_Slash), move8WordsAfter},
    { LEADER_SEQ(LEAD(0), Key_L, Key_Slash), move9WordsAfter},

    // moveNLinesAfter
    { LEADER_SEQ(LEAD(0), Key_A, Key_K), move1LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_K), move2LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_K), move3LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_F, Key_K), move4LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_G, Key_K), move5LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_H, Key_K), move6LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_J, Key_K), move7LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_K, Key_K), move8LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_L, Key_K), move9LinesAfter},

// Commented because of memory usage and not really useful in real life and when I tapped fn1 23 down, the keyboard does not work after (I don't know why)
//     // moveNParagraphsAfter
//     { LEADER_SEQ(LEAD(0), Key_A, Key_Comma), move1ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_S, Key_Comma), move2ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_D, Key_Comma), move3ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_Comma), move4ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_Comma), move5ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_Comma), move6ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_Comma), move7ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_Comma), move8ParagraphsAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_Comma), move9ParagraphsAfter},
//
//     // moveNPagesAfter
//     { LEADER_SEQ(LEAD(0), Key_A, Key_I), move1PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_S, Key_I), move2PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_D, Key_I), move3PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_I), move4PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_I), move5PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_I), move6PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_I), move7PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_I), move8PagesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_I), move9PagesAfter},


    // 3 keys sequences

    // moveNLinesBefore
    { LEADER_SEQ(LEAD(0), Key_A, Key_Semicolon, Key_L), move10LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_A, Key_L), move11LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_S, Key_L), move12LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_D, Key_L), move13LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_F, Key_L), move14LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_G, Key_L), move15LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_H, Key_L), move16LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_J, Key_L), move17LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_K, Key_L), move18LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_A, Key_L, Key_L), move19LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_Semicolon, Key_L), move20LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_A, Key_L), move21LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_S, Key_L), move22LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_D, Key_L), move23LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_F, Key_L), move24LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_G, Key_L), move25LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_H, Key_L), move26LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_J, Key_L), move27LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_K, Key_L), move28LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_S, Key_L, Key_L), move29LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_Semicolon, Key_L), move30LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_A, Key_L), move31LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_S, Key_L), move32LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_D, Key_L), move33LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_F, Key_L), move34LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_G, Key_L), move35LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_H, Key_L), move36LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_J, Key_L), move37LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_K, Key_L), move38LinesBefore},
    { LEADER_SEQ(LEAD(0), Key_D, Key_L, Key_L), move39LinesBefore},
// Commented because of memory usage and not really useful in real life
//     { LEADER_SEQ(LEAD(0), Key_F, Key_Semicolon, Key_L), move40LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_A, Key_L), move41LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_S, Key_L), move42LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_D, Key_L), move43LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_F, Key_L), move44LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_G, Key_L), move45LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_H, Key_L), move46LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_J, Key_L), move47LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_K, Key_L), move48LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_L, Key_L), move49LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_Semicolon, Key_L), move50LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_A, Key_L), move51LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_S, Key_L), move52LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_D, Key_L), move53LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_F, Key_L), move54LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_G, Key_L), move55LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_H, Key_L), move56LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_J, Key_L), move57LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_K, Key_L), move58LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_L, Key_L), move59LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_Semicolon, Key_L), move60LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_A, Key_L), move61LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_S, Key_L), move62LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_D, Key_L), move63LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_F, Key_L), move64LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_G, Key_L), move65LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_H, Key_L), move66LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_J, Key_L), move67LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_K, Key_L), move68LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_L, Key_L), move69LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_Semicolon, Key_L), move70LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_A, Key_L), move71LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_S, Key_L), move72LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_D, Key_L), move73LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_F, Key_L), move74LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_G, Key_L), move75LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_H, Key_L), move76LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_J, Key_L), move77LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_K, Key_L), move78LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_L, Key_L), move79LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_Semicolon, Key_L), move80LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_A, Key_L), move81LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_S, Key_L), move82LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_D, Key_L), move83LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_F, Key_L), move84LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_G, Key_L), move85LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_H, Key_L), move86LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_J, Key_L), move87LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_K, Key_L), move88LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_L, Key_L), move89LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_Semicolon, Key_L), move90LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_A, Key_L), move91LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_S, Key_L), move92LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_D, Key_L), move93LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_F, Key_L), move94LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_G, Key_L), move95LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_H, Key_L), move96LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_J, Key_L), move97LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_K, Key_L), move98LinesBefore},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_L, Key_L), move99LinesBefore},


    // moveNLinesAfter
    { LEADER_SEQ(LEAD(0), Key_A, Key_Semicolon, Key_K), move10LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_A, Key_K), move11LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_S, Key_K), move12LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_D, Key_K), move13LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_F, Key_K), move14LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_G, Key_K), move15LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_H, Key_K), move16LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_J, Key_K), move17LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_K, Key_K), move18LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_A, Key_L, Key_K), move19LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_Semicolon, Key_K), move20LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_A, Key_K), move21LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_S, Key_K), move22LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_D, Key_K), move23LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_F, Key_K), move24LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_G, Key_K), move25LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_H, Key_K), move26LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_J, Key_K), move27LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_K, Key_K), move28LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_S, Key_L, Key_K), move29LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_Semicolon, Key_K), move30LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_A, Key_K), move31LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_S, Key_K), move32LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_D, Key_K), move33LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_F, Key_K), move34LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_G, Key_K), move35LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_H, Key_K), move36LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_J, Key_K), move37LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_K, Key_K), move38LinesAfter},
    { LEADER_SEQ(LEAD(0), Key_D, Key_L, Key_K), move39LinesAfter}
// Commented because of memory usage and not really useful in real life
//     { LEADER_SEQ(LEAD(0), Key_F, Key_Semicolon, Key_K), move40LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_A, Key_K), move41LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_S, Key_K), move42LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_D, Key_K), move43LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_F, Key_K), move44LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_G, Key_K), move45LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_H, Key_K), move46LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_J, Key_K), move47LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_K, Key_K), move48LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_F, Key_L, Key_K), move49LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_Semicolon, Key_K), move50LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_A, Key_K), move51LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_S, Key_K), move52LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_D, Key_K), move53LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_F, Key_K), move54LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_G, Key_K), move55LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_H, Key_K), move56LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_J, Key_K), move57LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_K, Key_K), move58LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_G, Key_L, Key_K), move59LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_Semicolon, Key_K), move60LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_A, Key_K), move61LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_S, Key_K), move62LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_D, Key_K), move63LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_F, Key_K), move64LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_G, Key_K), move65LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_H, Key_K), move66LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_J, Key_K), move67LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_K, Key_K), move68LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_H, Key_L, Key_K), move69LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_Semicolon, Key_K), move70LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_A, Key_K), move71LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_S, Key_K), move72LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_D, Key_K), move73LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_F, Key_K), move74LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_G, Key_K), move75LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_H, Key_K), move76LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_J, Key_K), move77LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_K, Key_K), move78LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_J, Key_L, Key_K), move79LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_Semicolon, Key_K), move80LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_A, Key_K), move81LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_S, Key_K), move82LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_D, Key_K), move83LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_F, Key_K), move84LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_G, Key_K), move85LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_H, Key_K), move86LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_J, Key_K), move87LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_K, Key_K), move88LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_K, Key_L, Key_K), move89LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_Semicolon, Key_K), move90LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_A, Key_K), move91LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_S, Key_K), move92LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_D, Key_K), move93LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_F, Key_K), move94LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_G, Key_K), move95LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_H, Key_K), move96LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_J, Key_K), move97LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_K, Key_K), move98LinesAfter},
//     { LEADER_SEQ(LEAD(0), Key_L, Key_L, Key_K), move99LinesAfter},
  );

/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_0:
    return MACRODOWN(D(LeftShift), T(0), U(LeftShift));
    break;

  case MACRO_1:
    return MACRODOWN(D(LeftShift), T(1), U(LeftShift));
    break;

  case MACRO_2:
    return MACRODOWN(D(LeftShift), T(2), U(LeftShift));
    break;

  case MACRO_3:
    return MACRODOWN(D(LeftShift), T(3), U(LeftShift));
    break;

  case MACRO_4:
    return MACRODOWN(D(LeftShift), T(4), U(LeftShift));
    break;

  case MACRO_5:
    return MACRODOWN(D(LeftShift), T(5), U(LeftShift));
    break;

  case MACRO_6:
    return MACRODOWN(D(LeftShift), T(6), U(LeftShift));
    break;

  case MACRO_7:
    return MACRODOWN(D(LeftShift), T(7), U(LeftShift));
    break;

  case MACRO_8:
    return MACRODOWN(D(LeftShift), T(8), U(LeftShift));
    break;

  case MACRO_9:
    return MACRODOWN(D(LeftShift), T(9), U(LeftShift));
    break;

  case MACRO_ALT_1:
    return MACRODOWN(D(LeftAlt), D(LeftShift), T(1), U(LeftShift), U(LeftAlt));
    break;

  case MACRO_ALT_ENTER:
    return MACRODOWN(D(LeftAlt), T(Enter), U(LeftAlt));
    break;

  case MACRO_ALT_F4:
    return MACRODOWN(D(LeftAlt), T(F4), U(LeftAlt));
    break;

  case MACRO_ALT_F7:
    return MACRODOWN(D(LeftAlt), T(F7), U(LeftAlt));
    break;

  case MACRO_ALT_GR_1:
    return MACRODOWN(D(RightAlt), T(1), U(RightAlt));
    break;

  case MACRO_ALT_GR_2:
    return MACRODOWN(D(RightAlt), T(2), U(RightAlt));
    break;

  case MACRO_ALT_GR_3:
    return MACRODOWN(D(RightAlt), T(3), U(RightAlt));
    break;

  case MACRO_ALT_GR_4:
    return MACRODOWN(D(RightAlt), T(4), U(RightAlt));
    break;

  case MACRO_ALT_GR_5:
    return MACRODOWN(D(RightAlt), T(5), U(RightAlt));
    break;

  case MACRO_ALT_GR_A:
     return MACRODOWN(D(RightAlt), T(A), U(RightAlt));
     break;

  case MACRO_ALT_GR_A_AIGU:
     return MACRODOWN(D(RightAlt), T(Z), U(RightAlt));
     break;

  case MACRO_ALT_GR_B:
    return MACRODOWN(D(RightAlt), T(Q), U(RightAlt));
    break;

  case MACRO_ALT_GR_DOLLAR:
    return MACRODOWN(D(RightAlt), T(Backtick), U(RightAlt));
    break;

  case MACRO_ALT_GR_E:
     return MACRODOWN(D(RightAlt), T(F), U(RightAlt));
     break;

  case MACRO_ALT_GR_E_AIGU:
     return MACRODOWN(D(RightAlt), T(W), U(RightAlt));
     break;

  case MACRO_ALT_GR_E_GRAVE:
     return MACRODOWN(D(RightAlt), T(T), U(RightAlt));
     break;

  case MACRO_ALT_GR_I:
     return MACRODOWN(D(RightAlt), T(D), U(RightAlt));
     break;

  case MACRO_ALT_GR_EQUALS:
     return MACRODOWN(D(RightAlt), T(Minus), U(RightAlt));
     break;

  case MACRO_ALT_GR_K:
     return MACRODOWN(D(RightAlt), T(B), U(RightAlt));
     break;

  case MACRO_ALT_GR_O:
     return MACRODOWN(D(RightAlt), T(R), U(RightAlt));
     break;

  case MACRO_ALT_GR_P:
     return MACRODOWN(D(RightAlt), T(E), U(RightAlt));
     break;

  case MACRO_ALT_GR_SPACE:
     if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(U(LeftShift)));
        return MACRODOWN(D(RightAlt), T(Space), U(RightAlt));
     } else {
        return MACRODOWN(D(RightAlt), T(Space), U(RightAlt));
     }
     break;

  case MACRO_ALT_GR_U:
     return MACRODOWN(D(RightAlt), T(S), U(RightAlt));
     break;

  case MACRO_ALT_GR_X:
     return MACRODOWN(D(RightAlt), T(C), U(RightAlt));
     break;

  case MACRO_ALT_GR_Y:
     return MACRODOWN(D(RightAlt), T(X), U(RightAlt));
     break;

  case MACRO_ALT_DOWN:
    return MACRODOWN(D(LeftAlt), T(DownArrow), U(LeftAlt));
    break;

  case MACRO_ALT_LEFT:
    return MACRODOWN(D(LeftAlt), T(LeftArrow), U(LeftAlt));
    break;

  case MACRO_ALT_RIGHT:
    return MACRODOWN(D(LeftAlt), T(RightArrow), U(LeftAlt));
    break;

  case MACRO_ALT_UP:
    return MACRODOWN(D(LeftAlt), T(UpArrow), U(LeftAlt));
    break;

  case MACRO_ALT_SPACE:
    return MACRODOWN(D(LeftAlt), T(Space), U(LeftAlt));
    break;

  case MACRO_COLON:
    return MACRODOWN(D(LeftShift), T(V), U(LeftShift));
    break;

  case MACRO_CTRL_A:
    return MACRODOWN(D(LeftControl), T(A), U(LeftControl));
    break;

  case MACRO_CTRL_C:
    return MACRODOWN(D(LeftControl), T(H), U(LeftControl));
    break;

  case MACRO_CTRL_COLON:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(V), U(LeftShift), U(LeftControl));
    break;

  case MACRO_CTRL_DIVIDE:
    return MACRODOWN(D(LeftControl), T(9), U(LeftControl));
    break;

  case MACRO_CTRL_DOWN:
    return MACRODOWN(D(LeftControl), T(DownArrow), U(LeftControl));
    break;

  case MACRO_CTRL_END:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(End), U(LeftControl));
    break;

  case MACRO_CTRL_F:
    return MACRODOWN(D(LeftControl), T(Slash), U(LeftControl));
    break;

  case MACRO_CTRL_F3:
    return MACRODOWN(D(LeftControl), T(F3), U(LeftControl));
    break;

  case MACRO_CTRL_G:
    return MACRODOWN(D(LeftControl), T(Comma), U(LeftControl));
    break;

  case MACRO_CTRL_H:
    return MACRODOWN(D(LeftControl), T(Period), U(LeftControl));
    break;

  case MACRO_CTRL_HOME:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(Home), U(LeftControl));
    break;

  case MACRO_CTRL_LEFT:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(LeftArrow), U(LeftControl));
    break;

  case MACRO_CTRL_LEFT_LEFT_LEFT_LEFT:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(LeftArrow), T(LeftArrow), T(LeftArrow), T(LeftArrow), U(LeftControl));
    break;

  case MACRO_CTRL_LEFT_PARENTHESIS:
    return MACRODOWN(D(LeftControl), T(4), U(LeftControl));
    break;

  case MACRO_CTRL_N:
    return MACRODOWN(D(LeftControl), T(Semicolon), U(LeftControl));
    break;

  case MACRO_CTRL_P:
    return MACRODOWN(D(LeftControl), T(E), U(LeftControl));
    break;

  case MACRO_CTRL_U:
    return MACRODOWN(D(LeftControl), T(S), U(LeftControl));
    break;

  case MACRO_CTRL_UP:
    return MACRODOWN(D(LeftControl), T(UpArrow), U(LeftControl));
    break;

  case MACRO_CTRL_RIGHT:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(RightArrow), U(LeftControl));
    break;


  case MACRO_CTRL_RIGHT_PARENTHESIS:
    return MACRODOWN(D(LeftControl), T(5), U(LeftControl));
    break;

  case MACRO_CTRL_RIGHT_RIGHT_RIGHT_RIGHT:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(RightArrow), T(RightArrow), T(RightArrow), T(RightArrow), U(LeftControl));
    break;

  case MACRO_CTRL_S:
    return MACRODOWN(D(LeftControl), T(K), U(LeftControl));
    break;

  case MACRO_CTRL_SHIFT_ENTER:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(Enter), U(LeftShift), U(LeftControl));
    break;

  case MACRO_CTRL_SHIFT_SPACE:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(Space), U(LeftShift), U(LeftControl));
    break;

  case MACRO_CTRL_T:
    return MACRODOWN(D(LeftControl), T(J), U(LeftControl));
    break;

  case MACRO_CTRL_V:
    return MACRODOWN(D(LeftControl), T(U), U(LeftControl));
    break;

  case MACRO_CTRL_W:
    return MACRODOWN(D(LeftControl), T(RightBracket), U(LeftControl));
    break;

  case MACRO_CTRL_X:
    return MACRODOWN(D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_CTRL_Z:
    return MACRODOWN(D(LeftControl), T(LeftBracket), U(LeftControl));
    break;

  case MACRO_EXCLAMATION_POINT:
    return MACRODOWN(D(LeftShift), T(Y), U(LeftShift));
    break;

  case MACRO_SEMICOLON:
    return MACRODOWN(D(LeftShift), T(G), U(LeftShift));
    break;

  case MACRO_SHIFT_CTRL_DOWN_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(DownArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_END_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(End), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_HOME_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(Home), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_LEFT_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(LeftArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_LEFT_LEFT_LEFT_LEFT_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(LeftArrow), T(LeftArrow), T(LeftArrow), T(LeftArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_RIGHT_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(RightArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_RIGHT_RIGHT_RIGHT_RIGHT_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(RightArrow), T(RightArrow), T(RightArrow), T(RightArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_CTRL_UP_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(UpArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_DOWN_CTRL_X:
    return MACRODOWN(D(LeftShift), T(DownArrow), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_END_CTRL_X:
    return MACRODOWN(D(LeftShift), T(End), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_HOME_CTRL_X:
    return MACRODOWN(D(LeftShift), T(Home), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_PG_DOWN_CTRL_X:
    return MACRODOWN(D(LeftShift), T(PageDown), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_PG_UP_CTRL_X:
    return MACRODOWN(D(LeftShift), T(PageUp), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_UP_CTRL_X:
    return MACRODOWN(D(LeftShift), T(UpArrow), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_SUPER_Z:
    return MACRODOWN(D(LeftShift), D(LeftGui), T(LeftBracket), U(LeftGui), U(LeftShift));
    break;

  case MACRO_SPACE:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift)) {
        return MACRODOWN(U(LeftShift), D(RightAlt), T(Space), U(RightAlt), D(LeftShift));
    } else {
        return MACRODOWN(T(Spacebar));
    }
    break;

  case MACRO_SUPER_CTRL_DOWN:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(DownArrow), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_END:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(End), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_HOME:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(Home), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_LEFT:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(LeftArrow), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_PAGE_DOWN:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(PageDown), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_PAGE_UP:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(PageUp), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_ALT_DOWN:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), D(LeftAlt), T(DownArrow), U(LeftAlt), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_ALT_LEFT:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), D(LeftAlt), T(LeftArrow), U(LeftAlt), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_ALT_RIGHT:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), D(LeftAlt), T(RightArrow), U(LeftAlt), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_ALT_UP:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), D(LeftAlt), T(UpArrow), U(LeftAlt), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_DOWN:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(DownArrow), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_END:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(End), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_HOME:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(Home), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_LEFT:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(LeftArrow), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_PAGE_DOWN:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(PageDown), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_PAGE_UP:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(PageUp), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_RIGHT:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(RightArrow), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_SHIFT_UP:
    return MACRODOWN(D(LeftGui), D(LeftControl), D(LeftShift), T(UpArrow), U(LeftShift), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_RIGHT:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(RightArrow), U(LeftControl), U(LeftGui));
    break;

  case MACRO_SUPER_CTRL_UP:
    return MACRODOWN(D(LeftGui), D(LeftControl), T(UpArrow), U(LeftControl), U(LeftGui));
    break;

  }
  return MACRO_NONE;
}


// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.

static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    //LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    //LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

// /**
//  * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
//  * a function with an unused argument, to match what MagicCombo expects.
//  */
// static void toggleKeyboardProtocol(uint8_t combo_index) {
//   USBQuirks.toggleKeyboardProtocol();
// }
//
// /**
//  *  This enters the hardware test mode
//  */
// static void enterHardwareTestMode(uint8_t combo_index) {
//   HardwareTestMode.runTests();
// }

// static void playMacroShiftSuperZ(uint8_t combo_index) {
//   Macros.play(MACRO(T(Backspace), T(Backspace), D(LeftShift), D(LeftGui), T(LeftBracket), U(LeftGui), U(LeftShift)));
// }
//
// static void playMacroAltSpace(uint8_t combo_index) {
//   Macros.play(MACRO(T(Backspace), T(Backspace), D(LeftAlt), T(Space), U(LeftAlt)));
// }
//
// static void playMacroAltTab(uint8_t combo_index) {
//   Macros.play(MACRO(D(LeftAlt), T(Tab)));
// }


// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.

KALEIDOSCOPE_INIT_PLUGINS(

  // Qukeys
  Qukeys, // Used : 4.5

  // Leader
  Leader, // Used : 2.1

  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings, //0.6
  EEPROMKeymap, //2.4

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  //Focus, // 8.9

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  //FocusSettingsCommand, //1.7

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  //FocusEEPROMCommand, //1.0

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  //BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  //HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl, //Used : 3.5

  // ActiveModColorEffect (need LEDControl and OneShot)
  ActiveModColorEffect, // Used a little 2.1

  // We start with the LED effect that turns off all the LEDs.
  LEDOff, //O.0  (Absolutely needed)

  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
//  LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
//  LEDRainbowWaveEffect,

  // The chase effect follows the adventure of a blue pixel which chases a red pixel across
  // your keyboard. Spoiler: the blue pixel never catches the red pixel
//  LEDChaseEffect,

  // These static effects turn your keyboard's LEDs a variety of colors
//  solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet,

  // The breathe effect slowly pulses all of the LEDs on your keyboard
//  LEDBreatheEffect,

  // The AlphaSquare effect prints each character you type, using your
  // keyboard's LEDs as a display
  //AlphaSquareEffect,

  // The stalker effect lights up the keys you've pressed recently
  //StalkerEffect,

  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  //LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  //ColormapEffect,


  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  //NumPad,

  //OneShot,
  OneShot, // Used :  3.4

  // The macros plugin adds support for macros
  Macros, // Used

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  //MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  //HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  //MagicCombo,

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks //0.1 (Absolutely needed)
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {

  //Qukeys
  QUKEYS(
       kaleidoscope::plugin::Qukey(0, KeyAddr(1, 7), ShiftToLayer(NUMPAD)),
       kaleidoscope::plugin::Qukey(0, KeyAddr(1, 8), ShiftToLayer(ALTGR)),
       kaleidoscope::plugin::Qukey(0, KeyAddr(3, 6), ShiftToLayer(FUNCTION)),
       kaleidoscope::plugin::Qukey(0, KeyAddr(3, 9), ShiftToLayer(CUT))
  )

  Qukeys.setHoldTimeout(180);

  //OneShot
  OneShot.time_out = 500;

  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // Leader
  Leader.dictionary = leader_dictionary;
  Leader.time_out = 2000;

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  //NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  AlphaSquare.color = CRGB(255, 0, 0);

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  // The LED Stalker mode has a few effects. The one we like is called
  // 'BlazingTrail'. For details on other options, see
  // https://github.com/keyboardio/Kaleidoscope/blob/master/docs/plugins/LED-Stalker.md
  StalkerEffect.variant = STALKER(BlazingTrail);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(5);

  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to five layers, which is how
  // many editable layers we have (see above).
  ColormapEffect.max_layers(5);

}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
