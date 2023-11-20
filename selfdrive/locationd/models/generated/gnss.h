#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_1298370022994424896);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1216411467074742856);
void gnss_H_mod_fun(double *state, double *out_5581863977132795483);
void gnss_f_fun(double *state, double dt, double *out_6423546374911735369);
void gnss_F_fun(double *state, double dt, double *out_7437858096387244450);
void gnss_h_6(double *state, double *sat_pos, double *out_8168523164697780971);
void gnss_H_6(double *state, double *sat_pos, double *out_6215961085732895038);
void gnss_h_20(double *state, double *sat_pos, double *out_2583752503617678104);
void gnss_H_20(double *state, double *sat_pos, double *out_6777344250897440240);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7914792312414388917);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1169512049399806794);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7914792312414388917);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1169512049399806794);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}