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
void car_err_fun(double *nom_x, double *delta_x, double *out_6012251674703603378);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2552300699951834906);
void car_H_mod_fun(double *state, double *out_4476663174268174194);
void car_f_fun(double *state, double dt, double *out_2059632134765740243);
void car_F_fun(double *state, double dt, double *out_5892218022728076105);
void car_h_25(double *state, double *unused, double *out_1545506078435773641);
void car_H_25(double *state, double *unused, double *out_6462530086353255637);
void car_h_24(double *state, double *unused, double *out_1712967250978073065);
void car_H_24(double *state, double *unused, double *out_5783181307505134553);
void car_h_30(double *state, double *unused, double *out_1702692746786902786);
void car_H_30(double *state, double *unused, double *out_6591869033496495707);
void car_h_26(double *state, double *unused, double *out_7279276425219937979);
void car_H_26(double *state, double *unused, double *out_8242710668482239755);
void car_h_27(double *state, double *unused, double *out_3456167189225072004);
void car_H_27(double *state, double *unused, double *out_8766632345296920618);
void car_h_29(double *state, double *unused, double *out_7317850665653573656);
void car_H_29(double *state, double *unused, double *out_7966749001543079965);
void car_h_28(double *state, double *unused, double *out_643615085955218621);
void car_H_28(double *state, double *unused, double *out_8516364800601145400);
void car_h_31(double *state, double *unused, double *out_1820700140720279530);
void car_H_31(double *state, double *unused, double *out_6431884124476295209);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}