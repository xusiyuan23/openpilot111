#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2067482950567323166);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_2603530649313476471);
void gnss_H_mod_fun(double *state, double *out_5820927568950649229);
void gnss_f_fun(double *state, double dt, double *out_17551380326686977);
void gnss_F_fun(double *state, double dt, double *out_414838326010165834);
void gnss_h_6(double *state, double *sat_pos, double *out_9074704291738973277);
void gnss_H_6(double *state, double *sat_pos, double *out_8056400913830408537);
void gnss_h_20(double *state, double *sat_pos, double *out_5771271505288635021);
void gnss_H_20(double *state, double *sat_pos, double *out_5454875328892457956);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_5412429359018771727);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1987528380465191465);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_5412429359018771727);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1987528380465191465);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}