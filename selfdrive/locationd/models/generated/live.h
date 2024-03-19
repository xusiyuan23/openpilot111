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
void live_H(double *in_vec, double *out_6142139148085243549);
void live_err_fun(double *nom_x, double *delta_x, double *out_7221775709047634355);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7708138673724865102);
void live_H_mod_fun(double *state, double *out_606820068770458248);
void live_f_fun(double *state, double dt, double *out_8552173667168449856);
void live_F_fun(double *state, double dt, double *out_7518165017466021174);
void live_h_4(double *state, double *unused, double *out_1872526693599117952);
void live_H_4(double *state, double *unused, double *out_6588697467925331782);
void live_h_9(double *state, double *unused, double *out_2674948355925126045);
void live_H_9(double *state, double *unused, double *out_6347507821295741137);
void live_h_10(double *state, double *unused, double *out_2559390531990348826);
void live_H_10(double *state, double *unused, double *out_1384317159145848313);
void live_h_12(double *state, double *unused, double *out_3028429799449360277);
void live_H_12(double *state, double *unused, double *out_1569241059893369987);
void live_h_35(double *state, double *unused, double *out_8338918323392468458);
void live_H_35(double *state, double *unused, double *out_1176321972431643722);
void live_h_32(double *state, double *unused, double *out_7926082639028507978);
void live_H_32(double *state, double *unused, double *out_1710159450416810774);
void live_h_13(double *state, double *unused, double *out_8080423631789857062);
void live_H_13(double *state, double *unused, double *out_5143337386914164914);
void live_h_14(double *state, double *unused, double *out_2674948355925126045);
void live_H_14(double *state, double *unused, double *out_6347507821295741137);
void live_h_33(double *state, double *unused, double *out_6864593969968010794);
void live_H_33(double *state, double *unused, double *out_4326878977070501326);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}