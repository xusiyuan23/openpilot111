#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4028801004516007796);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_3768849830028997118);
void gnss_H_mod_fun(double *state, double *out_2860011657596565513);
void gnss_f_fun(double *state, double dt, double *out_8277081820145941661);
void gnss_F_fun(double *state, double dt, double *out_5064250981141033808);
void gnss_h_6(double *state, double *sat_pos, double *out_7274148501542244040);
void gnss_H_6(double *state, double *sat_pos, double *out_7813858614004248739);
void gnss_h_20(double *state, double *sat_pos, double *out_6896396091969207190);
void gnss_H_20(double *state, double *sat_pos, double *out_4020760982424116862);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_9148421716190266371);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1227456213680405631);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_9148421716190266371);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1227456213680405631);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}