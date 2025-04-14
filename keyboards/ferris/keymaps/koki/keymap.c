// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H


#include <stdio.h>

#include "mousekey.h"
#include "action_layer.h"
#include "eeconfig.h"
#include <stdlib.h>

#include "version.h"
#include "keymap_spanish.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
    _QWERTY,
    _SIMBO,
    _NUMER,
    _MOVE,
    _ADJUST,
    _MOVE2
};

enum ferris_keycodes {
  QWERTY = SAFE_RANGE,
  SIMBO,
  NUMER,
  MOVE,
  ADJUST,
  MOVE2
};

enum ferris_tap_dances {
  TD_Q_ESC
};


//aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT)   // Shift when held, Enter when tapped
#define BSCTL  LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped;
#define TABCTL  LCTL_T(KC_TAB) // Ctrl when held, TAB when tapped;
#define CTAB   LCTL(KC_TAB)
#define ATAB   LALT(KC_TAB)
#define RTAB   RALT(KC_TAB)

//aliases for Navigation layer
#define CBSPC LCTL(KC_BSPC)  // delete whole word
#define C_CL   LCTL(KC_LEFT) // move cursor one word back
#define C_CR   LCTL(KC_RGHT) // move cursor one word forward

//internet browser tab shortcuts and window swapping
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)

#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)


#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_BSPC_SIM LT(_SIM, KC_BSPC)
#define KC_SP_NUM LT(_NUM, KC_SPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)


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


tap_dance_action_t tap_dance_actions[] = {
/*
[ADJ]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LAYER_finished, dance_LAYER_reset),  //  Double-tap to activate Adjust layer via oneshot layer
*/
// Tap once for Q, twice for ESC
[TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),

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


    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [_QWERTY] = LAYOUT(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             LT(_MOVE, KC_Q),  KC_W,  KC_E,  KC_R, KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_A,  KC_S,  KC_D,  KC_F, KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            LSFT_T(KC_Z),  KC_X,  KC_C,  KC_V, KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 LT(_NUMER,KC_BSPC),LT(_MOVE,KC_SPC),      RALT_T(KC_SPC) ,   LT(_SIMBO,KC_ENT)
                                          //`--------------------------'  `--------------------------'

      ),

      [_NUMER] = LAYOUT(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_F5,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, KC_SPC,       KC_BSPC,       MO(_ADJUST)
                                          //`--------------------------'  `--------------------------'
      ),

      [_SIMBO] = LAYOUT(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      TD_LBCB,  TD_RBCB, TD_SLPI, TD_QUDQ, TD_SCCO,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      TD_UNMN,  TD_EQPL, TD_BKCO, TD_BKDO,TD_SLQU,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                MO(_ADJUST), KC_SPC,     KC_BSPC, _______
                                          //`--------------------------'  `--------------------------'
      ),
      [_MOVE] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_NO, KC_NO,   C_CL,    C_CR,    KC_NO,                             KC_NO,KC_HOME,  KC_NO , KC_END, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LCTL, KC_NO,KC_NO, KC_NO, KC_NO,                                    KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_NO ,   KC_F5,   KC_NO, KC_NO,   KC_RSFT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                         KC_LALT, KC_SPC,                   KC_BSPC,     KC_RALT
        ),

      [_MOVE2] = LAYOUT(
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO,    KC_NO,     C_CL,    C_CR,    KC_NO,                        KC_HOME,KC_END,  KC_NO , KC_NO, KC_NO,
          //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_NO,    KC_LALT,   KC_LCTL, KC_LSFT, KC_NO,                        KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_NO,
          //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           CTL_LEFT, CTL_RIGHT, KC_NO,   KC_NO,   KC_NO,                        KC_NO ,   KC_F5,   KC_NO, KC_NO,   KC_NO,
          //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                           KC_NO, KC_SPC,                 KC_BSPC,       KC_NO
          ),
      [_ADJUST] = LAYOUT(
        //,-----------------------------------------------------.                ,-----------------------------------------------------.
                KC_ESC,  KC_NO,KC_NO,  KC_NO, KC_NO,                                   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_CAPS,  KC_NO,  KC_NO,  KC_NO, KC_NO,                                  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
              CTL_Z,  CTL_X,  CTL_C ,   CTL_V , KC_B,                                 KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, KC_SPC,             KC_BSPC,  _______
                                          //`--------------------------'  `--------------------------'
      )
    };

     void keyboard_pre_init_user(void) {
       // Set our LED pin as output
       setPinOutput(B0);//amarillo
       setPinOutput(D5);//azul
       // Turn the LED off
       // (Due to technical reasons, high is off and low is on)
       writePinLow(B0);
       writePinLow(D5);
     }


     // Runs whenever there is a layer state change.
     layer_state_t layer_state_set_user(layer_state_t state) {


         uint8_t layer = get_highest_layer(state);
         switch (layer) {
             case 0:  //quwerty
             writePinHigh(B0);
             writePinHigh(D5);
                 break;
             case 1: /*_SIMBOL*/
     			    writePinLow(D5);
                 break;
             case 2: /*_NUMER*/
              writePinLow(B0);
                 break;
              case 3: /*_MOVE*/
              writePinLow(B0);
               writePinLow(D5);
             case 4: /*_NUMER*/
             writePinLow(B0);
              writePinLow(D5);
                 break;
         }

         return update_tri_layer_state(state, _NUMER, _SIMBO, _ADJUST);
     };




// Tap Dance Definitions
//tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
//    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
//};
