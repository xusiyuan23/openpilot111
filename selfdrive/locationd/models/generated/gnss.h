#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_920563397091966765);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_9207898715518151756);
void gnss_H_mod_fun(double *state, double *out_8858641397583587342);
void gnss_f_fun(double *state, double dt, double *out_8883459878223034240);
void gnss_F_fun(double *state, double dt, double *out_5523223948218415506);
void gnss_h_6(double *state, double *sat_pos, double *out_580488090984610716);
void gnss_H_6(double *state, double *sat_pos, double *out_930024451989407159);
void gnss_h_20(double *state, double *sat_pos, double *out_5239371180373600875);
void gnss_H_20(double *state, double *sat_pos, double *out_4343366647947653302);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1146845787665601201);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_913804198191897829);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1146845787665601201);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_913804198191897829);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}