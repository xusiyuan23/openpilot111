#pragma once
#include "rednose/helpers/ekf.h"
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
void live_H(double *in_vec, double *out_3996265270042170641);
void live_err_fun(double *nom_x, double *delta_x, double *out_3461674683723829337);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7385553611252329077);
void live_H_mod_fun(double *state, double *out_8192941733470122092);
void live_f_fun(double *state, double dt, double *out_3557410023905793232);
void live_F_fun(double *state, double dt, double *out_8557837785947457076);
void live_h_4(double *state, double *unused, double *out_1179371322125232753);
void live_H_4(double *state, double *unused, double *out_7315580968579262055);
void live_h_9(double *state, double *unused, double *out_7267185231670305086);
void live_H_9(double *state, double *unused, double *out_7556770615208852700);
void live_h_10(double *state, double *unused, double *out_5095924145481726408);
void live_H_10(double *state, double *unused, double *out_5645866099687886483);
void live_h_12(double *state, double *unused, double *out_2512392799571043135);
void live_H_12(double *state, double *unused, double *out_6111706697098327766);
void live_h_35(double *state, double *unused, double *out_7549588061413473025);
void live_H_35(double *state, double *unused, double *out_3366143664773314057);
void live_h_32(double *state, double *unused, double *out_1075397825167574537);
void live_H_32(double *state, double *unused, double *out_5548874522593978030);
void live_h_13(double *state, double *unused, double *out_5119914902696682383);
void live_H_13(double *state, double *unused, double *out_8634591391102879904);
void live_h_14(double *state, double *unused, double *out_7267185231670305086);
void live_H_14(double *state, double *unused, double *out_7556770615208852700);
void live_h_33(double *state, double *unused, double *out_834113502876921908);
void live_H_33(double *state, double *unused, double *out_215586660134456453);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}