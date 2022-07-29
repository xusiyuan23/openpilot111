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
void car_err_fun(double *nom_x, double *delta_x, double *out_5305892781643857816);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1853389451438471044);
void car_H_mod_fun(double *state, double *out_5416974647485655115);
void car_f_fun(double *state, double dt, double *out_460653607240400145);
void car_F_fun(double *state, double dt, double *out_5038888743742275480);
void car_h_25(double *state, double *unused, double *out_4621858964207047798);
void car_H_25(double *state, double *unused, double *out_3584924347823833573);
void car_h_24(double *state, double *unused, double *out_5377863993793220584);
void car_H_24(double *state, double *unused, double *out_5762138771430983546);
void car_h_30(double *state, double *unused, double *out_4386184082412952466);
void car_H_30(double *state, double *unused, double *out_6103257306331082200);
void car_h_26(double *state, double *unused, double *out_5840562879393216122);
void car_H_26(double *state, double *unused, double *out_156578971050222651);
void car_h_27(double *state, double *unused, double *out_2380903739586017981);
void car_H_27(double *state, double *unused, double *out_3928493994530657289);
void car_h_29(double *state, double *unused, double *out_2538090407937147126);
void car_H_29(double *state, double *unused, double *out_6613488650645474384);
void car_h_28(double *state, double *unused, double *out_6207258942218823427);
void car_H_28(double *state, double *unused, double *out_1531089633575943810);
void car_h_31(double *state, double *unused, double *out_8298827672951480705);
void car_H_31(double *state, double *unused, double *out_782787073283574127);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}