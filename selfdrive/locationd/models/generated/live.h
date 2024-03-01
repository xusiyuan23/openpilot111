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
void live_H(double *in_vec, double *out_8523600387998743663);
void live_err_fun(double *nom_x, double *delta_x, double *out_397224092559137986);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2649753097327329786);
void live_H_mod_fun(double *state, double *out_3318911277463317602);
void live_f_fun(double *state, double dt, double *out_5229533073546206660);
void live_F_fun(double *state, double dt, double *out_8885458061524429284);
void live_h_4(double *state, double *unused, double *out_5760213005657753023);
void live_H_4(double *state, double *unused, double *out_5017816733173915125);
void live_h_9(double *state, double *unused, double *out_3101841756117904645);
void live_H_9(double *state, double *unused, double *out_6141708405271189021);
void live_h_10(double *state, double *unused, double *out_4743256218283672467);
void live_H_10(double *state, double *unused, double *out_8791731730799357953);
void live_h_12(double *state, double *unused, double *out_2579169362312866661);
void live_H_12(double *state, double *unused, double *out_5638915758221508792);
void live_h_35(double *state, double *unused, double *out_7312630217986212032);
void live_H_35(double *state, double *unused, double *out_8384478790546522501);
void live_h_32(double *state, double *unused, double *out_117205148134792667);
void live_H_32(double *state, double *unused, double *out_232577830109754697);
void live_h_13(double *state, double *unused, double *out_8001914803084542081);
void live_H_13(double *state, double *unused, double *out_3456886129192004094);
void live_h_14(double *state, double *unused, double *out_3101841756117904645);
void live_H_14(double *state, double *unused, double *out_6141708405271189021);
void live_h_33(double *state, double *unused, double *out_505168331143758912);
void live_H_33(double *state, double *unused, double *out_6911708278524171511);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}