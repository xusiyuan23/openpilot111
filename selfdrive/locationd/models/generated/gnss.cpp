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
void err_fun(double *nom_x, double *delta_x, double *out_4849909810210845231) {
   out_4849909810210845231[0] = delta_x[0] + nom_x[0];
   out_4849909810210845231[1] = delta_x[1] + nom_x[1];
   out_4849909810210845231[2] = delta_x[2] + nom_x[2];
   out_4849909810210845231[3] = delta_x[3] + nom_x[3];
   out_4849909810210845231[4] = delta_x[4] + nom_x[4];
   out_4849909810210845231[5] = delta_x[5] + nom_x[5];
   out_4849909810210845231[6] = delta_x[6] + nom_x[6];
   out_4849909810210845231[7] = delta_x[7] + nom_x[7];
   out_4849909810210845231[8] = delta_x[8] + nom_x[8];
   out_4849909810210845231[9] = delta_x[9] + nom_x[9];
   out_4849909810210845231[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9155514165852770581) {
   out_9155514165852770581[0] = -nom_x[0] + true_x[0];
   out_9155514165852770581[1] = -nom_x[1] + true_x[1];
   out_9155514165852770581[2] = -nom_x[2] + true_x[2];
   out_9155514165852770581[3] = -nom_x[3] + true_x[3];
   out_9155514165852770581[4] = -nom_x[4] + true_x[4];
   out_9155514165852770581[5] = -nom_x[5] + true_x[5];
   out_9155514165852770581[6] = -nom_x[6] + true_x[6];
   out_9155514165852770581[7] = -nom_x[7] + true_x[7];
   out_9155514165852770581[8] = -nom_x[8] + true_x[8];
   out_9155514165852770581[9] = -nom_x[9] + true_x[9];
   out_9155514165852770581[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_1695716312477195060) {
   out_1695716312477195060[0] = 1.0;
   out_1695716312477195060[1] = 0;
   out_1695716312477195060[2] = 0;
   out_1695716312477195060[3] = 0;
   out_1695716312477195060[4] = 0;
   out_1695716312477195060[5] = 0;
   out_1695716312477195060[6] = 0;
   out_1695716312477195060[7] = 0;
   out_1695716312477195060[8] = 0;
   out_1695716312477195060[9] = 0;
   out_1695716312477195060[10] = 0;
   out_1695716312477195060[11] = 0;
   out_1695716312477195060[12] = 1.0;
   out_1695716312477195060[13] = 0;
   out_1695716312477195060[14] = 0;
   out_1695716312477195060[15] = 0;
   out_1695716312477195060[16] = 0;
   out_1695716312477195060[17] = 0;
   out_1695716312477195060[18] = 0;
   out_1695716312477195060[19] = 0;
   out_1695716312477195060[20] = 0;
   out_1695716312477195060[21] = 0;
   out_1695716312477195060[22] = 0;
   out_1695716312477195060[23] = 0;
   out_1695716312477195060[24] = 1.0;
   out_1695716312477195060[25] = 0;
   out_1695716312477195060[26] = 0;
   out_1695716312477195060[27] = 0;
   out_1695716312477195060[28] = 0;
   out_1695716312477195060[29] = 0;
   out_1695716312477195060[30] = 0;
   out_1695716312477195060[31] = 0;
   out_1695716312477195060[32] = 0;
   out_1695716312477195060[33] = 0;
   out_1695716312477195060[34] = 0;
   out_1695716312477195060[35] = 0;
   out_1695716312477195060[36] = 1.0;
   out_1695716312477195060[37] = 0;
   out_1695716312477195060[38] = 0;
   out_1695716312477195060[39] = 0;
   out_1695716312477195060[40] = 0;
   out_1695716312477195060[41] = 0;
   out_1695716312477195060[42] = 0;
   out_1695716312477195060[43] = 0;
   out_1695716312477195060[44] = 0;
   out_1695716312477195060[45] = 0;
   out_1695716312477195060[46] = 0;
   out_1695716312477195060[47] = 0;
   out_1695716312477195060[48] = 1.0;
   out_1695716312477195060[49] = 0;
   out_1695716312477195060[50] = 0;
   out_1695716312477195060[51] = 0;
   out_1695716312477195060[52] = 0;
   out_1695716312477195060[53] = 0;
   out_1695716312477195060[54] = 0;
   out_1695716312477195060[55] = 0;
   out_1695716312477195060[56] = 0;
   out_1695716312477195060[57] = 0;
   out_1695716312477195060[58] = 0;
   out_1695716312477195060[59] = 0;
   out_1695716312477195060[60] = 1.0;
   out_1695716312477195060[61] = 0;
   out_1695716312477195060[62] = 0;
   out_1695716312477195060[63] = 0;
   out_1695716312477195060[64] = 0;
   out_1695716312477195060[65] = 0;
   out_1695716312477195060[66] = 0;
   out_1695716312477195060[67] = 0;
   out_1695716312477195060[68] = 0;
   out_1695716312477195060[69] = 0;
   out_1695716312477195060[70] = 0;
   out_1695716312477195060[71] = 0;
   out_1695716312477195060[72] = 1.0;
   out_1695716312477195060[73] = 0;
   out_1695716312477195060[74] = 0;
   out_1695716312477195060[75] = 0;
   out_1695716312477195060[76] = 0;
   out_1695716312477195060[77] = 0;
   out_1695716312477195060[78] = 0;
   out_1695716312477195060[79] = 0;
   out_1695716312477195060[80] = 0;
   out_1695716312477195060[81] = 0;
   out_1695716312477195060[82] = 0;
   out_1695716312477195060[83] = 0;
   out_1695716312477195060[84] = 1.0;
   out_1695716312477195060[85] = 0;
   out_1695716312477195060[86] = 0;
   out_1695716312477195060[87] = 0;
   out_1695716312477195060[88] = 0;
   out_1695716312477195060[89] = 0;
   out_1695716312477195060[90] = 0;
   out_1695716312477195060[91] = 0;
   out_1695716312477195060[92] = 0;
   out_1695716312477195060[93] = 0;
   out_1695716312477195060[94] = 0;
   out_1695716312477195060[95] = 0;
   out_1695716312477195060[96] = 1.0;
   out_1695716312477195060[97] = 0;
   out_1695716312477195060[98] = 0;
   out_1695716312477195060[99] = 0;
   out_1695716312477195060[100] = 0;
   out_1695716312477195060[101] = 0;
   out_1695716312477195060[102] = 0;
   out_1695716312477195060[103] = 0;
   out_1695716312477195060[104] = 0;
   out_1695716312477195060[105] = 0;
   out_1695716312477195060[106] = 0;
   out_1695716312477195060[107] = 0;
   out_1695716312477195060[108] = 1.0;
   out_1695716312477195060[109] = 0;
   out_1695716312477195060[110] = 0;
   out_1695716312477195060[111] = 0;
   out_1695716312477195060[112] = 0;
   out_1695716312477195060[113] = 0;
   out_1695716312477195060[114] = 0;
   out_1695716312477195060[115] = 0;
   out_1695716312477195060[116] = 0;
   out_1695716312477195060[117] = 0;
   out_1695716312477195060[118] = 0;
   out_1695716312477195060[119] = 0;
   out_1695716312477195060[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_246318625600254703) {
   out_246318625600254703[0] = dt*state[3] + state[0];
   out_246318625600254703[1] = dt*state[4] + state[1];
   out_246318625600254703[2] = dt*state[5] + state[2];
   out_246318625600254703[3] = state[3];
   out_246318625600254703[4] = state[4];
   out_246318625600254703[5] = state[5];
   out_246318625600254703[6] = dt*state[7] + state[6];
   out_246318625600254703[7] = dt*state[8] + state[7];
   out_246318625600254703[8] = state[8];
   out_246318625600254703[9] = state[9];
   out_246318625600254703[10] = state[10];
}
void F_fun(double *state, double dt, double *out_991013928034158677) {
   out_991013928034158677[0] = 1;
   out_991013928034158677[1] = 0;
   out_991013928034158677[2] = 0;
   out_991013928034158677[3] = dt;
   out_991013928034158677[4] = 0;
   out_991013928034158677[5] = 0;
   out_991013928034158677[6] = 0;
   out_991013928034158677[7] = 0;
   out_991013928034158677[8] = 0;
   out_991013928034158677[9] = 0;
   out_991013928034158677[10] = 0;
   out_991013928034158677[11] = 0;
   out_991013928034158677[12] = 1;
   out_991013928034158677[13] = 0;
   out_991013928034158677[14] = 0;
   out_991013928034158677[15] = dt;
   out_991013928034158677[16] = 0;
   out_991013928034158677[17] = 0;
   out_991013928034158677[18] = 0;
   out_991013928034158677[19] = 0;
   out_991013928034158677[20] = 0;
   out_991013928034158677[21] = 0;
   out_991013928034158677[22] = 0;
   out_991013928034158677[23] = 0;
   out_991013928034158677[24] = 1;
   out_991013928034158677[25] = 0;
   out_991013928034158677[26] = 0;
   out_991013928034158677[27] = dt;
   out_991013928034158677[28] = 0;
   out_991013928034158677[29] = 0;
   out_991013928034158677[30] = 0;
   out_991013928034158677[31] = 0;
   out_991013928034158677[32] = 0;
   out_991013928034158677[33] = 0;
   out_991013928034158677[34] = 0;
   out_991013928034158677[35] = 0;
   out_991013928034158677[36] = 1;
   out_991013928034158677[37] = 0;
   out_991013928034158677[38] = 0;
   out_991013928034158677[39] = 0;
   out_991013928034158677[40] = 0;
   out_991013928034158677[41] = 0;
   out_991013928034158677[42] = 0;
   out_991013928034158677[43] = 0;
   out_991013928034158677[44] = 0;
   out_991013928034158677[45] = 0;
   out_991013928034158677[46] = 0;
   out_991013928034158677[47] = 0;
   out_991013928034158677[48] = 1;
   out_991013928034158677[49] = 0;
   out_991013928034158677[50] = 0;
   out_991013928034158677[51] = 0;
   out_991013928034158677[52] = 0;
   out_991013928034158677[53] = 0;
   out_991013928034158677[54] = 0;
   out_991013928034158677[55] = 0;
   out_991013928034158677[56] = 0;
   out_991013928034158677[57] = 0;
   out_991013928034158677[58] = 0;
   out_991013928034158677[59] = 0;
   out_991013928034158677[60] = 1;
   out_991013928034158677[61] = 0;
   out_991013928034158677[62] = 0;
   out_991013928034158677[63] = 0;
   out_991013928034158677[64] = 0;
   out_991013928034158677[65] = 0;
   out_991013928034158677[66] = 0;
   out_991013928034158677[67] = 0;
   out_991013928034158677[68] = 0;
   out_991013928034158677[69] = 0;
   out_991013928034158677[70] = 0;
   out_991013928034158677[71] = 0;
   out_991013928034158677[72] = 1;
   out_991013928034158677[73] = dt;
   out_991013928034158677[74] = 0;
   out_991013928034158677[75] = 0;
   out_991013928034158677[76] = 0;
   out_991013928034158677[77] = 0;
   out_991013928034158677[78] = 0;
   out_991013928034158677[79] = 0;
   out_991013928034158677[80] = 0;
   out_991013928034158677[81] = 0;
   out_991013928034158677[82] = 0;
   out_991013928034158677[83] = 0;
   out_991013928034158677[84] = 1;
   out_991013928034158677[85] = dt;
   out_991013928034158677[86] = 0;
   out_991013928034158677[87] = 0;
   out_991013928034158677[88] = 0;
   out_991013928034158677[89] = 0;
   out_991013928034158677[90] = 0;
   out_991013928034158677[91] = 0;
   out_991013928034158677[92] = 0;
   out_991013928034158677[93] = 0;
   out_991013928034158677[94] = 0;
   out_991013928034158677[95] = 0;
   out_991013928034158677[96] = 1;
   out_991013928034158677[97] = 0;
   out_991013928034158677[98] = 0;
   out_991013928034158677[99] = 0;
   out_991013928034158677[100] = 0;
   out_991013928034158677[101] = 0;
   out_991013928034158677[102] = 0;
   out_991013928034158677[103] = 0;
   out_991013928034158677[104] = 0;
   out_991013928034158677[105] = 0;
   out_991013928034158677[106] = 0;
   out_991013928034158677[107] = 0;
   out_991013928034158677[108] = 1;
   out_991013928034158677[109] = 0;
   out_991013928034158677[110] = 0;
   out_991013928034158677[111] = 0;
   out_991013928034158677[112] = 0;
   out_991013928034158677[113] = 0;
   out_991013928034158677[114] = 0;
   out_991013928034158677[115] = 0;
   out_991013928034158677[116] = 0;
   out_991013928034158677[117] = 0;
   out_991013928034158677[118] = 0;
   out_991013928034158677[119] = 0;
   out_991013928034158677[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_3254589478467387681) {
   out_3254589478467387681[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_4443399033591840542) {
   out_4443399033591840542[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4443399033591840542[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4443399033591840542[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4443399033591840542[3] = 0;
   out_4443399033591840542[4] = 0;
   out_4443399033591840542[5] = 0;
   out_4443399033591840542[6] = 1;
   out_4443399033591840542[7] = 0;
   out_4443399033591840542[8] = 0;
   out_4443399033591840542[9] = 0;
   out_4443399033591840542[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_5372212336627346046) {
   out_5372212336627346046[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_2252354659347544918) {
   out_2252354659347544918[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2252354659347544918[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2252354659347544918[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2252354659347544918[3] = 0;
   out_2252354659347544918[4] = 0;
   out_2252354659347544918[5] = 0;
   out_2252354659347544918[6] = 1;
   out_2252354659347544918[7] = 0;
   out_2252354659347544918[8] = 0;
   out_2252354659347544918[9] = 1;
   out_2252354659347544918[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_6050116121606786003) {
   out_6050116121606786003[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_2862955004951087597) {
   out_2862955004951087597[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[6] = 0;
   out_2862955004951087597[7] = 1;
   out_2862955004951087597[8] = 0;
   out_2862955004951087597[9] = 0;
   out_2862955004951087597[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_6050116121606786003) {
   out_6050116121606786003[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_2862955004951087597) {
   out_2862955004951087597[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2862955004951087597[6] = 0;
   out_2862955004951087597[7] = 1;
   out_2862955004951087597[8] = 0;
   out_2862955004951087597[9] = 0;
   out_2862955004951087597[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4849909810210845231) {
  err_fun(nom_x, delta_x, out_4849909810210845231);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_9155514165852770581) {
  inv_err_fun(nom_x, true_x, out_9155514165852770581);
}
void gnss_H_mod_fun(double *state, double *out_1695716312477195060) {
  H_mod_fun(state, out_1695716312477195060);
}
void gnss_f_fun(double *state, double dt, double *out_246318625600254703) {
  f_fun(state,  dt, out_246318625600254703);
}
void gnss_F_fun(double *state, double dt, double *out_991013928034158677) {
  F_fun(state,  dt, out_991013928034158677);
}
void gnss_h_6(double *state, double *sat_pos, double *out_3254589478467387681) {
  h_6(state, sat_pos, out_3254589478467387681);
}
void gnss_H_6(double *state, double *sat_pos, double *out_4443399033591840542) {
  H_6(state, sat_pos, out_4443399033591840542);
}
void gnss_h_20(double *state, double *sat_pos, double *out_5372212336627346046) {
  h_20(state, sat_pos, out_5372212336627346046);
}
void gnss_H_20(double *state, double *sat_pos, double *out_2252354659347544918) {
  H_20(state, sat_pos, out_2252354659347544918);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6050116121606786003) {
  h_7(state, sat_pos_vel, out_6050116121606786003);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2862955004951087597) {
  H_7(state, sat_pos_vel, out_2862955004951087597);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6050116121606786003) {
  h_21(state, sat_pos_vel, out_6050116121606786003);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2862955004951087597) {
  H_21(state, sat_pos_vel, out_2862955004951087597);
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
