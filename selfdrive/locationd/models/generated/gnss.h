#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3729148486180488546);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_5677138656413877520);
void gnss_H_mod_fun(double *state, double *out_237374271348491673);
void gnss_f_fun(double *state, double dt, double *out_5929499374247199262);
void gnss_F_fun(double *state, double dt, double *out_847881920946397673);
void gnss_h_6(double *state, double *sat_pos, double *out_4769849476023598544);
void gnss_H_6(double *state, double *sat_pos, double *out_747127776806928814);
void gnss_h_20(double *state, double *sat_pos, double *out_5861460590680520073);
void gnss_H_20(double *state, double *sat_pos, double *out_8385843719838436302);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_5467876944101765304);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_4135749185661226665);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_5467876944101765304);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_4135749185661226665);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}