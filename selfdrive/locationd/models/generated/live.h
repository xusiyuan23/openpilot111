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
void live_H(double *in_vec, double *out_4281580954174424078);
void live_err_fun(double *nom_x, double *delta_x, double *out_6020033059433352461);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_8784462575491582337);
void live_H_mod_fun(double *state, double *out_3196248901070636896);
void live_f_fun(double *state, double dt, double *out_1307995963717417138);
void live_F_fun(double *state, double dt, double *out_2913954870345271558);
void live_h_4(double *state, double *unused, double *out_5227201962942267756);
void live_H_4(double *state, double *unused, double *out_8934556766272716891);
void live_h_9(double *state, double *unused, double *out_8242329221781602876);
void live_H_9(double *state, double *unused, double *out_6045695213992637549);
void live_h_10(double *state, double *unused, double *out_4525709092164084266);
void live_H_10(double *state, double *unused, double *out_6290261927440969782);
void live_h_12(double *state, double *unused, double *out_1533628872533736742);
void live_H_12(double *state, double *unused, double *out_8313457741225123224);
void live_h_35(double *state, double *unused, double *out_3219567362710053882);
void live_H_35(double *state, double *unused, double *out_5567894708900109515);
void live_h_32(double *state, double *unused, double *out_7936133118583631274);
void live_H_32(double *state, double *unused, double *out_7279438951942359868);
void live_h_13(double *state, double *unused, double *out_2282936705415825262);
void live_H_13(double *state, double *unused, double *out_2592371241030708137);
void live_h_14(double *state, double *unused, double *out_8242329221781602876);
void live_H_14(double *state, double *unused, double *out_6045695213992637549);
void live_h_33(double *state, double *unused, double *out_5915136300903460843);
void live_H_33(double *state, double *unused, double *out_2417337704261251911);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}