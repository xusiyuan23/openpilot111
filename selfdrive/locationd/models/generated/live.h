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
void live_H(double *in_vec, double *out_133227908697253646);
void live_err_fun(double *nom_x, double *delta_x, double *out_7956773024485299364);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2732543202000143924);
void live_H_mod_fun(double *state, double *out_3009125082534637337);
void live_f_fun(double *state, double dt, double *out_4335391440186581522);
void live_F_fun(double *state, double dt, double *out_5664590113989302035);
void live_h_4(double *state, double *unused, double *out_3014692161587012603);
void live_H_4(double *state, double *unused, double *out_5026841573156437834);
void live_h_9(double *state, double *unused, double *out_3562980285330159985);
void live_H_9(double *state, double *unused, double *out_6132683565288666312);
void live_h_10(double *state, double *unused, double *out_535862169176880815);
void live_H_10(double *state, double *unused, double *out_8297258708073091465);
void live_h_12(double *state, double *unused, double *out_925715247818340264);
void live_H_12(double *state, double *unused, double *out_5647940598204031501);
void live_h_35(double *state, double *unused, double *out_9149207542038296554);
void live_H_35(double *state, double *unused, double *out_8393503630529045210);
void live_h_32(double *state, double *unused, double *out_8538571874421941973);
void live_H_32(double *state, double *unused, double *out_5507022207680590714);
void live_h_13(double *state, double *unused, double *out_3046368725689310100);
void live_H_13(double *state, double *unused, double *out_619902790956587499);
void live_h_14(double *state, double *unused, double *out_3562980285330159985);
void live_H_14(double *state, double *unused, double *out_6132683565288666312);
void live_h_33(double *state, double *unused, double *out_6545880632453829262);
void live_H_33(double *state, double *unused, double *out_6902683438541648802);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}