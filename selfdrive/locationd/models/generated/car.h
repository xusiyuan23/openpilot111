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
void car_err_fun(double *nom_x, double *delta_x, double *out_7398202595670281399);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1202273728262154148);
void car_H_mod_fun(double *state, double *out_3953678512844074941);
void car_f_fun(double *state, double dt, double *out_4919033046586703302);
void car_F_fun(double *state, double dt, double *out_4107182711379579553);
void car_h_25(double *state, double *unused, double *out_1567680244849663411);
void car_H_25(double *state, double *unused, double *out_5225987524986084127);
void car_h_24(double *state, double *unused, double *out_2364262104948025745);
void car_H_24(double *state, double *unused, double *out_6913803960855188318);
void car_h_30(double *state, double *unused, double *out_2025881607008225073);
void car_H_30(double *state, double *unused, double *out_6304066207231850734);
void car_h_26(double *state, double *unused, double *out_7624553002435329403);
void car_H_26(double *state, double *unused, double *out_1484484206112027903);
void car_h_27(double *state, double *unused, double *out_7786159700633563417);
void car_H_27(double *state, double *unused, double *out_8478829519032275645);
void car_h_29(double *state, double *unused, double *out_2897319116255315758);
void car_H_29(double *state, double *unused, double *out_8254551827807724938);
void car_h_28(double *state, double *unused, double *out_1907874213074848329);
void car_H_28(double *state, double *unused, double *out_3172152810738194364);
void car_h_31(double *state, double *unused, double *out_6195585011971009030);
void car_H_31(double *state, double *unused, double *out_5256633486863044555);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}