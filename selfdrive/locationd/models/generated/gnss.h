#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_9035463591687765688);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_4584995547093836909);
void gnss_H_mod_fun(double *state, double *out_485515789311103855);
void gnss_f_fun(double *state, double dt, double *out_2804668263201152505);
void gnss_F_fun(double *state, double dt, double *out_5897584534679452406);
void gnss_h_6(double *state, double *sat_pos, double *out_7299654809535441585);
void gnss_H_6(double *state, double *sat_pos, double *out_4935507375780414315);
void gnss_h_20(double *state, double *sat_pos, double *out_2539033399603050808);
void gnss_H_20(double *state, double *sat_pos, double *out_5887166057814938);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_3700295129188825651);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3222417806161331882);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_3700295129188825651);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3222417806161331882);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}