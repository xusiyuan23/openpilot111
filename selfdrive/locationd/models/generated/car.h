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
void car_err_fun(double *nom_x, double *delta_x, double *out_8398572426417880298);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8550243317389602002);
void car_H_mod_fun(double *state, double *out_2446351589466899685);
void car_f_fun(double *state, double dt, double *out_3483379115055167654);
void car_F_fun(double *state, double dt, double *out_1479224434010073741);
void car_h_25(double *state, double *unused, double *out_7644021312554520659);
void car_H_25(double *state, double *unused, double *out_2503344116145806535);
void car_h_24(double *state, double *unused, double *out_8913457371165772029);
void car_H_24(double *state, double *unused, double *out_1054581482656516601);
void car_h_30(double *state, double *unused, double *out_5825939176296356298);
void car_H_30(double *state, double *unused, double *out_2632683063289046605);
void car_h_26(double *state, double *unused, double *out_4544604859564383315);
void car_H_26(double *state, double *unused, double *out_6244847435019862759);
void car_h_27(double *state, double *unused, double *out_6284393781545150831);
void car_H_27(double *state, double *unused, double *out_4807446375089471516);
void car_h_29(double *state, double *unused, double *out_4882429323394693863);
void car_H_29(double *state, double *unused, double *out_2122451718974654421);
void car_h_28(double *state, double *unused, double *out_2002829940301490323);
void car_H_28(double *state, double *unused, double *out_4557178830393696298);
void car_h_31(double *state, double *unused, double *out_237251338199528526);
void car_H_31(double *state, double *unused, double *out_2472698154268846107);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}