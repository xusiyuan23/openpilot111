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
void live_H(double *in_vec, double *out_409344677196790516);
void live_err_fun(double *nom_x, double *delta_x, double *out_5410019838797489797);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5107495764560298202);
void live_H_mod_fun(double *state, double *out_4893943347815461903);
void live_f_fun(double *state, double dt, double *out_1490934551927816954);
void live_F_fun(double *state, double dt, double *out_2062859019570548817);
void live_h_4(double *state, double *unused, double *out_335431168283599212);
void live_H_4(double *state, double *unused, double *out_4205541147974148351);
void live_h_9(double *state, double *unused, double *out_1746837330775165620);
void live_H_9(double *state, double *unused, double *out_3964351501344557706);
void live_h_10(double *state, double *unused, double *out_6389141055710814361);
void live_H_10(double *state, double *unused, double *out_394910773077939482);
void live_h_12(double *state, double *unused, double *out_4800955541602290447);
void live_H_12(double *state, double *unused, double *out_813915260057813444);
void live_h_35(double *state, double *unused, double *out_8655348954820926857);
void live_H_35(double *state, double *unused, double *out_838879090601540975);
void live_h_32(double *state, double *unused, double *out_7002226014671976453);
void live_H_32(double *state, double *unused, double *out_707714305660800506);
void live_h_13(double *state, double *unused, double *out_6173959503153832213);
void live_H_13(double *state, double *unused, double *out_1842862337219813003);
void live_h_14(double *state, double *unused, double *out_1746837330775165620);
void live_H_14(double *state, double *unused, double *out_3964351501344557706);
void live_h_33(double *state, double *unused, double *out_5949943105988094266);
void live_H_33(double *state, double *unused, double *out_2311677914037316629);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}