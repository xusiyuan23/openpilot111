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
void err_fun(double *nom_x, double *delta_x, double *out_5270397344340919402) {
   out_5270397344340919402[0] = delta_x[0] + nom_x[0];
   out_5270397344340919402[1] = delta_x[1] + nom_x[1];
   out_5270397344340919402[2] = delta_x[2] + nom_x[2];
   out_5270397344340919402[3] = delta_x[3] + nom_x[3];
   out_5270397344340919402[4] = delta_x[4] + nom_x[4];
   out_5270397344340919402[5] = delta_x[5] + nom_x[5];
   out_5270397344340919402[6] = delta_x[6] + nom_x[6];
   out_5270397344340919402[7] = delta_x[7] + nom_x[7];
   out_5270397344340919402[8] = delta_x[8] + nom_x[8];
   out_5270397344340919402[9] = delta_x[9] + nom_x[9];
   out_5270397344340919402[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1512259161409062554) {
   out_1512259161409062554[0] = -nom_x[0] + true_x[0];
   out_1512259161409062554[1] = -nom_x[1] + true_x[1];
   out_1512259161409062554[2] = -nom_x[2] + true_x[2];
   out_1512259161409062554[3] = -nom_x[3] + true_x[3];
   out_1512259161409062554[4] = -nom_x[4] + true_x[4];
   out_1512259161409062554[5] = -nom_x[5] + true_x[5];
   out_1512259161409062554[6] = -nom_x[6] + true_x[6];
   out_1512259161409062554[7] = -nom_x[7] + true_x[7];
   out_1512259161409062554[8] = -nom_x[8] + true_x[8];
   out_1512259161409062554[9] = -nom_x[9] + true_x[9];
   out_1512259161409062554[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_8413937430488034064) {
   out_8413937430488034064[0] = 1.0;
   out_8413937430488034064[1] = 0;
   out_8413937430488034064[2] = 0;
   out_8413937430488034064[3] = 0;
   out_8413937430488034064[4] = 0;
   out_8413937430488034064[5] = 0;
   out_8413937430488034064[6] = 0;
   out_8413937430488034064[7] = 0;
   out_8413937430488034064[8] = 0;
   out_8413937430488034064[9] = 0;
   out_8413937430488034064[10] = 0;
   out_8413937430488034064[11] = 0;
   out_8413937430488034064[12] = 1.0;
   out_8413937430488034064[13] = 0;
   out_8413937430488034064[14] = 0;
   out_8413937430488034064[15] = 0;
   out_8413937430488034064[16] = 0;
   out_8413937430488034064[17] = 0;
   out_8413937430488034064[18] = 0;
   out_8413937430488034064[19] = 0;
   out_8413937430488034064[20] = 0;
   out_8413937430488034064[21] = 0;
   out_8413937430488034064[22] = 0;
   out_8413937430488034064[23] = 0;
   out_8413937430488034064[24] = 1.0;
   out_8413937430488034064[25] = 0;
   out_8413937430488034064[26] = 0;
   out_8413937430488034064[27] = 0;
   out_8413937430488034064[28] = 0;
   out_8413937430488034064[29] = 0;
   out_8413937430488034064[30] = 0;
   out_8413937430488034064[31] = 0;
   out_8413937430488034064[32] = 0;
   out_8413937430488034064[33] = 0;
   out_8413937430488034064[34] = 0;
   out_8413937430488034064[35] = 0;
   out_8413937430488034064[36] = 1.0;
   out_8413937430488034064[37] = 0;
   out_8413937430488034064[38] = 0;
   out_8413937430488034064[39] = 0;
   out_8413937430488034064[40] = 0;
   out_8413937430488034064[41] = 0;
   out_8413937430488034064[42] = 0;
   out_8413937430488034064[43] = 0;
   out_8413937430488034064[44] = 0;
   out_8413937430488034064[45] = 0;
   out_8413937430488034064[46] = 0;
   out_8413937430488034064[47] = 0;
   out_8413937430488034064[48] = 1.0;
   out_8413937430488034064[49] = 0;
   out_8413937430488034064[50] = 0;
   out_8413937430488034064[51] = 0;
   out_8413937430488034064[52] = 0;
   out_8413937430488034064[53] = 0;
   out_8413937430488034064[54] = 0;
   out_8413937430488034064[55] = 0;
   out_8413937430488034064[56] = 0;
   out_8413937430488034064[57] = 0;
   out_8413937430488034064[58] = 0;
   out_8413937430488034064[59] = 0;
   out_8413937430488034064[60] = 1.0;
   out_8413937430488034064[61] = 0;
   out_8413937430488034064[62] = 0;
   out_8413937430488034064[63] = 0;
   out_8413937430488034064[64] = 0;
   out_8413937430488034064[65] = 0;
   out_8413937430488034064[66] = 0;
   out_8413937430488034064[67] = 0;
   out_8413937430488034064[68] = 0;
   out_8413937430488034064[69] = 0;
   out_8413937430488034064[70] = 0;
   out_8413937430488034064[71] = 0;
   out_8413937430488034064[72] = 1.0;
   out_8413937430488034064[73] = 0;
   out_8413937430488034064[74] = 0;
   out_8413937430488034064[75] = 0;
   out_8413937430488034064[76] = 0;
   out_8413937430488034064[77] = 0;
   out_8413937430488034064[78] = 0;
   out_8413937430488034064[79] = 0;
   out_8413937430488034064[80] = 0;
   out_8413937430488034064[81] = 0;
   out_8413937430488034064[82] = 0;
   out_8413937430488034064[83] = 0;
   out_8413937430488034064[84] = 1.0;
   out_8413937430488034064[85] = 0;
   out_8413937430488034064[86] = 0;
   out_8413937430488034064[87] = 0;
   out_8413937430488034064[88] = 0;
   out_8413937430488034064[89] = 0;
   out_8413937430488034064[90] = 0;
   out_8413937430488034064[91] = 0;
   out_8413937430488034064[92] = 0;
   out_8413937430488034064[93] = 0;
   out_8413937430488034064[94] = 0;
   out_8413937430488034064[95] = 0;
   out_8413937430488034064[96] = 1.0;
   out_8413937430488034064[97] = 0;
   out_8413937430488034064[98] = 0;
   out_8413937430488034064[99] = 0;
   out_8413937430488034064[100] = 0;
   out_8413937430488034064[101] = 0;
   out_8413937430488034064[102] = 0;
   out_8413937430488034064[103] = 0;
   out_8413937430488034064[104] = 0;
   out_8413937430488034064[105] = 0;
   out_8413937430488034064[106] = 0;
   out_8413937430488034064[107] = 0;
   out_8413937430488034064[108] = 1.0;
   out_8413937430488034064[109] = 0;
   out_8413937430488034064[110] = 0;
   out_8413937430488034064[111] = 0;
   out_8413937430488034064[112] = 0;
   out_8413937430488034064[113] = 0;
   out_8413937430488034064[114] = 0;
   out_8413937430488034064[115] = 0;
   out_8413937430488034064[116] = 0;
   out_8413937430488034064[117] = 0;
   out_8413937430488034064[118] = 0;
   out_8413937430488034064[119] = 0;
   out_8413937430488034064[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_8044790491496694058) {
   out_8044790491496694058[0] = dt*state[3] + state[0];
   out_8044790491496694058[1] = dt*state[4] + state[1];
   out_8044790491496694058[2] = dt*state[5] + state[2];
   out_8044790491496694058[3] = state[3];
   out_8044790491496694058[4] = state[4];
   out_8044790491496694058[5] = state[5];
   out_8044790491496694058[6] = dt*state[7] + state[6];
   out_8044790491496694058[7] = dt*state[8] + state[7];
   out_8044790491496694058[8] = state[8];
   out_8044790491496694058[9] = state[9];
   out_8044790491496694058[10] = state[10];
}
void F_fun(double *state, double dt, double *out_7107643139068643538) {
   out_7107643139068643538[0] = 1;
   out_7107643139068643538[1] = 0;
   out_7107643139068643538[2] = 0;
   out_7107643139068643538[3] = dt;
   out_7107643139068643538[4] = 0;
   out_7107643139068643538[5] = 0;
   out_7107643139068643538[6] = 0;
   out_7107643139068643538[7] = 0;
   out_7107643139068643538[8] = 0;
   out_7107643139068643538[9] = 0;
   out_7107643139068643538[10] = 0;
   out_7107643139068643538[11] = 0;
   out_7107643139068643538[12] = 1;
   out_7107643139068643538[13] = 0;
   out_7107643139068643538[14] = 0;
   out_7107643139068643538[15] = dt;
   out_7107643139068643538[16] = 0;
   out_7107643139068643538[17] = 0;
   out_7107643139068643538[18] = 0;
   out_7107643139068643538[19] = 0;
   out_7107643139068643538[20] = 0;
   out_7107643139068643538[21] = 0;
   out_7107643139068643538[22] = 0;
   out_7107643139068643538[23] = 0;
   out_7107643139068643538[24] = 1;
   out_7107643139068643538[25] = 0;
   out_7107643139068643538[26] = 0;
   out_7107643139068643538[27] = dt;
   out_7107643139068643538[28] = 0;
   out_7107643139068643538[29] = 0;
   out_7107643139068643538[30] = 0;
   out_7107643139068643538[31] = 0;
   out_7107643139068643538[32] = 0;
   out_7107643139068643538[33] = 0;
   out_7107643139068643538[34] = 0;
   out_7107643139068643538[35] = 0;
   out_7107643139068643538[36] = 1;
   out_7107643139068643538[37] = 0;
   out_7107643139068643538[38] = 0;
   out_7107643139068643538[39] = 0;
   out_7107643139068643538[40] = 0;
   out_7107643139068643538[41] = 0;
   out_7107643139068643538[42] = 0;
   out_7107643139068643538[43] = 0;
   out_7107643139068643538[44] = 0;
   out_7107643139068643538[45] = 0;
   out_7107643139068643538[46] = 0;
   out_7107643139068643538[47] = 0;
   out_7107643139068643538[48] = 1;
   out_7107643139068643538[49] = 0;
   out_7107643139068643538[50] = 0;
   out_7107643139068643538[51] = 0;
   out_7107643139068643538[52] = 0;
   out_7107643139068643538[53] = 0;
   out_7107643139068643538[54] = 0;
   out_7107643139068643538[55] = 0;
   out_7107643139068643538[56] = 0;
   out_7107643139068643538[57] = 0;
   out_7107643139068643538[58] = 0;
   out_7107643139068643538[59] = 0;
   out_7107643139068643538[60] = 1;
   out_7107643139068643538[61] = 0;
   out_7107643139068643538[62] = 0;
   out_7107643139068643538[63] = 0;
   out_7107643139068643538[64] = 0;
   out_7107643139068643538[65] = 0;
   out_7107643139068643538[66] = 0;
   out_7107643139068643538[67] = 0;
   out_7107643139068643538[68] = 0;
   out_7107643139068643538[69] = 0;
   out_7107643139068643538[70] = 0;
   out_7107643139068643538[71] = 0;
   out_7107643139068643538[72] = 1;
   out_7107643139068643538[73] = dt;
   out_7107643139068643538[74] = 0;
   out_7107643139068643538[75] = 0;
   out_7107643139068643538[76] = 0;
   out_7107643139068643538[77] = 0;
   out_7107643139068643538[78] = 0;
   out_7107643139068643538[79] = 0;
   out_7107643139068643538[80] = 0;
   out_7107643139068643538[81] = 0;
   out_7107643139068643538[82] = 0;
   out_7107643139068643538[83] = 0;
   out_7107643139068643538[84] = 1;
   out_7107643139068643538[85] = dt;
   out_7107643139068643538[86] = 0;
   out_7107643139068643538[87] = 0;
   out_7107643139068643538[88] = 0;
   out_7107643139068643538[89] = 0;
   out_7107643139068643538[90] = 0;
   out_7107643139068643538[91] = 0;
   out_7107643139068643538[92] = 0;
   out_7107643139068643538[93] = 0;
   out_7107643139068643538[94] = 0;
   out_7107643139068643538[95] = 0;
   out_7107643139068643538[96] = 1;
   out_7107643139068643538[97] = 0;
   out_7107643139068643538[98] = 0;
   out_7107643139068643538[99] = 0;
   out_7107643139068643538[100] = 0;
   out_7107643139068643538[101] = 0;
   out_7107643139068643538[102] = 0;
   out_7107643139068643538[103] = 0;
   out_7107643139068643538[104] = 0;
   out_7107643139068643538[105] = 0;
   out_7107643139068643538[106] = 0;
   out_7107643139068643538[107] = 0;
   out_7107643139068643538[108] = 1;
   out_7107643139068643538[109] = 0;
   out_7107643139068643538[110] = 0;
   out_7107643139068643538[111] = 0;
   out_7107643139068643538[112] = 0;
   out_7107643139068643538[113] = 0;
   out_7107643139068643538[114] = 0;
   out_7107643139068643538[115] = 0;
   out_7107643139068643538[116] = 0;
   out_7107643139068643538[117] = 0;
   out_7107643139068643538[118] = 0;
   out_7107643139068643538[119] = 0;
   out_7107643139068643538[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_1014783744438669605) {
   out_1014783744438669605[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_2647892629803094557) {
   out_2647892629803094557[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2647892629803094557[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2647892629803094557[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2647892629803094557[3] = 0;
   out_2647892629803094557[4] = 0;
   out_2647892629803094557[5] = 0;
   out_2647892629803094557[6] = 1;
   out_2647892629803094557[7] = 0;
   out_2647892629803094557[8] = 0;
   out_2647892629803094557[9] = 0;
   out_2647892629803094557[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_4446463785726682298) {
   out_4446463785726682298[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_2058835805956563056) {
   out_2058835805956563056[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2058835805956563056[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2058835805956563056[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2058835805956563056[3] = 0;
   out_2058835805956563056[4] = 0;
   out_2058835805956563056[5] = 0;
   out_2058835805956563056[6] = 1;
   out_2058835805956563056[7] = 0;
   out_2058835805956563056[8] = 0;
   out_2058835805956563056[9] = 1;
   out_2058835805956563056[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_6977013047509885177) {
   out_6977013047509885177[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_3396370189700754510) {
   out_3396370189700754510[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[6] = 0;
   out_3396370189700754510[7] = 1;
   out_3396370189700754510[8] = 0;
   out_3396370189700754510[9] = 0;
   out_3396370189700754510[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_6977013047509885177) {
   out_6977013047509885177[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_3396370189700754510) {
   out_3396370189700754510[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3396370189700754510[6] = 0;
   out_3396370189700754510[7] = 1;
   out_3396370189700754510[8] = 0;
   out_3396370189700754510[9] = 0;
   out_3396370189700754510[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_5270397344340919402) {
  err_fun(nom_x, delta_x, out_5270397344340919402);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_1512259161409062554) {
  inv_err_fun(nom_x, true_x, out_1512259161409062554);
}
void gnss_H_mod_fun(double *state, double *out_8413937430488034064) {
  H_mod_fun(state, out_8413937430488034064);
}
void gnss_f_fun(double *state, double dt, double *out_8044790491496694058) {
  f_fun(state,  dt, out_8044790491496694058);
}
void gnss_F_fun(double *state, double dt, double *out_7107643139068643538) {
  F_fun(state,  dt, out_7107643139068643538);
}
void gnss_h_6(double *state, double *sat_pos, double *out_1014783744438669605) {
  h_6(state, sat_pos, out_1014783744438669605);
}
void gnss_H_6(double *state, double *sat_pos, double *out_2647892629803094557) {
  H_6(state, sat_pos, out_2647892629803094557);
}
void gnss_h_20(double *state, double *sat_pos, double *out_4446463785726682298) {
  h_20(state, sat_pos, out_4446463785726682298);
}
void gnss_H_20(double *state, double *sat_pos, double *out_2058835805956563056) {
  H_20(state, sat_pos, out_2058835805956563056);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6977013047509885177) {
  h_7(state, sat_pos_vel, out_6977013047509885177);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3396370189700754510) {
  H_7(state, sat_pos_vel, out_3396370189700754510);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6977013047509885177) {
  h_21(state, sat_pos_vel, out_6977013047509885177);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3396370189700754510) {
  H_21(state, sat_pos_vel, out_3396370189700754510);
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
