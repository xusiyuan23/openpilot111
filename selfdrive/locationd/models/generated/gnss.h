#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4766384142186770465);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6278544928106810662);
void gnss_H_mod_fun(double *state, double *out_8097412979060097308);
void gnss_f_fun(double *state, double dt, double *out_3104780102329770139);
void gnss_F_fun(double *state, double dt, double *out_4096543142917168482);
void gnss_h_6(double *state, double *sat_pos, double *out_6758247131004536746);
void gnss_H_6(double *state, double *sat_pos, double *out_4686865741220841403);
void gnss_h_20(double *state, double *sat_pos, double *out_421409222323252481);
void gnss_H_20(double *state, double *sat_pos, double *out_4448074927986596639);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6662915346589297390);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7535590482650814090);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6662915346589297390);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7535590482650814090);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}