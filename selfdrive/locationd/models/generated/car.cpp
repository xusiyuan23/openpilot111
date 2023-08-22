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
void err_fun(double *nom_x, double *delta_x, double *out_3511157536608921668) {
   out_3511157536608921668[0] = delta_x[0] + nom_x[0];
   out_3511157536608921668[1] = delta_x[1] + nom_x[1];
   out_3511157536608921668[2] = delta_x[2] + nom_x[2];
   out_3511157536608921668[3] = delta_x[3] + nom_x[3];
   out_3511157536608921668[4] = delta_x[4] + nom_x[4];
   out_3511157536608921668[5] = delta_x[5] + nom_x[5];
   out_3511157536608921668[6] = delta_x[6] + nom_x[6];
   out_3511157536608921668[7] = delta_x[7] + nom_x[7];
   out_3511157536608921668[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6431969432730020252) {
   out_6431969432730020252[0] = -nom_x[0] + true_x[0];
   out_6431969432730020252[1] = -nom_x[1] + true_x[1];
   out_6431969432730020252[2] = -nom_x[2] + true_x[2];
   out_6431969432730020252[3] = -nom_x[3] + true_x[3];
   out_6431969432730020252[4] = -nom_x[4] + true_x[4];
   out_6431969432730020252[5] = -nom_x[5] + true_x[5];
   out_6431969432730020252[6] = -nom_x[6] + true_x[6];
   out_6431969432730020252[7] = -nom_x[7] + true_x[7];
   out_6431969432730020252[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7948008639250905645) {
   out_7948008639250905645[0] = 1.0;
   out_7948008639250905645[1] = 0;
   out_7948008639250905645[2] = 0;
   out_7948008639250905645[3] = 0;
   out_7948008639250905645[4] = 0;
   out_7948008639250905645[5] = 0;
   out_7948008639250905645[6] = 0;
   out_7948008639250905645[7] = 0;
   out_7948008639250905645[8] = 0;
   out_7948008639250905645[9] = 0;
   out_7948008639250905645[10] = 1.0;
   out_7948008639250905645[11] = 0;
   out_7948008639250905645[12] = 0;
   out_7948008639250905645[13] = 0;
   out_7948008639250905645[14] = 0;
   out_7948008639250905645[15] = 0;
   out_7948008639250905645[16] = 0;
   out_7948008639250905645[17] = 0;
   out_7948008639250905645[18] = 0;
   out_7948008639250905645[19] = 0;
   out_7948008639250905645[20] = 1.0;
   out_7948008639250905645[21] = 0;
   out_7948008639250905645[22] = 0;
   out_7948008639250905645[23] = 0;
   out_7948008639250905645[24] = 0;
   out_7948008639250905645[25] = 0;
   out_7948008639250905645[26] = 0;
   out_7948008639250905645[27] = 0;
   out_7948008639250905645[28] = 0;
   out_7948008639250905645[29] = 0;
   out_7948008639250905645[30] = 1.0;
   out_7948008639250905645[31] = 0;
   out_7948008639250905645[32] = 0;
   out_7948008639250905645[33] = 0;
   out_7948008639250905645[34] = 0;
   out_7948008639250905645[35] = 0;
   out_7948008639250905645[36] = 0;
   out_7948008639250905645[37] = 0;
   out_7948008639250905645[38] = 0;
   out_7948008639250905645[39] = 0;
   out_7948008639250905645[40] = 1.0;
   out_7948008639250905645[41] = 0;
   out_7948008639250905645[42] = 0;
   out_7948008639250905645[43] = 0;
   out_7948008639250905645[44] = 0;
   out_7948008639250905645[45] = 0;
   out_7948008639250905645[46] = 0;
   out_7948008639250905645[47] = 0;
   out_7948008639250905645[48] = 0;
   out_7948008639250905645[49] = 0;
   out_7948008639250905645[50] = 1.0;
   out_7948008639250905645[51] = 0;
   out_7948008639250905645[52] = 0;
   out_7948008639250905645[53] = 0;
   out_7948008639250905645[54] = 0;
   out_7948008639250905645[55] = 0;
   out_7948008639250905645[56] = 0;
   out_7948008639250905645[57] = 0;
   out_7948008639250905645[58] = 0;
   out_7948008639250905645[59] = 0;
   out_7948008639250905645[60] = 1.0;
   out_7948008639250905645[61] = 0;
   out_7948008639250905645[62] = 0;
   out_7948008639250905645[63] = 0;
   out_7948008639250905645[64] = 0;
   out_7948008639250905645[65] = 0;
   out_7948008639250905645[66] = 0;
   out_7948008639250905645[67] = 0;
   out_7948008639250905645[68] = 0;
   out_7948008639250905645[69] = 0;
   out_7948008639250905645[70] = 1.0;
   out_7948008639250905645[71] = 0;
   out_7948008639250905645[72] = 0;
   out_7948008639250905645[73] = 0;
   out_7948008639250905645[74] = 0;
   out_7948008639250905645[75] = 0;
   out_7948008639250905645[76] = 0;
   out_7948008639250905645[77] = 0;
   out_7948008639250905645[78] = 0;
   out_7948008639250905645[79] = 0;
   out_7948008639250905645[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2086994761209225774) {
   out_2086994761209225774[0] = state[0];
   out_2086994761209225774[1] = state[1];
   out_2086994761209225774[2] = state[2];
   out_2086994761209225774[3] = state[3];
   out_2086994761209225774[4] = state[4];
   out_2086994761209225774[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2086994761209225774[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2086994761209225774[7] = state[7];
   out_2086994761209225774[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8139310027990993197) {
   out_8139310027990993197[0] = 1;
   out_8139310027990993197[1] = 0;
   out_8139310027990993197[2] = 0;
   out_8139310027990993197[3] = 0;
   out_8139310027990993197[4] = 0;
   out_8139310027990993197[5] = 0;
   out_8139310027990993197[6] = 0;
   out_8139310027990993197[7] = 0;
   out_8139310027990993197[8] = 0;
   out_8139310027990993197[9] = 0;
   out_8139310027990993197[10] = 1;
   out_8139310027990993197[11] = 0;
   out_8139310027990993197[12] = 0;
   out_8139310027990993197[13] = 0;
   out_8139310027990993197[14] = 0;
   out_8139310027990993197[15] = 0;
   out_8139310027990993197[16] = 0;
   out_8139310027990993197[17] = 0;
   out_8139310027990993197[18] = 0;
   out_8139310027990993197[19] = 0;
   out_8139310027990993197[20] = 1;
   out_8139310027990993197[21] = 0;
   out_8139310027990993197[22] = 0;
   out_8139310027990993197[23] = 0;
   out_8139310027990993197[24] = 0;
   out_8139310027990993197[25] = 0;
   out_8139310027990993197[26] = 0;
   out_8139310027990993197[27] = 0;
   out_8139310027990993197[28] = 0;
   out_8139310027990993197[29] = 0;
   out_8139310027990993197[30] = 1;
   out_8139310027990993197[31] = 0;
   out_8139310027990993197[32] = 0;
   out_8139310027990993197[33] = 0;
   out_8139310027990993197[34] = 0;
   out_8139310027990993197[35] = 0;
   out_8139310027990993197[36] = 0;
   out_8139310027990993197[37] = 0;
   out_8139310027990993197[38] = 0;
   out_8139310027990993197[39] = 0;
   out_8139310027990993197[40] = 1;
   out_8139310027990993197[41] = 0;
   out_8139310027990993197[42] = 0;
   out_8139310027990993197[43] = 0;
   out_8139310027990993197[44] = 0;
   out_8139310027990993197[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8139310027990993197[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8139310027990993197[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8139310027990993197[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8139310027990993197[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8139310027990993197[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8139310027990993197[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8139310027990993197[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8139310027990993197[53] = -9.8000000000000007*dt;
   out_8139310027990993197[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8139310027990993197[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8139310027990993197[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8139310027990993197[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8139310027990993197[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8139310027990993197[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8139310027990993197[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8139310027990993197[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8139310027990993197[62] = 0;
   out_8139310027990993197[63] = 0;
   out_8139310027990993197[64] = 0;
   out_8139310027990993197[65] = 0;
   out_8139310027990993197[66] = 0;
   out_8139310027990993197[67] = 0;
   out_8139310027990993197[68] = 0;
   out_8139310027990993197[69] = 0;
   out_8139310027990993197[70] = 1;
   out_8139310027990993197[71] = 0;
   out_8139310027990993197[72] = 0;
   out_8139310027990993197[73] = 0;
   out_8139310027990993197[74] = 0;
   out_8139310027990993197[75] = 0;
   out_8139310027990993197[76] = 0;
   out_8139310027990993197[77] = 0;
   out_8139310027990993197[78] = 0;
   out_8139310027990993197[79] = 0;
   out_8139310027990993197[80] = 1;
}
void h_25(double *state, double *unused, double *out_4906131110836938043) {
   out_4906131110836938043[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8920612812001856359) {
   out_8920612812001856359[0] = 0;
   out_8920612812001856359[1] = 0;
   out_8920612812001856359[2] = 0;
   out_8920612812001856359[3] = 0;
   out_8920612812001856359[4] = 0;
   out_8920612812001856359[5] = 0;
   out_8920612812001856359[6] = 1;
   out_8920612812001856359[7] = 0;
   out_8920612812001856359[8] = 0;
}
void h_24(double *state, double *unused, double *out_3427550057756876624) {
   out_3427550057756876624[0] = state[4];
   out_3427550057756876624[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5543808110309927359) {
   out_5543808110309927359[0] = 0;
   out_5543808110309927359[1] = 0;
   out_5543808110309927359[2] = 0;
   out_5543808110309927359[3] = 0;
   out_5543808110309927359[4] = 1;
   out_5543808110309927359[5] = 0;
   out_5543808110309927359[6] = 0;
   out_5543808110309927359[7] = 0;
   out_5543808110309927359[8] = 0;
   out_5543808110309927359[9] = 0;
   out_5543808110309927359[10] = 0;
   out_5543808110309927359[11] = 0;
   out_5543808110309927359[12] = 0;
   out_5543808110309927359[13] = 0;
   out_5543808110309927359[14] = 1;
   out_5543808110309927359[15] = 0;
   out_5543808110309927359[16] = 0;
   out_5543808110309927359[17] = 0;
}
void h_30(double *state, double *unused, double *out_5063317779188067188) {
   out_5063317779188067188[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2003922470510239604) {
   out_2003922470510239604[0] = 0;
   out_2003922470510239604[1] = 0;
   out_2003922470510239604[2] = 0;
   out_2003922470510239604[3] = 0;
   out_2003922470510239604[4] = 1;
   out_2003922470510239604[5] = 0;
   out_2003922470510239604[6] = 0;
   out_2003922470510239604[7] = 0;
   out_2003922470510239604[8] = 0;
}
void h_26(double *state, double *unused, double *out_8958065379223252895) {
   out_8958065379223252895[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5784627942833639033) {
   out_5784627942833639033[0] = 0;
   out_5784627942833639033[1] = 0;
   out_5784627942833639033[2] = 0;
   out_5784627942833639033[3] = 0;
   out_5784627942833639033[4] = 0;
   out_5784627942833639033[5] = 0;
   out_5784627942833639033[6] = 0;
   out_5784627942833639033[7] = 1;
   out_5784627942833639033[8] = 0;
}
void h_27(double *state, double *unused, double *out_7942917162281270728) {
   out_7942917162281270728[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4178685782310664515) {
   out_4178685782310664515[0] = 0;
   out_4178685782310664515[1] = 0;
   out_4178685782310664515[2] = 0;
   out_4178685782310664515[3] = 1;
   out_4178685782310664515[4] = 0;
   out_4178685782310664515[5] = 0;
   out_4178685782310664515[6] = 0;
   out_4178685782310664515[7] = 0;
   out_4178685782310664515[8] = 0;
}
void h_29(double *state, double *unused, double *out_3732991685077929952) {
   out_3732991685077929952[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1493691126195847420) {
   out_1493691126195847420[0] = 0;
   out_1493691126195847420[1] = 1;
   out_1493691126195847420[2] = 0;
   out_1493691126195847420[3] = 0;
   out_1493691126195847420[4] = 0;
   out_1493691126195847420[5] = 0;
   out_1493691126195847420[6] = 0;
   out_1493691126195847420[7] = 0;
   out_1493691126195847420[8] = 0;
}
void h_28(double *state, double *unused, double *out_2300187291200313893) {
   out_2300187291200313893[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6576090143265377994) {
   out_6576090143265377994[0] = 1;
   out_6576090143265377994[1] = 0;
   out_6576090143265377994[2] = 0;
   out_6576090143265377994[3] = 0;
   out_6576090143265377994[4] = 0;
   out_6576090143265377994[5] = 0;
   out_6576090143265377994[6] = 0;
   out_6576090143265377994[7] = 0;
   out_6576090143265377994[8] = 0;
}
void h_31(double *state, double *unused, double *out_5181325173121443932) {
   out_5181325173121443932[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8889966850124895931) {
   out_8889966850124895931[0] = 0;
   out_8889966850124895931[1] = 0;
   out_8889966850124895931[2] = 0;
   out_8889966850124895931[3] = 0;
   out_8889966850124895931[4] = 0;
   out_8889966850124895931[5] = 0;
   out_8889966850124895931[6] = 0;
   out_8889966850124895931[7] = 0;
   out_8889966850124895931[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3511157536608921668) {
  err_fun(nom_x, delta_x, out_3511157536608921668);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6431969432730020252) {
  inv_err_fun(nom_x, true_x, out_6431969432730020252);
}
void car_H_mod_fun(double *state, double *out_7948008639250905645) {
  H_mod_fun(state, out_7948008639250905645);
}
void car_f_fun(double *state, double dt, double *out_2086994761209225774) {
  f_fun(state,  dt, out_2086994761209225774);
}
void car_F_fun(double *state, double dt, double *out_8139310027990993197) {
  F_fun(state,  dt, out_8139310027990993197);
}
void car_h_25(double *state, double *unused, double *out_4906131110836938043) {
  h_25(state, unused, out_4906131110836938043);
}
void car_H_25(double *state, double *unused, double *out_8920612812001856359) {
  H_25(state, unused, out_8920612812001856359);
}
void car_h_24(double *state, double *unused, double *out_3427550057756876624) {
  h_24(state, unused, out_3427550057756876624);
}
void car_H_24(double *state, double *unused, double *out_5543808110309927359) {
  H_24(state, unused, out_5543808110309927359);
}
void car_h_30(double *state, double *unused, double *out_5063317779188067188) {
  h_30(state, unused, out_5063317779188067188);
}
void car_H_30(double *state, double *unused, double *out_2003922470510239604) {
  H_30(state, unused, out_2003922470510239604);
}
void car_h_26(double *state, double *unused, double *out_8958065379223252895) {
  h_26(state, unused, out_8958065379223252895);
}
void car_H_26(double *state, double *unused, double *out_5784627942833639033) {
  H_26(state, unused, out_5784627942833639033);
}
void car_h_27(double *state, double *unused, double *out_7942917162281270728) {
  h_27(state, unused, out_7942917162281270728);
}
void car_H_27(double *state, double *unused, double *out_4178685782310664515) {
  H_27(state, unused, out_4178685782310664515);
}
void car_h_29(double *state, double *unused, double *out_3732991685077929952) {
  h_29(state, unused, out_3732991685077929952);
}
void car_H_29(double *state, double *unused, double *out_1493691126195847420) {
  H_29(state, unused, out_1493691126195847420);
}
void car_h_28(double *state, double *unused, double *out_2300187291200313893) {
  h_28(state, unused, out_2300187291200313893);
}
void car_H_28(double *state, double *unused, double *out_6576090143265377994) {
  H_28(state, unused, out_6576090143265377994);
}
void car_h_31(double *state, double *unused, double *out_5181325173121443932) {
  h_31(state, unused, out_5181325173121443932);
}
void car_H_31(double *state, double *unused, double *out_8889966850124895931) {
  H_31(state, unused, out_8889966850124895931);
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
