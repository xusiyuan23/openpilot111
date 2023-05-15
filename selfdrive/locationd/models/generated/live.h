#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_263842806597291);
void live_err_fun(double *nom_x, double *delta_x, double *out_8569159409576762549);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_284279922701101553);
void live_H_mod_fun(double *state, double *out_8714581148882225607);
void live_f_fun(double *state, double dt, double *out_1713867968062410626);
void live_F_fun(double *state, double dt, double *out_8009710216144762132);
void live_h_4(double *state, double *unused, double *out_5932591475428494127);
void live_H_4(double *state, double *unused, double *out_2730109072736447982);
void live_h_9(double *state, double *unused, double *out_5854075401467761119);
void live_H_9(double *state, double *unused, double *out_2488919426106857337);
void live_h_10(double *state, double *unused, double *out_1420303220039557508);
void live_H_10(double *state, double *unused, double *out_1532345507062168959);
void live_h_12(double *state, double *unused, double *out_95484120703134841);
void live_H_12(double *state, double *unused, double *out_2289347335295513813);
void live_h_35(double *state, double *unused, double *out_6264768899209819592);
void live_H_35(double *state, double *unused, double *out_636552984636159394);
void live_h_32(double *state, double *unused, double *out_2061377894861506384);
void live_H_32(double *state, double *unused, double *out_3582146253035749676);
void live_h_13(double *state, double *unused, double *out_65595433475112262);
void live_H_13(double *state, double *unused, double *out_5494855882448693637);
void live_h_14(double *state, double *unused, double *out_5854075401467761119);
void live_H_14(double *state, double *unused, double *out_2488919426106857337);
void live_h_33(double *state, double *unused, double *out_3796847141673179462);
void live_H_33(double *state, double *unused, double *out_3787109989275016998);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}