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
void car_err_fun(double *nom_x, double *delta_x, double *out_6221041922176669826);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3875401196843302167);
void car_H_mod_fun(double *state, double *out_9089536759471748437);
void car_f_fun(double *state, double dt, double *out_3779678567620275028);
void car_F_fun(double *state, double dt, double *out_1785761162142041567);
void car_h_25(double *state, double *unused, double *out_4996244158397258433);
void car_H_25(double *state, double *unused, double *out_5210786231112538818);
void car_h_24(double *state, double *unused, double *out_1972001985963987938);
void car_H_24(double *state, double *unused, double *out_6660386036005494697);
void car_h_30(double *state, double *unused, double *out_4721050096112752544);
void car_H_30(double *state, double *unused, double *out_6319267501105396043);
void car_h_26(double *state, double *unused, double *out_4705150565156322630);
void car_H_26(double *state, double *unused, double *out_1469282912238482594);
void car_h_27(double *state, double *unused, double *out_5429109263587212);
void car_H_27(double *state, double *unused, double *out_8494030812905820954);
void car_h_29(double *state, double *unused, double *out_280623171548093101);
void car_H_29(double *state, double *unused, double *out_5809036156791003859);
void car_h_28(double *state, double *unused, double *out_1485357213837934172);
void car_H_28(double *state, double *unused, double *out_3156951516864649055);
void car_h_31(double *state, double *unused, double *out_897940860117886569);
void car_H_31(double *state, double *unused, double *out_5241432192989499246);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}