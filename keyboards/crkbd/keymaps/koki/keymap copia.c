/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



/*******************************************************************
 *                 CRKBD
 * *****************************************************************
 */
#include QMK_KEYBOARD_H
#include <stdio.h>

#include "mousekey.h"
#include "action_layer.h"
#include "eeconfig.h"
#include <stdlib.h>

#include "version.h"
#include "keymap_spanish.h"

enum planck_layers {
  _QWERTY,
  _SIMBO,
  _NUMER,
  _MOVE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SIMBO,
  NUMER,
  MOVE,
  ADJUST
};



//aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT)   // Shift when held, Enter when tapped
#define BSCTL  LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped
#define CTAB   LCTL(KC_TAB)
#define ATAB   LALT(KC_TAB)

//aliases for Navigation layer
#define CBSPC LCTL(KC_BSPC)  // delete whole word
#define C_CL   LCTL(KC_LEFT) // move cursor one word back
#define C_CR   LCTL(KC_RGHT) // move cursor one word forward

//internet browser tab shortcuts and window swapping
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)

#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)

//Tap Dance Declarations
enum {
  ADJ = 0,
LBCB,
RBCB,
EQPL,
PLEQ,
UNMN,
SLPI,
GVTL,
QUDQ,
SCCO,
SLQU,
BKCO,
BKDO,
LCAP,
RCAP
};

/*
void dance_LAYER_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
     layer_on(_ADJUST2);
     set_oneshot_layer(_ADJUST2, ONESHOT_START);
  }
}
void dance_LAYER_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
     layer_off(_ADJUST2);
     clear_oneshot_layer_state(ONESHOT_PRESSED);
  }
}
*/


qk_tap_dance_action_t tap_dance_actions[] = {
/*
[ADJ]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LAYER_finished, dance_LAYER_reset),  //  Double-tap to activate Adjust layer via oneshot layer
*/
[LBCB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),  // Left bracket on a single-tap, left brace on a double-tap
[RBCB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),  // Right bracket on a single-tap, right brace on a double-tap
[EQPL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),   // Plus sign on a single-tap, equal sign on a double-tap
[PLEQ] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_EQL),   // Equal sign on a single-tap, plus sign on a double-tap
[UNMN] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS,KC_MINS),  // underscore  sign on a single-tap, Minus on a double-tap
[SLPI] = ACTION_TAP_DANCE_DOUBLE(KC_BACKSLASH, KC_PIPE),
[GVTL] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),   // Grave on a single-tap, tilde on a double-tap
[QUDQ] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
[SCCO] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON),
[SLQU] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUESTION),
[BKCO] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA,KC_LABK),
[BKDO] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,  KC_RABK),
[LCAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
[RCAP] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS)
};

//Aliases for longer keycodes
/*
#define NUMPAD  TG(_NUMPAD)
#define ADJUST  MO(_ADJUST2)
#define SPCFN   LT(_FUNCTION, KC_SPC)
#define BSPCFN  LT(_FUNCTION2, KC_BSPC)
#define ENTNS   LT(_NUMBERS, KC_ENT)
#define DELNS   LT(_NUMBERS2, KC_DEL)
*/
#define CTLESC  CTL_T(KC_ESC)
#define ALTAPP  ALT_T(KC_APP)
#define CTL_A   LCTL(KC_A)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define CTL_X   LCTL(KC_X)
#define CTL_Z   LCTL(KC_Z)
#define CTL_Y   LCTL(KC_Y)
#define CA_TAB  LCA(KC_TAB)
#define HYPER   ALL_T(KC_NO)
/*
#define TD_ADJ  TD(ADJ)
*/
#define TD_LBCB TD(LBCB)
#define TD_RBCB TD(RBCB)
#define TD_EQPL TD(EQPL)
#define TD_PLEQ TD(PLEQ)
#define TD_UNMN TD(UNMN)
#define TD_SLPI TD(SLPI)
#define TD_GVTL TD(GVTL)
#define TD_QUDQ TD(QUDQ)
#define TD_SCCO TD(SCCO)
#define TD_SLQU TD(SLQU)
#define TD_BKCO TD(BKCO)
#define TD_BKDO TD(BKDO)

#define TD_LCAP TD(LCAP)
#define TD_RCAP TD(RCAP)

#define NKROTG  MAGIC_TOGGLE_NKRO

#define NUMER TT(_NUMER)
#define SIMBO TT(_SIMBO)
#define ADJU TT(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
    LT(_MOVE,KC_ESC),  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(_ADJUST,KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,KC_SLSH, TD_RCAP,

                           TD_RCAP, SIMBO,KC_SPC,     KC_SPC, NUMER,KC_RALT
  ),



  [_SIMBO] = LAYOUT_split_3x6_3(
    TD_GVTL,KC_EXLM,KC_AT,KC_HASH,KC_DOLLAR,KC_PERC,      KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_CAPS,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                TD_LBCB,  TD_RBCB, TD_SLPI, TD_QUDQ, TD_SCCO, KC_NO,
    KC_LCTL,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                TD_UNMN,  TD_EQPL, TD_BKCO, TD_BKDO,TD_SLQU , KC_RSFT,
                          _______, _______, _______,      _______, _______, _______
  ),

[_MOVE] = LAYOUT_split_3x6_3(
  _______, _______,   _______,   C_CL,   C_CR,  _______,  _______, KC_HOME, KC_UP,   KC_END,      KC_PGUP,   _______,
  _______, _______, KC_LCTL, KC_LALT, KC_LSFT, _______, _______ , KC_LEFT, KC_DOWN, KC_RGHT,  KC_UP, _______,
  KC_LSFT, _______, _______, _______, _______, _______, _______ , KC_F5,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,
                               KC_NO, KC_NO,        KC_NO,       KC_NO, KC_NO, KC_NO
  ),


  [_NUMER] = LAYOUT(
    KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,      KC_7,        KC_8,      KC_9,    	KC_0,      KC_BSPC,
    KC_CAPS,  	KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_LBRC,   KC_RBRC, 	KC_BSLASH, KC_QUOTE,	KC_SCOLON, KC_ENTER,
    KC_LCTL, 	KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_MINUS,  KC_EQUAL, 	KC_COMMA,  KC_DOT, 	KC_SLSH,     KC_RSFT,
                                          _______, _______, _______,      _______, _______, _______

  ),


  [_ADJUST] = LAYOUT_split_3x6_3(
    KC_NO, RESET,   RGB_TOG,  BL_TOGG, BL_STEP, BL_ON, BL_OFF, BL_INC, BL_DEC, KC_NO, KC_NO, KC_NO ,
    KC_NO, RGB_MODE_PLAIN, RGB_HUI, RGB_SAI, RGB_VAI,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      _______, _______, _______,      _______, _______, _______
  )
};










#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

//void render_crkbd_logo(void) {
//    static const char PROGMEM crkbd_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//        0};
//    oled_write_P(crkbd_logo, false);
//}



#define L_QWERTY 0
#define L_SIMBO 2
#define L_NUMER 4
#define L_MOVE 8
#define L_ADJUST 16



#    define KEYLOG_LEN 5
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("\n"), false);
    oled_write(keylog_str, false);
}


/*void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case 0:
            oled_write_ln_P(PSTR("QWERT"), true);
            break;
        case 1:
            oled_write_ln_P(PSTR("SIMBO"), true);
            break;
        case 2:
            oled_write_ln_P(PSTR("NUMER"), true);
            break;
        case 3:
            oled_write_ln_P(PSTR("NUM"), true);
            break;
        case 2|1:
            oled_write_ln_P(PSTR("ADJUST"), true);
            break;
    }
}
*/

//void render_default_layer_state(void) {
    //oled_write_P(PSTR("   "), false);//Lyout
    //switch (get_highest_layer(defaults_layer_state)) {
  //      case _QWERTY:
 //           oled_write_P(PSTR("QWRTY"), true);
   //         break;
    //    case _MOVE:
   //         oled_write_P(PSTR("_MOVE"), true);
    //        break;
    //    case _SIMBOL:
   //         oled_write_P(PSTR("SIMBO"), true);
    //        break;
    //     case _NUM:
    //        oled_write_P(PSTR("_NUM_"), true);
    //        break;
    //    case _NAVIGATION:
     //       oled_write_P(PSTR("NAVIG"), true);
   //         break;
    //    case _ADJUST:
     //       oled_write_P(PSTR("ADJUS"), true);
     //       break;
   // }
//}

void render_layer_state(void) {
   //oled_write_P(PSTR("LAYER"), false);
    //oled_write_P(PSTR("SIMBO"), layer_state_is(_MOVE));
    //oled_write_P(PSTR("NUMER"), layer_state_is(_SIMBOL));
            oled_write_P(PSTR("QWRTY"), layer_state_is(_QWERTY));

            oled_write_P(PSTR("SIMBO"), layer_state_is(_SIMBO));

            oled_write_P(PSTR("NUMER"), layer_state_is(_NUMER));

            oled_write_P(PSTR("\n"), false);

            oled_write_P(PSTR("MOVE\n"), layer_state_is(_MOVE));
           oled_write_P(PSTR("ADJUS\n"), layer_state_is(_ADJUST));
            //oled_write_P(PSTR("NUM\n"), layer_state_is(_NUM));

            //oled_write_P(PSTR("ADJUS"), layer_state_is(_ADJUST));

}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("     "), false);//Lock
    //oled_write_P(PSTR(" "), false);
    //oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("CAPS\n"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    //oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));

    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

}

void render_mod_status(uint8_t modifiers) {
  //  oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("CTRL_"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("_ALT_"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("_GUI_"), (modifiers & MOD_MASK_GUI));
}

//void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
//    static const char PROGMEM logo[][2][3] = {
//        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//    };
//    oled_write_P(PSTR("BTMGK"), false);
//    oled_write_P(PSTR(" "), false);
//    oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
//    oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
//    oled_write_P(PSTR(" "), false);
//    oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
//    oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);
//    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
//}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    //render_default_layer_state();


            render_layer_state();
            render_keylock_status(host_keyboard_leds());
            render_mod_status(get_mods());
            //render_bootmagic_status();

            //render_keylogger_status();


}

bool oled_task_user(void) {
    //update_log();
    if (is_keyboard_master()) {

        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {

        //render_crkbd_logo();
    }
    return false;
}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    if (record->event.pressed) {
//        add_keylog(keycode);
//    }
//    return true;
//}


///////////////////////////////////////////////////////////////
//para que el shift + backspace saque el delete
///////////////////////////////////////////////////////////////
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    add_keylog(keycode);/////para el oled//////////////
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        break;//return true;
    }
    case TD_RCAP:
    if (record->event.pressed) {
      rgblight_sethsv(HSV_GREEN);

    }
    else {
       if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
             rgblight_sethsv(HSV_GREEN);//VERDE
       }
       else {
                  layer_move(_QWERTY);
                  rgblight_sethsv(HSV_BLACK);

      }
    }



    break;

    case KC_CAPS:

      if (record->event.pressed) {
      rgblight_sethsv(HSV_GREEN);
          //PLAY_SONG(STARTUP_SOUND);
    }
     break;
    }
    return true;
};



#endif ///del oled


// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
   rgblight_sethsv(HSV_BLACK);
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {


    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:  //quwerty
         if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
               rgblight_sethsv(HSV_GREEN);//VERDE
            } else {
        	       rgblight_sethsv(HSV_BLACK);
        	}
            break;
        case 1: /*_SIMBOL*/
			rgblight_sethsv(HSV_BLUE); //AZUL
            break;
        case 2: /*_NUMER*/
             rgblight_sethsv(HSV_RED); //ROJO
            break;
        case 3:/*_MOVE*/
            rgblight_sethsv(HSV_WHITE);//BLANCO
            break;
        case 4:/*_ADJUST*/
            rgblight_sethsv(HSV_MAGENTA);//MAGENTA
            break;
        default:
		     rgblight_sethsv(HSV_BLACK);
            break;
    }

    return update_tri_layer_state(state, _NUMER, _SIMBO, _ADJUST);
};


/****************

 HSV_AZURE       132, 102, 255
# HSV_BLACK         0,   0,   0
# HSV_BLUE        170, 255, 255
# HSV_CHARTREUSE   64, 255, 255
# HSV_CORAL        11, 176, 255
# HSV_CYAN        128, 255, 255
# HSV_GOLD         36, 255, 255
# HSV_GOLDENROD    30, 218, 218
# HSV_GREEN        85, 255, 255
# HSV_MAGENTA     213, 255, 255
# HSV_ORANGE       28, 255, 255
# HSV_PINK        234, 128, 255
# HSV_PURPLE      191, 255, 255
# HSV_RED           0, 255, 255
# HSV_SPRINGGREEN 106, 255, 255
# HSV_TEAL        128, 255, 128
# HSV_TURQUOISE   123,  90, 112
# HSV_WHITE         0,   0, 255
# HSV_YELLOW       43, 255, 255
# HSV_OFF         HSV_BLACK

**********************/
