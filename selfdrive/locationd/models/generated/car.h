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
void car_err_fun(double *nom_x, double *delta_x, double *out_1928513491143626106);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5316378672319491408);
void car_H_mod_fun(double *state, double *out_81331222009082685);
void car_f_fun(double *state, double dt, double *out_7697253348860842728);
void car_F_fun(double *state, double dt, double *out_6648150650683530522);
void car_h_25(double *state, double *unused, double *out_689257566577270559);
void car_H_25(double *state, double *unused, double *out_5255463841783268914);
void car_h_24(double *state, double *unused, double *out_5847624080141109321);
void car_H_24(double *state, double *unused, double *out_3519428566028901980);
void car_h_30(double *state, double *unused, double *out_2139888959206153726);
void car_H_30(double *state, double *unused, double *out_5126124894640028844);
void car_h_26(double *state, double *unused, double *out_6842080212800687039);
void car_H_26(double *state, double *unused, double *out_1513960522909212690);
void car_h_27(double *state, double *unused, double *out_85941681900793042);
void car_H_27(double *state, double *unused, double *out_2951361582839603933);
void car_h_29(double *state, double *unused, double *out_2861784308454691919);
void car_H_29(double *state, double *unused, double *out_1237998855970052900);
void car_h_28(double *state, double *unused, double *out_7588263513831031675);
void car_H_28(double *state, double *unused, double *out_3201629127535379151);
void car_h_31(double *state, double *unused, double *out_5362809011846144576);
void car_H_31(double *state, double *unused, double *out_5286109803660229342);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}