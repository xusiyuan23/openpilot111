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
void live_H(double *in_vec, double *out_4115360115617180917);
void live_err_fun(double *nom_x, double *delta_x, double *out_5028549102333271222);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3646282937470409636);
void live_H_mod_fun(double *state, double *out_7127514700151125808);
void live_f_fun(double *state, double dt, double *out_3531017197459290528);
void live_F_fun(double *state, double dt, double *out_5997997079382275200);
void live_h_4(double *state, double *unused, double *out_6904501674011099908);
void live_H_4(double *state, double *unused, double *out_5118231804045452936);
void live_h_9(double *state, double *unused, double *out_4418067749625567351);
void live_H_9(double *state, double *unused, double *out_5359421450675043581);
void live_h_10(double *state, double *unused, double *out_4758123137462151767);
void live_H_10(double *state, double *unused, double *out_4946595789551345802);
void live_h_12(double *state, double *unused, double *out_4503841594187230457);
void live_H_12(double *state, double *unused, double *out_8309055861632136885);
void live_h_35(double *state, double *unused, double *out_4180789303881171216);
void live_H_35(double *state, double *unused, double *out_5563492829307123176);
void live_h_32(double *state, double *unused, double *out_136984558303756229);
void live_H_32(double *state, double *unused, double *out_1570029357723943956);
void live_h_13(double *state, double *unused, double *out_8534437771530735397);
void live_H_13(double *state, double *unused, double *out_485470292711997410);
void live_h_14(double *state, double *unused, double *out_4418067749625567351);
void live_H_14(double *state, double *unused, double *out_5359421450675043581);
void live_h_33(double *state, double *unused, double *out_2950569226751515122);
void live_H_33(double *state, double *unused, double *out_6811293207652633700);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}