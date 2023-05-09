#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_638760506292347052);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1357695715425304307);
void gnss_H_mod_fun(double *state, double *out_8293051259792062881);
void gnss_f_fun(double *state, double dt, double *out_3680399526685225726);
void gnss_F_fun(double *state, double dt, double *out_3518510924285127846);
void gnss_h_6(double *state, double *sat_pos, double *out_6626517376083254528);
void gnss_H_6(double *state, double *sat_pos, double *out_7012552859857848193);
void gnss_h_20(double *state, double *sat_pos, double *out_1916374596602260347);
void gnss_H_20(double *state, double *sat_pos, double *out_8575710610156363526);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8599846894541753100);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_562112177466942736);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8599846894541753100);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_562112177466942736);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}