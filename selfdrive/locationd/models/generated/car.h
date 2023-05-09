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
void car_err_fun(double *nom_x, double *delta_x, double *out_5384428575304141493);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4549184669954132702);
void car_H_mod_fun(double *state, double *out_1711160830974719761);
void car_f_fun(double *state, double dt, double *out_4246157559450135369);
void car_F_fun(double *state, double dt, double *out_226785303060119004);
void car_h_25(double *state, double *unused, double *out_9112045252708408632);
void car_H_25(double *state, double *unused, double *out_4780486682676063011);
void car_h_24(double *state, double *unused, double *out_5255225383959719707);
void car_H_24(double *state, double *unused, double *out_5177131987029922506);
void car_h_30(double *state, double *unused, double *out_6164319262352923671);
void car_H_30(double *state, double *unused, double *out_2262153724168814384);
void car_h_26(double *state, double *unused, double *out_3127533210908590986);
void car_H_26(double *state, double *unused, double *out_8521990001550119235);
void car_h_27(double *state, double *unused, double *out_1083931870738253695);
void car_H_27(double *state, double *unused, double *out_38559652984871167);
void car_h_29(double *state, double *unused, double *out_1162645994692078026);
void car_H_29(double *state, double *unused, double *out_1751922379854422200);
void car_h_28(double *state, double *unused, double *out_6046311868419546927);
void car_H_28(double *state, double *unused, double *out_6834321396923952774);
void car_h_31(double *state, double *unused, double *out_2341210026358057696);
void car_H_31(double *state, double *unused, double *out_4749840720799102583);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}