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
void car_err_fun(double *nom_x, double *delta_x, double *out_3511157536608921668);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6431969432730020252);
void car_H_mod_fun(double *state, double *out_7948008639250905645);
void car_f_fun(double *state, double dt, double *out_2086994761209225774);
void car_F_fun(double *state, double dt, double *out_8139310027990993197);
void car_h_25(double *state, double *unused, double *out_4906131110836938043);
void car_H_25(double *state, double *unused, double *out_8920612812001856359);
void car_h_24(double *state, double *unused, double *out_3427550057756876624);
void car_H_24(double *state, double *unused, double *out_5543808110309927359);
void car_h_30(double *state, double *unused, double *out_5063317779188067188);
void car_H_30(double *state, double *unused, double *out_2003922470510239604);
void car_h_26(double *state, double *unused, double *out_8958065379223252895);
void car_H_26(double *state, double *unused, double *out_5784627942833639033);
void car_h_27(double *state, double *unused, double *out_7942917162281270728);
void car_H_27(double *state, double *unused, double *out_4178685782310664515);
void car_h_29(double *state, double *unused, double *out_3732991685077929952);
void car_H_29(double *state, double *unused, double *out_1493691126195847420);
void car_h_28(double *state, double *unused, double *out_2300187291200313893);
void car_H_28(double *state, double *unused, double *out_6576090143265377994);
void car_h_31(double *state, double *unused, double *out_5181325173121443932);
void car_H_31(double *state, double *unused, double *out_8889966850124895931);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}