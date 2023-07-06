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
void live_H(double *in_vec, double *out_5128157265026678182);
void live_err_fun(double *nom_x, double *delta_x, double *out_2798632635382813919);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5339335174414579736);
void live_H_mod_fun(double *state, double *out_1284023194967019530);
void live_f_fun(double *state, double dt, double *out_1421591046507185130);
void live_F_fun(double *state, double dt, double *out_7704460823213363823);
void live_h_4(double *state, double *unused, double *out_602047715749074833);
void live_H_4(double *state, double *unused, double *out_9042268972257776925);
void live_h_9(double *state, double *unused, double *out_4954724991031095057);
void live_H_9(double *state, double *unused, double *out_2117256166187327221);
void live_h_10(double *state, double *unused, double *out_8523310708961865851);
void live_H_10(double *state, double *unused, double *out_4826563757172353065);
void live_h_12(double *state, double *unused, double *out_2499034109806295132);
void live_H_12(double *state, double *unused, double *out_4385018693419812896);
void live_h_35(double *state, double *unused, double *out_4692529026086718755);
void live_H_35(double *state, double *unused, double *out_1639455661094799187);
void live_h_32(double *state, double *unused, double *out_7068888198573815517);
void live_H_32(double *state, double *unused, double *out_7238866073961881420);
void live_h_13(double *state, double *unused, double *out_7559512868723735515);
void live_H_13(double *state, double *unused, double *out_8231147310952013425);
void live_h_14(double *state, double *unused, double *out_4954724991031095057);
void live_H_14(double *state, double *unused, double *out_2117256166187327221);
void live_h_33(double *state, double *unused, double *out_1217344797616727358);
void live_H_33(double *state, double *unused, double *out_1511101343544058417);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}