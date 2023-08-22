#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2155524759348881706);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_3000442515133824169);
void gnss_H_mod_fun(double *state, double *out_6886810493919790975);
void gnss_f_fun(double *state, double dt, double *out_8724257366443597251);
void gnss_F_fun(double *state, double dt, double *out_2206723714956142118);
void gnss_h_6(double *state, double *sat_pos, double *out_9215791719434072081);
void gnss_H_6(double *state, double *sat_pos, double *out_6079281560797038039);
void gnss_h_20(double *state, double *sat_pos, double *out_707679285162606847);
void gnss_H_20(double *state, double *sat_pos, double *out_6425650286104756584);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8648640613651272087);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_236788228116502184);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8648640613651272087);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_236788228116502184);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}