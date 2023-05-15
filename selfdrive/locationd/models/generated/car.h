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
void car_err_fun(double *nom_x, double *delta_x, double *out_2352872656412802824);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7914023550455204906);
void car_H_mod_fun(double *state, double *out_6232055486637493083);
void car_f_fun(double *state, double dt, double *out_7443095893193800780);
void car_F_fun(double *state, double dt, double *out_2098139970056789871);
void car_h_25(double *state, double *unused, double *out_8602721369322250957);
void car_H_25(double *state, double *unused, double *out_8912817928593951573);
void car_h_24(double *state, double *unused, double *out_3580444101429411878);
void car_H_24(double *state, double *unused, double *out_5354892329791628437);
void car_h_30(double *state, double *unused, double *out_3073187478036949723);
void car_H_30(double *state, double *unused, double *out_6394484970086702946);
void car_h_26(double *state, double *unused, double *out_4240931279113091460);
void car_H_26(double *state, double *unused, double *out_5792422826241543819);
void car_h_27(double *state, double *unused, double *out_3601048101661405312);
void car_H_27(double *state, double *unused, double *out_7229823886171935062);
void car_h_29(double *state, double *unused, double *out_260635374767096340);
void car_H_29(double *state, double *unused, double *out_5516461159302384029);
void car_h_28(double *state, double *unused, double *out_5291495936397086272);
void car_H_28(double *state, double *unused, double *out_7480091430867710280);
void car_h_31(double *state, double *unused, double *out_7755811163072584423);
void car_H_31(double *state, double *unused, double *out_5166214724008192343);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}