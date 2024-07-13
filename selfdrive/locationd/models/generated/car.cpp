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
void err_fun(double *nom_x, double *delta_x, double *out_7683831691601887608) {
   out_7683831691601887608[0] = delta_x[0] + nom_x[0];
   out_7683831691601887608[1] = delta_x[1] + nom_x[1];
   out_7683831691601887608[2] = delta_x[2] + nom_x[2];
   out_7683831691601887608[3] = delta_x[3] + nom_x[3];
   out_7683831691601887608[4] = delta_x[4] + nom_x[4];
   out_7683831691601887608[5] = delta_x[5] + nom_x[5];
   out_7683831691601887608[6] = delta_x[6] + nom_x[6];
   out_7683831691601887608[7] = delta_x[7] + nom_x[7];
   out_7683831691601887608[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2772021370076241199) {
   out_2772021370076241199[0] = -nom_x[0] + true_x[0];
   out_2772021370076241199[1] = -nom_x[1] + true_x[1];
   out_2772021370076241199[2] = -nom_x[2] + true_x[2];
   out_2772021370076241199[3] = -nom_x[3] + true_x[3];
   out_2772021370076241199[4] = -nom_x[4] + true_x[4];
   out_2772021370076241199[5] = -nom_x[5] + true_x[5];
   out_2772021370076241199[6] = -nom_x[6] + true_x[6];
   out_2772021370076241199[7] = -nom_x[7] + true_x[7];
   out_2772021370076241199[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2876076255899625510) {
   out_2876076255899625510[0] = 1.0;
   out_2876076255899625510[1] = 0;
   out_2876076255899625510[2] = 0;
   out_2876076255899625510[3] = 0;
   out_2876076255899625510[4] = 0;
   out_2876076255899625510[5] = 0;
   out_2876076255899625510[6] = 0;
   out_2876076255899625510[7] = 0;
   out_2876076255899625510[8] = 0;
   out_2876076255899625510[9] = 0;
   out_2876076255899625510[10] = 1.0;
   out_2876076255899625510[11] = 0;
   out_2876076255899625510[12] = 0;
   out_2876076255899625510[13] = 0;
   out_2876076255899625510[14] = 0;
   out_2876076255899625510[15] = 0;
   out_2876076255899625510[16] = 0;
   out_2876076255899625510[17] = 0;
   out_2876076255899625510[18] = 0;
   out_2876076255899625510[19] = 0;
   out_2876076255899625510[20] = 1.0;
   out_2876076255899625510[21] = 0;
   out_2876076255899625510[22] = 0;
   out_2876076255899625510[23] = 0;
   out_2876076255899625510[24] = 0;
   out_2876076255899625510[25] = 0;
   out_2876076255899625510[26] = 0;
   out_2876076255899625510[27] = 0;
   out_2876076255899625510[28] = 0;
   out_2876076255899625510[29] = 0;
   out_2876076255899625510[30] = 1.0;
   out_2876076255899625510[31] = 0;
   out_2876076255899625510[32] = 0;
   out_2876076255899625510[33] = 0;
   out_2876076255899625510[34] = 0;
   out_2876076255899625510[35] = 0;
   out_2876076255899625510[36] = 0;
   out_2876076255899625510[37] = 0;
   out_2876076255899625510[38] = 0;
   out_2876076255899625510[39] = 0;
   out_2876076255899625510[40] = 1.0;
   out_2876076255899625510[41] = 0;
   out_2876076255899625510[42] = 0;
   out_2876076255899625510[43] = 0;
   out_2876076255899625510[44] = 0;
   out_2876076255899625510[45] = 0;
   out_2876076255899625510[46] = 0;
   out_2876076255899625510[47] = 0;
   out_2876076255899625510[48] = 0;
   out_2876076255899625510[49] = 0;
   out_2876076255899625510[50] = 1.0;
   out_2876076255899625510[51] = 0;
   out_2876076255899625510[52] = 0;
   out_2876076255899625510[53] = 0;
   out_2876076255899625510[54] = 0;
   out_2876076255899625510[55] = 0;
   out_2876076255899625510[56] = 0;
   out_2876076255899625510[57] = 0;
   out_2876076255899625510[58] = 0;
   out_2876076255899625510[59] = 0;
   out_2876076255899625510[60] = 1.0;
   out_2876076255899625510[61] = 0;
   out_2876076255899625510[62] = 0;
   out_2876076255899625510[63] = 0;
   out_2876076255899625510[64] = 0;
   out_2876076255899625510[65] = 0;
   out_2876076255899625510[66] = 0;
   out_2876076255899625510[67] = 0;
   out_2876076255899625510[68] = 0;
   out_2876076255899625510[69] = 0;
   out_2876076255899625510[70] = 1.0;
   out_2876076255899625510[71] = 0;
   out_2876076255899625510[72] = 0;
   out_2876076255899625510[73] = 0;
   out_2876076255899625510[74] = 0;
   out_2876076255899625510[75] = 0;
   out_2876076255899625510[76] = 0;
   out_2876076255899625510[77] = 0;
   out_2876076255899625510[78] = 0;
   out_2876076255899625510[79] = 0;
   out_2876076255899625510[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_711338878401685436) {
   out_711338878401685436[0] = state[0];
   out_711338878401685436[1] = state[1];
   out_711338878401685436[2] = state[2];
   out_711338878401685436[3] = state[3];
   out_711338878401685436[4] = state[4];
   out_711338878401685436[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_711338878401685436[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_711338878401685436[7] = state[7];
   out_711338878401685436[8] = state[8];
}
void F_fun(double *state, double dt, double *out_782397592704791785) {
   out_782397592704791785[0] = 1;
   out_782397592704791785[1] = 0;
   out_782397592704791785[2] = 0;
   out_782397592704791785[3] = 0;
   out_782397592704791785[4] = 0;
   out_782397592704791785[5] = 0;
   out_782397592704791785[6] = 0;
   out_782397592704791785[7] = 0;
   out_782397592704791785[8] = 0;
   out_782397592704791785[9] = 0;
   out_782397592704791785[10] = 1;
   out_782397592704791785[11] = 0;
   out_782397592704791785[12] = 0;
   out_782397592704791785[13] = 0;
   out_782397592704791785[14] = 0;
   out_782397592704791785[15] = 0;
   out_782397592704791785[16] = 0;
   out_782397592704791785[17] = 0;
   out_782397592704791785[18] = 0;
   out_782397592704791785[19] = 0;
   out_782397592704791785[20] = 1;
   out_782397592704791785[21] = 0;
   out_782397592704791785[22] = 0;
   out_782397592704791785[23] = 0;
   out_782397592704791785[24] = 0;
   out_782397592704791785[25] = 0;
   out_782397592704791785[26] = 0;
   out_782397592704791785[27] = 0;
   out_782397592704791785[28] = 0;
   out_782397592704791785[29] = 0;
   out_782397592704791785[30] = 1;
   out_782397592704791785[31] = 0;
   out_782397592704791785[32] = 0;
   out_782397592704791785[33] = 0;
   out_782397592704791785[34] = 0;
   out_782397592704791785[35] = 0;
   out_782397592704791785[36] = 0;
   out_782397592704791785[37] = 0;
   out_782397592704791785[38] = 0;
   out_782397592704791785[39] = 0;
   out_782397592704791785[40] = 1;
   out_782397592704791785[41] = 0;
   out_782397592704791785[42] = 0;
   out_782397592704791785[43] = 0;
   out_782397592704791785[44] = 0;
   out_782397592704791785[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_782397592704791785[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_782397592704791785[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_782397592704791785[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_782397592704791785[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_782397592704791785[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_782397592704791785[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_782397592704791785[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_782397592704791785[53] = -9.8000000000000007*dt;
   out_782397592704791785[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_782397592704791785[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_782397592704791785[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_782397592704791785[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_782397592704791785[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_782397592704791785[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_782397592704791785[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_782397592704791785[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_782397592704791785[62] = 0;
   out_782397592704791785[63] = 0;
   out_782397592704791785[64] = 0;
   out_782397592704791785[65] = 0;
   out_782397592704791785[66] = 0;
   out_782397592704791785[67] = 0;
   out_782397592704791785[68] = 0;
   out_782397592704791785[69] = 0;
   out_782397592704791785[70] = 1;
   out_782397592704791785[71] = 0;
   out_782397592704791785[72] = 0;
   out_782397592704791785[73] = 0;
   out_782397592704791785[74] = 0;
   out_782397592704791785[75] = 0;
   out_782397592704791785[76] = 0;
   out_782397592704791785[77] = 0;
   out_782397592704791785[78] = 0;
   out_782397592704791785[79] = 0;
   out_782397592704791785[80] = 1;
}
void h_25(double *state, double *unused, double *out_2211854499255104178) {
   out_2211854499255104178[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2676605904450648455) {
   out_2676605904450648455[0] = 0;
   out_2676605904450648455[1] = 0;
   out_2676605904450648455[2] = 0;
   out_2676605904450648455[3] = 0;
   out_2676605904450648455[4] = 0;
   out_2676605904450648455[5] = 0;
   out_2676605904450648455[6] = 1;
   out_2676605904450648455[7] = 0;
   out_2676605904450648455[8] = 0;
}
void h_24(double *state, double *unused, double *out_3020119525027846586) {
   out_3020119525027846586[0] = state[4];
   out_3020119525027846586[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3521602513234343854) {
   out_3521602513234343854[0] = 0;
   out_3521602513234343854[1] = 0;
   out_3521602513234343854[2] = 0;
   out_3521602513234343854[3] = 0;
   out_3521602513234343854[4] = 1;
   out_3521602513234343854[5] = 0;
   out_3521602513234343854[6] = 0;
   out_3521602513234343854[7] = 0;
   out_3521602513234343854[8] = 0;
   out_3521602513234343854[9] = 0;
   out_3521602513234343854[10] = 0;
   out_3521602513234343854[11] = 0;
   out_3521602513234343854[12] = 0;
   out_3521602513234343854[13] = 0;
   out_3521602513234343854[14] = 1;
   out_3521602513234343854[15] = 0;
   out_3521602513234343854[16] = 0;
   out_3521602513234343854[17] = 0;
}
void h_30(double *state, double *unused, double *out_1936660436970598289) {
   out_1936660436970598289[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5194938862957897082) {
   out_5194938862957897082[0] = 0;
   out_5194938862957897082[1] = 0;
   out_5194938862957897082[2] = 0;
   out_5194938862957897082[3] = 0;
   out_5194938862957897082[4] = 1;
   out_5194938862957897082[5] = 0;
   out_5194938862957897082[6] = 0;
   out_5194938862957897082[7] = 0;
   out_5194938862957897082[8] = 0;
}
void h_26(double *state, double *unused, double *out_667744883838099362) {
   out_667744883838099362[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1064897414423407769) {
   out_1064897414423407769[0] = 0;
   out_1064897414423407769[1] = 0;
   out_1064897414423407769[2] = 0;
   out_1064897414423407769[3] = 0;
   out_1064897414423407769[4] = 0;
   out_1064897414423407769[5] = 0;
   out_1064897414423407769[6] = 0;
   out_1064897414423407769[7] = 1;
   out_1064897414423407769[8] = 0;
}
void h_27(double *state, double *unused, double *out_7553721735141134741) {
   out_7553721735141134741[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7418532934141840299) {
   out_7418532934141840299[0] = 0;
   out_7418532934141840299[1] = 0;
   out_7418532934141840299[2] = 0;
   out_7418532934141840299[3] = 1;
   out_7418532934141840299[4] = 0;
   out_7418532934141840299[5] = 0;
   out_7418532934141840299[6] = 0;
   out_7418532934141840299[7] = 0;
   out_7418532934141840299[8] = 0;
}
void h_29(double *state, double *unused, double *out_9074940202310252514) {
   out_9074940202310252514[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5705170207272289266) {
   out_5705170207272289266[0] = 0;
   out_5705170207272289266[1] = 1;
   out_5705170207272289266[2] = 0;
   out_5705170207272289266[3] = 0;
   out_5705170207272289266[4] = 0;
   out_5705170207272289266[5] = 0;
   out_5705170207272289266[6] = 0;
   out_5705170207272289266[7] = 0;
   out_5705170207272289266[8] = 0;
}
void h_28(double *state, double *unused, double *out_2552048467480289096) {
   out_2552048467480289096[0] = state[0];
}
void H_28(double *state, double *unused, double *out_622771190202758692) {
   out_622771190202758692[0] = 1;
   out_622771190202758692[1] = 0;
   out_622771190202758692[2] = 0;
   out_622771190202758692[3] = 0;
   out_622771190202758692[4] = 0;
   out_622771190202758692[5] = 0;
   out_622771190202758692[6] = 0;
   out_622771190202758692[7] = 0;
   out_622771190202758692[8] = 0;
}
void h_31(double *state, double *unused, double *out_5159580489610589139) {
   out_5159580489610589139[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2707251866327608883) {
   out_2707251866327608883[0] = 0;
   out_2707251866327608883[1] = 0;
   out_2707251866327608883[2] = 0;
   out_2707251866327608883[3] = 0;
   out_2707251866327608883[4] = 0;
   out_2707251866327608883[5] = 0;
   out_2707251866327608883[6] = 0;
   out_2707251866327608883[7] = 0;
   out_2707251866327608883[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7683831691601887608) {
  err_fun(nom_x, delta_x, out_7683831691601887608);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2772021370076241199) {
  inv_err_fun(nom_x, true_x, out_2772021370076241199);
}
void car_H_mod_fun(double *state, double *out_2876076255899625510) {
  H_mod_fun(state, out_2876076255899625510);
}
void car_f_fun(double *state, double dt, double *out_711338878401685436) {
  f_fun(state,  dt, out_711338878401685436);
}
void car_F_fun(double *state, double dt, double *out_782397592704791785) {
  F_fun(state,  dt, out_782397592704791785);
}
void car_h_25(double *state, double *unused, double *out_2211854499255104178) {
  h_25(state, unused, out_2211854499255104178);
}
void car_H_25(double *state, double *unused, double *out_2676605904450648455) {
  H_25(state, unused, out_2676605904450648455);
}
void car_h_24(double *state, double *unused, double *out_3020119525027846586) {
  h_24(state, unused, out_3020119525027846586);
}
void car_H_24(double *state, double *unused, double *out_3521602513234343854) {
  H_24(state, unused, out_3521602513234343854);
}
void car_h_30(double *state, double *unused, double *out_1936660436970598289) {
  h_30(state, unused, out_1936660436970598289);
}
void car_H_30(double *state, double *unused, double *out_5194938862957897082) {
  H_30(state, unused, out_5194938862957897082);
}
void car_h_26(double *state, double *unused, double *out_667744883838099362) {
  h_26(state, unused, out_667744883838099362);
}
void car_H_26(double *state, double *unused, double *out_1064897414423407769) {
  H_26(state, unused, out_1064897414423407769);
}
void car_h_27(double *state, double *unused, double *out_7553721735141134741) {
  h_27(state, unused, out_7553721735141134741);
}
void car_H_27(double *state, double *unused, double *out_7418532934141840299) {
  H_27(state, unused, out_7418532934141840299);
}
void car_h_29(double *state, double *unused, double *out_9074940202310252514) {
  h_29(state, unused, out_9074940202310252514);
}
void car_H_29(double *state, double *unused, double *out_5705170207272289266) {
  H_29(state, unused, out_5705170207272289266);
}
void car_h_28(double *state, double *unused, double *out_2552048467480289096) {
  h_28(state, unused, out_2552048467480289096);
}
void car_H_28(double *state, double *unused, double *out_622771190202758692) {
  H_28(state, unused, out_622771190202758692);
}
void car_h_31(double *state, double *unused, double *out_5159580489610589139) {
  h_31(state, unused, out_5159580489610589139);
}
void car_H_31(double *state, double *unused, double *out_2707251866327608883) {
  H_31(state, unused, out_2707251866327608883);
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

ekf_lib_init(car)
