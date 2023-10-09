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
void live_H(double *in_vec, double *out_5472226391913428582);
void live_err_fun(double *nom_x, double *delta_x, double *out_6508029974320597245);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2019856750264798283);
void live_H_mod_fun(double *state, double *out_8564774469718261605);
void live_f_fun(double *state, double dt, double *out_2167758224172516708);
void live_F_fun(double *state, double dt, double *out_6604773883138368354);
void live_h_4(double *state, double *unused, double *out_5070441118667315187);
void live_H_4(double *state, double *unused, double *out_7142926226124309892);
void live_h_9(double *state, double *unused, double *out_1124175015924690318);
void live_H_9(double *state, double *unused, double *out_7146650111230464241);
void live_h_10(double *state, double *unused, double *out_2109137017318231990);
void live_H_10(double *state, double *unused, double *out_5552727043354966226);
void live_h_12(double *state, double *unused, double *out_5291604573526602269);
void live_H_12(double *state, double *unused, double *out_6521827201076716225);
void live_h_35(double *state, double *unused, double *out_2118741506585347044);
void live_H_35(double *state, double *unused, double *out_3776264168751702516);
void live_h_32(double *state, double *unused, double *out_3360608214289959379);
void live_H_32(double *state, double *unused, double *out_7755615401263732744);
void live_h_13(double *state, double *unused, double *out_5506979747554367956);
void live_H_13(double *state, double *unused, double *out_8591558027073825108);
void live_h_14(double *state, double *unused, double *out_1124175015924690318);
void live_H_14(double *state, double *unused, double *out_7146650111230464241);
void live_h_33(double *state, double *unused, double *out_5570441104795240755);
void live_H_33(double *state, double *unused, double *out_625707164112844912);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}