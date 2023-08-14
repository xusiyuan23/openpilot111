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
void car_err_fun(double *nom_x, double *delta_x, double *out_1282327502940326821);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4590721196226970281);
void car_H_mod_fun(double *state, double *out_2163953626510216661);
void car_f_fun(double *state, double dt, double *out_405606070335708994);
void car_F_fun(double *state, double dt, double *out_7303340041697938188);
void car_h_25(double *state, double *unused, double *out_5588110016210508170);
void car_H_25(double *state, double *unused, double *out_6037113083971364302);
void car_h_24(double *state, double *unused, double *out_4380624216713203670);
void car_H_24(double *state, double *unused, double *out_8209762682976863868);
void car_h_30(double *state, double *unused, double *out_4965694562614520087);
void car_H_30(double *state, double *unused, double *out_879577257520252453);
void car_h_26(double *state, double *unused, double *out_4499080339088190764);
void car_H_26(double *state, double *unused, double *out_8668127670864131090);
void car_h_27(double *state, double *unused, double *out_586436748549662525);
void car_H_27(double *state, double *unused, double *out_1295186054280172458);
void car_h_29(double *state, double *unused, double *out_5569010447290997604);
void car_H_29(double *state, double *unused, double *out_3008548781149723491);
void car_h_28(double *state, double *unused, double *out_2689411064197794064);
void car_H_28(double *state, double *unused, double *out_8090947798219254065);
void car_h_31(double *state, double *unused, double *out_5863304078495014059);
void car_H_31(double *state, double *unused, double *out_6006467122094403874);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}