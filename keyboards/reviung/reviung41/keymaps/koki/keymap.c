/*******************************************************************
 *                REVIUNG41
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
  _ADJUST,
  _MOVE2
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SIMBO,
  NUMER,
  MOVE,
  ADJUST,
  MOVE2
};



//aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT)   // Shift when held, Enter when tapped
#define BSCTL  LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped;
#define TABCTL  LCTL_T(KC_TAB) // Ctrl when held, TAB when tapped;
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



tap_dance_action_t tap_dance_actions[] = {




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
#define CTL_LEFT    LCTL(KC_LEFT)
#define CTL_RIGHT   LCTL(KC_RIGHT)
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


static bool is_caps_lock_on = false;


    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [_QWERTY] = LAYOUT_reviung41(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          LT(_MOVE,KC_ESC),    KC_Q,  KC_W,  KC_E,  KC_R, KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TABCTL,   KC_A,  KC_S,  KC_D,  KC_F, KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TD_LCAP,  KC_Z,  KC_X,  KC_C,  KC_V, KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, TD_RCAP,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LALT,   MO(_NUMER),     KC_SPC ,   MO(_SIMBO), KC_RALT
                                          //`--------------------------'  `--------------------------'

      ),

      [_NUMER] = LAYOUT_reviung41(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_F5,   KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______,       KC_SPC,       MO(_ADJUST), _______
                                          //`--------------------------'  `--------------------------'
      ),

      [_SIMBO] = LAYOUT_reviung41(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          TD_GVTL, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      TD_LBCB,  TD_RBCB, TD_SLPI, TD_QUDQ, TD_SCCO, KC_NO,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TD_LCAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      TD_UNMN,  TD_EQPL, TD_BKCO, TD_BKDO,TD_SLQU, TD_RCAP,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______,   MO(_ADJUST),     KC_SPC, _______,_______
                                          //`--------------------------'  `--------------------------'
      ),
      [_MOVE] = LAYOUT_reviung41(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, KC_NO, KC_NO,   C_CL,    C_CR,    KC_NO,                             KC_NO,KC_HOME,  KC_NO , KC_END, KC_NO, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_NO, KC_NO,KC_NO, KC_NO, KC_NO,                                    KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_NO,  KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_NO ,   KC_F5,   KC_NO, KC_NO,   KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                        _______, KC_NO,                   KC_SPC,     KC_NO, KC_RALT
        ),

      [_MOVE2] = LAYOUT_reviung41(
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_ESC,  KC_NO,    KC_NO,     C_CL,    C_CR,    KC_NO,                        KC_HOME,KC_END,  KC_NO , KC_NO, KC_NO, KC_BSPC,
          //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, KC_NO,    KC_LALT,   KC_LCTL, KC_LSFT, KC_NO,                        KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_NO,  KC_ENT,
          //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT, CTL_LEFT, CTL_RIGHT, KC_NO,   KC_NO,   KC_NO,                        KC_NO ,   KC_F5,   KC_NO, KC_NO,   KC_NO, KC_NO,
          //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_NO,                 KC_SPC,       KC_NO, KC_LALT
          ),
      [_ADJUST] = LAYOUT_reviung41(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, RGB_MODE_PLAIN,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_RALT, _______,             KC_SPC,  _______, _______
                                          //`--------------------------'  `--------------------------'
      )
    };
















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



  bool caps = host_keyboard_led_state().caps_lock;


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
       if (caps){
             rgblight_sethsv(HSV_GREEN);//VERDE
       }
       else {
                  layer_move(_QWERTY);
                  rgblight_sethsv(HSV_BLACK);

      }
    }



    break;

    case TD_LCAP:
    if (record->event.pressed) {
      rgblight_sethsv(HSV_GREEN);

    }
    else {

       if (caps){
             rgblight_sethsv(HSV_GREEN);//VERDE
       }
       else {
                  layer_move(_QWERTY);
                  rgblight_sethsv(HSV_BLACK);

      }
    }



    break;


    case KC_CAPS:

      if (caps) {
      rgblight_sethsv(HSV_GREEN);
          //PLAY_SONG(STARTUP_SOUND);
    }
     break;
    }
    return true;
};






// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
   rgblight_sethsv(HSV_BLACK);
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {


    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:  //quwerty
         if (is_caps_lock_on){
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
        case 5:/*_MOVE2*/
            rgblight_sethsv(HSV_TEAL);//YELLOW
            break;
        default:
		     rgblight_sethsv(HSV_BLACK);
            break;
    }

    return update_tri_layer_state(state, _NUMER, _SIMBO, _ADJUST);
};


/****************

# HSV_AZURE       132, 102, 255
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
