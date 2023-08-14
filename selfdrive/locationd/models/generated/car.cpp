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
void err_fun(double *nom_x, double *delta_x, double *out_1282327502940326821) {
   out_1282327502940326821[0] = delta_x[0] + nom_x[0];
   out_1282327502940326821[1] = delta_x[1] + nom_x[1];
   out_1282327502940326821[2] = delta_x[2] + nom_x[2];
   out_1282327502940326821[3] = delta_x[3] + nom_x[3];
   out_1282327502940326821[4] = delta_x[4] + nom_x[4];
   out_1282327502940326821[5] = delta_x[5] + nom_x[5];
   out_1282327502940326821[6] = delta_x[6] + nom_x[6];
   out_1282327502940326821[7] = delta_x[7] + nom_x[7];
   out_1282327502940326821[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4590721196226970281) {
   out_4590721196226970281[0] = -nom_x[0] + true_x[0];
   out_4590721196226970281[1] = -nom_x[1] + true_x[1];
   out_4590721196226970281[2] = -nom_x[2] + true_x[2];
   out_4590721196226970281[3] = -nom_x[3] + true_x[3];
   out_4590721196226970281[4] = -nom_x[4] + true_x[4];
   out_4590721196226970281[5] = -nom_x[5] + true_x[5];
   out_4590721196226970281[6] = -nom_x[6] + true_x[6];
   out_4590721196226970281[7] = -nom_x[7] + true_x[7];
   out_4590721196226970281[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2163953626510216661) {
   out_2163953626510216661[0] = 1.0;
   out_2163953626510216661[1] = 0;
   out_2163953626510216661[2] = 0;
   out_2163953626510216661[3] = 0;
   out_2163953626510216661[4] = 0;
   out_2163953626510216661[5] = 0;
   out_2163953626510216661[6] = 0;
   out_2163953626510216661[7] = 0;
   out_2163953626510216661[8] = 0;
   out_2163953626510216661[9] = 0;
   out_2163953626510216661[10] = 1.0;
   out_2163953626510216661[11] = 0;
   out_2163953626510216661[12] = 0;
   out_2163953626510216661[13] = 0;
   out_2163953626510216661[14] = 0;
   out_2163953626510216661[15] = 0;
   out_2163953626510216661[16] = 0;
   out_2163953626510216661[17] = 0;
   out_2163953626510216661[18] = 0;
   out_2163953626510216661[19] = 0;
   out_2163953626510216661[20] = 1.0;
   out_2163953626510216661[21] = 0;
   out_2163953626510216661[22] = 0;
   out_2163953626510216661[23] = 0;
   out_2163953626510216661[24] = 0;
   out_2163953626510216661[25] = 0;
   out_2163953626510216661[26] = 0;
   out_2163953626510216661[27] = 0;
   out_2163953626510216661[28] = 0;
   out_2163953626510216661[29] = 0;
   out_2163953626510216661[30] = 1.0;
   out_2163953626510216661[31] = 0;
   out_2163953626510216661[32] = 0;
   out_2163953626510216661[33] = 0;
   out_2163953626510216661[34] = 0;
   out_2163953626510216661[35] = 0;
   out_2163953626510216661[36] = 0;
   out_2163953626510216661[37] = 0;
   out_2163953626510216661[38] = 0;
   out_2163953626510216661[39] = 0;
   out_2163953626510216661[40] = 1.0;
   out_2163953626510216661[41] = 0;
   out_2163953626510216661[42] = 0;
   out_2163953626510216661[43] = 0;
   out_2163953626510216661[44] = 0;
   out_2163953626510216661[45] = 0;
   out_2163953626510216661[46] = 0;
   out_2163953626510216661[47] = 0;
   out_2163953626510216661[48] = 0;
   out_2163953626510216661[49] = 0;
   out_2163953626510216661[50] = 1.0;
   out_2163953626510216661[51] = 0;
   out_2163953626510216661[52] = 0;
   out_2163953626510216661[53] = 0;
   out_2163953626510216661[54] = 0;
   out_2163953626510216661[55] = 0;
   out_2163953626510216661[56] = 0;
   out_2163953626510216661[57] = 0;
   out_2163953626510216661[58] = 0;
   out_2163953626510216661[59] = 0;
   out_2163953626510216661[60] = 1.0;
   out_2163953626510216661[61] = 0;
   out_2163953626510216661[62] = 0;
   out_2163953626510216661[63] = 0;
   out_2163953626510216661[64] = 0;
   out_2163953626510216661[65] = 0;
   out_2163953626510216661[66] = 0;
   out_2163953626510216661[67] = 0;
   out_2163953626510216661[68] = 0;
   out_2163953626510216661[69] = 0;
   out_2163953626510216661[70] = 1.0;
   out_2163953626510216661[71] = 0;
   out_2163953626510216661[72] = 0;
   out_2163953626510216661[73] = 0;
   out_2163953626510216661[74] = 0;
   out_2163953626510216661[75] = 0;
   out_2163953626510216661[76] = 0;
   out_2163953626510216661[77] = 0;
   out_2163953626510216661[78] = 0;
   out_2163953626510216661[79] = 0;
   out_2163953626510216661[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_405606070335708994) {
   out_405606070335708994[0] = state[0];
   out_405606070335708994[1] = state[1];
   out_405606070335708994[2] = state[2];
   out_405606070335708994[3] = state[3];
   out_405606070335708994[4] = state[4];
   out_405606070335708994[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_405606070335708994[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_405606070335708994[7] = state[7];
   out_405606070335708994[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7303340041697938188) {
   out_7303340041697938188[0] = 1;
   out_7303340041697938188[1] = 0;
   out_7303340041697938188[2] = 0;
   out_7303340041697938188[3] = 0;
   out_7303340041697938188[4] = 0;
   out_7303340041697938188[5] = 0;
   out_7303340041697938188[6] = 0;
   out_7303340041697938188[7] = 0;
   out_7303340041697938188[8] = 0;
   out_7303340041697938188[9] = 0;
   out_7303340041697938188[10] = 1;
   out_7303340041697938188[11] = 0;
   out_7303340041697938188[12] = 0;
   out_7303340041697938188[13] = 0;
   out_7303340041697938188[14] = 0;
   out_7303340041697938188[15] = 0;
   out_7303340041697938188[16] = 0;
   out_7303340041697938188[17] = 0;
   out_7303340041697938188[18] = 0;
   out_7303340041697938188[19] = 0;
   out_7303340041697938188[20] = 1;
   out_7303340041697938188[21] = 0;
   out_7303340041697938188[22] = 0;
   out_7303340041697938188[23] = 0;
   out_7303340041697938188[24] = 0;
   out_7303340041697938188[25] = 0;
   out_7303340041697938188[26] = 0;
   out_7303340041697938188[27] = 0;
   out_7303340041697938188[28] = 0;
   out_7303340041697938188[29] = 0;
   out_7303340041697938188[30] = 1;
   out_7303340041697938188[31] = 0;
   out_7303340041697938188[32] = 0;
   out_7303340041697938188[33] = 0;
   out_7303340041697938188[34] = 0;
   out_7303340041697938188[35] = 0;
   out_7303340041697938188[36] = 0;
   out_7303340041697938188[37] = 0;
   out_7303340041697938188[38] = 0;
   out_7303340041697938188[39] = 0;
   out_7303340041697938188[40] = 1;
   out_7303340041697938188[41] = 0;
   out_7303340041697938188[42] = 0;
   out_7303340041697938188[43] = 0;
   out_7303340041697938188[44] = 0;
   out_7303340041697938188[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7303340041697938188[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7303340041697938188[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7303340041697938188[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7303340041697938188[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7303340041697938188[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7303340041697938188[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7303340041697938188[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7303340041697938188[53] = -9.8000000000000007*dt;
   out_7303340041697938188[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7303340041697938188[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7303340041697938188[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7303340041697938188[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7303340041697938188[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7303340041697938188[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7303340041697938188[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7303340041697938188[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7303340041697938188[62] = 0;
   out_7303340041697938188[63] = 0;
   out_7303340041697938188[64] = 0;
   out_7303340041697938188[65] = 0;
   out_7303340041697938188[66] = 0;
   out_7303340041697938188[67] = 0;
   out_7303340041697938188[68] = 0;
   out_7303340041697938188[69] = 0;
   out_7303340041697938188[70] = 1;
   out_7303340041697938188[71] = 0;
   out_7303340041697938188[72] = 0;
   out_7303340041697938188[73] = 0;
   out_7303340041697938188[74] = 0;
   out_7303340041697938188[75] = 0;
   out_7303340041697938188[76] = 0;
   out_7303340041697938188[77] = 0;
   out_7303340041697938188[78] = 0;
   out_7303340041697938188[79] = 0;
   out_7303340041697938188[80] = 1;
}
void h_25(double *state, double *unused, double *out_5588110016210508170) {
   out_5588110016210508170[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6037113083971364302) {
   out_6037113083971364302[0] = 0;
   out_6037113083971364302[1] = 0;
   out_6037113083971364302[2] = 0;
   out_6037113083971364302[3] = 0;
   out_6037113083971364302[4] = 0;
   out_6037113083971364302[5] = 0;
   out_6037113083971364302[6] = 1;
   out_6037113083971364302[7] = 0;
   out_6037113083971364302[8] = 0;
}
void h_24(double *state, double *unused, double *out_4380624216713203670) {
   out_4380624216713203670[0] = state[4];
   out_4380624216713203670[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8209762682976863868) {
   out_8209762682976863868[0] = 0;
   out_8209762682976863868[1] = 0;
   out_8209762682976863868[2] = 0;
   out_8209762682976863868[3] = 0;
   out_8209762682976863868[4] = 1;
   out_8209762682976863868[5] = 0;
   out_8209762682976863868[6] = 0;
   out_8209762682976863868[7] = 0;
   out_8209762682976863868[8] = 0;
   out_8209762682976863868[9] = 0;
   out_8209762682976863868[10] = 0;
   out_8209762682976863868[11] = 0;
   out_8209762682976863868[12] = 0;
   out_8209762682976863868[13] = 0;
   out_8209762682976863868[14] = 1;
   out_8209762682976863868[15] = 0;
   out_8209762682976863868[16] = 0;
   out_8209762682976863868[17] = 0;
}
void h_30(double *state, double *unused, double *out_4965694562614520087) {
   out_4965694562614520087[0] = state[4];
}
void H_30(double *state, double *unused, double *out_879577257520252453) {
   out_879577257520252453[0] = 0;
   out_879577257520252453[1] = 0;
   out_879577257520252453[2] = 0;
   out_879577257520252453[3] = 0;
   out_879577257520252453[4] = 1;
   out_879577257520252453[5] = 0;
   out_879577257520252453[6] = 0;
   out_879577257520252453[7] = 0;
   out_879577257520252453[8] = 0;
}
void h_26(double *state, double *unused, double *out_4499080339088190764) {
   out_4499080339088190764[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8668127670864131090) {
   out_8668127670864131090[0] = 0;
   out_8668127670864131090[1] = 0;
   out_8668127670864131090[2] = 0;
   out_8668127670864131090[3] = 0;
   out_8668127670864131090[4] = 0;
   out_8668127670864131090[5] = 0;
   out_8668127670864131090[6] = 0;
   out_8668127670864131090[7] = 1;
   out_8668127670864131090[8] = 0;
}
void h_27(double *state, double *unused, double *out_586436748549662525) {
   out_586436748549662525[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1295186054280172458) {
   out_1295186054280172458[0] = 0;
   out_1295186054280172458[1] = 0;
   out_1295186054280172458[2] = 0;
   out_1295186054280172458[3] = 1;
   out_1295186054280172458[4] = 0;
   out_1295186054280172458[5] = 0;
   out_1295186054280172458[6] = 0;
   out_1295186054280172458[7] = 0;
   out_1295186054280172458[8] = 0;
}
void h_29(double *state, double *unused, double *out_5569010447290997604) {
   out_5569010447290997604[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3008548781149723491) {
   out_3008548781149723491[0] = 0;
   out_3008548781149723491[1] = 1;
   out_3008548781149723491[2] = 0;
   out_3008548781149723491[3] = 0;
   out_3008548781149723491[4] = 0;
   out_3008548781149723491[5] = 0;
   out_3008548781149723491[6] = 0;
   out_3008548781149723491[7] = 0;
   out_3008548781149723491[8] = 0;
}
void h_28(double *state, double *unused, double *out_2689411064197794064) {
   out_2689411064197794064[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8090947798219254065) {
   out_8090947798219254065[0] = 1;
   out_8090947798219254065[1] = 0;
   out_8090947798219254065[2] = 0;
   out_8090947798219254065[3] = 0;
   out_8090947798219254065[4] = 0;
   out_8090947798219254065[5] = 0;
   out_8090947798219254065[6] = 0;
   out_8090947798219254065[7] = 0;
   out_8090947798219254065[8] = 0;
}
void h_31(double *state, double *unused, double *out_5863304078495014059) {
   out_5863304078495014059[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6006467122094403874) {
   out_6006467122094403874[0] = 0;
   out_6006467122094403874[1] = 0;
   out_6006467122094403874[2] = 0;
   out_6006467122094403874[3] = 0;
   out_6006467122094403874[4] = 0;
   out_6006467122094403874[5] = 0;
   out_6006467122094403874[6] = 0;
   out_6006467122094403874[7] = 0;
   out_6006467122094403874[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1282327502940326821) {
  err_fun(nom_x, delta_x, out_1282327502940326821);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4590721196226970281) {
  inv_err_fun(nom_x, true_x, out_4590721196226970281);
}
void car_H_mod_fun(double *state, double *out_2163953626510216661) {
  H_mod_fun(state, out_2163953626510216661);
}
void car_f_fun(double *state, double dt, double *out_405606070335708994) {
  f_fun(state,  dt, out_405606070335708994);
}
void car_F_fun(double *state, double dt, double *out_7303340041697938188) {
  F_fun(state,  dt, out_7303340041697938188);
}
void car_h_25(double *state, double *unused, double *out_5588110016210508170) {
  h_25(state, unused, out_5588110016210508170);
}
void car_H_25(double *state, double *unused, double *out_6037113083971364302) {
  H_25(state, unused, out_6037113083971364302);
}
void car_h_24(double *state, double *unused, double *out_4380624216713203670) {
  h_24(state, unused, out_4380624216713203670);
}
void car_H_24(double *state, double *unused, double *out_8209762682976863868) {
  H_24(state, unused, out_8209762682976863868);
}
void car_h_30(double *state, double *unused, double *out_4965694562614520087) {
  h_30(state, unused, out_4965694562614520087);
}
void car_H_30(double *state, double *unused, double *out_879577257520252453) {
  H_30(state, unused, out_879577257520252453);
}
void car_h_26(double *state, double *unused, double *out_4499080339088190764) {
  h_26(state, unused, out_4499080339088190764);
}
void car_H_26(double *state, double *unused, double *out_8668127670864131090) {
  H_26(state, unused, out_8668127670864131090);
}
void car_h_27(double *state, double *unused, double *out_586436748549662525) {
  h_27(state, unused, out_586436748549662525);
}
void car_H_27(double *state, double *unused, double *out_1295186054280172458) {
  H_27(state, unused, out_1295186054280172458);
}
void car_h_29(double *state, double *unused, double *out_5569010447290997604) {
  h_29(state, unused, out_5569010447290997604);
}
void car_H_29(double *state, double *unused, double *out_3008548781149723491) {
  H_29(state, unused, out_3008548781149723491);
}
void car_h_28(double *state, double *unused, double *out_2689411064197794064) {
  h_28(state, unused, out_2689411064197794064);
}
void car_H_28(double *state, double *unused, double *out_8090947798219254065) {
  H_28(state, unused, out_8090947798219254065);
}
void car_h_31(double *state, double *unused, double *out_5863304078495014059) {
  h_31(state, unused, out_5863304078495014059);
}
void car_H_31(double *state, double *unused, double *out_6006467122094403874) {
  H_31(state, unused, out_6006467122094403874);
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
