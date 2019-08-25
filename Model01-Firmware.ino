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
       MACRO_ALT_ENTER,
       MACRO_ALT_F4,
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
       MACRO_CTRL_A,
       MACRO_CTRL_ALT_GR_3,
       MACRO_CTRL_ALT_GR_4,
       MACRO_CTRL_C,
       MACRO_CTRL_END,
       MACRO_CTRL_F,
       MACRO_CTRL_F4,
       MACRO_CTRL_G,
       MACRO_CTRL_HOME,
       MACRO_CTRL_LEFT,
       MACRO_CTRL_L,
       MACRO_CTRL_N,
       MACRO_CTRL_O,
       MACRO_CTRL_PAGE_DOWN,
       MACRO_CTRL_PAGE_UP,
       MACRO_CTRL_R,
       MACRO_CTRL_RIGHT,
       MACRO_CTRL_S,
       MACRO_CTRL_SHIFT_ENTER,
       MACRO_CTRL_SHIFT_Z,
       MACRO_CTRL_T,
       MACRO_CTRL_TAB,
       MACRO_CTRL_SHIFT_TAB,
       MACRO_CTRL_V,
       MACRO_CTRL_W,
       MACRO_CTRL_X,
       MACRO_CTRL_Y,
       MACRO_CTRL_Z,
       MACRO_EXCLAMATION_POINT,
       MACRO_LEFT_CURLY_BRACKET,
       MACRO_MOUSE_NW_NW_NW,
       MACRO_MOUSE_SW_SW_SW,
       MACRO_MOUSE_NE_NE_NE,
       MACRO_MOUSE_SE_SE_SE,
       MACRO_SEMICOLON,
       MACRO_SHIFT_TAB,
       MACRO_SPACE_EQUALS_SPACE,
       MACRO_SUPER_DOWN,
       MACRO_SUPER_LEFT,
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

enum { PRIMARY, NUMPAD, FUNCTION }; // layers


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
  (___,                        Key_1,     M(MACRO_ALT_GR_2), M(MACRO_ALT_GR_3), Key_4, Key_5, M(MACRO_LEFT_CURLY_BRACKET),
   Key_Backtick,               Key_Q,     Key_W,             Key_E,             Key_R, Key_T, M(MACRO_SEMICOLON),
   Key_RightBracket,           Key_A,     Key_S,             Key_D,             Key_F, Key_G,
   Key_Minus,                  Key_Z,     Key_X,             Key_C,             Key_V, Key_B, M(MACRO_ALT_TAB),
   OSM(LeftShift), Key_Backspace, OSM(LeftControl), OSM(LeftAlt),
   M(MACRO_ALT_SPACE),

   ___,                        Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Equals,
   Key_Tab,                    Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_LeftBracket,
                               Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_Escape,                 Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Backslash,
   Key_LeftGui, Key_Enter, Key_Spacebar, OSM(RightShift),
   ShiftToLayer(NUMPAD)),

#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif



  [NUMPAD] =  KEYMAP_STACKED
  (___,                        M(MACRO_ALT_GR_1),      Key_2,                  Key_3,             M(MACRO_ALT_GR_4),   M(MACRO_ALT_GR_5), ___,
   M(MACRO_ALT_GR_DOLLAR),     M(MACRO_ALT_GR_B),      M(MACRO_ALT_GR_E_AIGU), M(MACRO_ALT_GR_P), M(MACRO_ALT_GR_O),   M(MACRO_ALT_GR_E_GRAVE), ___,
   M(MACRO_EXCLAMATION_POINT), M(MACRO_ALT_GR_A),      M(MACRO_ALT_GR_U),      M(MACRO_ALT_GR_I), M(MACRO_ALT_GR_E),   M(MACRO_ALT_GR_COMMA),
   M(MACRO_ALT_GR_EQUALS),     M(MACRO_ALT_GR_A_AIGU), M(MACRO_ALT_GR_Y),      M(MACRO_ALT_GR_X), M(MACRO_ALT_GR_DOT), M(MACRO_ALT_GR_K), ___,
   ___, ___, ___, ___,
   ___,

   ___,                    ___,             Key_KeypadAdd,        Key_KeypadSubtract,  Key_KeypadDivide,  Key_KeypadMultiply,   ___,
   M(MACRO_SHIFT_TAB),     M(MACRO_6),      M(MACRO_7),           M(MACRO_8),          M(MACRO_9),        M(MACRO_0),           Key_KeypadEnter,
                           Key_KeypadDot,   M(MACRO_1),           M(MACRO_2),          M(MACRO_3),        M(MACRO_4),           M(MACRO_5),
   ___,                    M(MACRO_ALT_F4), M(MACRO_SUPER_LEFT),  M(MACRO_SUPER_DOWN), M(MACRO_SUPER_UP), M(MACRO_SUPER_RIGHT), Key_Tab,
   OSM(RightAlt), M(MACRO_CTRL_SHIFT_ENTER), M(MACRO_ALT_GR_SPACE),  Key_RightShift,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (Key_PrintScreen,           Key_F1,                  Key_F2,               Key_F3,                 Key_F4,                Key_F5,              M(MACRO_CTRL_L),
   M(MACRO_CTRL_O),           M(MACRO_CTRL_N),         M(MACRO_CTRL_S),      M(MACRO_CTRL_T),        M(MACRO_CTRL_F4),      M(MACRO_ALT_F4),     M(MACRO_CTRL_F),
   Key_Insert,                M(MACRO_CTRL_Z),         M(MACRO_CTRL_X),      M(MACRO_CTRL_C),        M(MACRO_CTRL_V),       Key_Delete,
   Key_Escape,                Key_LeftArrow,           Key_DownArrow,        Key_UpArrow,            Key_RightArrow,        Key_Enter,           ___,
   Key_LeftShift, Key_Spacebar, Key_LeftControl, Key_LeftAlt,
   ___,

   ___,                       Key_F6,                  Key_F7,               Key_F8,                 Key_F9,                Key_F10,             Key_F11,
   ___,                       M(MACRO_CTRL_HOME),      M(MACRO_CTRL_LEFT),   Key_PageDown,           Key_PageUp,            M(MACRO_CTRL_RIGHT), M(MACRO_CTRL_END),
                              Key_Home,                Key_LeftArrow,        Key_DownArrow,          Key_UpArrow,           Key_RightArrow,      Key_End,
   ___,                       Key_PcApplication,       M(MACRO_ALT_LEFT),    M(MACRO_ALT_DOWN),      M(MACRO_ALT_UP),       M(MACRO_ALT_RIGHT),  Key_F12,
   ___, ___, M(MACRO_SPACE_EQUALS_SPACE), M(MACRO_ALT_ENTER),
   ___)
) // KEYMAPS(



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
  static Key lastKey;
  bool toggledOn = false;
  if (keyToggledOn(keyState)) {
    lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
    toggledOn = true;
  }

  if (keyIsPressed(keyState))
    Kaleidoscope.hid().keyboard().pressKey(lastKey, toggledOn);
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

  case MACRO_ALT_ENTER:
    return MACRODOWN(D(LeftAlt), T(Enter), U(LeftAlt));
    break;

  case MACRO_ALT_F4:
    return MACRODOWN(D(LeftAlt), T(F4), U(LeftAlt));
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
    return MACRODOWN(D(LeftAlt), T(LeftShift), T(Tab), U(LeftAlt));
    break;

  case MACRO_CTRL_A:
    return MACRODOWN(D(LeftControl), T(A), U(LeftControl));
    break;

  case MACRO_CTRL_ALT_GR_3:
    return MACRODOWN(D(LeftControl), D(RightAlt), T(3), U(RightAlt), U(LeftControl));
    break;

  case MACRO_CTRL_ALT_GR_4:
    return MACRODOWN(D(LeftControl), D(RightAlt), T(4), U(RightAlt), U(LeftControl));
    break;

  case MACRO_CTRL_C:
    return MACRODOWN(D(LeftControl), T(H), U(LeftControl));
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

  case MACRO_CTRL_L:
    return MACRODOWN(D(LeftControl), T(O), U(LeftControl));
    break;

  case MACRO_CTRL_N:
    return MACRODOWN(D(LeftControl), T(Semicolon), U(LeftControl));
    break;

  case MACRO_CTRL_O:
    return MACRODOWN(D(LeftControl), T(R), U(LeftControl));
    break;

  case MACRO_CTRL_PAGE_DOWN:
    return MACRODOWN(D(LeftControl), T(PageDown), U(LeftControl));
    break;

  case MACRO_CTRL_PAGE_UP:
    return MACRODOWN(D(LeftControl), T(PageUp), U(LeftControl));
    break;

  case MACRO_CTRL_R:
    return MACRODOWN(D(LeftControl), T(L), U(LeftControl));
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

  case MACRO_CTRL_S:
    return MACRODOWN(D(LeftControl), T(K), U(LeftControl));
    break;

  case MACRO_CTRL_SHIFT_ENTER:
    return MACRODOWN(D(LeftControl), D(LeftShift), T(Enter), U(LeftShift), U(LeftControl));
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

  case MACRO_SHIFT_TAB:
    return MACRODOWN(D(LeftShift), T(Tab), U(LeftShift));
    break;

  case MACRO_SPACE_EQUALS_SPACE:
    return MACRODOWN(T(Spacebar), T(Minus), T(Spacebar));
    break;

  case MACRO_SUPER_DOWN:
    return MACRODOWN(D(LeftGui), T(DownArrow), U(LeftGui));
    break;

  case MACRO_SUPER_LEFT:
    return MACRODOWN(D(LeftGui), T(LeftArrow), U(LeftGui));
    break;

  case MACRO_SUPER_RIGHT:
    return MACRODOWN(D(LeftGui), T(RightArrow), U(LeftGui));
    break;

  case MACRO_SUPER_TAB:
    return MACRODOWN(D(LeftGui), T(Tab), U(LeftGui));
    break;

  case MACRO_SUPER_UP:
    return MACRODOWN(D(LeftGui), T(UpArrow), U(LeftGui));
    break;

  case MACRO_VI:
    // TODO
    break;

  }
  return MACRO_NONE;
}

/*

static void leaderSA(uint8_t seq_index) {
    Macros.type(PSTR(" A"));
}
static void leaderSB(uint8_t seq_index) {
    Macros.type(PSTR(" B"));
}
static void leaderSC(uint8_t seq_index) {
    Macros.type(PSTR(" C"));
}
static void leaderSD(uint8_t seq_index) {
    Macros.type(PSTR(" D"));
}
static void leaderSE(uint8_t seq_index) {
    Macros.type(PSTR(" E"));
}
static void leaderSF(uint8_t seq_index) {
    Macros.type(PSTR(" F"));
}
static void leaderSG(uint8_t seq_index) {
    Macros.type(PSTR(" G"));
}
static void leaderSH(uint8_t seq_index) {
    Macros.type(PSTR(" H"));
}
static void leaderSI(uint8_t seq_index) {
    Macros.type(PSTR(" I"));
}
static void leaderSJ(uint8_t seq_index) {
    Macros.type(PSTR(" J"));
}
static void leaderSK(uint8_t seq_index) {
    Macros.type(PSTR(" K"));
}
static void leaderSL(uint8_t seq_index) {
    Macros.type(PSTR(" L"));
}
static void leaderSM(uint8_t seq_index) {
    Macros.type(PSTR(" M"));
}
static void leaderSN(uint8_t seq_index) {
    Macros.type(PSTR(" N"));
}
static void leaderSO(uint8_t seq_index) {
    Macros.type(PSTR(" O"));
}
static void leaderSP(uint8_t seq_index) {
    Macros.type(PSTR(" P"));
}
static void leaderSQ(uint8_t seq_index) {
    Macros.type(PSTR(" Q"));
}
static void leaderSR(uint8_t seq_index) {
    Macros.type(PSTR(" R"));
}
static void leaderSS(uint8_t seq_index) {
    Macros.type(PSTR(" S"));
}
static void leaderST(uint8_t seq_index) {
    Macros.type(PSTR(" T"));
}
static void leaderSU(uint8_t seq_index) {
    Macros.type(PSTR(" U"));
}
static void leaderSV(uint8_t seq_index) {
    Macros.type(PSTR(" V"));
}
static void leaderSW(uint8_t seq_index) {
    Macros.type(PSTR(" W"));
}
static void leaderSX(uint8_t seq_index) {
    Macros.type(PSTR(" X"));
}
static void leaderSY(uint8_t seq_index) {
    Macros.type(PSTR(" Y"));
}
static void leaderSZ(uint8_t seq_index) {
    Macros.type(PSTR(" Z"));
}
static void leaderS(uint8_t seq_index) {
    Macros.type(PSTR(" "));
}



static void leaderPSA(uint8_t seq_index) {
    Macros.type(PSTR(". A"));
}
static void leaderPSB(uint8_t seq_index) {
    Macros.type(PSTR(". B"));
}
static void leaderPSC(uint8_t seq_index) {
    Macros.type(PSTR(". C"));
}
static void leaderPSD(uint8_t seq_index) {
    Macros.type(PSTR(". D"));
}
static void leaderPSE(uint8_t seq_index) {
    Macros.type(PSTR(". E"));
}
static void leaderPSF(uint8_t seq_index) {
    Macros.type(PSTR(". F"));
}
static void leaderPSG(uint8_t seq_index) {
    Macros.type(PSTR(". G"));
}
static void leaderPSH(uint8_t seq_index) {
    Macros.type(PSTR(". H"));
}
static void leaderPSI(uint8_t seq_index) {
    Macros.type(PSTR(". I"));
}
static void leaderPSJ(uint8_t seq_index) {
    Macros.type(PSTR(". J"));
}
static void leaderPSK(uint8_t seq_index) {
    Macros.type(PSTR(". K"));
}
static void leaderPSL(uint8_t seq_index) {
    Macros.type(PSTR(". L"));
}
static void leaderPSM(uint8_t seq_index) {
    Macros.type(PSTR(". M"));
}
static void leaderPSN(uint8_t seq_index) {
    Macros.type(PSTR(". N"));
}
static void leaderPSO(uint8_t seq_index) {
    Macros.type(PSTR(". O"));
}
static void leaderPSP(uint8_t seq_index) {
    Macros.type(PSTR(". P"));
}
static void leaderPSQ(uint8_t seq_index) {
    Macros.type(PSTR(". Q"));
}
static void leaderPSR(uint8_t seq_index) {
    Macros.type(PSTR(". R"));
}
static void leaderPSS(uint8_t seq_index) {
    Macros.type(PSTR(". S"));
}
static void leaderPST(uint8_t seq_index) {
    Macros.type(PSTR(". T"));
}
static void leaderPSU(uint8_t seq_index) {
    Macros.type(PSTR(". U"));
}
static void leaderPSV(uint8_t seq_index) {
    Macros.type(PSTR(". V"));
}
static void leaderPSW(uint8_t seq_index) {
    Macros.type(PSTR(". W"));
}
static void leaderPSX(uint8_t seq_index) {
    Macros.type(PSTR(". X"));
}
static void leaderPSY(uint8_t seq_index) {
    Macros.type(PSTR(". Y"));
}
static void leaderPSZ(uint8_t seq_index) {
    Macros.type(PSTR(". Z"));
}
static void leaderP(uint8_t seq_index) {
    Macros.type(PSTR("."));
}



static void leaderEA(uint8_t seq_index) {
    Macros.type(PSTR("\nA"));
}
static void leaderEB(uint8_t seq_index) {
    Macros.type(PSTR("\nB"));
}
static void leaderEC(uint8_t seq_index) {
    Macros.type(PSTR("\nC"));
}
static void leaderED(uint8_t seq_index) {
    Macros.type(PSTR("\nD"));
}
static void leaderEE(uint8_t seq_index) {
    Macros.type(PSTR("\nE"));
}
static void leaderEF(uint8_t seq_index) {
    Macros.type(PSTR("\nF"));
}
static void leaderEG(uint8_t seq_index) {
    Macros.type(PSTR("\nG"));
}
static void leaderEH(uint8_t seq_index) {
    Macros.type(PSTR("\nH"));
}
static void leaderEI(uint8_t seq_index) {
    Macros.type(PSTR("\nI"));
}
static void leaderEJ(uint8_t seq_index) {
    Macros.type(PSTR("\nJ"));
}
static void leaderEK(uint8_t seq_index) {
    Macros.type(PSTR("\nK"));
}
static void leaderEL(uint8_t seq_index) {
    Macros.type(PSTR("\nL"));
}
static void leaderEM(uint8_t seq_index) {
    Macros.type(PSTR("\nM"));
}
static void leaderEN(uint8_t seq_index) {
    Macros.type(PSTR("\nN"));
}
static void leaderEO(uint8_t seq_index) {
    Macros.type(PSTR("\nO"));
}
static void leaderEP(uint8_t seq_index) {
    Macros.type(PSTR("\nP"));
}
static void leaderEQ(uint8_t seq_index) {
    Macros.type(PSTR("\nQ"));
}
static void leaderER(uint8_t seq_index) {
    Macros.type(PSTR("\nR"));
}
static void leaderES(uint8_t seq_index) {
    Macros.type(PSTR("\nS"));
}
static void leaderET(uint8_t seq_index) {
    Macros.type(PSTR("\nT"));
}
static void leaderEU(uint8_t seq_index) {
    Macros.type(PSTR("\nU"));
}
static void leaderEV(uint8_t seq_index) {
    Macros.type(PSTR("\nV"));
}
static void leaderEW(uint8_t seq_index) {
    Macros.type(PSTR("\nW"));
}
static void leaderEX(uint8_t seq_index) {
    Macros.type(PSTR("\nX"));
}
static void leaderEY(uint8_t seq_index) {
    Macros.type(PSTR("\nY"));
}
static void leaderEZ(uint8_t seq_index) {
    Macros.type(PSTR("\nZ"));
}
static void leaderE(uint8_t seq_index) {
    Macros.type(PSTR("\n"));
}

static void leader(uint8_t seq_index) {
    Macros.type(PSTR(""));
}

static const kaleidoscope::plugin::Leader::dictionary_t leader_dictionary[] PROGMEM =
LEADER_DICT(
{LEADER_SEQ(LEAD(0), Key_A), leaderSA},
{LEADER_SEQ(LEAD(0), Key_B), leaderSB},
{LEADER_SEQ(LEAD(0), Key_C), leaderSC},
{LEADER_SEQ(LEAD(0), Key_D), leaderSD},
{LEADER_SEQ(LEAD(0), Key_E), leaderSE},
{LEADER_SEQ(LEAD(0), Key_F), leaderSF},
{LEADER_SEQ(LEAD(0), Key_G), leaderSG},
{LEADER_SEQ(LEAD(0), Key_H), leaderSH},
{LEADER_SEQ(LEAD(0), Key_I), leaderSI},
{LEADER_SEQ(LEAD(0), Key_J), leaderSJ},
{LEADER_SEQ(LEAD(0), Key_K), leaderSK},
{LEADER_SEQ(LEAD(0), Key_L), leaderSL},
{LEADER_SEQ(LEAD(0), Key_M), leaderSM},
{LEADER_SEQ(LEAD(0), Key_N), leaderSN},
{LEADER_SEQ(LEAD(0), Key_O), leaderSO},
{LEADER_SEQ(LEAD(0), Key_P), leaderSP},
{LEADER_SEQ(LEAD(0), Key_Q), leaderSQ},
{LEADER_SEQ(LEAD(0), Key_R), leaderSR},
{LEADER_SEQ(LEAD(0), Key_S), leaderSS},
{LEADER_SEQ(LEAD(0), Key_T), leaderST},
{LEADER_SEQ(LEAD(0), Key_U), leaderSU},
{LEADER_SEQ(LEAD(0), Key_V), leaderSV},
{LEADER_SEQ(LEAD(0), Key_W), leaderSW},
{LEADER_SEQ(LEAD(0), Key_X), leaderSX},
{LEADER_SEQ(LEAD(0), Key_Y), leaderSY},
{LEADER_SEQ(LEAD(0), Key_Z), leaderSZ},
{LEADER_SEQ(LEAD(0), Key_Spacebar), leaderS},
{LEADER_SEQ(LEAD(0), Key_Escape), leader},
{LEADER_SEQ(LEAD(1), Key_A), leaderPSA},
{LEADER_SEQ(LEAD(1), Key_B), leaderPSB},
{LEADER_SEQ(LEAD(1), Key_C), leaderPSC},
{LEADER_SEQ(LEAD(1), Key_D), leaderPSD},
{LEADER_SEQ(LEAD(1), Key_E), leaderPSE},
{LEADER_SEQ(LEAD(1), Key_F), leaderPSF},
{LEADER_SEQ(LEAD(1), Key_G), leaderPSG},
{LEADER_SEQ(LEAD(1), Key_H), leaderPSH},
{LEADER_SEQ(LEAD(1), Key_I), leaderPSI},
{LEADER_SEQ(LEAD(1), Key_J), leaderPSJ},
{LEADER_SEQ(LEAD(1), Key_K), leaderPSK},
{LEADER_SEQ(LEAD(1), Key_L), leaderPSL},
{LEADER_SEQ(LEAD(1), Key_M), leaderPSM},
{LEADER_SEQ(LEAD(1), Key_N), leaderPSN},
{LEADER_SEQ(LEAD(1), Key_O), leaderPSO},
{LEADER_SEQ(LEAD(1), Key_P), leaderPSP},
{LEADER_SEQ(LEAD(1), Key_Q), leaderPSQ},
{LEADER_SEQ(LEAD(1), Key_R), leaderPSR},
{LEADER_SEQ(LEAD(1), Key_S), leaderPSS},
{LEADER_SEQ(LEAD(1), Key_T), leaderPST},
{LEADER_SEQ(LEAD(1), Key_U), leaderPSU},
{LEADER_SEQ(LEAD(1), Key_V), leaderPSV},
{LEADER_SEQ(LEAD(1), Key_W), leaderPSW},
{LEADER_SEQ(LEAD(1), Key_X), leaderPSX},
{LEADER_SEQ(LEAD(1), Key_Y), leaderPSY},
{LEADER_SEQ(LEAD(1), Key_Z), leaderPSZ},
{LEADER_SEQ(LEAD(1), Key_Spacebar), leaderP},
{LEADER_SEQ(LEAD(1), Key_Escape), leader},



{LEADER_SEQ(LEAD(2), Key_A), leaderEA},
{LEADER_SEQ(LEAD(2), Key_B), leaderEB},
{LEADER_SEQ(LEAD(2), Key_C), leaderEC},
{LEADER_SEQ(LEAD(2), Key_D), leaderED},
{LEADER_SEQ(LEAD(2), Key_E), leaderEE},
{LEADER_SEQ(LEAD(2), Key_F), leaderEF},
{LEADER_SEQ(LEAD(2), Key_G), leaderEG},
{LEADER_SEQ(LEAD(2), Key_H), leaderEH},
{LEADER_SEQ(LEAD(2), Key_I), leaderEI},
{LEADER_SEQ(LEAD(2), Key_J), leaderEJ},
{LEADER_SEQ(LEAD(2), Key_K), leaderEK},
{LEADER_SEQ(LEAD(2), Key_L), leaderEL},
{LEADER_SEQ(LEAD(2), Key_M), leaderEM},
{LEADER_SEQ(LEAD(2), Key_N), leaderEN},
{LEADER_SEQ(LEAD(2), Key_O), leaderEO},
{LEADER_SEQ(LEAD(2), Key_P), leaderEP},
{LEADER_SEQ(LEAD(2), Key_Q), leaderEQ},
{LEADER_SEQ(LEAD(2), Key_R), leaderER},
{LEADER_SEQ(LEAD(2), Key_S), leaderES},
{LEADER_SEQ(LEAD(2), Key_T), leaderET},
{LEADER_SEQ(LEAD(2), Key_U), leaderEU},
{LEADER_SEQ(LEAD(2), Key_V), leaderEV},
{LEADER_SEQ(LEAD(2), Key_W), leaderEW},
{LEADER_SEQ(LEAD(2), Key_X), leaderEX},
{LEADER_SEQ(LEAD(2), Key_Y), leaderEY},
{LEADER_SEQ(LEAD(2), Key_Z), leaderEZ},
{LEADER_SEQ(LEAD(2), Key_Enter), leaderE},
{LEADER_SEQ(LEAD(2), Key_Escape), leader}

);

*/

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
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
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


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
}, {
  .action = enterHardwareTestMode,
  // Left Fn + Prog + LED
  .keys = { R3C6, R0C0, R0C6 }
});

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // Qukeys
  Qukeys,

  // Leader
  //Leader,

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
  HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

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
  LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  //ColormapEffect,


  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  NumPad,

  //OneShot,
  OneShot,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

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
       kaleidoscope::plugin::Qukey(0, 3, 6, ShiftToLayer(FUNCTION))
  )

  Qukeys.setTimeout(200);

  //OneShot
  OneShot.time_out = 1000;


  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  MouseKeys.setWarpGridSize(MOUSE_WARP_GRID_3X3);

  // Leader
  //Leader.dictionary = leader_dictionary;
  //Leader.time_out = 3000;

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
