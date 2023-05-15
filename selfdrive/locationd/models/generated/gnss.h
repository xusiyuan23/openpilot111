#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_7168960314819711533);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1733150604893116259);
void gnss_H_mod_fun(double *state, double *out_371800311444603574);
void gnss_f_fun(double *state, double dt, double *out_312732959618460837);
void gnss_F_fun(double *state, double dt, double *out_8832414516263107828);
void gnss_h_6(double *state, double *sat_pos, double *out_4697182586436612919);
void gnss_H_6(double *state, double *sat_pos, double *out_7897284550397221958);
void gnss_h_20(double *state, double *sat_pos, double *out_5766309662114082818);
void gnss_H_20(double *state, double *sat_pos, double *out_4592986296223702715);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_5139465688239376923);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1926627125318281676);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_5139465688239376923);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1926627125318281676);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}