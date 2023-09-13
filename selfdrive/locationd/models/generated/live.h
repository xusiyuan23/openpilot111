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
void live_H(double *in_vec, double *out_8494622585832445872);
void live_err_fun(double *nom_x, double *delta_x, double *out_2249411990467774485);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2859626302290428272);
void live_H_mod_fun(double *state, double *out_1508708626145229465);
void live_f_fun(double *state, double dt, double *out_3025328284235069091);
void live_F_fun(double *state, double dt, double *out_2866880934425822829);
void live_h_4(double *state, double *unused, double *out_195412779303848081);
void live_H_4(double *state, double *unused, double *out_8454023741651631723);
void live_h_9(double *state, double *unused, double *out_1505666915611342749);
void live_H_9(double *state, double *unused, double *out_8695213388281222368);
void live_h_10(double *state, double *unused, double *out_4353819279872822444);
void live_H_10(double *state, double *unused, double *out_8953681816626175346);
void live_h_12(double *state, double *unused, double *out_5544595070917867689);
void live_H_12(double *state, double *unused, double *out_4973263924025958098);
void live_h_35(double *state, double *unused, double *out_3473632359961004563);
void live_H_35(double *state, double *unused, double *out_6626058274685312517);
void live_h_32(double *state, double *unused, double *out_7617791596832061829);
void live_H_32(double *state, double *unused, double *out_555957272717473204);
void live_h_13(double *state, double *unused, double *out_8348130591745782147);
void live_H_13(double *state, double *unused, double *out_1808664940182043499);
void live_h_14(double *state, double *unused, double *out_1505666915611342749);
void live_H_14(double *state, double *unused, double *out_8695213388281222368);
void live_h_33(double *state, double *unused, double *out_3527010921757156150);
void live_H_33(double *state, double *unused, double *out_3475501270046454913);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}