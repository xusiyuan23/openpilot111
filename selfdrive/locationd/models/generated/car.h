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
void car_err_fun(double *nom_x, double *delta_x, double *out_5707134025468540196);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1436040563472290876);
void car_H_mod_fun(double *state, double *out_3949928528883118484);
void car_f_fun(double *state, double dt, double *out_7070584549021633741);
void car_F_fun(double *state, double dt, double *out_6590587311256226805);
void car_h_25(double *state, double *unused, double *out_5654373301579232004);
void car_H_25(double *state, double *unused, double *out_7074661439769165345);
void car_h_24(double *state, double *unused, double *out_6513601548719522224);
void car_H_24(double *state, double *unused, double *out_499089633177647244);
void car_h_30(double *state, double *unused, double *out_3209738123313789182);
void car_H_30(double *state, double *unused, double *out_157971098277548590);
void car_h_26(double *state, double *unused, double *out_3813054007990266699);
void car_H_26(double *state, double *unused, double *out_3770135470008364744);
void car_h_27(double *state, double *unused, double *out_2617587250134899319);
void car_H_27(double *state, double *unused, double *out_2332734410077973501);
void car_h_29(double *state, double *unused, double *out_4153247976215451617);
void car_H_29(double *state, double *unused, double *out_4046097136947524534);
void car_h_28(double *state, double *unused, double *out_7032847359308655157);
void car_H_28(double *state, double *unused, double *out_9128496154017055108);
void car_h_31(double *state, double *unused, double *out_5379179239294726115);
void car_H_31(double *state, double *unused, double *out_2013810742651908);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}