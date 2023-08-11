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
void car_err_fun(double *nom_x, double *delta_x, double *out_8412408275907562510);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5009429012443487067);
void car_H_mod_fun(double *state, double *out_7201068384612818103);
void car_f_fun(double *state, double dt, double *out_2117395969407442559);
void car_F_fun(double *state, double dt, double *out_1930106235119052766);
void car_h_25(double *state, double *unused, double *out_4962192466318968957);
void car_H_25(double *state, double *unused, double *out_279667768067758393);
void car_h_24(double *state, double *unused, double *out_8672504443832107776);
void car_H_24(double *state, double *unused, double *out_1897546655539391580);
void car_h_30(double *state, double *unused, double *out_4360774308705605403);
void car_H_30(double *state, double *unused, double *out_2238665190439490234);
void car_h_26(double *state, double *unused, double *out_640898958955240242);
void car_H_26(double *state, double *unused, double *out_4021171086941814617);
void car_h_27(double *state, double *unused, double *out_3142070393519437079);
void car_H_27(double *state, double *unused, double *out_4462259261623433451);
void car_h_29(double *state, double *unused, double *out_4621194863301235362);
void car_H_29(double *state, double *unused, double *out_2748896534753882418);
void car_h_28(double *state, double *unused, double *out_7655328506878780195);
void car_H_28(double *state, double *unused, double *out_2333502482315648156);
void car_h_31(double *state, double *unused, double *out_5721286350569910218);
void car_H_31(double *state, double *unused, double *out_249021806190797965);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}