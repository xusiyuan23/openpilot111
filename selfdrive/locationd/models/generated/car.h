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
void car_err_fun(double *nom_x, double *delta_x, double *out_36399703031354541);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1481941880078478546);
void car_H_mod_fun(double *state, double *out_782698275337075542);
void car_f_fun(double *state, double dt, double *out_1178114905851405491);
void car_F_fun(double *state, double dt, double *out_6287201840608329987);
void car_h_25(double *state, double *unused, double *out_6173327891092993483);
void car_H_25(double *state, double *unused, double *out_7500800954454960250);
void car_h_24(double *state, double *unused, double *out_8736520822803851319);
void car_H_24(double *state, double *unused, double *out_3503268526265875046);
void car_h_30(double *state, double *unused, double *out_6448521953377499372);
void car_H_30(double *state, double *unused, double *out_7630139901598200320);
void car_h_26(double *state, double *unused, double *out_346002517644304982);
void car_H_26(double *state, double *unused, double *out_7204439800380535142);
void car_h_27(double *state, double *unused, double *out_7271742914955712488);
void car_H_27(double *state, double *unused, double *out_8641840860310926385);
void car_h_29(double *state, double *unused, double *out_3411735901933166687);
void car_H_29(double *state, double *unused, double *out_6928478133441375352);
void car_h_28(double *state, double *unused, double *out_1446094004912979838);
void car_H_28(double *state, double *unused, double *out_1846079116371844778);
void car_h_31(double *state, double *unused, double *out_7623959283721876650);
void car_H_31(double *state, double *unused, double *out_7470154992577999822);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}