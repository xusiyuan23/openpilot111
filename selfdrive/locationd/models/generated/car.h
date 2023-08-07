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
void car_err_fun(double *nom_x, double *delta_x, double *out_4904502417690011868);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2523710226769313624);
void car_H_mod_fun(double *state, double *out_2102495077234161738);
void car_f_fun(double *state, double dt, double *out_2902792789409424078);
void car_F_fun(double *state, double dt, double *out_7384697533201998408);
void car_h_25(double *state, double *unused, double *out_6076734193594010054);
void car_H_25(double *state, double *unused, double *out_8386229354659032627);
void car_h_24(double *state, double *unused, double *out_3849361237634050377);
void car_H_24(double *state, double *unused, double *out_6058802640420010356);
void car_h_30(double *state, double *unused, double *out_1686531063226662387);
void car_H_30(double *state, double *unused, double *out_3143824377558902234);
void car_h_26(double *state, double *unused, double *out_1350254988217670298);
void car_H_26(double *state, double *unused, double *out_4644726035784976403);
void car_h_27(double *state, double *unused, double *out_4717106662584640226);
void car_H_27(double *state, double *unused, double *out_5318587689359327145);
void car_h_29(double *state, double *unused, double *out_3506653136026194265);
void car_H_29(double *state, double *unused, double *out_2633593033244510050);
void car_h_28(double *state, double *unused, double *out_2096438289248014934);
void car_H_28(double *state, double *unused, double *out_7715992050314040624);
void car_h_31(double *state, double *unused, double *out_3232292595431690380);
void car_H_31(double *state, double *unused, double *out_8416875316535993055);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}