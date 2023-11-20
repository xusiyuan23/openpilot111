#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1298370022994424896) {
   out_1298370022994424896[0] = delta_x[0] + nom_x[0];
   out_1298370022994424896[1] = delta_x[1] + nom_x[1];
   out_1298370022994424896[2] = delta_x[2] + nom_x[2];
   out_1298370022994424896[3] = delta_x[3] + nom_x[3];
   out_1298370022994424896[4] = delta_x[4] + nom_x[4];
   out_1298370022994424896[5] = delta_x[5] + nom_x[5];
   out_1298370022994424896[6] = delta_x[6] + nom_x[6];
   out_1298370022994424896[7] = delta_x[7] + nom_x[7];
   out_1298370022994424896[8] = delta_x[8] + nom_x[8];
   out_1298370022994424896[9] = delta_x[9] + nom_x[9];
   out_1298370022994424896[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1216411467074742856) {
   out_1216411467074742856[0] = -nom_x[0] + true_x[0];
   out_1216411467074742856[1] = -nom_x[1] + true_x[1];
   out_1216411467074742856[2] = -nom_x[2] + true_x[2];
   out_1216411467074742856[3] = -nom_x[3] + true_x[3];
   out_1216411467074742856[4] = -nom_x[4] + true_x[4];
   out_1216411467074742856[5] = -nom_x[5] + true_x[5];
   out_1216411467074742856[6] = -nom_x[6] + true_x[6];
   out_1216411467074742856[7] = -nom_x[7] + true_x[7];
   out_1216411467074742856[8] = -nom_x[8] + true_x[8];
   out_1216411467074742856[9] = -nom_x[9] + true_x[9];
   out_1216411467074742856[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_5581863977132795483) {
   out_5581863977132795483[0] = 1.0;
   out_5581863977132795483[1] = 0;
   out_5581863977132795483[2] = 0;
   out_5581863977132795483[3] = 0;
   out_5581863977132795483[4] = 0;
   out_5581863977132795483[5] = 0;
   out_5581863977132795483[6] = 0;
   out_5581863977132795483[7] = 0;
   out_5581863977132795483[8] = 0;
   out_5581863977132795483[9] = 0;
   out_5581863977132795483[10] = 0;
   out_5581863977132795483[11] = 0;
   out_5581863977132795483[12] = 1.0;
   out_5581863977132795483[13] = 0;
   out_5581863977132795483[14] = 0;
   out_5581863977132795483[15] = 0;
   out_5581863977132795483[16] = 0;
   out_5581863977132795483[17] = 0;
   out_5581863977132795483[18] = 0;
   out_5581863977132795483[19] = 0;
   out_5581863977132795483[20] = 0;
   out_5581863977132795483[21] = 0;
   out_5581863977132795483[22] = 0;
   out_5581863977132795483[23] = 0;
   out_5581863977132795483[24] = 1.0;
   out_5581863977132795483[25] = 0;
   out_5581863977132795483[26] = 0;
   out_5581863977132795483[27] = 0;
   out_5581863977132795483[28] = 0;
   out_5581863977132795483[29] = 0;
   out_5581863977132795483[30] = 0;
   out_5581863977132795483[31] = 0;
   out_5581863977132795483[32] = 0;
   out_5581863977132795483[33] = 0;
   out_5581863977132795483[34] = 0;
   out_5581863977132795483[35] = 0;
   out_5581863977132795483[36] = 1.0;
   out_5581863977132795483[37] = 0;
   out_5581863977132795483[38] = 0;
   out_5581863977132795483[39] = 0;
   out_5581863977132795483[40] = 0;
   out_5581863977132795483[41] = 0;
   out_5581863977132795483[42] = 0;
   out_5581863977132795483[43] = 0;
   out_5581863977132795483[44] = 0;
   out_5581863977132795483[45] = 0;
   out_5581863977132795483[46] = 0;
   out_5581863977132795483[47] = 0;
   out_5581863977132795483[48] = 1.0;
   out_5581863977132795483[49] = 0;
   out_5581863977132795483[50] = 0;
   out_5581863977132795483[51] = 0;
   out_5581863977132795483[52] = 0;
   out_5581863977132795483[53] = 0;
   out_5581863977132795483[54] = 0;
   out_5581863977132795483[55] = 0;
   out_5581863977132795483[56] = 0;
   out_5581863977132795483[57] = 0;
   out_5581863977132795483[58] = 0;
   out_5581863977132795483[59] = 0;
   out_5581863977132795483[60] = 1.0;
   out_5581863977132795483[61] = 0;
   out_5581863977132795483[62] = 0;
   out_5581863977132795483[63] = 0;
   out_5581863977132795483[64] = 0;
   out_5581863977132795483[65] = 0;
   out_5581863977132795483[66] = 0;
   out_5581863977132795483[67] = 0;
   out_5581863977132795483[68] = 0;
   out_5581863977132795483[69] = 0;
   out_5581863977132795483[70] = 0;
   out_5581863977132795483[71] = 0;
   out_5581863977132795483[72] = 1.0;
   out_5581863977132795483[73] = 0;
   out_5581863977132795483[74] = 0;
   out_5581863977132795483[75] = 0;
   out_5581863977132795483[76] = 0;
   out_5581863977132795483[77] = 0;
   out_5581863977132795483[78] = 0;
   out_5581863977132795483[79] = 0;
   out_5581863977132795483[80] = 0;
   out_5581863977132795483[81] = 0;
   out_5581863977132795483[82] = 0;
   out_5581863977132795483[83] = 0;
   out_5581863977132795483[84] = 1.0;
   out_5581863977132795483[85] = 0;
   out_5581863977132795483[86] = 0;
   out_5581863977132795483[87] = 0;
   out_5581863977132795483[88] = 0;
   out_5581863977132795483[89] = 0;
   out_5581863977132795483[90] = 0;
   out_5581863977132795483[91] = 0;
   out_5581863977132795483[92] = 0;
   out_5581863977132795483[93] = 0;
   out_5581863977132795483[94] = 0;
   out_5581863977132795483[95] = 0;
   out_5581863977132795483[96] = 1.0;
   out_5581863977132795483[97] = 0;
   out_5581863977132795483[98] = 0;
   out_5581863977132795483[99] = 0;
   out_5581863977132795483[100] = 0;
   out_5581863977132795483[101] = 0;
   out_5581863977132795483[102] = 0;
   out_5581863977132795483[103] = 0;
   out_5581863977132795483[104] = 0;
   out_5581863977132795483[105] = 0;
   out_5581863977132795483[106] = 0;
   out_5581863977132795483[107] = 0;
   out_5581863977132795483[108] = 1.0;
   out_5581863977132795483[109] = 0;
   out_5581863977132795483[110] = 0;
   out_5581863977132795483[111] = 0;
   out_5581863977132795483[112] = 0;
   out_5581863977132795483[113] = 0;
   out_5581863977132795483[114] = 0;
   out_5581863977132795483[115] = 0;
   out_5581863977132795483[116] = 0;
   out_5581863977132795483[117] = 0;
   out_5581863977132795483[118] = 0;
   out_5581863977132795483[119] = 0;
   out_5581863977132795483[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_6423546374911735369) {
   out_6423546374911735369[0] = dt*state[3] + state[0];
   out_6423546374911735369[1] = dt*state[4] + state[1];
   out_6423546374911735369[2] = dt*state[5] + state[2];
   out_6423546374911735369[3] = state[3];
   out_6423546374911735369[4] = state[4];
   out_6423546374911735369[5] = state[5];
   out_6423546374911735369[6] = dt*state[7] + state[6];
   out_6423546374911735369[7] = dt*state[8] + state[7];
   out_6423546374911735369[8] = state[8];
   out_6423546374911735369[9] = state[9];
   out_6423546374911735369[10] = state[10];
}
void F_fun(double *state, double dt, double *out_7437858096387244450) {
   out_7437858096387244450[0] = 1;
   out_7437858096387244450[1] = 0;
   out_7437858096387244450[2] = 0;
   out_7437858096387244450[3] = dt;
   out_7437858096387244450[4] = 0;
   out_7437858096387244450[5] = 0;
   out_7437858096387244450[6] = 0;
   out_7437858096387244450[7] = 0;
   out_7437858096387244450[8] = 0;
   out_7437858096387244450[9] = 0;
   out_7437858096387244450[10] = 0;
   out_7437858096387244450[11] = 0;
   out_7437858096387244450[12] = 1;
   out_7437858096387244450[13] = 0;
   out_7437858096387244450[14] = 0;
   out_7437858096387244450[15] = dt;
   out_7437858096387244450[16] = 0;
   out_7437858096387244450[17] = 0;
   out_7437858096387244450[18] = 0;
   out_7437858096387244450[19] = 0;
   out_7437858096387244450[20] = 0;
   out_7437858096387244450[21] = 0;
   out_7437858096387244450[22] = 0;
   out_7437858096387244450[23] = 0;
   out_7437858096387244450[24] = 1;
   out_7437858096387244450[25] = 0;
   out_7437858096387244450[26] = 0;
   out_7437858096387244450[27] = dt;
   out_7437858096387244450[28] = 0;
   out_7437858096387244450[29] = 0;
   out_7437858096387244450[30] = 0;
   out_7437858096387244450[31] = 0;
   out_7437858096387244450[32] = 0;
   out_7437858096387244450[33] = 0;
   out_7437858096387244450[34] = 0;
   out_7437858096387244450[35] = 0;
   out_7437858096387244450[36] = 1;
   out_7437858096387244450[37] = 0;
   out_7437858096387244450[38] = 0;
   out_7437858096387244450[39] = 0;
   out_7437858096387244450[40] = 0;
   out_7437858096387244450[41] = 0;
   out_7437858096387244450[42] = 0;
   out_7437858096387244450[43] = 0;
   out_7437858096387244450[44] = 0;
   out_7437858096387244450[45] = 0;
   out_7437858096387244450[46] = 0;
   out_7437858096387244450[47] = 0;
   out_7437858096387244450[48] = 1;
   out_7437858096387244450[49] = 0;
   out_7437858096387244450[50] = 0;
   out_7437858096387244450[51] = 0;
   out_7437858096387244450[52] = 0;
   out_7437858096387244450[53] = 0;
   out_7437858096387244450[54] = 0;
   out_7437858096387244450[55] = 0;
   out_7437858096387244450[56] = 0;
   out_7437858096387244450[57] = 0;
   out_7437858096387244450[58] = 0;
   out_7437858096387244450[59] = 0;
   out_7437858096387244450[60] = 1;
   out_7437858096387244450[61] = 0;
   out_7437858096387244450[62] = 0;
   out_7437858096387244450[63] = 0;
   out_7437858096387244450[64] = 0;
   out_7437858096387244450[65] = 0;
   out_7437858096387244450[66] = 0;
   out_7437858096387244450[67] = 0;
   out_7437858096387244450[68] = 0;
   out_7437858096387244450[69] = 0;
   out_7437858096387244450[70] = 0;
   out_7437858096387244450[71] = 0;
   out_7437858096387244450[72] = 1;
   out_7437858096387244450[73] = dt;
   out_7437858096387244450[74] = 0;
   out_7437858096387244450[75] = 0;
   out_7437858096387244450[76] = 0;
   out_7437858096387244450[77] = 0;
   out_7437858096387244450[78] = 0;
   out_7437858096387244450[79] = 0;
   out_7437858096387244450[80] = 0;
   out_7437858096387244450[81] = 0;
   out_7437858096387244450[82] = 0;
   out_7437858096387244450[83] = 0;
   out_7437858096387244450[84] = 1;
   out_7437858096387244450[85] = dt;
   out_7437858096387244450[86] = 0;
   out_7437858096387244450[87] = 0;
   out_7437858096387244450[88] = 0;
   out_7437858096387244450[89] = 0;
   out_7437858096387244450[90] = 0;
   out_7437858096387244450[91] = 0;
   out_7437858096387244450[92] = 0;
   out_7437858096387244450[93] = 0;
   out_7437858096387244450[94] = 0;
   out_7437858096387244450[95] = 0;
   out_7437858096387244450[96] = 1;
   out_7437858096387244450[97] = 0;
   out_7437858096387244450[98] = 0;
   out_7437858096387244450[99] = 0;
   out_7437858096387244450[100] = 0;
   out_7437858096387244450[101] = 0;
   out_7437858096387244450[102] = 0;
   out_7437858096387244450[103] = 0;
   out_7437858096387244450[104] = 0;
   out_7437858096387244450[105] = 0;
   out_7437858096387244450[106] = 0;
   out_7437858096387244450[107] = 0;
   out_7437858096387244450[108] = 1;
   out_7437858096387244450[109] = 0;
   out_7437858096387244450[110] = 0;
   out_7437858096387244450[111] = 0;
   out_7437858096387244450[112] = 0;
   out_7437858096387244450[113] = 0;
   out_7437858096387244450[114] = 0;
   out_7437858096387244450[115] = 0;
   out_7437858096387244450[116] = 0;
   out_7437858096387244450[117] = 0;
   out_7437858096387244450[118] = 0;
   out_7437858096387244450[119] = 0;
   out_7437858096387244450[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_8168523164697780971) {
   out_8168523164697780971[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_6215961085732895038) {
   out_6215961085732895038[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6215961085732895038[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6215961085732895038[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6215961085732895038[3] = 0;
   out_6215961085732895038[4] = 0;
   out_6215961085732895038[5] = 0;
   out_6215961085732895038[6] = 1;
   out_6215961085732895038[7] = 0;
   out_6215961085732895038[8] = 0;
   out_6215961085732895038[9] = 0;
   out_6215961085732895038[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_2583752503617678104) {
   out_2583752503617678104[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_6777344250897440240) {
   out_6777344250897440240[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6777344250897440240[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6777344250897440240[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6777344250897440240[3] = 0;
   out_6777344250897440240[4] = 0;
   out_6777344250897440240[5] = 0;
   out_6777344250897440240[6] = 1;
   out_6777344250897440240[7] = 0;
   out_6777344250897440240[8] = 0;
   out_6777344250897440240[9] = 1;
   out_6777344250897440240[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_7914792312414388917) {
   out_7914792312414388917[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_1169512049399806794) {
   out_1169512049399806794[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[6] = 0;
   out_1169512049399806794[7] = 1;
   out_1169512049399806794[8] = 0;
   out_1169512049399806794[9] = 0;
   out_1169512049399806794[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_7914792312414388917) {
   out_7914792312414388917[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_1169512049399806794) {
   out_1169512049399806794[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1169512049399806794[6] = 0;
   out_1169512049399806794[7] = 1;
   out_1169512049399806794[8] = 0;
   out_1169512049399806794[9] = 0;
   out_1169512049399806794[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_1298370022994424896) {
  err_fun(nom_x, delta_x, out_1298370022994424896);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1216411467074742856) {
  inv_err_fun(nom_x, true_x, out_1216411467074742856);
}
void gnss_H_mod_fun(double *state, double *out_5581863977132795483) {
  H_mod_fun(state, out_5581863977132795483);
}
void gnss_f_fun(double *state, double dt, double *out_6423546374911735369) {
  f_fun(state,  dt, out_6423546374911735369);
}
void gnss_F_fun(double *state, double dt, double *out_7437858096387244450) {
  F_fun(state,  dt, out_7437858096387244450);
}
void gnss_h_6(double *state, double *sat_pos, double *out_8168523164697780971) {
  h_6(state, sat_pos, out_8168523164697780971);
}
void gnss_H_6(double *state, double *sat_pos, double *out_6215961085732895038) {
  H_6(state, sat_pos, out_6215961085732895038);
}
void gnss_h_20(double *state, double *sat_pos, double *out_2583752503617678104) {
  h_20(state, sat_pos, out_2583752503617678104);
}
void gnss_H_20(double *state, double *sat_pos, double *out_6777344250897440240) {
  H_20(state, sat_pos, out_6777344250897440240);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7914792312414388917) {
  h_7(state, sat_pos_vel, out_7914792312414388917);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1169512049399806794) {
  H_7(state, sat_pos_vel, out_1169512049399806794);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7914792312414388917) {
  h_21(state, sat_pos_vel, out_7914792312414388917);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1169512049399806794) {
  H_21(state, sat_pos_vel, out_1169512049399806794);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
