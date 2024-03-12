#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_4583207975382893756);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9143150462401985555);
void car_H_mod_fun(double *state, double *out_3358041296692552281);
void car_f_fun(double *state, double dt, double *out_8358470198575263086);
void car_F_fun(double *state, double dt, double *out_2436312018501040113);
void car_h_25(double *state, double *unused, double *out_6441266928430861183);
void car_H_25(double *state, double *unused, double *out_1604934088768020918);
void car_h_24(double *state, double *unused, double *out_7412346538782629975);
void car_H_24(double *state, double *unused, double *out_572280334839129055);
void car_h_30(double *state, double *unused, double *out_5234641918928339497);
void car_H_30(double *state, double *unused, double *out_913398869739227709);
void car_h_26(double *state, double *unused, double *out_3561667545337657643);
void car_H_26(double *state, double *unused, double *out_5346437407642077142);
void car_h_27(double *state, double *unused, double *out_1439593660770015538);
void car_H_27(double *state, double *unused, double *out_3136992940923170926);
void car_h_29(double *state, double *unused, double *out_8210428887120366474);
void car_H_29(double *state, double *unused, double *out_1423630214053619893);
void car_h_28(double *state, double *unused, double *out_2383103513671677973);
void car_H_28(double *state, double *unused, double *out_3658768803015910681);
void car_h_31(double *state, double *unused, double *out_9057751154923205472);
void car_H_31(double *state, double *unused, double *out_1574288126891060490);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}