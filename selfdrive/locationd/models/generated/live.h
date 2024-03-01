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
void live_H(double *in_vec, double *out_924166259539900593);
void live_err_fun(double *nom_x, double *delta_x, double *out_2624644257926435556);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4025951560506220674);
void live_H_mod_fun(double *state, double *out_5841896394523971320);
void live_f_fun(double *state, double dt, double *out_4088780942343910929);
void live_F_fun(double *state, double dt, double *out_5395698791493054447);
void live_h_4(double *state, double *unused, double *out_1475320639733206747);
void live_H_4(double *state, double *unused, double *out_6765011008485871039);
void live_h_9(double *state, double *unused, double *out_8384748376343217020);
void live_H_9(double *state, double *unused, double *out_6523821361856280394);
void live_h_10(double *state, double *unused, double *out_6382193643629262946);
void live_H_10(double *state, double *unused, double *out_6166121520443452896);
void live_h_12(double *state, double *unused, double *out_4546335320385339077);
void live_H_12(double *state, double *unused, double *out_6143911983438277372);
void live_h_35(double *state, double *unused, double *out_3599039103483015387);
void live_H_35(double *state, double *unused, double *out_3398348951113263663);
void live_h_32(double *state, double *unused, double *out_5930648090888766425);
void live_H_32(double *state, double *unused, double *out_8133530618902171597);
void live_h_13(double *state, double *unused, double *out_6616808016354863787);
void live_H_13(double *state, double *unused, double *out_3244583673599752062);
void live_h_14(double *state, double *unused, double *out_8384748376343217020);
void live_H_14(double *state, double *unused, double *out_6523821361856280394);
void live_h_33(double *state, double *unused, double *out_4385004923179070765);
void live_H_33(double *state, double *unused, double *out_247791946474406059);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}