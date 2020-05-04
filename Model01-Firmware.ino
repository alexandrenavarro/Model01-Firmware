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
#include "Kaleidoscope-MagicCombo.h"

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

enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       MACRO_0,
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
       MACRO_ALT_D,
       MACRO_ALT_ENTER,
       MACRO_ALT_F4,
       MACRO_ALT_F6,
       MACRO_ALT_F7,
       MACRO_ALT_GR_1,
       MACRO_ALT_GR_2,
       MACRO_ALT_GR_3,
       MACRO_ALT_GR_4,
       MACRO_ALT_GR_5,
       MACRO_ALT_GR_A,
       MACRO_ALT_GR_A_AIGU,
       MACRO_ALT_GR_B,
       MACRO_ALT_GR_COMMA,
       MACRO_ALT_GR_DOLLAR,
       MACRO_ALT_GR_DOT,
       MACRO_ALT_GR_E,
       MACRO_ALT_GR_EQUALS,
       MACRO_ALT_GR_E_AIGU,
       MACRO_ALT_GR_E_GRAVE,
       MACRO_ALT_GR_E_CIRC,
       MACRO_ALT_GR_I,
       MACRO_ALT_GR_K,
       MACRO_ALT_GR_O,
       MACRO_ALT_GR_P,
       MACRO_ALT_GR_SPACE,
       MACRO_ALT_GR_U,
       MACRO_ALT_GR_W,
       MACRO_ALT_GR_X,
       MACRO_ALT_GR_Y,
       MACRO_ALT_DOWN,
       MACRO_ALT_LEFT,
       MACRO_ALT_RIGHT,
       MACRO_ALT_UP,
       MACRO_ALT_SHIFT_TAB,
       MACRO_ALT_SPACE,
       MACRO_ALT_TAB,
       MACRO_ALT_TAB_DOWN,
       MACRO_COLON,
       MACRO_COLON_Q_EXCLAMATION_POINT,
       MACRO_COLON_W_EXCLAMATION_POINT,
       MACRO_CTRL_A,
       MACRO_CTRL_ALT_B,
       MACRO_CTRL_ALT_GR_3,
       MACRO_CTRL_ALT_GR_4,
       MACRO_CTRL_ALT_SHIFT_T,
       MACRO_CTRL_BRACKET_LEFT,
       MACRO_CTRL_BRACKET_RIGHT,
       MACRO_CTRL_C,
       MACRO_CTRL_DIVIDE,
       MACRO_CTRL_DOWN,
       MACRO_CTRL_END,
       MACRO_CTRL_F,
       MACRO_CTRL_F3,
       MACRO_CTRL_F4,
       MACRO_CTRL_G,
       MACRO_CTRL_HOME,
       MACRO_CTRL_K,
       MACRO_CTRL_LEFT,
       MACRO_CTRL_LEFT_LEFT,
       MACRO_CTRL_L,
       MACRO_CTRL_N,
       MACRO_CTRL_O,
       MACRO_CTRL_P,
       MACRO_CTRL_PAGE_DOWN,
       MACRO_CTRL_PAGE_DOWN_ALT_PERIOD,
       MACRO_CTRL_PAGE_UP,
       MACRO_CTRL_PAGE_UP_ALT_COMMA,
       MACRO_CTRL_U,
       MACRO_CTRL_UP,
       MACRO_CTRL_R,
       MACRO_CTRL_RIGHT,
       MACRO_CTRL_RIGHT_RIGHT,
       MACRO_CTRL_S,
       MACRO_CTRL_SHIFT_ENTER,
       MACRO_CTRL_SHIFT_SPACE,
       MACRO_CTRL_SHIFT_W,
       MACRO_CTRL_SHIFT_Z,
       MACRO_CTRL_T,
       MACRO_CTRL_TAB,
       MACRO_CTRL_SHIFT_TAB,
       MACRO_CTRL_V,
       MACRO_CTRL_W,
       MACRO_CTRL_X,
       MACRO_CTRL_Y,
       MACRO_CTRL_Z,
       MACRO_END_SEMICOLON,
       MACRO_END_SEMICOLON_ENTER,
       MACRO_EXCLAMATION_POINT,
       MACRO_LEFT_CURLY_BRACKET,
       MACRO_MOUSE_NW_NW_NW,
       MACRO_MOUSE_SW_SW_SW,
       MACRO_MOUSE_NE_NE_NE,
       MACRO_MOUSE_SE_SE_SE,
       MACRO_SEMICOLON,
       MACRO_SHIFT_CTRL_END_X,
       MACRO_SHIFT_CTRL_HOME_X,
       MACRO_SHIFT_CTRL_LEFT_X,
       MACRO_SHIFT_CTRL_RIGHT_X,
       MACRO_SHIFT_DOWN_CTRL_X,
       MACRO_SHIFT_END_CTRL_X,
       MACRO_SHIFT_HOME_CTRL_X,
       MACRO_SHIFT_LEFT_CTRL_X,
       MACRO_SHIFT_PG_DOWN_CTRL_X,
       MACRO_SHIFT_PG_UP_CTRL_X,
       MACRO_SHIFT_RIGHT_CTRL_X,
       MACRO_SHIFT_UP_CTRL_X,
       MACRO_SHIFT_SUPER_Z,
       MACRO_SHIFT_TAB,
       MACRO_SPACE,
       MACRO_SPACE_EQUALS_SPACE,
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
       MACRO_SUPER_DOWN,
       MACRO_SUPER_LEFT,
       MACRO_SUPER_M,
       MACRO_SUPER_RIGHT,
       MACRO_SUPER_TAB,
       MACRO_SUPER_UP,
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

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
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

   M(MACRO_ANY),   Key_6, Key_7, Key_8, Key_9, Key_0, LockLayer(NUMPAD),
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

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
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
  (Key_Insert,                             Key_1,                                  M(MACRO_ALT_GR_2),                      M(MACRO_ALT_GR_3),                      Key_4,                        Key_5,                              M(MACRO_COLON),
   Key_Backtick,                           Key_Q,                                  Key_W,                                  Key_E,                                  Key_R,                        Key_T,                              Key_Tab,
   Key_RightBracket,                       Key_A,                                  Key_S,                                  Key_D,                                  Key_F,                        Key_G,
   Key_Minus,                              Key_Z,                                  Key_X,                                  Key_C,                                  Key_V,                        Key_B,                              Key_Escape,
   OSM(LeftShift),                         Key_Backspace,                          OSM(LeftControl),                       OSM(LeftAlt),
   LEAD(0),

   ___,                                    Key_6,                                  Key_7,                                  Key_8,                                  Key_9,                        Key_0,                              Key_Equals,
   LEAD(0),                                Key_Y,                                  Key_U,                                  Key_I,                                  Key_O,                        Key_P,                              Key_LeftBracket,
                                           Key_H,                                  Key_J,                                  Key_K,                                  Key_L,                        Key_Semicolon,                      Key_Quote,
   M(MACRO_ALT_SPACE),                     Key_N,                                  Key_M,                                  Key_Comma,                              Key_Period,                   Key_Slash,                          Key_Backslash,
   Key_LeftGui,                            Key_Enter,                              Key_Spacebar,                           OSM(LeftShift),
   M(MACRO_SHIFT_SUPER_Z)),

#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif
  [FUNCTION] =  KEYMAP_STACKED
  (M(MACRO_CTRL_P),                        Key_F1,                                 Key_F2,                                 Key_F3,                                 Key_F4,                                 Key_F5,                                  M(MACRO_CTRL_A),
   M(MACRO_CTRL_N),                        M(MACRO_CTRL_S),                        M(MACRO_CTRL_F3),                       M(MACRO_CTRL_T),                        M(MACRO_CTRL_W),                        M(MACRO_ALT_F4),                         M(MACRO_CTRL_R),
   Key_Delete,                             M(MACRO_CTRL_Z),                        M(MACRO_CTRL_X),                        M(MACRO_CTRL_C),                        M(MACRO_CTRL_V),                        M(MACRO_CTRL_F),
   M(MACRO_CTRL_DIVIDE),                   M(MACRO_ALT_LEFT),                      M(MACRO_CTRL_PAGE_UP_ALT_COMMA),        M(MACRO_CTRL_PAGE_DOWN_ALT_PERIOD),     Key_F4,                                 M(MACRO_ALT_F7),                         M(MACRO_ALT_RIGHT),
   Key_LeftShift,                          Key_Enter,                              Key_LeftControl,                        Key_LeftAlt,
   ___,

   Key_F12,                                Key_F6,                                 Key_F7,                                 Key_F8,                                 Key_F9,                                 Key_F10,                                 Key_F11,
   M(MACRO_CTRL_ALT_SHIFT_T),              M(MACRO_CTRL_SHIFT_W),                  M(MACRO_CTRL_BRACKET_LEFT),             M(MACRO_CTRL_DOWN),                     M(MACRO_CTRL_UP),                       M(MACRO_CTRL_BRACKET_RIGHT),             M(MACRO_CTRL_W),
                                           Key_Home,                               Key_LeftArrow,                          Key_DownArrow,                          Key_UpArrow,                            Key_RightArrow,                          Key_End,
   Key_PcApplication,                      M(MACRO_CTRL_HOME),                     M(MACRO_CTRL_LEFT),                     Key_PageDown,                           Key_PageUp,                             M(MACRO_CTRL_RIGHT),                     M(MACRO_CTRL_END),
   ___,                                    M(MACRO_CTRL_SHIFT_ENTER),              M(MACRO_CTRL_SHIFT_SPACE),              ___,
   M(MACRO_ALT_1)),

  [NUMPAD] =  KEYMAP_STACKED
  (___,                                    ___,                                    ___,                                    ___,                                    ___,                                    ___,                                     ___,
   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                    ___,                                     ___,
   M(MACRO_CTRL_G),                        M(MACRO_1),                             M(MACRO_2),                             M(MACRO_3),                             M(MACRO_4),                             M(MACRO_5),
   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                    ___,                                     ___,
   ___, ___, ___, ___,
   ___,

   ___,                                    ___,                                    Key_KeypadAdd,                          Key_KeypadSubtract,                     Key_KeypadDivide,                       Key_KeypadMultiply,                      ___,
   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                    ___,                                     ___,
                                           M(MACRO_6),                             M(MACRO_7),                             M(MACRO_8),                             M(MACRO_9),                             M(MACRO_0),                              M(MACRO_CTRL_K),
   ___,                                    M(MACRO_CTRL_U),                        M(MACRO_CTRL_W),                        ___,                                    ___,                                    M(MACRO_ALT_D),                          ___,
   ___,                                    ___,                                    Key_Backspace,                          ___,
   ___),

   [ALTGR] =  KEYMAP_STACKED
   (___,                                   M(MACRO_ALT_GR_1),                      Key_2,                                  Key_3,                                  M(MACRO_ALT_GR_4),                      M(MACRO_ALT_GR_5),                        ___,
    M(MACRO_ALT_GR_DOLLAR),                M(MACRO_ALT_GR_B),                      M(MACRO_ALT_GR_E_AIGU),                 M(MACRO_ALT_GR_P),                      M(MACRO_ALT_GR_O),                      M(MACRO_ALT_GR_E_GRAVE),                  ___,
    M(MACRO_EXCLAMATION_POINT),            M(MACRO_ALT_GR_A),                      M(MACRO_ALT_GR_U),                      M(MACRO_COLON),                         M(MACRO_SEMICOLON),                     M(MACRO_ALT_GR_E),
    M(MACRO_ALT_GR_EQUALS),                M(MACRO_ALT_GR_A_AIGU),                 M(MACRO_ALT_GR_Y),                      M(MACRO_ALT_GR_X),                      M(MACRO_ALT_GR_I),                      M(MACRO_ALT_GR_K),                        ___,
    ___, Key_Spacebar, ___, ___,
    ___,

    ___,                                   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                      ___,
    ___,                                   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                      ___,
                                           ___,                                    ___,                                    ___,                                    ___,                                    ___,                                      ___,
    ___,                                   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                      ___,
    ___,                                   ___,                                    ___,                                    ___,
    ___),

  [CUT] =  KEYMAP_STACKED
   (Key_PrintScreen,                       ___,                                    M(MACRO_SUPER_CTRL_SHIFT_ALT_DOWN),     M(MACRO_SUPER_CTRL_SHIFT_ALT_UP),       ___,                                    ___,                                     ___,
    M(MACRO_SUPER_CTRL_SHIFT_HOME),        M(MACRO_SUPER_CTRL_HOME),               M(MACRO_SUPER_CTRL_SHIFT_DOWN),         M(MACRO_SUPER_CTRL_SHIFT_UP),           M(MACRO_SUPER_CTRL_PAGE_UP),            M(MACRO_SUPER_CTRL_SHIFT_PAGE_UP),       ___,
    M(MACRO_SUPER_CTRL_SHIFT_LEFT),        M(MACRO_SUPER_CTRL_LEFT),               M(MACRO_SUPER_CTRL_DOWN),               M(MACRO_SUPER_CTRL_UP),                 M(MACRO_SUPER_CTRL_RIGHT),              M(MACRO_SUPER_CTRL_SHIFT_RIGHT),
    M(MACRO_SUPER_CTRL_SHIFT_END),         M(MACRO_SUPER_CTRL_END),                M(MACRO_SUPER_CTRL_SHIFT_ALT_LEFT),     M(MACRO_SUPER_CTRL_SHIFT_ALT_RIGHT),    M(MACRO_SUPER_CTRL_PAGE_DOWN),          M(MACRO_SUPER_CTRL_SHIFT_PAGE_DOWN),     ___,
    ___, ___, ___, ___,
    ___,

    ___,                                   ___,                                    ___,                                    ___,                                    ___,                                    ___,                                 ___,
    ___,                                   ___,                                    M(MACRO_SUPER_LEFT),                    M(MACRO_SUPER_DOWN),                    M(MACRO_SUPER_UP),                      M(MACRO_SUPER_RIGHT),                ___,
                                           M(MACRO_SHIFT_HOME_CTRL_X),             Key_Backspace,                          M(MACRO_SHIFT_DOWN_CTRL_X),             M(MACRO_SHIFT_UP_CTRL_X),               Key_Delete,                          M(MACRO_SHIFT_END_CTRL_X),
    ___,                                   M(MACRO_SHIFT_CTRL_HOME_X),             M(MACRO_SHIFT_CTRL_LEFT_X),             M(MACRO_SHIFT_PG_DOWN_CTRL_X),          M(MACRO_SHIFT_PG_UP_CTRL_X),            M(MACRO_SHIFT_CTRL_RIGHT_X),         M(MACRO_SHIFT_CTRL_END_X),
    ___,                                   M(MACRO_ALT_ENTER),                     M(MACRO_ALT_GR_SPACE),                  Key_LeftShift,
    ___)

) // KEYMAPS(


// Leader plugin
// Move (jkl), Go (g), Undo (u), Paste (p) Comment (?)
static void moveNNextChar(uint8_t seq_index, int n) {
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(RightArrow)));
    }
}
static void move1NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 1);}
static void move2NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 2);}
static void move3NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 3);}
static void move4NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 4);}
static void move5NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 5);}
static void move6NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 6);}
static void move7NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 7);}
static void move8NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 8);}
static void move9NextChar(uint8_t seq_index) { moveNNextChar(seq_index, 9);}

// Delete () / Cut (d) / Copy (y)
static void leader_1dd(uint8_t seq_index) { leader_ndd(seq_index, 1);}
static void leader_2dd(uint8_t seq_index) { leader_ndd(seq_index, 2);}
static void leader_3dd(uint8_t seq_index) { leader_ndd(seq_index, 3);}
static void leader_4dd(uint8_t seq_index) { leader_ndd(seq_index, 4);}
static void leader_5dd(uint8_t seq_index) { leader_ndd(seq_index, 5);}
static void leader_6dd(uint8_t seq_index) { leader_ndd(seq_index, 6);}
static void leader_7dd(uint8_t seq_index) { leader_ndd(seq_index, 7);}
static void leader_8dd(uint8_t seq_index) { leader_ndd(seq_index, 8);}
static void leader_9dd(uint8_t seq_index) { leader_ndd(seq_index, 9);}

static void test(uint8_t seq_index, int n, macro_t* macro) {
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(T(Home), D(LeftShift), T(End), U(LeftShift), T(Delete)));
    }
    Macros.play(macro);
}

static void leader_ndd(uint8_t seq_index, int n) {
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(T(Home), D(LeftShift), T(End), U(LeftShift), T(Delete)));
    }
    Macros.play(MACRO(T(Backspace)));
}

static void leader_nd0(uint8_t seq_index, int n) {
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftShift), T(Home), U(LeftShift), T(Delete)));
    }
}

static void leader_ndb(uint8_t seq_index, int n) {
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftShift), D(LeftControl), D(LeftArrow), U(LeftControl), U(LeftShift), T(Delete)));
    }
}

static void leader_ng(uint8_t seq_index, int n) {
    for (int i = 0; i < n; i++) {
        Macros.play(MACRO(D(LeftControl), T(Comma), U(LeftControl)));
    }
}


static void leader_dw(uint8_t seq_index) {
    Macros.play(MACRO(D(LeftShift), D(LeftControl), T(RightArrow), U(LeftControl), U(LeftShift), T(Delete)));
}
//   Key_RightBracket,                       Key_A,                                  Key_S,                                  Key_D,                                  Key_F,                        Key_G,
//                                           Key_H,                                  Key_J,                                  Key_K,                                  Key_L,                        Key_Semicolon,                      Key_Quote,

 static const kaleidoscope::plugin::Leader::dictionary_t leader_dictionary[] PROGMEM =
 LEADER_DICT(
  { LEADER_SEQ(LEAD(0), Key_RightBracket, Key_P), leader_dw},
//  { LEADER_SEQ(LEAD(0), Key_RightBracket, Key_RightBracket), leader_1dd},
//  { LEADER_SEQ(LEAD(0), Key_1, Key_RightBracket, Key_RightBracket), leader_1dd},
// { LEADER_SEQ(LEAD(0), Key_2, Key_RightBracket, Key_RightBracket), leader_2dd},
//  { LEADER_SEQ(LEAD(0), Key_3, Key_RightBracket, Key_RightBracket), leader_3dd},
//  { LEADER_SEQ(LEAD(0), Key_4, Key_RightBracket, Key_RightBracket), leader_4dd},
//  { LEADER_SEQ(LEAD(0), Key_5, Key_RightBracket, Key_RightBracket), leader_5dd},
//  { LEADER_SEQ(LEAD(0), Key_6, Key_RightBracket, Key_RightBracket), leader_6dd},
//  { LEADER_SEQ(LEAD(0), Key_7, Key_RightBracket, Key_RightBracket), leader_7dd},
//  { LEADER_SEQ(LEAD(0), Key_8, Key_RightBracket, Key_RightBracket), leader_8dd},
//  { LEADER_SEQ(LEAD(0), Key_9, Key_RightBracket, Key_RightBracket), leader_9dd},

    { LEADER_SEQ(LEAD(0), Key_Semicolon), move1NextChar},
    { LEADER_SEQ(LEAD(0), Key_1, Key_Semicolon), move1NextChar},
    { LEADER_SEQ(LEAD(0), Key_A, Key_Spacebar, Key_Semicolon), move1NextChar},
    { LEADER_SEQ(LEAD(0), Key_S, Key_Spacebar, Key_Semicolon), move2NextChar},
    { LEADER_SEQ(LEAD(0), Key_D, Key_Spacebar, Key_Semicolon), move3NextChar},
    { LEADER_SEQ(LEAD(0), Key_F, Key_Spacebar, Key_Semicolon), move4NextChar},
    { LEADER_SEQ(LEAD(0), Key_4, Key_Semicolon), move4NextChar},
    { LEADER_SEQ(LEAD(0), Key_G, Key_Spacebar, Key_Semicolon), move5NextChar},
    { LEADER_SEQ(LEAD(0), Key_H, Key_Spacebar, Key_Semicolon), move6NextChar},
    { LEADER_SEQ(LEAD(0), Key_J, Key_Spacebar, Key_Semicolon), move7NextChar},
    { LEADER_SEQ(LEAD(0), Key_K, Key_Spacebar, Key_Semicolon), move8NextChar},
    { LEADER_SEQ(LEAD(0), Key_L, Key_Spacebar, Key_Semicolon), move9NextChar}
  );



/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
//   static Key lastKey;
//   bool toggledOn = false;
//   if (keyToggledOn(keyState)) {
//     lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
//     toggledOn = true;
//   }
//
//   if (keyIsPressed(keyState))
//     Kaleidoscope.hid().keyboard().pressKey(lastKey, toggledOn);
}


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

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;

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

  case MACRO_ALT_D:
    return MACRODOWN(D(LeftAlt), T(I), U(LeftAlt));
    break;

  case MACRO_ALT_ENTER:
    return MACRODOWN(D(LeftAlt), T(Enter), U(LeftAlt));
    break;

  case MACRO_ALT_F4:
    return MACRODOWN(D(LeftAlt), T(F4), U(LeftAlt));
    break;

  case MACRO_ALT_F6:
    return MACRODOWN(D(LeftAlt), T(F6), U(LeftAlt));
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

  case MACRO_ALT_GR_COMMA:
     return MACRODOWN(D(RightAlt), T(G), U(RightAlt));
     break;

  case MACRO_ALT_GR_DOLLAR:
    return MACRODOWN(D(RightAlt), T(Backtick), U(RightAlt));
    break;

  case MACRO_ALT_GR_DOT:
     return MACRODOWN(D(RightAlt), T(V), U(RightAlt));
     break;

  case MACRO_ALT_GR_E:
     return MACRODOWN(D(RightAlt), T(F), U(RightAlt));
     break;

  case MACRO_ALT_GR_E_AIGU:
     return MACRODOWN(D(RightAlt), T(W), U(RightAlt));
     break;

  case MACRO_ALT_GR_E_CIRC:
     return MACRODOWN(D(RightAlt), T(NonUsBackslashAndPipe), U(RightAlt));
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
     if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(U(LeftShift)));
        return MACRODOWN(D(RightAlt), T(Space), U(RightAlt));
     } else {
       return MACRODOWN(D(RightAlt), T(Space), U(RightAlt));
     }
     break;

  case MACRO_ALT_GR_U:
     return MACRODOWN(D(RightAlt), T(S), U(RightAlt));
     break;

  case MACRO_ALT_GR_W:
    return MACRODOWN(D(RightAlt), T(Backtick), U(RightAlt));
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

  case MACRO_ALT_SHIFT_TAB:
    return MACRODOWN(D(LeftAlt), D(LeftShift), T(Tab), U(LeftShift), U(LeftAlt));
    break;

  case MACRO_ALT_TAB:
    return MACRODOWN(D(LeftAlt), T(Tab), U(LeftAlt));
    break;

  case MACRO_ALT_TAB_DOWN:
    return MACRODOWN(D(LeftAlt), T(Tab));
    break;

  case MACRO_COLON:
    return MACRODOWN(D(LeftShift), T(V), U(LeftShift));
    break;

  case MACRO_COLON_Q_EXCLAMATION_POINT:
    return MACRODOWN(D(LeftShift), T(V), U(LeftShift), T(M), D(LeftShift), T(Y), U(LeftShift), T(Enter));
    break;

  case MACRO_COLON_W_EXCLAMATION_POINT:
    return MACRODOWN(D(LeftShift), T(V), U(LeftShift), T(RightBracket), D(LeftShift), T(Y), U(LeftShift), T(Enter));
    break;

  case MACRO_CTRL_A:
    return MACRODOWN(D(LeftControl), T(A), U(LeftControl));
    break;

  case MACRO_CTRL_ALT_B:
    return MACRODOWN(D(LeftControl), D(LeftAlt), T(Q), U(LeftAlt), U(LeftControl));
    break;

  case MACRO_CTRL_ALT_GR_3:
    return MACRODOWN(D(LeftControl), D(RightAlt), T(3), U(RightAlt), U(LeftControl));
    break;

  case MACRO_CTRL_ALT_GR_4:
    return MACRODOWN(D(LeftControl), D(RightAlt), T(4), U(RightAlt), U(LeftControl));
    break;

  case MACRO_CTRL_ALT_SHIFT_T:
    return MACRODOWN(D(LeftControl), D(LeftAlt), D(LeftShift), T(J), U(LeftShift), U(LeftAlt), U(LeftControl));
    break;

  case MACRO_CTRL_BRACKET_LEFT:
    return MACRODOWN(D(LeftControl), D(RightAlt), T(4), U(RightAlt), U(LeftControl));
    break;

  case MACRO_CTRL_BRACKET_RIGHT:
    return MACRODOWN(D(LeftControl), D(RightAlt), T(5), U(RightAlt), U(LeftControl));
    break;

  case MACRO_CTRL_C:
    return MACRODOWN(D(LeftControl), T(H), U(LeftControl));
    break;

  case MACRO_CTRL_DIVIDE:
    return MACRODOWN(D(LeftControl), T(9), U(LeftControl));
    break;

  case MACRO_CTRL_DOWN:
    return MACRODOWN(D(LeftControl), T(DownArrow), U(LeftControl));
    break;

  case MACRO_CTRL_END:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftGui) || kaleidoscope::hid::wasModifierKeyActive(Key_RightGui)) {
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

  case MACRO_CTRL_F4:
    return MACRODOWN(D(LeftControl), T(F4), U(LeftControl));
    break;

  case MACRO_CTRL_G:
    return MACRODOWN(D(LeftControl), T(Comma), U(LeftControl));
    break;

  case MACRO_CTRL_HOME:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftGui) || kaleidoscope::hid::wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(Home), U(LeftControl));
    break;

  case MACRO_CTRL_K:
     return MACRODOWN(D(LeftControl), T(B), U(LeftControl));
     break;

  case MACRO_CTRL_LEFT:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftGui) || kaleidoscope::hid::wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(LeftArrow), U(LeftControl));
    break;

  case MACRO_CTRL_LEFT_LEFT:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftGui) || kaleidoscope::hid::wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(LeftArrow), T(LeftArrow), U(LeftControl));
    break;

  case MACRO_CTRL_L:
    return MACRODOWN(D(LeftControl), T(O), U(LeftControl));
    break;

  case MACRO_CTRL_N:
    return MACRODOWN(D(LeftControl), T(Semicolon), U(LeftControl));
    break;

  case MACRO_CTRL_O:
    return MACRODOWN(D(LeftControl), T(R), U(LeftControl));
    break;

  case MACRO_CTRL_P:
    return MACRODOWN(D(LeftControl), T(E), U(LeftControl));
    break;

  case MACRO_CTRL_PAGE_DOWN:
    return MACRODOWN(D(LeftControl), T(PageDown), U(LeftControl));
    break;

  case MACRO_CTRL_PAGE_DOWN_ALT_PERIOD:
    return MACRODOWN(D(LeftControl), T(PageDown), U(LeftControl), D(LeftAlt), T(V), U(LeftAlt));
    break;

  case MACRO_CTRL_PAGE_UP:
    return MACRODOWN(D(LeftControl), T(PageUp), U(LeftControl));
    break;

  case MACRO_CTRL_PAGE_UP_ALT_COMMA:
    return MACRODOWN(D(LeftControl), T(PageUp), U(LeftControl), D(LeftAlt), T(G), U(LeftAlt));
    break;

  case MACRO_CTRL_R:
    return MACRODOWN(D(LeftControl), T(L), U(LeftControl));
    break;

  case MACRO_CTRL_U:
    return MACRODOWN(D(LeftControl), T(S), U(LeftControl));
    break;

  case MACRO_CTRL_UP:
    return MACRODOWN(D(LeftControl), T(UpArrow), U(LeftControl));
    break;

  case MACRO_CTRL_RIGHT:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftGui) || kaleidoscope::hid::wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(RightArrow), U(LeftControl));
    break;

  case MACRO_CTRL_RIGHT_RIGHT:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        Macros.play(MACRODOWN(D(LeftShift)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftAlt)) {
        Macros.play(MACRODOWN(D(LeftAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_RightAlt)) {
        Macros.play(MACRODOWN(D(RightAlt)));
    }
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftGui) || kaleidoscope::hid::wasModifierKeyActive(Key_RightGui)) {
        Macros.play(MACRODOWN(D(LeftGui)));
    }
    return MACRODOWN(D(LeftControl), T(RightArrow), T(RightArrow), U(LeftControl));
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

  case MACRO_CTRL_SHIFT_W:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(RightBracket), U(LeftShift), U(LeftControl));
    break;

  case MACRO_CTRL_SHIFT_Z:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(LeftBracket), U(LeftShift), U(LeftControl));
    break;

  case MACRO_CTRL_T:
    return MACRODOWN(D(LeftControl), T(J), U(LeftControl));
    break;

  case MACRO_CTRL_TAB:
    return MACRODOWN(D(LeftControl), T(Tab), U(LeftControl));
    break;

  case MACRO_CTRL_SHIFT_TAB:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(Tab), U(LeftShift), U(LeftControl));
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

  case MACRO_CTRL_Y:
    return MACRODOWN(D(LeftControl), T(X), U(LeftControl));
    break;

  case MACRO_CTRL_Z:
    return MACRODOWN(D(LeftControl), T(LeftBracket), U(LeftControl));
    break;

  case MACRO_END_SEMICOLON:
    return MACRODOWN(T(End), D(LeftShift), T(G), D(LeftShift));
    break;

  case MACRO_END_SEMICOLON_ENTER:
    return MACRODOWN(T(End), D(LeftShift), T(G), D(LeftShift), T(Enter));
    break;

  case MACRO_EXCLAMATION_POINT:
    return MACRODOWN(D(LeftShift), T(Y), U(LeftShift));
    break;

  case MACRO_LEFT_CURLY_BRACKET:
    return MACRODOWN(D(RightAlt), T(X), U(RightAlt));
    break;

  case MACRO_MOUSE_NW_NW_NW:
    return MACRODOWN(T(mouseWarpNW), T(mouseWarpNW), T(mouseWarpNW), T(mouseWarpEnd));
    break;

  case MACRO_MOUSE_SW_SW_SW:
    return MACRODOWN(T(mouseWarpSW), T(mouseWarpSW), T(mouseWarpSW), T(mouseWarpEnd));
    break;

  case MACRO_MOUSE_NE_NE_NE:
    return MACRODOWN(T(mouseWarpNE), T(mouseWarpNE), T(mouseWarpNE), T(mouseWarpEnd));
    break;

  case MACRO_MOUSE_SE_SE_SE:
    return MACRODOWN(T(mouseWarpSE), T(mouseWarpSE), T(mouseWarpSE), T(mouseWarpEnd));
    break;

  case MACRO_SEMICOLON:
    return MACRODOWN(D(LeftShift), T(G), U(LeftShift));
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

  case MACRO_SHIFT_CTRL_RIGHT_X:
    return MACRODOWN(D(LeftShift), D(LeftControl), T(RightArrow), U(LeftControl), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
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

  case MACRO_SHIFT_LEFT_CTRL_X:
    return MACRODOWN(D(LeftShift), T(LeftArrow), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_PG_DOWN_CTRL_X:
    return MACRODOWN(D(LeftShift), T(PageDown), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_PG_UP_CTRL_X:
    return MACRODOWN(D(LeftShift), T(PageUp), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_RIGHT_CTRL_X:
    return MACRODOWN(D(LeftShift), T(RightArrow), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_UP_CTRL_X:
    return MACRODOWN(D(LeftShift), T(UpArrow), U(LeftShift), D(LeftControl), T(C), U(LeftControl));
    break;

  case MACRO_SHIFT_SUPER_Z:
    return MACRODOWN(D(LeftShift), D(LeftGui), T(LeftBracket), U(LeftGui), U(LeftShift));
    break;

  case MACRO_SHIFT_TAB:
    return MACRODOWN(D(LeftShift), T(Tab), U(LeftShift));
    break;

  case MACRO_SPACE:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift)) {
        return MACRODOWN(U(LeftShift), T(Space));
    } else {
        return MACRODOWN(T(Space));
    }
    break;

  case MACRO_SPACE_EQUALS_SPACE:
    return MACRODOWN(T(Spacebar), T(Minus), T(Spacebar));
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

  case MACRO_SUPER_DOWN:
    return MACRODOWN(D(LeftGui), D(DownArrow), U(DownArrow), U(LeftGui));
    break;

  case MACRO_SUPER_LEFT:
    return MACRODOWN(D(LeftGui), D(LeftArrow), U(LeftArrow), U(LeftGui), W(50), T(Esc), W(50), T(Esc));
    break;

  case MACRO_SUPER_M:
    return MACRODOWN(D(LeftGui), T(Quote), U(LeftGui));
    break;

  case MACRO_SUPER_RIGHT:
    return MACRODOWN(D(LeftGui), D(RightArrow), U(RightArrow), U(LeftGui), W(50), T(Esc), W(50), T(Esc));
    break;

  case MACRO_SUPER_TAB:
    return MACRODOWN(D(LeftGui), T(Tab), U(LeftGui));
    break;

  case MACRO_SUPER_UP:
    return MACRODOWN(D(LeftGui), D(UpArrow), U(UpArrow), U(LeftGui));
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

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}

static void playMacroShiftSuperZ(uint8_t combo_index) {
  Macros.play(MACRO(T(Backspace), T(Backspace), D(LeftShift), D(LeftGui), T(LeftBracket), U(LeftGui), U(LeftShift)));
}

static void playMacroAltSpace(uint8_t combo_index) {
  Macros.play(MACRO(T(Backspace), T(Backspace), D(LeftAlt), T(Space), U(LeftAlt)));
}

static void playMacroAltTab(uint8_t combo_index) {
  Macros.play(MACRO(D(LeftAlt), T(Tab)));
}



// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.

KALEIDOSCOPE_INIT_PLUGINS(

  // Qukeys
  Qukeys,

  // Leader
  Leader,

  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  //BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  //HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

  // ActiveModColorEffect (need LEDControl and OneShot)
  ActiveModColorEffect,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

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
  OneShot,

  // The macros plugin adds support for macros
  Macros,

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
  USBQuirks
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {


//   QUKEYS(
//     kaleidoscope::plugin::Qukey(0, 2, 2,  Key_LeftAlt),
//     kaleidoscope::plugin::Qukey(0, 2, 3,  Key_LeftControl),
//     kaleidoscope::plugin::Qukey(0, 2, 4,  OSM(LeftShift)),
//     kaleidoscope::plugin::Qukey(0, 2, 5,  ShiftToLayer(NUMPAD)),
//     kaleidoscope::plugin::Qukey(0, 2, 10, ShiftToLayer(NUMPAD)),
//     kaleidoscope::plugin::Qukey(0, 2, 11, OSM(LeftShift)),
//     kaleidoscope::plugin::Qukey(0, 2, 12, Key_RightControl),
//     kaleidoscope::plugin::Qukey(0, 2, 13, Key_RightAlt),
//     kaleidoscope::plugin::Qukey(0, 3, 6,  ShiftToLayer(FUNCTION)),
//     kaleidoscope::plugin::Qukey(0, 3, 9,  ShiftToLayer(FUNCTION))
//   )

  QUKEYS(
       //kaleidoscope::plugin::Qukey(0, 2, 1, OSM(LeftShift)),
       //kaleidoscope::plugin::Qukey(0, 2, 14,OSM(LeftShift)),
       //kaleidoscope::plugin::Qukey(0, 1, 7, Key_LeftAlt),
       kaleidoscope::plugin::Qukey(0, 1, 7, ShiftToLayer(NUMPAD)),
       kaleidoscope::plugin::Qukey(0, 1, 8, ShiftToLayer(ALTGR)),
       kaleidoscope::plugin::Qukey(0, 3, 6, ShiftToLayer(FUNCTION)),
       kaleidoscope::plugin::Qukey(0, 3, 9, ShiftToLayer(CUT))
  )

  Qukeys.setTimeout(180);

  //OneShot
  OneShot.time_out = 500;

  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  MouseKeys.setWarpGridSize(MOUSE_WARP_GRID_3X3);

  // Leader
  Leader.dictionary = leader_dictionary;
  Leader.time_out = 5000;

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

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
