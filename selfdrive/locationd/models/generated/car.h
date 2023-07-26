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
void car_err_fun(double *nom_x, double *delta_x, double *out_3028736888961783120);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3218082572571671239);
void car_H_mod_fun(double *state, double *out_1114876351103919435);
void car_f_fun(double *state, double dt, double *out_6826993337149264426);
void car_F_fun(double *state, double dt, double *out_5391441206083204607);
void car_h_25(double *state, double *unused, double *out_3881631893549789208);
void car_H_25(double *state, double *unused, double *out_7267345600465790480);
void car_h_24(double *state, double *unused, double *out_700870389243627536);
void car_H_24(double *state, double *unused, double *out_5094696001460290914);
void car_h_30(double *state, double *unused, double *out_6829357883905274169);
void car_H_30(double *state, double *unused, double *out_4262708131752144381);
void car_h_26(double *state, double *unused, double *out_1827684616244428524);
void car_H_26(double *state, double *unused, double *out_3525842281591734256);
void car_h_27(double *state, double *unused, double *out_6761232746364086773);
void car_H_27(double *state, double *unused, double *out_6437471443552569292);
void car_h_29(double *state, double *unused, double *out_6615712922143431802);
void car_H_29(double *state, double *unused, double *out_8150834170422120325);
void car_h_28(double *state, double *unused, double *out_1759559478703241128);
void car_H_28(double *state, double *unused, double *out_5213510886217900717);
void car_h_31(double *state, double *unused, double *out_3999640757204259977);
void car_H_31(double *state, double *unused, double *out_7297991562342750908);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}