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
 *                      Code generated with SymPy 1.10.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4766384142186770465) {
   out_4766384142186770465[0] = delta_x[0] + nom_x[0];
   out_4766384142186770465[1] = delta_x[1] + nom_x[1];
   out_4766384142186770465[2] = delta_x[2] + nom_x[2];
   out_4766384142186770465[3] = delta_x[3] + nom_x[3];
   out_4766384142186770465[4] = delta_x[4] + nom_x[4];
   out_4766384142186770465[5] = delta_x[5] + nom_x[5];
   out_4766384142186770465[6] = delta_x[6] + nom_x[6];
   out_4766384142186770465[7] = delta_x[7] + nom_x[7];
   out_4766384142186770465[8] = delta_x[8] + nom_x[8];
   out_4766384142186770465[9] = delta_x[9] + nom_x[9];
   out_4766384142186770465[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6278544928106810662) {
   out_6278544928106810662[0] = -nom_x[0] + true_x[0];
   out_6278544928106810662[1] = -nom_x[1] + true_x[1];
   out_6278544928106810662[2] = -nom_x[2] + true_x[2];
   out_6278544928106810662[3] = -nom_x[3] + true_x[3];
   out_6278544928106810662[4] = -nom_x[4] + true_x[4];
   out_6278544928106810662[5] = -nom_x[5] + true_x[5];
   out_6278544928106810662[6] = -nom_x[6] + true_x[6];
   out_6278544928106810662[7] = -nom_x[7] + true_x[7];
   out_6278544928106810662[8] = -nom_x[8] + true_x[8];
   out_6278544928106810662[9] = -nom_x[9] + true_x[9];
   out_6278544928106810662[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_8097412979060097308) {
   out_8097412979060097308[0] = 1.0;
   out_8097412979060097308[1] = 0;
   out_8097412979060097308[2] = 0;
   out_8097412979060097308[3] = 0;
   out_8097412979060097308[4] = 0;
   out_8097412979060097308[5] = 0;
   out_8097412979060097308[6] = 0;
   out_8097412979060097308[7] = 0;
   out_8097412979060097308[8] = 0;
   out_8097412979060097308[9] = 0;
   out_8097412979060097308[10] = 0;
   out_8097412979060097308[11] = 0;
   out_8097412979060097308[12] = 1.0;
   out_8097412979060097308[13] = 0;
   out_8097412979060097308[14] = 0;
   out_8097412979060097308[15] = 0;
   out_8097412979060097308[16] = 0;
   out_8097412979060097308[17] = 0;
   out_8097412979060097308[18] = 0;
   out_8097412979060097308[19] = 0;
   out_8097412979060097308[20] = 0;
   out_8097412979060097308[21] = 0;
   out_8097412979060097308[22] = 0;
   out_8097412979060097308[23] = 0;
   out_8097412979060097308[24] = 1.0;
   out_8097412979060097308[25] = 0;
   out_8097412979060097308[26] = 0;
   out_8097412979060097308[27] = 0;
   out_8097412979060097308[28] = 0;
   out_8097412979060097308[29] = 0;
   out_8097412979060097308[30] = 0;
   out_8097412979060097308[31] = 0;
   out_8097412979060097308[32] = 0;
   out_8097412979060097308[33] = 0;
   out_8097412979060097308[34] = 0;
   out_8097412979060097308[35] = 0;
   out_8097412979060097308[36] = 1.0;
   out_8097412979060097308[37] = 0;
   out_8097412979060097308[38] = 0;
   out_8097412979060097308[39] = 0;
   out_8097412979060097308[40] = 0;
   out_8097412979060097308[41] = 0;
   out_8097412979060097308[42] = 0;
   out_8097412979060097308[43] = 0;
   out_8097412979060097308[44] = 0;
   out_8097412979060097308[45] = 0;
   out_8097412979060097308[46] = 0;
   out_8097412979060097308[47] = 0;
   out_8097412979060097308[48] = 1.0;
   out_8097412979060097308[49] = 0;
   out_8097412979060097308[50] = 0;
   out_8097412979060097308[51] = 0;
   out_8097412979060097308[52] = 0;
   out_8097412979060097308[53] = 0;
   out_8097412979060097308[54] = 0;
   out_8097412979060097308[55] = 0;
   out_8097412979060097308[56] = 0;
   out_8097412979060097308[57] = 0;
   out_8097412979060097308[58] = 0;
   out_8097412979060097308[59] = 0;
   out_8097412979060097308[60] = 1.0;
   out_8097412979060097308[61] = 0;
   out_8097412979060097308[62] = 0;
   out_8097412979060097308[63] = 0;
   out_8097412979060097308[64] = 0;
   out_8097412979060097308[65] = 0;
   out_8097412979060097308[66] = 0;
   out_8097412979060097308[67] = 0;
   out_8097412979060097308[68] = 0;
   out_8097412979060097308[69] = 0;
   out_8097412979060097308[70] = 0;
   out_8097412979060097308[71] = 0;
   out_8097412979060097308[72] = 1.0;
   out_8097412979060097308[73] = 0;
   out_8097412979060097308[74] = 0;
   out_8097412979060097308[75] = 0;
   out_8097412979060097308[76] = 0;
   out_8097412979060097308[77] = 0;
   out_8097412979060097308[78] = 0;
   out_8097412979060097308[79] = 0;
   out_8097412979060097308[80] = 0;
   out_8097412979060097308[81] = 0;
   out_8097412979060097308[82] = 0;
   out_8097412979060097308[83] = 0;
   out_8097412979060097308[84] = 1.0;
   out_8097412979060097308[85] = 0;
   out_8097412979060097308[86] = 0;
   out_8097412979060097308[87] = 0;
   out_8097412979060097308[88] = 0;
   out_8097412979060097308[89] = 0;
   out_8097412979060097308[90] = 0;
   out_8097412979060097308[91] = 0;
   out_8097412979060097308[92] = 0;
   out_8097412979060097308[93] = 0;
   out_8097412979060097308[94] = 0;
   out_8097412979060097308[95] = 0;
   out_8097412979060097308[96] = 1.0;
   out_8097412979060097308[97] = 0;
   out_8097412979060097308[98] = 0;
   out_8097412979060097308[99] = 0;
   out_8097412979060097308[100] = 0;
   out_8097412979060097308[101] = 0;
   out_8097412979060097308[102] = 0;
   out_8097412979060097308[103] = 0;
   out_8097412979060097308[104] = 0;
   out_8097412979060097308[105] = 0;
   out_8097412979060097308[106] = 0;
   out_8097412979060097308[107] = 0;
   out_8097412979060097308[108] = 1.0;
   out_8097412979060097308[109] = 0;
   out_8097412979060097308[110] = 0;
   out_8097412979060097308[111] = 0;
   out_8097412979060097308[112] = 0;
   out_8097412979060097308[113] = 0;
   out_8097412979060097308[114] = 0;
   out_8097412979060097308[115] = 0;
   out_8097412979060097308[116] = 0;
   out_8097412979060097308[117] = 0;
   out_8097412979060097308[118] = 0;
   out_8097412979060097308[119] = 0;
   out_8097412979060097308[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_3104780102329770139) {
   out_3104780102329770139[0] = dt*state[3] + state[0];
   out_3104780102329770139[1] = dt*state[4] + state[1];
   out_3104780102329770139[2] = dt*state[5] + state[2];
   out_3104780102329770139[3] = state[3];
   out_3104780102329770139[4] = state[4];
   out_3104780102329770139[5] = state[5];
   out_3104780102329770139[6] = dt*state[7] + state[6];
   out_3104780102329770139[7] = dt*state[8] + state[7];
   out_3104780102329770139[8] = state[8];
   out_3104780102329770139[9] = state[9];
   out_3104780102329770139[10] = state[10];
}
void F_fun(double *state, double dt, double *out_4096543142917168482) {
   out_4096543142917168482[0] = 1;
   out_4096543142917168482[1] = 0;
   out_4096543142917168482[2] = 0;
   out_4096543142917168482[3] = dt;
   out_4096543142917168482[4] = 0;
   out_4096543142917168482[5] = 0;
   out_4096543142917168482[6] = 0;
   out_4096543142917168482[7] = 0;
   out_4096543142917168482[8] = 0;
   out_4096543142917168482[9] = 0;
   out_4096543142917168482[10] = 0;
   out_4096543142917168482[11] = 0;
   out_4096543142917168482[12] = 1;
   out_4096543142917168482[13] = 0;
   out_4096543142917168482[14] = 0;
   out_4096543142917168482[15] = dt;
   out_4096543142917168482[16] = 0;
   out_4096543142917168482[17] = 0;
   out_4096543142917168482[18] = 0;
   out_4096543142917168482[19] = 0;
   out_4096543142917168482[20] = 0;
   out_4096543142917168482[21] = 0;
   out_4096543142917168482[22] = 0;
   out_4096543142917168482[23] = 0;
   out_4096543142917168482[24] = 1;
   out_4096543142917168482[25] = 0;
   out_4096543142917168482[26] = 0;
   out_4096543142917168482[27] = dt;
   out_4096543142917168482[28] = 0;
   out_4096543142917168482[29] = 0;
   out_4096543142917168482[30] = 0;
   out_4096543142917168482[31] = 0;
   out_4096543142917168482[32] = 0;
   out_4096543142917168482[33] = 0;
   out_4096543142917168482[34] = 0;
   out_4096543142917168482[35] = 0;
   out_4096543142917168482[36] = 1;
   out_4096543142917168482[37] = 0;
   out_4096543142917168482[38] = 0;
   out_4096543142917168482[39] = 0;
   out_4096543142917168482[40] = 0;
   out_4096543142917168482[41] = 0;
   out_4096543142917168482[42] = 0;
   out_4096543142917168482[43] = 0;
   out_4096543142917168482[44] = 0;
   out_4096543142917168482[45] = 0;
   out_4096543142917168482[46] = 0;
   out_4096543142917168482[47] = 0;
   out_4096543142917168482[48] = 1;
   out_4096543142917168482[49] = 0;
   out_4096543142917168482[50] = 0;
   out_4096543142917168482[51] = 0;
   out_4096543142917168482[52] = 0;
   out_4096543142917168482[53] = 0;
   out_4096543142917168482[54] = 0;
   out_4096543142917168482[55] = 0;
   out_4096543142917168482[56] = 0;
   out_4096543142917168482[57] = 0;
   out_4096543142917168482[58] = 0;
   out_4096543142917168482[59] = 0;
   out_4096543142917168482[60] = 1;
   out_4096543142917168482[61] = 0;
   out_4096543142917168482[62] = 0;
   out_4096543142917168482[63] = 0;
   out_4096543142917168482[64] = 0;
   out_4096543142917168482[65] = 0;
   out_4096543142917168482[66] = 0;
   out_4096543142917168482[67] = 0;
   out_4096543142917168482[68] = 0;
   out_4096543142917168482[69] = 0;
   out_4096543142917168482[70] = 0;
   out_4096543142917168482[71] = 0;
   out_4096543142917168482[72] = 1;
   out_4096543142917168482[73] = dt;
   out_4096543142917168482[74] = 0;
   out_4096543142917168482[75] = 0;
   out_4096543142917168482[76] = 0;
   out_4096543142917168482[77] = 0;
   out_4096543142917168482[78] = 0;
   out_4096543142917168482[79] = 0;
   out_4096543142917168482[80] = 0;
   out_4096543142917168482[81] = 0;
   out_4096543142917168482[82] = 0;
   out_4096543142917168482[83] = 0;
   out_4096543142917168482[84] = 1;
   out_4096543142917168482[85] = dt;
   out_4096543142917168482[86] = 0;
   out_4096543142917168482[87] = 0;
   out_4096543142917168482[88] = 0;
   out_4096543142917168482[89] = 0;
   out_4096543142917168482[90] = 0;
   out_4096543142917168482[91] = 0;
   out_4096543142917168482[92] = 0;
   out_4096543142917168482[93] = 0;
   out_4096543142917168482[94] = 0;
   out_4096543142917168482[95] = 0;
   out_4096543142917168482[96] = 1;
   out_4096543142917168482[97] = 0;
   out_4096543142917168482[98] = 0;
   out_4096543142917168482[99] = 0;
   out_4096543142917168482[100] = 0;
   out_4096543142917168482[101] = 0;
   out_4096543142917168482[102] = 0;
   out_4096543142917168482[103] = 0;
   out_4096543142917168482[104] = 0;
   out_4096543142917168482[105] = 0;
   out_4096543142917168482[106] = 0;
   out_4096543142917168482[107] = 0;
   out_4096543142917168482[108] = 1;
   out_4096543142917168482[109] = 0;
   out_4096543142917168482[110] = 0;
   out_4096543142917168482[111] = 0;
   out_4096543142917168482[112] = 0;
   out_4096543142917168482[113] = 0;
   out_4096543142917168482[114] = 0;
   out_4096543142917168482[115] = 0;
   out_4096543142917168482[116] = 0;
   out_4096543142917168482[117] = 0;
   out_4096543142917168482[118] = 0;
   out_4096543142917168482[119] = 0;
   out_4096543142917168482[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_6758247131004536746) {
   out_6758247131004536746[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_4686865741220841403) {
   out_4686865741220841403[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4686865741220841403[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4686865741220841403[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4686865741220841403[3] = 0;
   out_4686865741220841403[4] = 0;
   out_4686865741220841403[5] = 0;
   out_4686865741220841403[6] = 1;
   out_4686865741220841403[7] = 0;
   out_4686865741220841403[8] = 0;
   out_4686865741220841403[9] = 0;
   out_4686865741220841403[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_421409222323252481) {
   out_421409222323252481[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_4448074927986596639) {
   out_4448074927986596639[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4448074927986596639[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4448074927986596639[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4448074927986596639[3] = 0;
   out_4448074927986596639[4] = 0;
   out_4448074927986596639[5] = 0;
   out_4448074927986596639[6] = 1;
   out_4448074927986596639[7] = 0;
   out_4448074927986596639[8] = 0;
   out_4448074927986596639[9] = 1;
   out_4448074927986596639[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_6662915346589297390) {
   out_6662915346589297390[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7535590482650814090) {
   out_7535590482650814090[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[6] = 0;
   out_7535590482650814090[7] = 1;
   out_7535590482650814090[8] = 0;
   out_7535590482650814090[9] = 0;
   out_7535590482650814090[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_6662915346589297390) {
   out_6662915346589297390[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7535590482650814090) {
   out_7535590482650814090[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7535590482650814090[6] = 0;
   out_7535590482650814090[7] = 1;
   out_7535590482650814090[8] = 0;
   out_7535590482650814090[9] = 0;
   out_7535590482650814090[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4766384142186770465) {
  err_fun(nom_x, delta_x, out_4766384142186770465);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6278544928106810662) {
  inv_err_fun(nom_x, true_x, out_6278544928106810662);
}
void gnss_H_mod_fun(double *state, double *out_8097412979060097308) {
  H_mod_fun(state, out_8097412979060097308);
}
void gnss_f_fun(double *state, double dt, double *out_3104780102329770139) {
  f_fun(state,  dt, out_3104780102329770139);
}
void gnss_F_fun(double *state, double dt, double *out_4096543142917168482) {
  F_fun(state,  dt, out_4096543142917168482);
}
void gnss_h_6(double *state, double *sat_pos, double *out_6758247131004536746) {
  h_6(state, sat_pos, out_6758247131004536746);
}
void gnss_H_6(double *state, double *sat_pos, double *out_4686865741220841403) {
  H_6(state, sat_pos, out_4686865741220841403);
}
void gnss_h_20(double *state, double *sat_pos, double *out_421409222323252481) {
  h_20(state, sat_pos, out_421409222323252481);
}
void gnss_H_20(double *state, double *sat_pos, double *out_4448074927986596639) {
  H_20(state, sat_pos, out_4448074927986596639);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6662915346589297390) {
  h_7(state, sat_pos_vel, out_6662915346589297390);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7535590482650814090) {
  H_7(state, sat_pos_vel, out_7535590482650814090);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6662915346589297390) {
  h_21(state, sat_pos_vel, out_6662915346589297390);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7535590482650814090) {
  H_21(state, sat_pos_vel, out_7535590482650814090);
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
