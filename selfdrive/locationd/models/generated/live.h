#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_5027207160750161004);
void live_err_fun(double *nom_x, double *delta_x, double *out_812293829444590878);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2331899367078236024);
void live_H_mod_fun(double *state, double *out_3350621260021879835);
void live_f_fun(double *state, double dt, double *out_9110479569516509106);
void live_F_fun(double *state, double dt, double *out_956757865849250644);
void live_h_4(double *state, double *unused, double *out_396243034408503816);
void live_H_4(double *state, double *unused, double *out_7955964066782090966);
void live_h_9(double *state, double *unused, double *out_3280179861815054133);
void live_H_9(double *state, double *unused, double *out_8197153713411681611);
void live_h_10(double *state, double *unused, double *out_7028739412274946671);
void live_H_10(double *state, double *unused, double *out_5406505055183973833);
void live_h_12(double *state, double *unused, double *out_2939119697401536762);
void live_H_12(double *state, double *unused, double *out_8577063091829684633);
void live_h_35(double *state, double *unused, double *out_3733220149839256661);
void live_H_35(double *state, double *unused, double *out_7124117949554853274);
void live_h_32(double *state, double *unused, double *out_6268450557573639622);
void live_H_32(double *state, double *unused, double *out_4419093436653103337);
void live_h_13(double *state, double *unused, double *out_7986377932969783217);
void live_H_13(double *state, double *unused, double *out_276341309716065550);
void live_h_14(double *state, double *unused, double *out_3280179861815054133);
void live_H_14(double *state, double *unused, double *out_8197153713411681611);
void live_h_33(double *state, double *unused, double *out_3797754961266519421);
void live_H_33(double *state, double *unused, double *out_3973560944915995670);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}