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
void live_H(double *in_vec, double *out_2363812074447305841);
void live_err_fun(double *nom_x, double *delta_x, double *out_6269769043913535493);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7372408302410611357);
void live_H_mod_fun(double *state, double *out_323168030093411574);
void live_f_fun(double *state, double dt, double *out_8727360583652276978);
void live_F_fun(double *state, double dt, double *out_56582328146481194);
void live_h_4(double *state, double *unused, double *out_3495874077871324958);
void live_H_4(double *state, double *unused, double *out_5675340409063545143);
void live_h_9(double *state, double *unused, double *out_2329430295379681157);
void live_H_9(double *state, double *unused, double *out_5916530055693135788);
void live_h_10(double *state, double *unused, double *out_6002666685057306713);
void live_H_10(double *state, double *unused, double *out_1457761977046980482);
void live_h_12(double *state, double *unused, double *out_2504055259638529936);
void live_H_12(double *state, double *unused, double *out_7751947256614044678);
void live_h_35(double *state, double *unused, double *out_7742259407295802366);
void live_H_35(double *state, double *unused, double *out_9042002466436152519);
void live_h_32(double *state, double *unused, double *out_6946137798333760961);
void live_H_32(double *state, double *unused, double *out_6155521043587698023);
void live_h_13(double *state, double *unused, double *out_7588585975073727177);
void live_H_13(double *state, double *unused, double *out_8230890641426416896);
void live_h_14(double *state, double *unused, double *out_2329430295379681157);
void live_H_14(double *state, double *unused, double *out_5916530055693135788);
void live_h_33(double *state, double *unused, double *out_4608549978778917310);
void live_H_33(double *state, double *unused, double *out_6254184602634541493);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}