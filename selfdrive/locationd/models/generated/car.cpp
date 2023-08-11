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
void err_fun(double *nom_x, double *delta_x, double *out_8412408275907562510) {
   out_8412408275907562510[0] = delta_x[0] + nom_x[0];
   out_8412408275907562510[1] = delta_x[1] + nom_x[1];
   out_8412408275907562510[2] = delta_x[2] + nom_x[2];
   out_8412408275907562510[3] = delta_x[3] + nom_x[3];
   out_8412408275907562510[4] = delta_x[4] + nom_x[4];
   out_8412408275907562510[5] = delta_x[5] + nom_x[5];
   out_8412408275907562510[6] = delta_x[6] + nom_x[6];
   out_8412408275907562510[7] = delta_x[7] + nom_x[7];
   out_8412408275907562510[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5009429012443487067) {
   out_5009429012443487067[0] = -nom_x[0] + true_x[0];
   out_5009429012443487067[1] = -nom_x[1] + true_x[1];
   out_5009429012443487067[2] = -nom_x[2] + true_x[2];
   out_5009429012443487067[3] = -nom_x[3] + true_x[3];
   out_5009429012443487067[4] = -nom_x[4] + true_x[4];
   out_5009429012443487067[5] = -nom_x[5] + true_x[5];
   out_5009429012443487067[6] = -nom_x[6] + true_x[6];
   out_5009429012443487067[7] = -nom_x[7] + true_x[7];
   out_5009429012443487067[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7201068384612818103) {
   out_7201068384612818103[0] = 1.0;
   out_7201068384612818103[1] = 0;
   out_7201068384612818103[2] = 0;
   out_7201068384612818103[3] = 0;
   out_7201068384612818103[4] = 0;
   out_7201068384612818103[5] = 0;
   out_7201068384612818103[6] = 0;
   out_7201068384612818103[7] = 0;
   out_7201068384612818103[8] = 0;
   out_7201068384612818103[9] = 0;
   out_7201068384612818103[10] = 1.0;
   out_7201068384612818103[11] = 0;
   out_7201068384612818103[12] = 0;
   out_7201068384612818103[13] = 0;
   out_7201068384612818103[14] = 0;
   out_7201068384612818103[15] = 0;
   out_7201068384612818103[16] = 0;
   out_7201068384612818103[17] = 0;
   out_7201068384612818103[18] = 0;
   out_7201068384612818103[19] = 0;
   out_7201068384612818103[20] = 1.0;
   out_7201068384612818103[21] = 0;
   out_7201068384612818103[22] = 0;
   out_7201068384612818103[23] = 0;
   out_7201068384612818103[24] = 0;
   out_7201068384612818103[25] = 0;
   out_7201068384612818103[26] = 0;
   out_7201068384612818103[27] = 0;
   out_7201068384612818103[28] = 0;
   out_7201068384612818103[29] = 0;
   out_7201068384612818103[30] = 1.0;
   out_7201068384612818103[31] = 0;
   out_7201068384612818103[32] = 0;
   out_7201068384612818103[33] = 0;
   out_7201068384612818103[34] = 0;
   out_7201068384612818103[35] = 0;
   out_7201068384612818103[36] = 0;
   out_7201068384612818103[37] = 0;
   out_7201068384612818103[38] = 0;
   out_7201068384612818103[39] = 0;
   out_7201068384612818103[40] = 1.0;
   out_7201068384612818103[41] = 0;
   out_7201068384612818103[42] = 0;
   out_7201068384612818103[43] = 0;
   out_7201068384612818103[44] = 0;
   out_7201068384612818103[45] = 0;
   out_7201068384612818103[46] = 0;
   out_7201068384612818103[47] = 0;
   out_7201068384612818103[48] = 0;
   out_7201068384612818103[49] = 0;
   out_7201068384612818103[50] = 1.0;
   out_7201068384612818103[51] = 0;
   out_7201068384612818103[52] = 0;
   out_7201068384612818103[53] = 0;
   out_7201068384612818103[54] = 0;
   out_7201068384612818103[55] = 0;
   out_7201068384612818103[56] = 0;
   out_7201068384612818103[57] = 0;
   out_7201068384612818103[58] = 0;
   out_7201068384612818103[59] = 0;
   out_7201068384612818103[60] = 1.0;
   out_7201068384612818103[61] = 0;
   out_7201068384612818103[62] = 0;
   out_7201068384612818103[63] = 0;
   out_7201068384612818103[64] = 0;
   out_7201068384612818103[65] = 0;
   out_7201068384612818103[66] = 0;
   out_7201068384612818103[67] = 0;
   out_7201068384612818103[68] = 0;
   out_7201068384612818103[69] = 0;
   out_7201068384612818103[70] = 1.0;
   out_7201068384612818103[71] = 0;
   out_7201068384612818103[72] = 0;
   out_7201068384612818103[73] = 0;
   out_7201068384612818103[74] = 0;
   out_7201068384612818103[75] = 0;
   out_7201068384612818103[76] = 0;
   out_7201068384612818103[77] = 0;
   out_7201068384612818103[78] = 0;
   out_7201068384612818103[79] = 0;
   out_7201068384612818103[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2117395969407442559) {
   out_2117395969407442559[0] = state[0];
   out_2117395969407442559[1] = state[1];
   out_2117395969407442559[2] = state[2];
   out_2117395969407442559[3] = state[3];
   out_2117395969407442559[4] = state[4];
   out_2117395969407442559[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2117395969407442559[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2117395969407442559[7] = state[7];
   out_2117395969407442559[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1930106235119052766) {
   out_1930106235119052766[0] = 1;
   out_1930106235119052766[1] = 0;
   out_1930106235119052766[2] = 0;
   out_1930106235119052766[3] = 0;
   out_1930106235119052766[4] = 0;
   out_1930106235119052766[5] = 0;
   out_1930106235119052766[6] = 0;
   out_1930106235119052766[7] = 0;
   out_1930106235119052766[8] = 0;
   out_1930106235119052766[9] = 0;
   out_1930106235119052766[10] = 1;
   out_1930106235119052766[11] = 0;
   out_1930106235119052766[12] = 0;
   out_1930106235119052766[13] = 0;
   out_1930106235119052766[14] = 0;
   out_1930106235119052766[15] = 0;
   out_1930106235119052766[16] = 0;
   out_1930106235119052766[17] = 0;
   out_1930106235119052766[18] = 0;
   out_1930106235119052766[19] = 0;
   out_1930106235119052766[20] = 1;
   out_1930106235119052766[21] = 0;
   out_1930106235119052766[22] = 0;
   out_1930106235119052766[23] = 0;
   out_1930106235119052766[24] = 0;
   out_1930106235119052766[25] = 0;
   out_1930106235119052766[26] = 0;
   out_1930106235119052766[27] = 0;
   out_1930106235119052766[28] = 0;
   out_1930106235119052766[29] = 0;
   out_1930106235119052766[30] = 1;
   out_1930106235119052766[31] = 0;
   out_1930106235119052766[32] = 0;
   out_1930106235119052766[33] = 0;
   out_1930106235119052766[34] = 0;
   out_1930106235119052766[35] = 0;
   out_1930106235119052766[36] = 0;
   out_1930106235119052766[37] = 0;
   out_1930106235119052766[38] = 0;
   out_1930106235119052766[39] = 0;
   out_1930106235119052766[40] = 1;
   out_1930106235119052766[41] = 0;
   out_1930106235119052766[42] = 0;
   out_1930106235119052766[43] = 0;
   out_1930106235119052766[44] = 0;
   out_1930106235119052766[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1930106235119052766[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1930106235119052766[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1930106235119052766[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1930106235119052766[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1930106235119052766[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1930106235119052766[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1930106235119052766[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1930106235119052766[53] = -9.8000000000000007*dt;
   out_1930106235119052766[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1930106235119052766[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1930106235119052766[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1930106235119052766[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1930106235119052766[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1930106235119052766[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1930106235119052766[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1930106235119052766[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1930106235119052766[62] = 0;
   out_1930106235119052766[63] = 0;
   out_1930106235119052766[64] = 0;
   out_1930106235119052766[65] = 0;
   out_1930106235119052766[66] = 0;
   out_1930106235119052766[67] = 0;
   out_1930106235119052766[68] = 0;
   out_1930106235119052766[69] = 0;
   out_1930106235119052766[70] = 1;
   out_1930106235119052766[71] = 0;
   out_1930106235119052766[72] = 0;
   out_1930106235119052766[73] = 0;
   out_1930106235119052766[74] = 0;
   out_1930106235119052766[75] = 0;
   out_1930106235119052766[76] = 0;
   out_1930106235119052766[77] = 0;
   out_1930106235119052766[78] = 0;
   out_1930106235119052766[79] = 0;
   out_1930106235119052766[80] = 1;
}
void h_25(double *state, double *unused, double *out_4962192466318968957) {
   out_4962192466318968957[0] = state[6];
}
void H_25(double *state, double *unused, double *out_279667768067758393) {
   out_279667768067758393[0] = 0;
   out_279667768067758393[1] = 0;
   out_279667768067758393[2] = 0;
   out_279667768067758393[3] = 0;
   out_279667768067758393[4] = 0;
   out_279667768067758393[5] = 0;
   out_279667768067758393[6] = 1;
   out_279667768067758393[7] = 0;
   out_279667768067758393[8] = 0;
}
void h_24(double *state, double *unused, double *out_8672504443832107776) {
   out_8672504443832107776[0] = state[4];
   out_8672504443832107776[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1897546655539391580) {
   out_1897546655539391580[0] = 0;
   out_1897546655539391580[1] = 0;
   out_1897546655539391580[2] = 0;
   out_1897546655539391580[3] = 0;
   out_1897546655539391580[4] = 1;
   out_1897546655539391580[5] = 0;
   out_1897546655539391580[6] = 0;
   out_1897546655539391580[7] = 0;
   out_1897546655539391580[8] = 0;
   out_1897546655539391580[9] = 0;
   out_1897546655539391580[10] = 0;
   out_1897546655539391580[11] = 0;
   out_1897546655539391580[12] = 0;
   out_1897546655539391580[13] = 0;
   out_1897546655539391580[14] = 1;
   out_1897546655539391580[15] = 0;
   out_1897546655539391580[16] = 0;
   out_1897546655539391580[17] = 0;
}
void h_30(double *state, double *unused, double *out_4360774308705605403) {
   out_4360774308705605403[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2238665190439490234) {
   out_2238665190439490234[0] = 0;
   out_2238665190439490234[1] = 0;
   out_2238665190439490234[2] = 0;
   out_2238665190439490234[3] = 0;
   out_2238665190439490234[4] = 1;
   out_2238665190439490234[5] = 0;
   out_2238665190439490234[6] = 0;
   out_2238665190439490234[7] = 0;
   out_2238665190439490234[8] = 0;
}
void h_26(double *state, double *unused, double *out_640898958955240242) {
   out_640898958955240242[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4021171086941814617) {
   out_4021171086941814617[0] = 0;
   out_4021171086941814617[1] = 0;
   out_4021171086941814617[2] = 0;
   out_4021171086941814617[3] = 0;
   out_4021171086941814617[4] = 0;
   out_4021171086941814617[5] = 0;
   out_4021171086941814617[6] = 0;
   out_4021171086941814617[7] = 1;
   out_4021171086941814617[8] = 0;
}
void h_27(double *state, double *unused, double *out_3142070393519437079) {
   out_3142070393519437079[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4462259261623433451) {
   out_4462259261623433451[0] = 0;
   out_4462259261623433451[1] = 0;
   out_4462259261623433451[2] = 0;
   out_4462259261623433451[3] = 1;
   out_4462259261623433451[4] = 0;
   out_4462259261623433451[5] = 0;
   out_4462259261623433451[6] = 0;
   out_4462259261623433451[7] = 0;
   out_4462259261623433451[8] = 0;
}
void h_29(double *state, double *unused, double *out_4621194863301235362) {
   out_4621194863301235362[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2748896534753882418) {
   out_2748896534753882418[0] = 0;
   out_2748896534753882418[1] = 1;
   out_2748896534753882418[2] = 0;
   out_2748896534753882418[3] = 0;
   out_2748896534753882418[4] = 0;
   out_2748896534753882418[5] = 0;
   out_2748896534753882418[6] = 0;
   out_2748896534753882418[7] = 0;
   out_2748896534753882418[8] = 0;
}
void h_28(double *state, double *unused, double *out_7655328506878780195) {
   out_7655328506878780195[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2333502482315648156) {
   out_2333502482315648156[0] = 1;
   out_2333502482315648156[1] = 0;
   out_2333502482315648156[2] = 0;
   out_2333502482315648156[3] = 0;
   out_2333502482315648156[4] = 0;
   out_2333502482315648156[5] = 0;
   out_2333502482315648156[6] = 0;
   out_2333502482315648156[7] = 0;
   out_2333502482315648156[8] = 0;
}
void h_31(double *state, double *unused, double *out_5721286350569910218) {
   out_5721286350569910218[0] = state[8];
}
void H_31(double *state, double *unused, double *out_249021806190797965) {
   out_249021806190797965[0] = 0;
   out_249021806190797965[1] = 0;
   out_249021806190797965[2] = 0;
   out_249021806190797965[3] = 0;
   out_249021806190797965[4] = 0;
   out_249021806190797965[5] = 0;
   out_249021806190797965[6] = 0;
   out_249021806190797965[7] = 0;
   out_249021806190797965[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8412408275907562510) {
  err_fun(nom_x, delta_x, out_8412408275907562510);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5009429012443487067) {
  inv_err_fun(nom_x, true_x, out_5009429012443487067);
}
void car_H_mod_fun(double *state, double *out_7201068384612818103) {
  H_mod_fun(state, out_7201068384612818103);
}
void car_f_fun(double *state, double dt, double *out_2117395969407442559) {
  f_fun(state,  dt, out_2117395969407442559);
}
void car_F_fun(double *state, double dt, double *out_1930106235119052766) {
  F_fun(state,  dt, out_1930106235119052766);
}
void car_h_25(double *state, double *unused, double *out_4962192466318968957) {
  h_25(state, unused, out_4962192466318968957);
}
void car_H_25(double *state, double *unused, double *out_279667768067758393) {
  H_25(state, unused, out_279667768067758393);
}
void car_h_24(double *state, double *unused, double *out_8672504443832107776) {
  h_24(state, unused, out_8672504443832107776);
}
void car_H_24(double *state, double *unused, double *out_1897546655539391580) {
  H_24(state, unused, out_1897546655539391580);
}
void car_h_30(double *state, double *unused, double *out_4360774308705605403) {
  h_30(state, unused, out_4360774308705605403);
}
void car_H_30(double *state, double *unused, double *out_2238665190439490234) {
  H_30(state, unused, out_2238665190439490234);
}
void car_h_26(double *state, double *unused, double *out_640898958955240242) {
  h_26(state, unused, out_640898958955240242);
}
void car_H_26(double *state, double *unused, double *out_4021171086941814617) {
  H_26(state, unused, out_4021171086941814617);
}
void car_h_27(double *state, double *unused, double *out_3142070393519437079) {
  h_27(state, unused, out_3142070393519437079);
}
void car_H_27(double *state, double *unused, double *out_4462259261623433451) {
  H_27(state, unused, out_4462259261623433451);
}
void car_h_29(double *state, double *unused, double *out_4621194863301235362) {
  h_29(state, unused, out_4621194863301235362);
}
void car_H_29(double *state, double *unused, double *out_2748896534753882418) {
  H_29(state, unused, out_2748896534753882418);
}
void car_h_28(double *state, double *unused, double *out_7655328506878780195) {
  h_28(state, unused, out_7655328506878780195);
}
void car_H_28(double *state, double *unused, double *out_2333502482315648156) {
  H_28(state, unused, out_2333502482315648156);
}
void car_h_31(double *state, double *unused, double *out_5721286350569910218) {
  h_31(state, unused, out_5721286350569910218);
}
void car_H_31(double *state, double *unused, double *out_249021806190797965) {
  H_31(state, unused, out_249021806190797965);
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
