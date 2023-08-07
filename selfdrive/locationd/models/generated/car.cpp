#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4904502417690011868) {
   out_4904502417690011868[0] = delta_x[0] + nom_x[0];
   out_4904502417690011868[1] = delta_x[1] + nom_x[1];
   out_4904502417690011868[2] = delta_x[2] + nom_x[2];
   out_4904502417690011868[3] = delta_x[3] + nom_x[3];
   out_4904502417690011868[4] = delta_x[4] + nom_x[4];
   out_4904502417690011868[5] = delta_x[5] + nom_x[5];
   out_4904502417690011868[6] = delta_x[6] + nom_x[6];
   out_4904502417690011868[7] = delta_x[7] + nom_x[7];
   out_4904502417690011868[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2523710226769313624) {
   out_2523710226769313624[0] = -nom_x[0] + true_x[0];
   out_2523710226769313624[1] = -nom_x[1] + true_x[1];
   out_2523710226769313624[2] = -nom_x[2] + true_x[2];
   out_2523710226769313624[3] = -nom_x[3] + true_x[3];
   out_2523710226769313624[4] = -nom_x[4] + true_x[4];
   out_2523710226769313624[5] = -nom_x[5] + true_x[5];
   out_2523710226769313624[6] = -nom_x[6] + true_x[6];
   out_2523710226769313624[7] = -nom_x[7] + true_x[7];
   out_2523710226769313624[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2102495077234161738) {
   out_2102495077234161738[0] = 1.0;
   out_2102495077234161738[1] = 0;
   out_2102495077234161738[2] = 0;
   out_2102495077234161738[3] = 0;
   out_2102495077234161738[4] = 0;
   out_2102495077234161738[5] = 0;
   out_2102495077234161738[6] = 0;
   out_2102495077234161738[7] = 0;
   out_2102495077234161738[8] = 0;
   out_2102495077234161738[9] = 0;
   out_2102495077234161738[10] = 1.0;
   out_2102495077234161738[11] = 0;
   out_2102495077234161738[12] = 0;
   out_2102495077234161738[13] = 0;
   out_2102495077234161738[14] = 0;
   out_2102495077234161738[15] = 0;
   out_2102495077234161738[16] = 0;
   out_2102495077234161738[17] = 0;
   out_2102495077234161738[18] = 0;
   out_2102495077234161738[19] = 0;
   out_2102495077234161738[20] = 1.0;
   out_2102495077234161738[21] = 0;
   out_2102495077234161738[22] = 0;
   out_2102495077234161738[23] = 0;
   out_2102495077234161738[24] = 0;
   out_2102495077234161738[25] = 0;
   out_2102495077234161738[26] = 0;
   out_2102495077234161738[27] = 0;
   out_2102495077234161738[28] = 0;
   out_2102495077234161738[29] = 0;
   out_2102495077234161738[30] = 1.0;
   out_2102495077234161738[31] = 0;
   out_2102495077234161738[32] = 0;
   out_2102495077234161738[33] = 0;
   out_2102495077234161738[34] = 0;
   out_2102495077234161738[35] = 0;
   out_2102495077234161738[36] = 0;
   out_2102495077234161738[37] = 0;
   out_2102495077234161738[38] = 0;
   out_2102495077234161738[39] = 0;
   out_2102495077234161738[40] = 1.0;
   out_2102495077234161738[41] = 0;
   out_2102495077234161738[42] = 0;
   out_2102495077234161738[43] = 0;
   out_2102495077234161738[44] = 0;
   out_2102495077234161738[45] = 0;
   out_2102495077234161738[46] = 0;
   out_2102495077234161738[47] = 0;
   out_2102495077234161738[48] = 0;
   out_2102495077234161738[49] = 0;
   out_2102495077234161738[50] = 1.0;
   out_2102495077234161738[51] = 0;
   out_2102495077234161738[52] = 0;
   out_2102495077234161738[53] = 0;
   out_2102495077234161738[54] = 0;
   out_2102495077234161738[55] = 0;
   out_2102495077234161738[56] = 0;
   out_2102495077234161738[57] = 0;
   out_2102495077234161738[58] = 0;
   out_2102495077234161738[59] = 0;
   out_2102495077234161738[60] = 1.0;
   out_2102495077234161738[61] = 0;
   out_2102495077234161738[62] = 0;
   out_2102495077234161738[63] = 0;
   out_2102495077234161738[64] = 0;
   out_2102495077234161738[65] = 0;
   out_2102495077234161738[66] = 0;
   out_2102495077234161738[67] = 0;
   out_2102495077234161738[68] = 0;
   out_2102495077234161738[69] = 0;
   out_2102495077234161738[70] = 1.0;
   out_2102495077234161738[71] = 0;
   out_2102495077234161738[72] = 0;
   out_2102495077234161738[73] = 0;
   out_2102495077234161738[74] = 0;
   out_2102495077234161738[75] = 0;
   out_2102495077234161738[76] = 0;
   out_2102495077234161738[77] = 0;
   out_2102495077234161738[78] = 0;
   out_2102495077234161738[79] = 0;
   out_2102495077234161738[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2902792789409424078) {
   out_2902792789409424078[0] = state[0];
   out_2902792789409424078[1] = state[1];
   out_2902792789409424078[2] = state[2];
   out_2902792789409424078[3] = state[3];
   out_2902792789409424078[4] = state[4];
   out_2902792789409424078[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2902792789409424078[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2902792789409424078[7] = state[7];
   out_2902792789409424078[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7384697533201998408) {
   out_7384697533201998408[0] = 1;
   out_7384697533201998408[1] = 0;
   out_7384697533201998408[2] = 0;
   out_7384697533201998408[3] = 0;
   out_7384697533201998408[4] = 0;
   out_7384697533201998408[5] = 0;
   out_7384697533201998408[6] = 0;
   out_7384697533201998408[7] = 0;
   out_7384697533201998408[8] = 0;
   out_7384697533201998408[9] = 0;
   out_7384697533201998408[10] = 1;
   out_7384697533201998408[11] = 0;
   out_7384697533201998408[12] = 0;
   out_7384697533201998408[13] = 0;
   out_7384697533201998408[14] = 0;
   out_7384697533201998408[15] = 0;
   out_7384697533201998408[16] = 0;
   out_7384697533201998408[17] = 0;
   out_7384697533201998408[18] = 0;
   out_7384697533201998408[19] = 0;
   out_7384697533201998408[20] = 1;
   out_7384697533201998408[21] = 0;
   out_7384697533201998408[22] = 0;
   out_7384697533201998408[23] = 0;
   out_7384697533201998408[24] = 0;
   out_7384697533201998408[25] = 0;
   out_7384697533201998408[26] = 0;
   out_7384697533201998408[27] = 0;
   out_7384697533201998408[28] = 0;
   out_7384697533201998408[29] = 0;
   out_7384697533201998408[30] = 1;
   out_7384697533201998408[31] = 0;
   out_7384697533201998408[32] = 0;
   out_7384697533201998408[33] = 0;
   out_7384697533201998408[34] = 0;
   out_7384697533201998408[35] = 0;
   out_7384697533201998408[36] = 0;
   out_7384697533201998408[37] = 0;
   out_7384697533201998408[38] = 0;
   out_7384697533201998408[39] = 0;
   out_7384697533201998408[40] = 1;
   out_7384697533201998408[41] = 0;
   out_7384697533201998408[42] = 0;
   out_7384697533201998408[43] = 0;
   out_7384697533201998408[44] = 0;
   out_7384697533201998408[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7384697533201998408[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7384697533201998408[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7384697533201998408[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7384697533201998408[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7384697533201998408[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7384697533201998408[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7384697533201998408[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7384697533201998408[53] = -9.8000000000000007*dt;
   out_7384697533201998408[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7384697533201998408[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7384697533201998408[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7384697533201998408[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7384697533201998408[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7384697533201998408[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7384697533201998408[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7384697533201998408[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7384697533201998408[62] = 0;
   out_7384697533201998408[63] = 0;
   out_7384697533201998408[64] = 0;
   out_7384697533201998408[65] = 0;
   out_7384697533201998408[66] = 0;
   out_7384697533201998408[67] = 0;
   out_7384697533201998408[68] = 0;
   out_7384697533201998408[69] = 0;
   out_7384697533201998408[70] = 1;
   out_7384697533201998408[71] = 0;
   out_7384697533201998408[72] = 0;
   out_7384697533201998408[73] = 0;
   out_7384697533201998408[74] = 0;
   out_7384697533201998408[75] = 0;
   out_7384697533201998408[76] = 0;
   out_7384697533201998408[77] = 0;
   out_7384697533201998408[78] = 0;
   out_7384697533201998408[79] = 0;
   out_7384697533201998408[80] = 1;
}
void h_25(double *state, double *unused, double *out_6076734193594010054) {
   out_6076734193594010054[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8386229354659032627) {
   out_8386229354659032627[0] = 0;
   out_8386229354659032627[1] = 0;
   out_8386229354659032627[2] = 0;
   out_8386229354659032627[3] = 0;
   out_8386229354659032627[4] = 0;
   out_8386229354659032627[5] = 0;
   out_8386229354659032627[6] = 1;
   out_8386229354659032627[7] = 0;
   out_8386229354659032627[8] = 0;
}
void h_24(double *state, double *unused, double *out_3849361237634050377) {
   out_3849361237634050377[0] = state[4];
   out_3849361237634050377[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6058802640420010356) {
   out_6058802640420010356[0] = 0;
   out_6058802640420010356[1] = 0;
   out_6058802640420010356[2] = 0;
   out_6058802640420010356[3] = 0;
   out_6058802640420010356[4] = 1;
   out_6058802640420010356[5] = 0;
   out_6058802640420010356[6] = 0;
   out_6058802640420010356[7] = 0;
   out_6058802640420010356[8] = 0;
   out_6058802640420010356[9] = 0;
   out_6058802640420010356[10] = 0;
   out_6058802640420010356[11] = 0;
   out_6058802640420010356[12] = 0;
   out_6058802640420010356[13] = 0;
   out_6058802640420010356[14] = 1;
   out_6058802640420010356[15] = 0;
   out_6058802640420010356[16] = 0;
   out_6058802640420010356[17] = 0;
}
void h_30(double *state, double *unused, double *out_1686531063226662387) {
   out_1686531063226662387[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3143824377558902234) {
   out_3143824377558902234[0] = 0;
   out_3143824377558902234[1] = 0;
   out_3143824377558902234[2] = 0;
   out_3143824377558902234[3] = 0;
   out_3143824377558902234[4] = 1;
   out_3143824377558902234[5] = 0;
   out_3143824377558902234[6] = 0;
   out_3143824377558902234[7] = 0;
   out_3143824377558902234[8] = 0;
}
void h_26(double *state, double *unused, double *out_1350254988217670298) {
   out_1350254988217670298[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4644726035784976403) {
   out_4644726035784976403[0] = 0;
   out_4644726035784976403[1] = 0;
   out_4644726035784976403[2] = 0;
   out_4644726035784976403[3] = 0;
   out_4644726035784976403[4] = 0;
   out_4644726035784976403[5] = 0;
   out_4644726035784976403[6] = 0;
   out_4644726035784976403[7] = 1;
   out_4644726035784976403[8] = 0;
}
void h_27(double *state, double *unused, double *out_4717106662584640226) {
   out_4717106662584640226[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5318587689359327145) {
   out_5318587689359327145[0] = 0;
   out_5318587689359327145[1] = 0;
   out_5318587689359327145[2] = 0;
   out_5318587689359327145[3] = 1;
   out_5318587689359327145[4] = 0;
   out_5318587689359327145[5] = 0;
   out_5318587689359327145[6] = 0;
   out_5318587689359327145[7] = 0;
   out_5318587689359327145[8] = 0;
}
void h_29(double *state, double *unused, double *out_3506653136026194265) {
   out_3506653136026194265[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2633593033244510050) {
   out_2633593033244510050[0] = 0;
   out_2633593033244510050[1] = 1;
   out_2633593033244510050[2] = 0;
   out_2633593033244510050[3] = 0;
   out_2633593033244510050[4] = 0;
   out_2633593033244510050[5] = 0;
   out_2633593033244510050[6] = 0;
   out_2633593033244510050[7] = 0;
   out_2633593033244510050[8] = 0;
}
void h_28(double *state, double *unused, double *out_2096438289248014934) {
   out_2096438289248014934[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7715992050314040624) {
   out_7715992050314040624[0] = 1;
   out_7715992050314040624[1] = 0;
   out_7715992050314040624[2] = 0;
   out_7715992050314040624[3] = 0;
   out_7715992050314040624[4] = 0;
   out_7715992050314040624[5] = 0;
   out_7715992050314040624[6] = 0;
   out_7715992050314040624[7] = 0;
   out_7715992050314040624[8] = 0;
}
void h_31(double *state, double *unused, double *out_3232292595431690380) {
   out_3232292595431690380[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8416875316535993055) {
   out_8416875316535993055[0] = 0;
   out_8416875316535993055[1] = 0;
   out_8416875316535993055[2] = 0;
   out_8416875316535993055[3] = 0;
   out_8416875316535993055[4] = 0;
   out_8416875316535993055[5] = 0;
   out_8416875316535993055[6] = 0;
   out_8416875316535993055[7] = 0;
   out_8416875316535993055[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4904502417690011868) {
  err_fun(nom_x, delta_x, out_4904502417690011868);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2523710226769313624) {
  inv_err_fun(nom_x, true_x, out_2523710226769313624);
}
void car_H_mod_fun(double *state, double *out_2102495077234161738) {
  H_mod_fun(state, out_2102495077234161738);
}
void car_f_fun(double *state, double dt, double *out_2902792789409424078) {
  f_fun(state,  dt, out_2902792789409424078);
}
void car_F_fun(double *state, double dt, double *out_7384697533201998408) {
  F_fun(state,  dt, out_7384697533201998408);
}
void car_h_25(double *state, double *unused, double *out_6076734193594010054) {
  h_25(state, unused, out_6076734193594010054);
}
void car_H_25(double *state, double *unused, double *out_8386229354659032627) {
  H_25(state, unused, out_8386229354659032627);
}
void car_h_24(double *state, double *unused, double *out_3849361237634050377) {
  h_24(state, unused, out_3849361237634050377);
}
void car_H_24(double *state, double *unused, double *out_6058802640420010356) {
  H_24(state, unused, out_6058802640420010356);
}
void car_h_30(double *state, double *unused, double *out_1686531063226662387) {
  h_30(state, unused, out_1686531063226662387);
}
void car_H_30(double *state, double *unused, double *out_3143824377558902234) {
  H_30(state, unused, out_3143824377558902234);
}
void car_h_26(double *state, double *unused, double *out_1350254988217670298) {
  h_26(state, unused, out_1350254988217670298);
}
void car_H_26(double *state, double *unused, double *out_4644726035784976403) {
  H_26(state, unused, out_4644726035784976403);
}
void car_h_27(double *state, double *unused, double *out_4717106662584640226) {
  h_27(state, unused, out_4717106662584640226);
}
void car_H_27(double *state, double *unused, double *out_5318587689359327145) {
  H_27(state, unused, out_5318587689359327145);
}
void car_h_29(double *state, double *unused, double *out_3506653136026194265) {
  h_29(state, unused, out_3506653136026194265);
}
void car_H_29(double *state, double *unused, double *out_2633593033244510050) {
  H_29(state, unused, out_2633593033244510050);
}
void car_h_28(double *state, double *unused, double *out_2096438289248014934) {
  h_28(state, unused, out_2096438289248014934);
}
void car_H_28(double *state, double *unused, double *out_7715992050314040624) {
  H_28(state, unused, out_7715992050314040624);
}
void car_h_31(double *state, double *unused, double *out_3232292595431690380) {
  h_31(state, unused, out_3232292595431690380);
}
void car_H_31(double *state, double *unused, double *out_8416875316535993055) {
  H_31(state, unused, out_8416875316535993055);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
