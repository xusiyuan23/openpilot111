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
void err_fun(double *nom_x, double *delta_x, double *out_8128068779397269674) {
   out_8128068779397269674[0] = delta_x[0] + nom_x[0];
   out_8128068779397269674[1] = delta_x[1] + nom_x[1];
   out_8128068779397269674[2] = delta_x[2] + nom_x[2];
   out_8128068779397269674[3] = delta_x[3] + nom_x[3];
   out_8128068779397269674[4] = delta_x[4] + nom_x[4];
   out_8128068779397269674[5] = delta_x[5] + nom_x[5];
   out_8128068779397269674[6] = delta_x[6] + nom_x[6];
   out_8128068779397269674[7] = delta_x[7] + nom_x[7];
   out_8128068779397269674[8] = delta_x[8] + nom_x[8];
   out_8128068779397269674[9] = delta_x[9] + nom_x[9];
   out_8128068779397269674[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1141553057367786298) {
   out_1141553057367786298[0] = -nom_x[0] + true_x[0];
   out_1141553057367786298[1] = -nom_x[1] + true_x[1];
   out_1141553057367786298[2] = -nom_x[2] + true_x[2];
   out_1141553057367786298[3] = -nom_x[3] + true_x[3];
   out_1141553057367786298[4] = -nom_x[4] + true_x[4];
   out_1141553057367786298[5] = -nom_x[5] + true_x[5];
   out_1141553057367786298[6] = -nom_x[6] + true_x[6];
   out_1141553057367786298[7] = -nom_x[7] + true_x[7];
   out_1141553057367786298[8] = -nom_x[8] + true_x[8];
   out_1141553057367786298[9] = -nom_x[9] + true_x[9];
   out_1141553057367786298[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_2327247742686327650) {
   out_2327247742686327650[0] = 1.0;
   out_2327247742686327650[1] = 0;
   out_2327247742686327650[2] = 0;
   out_2327247742686327650[3] = 0;
   out_2327247742686327650[4] = 0;
   out_2327247742686327650[5] = 0;
   out_2327247742686327650[6] = 0;
   out_2327247742686327650[7] = 0;
   out_2327247742686327650[8] = 0;
   out_2327247742686327650[9] = 0;
   out_2327247742686327650[10] = 0;
   out_2327247742686327650[11] = 0;
   out_2327247742686327650[12] = 1.0;
   out_2327247742686327650[13] = 0;
   out_2327247742686327650[14] = 0;
   out_2327247742686327650[15] = 0;
   out_2327247742686327650[16] = 0;
   out_2327247742686327650[17] = 0;
   out_2327247742686327650[18] = 0;
   out_2327247742686327650[19] = 0;
   out_2327247742686327650[20] = 0;
   out_2327247742686327650[21] = 0;
   out_2327247742686327650[22] = 0;
   out_2327247742686327650[23] = 0;
   out_2327247742686327650[24] = 1.0;
   out_2327247742686327650[25] = 0;
   out_2327247742686327650[26] = 0;
   out_2327247742686327650[27] = 0;
   out_2327247742686327650[28] = 0;
   out_2327247742686327650[29] = 0;
   out_2327247742686327650[30] = 0;
   out_2327247742686327650[31] = 0;
   out_2327247742686327650[32] = 0;
   out_2327247742686327650[33] = 0;
   out_2327247742686327650[34] = 0;
   out_2327247742686327650[35] = 0;
   out_2327247742686327650[36] = 1.0;
   out_2327247742686327650[37] = 0;
   out_2327247742686327650[38] = 0;
   out_2327247742686327650[39] = 0;
   out_2327247742686327650[40] = 0;
   out_2327247742686327650[41] = 0;
   out_2327247742686327650[42] = 0;
   out_2327247742686327650[43] = 0;
   out_2327247742686327650[44] = 0;
   out_2327247742686327650[45] = 0;
   out_2327247742686327650[46] = 0;
   out_2327247742686327650[47] = 0;
   out_2327247742686327650[48] = 1.0;
   out_2327247742686327650[49] = 0;
   out_2327247742686327650[50] = 0;
   out_2327247742686327650[51] = 0;
   out_2327247742686327650[52] = 0;
   out_2327247742686327650[53] = 0;
   out_2327247742686327650[54] = 0;
   out_2327247742686327650[55] = 0;
   out_2327247742686327650[56] = 0;
   out_2327247742686327650[57] = 0;
   out_2327247742686327650[58] = 0;
   out_2327247742686327650[59] = 0;
   out_2327247742686327650[60] = 1.0;
   out_2327247742686327650[61] = 0;
   out_2327247742686327650[62] = 0;
   out_2327247742686327650[63] = 0;
   out_2327247742686327650[64] = 0;
   out_2327247742686327650[65] = 0;
   out_2327247742686327650[66] = 0;
   out_2327247742686327650[67] = 0;
   out_2327247742686327650[68] = 0;
   out_2327247742686327650[69] = 0;
   out_2327247742686327650[70] = 0;
   out_2327247742686327650[71] = 0;
   out_2327247742686327650[72] = 1.0;
   out_2327247742686327650[73] = 0;
   out_2327247742686327650[74] = 0;
   out_2327247742686327650[75] = 0;
   out_2327247742686327650[76] = 0;
   out_2327247742686327650[77] = 0;
   out_2327247742686327650[78] = 0;
   out_2327247742686327650[79] = 0;
   out_2327247742686327650[80] = 0;
   out_2327247742686327650[81] = 0;
   out_2327247742686327650[82] = 0;
   out_2327247742686327650[83] = 0;
   out_2327247742686327650[84] = 1.0;
   out_2327247742686327650[85] = 0;
   out_2327247742686327650[86] = 0;
   out_2327247742686327650[87] = 0;
   out_2327247742686327650[88] = 0;
   out_2327247742686327650[89] = 0;
   out_2327247742686327650[90] = 0;
   out_2327247742686327650[91] = 0;
   out_2327247742686327650[92] = 0;
   out_2327247742686327650[93] = 0;
   out_2327247742686327650[94] = 0;
   out_2327247742686327650[95] = 0;
   out_2327247742686327650[96] = 1.0;
   out_2327247742686327650[97] = 0;
   out_2327247742686327650[98] = 0;
   out_2327247742686327650[99] = 0;
   out_2327247742686327650[100] = 0;
   out_2327247742686327650[101] = 0;
   out_2327247742686327650[102] = 0;
   out_2327247742686327650[103] = 0;
   out_2327247742686327650[104] = 0;
   out_2327247742686327650[105] = 0;
   out_2327247742686327650[106] = 0;
   out_2327247742686327650[107] = 0;
   out_2327247742686327650[108] = 1.0;
   out_2327247742686327650[109] = 0;
   out_2327247742686327650[110] = 0;
   out_2327247742686327650[111] = 0;
   out_2327247742686327650[112] = 0;
   out_2327247742686327650[113] = 0;
   out_2327247742686327650[114] = 0;
   out_2327247742686327650[115] = 0;
   out_2327247742686327650[116] = 0;
   out_2327247742686327650[117] = 0;
   out_2327247742686327650[118] = 0;
   out_2327247742686327650[119] = 0;
   out_2327247742686327650[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_690824356618248952) {
   out_690824356618248952[0] = dt*state[3] + state[0];
   out_690824356618248952[1] = dt*state[4] + state[1];
   out_690824356618248952[2] = dt*state[5] + state[2];
   out_690824356618248952[3] = state[3];
   out_690824356618248952[4] = state[4];
   out_690824356618248952[5] = state[5];
   out_690824356618248952[6] = dt*state[7] + state[6];
   out_690824356618248952[7] = dt*state[8] + state[7];
   out_690824356618248952[8] = state[8];
   out_690824356618248952[9] = state[9];
   out_690824356618248952[10] = state[10];
}
void F_fun(double *state, double dt, double *out_2015156480179268251) {
   out_2015156480179268251[0] = 1;
   out_2015156480179268251[1] = 0;
   out_2015156480179268251[2] = 0;
   out_2015156480179268251[3] = dt;
   out_2015156480179268251[4] = 0;
   out_2015156480179268251[5] = 0;
   out_2015156480179268251[6] = 0;
   out_2015156480179268251[7] = 0;
   out_2015156480179268251[8] = 0;
   out_2015156480179268251[9] = 0;
   out_2015156480179268251[10] = 0;
   out_2015156480179268251[11] = 0;
   out_2015156480179268251[12] = 1;
   out_2015156480179268251[13] = 0;
   out_2015156480179268251[14] = 0;
   out_2015156480179268251[15] = dt;
   out_2015156480179268251[16] = 0;
   out_2015156480179268251[17] = 0;
   out_2015156480179268251[18] = 0;
   out_2015156480179268251[19] = 0;
   out_2015156480179268251[20] = 0;
   out_2015156480179268251[21] = 0;
   out_2015156480179268251[22] = 0;
   out_2015156480179268251[23] = 0;
   out_2015156480179268251[24] = 1;
   out_2015156480179268251[25] = 0;
   out_2015156480179268251[26] = 0;
   out_2015156480179268251[27] = dt;
   out_2015156480179268251[28] = 0;
   out_2015156480179268251[29] = 0;
   out_2015156480179268251[30] = 0;
   out_2015156480179268251[31] = 0;
   out_2015156480179268251[32] = 0;
   out_2015156480179268251[33] = 0;
   out_2015156480179268251[34] = 0;
   out_2015156480179268251[35] = 0;
   out_2015156480179268251[36] = 1;
   out_2015156480179268251[37] = 0;
   out_2015156480179268251[38] = 0;
   out_2015156480179268251[39] = 0;
   out_2015156480179268251[40] = 0;
   out_2015156480179268251[41] = 0;
   out_2015156480179268251[42] = 0;
   out_2015156480179268251[43] = 0;
   out_2015156480179268251[44] = 0;
   out_2015156480179268251[45] = 0;
   out_2015156480179268251[46] = 0;
   out_2015156480179268251[47] = 0;
   out_2015156480179268251[48] = 1;
   out_2015156480179268251[49] = 0;
   out_2015156480179268251[50] = 0;
   out_2015156480179268251[51] = 0;
   out_2015156480179268251[52] = 0;
   out_2015156480179268251[53] = 0;
   out_2015156480179268251[54] = 0;
   out_2015156480179268251[55] = 0;
   out_2015156480179268251[56] = 0;
   out_2015156480179268251[57] = 0;
   out_2015156480179268251[58] = 0;
   out_2015156480179268251[59] = 0;
   out_2015156480179268251[60] = 1;
   out_2015156480179268251[61] = 0;
   out_2015156480179268251[62] = 0;
   out_2015156480179268251[63] = 0;
   out_2015156480179268251[64] = 0;
   out_2015156480179268251[65] = 0;
   out_2015156480179268251[66] = 0;
   out_2015156480179268251[67] = 0;
   out_2015156480179268251[68] = 0;
   out_2015156480179268251[69] = 0;
   out_2015156480179268251[70] = 0;
   out_2015156480179268251[71] = 0;
   out_2015156480179268251[72] = 1;
   out_2015156480179268251[73] = dt;
   out_2015156480179268251[74] = 0;
   out_2015156480179268251[75] = 0;
   out_2015156480179268251[76] = 0;
   out_2015156480179268251[77] = 0;
   out_2015156480179268251[78] = 0;
   out_2015156480179268251[79] = 0;
   out_2015156480179268251[80] = 0;
   out_2015156480179268251[81] = 0;
   out_2015156480179268251[82] = 0;
   out_2015156480179268251[83] = 0;
   out_2015156480179268251[84] = 1;
   out_2015156480179268251[85] = dt;
   out_2015156480179268251[86] = 0;
   out_2015156480179268251[87] = 0;
   out_2015156480179268251[88] = 0;
   out_2015156480179268251[89] = 0;
   out_2015156480179268251[90] = 0;
   out_2015156480179268251[91] = 0;
   out_2015156480179268251[92] = 0;
   out_2015156480179268251[93] = 0;
   out_2015156480179268251[94] = 0;
   out_2015156480179268251[95] = 0;
   out_2015156480179268251[96] = 1;
   out_2015156480179268251[97] = 0;
   out_2015156480179268251[98] = 0;
   out_2015156480179268251[99] = 0;
   out_2015156480179268251[100] = 0;
   out_2015156480179268251[101] = 0;
   out_2015156480179268251[102] = 0;
   out_2015156480179268251[103] = 0;
   out_2015156480179268251[104] = 0;
   out_2015156480179268251[105] = 0;
   out_2015156480179268251[106] = 0;
   out_2015156480179268251[107] = 0;
   out_2015156480179268251[108] = 1;
   out_2015156480179268251[109] = 0;
   out_2015156480179268251[110] = 0;
   out_2015156480179268251[111] = 0;
   out_2015156480179268251[112] = 0;
   out_2015156480179268251[113] = 0;
   out_2015156480179268251[114] = 0;
   out_2015156480179268251[115] = 0;
   out_2015156480179268251[116] = 0;
   out_2015156480179268251[117] = 0;
   out_2015156480179268251[118] = 0;
   out_2015156480179268251[119] = 0;
   out_2015156480179268251[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_5585365302508030232) {
   out_5585365302508030232[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_8739010288179210207) {
   out_8739010288179210207[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8739010288179210207[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8739010288179210207[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8739010288179210207[3] = 0;
   out_8739010288179210207[4] = 0;
   out_8739010288179210207[5] = 0;
   out_8739010288179210207[6] = 1;
   out_8739010288179210207[7] = 0;
   out_8739010288179210207[8] = 0;
   out_8739010288179210207[9] = 0;
   out_8739010288179210207[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_8217292551938667710) {
   out_8217292551938667710[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_5820758707894519330) {
   out_5820758707894519330[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5820758707894519330[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5820758707894519330[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5820758707894519330[3] = 0;
   out_5820758707894519330[4] = 0;
   out_5820758707894519330[5] = 0;
   out_5820758707894519330[6] = 1;
   out_5820758707894519330[7] = 0;
   out_5820758707894519330[8] = 0;
   out_5820758707894519330[9] = 1;
   out_5820758707894519330[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_1303955860558393099) {
   out_1303955860558393099[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_6257595943694472907) {
   out_6257595943694472907[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[6] = 0;
   out_6257595943694472907[7] = 1;
   out_6257595943694472907[8] = 0;
   out_6257595943694472907[9] = 0;
   out_6257595943694472907[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_1303955860558393099) {
   out_1303955860558393099[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_6257595943694472907) {
   out_6257595943694472907[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6257595943694472907[6] = 0;
   out_6257595943694472907[7] = 1;
   out_6257595943694472907[8] = 0;
   out_6257595943694472907[9] = 0;
   out_6257595943694472907[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8128068779397269674) {
  err_fun(nom_x, delta_x, out_8128068779397269674);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1141553057367786298) {
  inv_err_fun(nom_x, true_x, out_1141553057367786298);
}
void gnss_H_mod_fun(double *state, double *out_2327247742686327650) {
  H_mod_fun(state, out_2327247742686327650);
}
void gnss_f_fun(double *state, double dt, double *out_690824356618248952) {
  f_fun(state,  dt, out_690824356618248952);
}
void gnss_F_fun(double *state, double dt, double *out_2015156480179268251) {
  F_fun(state,  dt, out_2015156480179268251);
}
void gnss_h_6(double *state, double *sat_pos, double *out_5585365302508030232) {
  h_6(state, sat_pos, out_5585365302508030232);
}
void gnss_H_6(double *state, double *sat_pos, double *out_8739010288179210207) {
  H_6(state, sat_pos, out_8739010288179210207);
}
void gnss_h_20(double *state, double *sat_pos, double *out_8217292551938667710) {
  h_20(state, sat_pos, out_8217292551938667710);
}
void gnss_H_20(double *state, double *sat_pos, double *out_5820758707894519330) {
  H_20(state, sat_pos, out_5820758707894519330);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1303955860558393099) {
  h_7(state, sat_pos_vel, out_1303955860558393099);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_6257595943694472907) {
  H_7(state, sat_pos_vel, out_6257595943694472907);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1303955860558393099) {
  h_21(state, sat_pos_vel, out_1303955860558393099);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_6257595943694472907) {
  H_21(state, sat_pos_vel, out_6257595943694472907);
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
