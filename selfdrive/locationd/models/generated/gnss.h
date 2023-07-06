#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_1753087778211117269);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_2956927510017451437);
void gnss_H_mod_fun(double *state, double *out_3719518099167795508);
void gnss_f_fun(double *state, double dt, double *out_897954495300312922);
void gnss_F_fun(double *state, double dt, double *out_6443902817737307729);
void gnss_h_6(double *state, double *sat_pos, double *out_245286193991190596);
void gnss_H_6(double *state, double *sat_pos, double *out_1271139816703817215);
void gnss_h_20(double *state, double *sat_pos, double *out_7714962011380569024);
void gnss_H_20(double *state, double *sat_pos, double *out_7189362631491019695);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_3341484752321584106);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2769680937173047531);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_3341484752321584106);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2769680937173047531);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}