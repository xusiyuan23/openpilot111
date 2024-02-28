#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8157223566737921768);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_2044125793472420016);
void gnss_H_mod_fun(double *state, double *out_9173041979963174697);
void gnss_f_fun(double *state, double dt, double *out_1618057822244112223);
void gnss_F_fun(double *state, double dt, double *out_2095238804530870251);
void gnss_h_6(double *state, double *sat_pos, double *out_8758992661908707843);
void gnss_H_6(double *state, double *sat_pos, double *out_3561767187659398853);
void gnss_h_20(double *state, double *sat_pos, double *out_2943069687929850059);
void gnss_H_20(double *state, double *sat_pos, double *out_2968919167798348741);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_4774871104966573529);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_149136905432068571);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_4774871104966573529);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_149136905432068571);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}