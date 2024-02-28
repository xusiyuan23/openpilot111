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
void live_H(double *in_vec, double *out_6974567924666299102);
void live_err_fun(double *nom_x, double *delta_x, double *out_2493100912041570996);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7217190665066253352);
void live_H_mod_fun(double *state, double *out_6899062083944887710);
void live_f_fun(double *state, double dt, double *out_252278658732009113);
void live_F_fun(double *state, double dt, double *out_4169121626430309510);
void live_h_4(double *state, double *unused, double *out_2184045668377535913);
void live_H_4(double *state, double *unused, double *out_5091087556127760923);
void live_h_9(double *state, double *unused, double *out_8158653303070436890);
void live_H_9(double *state, double *unused, double *out_2196131379136686547);
void live_h_10(double *state, double *unused, double *out_6830468309703972597);
void live_H_10(double *state, double *unused, double *out_8221089086801312150);
void live_h_12(double *state, double *unused, double *out_3698550038738074472);
void live_H_12(double *state, double *unused, double *out_6974398140539057697);
void live_h_35(double *state, double *unused, double *out_3507821483290070437);
void live_H_35(double *state, double *unused, double *out_1724425498755153547);
void live_h_32(double *state, double *unused, double *out_1049805558840064954);
void live_H_32(double *state, double *unused, double *out_1593260713814413078);
void live_h_13(double *state, double *unused, double *out_1881416958735212550);
void live_H_13(double *state, double *unused, double *out_5911629335895004065);
void live_h_14(double *state, double *unused, double *out_8158653303070436890);
void live_H_14(double *state, double *unused, double *out_2196131379136686547);
void live_h_33(double *state, double *unused, double *out_7532622185414820130);
void live_H_33(double *state, double *unused, double *out_8472160794518560882);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}