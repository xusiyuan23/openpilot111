#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4464393586256638428);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_8030080671851608904);
void gnss_H_mod_fun(double *state, double *out_8251410735794788719);
void gnss_f_fun(double *state, double dt, double *out_5670922108486976517);
void gnss_F_fun(double *state, double dt, double *out_285810453574311978);
void gnss_h_6(double *state, double *sat_pos, double *out_4260298364022558171);
void gnss_H_6(double *state, double *sat_pos, double *out_8167589833904039300);
void gnss_h_20(double *state, double *sat_pos, double *out_3277277287931894451);
void gnss_H_20(double *state, double *sat_pos, double *out_7951946710659046603);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1118653479581001871);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_390583059234594540);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1118653479581001871);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_390583059234594540);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}