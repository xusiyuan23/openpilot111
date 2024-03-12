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
void live_H(double *in_vec, double *out_5678547249781205843);
void live_err_fun(double *nom_x, double *delta_x, double *out_7786038415114058898);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4024320067273853194);
void live_H_mod_fun(double *state, double *out_5397558725730410635);
void live_f_fun(double *state, double dt, double *out_4167526640936982777);
void live_F_fun(double *state, double dt, double *out_5774721427747447809);
void live_h_4(double *state, double *unused, double *out_1878806005493183204);
void live_H_4(double *state, double *unused, double *out_8360835986635707346);
void live_h_9(double *state, double *unused, double *out_7008862357845565666);
void live_H_9(double *state, double *unused, double *out_2798689151809396800);
void live_h_10(double *state, double *unused, double *out_1854368242330831766);
void live_H_10(double *state, double *unused, double *out_7728768220624810382);
void live_h_12(double *state, double *unused, double *out_5466497058915449734);
void live_H_12(double *state, double *unused, double *out_5066451679041882475);
void live_h_35(double *state, double *unused, double *out_4931523598679842869);
void live_H_35(double *state, double *unused, double *out_6719246029701236894);
void live_h_32(double *state, double *unused, double *out_2039644813621010602);
void live_H_32(double *state, double *unused, double *out_6588081244760496425);
void live_h_13(double *state, double *unused, double *out_3593629792265566351);
void live_H_13(double *state, double *unused, double *out_242337613300384717);
void live_h_14(double *state, double *unused, double *out_7008862357845565666);
void live_H_14(double *state, double *unused, double *out_2798689151809396800);
void live_h_33(double *state, double *unused, double *out_4589975723008195621);
void live_H_33(double *state, double *unused, double *out_3568689025062379290);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}