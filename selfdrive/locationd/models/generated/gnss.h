#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_7450363419333197724);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6032626064256685771);
void gnss_H_mod_fun(double *state, double *out_5362512971153695335);
void gnss_f_fun(double *state, double dt, double *out_5166670299033539086);
void gnss_F_fun(double *state, double dt, double *out_1872100173248322506);
void gnss_h_6(double *state, double *sat_pos, double *out_8967874647147044523);
void gnss_H_6(double *state, double *sat_pos, double *out_7893943660228887170);
void gnss_h_20(double *state, double *sat_pos, double *out_9116871330935910653);
void gnss_H_20(double *state, double *sat_pos, double *out_5950134878048585736);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2263061303225699817);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2633963512929241755);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2263061303225699817);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2633963512929241755);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}