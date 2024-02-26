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
void car_err_fun(double *nom_x, double *delta_x, double *out_1964954299455970933);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6003963640381126063);
void car_H_mod_fun(double *state, double *out_1207008555950061675);
void car_f_fun(double *state, double dt, double *out_2803172193991338453);
void car_F_fun(double *state, double dt, double *out_4664417582021608014);
void car_h_25(double *state, double *unused, double *out_8570962910733009665);
void car_H_25(double *state, double *unused, double *out_1998904563998531603);
void car_h_24(double *state, double *unused, double *out_2751191583816658395);
void car_H_24(double *state, double *unused, double *out_6775987843813639291);
void car_h_30(double *state, double *unused, double *out_4933513382478987315);
void car_H_30(double *state, double *unused, double *out_1869565616855291533);
void car_h_26(double *state, double *unused, double *out_2501630051949713498);
void car_H_26(double *state, double *unused, double *out_1742598754875524621);
void car_h_27(double *state, double *unused, double *out_8932271310074879516);
void car_H_27(double *state, double *unused, double *out_305197694945133378);
void car_h_29(double *state, double *unused, double *out_5877023235380649750);
void car_H_29(double *state, double *unused, double *out_2379796961169683717);
void car_h_28(double *state, double *unused, double *out_5895485258630546831);
void car_H_28(double *state, double *unused, double *out_4343427232735009968);
void car_h_31(double *state, double *unused, double *out_5381229435042917038);
void car_H_31(double *state, double *unused, double *out_2029550525875492031);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}