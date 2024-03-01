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
void car_err_fun(double *nom_x, double *delta_x, double *out_5511008102036755857);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8300600328275299875);
void car_H_mod_fun(double *state, double *out_3128679903101307724);
void car_f_fun(double *state, double dt, double *out_3553875974525626115);
void car_F_fun(double *state, double dt, double *out_353016053043653311);
void car_h_25(double *state, double *unused, double *out_6199961577350591037);
void car_H_25(double *state, double *unused, double *out_5728077160425784390);
void car_h_24(double *state, double *unused, double *out_4286546153885119283);
void car_H_24(double *state, double *unused, double *out_5275992320295050906);
void car_h_30(double *state, double *unused, double *out_570873648999759899);
void car_H_30(double *state, double *unused, double *out_8190970583156159028);
void car_h_26(double *state, double *unused, double *out_372636203901902536);
void car_H_26(double *state, double *unused, double *out_8977163594409711002);
void car_h_27(double *state, double *unused, double *out_7245109228698114934);
void car_H_27(double *state, double *unused, double *out_8032179419369449371);
void car_h_29(double *state, double *unused, double *out_4430799618661085746);
void car_H_29(double *state, double *unused, double *out_8701201927470551212);
void car_h_28(double *state, double *unused, double *out_2243435961037269289);
void car_H_28(double *state, double *unused, double *out_7781911874673674153);
void car_h_31(double *state, double *unused, double *out_4483517239538288138);
void car_H_31(double *state, double *unused, double *out_8350955492176359526);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}