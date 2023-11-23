#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_5365537455458469032);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_3513839179035210816);
void gnss_H_mod_fun(double *state, double *out_2405840849544132315);
void gnss_f_fun(double *state, double dt, double *out_5902818684448534426);
void gnss_F_fun(double *state, double dt, double *out_1914444734837403549);
void gnss_h_6(double *state, double *sat_pos, double *out_2903029344596054497);
void gnss_H_6(double *state, double *sat_pos, double *out_3798983711418579832);
void gnss_h_20(double *state, double *sat_pos, double *out_5130050872567602623);
void gnss_H_20(double *state, double *sat_pos, double *out_8832869769537760488);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2068205041655051004);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_121303140786155029);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2068205041655051004);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_121303140786155029);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}