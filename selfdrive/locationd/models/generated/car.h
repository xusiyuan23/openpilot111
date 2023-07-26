#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8452624162127135067);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7823778302228655464);
void car_H_mod_fun(double *state, double *out_7408182881780194727);
void car_f_fun(double *state, double dt, double *out_8553102301205751821);
void car_F_fun(double *state, double dt, double *out_7871600829975871160);
void car_h_25(double *state, double *unused, double *out_3221146209385952877);
void car_H_25(double *state, double *unused, double *out_3868364801350448310);
void car_h_24(double *state, double *unused, double *out_3852580440014561271);
void car_H_24(double *state, double *unused, double *out_1000450063677258542);
void car_h_30(double *state, double *unused, double *out_4660126441368096308);
void car_H_30(double *state, double *unused, double *out_659331528777159888);
void car_h_26(double *state, double *unused, double *out_8301533601000622853);
void car_H_26(double *state, double *unused, double *out_126861482476392086);
void car_h_27(double *state, double *unused, double *out_1870892342875456835);
void car_H_27(double *state, double *unused, double *out_2834094840577584799);
void car_h_29(double *state, double *unused, double *out_1595698280590950946);
void car_H_29(double *state, double *unused, double *out_149100184462767704);
void car_h_28(double *state, double *unused, double *out_4475297663684154486);
void car_H_28(double *state, double *unused, double *out_5231499201532298278);
void car_h_31(double *state, double *unused, double *out_5421934217907419313);
void car_H_31(double *state, double *unused, double *out_499346619756959390);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}