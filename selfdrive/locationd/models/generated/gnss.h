#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_5270397344340919402);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1512259161409062554);
void gnss_H_mod_fun(double *state, double *out_8413937430488034064);
void gnss_f_fun(double *state, double dt, double *out_8044790491496694058);
void gnss_F_fun(double *state, double dt, double *out_7107643139068643538);
void gnss_h_6(double *state, double *sat_pos, double *out_1014783744438669605);
void gnss_H_6(double *state, double *sat_pos, double *out_2647892629803094557);
void gnss_h_20(double *state, double *sat_pos, double *out_4446463785726682298);
void gnss_H_20(double *state, double *sat_pos, double *out_2058835805956563056);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6977013047509885177);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3396370189700754510);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6977013047509885177);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3396370189700754510);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}