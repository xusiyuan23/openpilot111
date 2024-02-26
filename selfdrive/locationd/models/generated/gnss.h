#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8519908807701444381);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_7494726988393394594);
void gnss_H_mod_fun(double *state, double *out_6213794081998936506);
void gnss_f_fun(double *state, double dt, double *out_7557732014251175831);
void gnss_F_fun(double *state, double dt, double *out_3784107475037224440);
void gnss_h_6(double *state, double *sat_pos, double *out_1045706946388579730);
void gnss_H_6(double *state, double *sat_pos, double *out_6469468708647551695);
void gnss_h_20(double *state, double *sat_pos, double *out_4390939550384841311);
void gnss_H_20(double *state, double *sat_pos, double *out_4150453882875260635);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_882947065038288714);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_4769832076722140500);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_882947065038288714);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_4769832076722140500);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}