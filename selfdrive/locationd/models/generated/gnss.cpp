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
 *                       Code generated with sympy 1.9                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4464393586256638428) {
   out_4464393586256638428[0] = delta_x[0] + nom_x[0];
   out_4464393586256638428[1] = delta_x[1] + nom_x[1];
   out_4464393586256638428[2] = delta_x[2] + nom_x[2];
   out_4464393586256638428[3] = delta_x[3] + nom_x[3];
   out_4464393586256638428[4] = delta_x[4] + nom_x[4];
   out_4464393586256638428[5] = delta_x[5] + nom_x[5];
   out_4464393586256638428[6] = delta_x[6] + nom_x[6];
   out_4464393586256638428[7] = delta_x[7] + nom_x[7];
   out_4464393586256638428[8] = delta_x[8] + nom_x[8];
   out_4464393586256638428[9] = delta_x[9] + nom_x[9];
   out_4464393586256638428[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8030080671851608904) {
   out_8030080671851608904[0] = -nom_x[0] + true_x[0];
   out_8030080671851608904[1] = -nom_x[1] + true_x[1];
   out_8030080671851608904[2] = -nom_x[2] + true_x[2];
   out_8030080671851608904[3] = -nom_x[3] + true_x[3];
   out_8030080671851608904[4] = -nom_x[4] + true_x[4];
   out_8030080671851608904[5] = -nom_x[5] + true_x[5];
   out_8030080671851608904[6] = -nom_x[6] + true_x[6];
   out_8030080671851608904[7] = -nom_x[7] + true_x[7];
   out_8030080671851608904[8] = -nom_x[8] + true_x[8];
   out_8030080671851608904[9] = -nom_x[9] + true_x[9];
   out_8030080671851608904[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_8251410735794788719) {
   out_8251410735794788719[0] = 1.0;
   out_8251410735794788719[1] = 0;
   out_8251410735794788719[2] = 0;
   out_8251410735794788719[3] = 0;
   out_8251410735794788719[4] = 0;
   out_8251410735794788719[5] = 0;
   out_8251410735794788719[6] = 0;
   out_8251410735794788719[7] = 0;
   out_8251410735794788719[8] = 0;
   out_8251410735794788719[9] = 0;
   out_8251410735794788719[10] = 0;
   out_8251410735794788719[11] = 0;
   out_8251410735794788719[12] = 1.0;
   out_8251410735794788719[13] = 0;
   out_8251410735794788719[14] = 0;
   out_8251410735794788719[15] = 0;
   out_8251410735794788719[16] = 0;
   out_8251410735794788719[17] = 0;
   out_8251410735794788719[18] = 0;
   out_8251410735794788719[19] = 0;
   out_8251410735794788719[20] = 0;
   out_8251410735794788719[21] = 0;
   out_8251410735794788719[22] = 0;
   out_8251410735794788719[23] = 0;
   out_8251410735794788719[24] = 1.0;
   out_8251410735794788719[25] = 0;
   out_8251410735794788719[26] = 0;
   out_8251410735794788719[27] = 0;
   out_8251410735794788719[28] = 0;
   out_8251410735794788719[29] = 0;
   out_8251410735794788719[30] = 0;
   out_8251410735794788719[31] = 0;
   out_8251410735794788719[32] = 0;
   out_8251410735794788719[33] = 0;
   out_8251410735794788719[34] = 0;
   out_8251410735794788719[35] = 0;
   out_8251410735794788719[36] = 1.0;
   out_8251410735794788719[37] = 0;
   out_8251410735794788719[38] = 0;
   out_8251410735794788719[39] = 0;
   out_8251410735794788719[40] = 0;
   out_8251410735794788719[41] = 0;
   out_8251410735794788719[42] = 0;
   out_8251410735794788719[43] = 0;
   out_8251410735794788719[44] = 0;
   out_8251410735794788719[45] = 0;
   out_8251410735794788719[46] = 0;
   out_8251410735794788719[47] = 0;
   out_8251410735794788719[48] = 1.0;
   out_8251410735794788719[49] = 0;
   out_8251410735794788719[50] = 0;
   out_8251410735794788719[51] = 0;
   out_8251410735794788719[52] = 0;
   out_8251410735794788719[53] = 0;
   out_8251410735794788719[54] = 0;
   out_8251410735794788719[55] = 0;
   out_8251410735794788719[56] = 0;
   out_8251410735794788719[57] = 0;
   out_8251410735794788719[58] = 0;
   out_8251410735794788719[59] = 0;
   out_8251410735794788719[60] = 1.0;
   out_8251410735794788719[61] = 0;
   out_8251410735794788719[62] = 0;
   out_8251410735794788719[63] = 0;
   out_8251410735794788719[64] = 0;
   out_8251410735794788719[65] = 0;
   out_8251410735794788719[66] = 0;
   out_8251410735794788719[67] = 0;
   out_8251410735794788719[68] = 0;
   out_8251410735794788719[69] = 0;
   out_8251410735794788719[70] = 0;
   out_8251410735794788719[71] = 0;
   out_8251410735794788719[72] = 1.0;
   out_8251410735794788719[73] = 0;
   out_8251410735794788719[74] = 0;
   out_8251410735794788719[75] = 0;
   out_8251410735794788719[76] = 0;
   out_8251410735794788719[77] = 0;
   out_8251410735794788719[78] = 0;
   out_8251410735794788719[79] = 0;
   out_8251410735794788719[80] = 0;
   out_8251410735794788719[81] = 0;
   out_8251410735794788719[82] = 0;
   out_8251410735794788719[83] = 0;
   out_8251410735794788719[84] = 1.0;
   out_8251410735794788719[85] = 0;
   out_8251410735794788719[86] = 0;
   out_8251410735794788719[87] = 0;
   out_8251410735794788719[88] = 0;
   out_8251410735794788719[89] = 0;
   out_8251410735794788719[90] = 0;
   out_8251410735794788719[91] = 0;
   out_8251410735794788719[92] = 0;
   out_8251410735794788719[93] = 0;
   out_8251410735794788719[94] = 0;
   out_8251410735794788719[95] = 0;
   out_8251410735794788719[96] = 1.0;
   out_8251410735794788719[97] = 0;
   out_8251410735794788719[98] = 0;
   out_8251410735794788719[99] = 0;
   out_8251410735794788719[100] = 0;
   out_8251410735794788719[101] = 0;
   out_8251410735794788719[102] = 0;
   out_8251410735794788719[103] = 0;
   out_8251410735794788719[104] = 0;
   out_8251410735794788719[105] = 0;
   out_8251410735794788719[106] = 0;
   out_8251410735794788719[107] = 0;
   out_8251410735794788719[108] = 1.0;
   out_8251410735794788719[109] = 0;
   out_8251410735794788719[110] = 0;
   out_8251410735794788719[111] = 0;
   out_8251410735794788719[112] = 0;
   out_8251410735794788719[113] = 0;
   out_8251410735794788719[114] = 0;
   out_8251410735794788719[115] = 0;
   out_8251410735794788719[116] = 0;
   out_8251410735794788719[117] = 0;
   out_8251410735794788719[118] = 0;
   out_8251410735794788719[119] = 0;
   out_8251410735794788719[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_5670922108486976517) {
   out_5670922108486976517[0] = dt*state[3] + state[0];
   out_5670922108486976517[1] = dt*state[4] + state[1];
   out_5670922108486976517[2] = dt*state[5] + state[2];
   out_5670922108486976517[3] = state[3];
   out_5670922108486976517[4] = state[4];
   out_5670922108486976517[5] = state[5];
   out_5670922108486976517[6] = dt*state[7] + state[6];
   out_5670922108486976517[7] = dt*state[8] + state[7];
   out_5670922108486976517[8] = state[8];
   out_5670922108486976517[9] = state[9];
   out_5670922108486976517[10] = state[10];
}
void F_fun(double *state, double dt, double *out_285810453574311978) {
   out_285810453574311978[0] = 1;
   out_285810453574311978[1] = 0;
   out_285810453574311978[2] = 0;
   out_285810453574311978[3] = dt;
   out_285810453574311978[4] = 0;
   out_285810453574311978[5] = 0;
   out_285810453574311978[6] = 0;
   out_285810453574311978[7] = 0;
   out_285810453574311978[8] = 0;
   out_285810453574311978[9] = 0;
   out_285810453574311978[10] = 0;
   out_285810453574311978[11] = 0;
   out_285810453574311978[12] = 1;
   out_285810453574311978[13] = 0;
   out_285810453574311978[14] = 0;
   out_285810453574311978[15] = dt;
   out_285810453574311978[16] = 0;
   out_285810453574311978[17] = 0;
   out_285810453574311978[18] = 0;
   out_285810453574311978[19] = 0;
   out_285810453574311978[20] = 0;
   out_285810453574311978[21] = 0;
   out_285810453574311978[22] = 0;
   out_285810453574311978[23] = 0;
   out_285810453574311978[24] = 1;
   out_285810453574311978[25] = 0;
   out_285810453574311978[26] = 0;
   out_285810453574311978[27] = dt;
   out_285810453574311978[28] = 0;
   out_285810453574311978[29] = 0;
   out_285810453574311978[30] = 0;
   out_285810453574311978[31] = 0;
   out_285810453574311978[32] = 0;
   out_285810453574311978[33] = 0;
   out_285810453574311978[34] = 0;
   out_285810453574311978[35] = 0;
   out_285810453574311978[36] = 1;
   out_285810453574311978[37] = 0;
   out_285810453574311978[38] = 0;
   out_285810453574311978[39] = 0;
   out_285810453574311978[40] = 0;
   out_285810453574311978[41] = 0;
   out_285810453574311978[42] = 0;
   out_285810453574311978[43] = 0;
   out_285810453574311978[44] = 0;
   out_285810453574311978[45] = 0;
   out_285810453574311978[46] = 0;
   out_285810453574311978[47] = 0;
   out_285810453574311978[48] = 1;
   out_285810453574311978[49] = 0;
   out_285810453574311978[50] = 0;
   out_285810453574311978[51] = 0;
   out_285810453574311978[52] = 0;
   out_285810453574311978[53] = 0;
   out_285810453574311978[54] = 0;
   out_285810453574311978[55] = 0;
   out_285810453574311978[56] = 0;
   out_285810453574311978[57] = 0;
   out_285810453574311978[58] = 0;
   out_285810453574311978[59] = 0;
   out_285810453574311978[60] = 1;
   out_285810453574311978[61] = 0;
   out_285810453574311978[62] = 0;
   out_285810453574311978[63] = 0;
   out_285810453574311978[64] = 0;
   out_285810453574311978[65] = 0;
   out_285810453574311978[66] = 0;
   out_285810453574311978[67] = 0;
   out_285810453574311978[68] = 0;
   out_285810453574311978[69] = 0;
   out_285810453574311978[70] = 0;
   out_285810453574311978[71] = 0;
   out_285810453574311978[72] = 1;
   out_285810453574311978[73] = dt;
   out_285810453574311978[74] = 0;
   out_285810453574311978[75] = 0;
   out_285810453574311978[76] = 0;
   out_285810453574311978[77] = 0;
   out_285810453574311978[78] = 0;
   out_285810453574311978[79] = 0;
   out_285810453574311978[80] = 0;
   out_285810453574311978[81] = 0;
   out_285810453574311978[82] = 0;
   out_285810453574311978[83] = 0;
   out_285810453574311978[84] = 1;
   out_285810453574311978[85] = dt;
   out_285810453574311978[86] = 0;
   out_285810453574311978[87] = 0;
   out_285810453574311978[88] = 0;
   out_285810453574311978[89] = 0;
   out_285810453574311978[90] = 0;
   out_285810453574311978[91] = 0;
   out_285810453574311978[92] = 0;
   out_285810453574311978[93] = 0;
   out_285810453574311978[94] = 0;
   out_285810453574311978[95] = 0;
   out_285810453574311978[96] = 1;
   out_285810453574311978[97] = 0;
   out_285810453574311978[98] = 0;
   out_285810453574311978[99] = 0;
   out_285810453574311978[100] = 0;
   out_285810453574311978[101] = 0;
   out_285810453574311978[102] = 0;
   out_285810453574311978[103] = 0;
   out_285810453574311978[104] = 0;
   out_285810453574311978[105] = 0;
   out_285810453574311978[106] = 0;
   out_285810453574311978[107] = 0;
   out_285810453574311978[108] = 1;
   out_285810453574311978[109] = 0;
   out_285810453574311978[110] = 0;
   out_285810453574311978[111] = 0;
   out_285810453574311978[112] = 0;
   out_285810453574311978[113] = 0;
   out_285810453574311978[114] = 0;
   out_285810453574311978[115] = 0;
   out_285810453574311978[116] = 0;
   out_285810453574311978[117] = 0;
   out_285810453574311978[118] = 0;
   out_285810453574311978[119] = 0;
   out_285810453574311978[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_4260298364022558171) {
   out_4260298364022558171[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_8167589833904039300) {
   out_8167589833904039300[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8167589833904039300[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8167589833904039300[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8167589833904039300[3] = 0;
   out_8167589833904039300[4] = 0;
   out_8167589833904039300[5] = 0;
   out_8167589833904039300[6] = 1;
   out_8167589833904039300[7] = 0;
   out_8167589833904039300[8] = 0;
   out_8167589833904039300[9] = 0;
   out_8167589833904039300[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_3277277287931894451) {
   out_3277277287931894451[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_7951946710659046603) {
   out_7951946710659046603[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7951946710659046603[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7951946710659046603[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7951946710659046603[3] = 0;
   out_7951946710659046603[4] = 0;
   out_7951946710659046603[5] = 0;
   out_7951946710659046603[6] = 1;
   out_7951946710659046603[7] = 0;
   out_7951946710659046603[8] = 0;
   out_7951946710659046603[9] = 1;
   out_7951946710659046603[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_1118653479581001871) {
   out_1118653479581001871[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_390583059234594540) {
   out_390583059234594540[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[6] = 0;
   out_390583059234594540[7] = 1;
   out_390583059234594540[8] = 0;
   out_390583059234594540[9] = 0;
   out_390583059234594540[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_1118653479581001871) {
   out_1118653479581001871[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_390583059234594540) {
   out_390583059234594540[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_390583059234594540[6] = 0;
   out_390583059234594540[7] = 1;
   out_390583059234594540[8] = 0;
   out_390583059234594540[9] = 0;
   out_390583059234594540[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4464393586256638428) {
  err_fun(nom_x, delta_x, out_4464393586256638428);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_8030080671851608904) {
  inv_err_fun(nom_x, true_x, out_8030080671851608904);
}
void gnss_H_mod_fun(double *state, double *out_8251410735794788719) {
  H_mod_fun(state, out_8251410735794788719);
}
void gnss_f_fun(double *state, double dt, double *out_5670922108486976517) {
  f_fun(state,  dt, out_5670922108486976517);
}
void gnss_F_fun(double *state, double dt, double *out_285810453574311978) {
  F_fun(state,  dt, out_285810453574311978);
}
void gnss_h_6(double *state, double *sat_pos, double *out_4260298364022558171) {
  h_6(state, sat_pos, out_4260298364022558171);
}
void gnss_H_6(double *state, double *sat_pos, double *out_8167589833904039300) {
  H_6(state, sat_pos, out_8167589833904039300);
}
void gnss_h_20(double *state, double *sat_pos, double *out_3277277287931894451) {
  h_20(state, sat_pos, out_3277277287931894451);
}
void gnss_H_20(double *state, double *sat_pos, double *out_7951946710659046603) {
  H_20(state, sat_pos, out_7951946710659046603);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1118653479581001871) {
  h_7(state, sat_pos_vel, out_1118653479581001871);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_390583059234594540) {
  H_7(state, sat_pos_vel, out_390583059234594540);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1118653479581001871) {
  h_21(state, sat_pos_vel, out_1118653479581001871);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_390583059234594540) {
  H_21(state, sat_pos_vel, out_390583059234594540);
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
