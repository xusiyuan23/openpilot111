#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_6647689131199657613);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_8021804499807982886);
void gnss_H_mod_fun(double *state, double *out_7990695309930200593);
void gnss_f_fun(double *state, double dt, double *out_8004965045134918007);
void gnss_F_fun(double *state, double dt, double *out_2717500358276134323);
void gnss_h_6(double *state, double *sat_pos, double *out_182141457505723631);
void gnss_H_6(double *state, double *sat_pos, double *out_2143497049330031194);
void gnss_h_20(double *state, double *sat_pos, double *out_2957539294942517241);
void gnss_H_20(double *state, double *sat_pos, double *out_5178148131249966948);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2639259269154791275);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_6741483478705714184);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2639259269154791275);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_6741483478705714184);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}