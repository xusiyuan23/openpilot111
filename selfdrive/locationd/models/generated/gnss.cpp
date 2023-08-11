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
void err_fun(double *nom_x, double *delta_x, double *out_2067482950567323166) {
   out_2067482950567323166[0] = delta_x[0] + nom_x[0];
   out_2067482950567323166[1] = delta_x[1] + nom_x[1];
   out_2067482950567323166[2] = delta_x[2] + nom_x[2];
   out_2067482950567323166[3] = delta_x[3] + nom_x[3];
   out_2067482950567323166[4] = delta_x[4] + nom_x[4];
   out_2067482950567323166[5] = delta_x[5] + nom_x[5];
   out_2067482950567323166[6] = delta_x[6] + nom_x[6];
   out_2067482950567323166[7] = delta_x[7] + nom_x[7];
   out_2067482950567323166[8] = delta_x[8] + nom_x[8];
   out_2067482950567323166[9] = delta_x[9] + nom_x[9];
   out_2067482950567323166[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2603530649313476471) {
   out_2603530649313476471[0] = -nom_x[0] + true_x[0];
   out_2603530649313476471[1] = -nom_x[1] + true_x[1];
   out_2603530649313476471[2] = -nom_x[2] + true_x[2];
   out_2603530649313476471[3] = -nom_x[3] + true_x[3];
   out_2603530649313476471[4] = -nom_x[4] + true_x[4];
   out_2603530649313476471[5] = -nom_x[5] + true_x[5];
   out_2603530649313476471[6] = -nom_x[6] + true_x[6];
   out_2603530649313476471[7] = -nom_x[7] + true_x[7];
   out_2603530649313476471[8] = -nom_x[8] + true_x[8];
   out_2603530649313476471[9] = -nom_x[9] + true_x[9];
   out_2603530649313476471[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_5820927568950649229) {
   out_5820927568950649229[0] = 1.0;
   out_5820927568950649229[1] = 0;
   out_5820927568950649229[2] = 0;
   out_5820927568950649229[3] = 0;
   out_5820927568950649229[4] = 0;
   out_5820927568950649229[5] = 0;
   out_5820927568950649229[6] = 0;
   out_5820927568950649229[7] = 0;
   out_5820927568950649229[8] = 0;
   out_5820927568950649229[9] = 0;
   out_5820927568950649229[10] = 0;
   out_5820927568950649229[11] = 0;
   out_5820927568950649229[12] = 1.0;
   out_5820927568950649229[13] = 0;
   out_5820927568950649229[14] = 0;
   out_5820927568950649229[15] = 0;
   out_5820927568950649229[16] = 0;
   out_5820927568950649229[17] = 0;
   out_5820927568950649229[18] = 0;
   out_5820927568950649229[19] = 0;
   out_5820927568950649229[20] = 0;
   out_5820927568950649229[21] = 0;
   out_5820927568950649229[22] = 0;
   out_5820927568950649229[23] = 0;
   out_5820927568950649229[24] = 1.0;
   out_5820927568950649229[25] = 0;
   out_5820927568950649229[26] = 0;
   out_5820927568950649229[27] = 0;
   out_5820927568950649229[28] = 0;
   out_5820927568950649229[29] = 0;
   out_5820927568950649229[30] = 0;
   out_5820927568950649229[31] = 0;
   out_5820927568950649229[32] = 0;
   out_5820927568950649229[33] = 0;
   out_5820927568950649229[34] = 0;
   out_5820927568950649229[35] = 0;
   out_5820927568950649229[36] = 1.0;
   out_5820927568950649229[37] = 0;
   out_5820927568950649229[38] = 0;
   out_5820927568950649229[39] = 0;
   out_5820927568950649229[40] = 0;
   out_5820927568950649229[41] = 0;
   out_5820927568950649229[42] = 0;
   out_5820927568950649229[43] = 0;
   out_5820927568950649229[44] = 0;
   out_5820927568950649229[45] = 0;
   out_5820927568950649229[46] = 0;
   out_5820927568950649229[47] = 0;
   out_5820927568950649229[48] = 1.0;
   out_5820927568950649229[49] = 0;
   out_5820927568950649229[50] = 0;
   out_5820927568950649229[51] = 0;
   out_5820927568950649229[52] = 0;
   out_5820927568950649229[53] = 0;
   out_5820927568950649229[54] = 0;
   out_5820927568950649229[55] = 0;
   out_5820927568950649229[56] = 0;
   out_5820927568950649229[57] = 0;
   out_5820927568950649229[58] = 0;
   out_5820927568950649229[59] = 0;
   out_5820927568950649229[60] = 1.0;
   out_5820927568950649229[61] = 0;
   out_5820927568950649229[62] = 0;
   out_5820927568950649229[63] = 0;
   out_5820927568950649229[64] = 0;
   out_5820927568950649229[65] = 0;
   out_5820927568950649229[66] = 0;
   out_5820927568950649229[67] = 0;
   out_5820927568950649229[68] = 0;
   out_5820927568950649229[69] = 0;
   out_5820927568950649229[70] = 0;
   out_5820927568950649229[71] = 0;
   out_5820927568950649229[72] = 1.0;
   out_5820927568950649229[73] = 0;
   out_5820927568950649229[74] = 0;
   out_5820927568950649229[75] = 0;
   out_5820927568950649229[76] = 0;
   out_5820927568950649229[77] = 0;
   out_5820927568950649229[78] = 0;
   out_5820927568950649229[79] = 0;
   out_5820927568950649229[80] = 0;
   out_5820927568950649229[81] = 0;
   out_5820927568950649229[82] = 0;
   out_5820927568950649229[83] = 0;
   out_5820927568950649229[84] = 1.0;
   out_5820927568950649229[85] = 0;
   out_5820927568950649229[86] = 0;
   out_5820927568950649229[87] = 0;
   out_5820927568950649229[88] = 0;
   out_5820927568950649229[89] = 0;
   out_5820927568950649229[90] = 0;
   out_5820927568950649229[91] = 0;
   out_5820927568950649229[92] = 0;
   out_5820927568950649229[93] = 0;
   out_5820927568950649229[94] = 0;
   out_5820927568950649229[95] = 0;
   out_5820927568950649229[96] = 1.0;
   out_5820927568950649229[97] = 0;
   out_5820927568950649229[98] = 0;
   out_5820927568950649229[99] = 0;
   out_5820927568950649229[100] = 0;
   out_5820927568950649229[101] = 0;
   out_5820927568950649229[102] = 0;
   out_5820927568950649229[103] = 0;
   out_5820927568950649229[104] = 0;
   out_5820927568950649229[105] = 0;
   out_5820927568950649229[106] = 0;
   out_5820927568950649229[107] = 0;
   out_5820927568950649229[108] = 1.0;
   out_5820927568950649229[109] = 0;
   out_5820927568950649229[110] = 0;
   out_5820927568950649229[111] = 0;
   out_5820927568950649229[112] = 0;
   out_5820927568950649229[113] = 0;
   out_5820927568950649229[114] = 0;
   out_5820927568950649229[115] = 0;
   out_5820927568950649229[116] = 0;
   out_5820927568950649229[117] = 0;
   out_5820927568950649229[118] = 0;
   out_5820927568950649229[119] = 0;
   out_5820927568950649229[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_17551380326686977) {
   out_17551380326686977[0] = dt*state[3] + state[0];
   out_17551380326686977[1] = dt*state[4] + state[1];
   out_17551380326686977[2] = dt*state[5] + state[2];
   out_17551380326686977[3] = state[3];
   out_17551380326686977[4] = state[4];
   out_17551380326686977[5] = state[5];
   out_17551380326686977[6] = dt*state[7] + state[6];
   out_17551380326686977[7] = dt*state[8] + state[7];
   out_17551380326686977[8] = state[8];
   out_17551380326686977[9] = state[9];
   out_17551380326686977[10] = state[10];
}
void F_fun(double *state, double dt, double *out_414838326010165834) {
   out_414838326010165834[0] = 1;
   out_414838326010165834[1] = 0;
   out_414838326010165834[2] = 0;
   out_414838326010165834[3] = dt;
   out_414838326010165834[4] = 0;
   out_414838326010165834[5] = 0;
   out_414838326010165834[6] = 0;
   out_414838326010165834[7] = 0;
   out_414838326010165834[8] = 0;
   out_414838326010165834[9] = 0;
   out_414838326010165834[10] = 0;
   out_414838326010165834[11] = 0;
   out_414838326010165834[12] = 1;
   out_414838326010165834[13] = 0;
   out_414838326010165834[14] = 0;
   out_414838326010165834[15] = dt;
   out_414838326010165834[16] = 0;
   out_414838326010165834[17] = 0;
   out_414838326010165834[18] = 0;
   out_414838326010165834[19] = 0;
   out_414838326010165834[20] = 0;
   out_414838326010165834[21] = 0;
   out_414838326010165834[22] = 0;
   out_414838326010165834[23] = 0;
   out_414838326010165834[24] = 1;
   out_414838326010165834[25] = 0;
   out_414838326010165834[26] = 0;
   out_414838326010165834[27] = dt;
   out_414838326010165834[28] = 0;
   out_414838326010165834[29] = 0;
   out_414838326010165834[30] = 0;
   out_414838326010165834[31] = 0;
   out_414838326010165834[32] = 0;
   out_414838326010165834[33] = 0;
   out_414838326010165834[34] = 0;
   out_414838326010165834[35] = 0;
   out_414838326010165834[36] = 1;
   out_414838326010165834[37] = 0;
   out_414838326010165834[38] = 0;
   out_414838326010165834[39] = 0;
   out_414838326010165834[40] = 0;
   out_414838326010165834[41] = 0;
   out_414838326010165834[42] = 0;
   out_414838326010165834[43] = 0;
   out_414838326010165834[44] = 0;
   out_414838326010165834[45] = 0;
   out_414838326010165834[46] = 0;
   out_414838326010165834[47] = 0;
   out_414838326010165834[48] = 1;
   out_414838326010165834[49] = 0;
   out_414838326010165834[50] = 0;
   out_414838326010165834[51] = 0;
   out_414838326010165834[52] = 0;
   out_414838326010165834[53] = 0;
   out_414838326010165834[54] = 0;
   out_414838326010165834[55] = 0;
   out_414838326010165834[56] = 0;
   out_414838326010165834[57] = 0;
   out_414838326010165834[58] = 0;
   out_414838326010165834[59] = 0;
   out_414838326010165834[60] = 1;
   out_414838326010165834[61] = 0;
   out_414838326010165834[62] = 0;
   out_414838326010165834[63] = 0;
   out_414838326010165834[64] = 0;
   out_414838326010165834[65] = 0;
   out_414838326010165834[66] = 0;
   out_414838326010165834[67] = 0;
   out_414838326010165834[68] = 0;
   out_414838326010165834[69] = 0;
   out_414838326010165834[70] = 0;
   out_414838326010165834[71] = 0;
   out_414838326010165834[72] = 1;
   out_414838326010165834[73] = dt;
   out_414838326010165834[74] = 0;
   out_414838326010165834[75] = 0;
   out_414838326010165834[76] = 0;
   out_414838326010165834[77] = 0;
   out_414838326010165834[78] = 0;
   out_414838326010165834[79] = 0;
   out_414838326010165834[80] = 0;
   out_414838326010165834[81] = 0;
   out_414838326010165834[82] = 0;
   out_414838326010165834[83] = 0;
   out_414838326010165834[84] = 1;
   out_414838326010165834[85] = dt;
   out_414838326010165834[86] = 0;
   out_414838326010165834[87] = 0;
   out_414838326010165834[88] = 0;
   out_414838326010165834[89] = 0;
   out_414838326010165834[90] = 0;
   out_414838326010165834[91] = 0;
   out_414838326010165834[92] = 0;
   out_414838326010165834[93] = 0;
   out_414838326010165834[94] = 0;
   out_414838326010165834[95] = 0;
   out_414838326010165834[96] = 1;
   out_414838326010165834[97] = 0;
   out_414838326010165834[98] = 0;
   out_414838326010165834[99] = 0;
   out_414838326010165834[100] = 0;
   out_414838326010165834[101] = 0;
   out_414838326010165834[102] = 0;
   out_414838326010165834[103] = 0;
   out_414838326010165834[104] = 0;
   out_414838326010165834[105] = 0;
   out_414838326010165834[106] = 0;
   out_414838326010165834[107] = 0;
   out_414838326010165834[108] = 1;
   out_414838326010165834[109] = 0;
   out_414838326010165834[110] = 0;
   out_414838326010165834[111] = 0;
   out_414838326010165834[112] = 0;
   out_414838326010165834[113] = 0;
   out_414838326010165834[114] = 0;
   out_414838326010165834[115] = 0;
   out_414838326010165834[116] = 0;
   out_414838326010165834[117] = 0;
   out_414838326010165834[118] = 0;
   out_414838326010165834[119] = 0;
   out_414838326010165834[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_9074704291738973277) {
   out_9074704291738973277[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_8056400913830408537) {
   out_8056400913830408537[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8056400913830408537[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8056400913830408537[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8056400913830408537[3] = 0;
   out_8056400913830408537[4] = 0;
   out_8056400913830408537[5] = 0;
   out_8056400913830408537[6] = 1;
   out_8056400913830408537[7] = 0;
   out_8056400913830408537[8] = 0;
   out_8056400913830408537[9] = 0;
   out_8056400913830408537[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_5771271505288635021) {
   out_5771271505288635021[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_5454875328892457956) {
   out_5454875328892457956[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5454875328892457956[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5454875328892457956[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5454875328892457956[3] = 0;
   out_5454875328892457956[4] = 0;
   out_5454875328892457956[5] = 0;
   out_5454875328892457956[6] = 1;
   out_5454875328892457956[7] = 0;
   out_5454875328892457956[8] = 0;
   out_5454875328892457956[9] = 1;
   out_5454875328892457956[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_5412429359018771727) {
   out_5412429359018771727[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_1987528380465191465) {
   out_1987528380465191465[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[6] = 0;
   out_1987528380465191465[7] = 1;
   out_1987528380465191465[8] = 0;
   out_1987528380465191465[9] = 0;
   out_1987528380465191465[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_5412429359018771727) {
   out_5412429359018771727[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_1987528380465191465) {
   out_1987528380465191465[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1987528380465191465[6] = 0;
   out_1987528380465191465[7] = 1;
   out_1987528380465191465[8] = 0;
   out_1987528380465191465[9] = 0;
   out_1987528380465191465[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2067482950567323166) {
  err_fun(nom_x, delta_x, out_2067482950567323166);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_2603530649313476471) {
  inv_err_fun(nom_x, true_x, out_2603530649313476471);
}
void gnss_H_mod_fun(double *state, double *out_5820927568950649229) {
  H_mod_fun(state, out_5820927568950649229);
}
void gnss_f_fun(double *state, double dt, double *out_17551380326686977) {
  f_fun(state,  dt, out_17551380326686977);
}
void gnss_F_fun(double *state, double dt, double *out_414838326010165834) {
  F_fun(state,  dt, out_414838326010165834);
}
void gnss_h_6(double *state, double *sat_pos, double *out_9074704291738973277) {
  h_6(state, sat_pos, out_9074704291738973277);
}
void gnss_H_6(double *state, double *sat_pos, double *out_8056400913830408537) {
  H_6(state, sat_pos, out_8056400913830408537);
}
void gnss_h_20(double *state, double *sat_pos, double *out_5771271505288635021) {
  h_20(state, sat_pos, out_5771271505288635021);
}
void gnss_H_20(double *state, double *sat_pos, double *out_5454875328892457956) {
  H_20(state, sat_pos, out_5454875328892457956);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_5412429359018771727) {
  h_7(state, sat_pos_vel, out_5412429359018771727);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1987528380465191465) {
  H_7(state, sat_pos_vel, out_1987528380465191465);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_5412429359018771727) {
  h_21(state, sat_pos_vel, out_5412429359018771727);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1987528380465191465) {
  H_21(state, sat_pos_vel, out_1987528380465191465);
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
