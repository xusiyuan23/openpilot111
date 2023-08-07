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
void live_H(double *in_vec, double *out_2107061543090158966);
void live_err_fun(double *nom_x, double *delta_x, double *out_1090842864546838841);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_1751534880763809428);
void live_H_mod_fun(double *state, double *out_2270168032272230264);
void live_f_fun(double *state, double dt, double *out_9047640957774126431);
void live_F_fun(double *state, double dt, double *out_4752414459068816126);
void live_h_4(double *state, double *unused, double *out_1938047718740512528);
void live_H_4(double *state, double *unused, double *out_8437989887064667391);
void live_h_9(double *state, double *unused, double *out_2016376091952434025);
void live_H_9(double *state, double *unused, double *out_2721535251380436755);
void live_h_10(double *state, double *unused, double *out_8252027734007822314);
void live_H_10(double *state, double *unused, double *out_1022365631619946756);
void live_h_12(double *state, double *unused, double *out_490832941153373832);
void live_H_12(double *state, double *unused, double *out_4989297778612922430);
void live_h_35(double *state, double *unused, double *out_851812883202032952);
void live_H_35(double *state, double *unused, double *out_6642092129272276849);
void live_h_32(double *state, double *unused, double *out_7198045605532929596);
void live_H_32(double *state, double *unused, double *out_6510927344331536380);
void live_h_13(double *state, double *unused, double *out_6813957582124674447);
void live_H_13(double *state, double *unused, double *out_7851984426394690165);
void live_h_14(double *state, double *unused, double *out_2016376091952434025);
void live_H_14(double *state, double *unused, double *out_2721535251380436755);
void live_h_33(double *state, double *unused, double *out_1521077794722315231);
void live_H_33(double *state, double *unused, double *out_3491535124633419245);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}