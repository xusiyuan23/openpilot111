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
void live_H(double *in_vec, double *out_8878279768875785666);
void live_err_fun(double *nom_x, double *delta_x, double *out_4998791096521120383);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_1441787487494056884);
void live_H_mod_fun(double *state, double *out_2717665409679363478);
void live_f_fun(double *state, double dt, double *out_403942427496437977);
void live_F_fun(double *state, double dt, double *out_2458917812698566361);
void live_h_4(double *state, double *unused, double *out_8582149101819624565);
void live_H_4(double *state, double *unused, double *out_5558417177173870845);
void live_h_9(double *state, double *unused, double *out_1154860171408856960);
void live_H_9(double *state, double *unused, double *out_5601107961271233301);
void live_h_10(double *state, double *unused, double *out_969643799357744360);
void live_H_10(double *state, double *unused, double *out_3456013052689401283);
void live_h_12(double *state, double *unused, double *out_5206625952372223305);
void live_H_12(double *state, double *unused, double *out_7868870488503718976);
void live_h_35(double *state, double *unused, double *out_9180592447251693531);
void live_H_35(double *state, double *unused, double *out_8925079234546478221);
void live_h_32(double *state, double *unused, double *out_1313397742306899264);
void live_H_32(double *state, double *unused, double *out_3325668821679395988);
void live_h_13(double *state, double *unused, double *out_2452376588077375079);
void live_H_13(double *state, double *unused, double *out_617763348992320591);
void live_h_14(double *state, double *unused, double *out_1154860171408856960);
void live_H_14(double *state, double *unused, double *out_5601107961271233301);
void live_h_33(double *state, double *unused, double *out_6863252709328783372);
void live_H_33(double *state, double *unused, double *out_6371107834524215791);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}