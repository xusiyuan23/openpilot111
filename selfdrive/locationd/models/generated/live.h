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
void live_H(double *in_vec, double *out_3981994659674141472);
void live_err_fun(double *nom_x, double *delta_x, double *out_3356596097038928074);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4391465575185495497);
void live_H_mod_fun(double *state, double *out_4990766548554672415);
void live_f_fun(double *state, double dt, double *out_3056772812413117361);
void live_F_fun(double *state, double dt, double *out_3001170024940786206);
void live_h_4(double *state, double *unused, double *out_4623444193655221191);
void live_H_4(double *state, double *unused, double *out_2603623762087390332);
void live_h_9(double *state, double *unused, double *out_4168973980757166041);
void live_H_9(double *state, double *unused, double *out_2362434115457799687);
void live_h_10(double *state, double *unused, double *out_3520412221597307166);
void live_H_10(double *state, double *unused, double *out_7396015770213526348);
void live_h_12(double *state, double *unused, double *out_7977792700499542139);
void live_H_12(double *state, double *unused, double *out_2415832645944571463);
void live_h_35(double *state, double *unused, double *out_3752355986187417342);
void live_H_35(double *state, double *unused, double *out_763038295285217044);
void live_h_32(double *state, double *unused, double *out_2897039262415537399);
void live_H_32(double *state, double *unused, double *out_6564342667492829602);
void live_h_13(double *state, double *unused, double *out_7535737061045930452);
void live_H_13(double *state, double *unused, double *out_3042894167287587122);
void live_h_14(double *state, double *unused, double *out_4168973980757166041);
void live_H_14(double *state, double *unused, double *out_2362434115457799687);
void live_h_33(double *state, double *unused, double *out_3687821174760154582);
void live_H_33(double *state, double *unused, double *out_3913595299924074648);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}