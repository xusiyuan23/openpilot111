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
void car_err_fun(double *nom_x, double *delta_x, double *out_2373438450883635122);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4678845552861946597);
void car_H_mod_fun(double *state, double *out_7488586493190929620);
void car_f_fun(double *state, double dt, double *out_6363234589794725649);
void car_F_fun(double *state, double dt, double *out_3089997159050685325);
void car_h_25(double *state, double *unused, double *out_582173192503055026);
void car_H_25(double *state, double *unused, double *out_4242371084562866524);
void car_h_24(double *state, double *unused, double *out_9199538503225060709);
void car_H_24(double *state, double *unused, double *out_7800296683365189660);
void car_h_30(double *state, double *unused, double *out_2365552797852429935);
void car_H_30(double *state, double *unused, double *out_7287682647655068337);
void car_h_26(double *state, double *unused, double *out_5178104901122283318);
void car_H_26(double *state, double *unused, double *out_4899225148673178428);
void car_h_27(double *state, double *unused, double *out_7968644223126639134);
void car_H_27(double *state, double *unused, double *out_8984298114254058368);
void car_h_29(double *state, double *unused, double *out_1197808996776288198);
void car_H_29(double *state, double *unused, double *out_6777451303340676153);
void car_h_28(double *state, double *unused, double *out_6278196388390958174);
void car_H_28(double *state, double *unused, double *out_6586893753299344889);
void car_h_31(double *state, double *unused, double *out_19244965110308528);
void car_H_31(double *state, double *unused, double *out_4273017046439826952);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}