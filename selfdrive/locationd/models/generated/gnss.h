#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4849909810210845231);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_9155514165852770581);
void gnss_H_mod_fun(double *state, double *out_1695716312477195060);
void gnss_f_fun(double *state, double dt, double *out_246318625600254703);
void gnss_F_fun(double *state, double dt, double *out_991013928034158677);
void gnss_h_6(double *state, double *sat_pos, double *out_3254589478467387681);
void gnss_H_6(double *state, double *sat_pos, double *out_4443399033591840542);
void gnss_h_20(double *state, double *sat_pos, double *out_5372212336627346046);
void gnss_H_20(double *state, double *sat_pos, double *out_2252354659347544918);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6050116121606786003);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2862955004951087597);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6050116121606786003);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2862955004951087597);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}