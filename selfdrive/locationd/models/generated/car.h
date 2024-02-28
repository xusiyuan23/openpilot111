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
void car_err_fun(double *nom_x, double *delta_x, double *out_8989390406176655642);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_872949834645227037);
void car_H_mod_fun(double *state, double *out_6190064514277074980);
void car_f_fun(double *state, double dt, double *out_5737342647877877229);
void car_F_fun(double *state, double dt, double *out_6498734987852944578);
void car_h_25(double *state, double *unused, double *out_358371148521877751);
void car_H_25(double *state, double *unused, double *out_3752758241963538269);
void car_h_24(double *state, double *unused, double *out_4557978488111553664);
void car_H_24(double *state, double *unused, double *out_993751085002970765);
void car_h_30(double *state, double *unused, double *out_7522901502232171434);
void car_H_30(double *state, double *unused, double *out_6271091200470786896);
void car_h_26(double *state, double *unused, double *out_2521228234571325789);
void car_H_26(double *state, double *unused, double *out_7057284211724338870);
void car_h_27(double *state, double *unused, double *out_1301881001423540186);
void car_H_27(double *state, double *unused, double *out_8494685271654730113);
void car_h_29(double *state, double *unused, double *out_2895729189507225245);
void car_H_29(double *state, double *unused, double *out_6781322544785179080);
void car_h_28(double *state, double *unused, double *out_9068663034437199427);
void car_H_28(double *state, double *unused, double *out_1698923527715648506);
void car_h_31(double *state, double *unused, double *out_3995820676775900101);
void car_H_31(double *state, double *unused, double *out_6431076109490987394);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}