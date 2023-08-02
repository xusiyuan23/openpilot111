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
void car_err_fun(double *nom_x, double *delta_x, double *out_6418008894828543880);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1941682345751704468);
void car_H_mod_fun(double *state, double *out_2092090189261374191);
void car_f_fun(double *state, double dt, double *out_2276750736619583802);
void car_F_fun(double *state, double dt, double *out_1624010529949937280);
void car_h_25(double *state, double *unused, double *out_3118536560980860465);
void car_H_25(double *state, double *unused, double *out_4788925088057501687);
void car_h_24(double *state, double *unused, double *out_5980892570550494700);
void car_H_24(double *state, double *unused, double *out_1786646718534016414);
void car_h_30(double *state, double *unused, double *out_4569167953609743632);
void car_H_30(double *state, double *unused, double *out_2127765253434115068);
void car_h_26(double *state, double *unused, double *out_2433594750183322147);
void car_H_26(double *state, double *unused, double *out_8530428406931557911);
void car_h_27(double *state, double *unused, double *out_6155322612425193150);
void car_H_27(double *state, double *unused, double *out_46998058366309843);
void car_h_29(double *state, double *unused, double *out_432505314051102013);
void car_H_29(double *state, double *unused, double *out_1760360785235860876);
void car_h_28(double *state, double *unused, double *out_6949554225398327903);
void car_H_28(double *state, double *unused, double *out_6842759802305391450);
void car_h_31(double *state, double *unused, double *out_3393730623265366354);
void car_H_31(double *state, double *unused, double *out_4758279126180541259);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}