#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8330333360624833292);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6322537350686059778);
void gnss_H_mod_fun(double *state, double *out_6515884925296062016);
void gnss_f_fun(double *state, double dt, double *out_523365963258079124);
void gnss_F_fun(double *state, double dt, double *out_5168491338484130631);
void gnss_h_6(double *state, double *sat_pos, double *out_1139312402143986909);
void gnss_H_6(double *state, double *sat_pos, double *out_2439869829476496896);
void gnss_h_20(double *state, double *sat_pos, double *out_6664425544558842711);
void gnss_H_20(double *state, double *sat_pos, double *out_164586234965804468);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8735629225209972255);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7961471765576663032);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8735629225209972255);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7961471765576663032);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}