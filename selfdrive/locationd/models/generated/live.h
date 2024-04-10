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
void live_H(double *in_vec, double *out_2514925971324519153);
void live_err_fun(double *nom_x, double *delta_x, double *out_8069791558270424482);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_429301602353769159);
void live_H_mod_fun(double *state, double *out_1386605300632116763);
void live_f_fun(double *state, double dt, double *out_858533111488398624);
void live_F_fun(double *state, double dt, double *out_1333631458729715779);
void live_h_4(double *state, double *unused, double *out_4226654547665910661);
void live_H_4(double *state, double *unused, double *out_803496816155160547);
void live_h_9(double *state, double *unused, double *out_1637398521647854197);
void live_H_9(double *state, double *unused, double *out_1044686462784751192);
void live_h_10(double *state, double *unused, double *out_2911177701660318769);
void live_H_10(double *state, double *unused, double *out_8738977984252755693);
void live_h_12(double *state, double *unused, double *out_8509321518908937806);
void live_H_12(double *state, double *unused, double *out_1424595841202754214);
void live_h_35(double *state, double *unused, double *out_2717107203032309566);
void live_H_35(double *state, double *unused, double *out_4170158873527767923);
void live_h_32(double *state, double *unused, double *out_5509610638763499116);
void live_H_32(double *state, double *unused, double *out_3857537178640322895);
void live_h_13(double *state, double *unused, double *out_5565586117472497019);
void live_H_13(double *state, double *unused, double *out_6962032018273124346);
void live_h_14(double *state, double *unused, double *out_1637398521647854197);
void live_H_14(double *state, double *unused, double *out_1044686462784751192);
void live_h_33(double *state, double *unused, double *out_6039189548824972318);
void live_H_33(double *state, double *unused, double *out_7320715878166625527);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}