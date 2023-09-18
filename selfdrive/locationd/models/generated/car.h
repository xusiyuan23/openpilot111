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
void car_err_fun(double *nom_x, double *delta_x, double *out_671583855790742447);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5648898715511339411);
void car_H_mod_fun(double *state, double *out_1463661415422686295);
void car_f_fun(double *state, double dt, double *out_4065214630836186202);
void car_F_fun(double *state, double dt, double *out_8116097140535481129);
void car_h_25(double *state, double *unused, double *out_4769400438462954391);
void car_H_25(double *state, double *unused, double *out_4920414855801952303);
void car_h_24(double *state, double *unused, double *out_5467276253789859636);
void car_H_24(double *state, double *unused, double *out_1655156950789565798);
void car_h_30(double *state, double *unused, double *out_8362735586557612018);
void car_H_30(double *state, double *unused, double *out_2402081897294703676);
void car_h_26(double *state, double *unused, double *out_4441278616070982763);
void car_H_26(double *state, double *unused, double *out_8661918174676008527);
void car_h_27(double *state, double *unused, double *out_4099496445352121952);
void car_H_27(double *state, double *unused, double *out_178487826110760459);
void car_h_29(double *state, double *unused, double *out_3361062318896766373);
void car_H_29(double *state, double *unused, double *out_1891850552980311492);
void car_h_28(double *state, double *unused, double *out_2514929989030348327);
void car_H_28(double *state, double *unused, double *out_6974249570049842066);
void car_h_31(double *state, double *unused, double *out_141268967578377915);
void car_H_31(double *state, double *unused, double *out_4889768893924991875);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}