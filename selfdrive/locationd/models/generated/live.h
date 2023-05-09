#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_8241352854636576825);
void live_err_fun(double *nom_x, double *delta_x, double *out_6956584107259677061);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3735347823356468233);
void live_H_mod_fun(double *state, double *out_7215248881055738529);
void live_f_fun(double *state, double dt, double *out_7385605237598930115);
void live_F_fun(double *state, double dt, double *out_7056904015291554990);
void live_h_4(double *state, double *unused, double *out_8349449970116828970);
void live_H_4(double *state, double *unused, double *out_7188737480185803033);
void live_h_9(double *state, double *unused, double *out_3652459562989647923);
void live_H_9(double *state, double *unused, double *out_6947547833556212388);
void live_h_10(double *state, double *unused, double *out_8215662764779518370);
void live_H_10(double *state, double *unused, double *out_2094257637643028062);
void live_h_12(double *state, double *unused, double *out_8569197030249233888);
void live_H_12(double *state, double *unused, double *out_2169281072153841238);
void live_h_35(double *state, double *unused, double *out_1501917841267451246);
void live_H_35(double *state, double *unused, double *out_576281960171172471);
void live_h_32(double *state, double *unused, double *out_8996403947392874492);
void live_H_32(double *state, double *unused, double *out_6377586332378785029);
void live_h_13(double *state, double *unused, double *out_5387084151892622067);
void live_H_13(double *state, double *unused, double *out_1375958207698795133);
void live_h_14(double *state, double *unused, double *out_3652459562989647923);
void live_H_14(double *state, double *unused, double *out_6947547833556212388);
void live_h_33(double *state, double *unused, double *out_3390849479985008479);
void live_H_33(double *state, double *unused, double *out_3726838964810030075);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}