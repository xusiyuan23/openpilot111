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
void live_H(double *in_vec, double *out_2427080946257414198);
void live_err_fun(double *nom_x, double *delta_x, double *out_4499017012837728402);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4568239191987130813);
void live_H_mod_fun(double *state, double *out_7466442051496209266);
void live_f_fun(double *state, double dt, double *out_7616316395018437217);
void live_F_fun(double *state, double dt, double *out_3738746660903124007);
void live_h_4(double *state, double *unused, double *out_5102933337023237333);
void live_H_4(double *state, double *unused, double *out_7235994504100796541);
void live_h_9(double *state, double *unused, double *out_6101034663185489335);
void live_H_9(double *state, double *unused, double *out_51224431163650929);
void live_h_10(double *state, double *unused, double *out_1900712798164773370);
void live_H_10(double *state, double *unused, double *out_4820155672142958661);
void live_h_12(double *state, double *unused, double *out_8879026316650247416);
void live_H_12(double *state, double *unused, double *out_6614895479053202874);
void live_h_35(double *state, double *unused, double *out_1924620734251358832);
void live_H_35(double *state, double *unused, double *out_3869332446728189165);
void live_h_32(double *state, double *unused, double *out_1566775458117550308);
void live_H_32(double *state, double *unused, double *out_8625923032509862606);
void live_h_13(double *state, double *unused, double *out_5786152235345498787);
void live_H_13(double *state, double *unused, double *out_1965575430518687731);
void live_h_14(double *state, double *unused, double *out_6101034663185489335);
void live_H_14(double *state, double *unused, double *out_51224431163650929);
void live_h_33(double *state, double *unused, double *out_1672775015514148260);
void live_H_33(double *state, double *unused, double *out_718775442089331561);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}