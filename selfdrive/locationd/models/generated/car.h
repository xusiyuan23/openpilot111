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
void car_err_fun(double *nom_x, double *delta_x, double *out_5337520902682181745);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8828680484256532384);
void car_H_mod_fun(double *state, double *out_5754598514978375131);
void car_f_fun(double *state, double dt, double *out_1092486187386673674);
void car_F_fun(double *state, double dt, double *out_7989567927593446774);
void car_h_25(double *state, double *unused, double *out_1411798654681004528);
void car_H_25(double *state, double *unused, double *out_7474154507154927049);
void car_h_24(double *state, double *unused, double *out_7765735534137007266);
void car_H_24(double *state, double *unused, double *out_9161970943024031240);
void car_h_30(double *state, double *unused, double *out_1136604592396498639);
void car_H_30(double *state, double *unused, double *out_8454256608047375940);
void car_h_26(double *state, double *unused, double *out_5262436925017350507);
void car_H_26(double *state, double *unused, double *out_3732651188280870825);
void car_h_27(double *state, double *unused, double *out_2355308507582666963);
void car_H_27(double *state, double *unused, double *out_7817724153861750765);
void car_h_29(double *state, double *unused, double *out_4173390643840831324);
void car_H_29(double *state, double *unused, double *out_7944025263732983756);
void car_h_28(double *state, double *unused, double *out_2646364760078178682);
void car_H_28(double *state, double *unused, double *out_5420319792907037286);
void car_h_31(double *state, double *unused, double *out_7228078822037537356);
void car_H_31(double *state, double *unused, double *out_3106443086047519349);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}