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
void live_H(double *in_vec, double *out_2599424605208563416);
void live_err_fun(double *nom_x, double *delta_x, double *out_5906482688677727015);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4105895011660699419);
void live_H_mod_fun(double *state, double *out_2441862623175928931);
void live_f_fun(double *state, double dt, double *out_983049846573028201);
void live_F_fun(double *state, double dt, double *out_2308345629494973071);
void live_h_4(double *state, double *unused, double *out_1273194498352079153);
void live_H_4(double *state, double *unused, double *out_5044539697197672704);
void live_h_9(double *state, double *unused, double *out_2204105631185551866);
void live_H_9(double *state, double *unused, double *out_4803350050568082059);
void live_h_10(double *state, double *unused, double *out_7635301002432442638);
void live_H_10(double *state, double *unused, double *out_1213061047748453780);
void live_h_12(double *state, double *unused, double *out_1818537461731555083);
void live_H_12(double *state, double *unused, double *out_25083289165710909);
void live_h_35(double *state, double *unused, double *out_4500813549489714448);
void live_H_35(double *state, double *unused, double *out_1677877639825065328);
void live_h_32(double *state, double *unused, double *out_1098957125053886739);
void live_H_32(double *state, double *unused, double *out_2407858048271857772);
void live_h_13(double *state, double *unused, double *out_3841394929060829831);
void live_H_13(double *state, double *unused, double *out_7526864419708909240);
void live_h_14(double *state, double *unused, double *out_2204105631185551866);
void live_H_14(double *state, double *unused, double *out_4803350050568082059);
void live_h_33(double *state, double *unused, double *out_7615682792382094432);
void live_H_33(double *state, double *unused, double *out_1472679364813792276);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}