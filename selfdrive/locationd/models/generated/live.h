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
void live_H(double *in_vec, double *out_5647844793781907598);
void live_err_fun(double *nom_x, double *delta_x, double *out_7240336443609568449);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5067105285576238600);
void live_H_mod_fun(double *state, double *out_1707446900005187655);
void live_f_fun(double *state, double dt, double *out_8886202847586122156);
void live_F_fun(double *state, double dt, double *out_8123954071177754895);
void live_h_4(double *state, double *unused, double *out_5003732951226513629);
void live_H_4(double *state, double *unused, double *out_7002519190470052957);
void live_h_9(double *state, double *unused, double *out_2706973776430170011);
void live_H_9(double *state, double *unused, double *out_7243708837099643602);
void live_h_10(double *state, double *unused, double *out_5958541671058094074);
void live_H_10(double *state, double *unused, double *out_6806706378750062726);
void live_h_12(double *state, double *unused, double *out_3703959340398270602);
void live_H_12(double *state, double *unused, double *out_6424768475207536864);
void live_h_35(double *state, double *unused, double *out_1455318101445775547);
void live_H_35(double *state, double *unused, double *out_8077562825866891283);
void live_h_32(double *state, double *unused, double *out_6206442455067868074);
void live_H_32(double *state, double *unused, double *out_6136724488533882482);
void live_h_13(double *state, double *unused, double *out_5313389083226060905);
void live_H_13(double *state, double *unused, double *out_8424484780051135399);
void live_h_14(double *state, double *unused, double *out_2706973776430170011);
void live_H_14(double *state, double *unused, double *out_7243708837099643602);
void live_h_33(double *state, double *unused, double *out_2007778731318175820);
void live_H_33(double *state, double *unused, double *out_4927005821228033679);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}