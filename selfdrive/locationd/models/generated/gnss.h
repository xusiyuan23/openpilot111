#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_1997882145746187898);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_7977352512819017738);
void gnss_H_mod_fun(double *state, double *out_8329454369015276923);
void gnss_f_fun(double *state, double dt, double *out_5966521461067562449);
void gnss_F_fun(double *state, double dt, double *out_3265364062710352632);
void gnss_h_6(double *state, double *sat_pos, double *out_8740291259499609875);
void gnss_H_6(double *state, double *sat_pos, double *out_6994153009562781871);
void gnss_h_20(double *state, double *sat_pos, double *out_8702166267876168587);
void gnss_H_20(double *state, double *sat_pos, double *out_2501154242205932671);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_5603600966869776746);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_950292981380994835);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_5603600966869776746);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_950292981380994835);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}