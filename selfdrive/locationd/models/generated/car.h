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
void car_err_fun(double *nom_x, double *delta_x, double *out_4194531078134201846);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5396071230919349347);
void car_H_mod_fun(double *state, double *out_2499327206041353790);
void car_f_fun(double *state, double dt, double *out_4500860229340437360);
void car_F_fun(double *state, double dt, double *out_9000440748762279641);
void car_h_25(double *state, double *unused, double *out_2791333436777253726);
void car_H_25(double *state, double *unused, double *out_7985710765029417005);
void car_h_24(double *state, double *unused, double *out_5318903299789527977);
void car_H_24(double *state, double *unused, double *out_5760002981050548443);
void car_h_30(double *state, double *unused, double *out_2634146768426124581);
void car_H_30(double *state, double *unused, double *out_1069020423537800250);
void car_h_26(double *state, double *unused, double *out_7596526766107417813);
void car_H_26(double *state, double *unused, double *out_6719529989806078387);
void car_h_27(double *state, double *unused, double *out_4419576049476967785);
void car_H_27(double *state, double *unused, double *out_3243783735338225161);
void car_h_29(double *state, double *unused, double *out_4144381987192461896);
void car_H_29(double *state, double *unused, double *out_558789079223408066);
void car_h_28(double *state, double *unused, double *out_582097218183877860);
void car_H_28(double *state, double *unused, double *out_5641188096292938640);
void car_h_31(double *state, double *unused, double *out_5163811280143236534);
void car_H_31(double *state, double *unused, double *out_7955064803152456577);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}