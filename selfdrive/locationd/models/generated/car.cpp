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
void err_fun(double *nom_x, double *delta_x, double *out_4583207975382893756) {
   out_4583207975382893756[0] = delta_x[0] + nom_x[0];
   out_4583207975382893756[1] = delta_x[1] + nom_x[1];
   out_4583207975382893756[2] = delta_x[2] + nom_x[2];
   out_4583207975382893756[3] = delta_x[3] + nom_x[3];
   out_4583207975382893756[4] = delta_x[4] + nom_x[4];
   out_4583207975382893756[5] = delta_x[5] + nom_x[5];
   out_4583207975382893756[6] = delta_x[6] + nom_x[6];
   out_4583207975382893756[7] = delta_x[7] + nom_x[7];
   out_4583207975382893756[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9143150462401985555) {
   out_9143150462401985555[0] = -nom_x[0] + true_x[0];
   out_9143150462401985555[1] = -nom_x[1] + true_x[1];
   out_9143150462401985555[2] = -nom_x[2] + true_x[2];
   out_9143150462401985555[3] = -nom_x[3] + true_x[3];
   out_9143150462401985555[4] = -nom_x[4] + true_x[4];
   out_9143150462401985555[5] = -nom_x[5] + true_x[5];
   out_9143150462401985555[6] = -nom_x[6] + true_x[6];
   out_9143150462401985555[7] = -nom_x[7] + true_x[7];
   out_9143150462401985555[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3358041296692552281) {
   out_3358041296692552281[0] = 1.0;
   out_3358041296692552281[1] = 0;
   out_3358041296692552281[2] = 0;
   out_3358041296692552281[3] = 0;
   out_3358041296692552281[4] = 0;
   out_3358041296692552281[5] = 0;
   out_3358041296692552281[6] = 0;
   out_3358041296692552281[7] = 0;
   out_3358041296692552281[8] = 0;
   out_3358041296692552281[9] = 0;
   out_3358041296692552281[10] = 1.0;
   out_3358041296692552281[11] = 0;
   out_3358041296692552281[12] = 0;
   out_3358041296692552281[13] = 0;
   out_3358041296692552281[14] = 0;
   out_3358041296692552281[15] = 0;
   out_3358041296692552281[16] = 0;
   out_3358041296692552281[17] = 0;
   out_3358041296692552281[18] = 0;
   out_3358041296692552281[19] = 0;
   out_3358041296692552281[20] = 1.0;
   out_3358041296692552281[21] = 0;
   out_3358041296692552281[22] = 0;
   out_3358041296692552281[23] = 0;
   out_3358041296692552281[24] = 0;
   out_3358041296692552281[25] = 0;
   out_3358041296692552281[26] = 0;
   out_3358041296692552281[27] = 0;
   out_3358041296692552281[28] = 0;
   out_3358041296692552281[29] = 0;
   out_3358041296692552281[30] = 1.0;
   out_3358041296692552281[31] = 0;
   out_3358041296692552281[32] = 0;
   out_3358041296692552281[33] = 0;
   out_3358041296692552281[34] = 0;
   out_3358041296692552281[35] = 0;
   out_3358041296692552281[36] = 0;
   out_3358041296692552281[37] = 0;
   out_3358041296692552281[38] = 0;
   out_3358041296692552281[39] = 0;
   out_3358041296692552281[40] = 1.0;
   out_3358041296692552281[41] = 0;
   out_3358041296692552281[42] = 0;
   out_3358041296692552281[43] = 0;
   out_3358041296692552281[44] = 0;
   out_3358041296692552281[45] = 0;
   out_3358041296692552281[46] = 0;
   out_3358041296692552281[47] = 0;
   out_3358041296692552281[48] = 0;
   out_3358041296692552281[49] = 0;
   out_3358041296692552281[50] = 1.0;
   out_3358041296692552281[51] = 0;
   out_3358041296692552281[52] = 0;
   out_3358041296692552281[53] = 0;
   out_3358041296692552281[54] = 0;
   out_3358041296692552281[55] = 0;
   out_3358041296692552281[56] = 0;
   out_3358041296692552281[57] = 0;
   out_3358041296692552281[58] = 0;
   out_3358041296692552281[59] = 0;
   out_3358041296692552281[60] = 1.0;
   out_3358041296692552281[61] = 0;
   out_3358041296692552281[62] = 0;
   out_3358041296692552281[63] = 0;
   out_3358041296692552281[64] = 0;
   out_3358041296692552281[65] = 0;
   out_3358041296692552281[66] = 0;
   out_3358041296692552281[67] = 0;
   out_3358041296692552281[68] = 0;
   out_3358041296692552281[69] = 0;
   out_3358041296692552281[70] = 1.0;
   out_3358041296692552281[71] = 0;
   out_3358041296692552281[72] = 0;
   out_3358041296692552281[73] = 0;
   out_3358041296692552281[74] = 0;
   out_3358041296692552281[75] = 0;
   out_3358041296692552281[76] = 0;
   out_3358041296692552281[77] = 0;
   out_3358041296692552281[78] = 0;
   out_3358041296692552281[79] = 0;
   out_3358041296692552281[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8358470198575263086) {
   out_8358470198575263086[0] = state[0];
   out_8358470198575263086[1] = state[1];
   out_8358470198575263086[2] = state[2];
   out_8358470198575263086[3] = state[3];
   out_8358470198575263086[4] = state[4];
   out_8358470198575263086[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8358470198575263086[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8358470198575263086[7] = state[7];
   out_8358470198575263086[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2436312018501040113) {
   out_2436312018501040113[0] = 1;
   out_2436312018501040113[1] = 0;
   out_2436312018501040113[2] = 0;
   out_2436312018501040113[3] = 0;
   out_2436312018501040113[4] = 0;
   out_2436312018501040113[5] = 0;
   out_2436312018501040113[6] = 0;
   out_2436312018501040113[7] = 0;
   out_2436312018501040113[8] = 0;
   out_2436312018501040113[9] = 0;
   out_2436312018501040113[10] = 1;
   out_2436312018501040113[11] = 0;
   out_2436312018501040113[12] = 0;
   out_2436312018501040113[13] = 0;
   out_2436312018501040113[14] = 0;
   out_2436312018501040113[15] = 0;
   out_2436312018501040113[16] = 0;
   out_2436312018501040113[17] = 0;
   out_2436312018501040113[18] = 0;
   out_2436312018501040113[19] = 0;
   out_2436312018501040113[20] = 1;
   out_2436312018501040113[21] = 0;
   out_2436312018501040113[22] = 0;
   out_2436312018501040113[23] = 0;
   out_2436312018501040113[24] = 0;
   out_2436312018501040113[25] = 0;
   out_2436312018501040113[26] = 0;
   out_2436312018501040113[27] = 0;
   out_2436312018501040113[28] = 0;
   out_2436312018501040113[29] = 0;
   out_2436312018501040113[30] = 1;
   out_2436312018501040113[31] = 0;
   out_2436312018501040113[32] = 0;
   out_2436312018501040113[33] = 0;
   out_2436312018501040113[34] = 0;
   out_2436312018501040113[35] = 0;
   out_2436312018501040113[36] = 0;
   out_2436312018501040113[37] = 0;
   out_2436312018501040113[38] = 0;
   out_2436312018501040113[39] = 0;
   out_2436312018501040113[40] = 1;
   out_2436312018501040113[41] = 0;
   out_2436312018501040113[42] = 0;
   out_2436312018501040113[43] = 0;
   out_2436312018501040113[44] = 0;
   out_2436312018501040113[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2436312018501040113[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2436312018501040113[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2436312018501040113[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2436312018501040113[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2436312018501040113[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2436312018501040113[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2436312018501040113[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2436312018501040113[53] = -9.8000000000000007*dt;
   out_2436312018501040113[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2436312018501040113[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2436312018501040113[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2436312018501040113[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2436312018501040113[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2436312018501040113[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2436312018501040113[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2436312018501040113[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2436312018501040113[62] = 0;
   out_2436312018501040113[63] = 0;
   out_2436312018501040113[64] = 0;
   out_2436312018501040113[65] = 0;
   out_2436312018501040113[66] = 0;
   out_2436312018501040113[67] = 0;
   out_2436312018501040113[68] = 0;
   out_2436312018501040113[69] = 0;
   out_2436312018501040113[70] = 1;
   out_2436312018501040113[71] = 0;
   out_2436312018501040113[72] = 0;
   out_2436312018501040113[73] = 0;
   out_2436312018501040113[74] = 0;
   out_2436312018501040113[75] = 0;
   out_2436312018501040113[76] = 0;
   out_2436312018501040113[77] = 0;
   out_2436312018501040113[78] = 0;
   out_2436312018501040113[79] = 0;
   out_2436312018501040113[80] = 1;
}
void h_25(double *state, double *unused, double *out_6441266928430861183) {
   out_6441266928430861183[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1604934088768020918) {
   out_1604934088768020918[0] = 0;
   out_1604934088768020918[1] = 0;
   out_1604934088768020918[2] = 0;
   out_1604934088768020918[3] = 0;
   out_1604934088768020918[4] = 0;
   out_1604934088768020918[5] = 0;
   out_1604934088768020918[6] = 1;
   out_1604934088768020918[7] = 0;
   out_1604934088768020918[8] = 0;
}
void h_24(double *state, double *unused, double *out_7412346538782629975) {
   out_7412346538782629975[0] = state[4];
   out_7412346538782629975[1] = state[5];
}
void H_24(double *state, double *unused, double *out_572280334839129055) {
   out_572280334839129055[0] = 0;
   out_572280334839129055[1] = 0;
   out_572280334839129055[2] = 0;
   out_572280334839129055[3] = 0;
   out_572280334839129055[4] = 1;
   out_572280334839129055[5] = 0;
   out_572280334839129055[6] = 0;
   out_572280334839129055[7] = 0;
   out_572280334839129055[8] = 0;
   out_572280334839129055[9] = 0;
   out_572280334839129055[10] = 0;
   out_572280334839129055[11] = 0;
   out_572280334839129055[12] = 0;
   out_572280334839129055[13] = 0;
   out_572280334839129055[14] = 1;
   out_572280334839129055[15] = 0;
   out_572280334839129055[16] = 0;
   out_572280334839129055[17] = 0;
}
void h_30(double *state, double *unused, double *out_5234641918928339497) {
   out_5234641918928339497[0] = state[4];
}
void H_30(double *state, double *unused, double *out_913398869739227709) {
   out_913398869739227709[0] = 0;
   out_913398869739227709[1] = 0;
   out_913398869739227709[2] = 0;
   out_913398869739227709[3] = 0;
   out_913398869739227709[4] = 1;
   out_913398869739227709[5] = 0;
   out_913398869739227709[6] = 0;
   out_913398869739227709[7] = 0;
   out_913398869739227709[8] = 0;
}
void h_26(double *state, double *unused, double *out_3561667545337657643) {
   out_3561667545337657643[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5346437407642077142) {
   out_5346437407642077142[0] = 0;
   out_5346437407642077142[1] = 0;
   out_5346437407642077142[2] = 0;
   out_5346437407642077142[3] = 0;
   out_5346437407642077142[4] = 0;
   out_5346437407642077142[5] = 0;
   out_5346437407642077142[6] = 0;
   out_5346437407642077142[7] = 1;
   out_5346437407642077142[8] = 0;
}
void h_27(double *state, double *unused, double *out_1439593660770015538) {
   out_1439593660770015538[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3136992940923170926) {
   out_3136992940923170926[0] = 0;
   out_3136992940923170926[1] = 0;
   out_3136992940923170926[2] = 0;
   out_3136992940923170926[3] = 1;
   out_3136992940923170926[4] = 0;
   out_3136992940923170926[5] = 0;
   out_3136992940923170926[6] = 0;
   out_3136992940923170926[7] = 0;
   out_3136992940923170926[8] = 0;
}
void h_29(double *state, double *unused, double *out_8210428887120366474) {
   out_8210428887120366474[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1423630214053619893) {
   out_1423630214053619893[0] = 0;
   out_1423630214053619893[1] = 1;
   out_1423630214053619893[2] = 0;
   out_1423630214053619893[3] = 0;
   out_1423630214053619893[4] = 0;
   out_1423630214053619893[5] = 0;
   out_1423630214053619893[6] = 0;
   out_1423630214053619893[7] = 0;
   out_1423630214053619893[8] = 0;
}
void h_28(double *state, double *unused, double *out_2383103513671677973) {
   out_2383103513671677973[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3658768803015910681) {
   out_3658768803015910681[0] = 1;
   out_3658768803015910681[1] = 0;
   out_3658768803015910681[2] = 0;
   out_3658768803015910681[3] = 0;
   out_3658768803015910681[4] = 0;
   out_3658768803015910681[5] = 0;
   out_3658768803015910681[6] = 0;
   out_3658768803015910681[7] = 0;
   out_3658768803015910681[8] = 0;
}
void h_31(double *state, double *unused, double *out_9057751154923205472) {
   out_9057751154923205472[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1574288126891060490) {
   out_1574288126891060490[0] = 0;
   out_1574288126891060490[1] = 0;
   out_1574288126891060490[2] = 0;
   out_1574288126891060490[3] = 0;
   out_1574288126891060490[4] = 0;
   out_1574288126891060490[5] = 0;
   out_1574288126891060490[6] = 0;
   out_1574288126891060490[7] = 0;
   out_1574288126891060490[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4583207975382893756) {
  err_fun(nom_x, delta_x, out_4583207975382893756);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9143150462401985555) {
  inv_err_fun(nom_x, true_x, out_9143150462401985555);
}
void car_H_mod_fun(double *state, double *out_3358041296692552281) {
  H_mod_fun(state, out_3358041296692552281);
}
void car_f_fun(double *state, double dt, double *out_8358470198575263086) {
  f_fun(state,  dt, out_8358470198575263086);
}
void car_F_fun(double *state, double dt, double *out_2436312018501040113) {
  F_fun(state,  dt, out_2436312018501040113);
}
void car_h_25(double *state, double *unused, double *out_6441266928430861183) {
  h_25(state, unused, out_6441266928430861183);
}
void car_H_25(double *state, double *unused, double *out_1604934088768020918) {
  H_25(state, unused, out_1604934088768020918);
}
void car_h_24(double *state, double *unused, double *out_7412346538782629975) {
  h_24(state, unused, out_7412346538782629975);
}
void car_H_24(double *state, double *unused, double *out_572280334839129055) {
  H_24(state, unused, out_572280334839129055);
}
void car_h_30(double *state, double *unused, double *out_5234641918928339497) {
  h_30(state, unused, out_5234641918928339497);
}
void car_H_30(double *state, double *unused, double *out_913398869739227709) {
  H_30(state, unused, out_913398869739227709);
}
void car_h_26(double *state, double *unused, double *out_3561667545337657643) {
  h_26(state, unused, out_3561667545337657643);
}
void car_H_26(double *state, double *unused, double *out_5346437407642077142) {
  H_26(state, unused, out_5346437407642077142);
}
void car_h_27(double *state, double *unused, double *out_1439593660770015538) {
  h_27(state, unused, out_1439593660770015538);
}
void car_H_27(double *state, double *unused, double *out_3136992940923170926) {
  H_27(state, unused, out_3136992940923170926);
}
void car_h_29(double *state, double *unused, double *out_8210428887120366474) {
  h_29(state, unused, out_8210428887120366474);
}
void car_H_29(double *state, double *unused, double *out_1423630214053619893) {
  H_29(state, unused, out_1423630214053619893);
}
void car_h_28(double *state, double *unused, double *out_2383103513671677973) {
  h_28(state, unused, out_2383103513671677973);
}
void car_H_28(double *state, double *unused, double *out_3658768803015910681) {
  H_28(state, unused, out_3658768803015910681);
}
void car_h_31(double *state, double *unused, double *out_9057751154923205472) {
  h_31(state, unused, out_9057751154923205472);
}
void car_H_31(double *state, double *unused, double *out_1574288126891060490) {
  H_31(state, unused, out_1574288126891060490);
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
