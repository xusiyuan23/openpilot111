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
void err_fun(double *nom_x, double *delta_x, double *out_3028736888961783120) {
   out_3028736888961783120[0] = delta_x[0] + nom_x[0];
   out_3028736888961783120[1] = delta_x[1] + nom_x[1];
   out_3028736888961783120[2] = delta_x[2] + nom_x[2];
   out_3028736888961783120[3] = delta_x[3] + nom_x[3];
   out_3028736888961783120[4] = delta_x[4] + nom_x[4];
   out_3028736888961783120[5] = delta_x[5] + nom_x[5];
   out_3028736888961783120[6] = delta_x[6] + nom_x[6];
   out_3028736888961783120[7] = delta_x[7] + nom_x[7];
   out_3028736888961783120[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3218082572571671239) {
   out_3218082572571671239[0] = -nom_x[0] + true_x[0];
   out_3218082572571671239[1] = -nom_x[1] + true_x[1];
   out_3218082572571671239[2] = -nom_x[2] + true_x[2];
   out_3218082572571671239[3] = -nom_x[3] + true_x[3];
   out_3218082572571671239[4] = -nom_x[4] + true_x[4];
   out_3218082572571671239[5] = -nom_x[5] + true_x[5];
   out_3218082572571671239[6] = -nom_x[6] + true_x[6];
   out_3218082572571671239[7] = -nom_x[7] + true_x[7];
   out_3218082572571671239[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1114876351103919435) {
   out_1114876351103919435[0] = 1.0;
   out_1114876351103919435[1] = 0;
   out_1114876351103919435[2] = 0;
   out_1114876351103919435[3] = 0;
   out_1114876351103919435[4] = 0;
   out_1114876351103919435[5] = 0;
   out_1114876351103919435[6] = 0;
   out_1114876351103919435[7] = 0;
   out_1114876351103919435[8] = 0;
   out_1114876351103919435[9] = 0;
   out_1114876351103919435[10] = 1.0;
   out_1114876351103919435[11] = 0;
   out_1114876351103919435[12] = 0;
   out_1114876351103919435[13] = 0;
   out_1114876351103919435[14] = 0;
   out_1114876351103919435[15] = 0;
   out_1114876351103919435[16] = 0;
   out_1114876351103919435[17] = 0;
   out_1114876351103919435[18] = 0;
   out_1114876351103919435[19] = 0;
   out_1114876351103919435[20] = 1.0;
   out_1114876351103919435[21] = 0;
   out_1114876351103919435[22] = 0;
   out_1114876351103919435[23] = 0;
   out_1114876351103919435[24] = 0;
   out_1114876351103919435[25] = 0;
   out_1114876351103919435[26] = 0;
   out_1114876351103919435[27] = 0;
   out_1114876351103919435[28] = 0;
   out_1114876351103919435[29] = 0;
   out_1114876351103919435[30] = 1.0;
   out_1114876351103919435[31] = 0;
   out_1114876351103919435[32] = 0;
   out_1114876351103919435[33] = 0;
   out_1114876351103919435[34] = 0;
   out_1114876351103919435[35] = 0;
   out_1114876351103919435[36] = 0;
   out_1114876351103919435[37] = 0;
   out_1114876351103919435[38] = 0;
   out_1114876351103919435[39] = 0;
   out_1114876351103919435[40] = 1.0;
   out_1114876351103919435[41] = 0;
   out_1114876351103919435[42] = 0;
   out_1114876351103919435[43] = 0;
   out_1114876351103919435[44] = 0;
   out_1114876351103919435[45] = 0;
   out_1114876351103919435[46] = 0;
   out_1114876351103919435[47] = 0;
   out_1114876351103919435[48] = 0;
   out_1114876351103919435[49] = 0;
   out_1114876351103919435[50] = 1.0;
   out_1114876351103919435[51] = 0;
   out_1114876351103919435[52] = 0;
   out_1114876351103919435[53] = 0;
   out_1114876351103919435[54] = 0;
   out_1114876351103919435[55] = 0;
   out_1114876351103919435[56] = 0;
   out_1114876351103919435[57] = 0;
   out_1114876351103919435[58] = 0;
   out_1114876351103919435[59] = 0;
   out_1114876351103919435[60] = 1.0;
   out_1114876351103919435[61] = 0;
   out_1114876351103919435[62] = 0;
   out_1114876351103919435[63] = 0;
   out_1114876351103919435[64] = 0;
   out_1114876351103919435[65] = 0;
   out_1114876351103919435[66] = 0;
   out_1114876351103919435[67] = 0;
   out_1114876351103919435[68] = 0;
   out_1114876351103919435[69] = 0;
   out_1114876351103919435[70] = 1.0;
   out_1114876351103919435[71] = 0;
   out_1114876351103919435[72] = 0;
   out_1114876351103919435[73] = 0;
   out_1114876351103919435[74] = 0;
   out_1114876351103919435[75] = 0;
   out_1114876351103919435[76] = 0;
   out_1114876351103919435[77] = 0;
   out_1114876351103919435[78] = 0;
   out_1114876351103919435[79] = 0;
   out_1114876351103919435[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6826993337149264426) {
   out_6826993337149264426[0] = state[0];
   out_6826993337149264426[1] = state[1];
   out_6826993337149264426[2] = state[2];
   out_6826993337149264426[3] = state[3];
   out_6826993337149264426[4] = state[4];
   out_6826993337149264426[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6826993337149264426[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6826993337149264426[7] = state[7];
   out_6826993337149264426[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5391441206083204607) {
   out_5391441206083204607[0] = 1;
   out_5391441206083204607[1] = 0;
   out_5391441206083204607[2] = 0;
   out_5391441206083204607[3] = 0;
   out_5391441206083204607[4] = 0;
   out_5391441206083204607[5] = 0;
   out_5391441206083204607[6] = 0;
   out_5391441206083204607[7] = 0;
   out_5391441206083204607[8] = 0;
   out_5391441206083204607[9] = 0;
   out_5391441206083204607[10] = 1;
   out_5391441206083204607[11] = 0;
   out_5391441206083204607[12] = 0;
   out_5391441206083204607[13] = 0;
   out_5391441206083204607[14] = 0;
   out_5391441206083204607[15] = 0;
   out_5391441206083204607[16] = 0;
   out_5391441206083204607[17] = 0;
   out_5391441206083204607[18] = 0;
   out_5391441206083204607[19] = 0;
   out_5391441206083204607[20] = 1;
   out_5391441206083204607[21] = 0;
   out_5391441206083204607[22] = 0;
   out_5391441206083204607[23] = 0;
   out_5391441206083204607[24] = 0;
   out_5391441206083204607[25] = 0;
   out_5391441206083204607[26] = 0;
   out_5391441206083204607[27] = 0;
   out_5391441206083204607[28] = 0;
   out_5391441206083204607[29] = 0;
   out_5391441206083204607[30] = 1;
   out_5391441206083204607[31] = 0;
   out_5391441206083204607[32] = 0;
   out_5391441206083204607[33] = 0;
   out_5391441206083204607[34] = 0;
   out_5391441206083204607[35] = 0;
   out_5391441206083204607[36] = 0;
   out_5391441206083204607[37] = 0;
   out_5391441206083204607[38] = 0;
   out_5391441206083204607[39] = 0;
   out_5391441206083204607[40] = 1;
   out_5391441206083204607[41] = 0;
   out_5391441206083204607[42] = 0;
   out_5391441206083204607[43] = 0;
   out_5391441206083204607[44] = 0;
   out_5391441206083204607[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5391441206083204607[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5391441206083204607[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5391441206083204607[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5391441206083204607[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5391441206083204607[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5391441206083204607[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5391441206083204607[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5391441206083204607[53] = -9.8000000000000007*dt;
   out_5391441206083204607[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5391441206083204607[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5391441206083204607[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5391441206083204607[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5391441206083204607[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5391441206083204607[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5391441206083204607[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5391441206083204607[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5391441206083204607[62] = 0;
   out_5391441206083204607[63] = 0;
   out_5391441206083204607[64] = 0;
   out_5391441206083204607[65] = 0;
   out_5391441206083204607[66] = 0;
   out_5391441206083204607[67] = 0;
   out_5391441206083204607[68] = 0;
   out_5391441206083204607[69] = 0;
   out_5391441206083204607[70] = 1;
   out_5391441206083204607[71] = 0;
   out_5391441206083204607[72] = 0;
   out_5391441206083204607[73] = 0;
   out_5391441206083204607[74] = 0;
   out_5391441206083204607[75] = 0;
   out_5391441206083204607[76] = 0;
   out_5391441206083204607[77] = 0;
   out_5391441206083204607[78] = 0;
   out_5391441206083204607[79] = 0;
   out_5391441206083204607[80] = 1;
}
void h_25(double *state, double *unused, double *out_3881631893549789208) {
   out_3881631893549789208[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7267345600465790480) {
   out_7267345600465790480[0] = 0;
   out_7267345600465790480[1] = 0;
   out_7267345600465790480[2] = 0;
   out_7267345600465790480[3] = 0;
   out_7267345600465790480[4] = 0;
   out_7267345600465790480[5] = 0;
   out_7267345600465790480[6] = 1;
   out_7267345600465790480[7] = 0;
   out_7267345600465790480[8] = 0;
}
void h_24(double *state, double *unused, double *out_700870389243627536) {
   out_700870389243627536[0] = state[4];
   out_700870389243627536[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5094696001460290914) {
   out_5094696001460290914[0] = 0;
   out_5094696001460290914[1] = 0;
   out_5094696001460290914[2] = 0;
   out_5094696001460290914[3] = 0;
   out_5094696001460290914[4] = 1;
   out_5094696001460290914[5] = 0;
   out_5094696001460290914[6] = 0;
   out_5094696001460290914[7] = 0;
   out_5094696001460290914[8] = 0;
   out_5094696001460290914[9] = 0;
   out_5094696001460290914[10] = 0;
   out_5094696001460290914[11] = 0;
   out_5094696001460290914[12] = 0;
   out_5094696001460290914[13] = 0;
   out_5094696001460290914[14] = 1;
   out_5094696001460290914[15] = 0;
   out_5094696001460290914[16] = 0;
   out_5094696001460290914[17] = 0;
}
void h_30(double *state, double *unused, double *out_6829357883905274169) {
   out_6829357883905274169[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4262708131752144381) {
   out_4262708131752144381[0] = 0;
   out_4262708131752144381[1] = 0;
   out_4262708131752144381[2] = 0;
   out_4262708131752144381[3] = 0;
   out_4262708131752144381[4] = 1;
   out_4262708131752144381[5] = 0;
   out_4262708131752144381[6] = 0;
   out_4262708131752144381[7] = 0;
   out_4262708131752144381[8] = 0;
}
void h_26(double *state, double *unused, double *out_1827684616244428524) {
   out_1827684616244428524[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3525842281591734256) {
   out_3525842281591734256[0] = 0;
   out_3525842281591734256[1] = 0;
   out_3525842281591734256[2] = 0;
   out_3525842281591734256[3] = 0;
   out_3525842281591734256[4] = 0;
   out_3525842281591734256[5] = 0;
   out_3525842281591734256[6] = 0;
   out_3525842281591734256[7] = 1;
   out_3525842281591734256[8] = 0;
}
void h_27(double *state, double *unused, double *out_6761232746364086773) {
   out_6761232746364086773[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6437471443552569292) {
   out_6437471443552569292[0] = 0;
   out_6437471443552569292[1] = 0;
   out_6437471443552569292[2] = 0;
   out_6437471443552569292[3] = 1;
   out_6437471443552569292[4] = 0;
   out_6437471443552569292[5] = 0;
   out_6437471443552569292[6] = 0;
   out_6437471443552569292[7] = 0;
   out_6437471443552569292[8] = 0;
}
void h_29(double *state, double *unused, double *out_6615712922143431802) {
   out_6615712922143431802[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8150834170422120325) {
   out_8150834170422120325[0] = 0;
   out_8150834170422120325[1] = 1;
   out_8150834170422120325[2] = 0;
   out_8150834170422120325[3] = 0;
   out_8150834170422120325[4] = 0;
   out_8150834170422120325[5] = 0;
   out_8150834170422120325[6] = 0;
   out_8150834170422120325[7] = 0;
   out_8150834170422120325[8] = 0;
}
void h_28(double *state, double *unused, double *out_1759559478703241128) {
   out_1759559478703241128[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5213510886217900717) {
   out_5213510886217900717[0] = 1;
   out_5213510886217900717[1] = 0;
   out_5213510886217900717[2] = 0;
   out_5213510886217900717[3] = 0;
   out_5213510886217900717[4] = 0;
   out_5213510886217900717[5] = 0;
   out_5213510886217900717[6] = 0;
   out_5213510886217900717[7] = 0;
   out_5213510886217900717[8] = 0;
}
void h_31(double *state, double *unused, double *out_3999640757204259977) {
   out_3999640757204259977[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7297991562342750908) {
   out_7297991562342750908[0] = 0;
   out_7297991562342750908[1] = 0;
   out_7297991562342750908[2] = 0;
   out_7297991562342750908[3] = 0;
   out_7297991562342750908[4] = 0;
   out_7297991562342750908[5] = 0;
   out_7297991562342750908[6] = 0;
   out_7297991562342750908[7] = 0;
   out_7297991562342750908[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3028736888961783120) {
  err_fun(nom_x, delta_x, out_3028736888961783120);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3218082572571671239) {
  inv_err_fun(nom_x, true_x, out_3218082572571671239);
}
void car_H_mod_fun(double *state, double *out_1114876351103919435) {
  H_mod_fun(state, out_1114876351103919435);
}
void car_f_fun(double *state, double dt, double *out_6826993337149264426) {
  f_fun(state,  dt, out_6826993337149264426);
}
void car_F_fun(double *state, double dt, double *out_5391441206083204607) {
  F_fun(state,  dt, out_5391441206083204607);
}
void car_h_25(double *state, double *unused, double *out_3881631893549789208) {
  h_25(state, unused, out_3881631893549789208);
}
void car_H_25(double *state, double *unused, double *out_7267345600465790480) {
  H_25(state, unused, out_7267345600465790480);
}
void car_h_24(double *state, double *unused, double *out_700870389243627536) {
  h_24(state, unused, out_700870389243627536);
}
void car_H_24(double *state, double *unused, double *out_5094696001460290914) {
  H_24(state, unused, out_5094696001460290914);
}
void car_h_30(double *state, double *unused, double *out_6829357883905274169) {
  h_30(state, unused, out_6829357883905274169);
}
void car_H_30(double *state, double *unused, double *out_4262708131752144381) {
  H_30(state, unused, out_4262708131752144381);
}
void car_h_26(double *state, double *unused, double *out_1827684616244428524) {
  h_26(state, unused, out_1827684616244428524);
}
void car_H_26(double *state, double *unused, double *out_3525842281591734256) {
  H_26(state, unused, out_3525842281591734256);
}
void car_h_27(double *state, double *unused, double *out_6761232746364086773) {
  h_27(state, unused, out_6761232746364086773);
}
void car_H_27(double *state, double *unused, double *out_6437471443552569292) {
  H_27(state, unused, out_6437471443552569292);
}
void car_h_29(double *state, double *unused, double *out_6615712922143431802) {
  h_29(state, unused, out_6615712922143431802);
}
void car_H_29(double *state, double *unused, double *out_8150834170422120325) {
  H_29(state, unused, out_8150834170422120325);
}
void car_h_28(double *state, double *unused, double *out_1759559478703241128) {
  h_28(state, unused, out_1759559478703241128);
}
void car_H_28(double *state, double *unused, double *out_5213510886217900717) {
  H_28(state, unused, out_5213510886217900717);
}
void car_h_31(double *state, double *unused, double *out_3999640757204259977) {
  h_31(state, unused, out_3999640757204259977);
}
void car_H_31(double *state, double *unused, double *out_7297991562342750908) {
  H_31(state, unused, out_7297991562342750908);
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
