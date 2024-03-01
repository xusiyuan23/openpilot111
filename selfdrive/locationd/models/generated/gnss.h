#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_7770421545425657173);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6164518556458829483);
void gnss_H_mod_fun(double *state, double *out_2919674671833270942);
void gnss_f_fun(double *state, double dt, double *out_6013352302135505178);
void gnss_F_fun(double *state, double dt, double *out_8801647677645000288);
void gnss_h_6(double *state, double *sat_pos, double *out_1045578979136692424);
void gnss_H_6(double *state, double *sat_pos, double *out_241828252807820164);
void gnss_h_20(double *state, double *sat_pos, double *out_4714342939399742881);
void gnss_H_20(double *state, double *sat_pos, double *out_5855007215558211037);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8728837866926503241);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_6725550507955256095);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8728837866926503241);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_6725550507955256095);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}