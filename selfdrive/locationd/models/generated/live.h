#pragma once
#include "rednose/helpers/ekf.h"
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
void live_H(double *in_vec, double *out_1487054425600868780);
void live_err_fun(double *nom_x, double *delta_x, double *out_3000503124079903655);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6379225765353453873);
void live_H_mod_fun(double *state, double *out_9104675487277614412);
void live_f_fun(double *state, double dt, double *out_8391031161948420107);
void live_F_fun(double *state, double dt, double *out_228686520774908462);
void live_h_4(double *state, double *unused, double *out_6856075649876796093);
void live_H_4(double *state, double *unused, double *out_1066397613201620329);
void live_h_9(double *state, double *unused, double *out_4609441899899940999);
void live_H_9(double *state, double *unused, double *out_8353616548466067799);
void live_h_10(double *state, double *unused, double *out_6950605159590993155);
void live_H_10(double *state, double *unused, double *out_6057680135580590067);
void live_h_12(double *state, double *unused, double *out_2992992818418352113);
void live_H_12(double *state, double *unused, double *out_5314860763841112667);
void live_h_35(double *state, double *unused, double *out_5804177491605939861);
void live_H_35(double *state, double *unused, double *out_4433059670574227705);
void live_h_32(double *state, double *unused, double *out_6135380207169186712);
void live_H_32(double *state, double *unused, double *out_4564224455514968174);
void live_h_13(double *state, double *unused, double *out_6464386838757310691);
void live_H_13(double *state, double *unused, double *out_5703077875601027123);
void live_h_14(double *state, double *unused, double *out_4609441899899940999);
void live_H_14(double *state, double *unused, double *out_8353616548466067799);
void live_h_33(double *state, double *unused, double *out_4764270069636906892);
void live_H_33(double *state, double *unused, double *out_3817098109861609482);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}