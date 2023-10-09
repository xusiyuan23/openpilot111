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
void car_err_fun(double *nom_x, double *delta_x, double *out_5396984848100642927);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3673760116113969531);
void car_H_mod_fun(double *state, double *out_8420735785113075149);
void car_f_fun(double *state, double dt, double *out_1495193358530267545);
void car_F_fun(double *state, double dt, double *out_8190059203776966087);
void car_h_25(double *state, double *unused, double *out_7770804733125093021);
void car_H_25(double *state, double *unused, double *out_3029957647977105485);
void car_h_24(double *state, double *unused, double *out_6297919134326163066);
void car_H_24(double *state, double *unused, double *out_6188721239663250906);
void car_h_30(double *state, double *unused, double *out_4823078742769608060);
void car_H_30(double *state, double *unused, double *out_1497738682150502713);
void car_h_26(double *state, double *unused, double *out_8621992063279097911);
void car_H_26(double *state, double *unused, double *out_711545670896950739);
void car_h_27(double *state, double *unused, double *out_1693970168577617830);
void car_H_27(double *state, double *unused, double *out_3672501993950927624);
void car_h_29(double *state, double *unused, double *out_1092552010964254276);
void car_H_29(double *state, double *unused, double *out_987507337836110529);
void car_h_28(double *state, double *unused, double *out_6695643436238463475);
void car_H_28(double *state, double *unused, double *out_6069906354905641103);
void car_h_31(double *state, double *unused, double *out_6945152627337250165);
void car_H_31(double *state, double *unused, double *out_1337753773130302215);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}