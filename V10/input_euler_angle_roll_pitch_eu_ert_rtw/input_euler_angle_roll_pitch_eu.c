/*
 * File: input_euler_angle_roll_pitch_eu.c
 *
 * Code generated for Simulink model 'input_euler_angle_roll_pitch_eu'.
 *
 * Model version                  : 1.1053
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Aug 20 15:15:52 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "input_euler_angle_roll_pitch_eu.h"
#define NumBitsPerChar                 8U

const BUS_TASK_PATH_OutParam
  input_euler_angle_roll_pitch_eu_rtZBUS_TASK_PATH_OutParam = {
  0.0,                                 /* currentPointNum */
  0.0,                                 /* prePointNum */
  0.0,                                 /* validPathNum */
  0.0,                                 /* headingCmd */
  0.0,                                 /* distToGo */
  0.0,                                 /* dz */
  0.0,                                 /* groundspeedCmd */
  0.0,                                 /* rollCmd */
  0.0,                                 /* turnRadiusCmd */
  0.0,                                 /* heightCmd */

  {
    0.0, 0.0 }
  ,                                    /* turnCenterLL */
  0.0,                                 /* dR_turn */
  NoneUAVMode,                         /* uavMode */
  NoneFlightTaskMode,                  /* flightTaskMode */
  NoneFlightControlMode,               /* flightControlMode */
  NoneControlMode,                     /* AutoManualMode */
  ComNormal,                           /* comStatus */
  0.0,                                 /* maxClimbSpeed */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* prePathPoint_LLA */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* curPathPoint_LLA */
  OnGround,                            /* whereIsUAV */
  NotAutoMode,                         /* typeAutoMode */
  0.0,                                 /* airspeedCmd */
  0.0,                                 /* switchHeight */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* LLATaskInterrupt */
  false,                               /* isTaskComplete */
  0.0,                                 /* numTakeOff */
  false,                               /* isHeadingRotate_OnGround */
  false,                               /* isAllowedToPause */
  false,                               /* isNeedToRecordBreak */
  0.0                                  /* lastTargetPathPoint */
} ;                                    /* BUS_TASK_PATH_OutParam ground */

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_remd_snf(real_T u0, real_T u1);

/* Forward declaration for local functions */
static void setup_motors_4a1(DW *rtDW);
static void from_euler(const real_T euler_angle[3], real_T q[4]);
static void rotation_matrix(const real_T q[4], real_T m[9]);
static void updata_cl(DW *rtDW);
static void from_rotation_matrix(const real_T m[9], real_T q[4]);
static void set_throttle_out(real_T throttle_ini, real_T apply_angle_boost,
  real_T filter_cutoff, DW *rtDW);
static real_T wrap_PI(real_T radian);
static real_T sqrt_controller(real_T error, real_T p, real_T second_ord_lim,
  real_T b_dt);
static real_T norm(const real_T x[2]);
static void ang_vel_limit(const real_T euler_radin[3], real_T b_ang_vel_roll_max,
  real_T b_ang_vel_pitch_max, real_T b_ang_vel_yaw_max, real_T euler_rado[3]);
static real_T norm_p(const real_T x[3]);
static void from_axis_angle(const real_T axisin[3], real_T theta, real_T q[4]);
static void quatmultiply(const real_T q[4], const real_T r[4], real_T qout[4]);
static void normalizeq(real_T q[4]);
static void attitude_controller_run_quat(DW *rtDW);
static void input_euler_angle_roll_pitch__o(real_T euler_roll_angle_cd, real_T
  euler_pitch_angle_cd, real_T euler_yaw_rate_cds, DW *rtDW);
static void rate_controller_run(DW *rtDW);
static void update_throttle_filter(DW *rtDW);
static void output_armed_stabilizing(DW *rtDW);
static void AP_MotorsMulticopter_output_4a1(DW *rtDW);
static void set_alt_target_from_climb_rate_(real_T b_climb_rate_cms, real_T b_dt,
  real_T force_descend, DW *rtDW);
static void update_z_controller(DW *rtDW);
static real_T get_weathervane_yaw_rate_cds(DW *rtDW);
static void run_xy_controller(real_T b_dt, DW *rtDW);
static void update_vel_controller_xy(DW *rtDW);
static void calc_nav_roll(DW *rtDW);
static void stabilize(DW *rtDW);
static void output_to_motors_plane_4a1(DW *rtDW);
static void update_50hz(DW *rtDW);
static void update_speed(real_T load_factor, DW *rtDW);
static void update_pitch_throttle(real_T b_hgt_dem_cm, real_T b_EAS_dem_cm,
  real_T load_factor, DW *rtDW);
static real_T get_bearing_to(const real_T loc2[2], const real_T b_loc[2], DW
  *rtDW);
static real_T prevent_indecision(real_T Nu, DW *rtDW);
static void update_waypoint(const real_T b_prev_WP[2], const real_T b_next_WP[2],
  real_T b_dist_min, DW *rtDW);
static void update_loiter(const real_T b_center_WP[2], real_T b_radius, real_T
  b_loiter_direction, DW *rtDW);
static void AP_MotorsMulticopter_output(DW *rtDW);
static void copter_run(DW *rtDW);
static void get_vector_xy_from_origin_NE(const real_T b_loc[2], const real_T
  b_loc_origin[2], real_T vec_ne[2], DW *rtDW);
static void set_alt_target_from_climb_rat_a(real_T alt_cm, real_T
  b_climb_rate_cms, real_T b_dt, real_T force_descend, DW *rtDW);
static void plane_run_4a1(DW *rtDW);
static void calc_nav_pitch(DW *rtDW);
static void get_distance_NE(const real_T loc2[2], const real_T b_loc[2], real_T
  distance_NE[2], DW *rtDW);
static void auto_mode_4a1(DW *rtDW);
static void copter_run_4a1(DW *rtDW);
static void set_alt_target_from_climb_rat_m(real_T b_climb_rate_cms, real_T b_dt,
  real_T force_descend, real_T sign_in, DW *rtDW);
static void copter_run_posfree_4a1(DW *rtDW);
static void auto_mode_sl_4a1(DW *rtDW);
static void run_V10(DW *rtDW);
static void setup_motors(DW *rtDW);
static void output_to_motors_plane(DW *rtDW);
static void plane_run(DW *rtDW);
static void auto_mode(DW *rtDW);
static void copter_run_posfree(DW *rtDW);
static void auto_mode_sl(DW *rtDW);
static void run_V1000(DW *rtDW);
static void run_V10s(DW *rtDW);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void setup_motors_4a1(DW *rtDW)
{
  rtDW->roll_factor[0] = -0.70710678118654746;
  rtDW->pitch_factor[0] = 0.70710678118654757;
  rtDW->yaw_factor[0] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CW;
  rtDW->roll_factor[1] = 0.70710678118654757;
  rtDW->pitch_factor[1] = -0.70710678118654746;
  rtDW->yaw_factor[1] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CW;
  rtDW->roll_factor[2] = 0.70710678118654757;
  rtDW->pitch_factor[2] = 0.70710678118654757;
  rtDW->yaw_factor[2] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CCW;
  rtDW->roll_factor[3] = -0.70710678118654768;
  rtDW->pitch_factor[3] = -0.70710678118654746;
  rtDW->yaw_factor[3] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CCW;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void from_euler(const real_T euler_angle[3], real_T q[4])
{
  real_T cr2;
  real_T cp2;
  real_T cy2;
  real_T sr2;
  real_T sp2;
  real_T sy2;
  real_T q_tmp;
  real_T q_tmp_0;
  cr2 = cos(euler_angle[0] * 0.5);
  cp2 = cos(euler_angle[1] * 0.5);
  cy2 = cos(euler_angle[2] * 0.5);
  sr2 = sin(euler_angle[0] * 0.5);
  sp2 = sin(euler_angle[1] * 0.5);
  sy2 = sin(euler_angle[2] * 0.5);
  q_tmp = cr2 * cp2;
  q_tmp_0 = sr2 * sp2;
  q[0] = q_tmp * cy2 + q_tmp_0 * sy2;
  cr2 *= sp2;
  cp2 *= sr2;
  q[1] = cp2 * cy2 - cr2 * sy2;
  q[2] = cr2 * cy2 + cp2 * sy2;
  q[3] = q_tmp * sy2 - q_tmp_0 * cy2;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void rotation_matrix(const real_T q[4], real_T m[9])
{
  real_T q3q3;
  real_T q3q4;
  real_T q2q2;
  real_T q2q3;
  real_T q2q4;
  real_T q1q2;
  real_T q1q3;
  real_T q1q4;
  real_T q4q4;
  q3q3 = q[2] * q[2];
  q3q4 = q[2] * q[3];
  q2q2 = q[1] * q[1];
  q2q3 = q[1] * q[2];
  q2q4 = q[1] * q[3];
  q1q2 = q[0] * q[1];
  q1q3 = q[0] * q[2];
  q1q4 = q[0] * q[3];
  q4q4 = q[3] * q[3];
  m[0] = 1.0 - (q3q3 + q4q4) * 2.0;
  m[3] = (q2q3 - q1q4) * 2.0;
  m[6] = (q2q4 + q1q3) * 2.0;
  m[1] = (q2q3 + q1q4) * 2.0;
  m[4] = 1.0 - (q2q2 + q4q4) * 2.0;
  m[7] = (q3q4 - q1q2) * 2.0;
  m[2] = (q2q4 - q1q3) * 2.0;
  m[5] = (q3q4 + q1q2) * 2.0;
  m[8] = 1.0 - (q2q2 + q3q3) * 2.0;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void updata_cl(DW *rtDW)
{
  real_T tmp[3];
  int32_T i;
  real_T tmp_0[4];
  tmp[0] = rtDW->roll;
  tmp[1] = rtDW->pitch;
  tmp[2] = rtDW->yaw;
  from_euler(tmp, tmp_0);
  rotation_matrix(tmp_0, rtDW->rot_body_to_ned);
  for (i = 0; i < 3; i++) {
    tmp[i] = rtDW->rot_body_to_ned[i + 6] * rtDW->accel_z +
      (rtDW->rot_body_to_ned[i + 3] * rtDW->accel_y + rtDW->rot_body_to_ned[i] *
       rtDW->accel_x);
  }

  rtDW->z_accel_meas = -(tmp[2] + rtDW->GRAVITY_MSS) * 100.0;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void from_rotation_matrix(const real_T m[9], real_T q[4])
{
  real_T tr;
  tr = (m[0] + m[4]) + m[8];
  if (tr > 0.0) {
    tr = sqrt(tr + 1.0) * 2.0;
    q[0] = 0.25 * tr;
    q[1] = (m[5] - m[7]) / tr;
    q[2] = (m[6] - m[2]) / tr;
    q[3] = (m[1] - m[3]) / tr;
  } else if ((m[0] > m[4]) && (m[0] > m[8])) {
    tr = sqrt(((m[0] + 1.0) - m[4]) - m[8]) * 2.0;
    q[0] = (m[5] - m[7]) / tr;
    q[1] = 0.25 * tr;
    q[2] = (m[3] + m[1]) / tr;
    q[3] = (m[6] + m[2]) / tr;
  } else if (m[4] > m[8]) {
    tr = sqrt(((m[4] + 1.0) - m[0]) - m[8]) * 2.0;
    q[0] = (m[6] - m[2]) / tr;
    q[1] = (m[3] + m[1]) / tr;
    q[2] = 0.25 * tr;
    q[3] = (m[7] + m[5]) / tr;
  } else {
    tr = sqrt(((m[8] + 1.0) - m[0]) - m[4]) * 2.0;
    q[0] = (m[1] - m[3]) / tr;
    q[1] = (m[6] + m[2]) / tr;
    q[2] = (m[7] + m[5]) / tr;
    q[3] = 0.25 * tr;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void set_throttle_out(real_T throttle_ini, real_T apply_angle_boost,
  real_T filter_cutoff, DW *rtDW)
{
  real_T cos_tilt;
  real_T amto;
  cos_tilt = throttle_ini / (rtDW->AC_ATTITUDE_CONTROL_ANGLE_LIMIT *
    rtDW->throttle_thrust_max);
  amto = cos_tilt;
  if (cos_tilt < 0.0) {
    amto = 0.0;
  }

  if (cos_tilt > 1.0) {
    amto = 1.0;
  }

  rtDW->althold_lean_angle_max += rtDW->dt / (rtDW->dt + rtDW->angle_limit_tc) *
    (acos(amto) - rtDW->althold_lean_angle_max);
  if (rtDW->throttle_thrust_max == 0.0) {
    rtDW->althold_lean_angle_max = 0.0;
  }

  rtDW->throttle_cutoff_frequency = filter_cutoff;
  if (apply_angle_boost != 0.0) {
    if (!(rtDW->angle_boost_enabled != 0.0)) {
      rtDW->angle_boost = 0.0;
    } else {
      cos_tilt = cos(rtDW->pitch) * cos(rtDW->roll);
      if (cos_tilt < 0.83) {
        cos_tilt = 0.83;
      }

      cos_tilt = throttle_ini / cos_tilt;
      amto = cos_tilt - throttle_ini;
      rtDW->angle_boost = amto;
      if (amto < -1.0) {
        rtDW->angle_boost = -1.0;
      }

      if (amto > 1.0) {
        rtDW->angle_boost = 1.0;
      }

      throttle_ini = cos_tilt;
    }
  } else {
    rtDW->angle_boost = 0.0;
  }

  rtDW->throttle_in = throttle_ini;
  cos_tilt = fmax(throttle_ini, rtDW->throttle_in);
  amto = cos_tilt;
  if (cos_tilt < 0.0) {
    amto = 0.0;
  }

  if (cos_tilt > 1.0) {
    amto = 1.0;
  }

  cos_tilt = fmax(amto, fmax(0.0, 1.0 - rtDW->throttle_rpy_mix) * amto +
                  rtDW->throttle_hover * rtDW->throttle_rpy_mix);
  rtDW->throttle_avg_max = cos_tilt;
  if (cos_tilt < 0.0) {
    rtDW->throttle_avg_max = 0.0;
  }

  if (cos_tilt > 1.0) {
    rtDW->throttle_avg_max = 1.0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T wrap_PI(real_T radian)
{
  real_T res;
  boolean_T rEQ0;
  real_T q;
  if (rtIsNaN(radian)) {
    res = (rtNaN);
  } else if (rtIsInf(radian)) {
    res = (rtNaN);
  } else if (radian == 0.0) {
    res = 0.0;
  } else {
    res = fmod(radian, 6.2831853071795862);
    rEQ0 = (res == 0.0);
    if (!rEQ0) {
      q = fabs(radian / 6.2831853071795862);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      res = 0.0;
    } else {
      if (radian < 0.0) {
        res += 6.2831853071795862;
      }
    }
  }

  if (res > 3.1415926535897931) {
    res -= 6.2831853071795862;
  }

  return res;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T sqrt_controller(real_T error, real_T p, real_T second_ord_lim,
  real_T b_dt)
{
  real_T correction_rate;
  real_T linear_dist;
  real_T low;
  real_T low_tmp;
  if (second_ord_lim <= 0.0) {
    correction_rate = error * p;
  } else if (p == 0.0) {
    if (error > 0.0) {
      correction_rate = sqrt(2.0 * second_ord_lim * error);
    } else if (error < 0.0) {
      correction_rate = -sqrt(2.0 * second_ord_lim * -error);
    } else {
      correction_rate = 0.0;
    }
  } else {
    linear_dist = second_ord_lim / p / p;
    if (error > linear_dist) {
      correction_rate = sqrt((error - linear_dist / 2.0) * (2.0 * second_ord_lim));
    } else if (error < -linear_dist) {
      correction_rate = -sqrt((-error - linear_dist / 2.0) * (2.0 *
        second_ord_lim));
    } else {
      correction_rate = error * p;
    }
  }

  linear_dist = correction_rate;
  low_tmp = fabs(error);
  low = -low_tmp / b_dt;
  low_tmp /= b_dt;
  if (correction_rate < low) {
    correction_rate = low;
  }

  if (linear_dist > low_tmp) {
    correction_rate = low_tmp;
  }

  return correction_rate;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void ang_vel_limit(const real_T euler_radin[3], real_T b_ang_vel_roll_max,
  real_T b_ang_vel_pitch_max, real_T b_ang_vel_yaw_max, real_T euler_rado[3])
{
  real_T thrust_vector_ang_vel_x;
  real_T thrust_vector_ang_vel_y;
  real_T thrust_vector_length;
  real_T thrust_vector_ang_vel_x_0[2];
  euler_rado[0] = euler_radin[0];
  euler_rado[1] = euler_radin[1];
  euler_rado[2] = euler_radin[2];
  if ((b_ang_vel_roll_max == 0.0) || (b_ang_vel_pitch_max == 0.0)) {
    if (b_ang_vel_roll_max != 0.0) {
      euler_rado[0] = euler_radin[0];
      if (euler_radin[0] < -b_ang_vel_roll_max) {
        euler_rado[0] = -b_ang_vel_roll_max;
      }

      if (euler_radin[0] > b_ang_vel_roll_max) {
        euler_rado[0] = b_ang_vel_roll_max;
      }
    }

    if (b_ang_vel_pitch_max != 0.0) {
      euler_rado[1] = euler_radin[1];
      if (euler_radin[1] < -b_ang_vel_pitch_max) {
        euler_rado[1] = -b_ang_vel_pitch_max;
      }

      if (euler_radin[1] > b_ang_vel_pitch_max) {
        euler_rado[1] = b_ang_vel_pitch_max;
      }
    }
  } else {
    thrust_vector_ang_vel_x = euler_radin[0] / b_ang_vel_roll_max;
    thrust_vector_ang_vel_y = euler_radin[1] / b_ang_vel_pitch_max;
    thrust_vector_ang_vel_x_0[0] = thrust_vector_ang_vel_x;
    thrust_vector_ang_vel_x_0[1] = thrust_vector_ang_vel_y;
    thrust_vector_length = norm(thrust_vector_ang_vel_x_0);
    if (thrust_vector_length > 1.0) {
      euler_rado[0] = thrust_vector_ang_vel_x * b_ang_vel_roll_max /
        thrust_vector_length;
      euler_rado[1] = thrust_vector_ang_vel_y * b_ang_vel_pitch_max /
        thrust_vector_length;
    }

    if (b_ang_vel_yaw_max != 0.0) {
      euler_rado[2] = euler_radin[2];
      if (euler_radin[2] < -b_ang_vel_yaw_max) {
        euler_rado[2] = -b_ang_vel_yaw_max;
      }

      if (euler_radin[2] > b_ang_vel_yaw_max) {
        euler_rado[2] = b_ang_vel_yaw_max;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T norm_p(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void from_axis_angle(const real_T axisin[3], real_T theta, real_T q[4])
{
  real_T st2;
  if (theta == 0.0) {
    q[0] = 1.0;
    q[1] = 0.0;
    q[2] = 0.0;
    q[3] = 0.0;
  } else {
    st2 = sin(theta / 2.0);
    q[0] = cos(theta / 2.0);
    q[1] = axisin[0] * st2;
    q[2] = axisin[1] * st2;
    q[3] = axisin[2] * st2;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void quatmultiply(const real_T q[4], const real_T r[4], real_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void normalizeq(real_T q[4])
{
  real_T quatMag;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(q[0]);
  if (absxk > 3.3121686421112381E-170) {
    quatMag = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    quatMag = t * t;
  }

  absxk = fabs(q[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quatMag = quatMag * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    quatMag += t * t;
  }

  absxk = fabs(q[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quatMag = quatMag * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    quatMag += t * t;
  }

  absxk = fabs(q[3]);
  if (absxk > scale) {
    t = scale / absxk;
    quatMag = quatMag * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    quatMag += t * t;
  }

  quatMag = scale * sqrt(quatMag);
  if (quatMag != 0.0) {
    q[0] /= quatMag;
    q[1] /= quatMag;
    q[2] /= quatMag;
    q[3] /= quatMag;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void attitude_controller_run_quat(DW *rtDW)
{
  real_T attitude_vehicle_quat[4];
  real_T feedforward_scalar;
  real_T att_to_thrust_vec[3];
  real_T thrust_vec_cross[3];
  real_T thrust_vector_length;
  real_T thrust_vec_correction_quat[4];
  real_T yaw_vec_correction_quat[4];
  real_T q[4];
  real_T low;
  real_T b_theta;
  real_T att_from_thrust_vec_tmp[3];
  real_T tmp[9];
  int32_T i;
  real_T high;
  real_T tmp_0[4];
  real_T tmp_1[4];
  from_rotation_matrix(rtDW->rot_body_to_ned, attitude_vehicle_quat);
  rotation_matrix(rtDW->attitude_target_quat, tmp);
  for (i = 0; i < 3; i++) {
    att_to_thrust_vec[i] = tmp[i + 6] + (tmp[i + 3] * 0.0 + tmp[i] * 0.0);
  }

  rotation_matrix(attitude_vehicle_quat, tmp);
  feedforward_scalar = 0.0;
  for (i = 0; i < 3; i++) {
    thrust_vector_length = tmp[i + 6] + (tmp[i + 3] * 0.0 + tmp[i] * 0.0);
    feedforward_scalar += thrust_vector_length * att_to_thrust_vec[i];
    att_from_thrust_vec_tmp[i] = thrust_vector_length;
  }

  thrust_vec_cross[0] = att_from_thrust_vec_tmp[1] * att_to_thrust_vec[2] -
    att_from_thrust_vec_tmp[2] * att_to_thrust_vec[1];
  thrust_vec_cross[1] = att_from_thrust_vec_tmp[2] * att_to_thrust_vec[0] -
    att_from_thrust_vec_tmp[0] * att_to_thrust_vec[2];
  thrust_vec_cross[2] = att_from_thrust_vec_tmp[0] * att_to_thrust_vec[1] -
    att_from_thrust_vec_tmp[1] * att_to_thrust_vec[0];
  thrust_vector_length = feedforward_scalar;
  if (feedforward_scalar < -1.0) {
    thrust_vector_length = -1.0;
  }

  if (feedforward_scalar > 1.0) {
    thrust_vector_length = 1.0;
  }

  feedforward_scalar = acos(thrust_vector_length);
  thrust_vector_length = norm_p(thrust_vec_cross);
  if ((thrust_vector_length == 0.0) || (feedforward_scalar == 0.0)) {
    thrust_vec_cross[0] = 0.0;
    thrust_vec_cross[1] = 0.0;
    thrust_vec_cross[2] = 1.0;
    feedforward_scalar = 0.0;
  } else {
    thrust_vec_cross[0] /= thrust_vector_length;
    thrust_vec_cross[1] /= thrust_vector_length;
    thrust_vec_cross[2] /= thrust_vector_length;
  }

  q[0] = attitude_vehicle_quat[0];
  q[1] = -attitude_vehicle_quat[1];
  q[2] = -attitude_vehicle_quat[2];
  q[3] = -attitude_vehicle_quat[3];
  from_axis_angle(thrust_vec_cross, feedforward_scalar, tmp_0);
  quatmultiply(q, tmp_0, tmp_1);
  quatmultiply(tmp_1, attitude_vehicle_quat, thrust_vec_correction_quat);
  q[0] = thrust_vec_correction_quat[0];
  q[1] = -thrust_vec_correction_quat[1];
  q[2] = -thrust_vec_correction_quat[2];
  q[3] = -thrust_vec_correction_quat[3];
  yaw_vec_correction_quat[0] = attitude_vehicle_quat[0];
  yaw_vec_correction_quat[1] = -attitude_vehicle_quat[1];
  yaw_vec_correction_quat[2] = -attitude_vehicle_quat[2];
  yaw_vec_correction_quat[3] = -attitude_vehicle_quat[3];
  quatmultiply(q, yaw_vec_correction_quat, tmp_0);
  quatmultiply(tmp_0, rtDW->attitude_target_quat, yaw_vec_correction_quat);
  thrust_vector_length = sqrt((thrust_vec_correction_quat[1] *
    thrust_vec_correction_quat[1] + thrust_vec_correction_quat[2] *
    thrust_vec_correction_quat[2]) + thrust_vec_correction_quat[3] *
    thrust_vec_correction_quat[3]);
  att_to_thrust_vec[0] = thrust_vec_correction_quat[1];
  att_to_thrust_vec[1] = thrust_vec_correction_quat[2];
  if (thrust_vector_length != 0.0) {
    att_to_thrust_vec[0] = thrust_vec_correction_quat[1] / thrust_vector_length;
    att_to_thrust_vec[1] = thrust_vec_correction_quat[2] / thrust_vector_length;
    thrust_vector_length = wrap_PI(2.0 * rt_atan2d_snf(thrust_vector_length,
      thrust_vec_correction_quat[0]));
    att_to_thrust_vec[0] *= thrust_vector_length;
    att_to_thrust_vec[1] *= thrust_vector_length;
  }

  rtDW->attitude_error_vector[0] = att_to_thrust_vec[0];
  rtDW->attitude_error_vector[1] = att_to_thrust_vec[1];
  thrust_vector_length = sqrt((yaw_vec_correction_quat[1] *
    yaw_vec_correction_quat[1] + yaw_vec_correction_quat[2] *
    yaw_vec_correction_quat[2]) + yaw_vec_correction_quat[3] *
    yaw_vec_correction_quat[3]);
  att_to_thrust_vec[2] = yaw_vec_correction_quat[3];
  if (thrust_vector_length != 0.0) {
    att_to_thrust_vec[2] = yaw_vec_correction_quat[3] / thrust_vector_length;
    thrust_vector_length = wrap_PI(2.0 * rt_atan2d_snf(thrust_vector_length,
      yaw_vec_correction_quat[0]));
    att_to_thrust_vec[2] *= thrust_vector_length;
  }

  thrust_vector_length = att_to_thrust_vec[2];
  if (rtDW->p_angle_yaw != 0.0) {
    high = rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLER_ / rtDW->p_angle_yaw;
    if (fabs(att_to_thrust_vec[2]) > high) {
      b_theta = wrap_PI(att_to_thrust_vec[2]);
      low = -rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLER_ / rtDW->p_angle_yaw;
      thrust_vector_length = b_theta;
      if (b_theta < low) {
        thrust_vector_length = low;
      }

      if (b_theta > high) {
        thrust_vector_length = high;
      }

      att_to_thrust_vec[0] = 0.0;
      att_to_thrust_vec[1] = 0.0;
      att_to_thrust_vec[2] = thrust_vector_length;
      b_theta = norm_p(att_to_thrust_vec);
      if (b_theta == 0.0) {
        yaw_vec_correction_quat[0] = 1.0;
        yaw_vec_correction_quat[1] = 0.0;
        yaw_vec_correction_quat[2] = 0.0;
        yaw_vec_correction_quat[3] = 0.0;
      } else {
        att_to_thrust_vec[0] = 0.0 / b_theta;
        att_to_thrust_vec[1] = 0.0 / b_theta;
        att_to_thrust_vec[2] = thrust_vector_length / b_theta;
        from_axis_angle(att_to_thrust_vec, b_theta, yaw_vec_correction_quat);
      }

      quatmultiply(attitude_vehicle_quat, thrust_vec_correction_quat, tmp_0);
      quatmultiply(tmp_0, yaw_vec_correction_quat, rtDW->attitude_target_quat);
    }
  }

  rtDW->attitude_error_vector[2] = thrust_vector_length;
  rtDW->thrust_error_angle = feedforward_scalar;
  if (rtDW->use_sqrt_controller != 0.0) {
    feedforward_scalar = rtDW->accel_roll_max * 0.01 / 2.0;
    thrust_vector_length = feedforward_scalar;
    if (feedforward_scalar < rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLL_a) {
      thrust_vector_length = rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLL_a;
    }

    if (feedforward_scalar > rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLLER) {
      thrust_vector_length = rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLLER;
    }

    rtDW->rate_target_ang_vel[0] = sqrt_controller(rtDW->attitude_error_vector[0],
      rtDW->p_angle_roll, thrust_vector_length, rtDW->dt);
    thrust_vector_length = rtDW->accel_pitch_max * 0.01 / 2.0;
    feedforward_scalar = thrust_vector_length;
    if (thrust_vector_length < rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLL_a) {
      feedforward_scalar = rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLL_a;
    }

    if (thrust_vector_length > rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLLER) {
      feedforward_scalar = rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLLER;
    }

    rtDW->rate_target_ang_vel[1] = sqrt_controller(rtDW->attitude_error_vector[1],
      rtDW->p_angle_pitch, feedforward_scalar, rtDW->dt);
    feedforward_scalar = rtDW->accel_yaw_max * 0.01 / 2.0;
    thrust_vector_length = feedforward_scalar;
    if (feedforward_scalar < rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLE_j) {
      thrust_vector_length = rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLE_j;
    }

    if (feedforward_scalar > rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLER_) {
      thrust_vector_length = rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLER_;
    }

    rtDW->rate_target_ang_vel[2] = sqrt_controller(rtDW->attitude_error_vector[2],
      rtDW->p_angle_yaw, thrust_vector_length, rtDW->dt);
  } else {
    rtDW->rate_target_ang_vel[0] = rtDW->p_angle_roll *
      rtDW->attitude_error_vector[0];
    rtDW->rate_target_ang_vel[1] = rtDW->p_angle_pitch *
      rtDW->attitude_error_vector[1];
    rtDW->rate_target_ang_vel[2] = rtDW->p_angle_yaw *
      rtDW->attitude_error_vector[2];
  }

  feedforward_scalar = rtDW->attitude_error_vector[1];
  if (rtDW->attitude_error_vector[1] < -0.78539816339744828) {
    feedforward_scalar = -0.78539816339744828;
  }

  if (rtDW->attitude_error_vector[1] > 0.78539816339744828) {
    feedforward_scalar = 0.78539816339744828;
  }

  rtDW->rate_target_ang_vel[0] += feedforward_scalar * rtDW->gyro_z;
  feedforward_scalar = rtDW->attitude_error_vector[0];
  if (rtDW->attitude_error_vector[0] < -0.78539816339744828) {
    feedforward_scalar = -0.78539816339744828;
  }

  if (rtDW->attitude_error_vector[0] > 0.78539816339744828) {
    feedforward_scalar = 0.78539816339744828;
  }

  rtDW->rate_target_ang_vel[1] -= feedforward_scalar * rtDW->gyro_z;
  for (i = 0; i < 3; i++) {
    thrust_vec_cross[i] = rtDW->rate_target_ang_vel[i];
  }

  ang_vel_limit(thrust_vec_cross, rtDW->ang_vel_roll_max / 180.0 *
                3.1415926535897931, rtDW->ang_vel_pitch_max / 180.0 *
                3.1415926535897931, rtDW->ang_vel_yaw_max / 180.0 *
                3.1415926535897931, rtDW->rate_target_ang_vel);
  q[0] = attitude_vehicle_quat[0];
  q[1] = -attitude_vehicle_quat[1];
  q[2] = -attitude_vehicle_quat[2];
  q[3] = -attitude_vehicle_quat[3];
  quatmultiply(q, rtDW->attitude_target_quat, thrust_vec_correction_quat);
  q[0] = thrust_vec_correction_quat[0];
  q[1] = -thrust_vec_correction_quat[1];
  q[2] = -thrust_vec_correction_quat[2];
  q[3] = -thrust_vec_correction_quat[3];
  tmp_0[0] = 0.0;
  tmp_0[1] = rtDW->attitude_target_ang_vel[0];
  tmp_0[2] = rtDW->attitude_target_ang_vel[1];
  tmp_0[3] = rtDW->attitude_target_ang_vel[2];
  quatmultiply(q, tmp_0, tmp_1);
  quatmultiply(tmp_1, thrust_vec_correction_quat, yaw_vec_correction_quat);
  if (rtDW->thrust_error_angle > rtDW->AC_ATTITUDE_THRUST_ERROR_ANGLE * 2.0) {
    rtDW->rate_target_ang_vel[2] = rtDW->gyro_z;
  } else if (rtDW->thrust_error_angle > rtDW->AC_ATTITUDE_THRUST_ERROR_ANGLE) {
    feedforward_scalar = 1.0 - (rtDW->thrust_error_angle -
      rtDW->AC_ATTITUDE_THRUST_ERROR_ANGLE) /
      rtDW->AC_ATTITUDE_THRUST_ERROR_ANGLE;
    rtDW->rate_target_ang_vel[0] += yaw_vec_correction_quat[1] *
      feedforward_scalar;
    rtDW->rate_target_ang_vel[1] += yaw_vec_correction_quat[2] *
      feedforward_scalar;
    rtDW->rate_target_ang_vel[2] += yaw_vec_correction_quat[3];
    rtDW->rate_target_ang_vel[2] = (1.0 - feedforward_scalar) * rtDW->gyro_z +
      rtDW->rate_target_ang_vel[2] * feedforward_scalar;
  } else {
    rtDW->rate_target_ang_vel[0] += yaw_vec_correction_quat[1];
    rtDW->rate_target_ang_vel[1] += yaw_vec_correction_quat[2];
    rtDW->rate_target_ang_vel[2] += yaw_vec_correction_quat[3];
  }

  if (rtDW->rate_bf_ff_enabled != 0.0) {
    att_to_thrust_vec[0] = rtDW->attitude_target_ang_vel[0] * rtDW->dt;
    att_to_thrust_vec[1] = rtDW->attitude_target_ang_vel[1] * rtDW->dt;
    att_to_thrust_vec[2] = rtDW->attitude_target_ang_vel[2] * rtDW->dt;
    feedforward_scalar = norm_p(att_to_thrust_vec);
    if (feedforward_scalar == 0.0) {
      yaw_vec_correction_quat[0] = 1.0;
      yaw_vec_correction_quat[1] = 0.0;
      yaw_vec_correction_quat[2] = 0.0;
      yaw_vec_correction_quat[3] = 0.0;
    } else {
      att_to_thrust_vec[0] /= feedforward_scalar;
      att_to_thrust_vec[1] /= feedforward_scalar;
      att_to_thrust_vec[2] /= feedforward_scalar;
      from_axis_angle(att_to_thrust_vec, feedforward_scalar,
                      yaw_vec_correction_quat);
    }

    for (i = 0; i < 4; i++) {
      tmp_0[i] = rtDW->attitude_target_quat[i];
    }

    quatmultiply(tmp_0, yaw_vec_correction_quat, rtDW->attitude_target_quat);
    normalizeq(rtDW->attitude_target_quat);
  } else {
    normalizeq(rtDW->attitude_target_quat);
  }

  attitude_vehicle_quat[1] = -attitude_vehicle_quat[1];
  attitude_vehicle_quat[2] = -attitude_vehicle_quat[2];
  attitude_vehicle_quat[3] = -attitude_vehicle_quat[3];
  quatmultiply(attitude_vehicle_quat, rtDW->attitude_target_quat,
               rtDW->attitude_ang_error);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void input_euler_angle_roll_pitch__o(real_T euler_roll_angle_cd, real_T
  euler_pitch_angle_cd, real_T euler_yaw_rate_cds, DW *rtDW)
{
  real_T euler_roll_angle;
  real_T euler_pitch_angle;
  real_T euler_yaw_rate;
  real_T sin_phi;
  real_T cos_phi;
  real_T sin_theta;
  real_T b_delta_ang_vel;
  real_T b_y_tmp;
  real_T c_y_tmp;
  real_T euler_accel_idx_0;
  real_T euler_accel_idx_1;
  real_T euler_accel_idx_2;
  real_T attitude_target_euler_angle_tmp;
  real_T tmp[3];
  int32_T i;
  euler_roll_angle = euler_roll_angle_cd * 0.01 / 180.0 * 3.1415926535897931;
  euler_pitch_angle = euler_pitch_angle_cd * 0.01 / 180.0 * 3.1415926535897931;
  euler_yaw_rate = euler_yaw_rate_cds * 0.01 / 180.0 * 3.1415926535897931;
  attitude_target_euler_angle_tmp = rtDW->attitude_target_quat[2] *
    rtDW->attitude_target_quat[2];
  rtDW->attitude_target_euler_angle[0] = rt_atan2d_snf
    ((rtDW->attitude_target_quat[0] * rtDW->attitude_target_quat[1] +
      rtDW->attitude_target_quat[2] * rtDW->attitude_target_quat[3]) * 2.0, 1.0
     - (rtDW->attitude_target_quat[1] * rtDW->attitude_target_quat[1] +
        attitude_target_euler_angle_tmp) * 2.0);
  rtDW->attitude_target_euler_angle[1] = asin((rtDW->attitude_target_quat[0] *
    rtDW->attitude_target_quat[2] - rtDW->attitude_target_quat[3] *
    rtDW->attitude_target_quat[1]) * 2.0);
  rtDW->attitude_target_euler_angle[2] = rt_atan2d_snf
    ((rtDW->attitude_target_quat[0] * rtDW->attitude_target_quat[3] +
      rtDW->attitude_target_quat[1] * rtDW->attitude_target_quat[2]) * 2.0, 1.0
     - (attitude_target_euler_angle_tmp + rtDW->attitude_target_quat[3] *
        rtDW->attitude_target_quat[3]) * 2.0);
  if (rtDW->rate_bf_ff_enabled != 0.0) {
    euler_accel_idx_0 = rtDW->accel_roll_max * 0.01 / 180.0 * 3.1415926535897931;
    euler_accel_idx_1 = rtDW->accel_pitch_max * 0.01 / 180.0 *
      3.1415926535897931;
    euler_accel_idx_2 = rtDW->accel_yaw_max * 0.01 / 180.0 * 3.1415926535897931;
    attitude_target_euler_angle_tmp = sin(rtDW->attitude_target_euler_angle[0]);
    sin_phi = fabs(attitude_target_euler_angle_tmp);
    if (sin_phi < 0.1) {
      sin_phi = 0.1;
    }

    b_y_tmp = cos(rtDW->attitude_target_euler_angle[0]);
    cos_phi = fabs(b_y_tmp);
    if (cos_phi < 0.1) {
      cos_phi = 0.1;
    }

    c_y_tmp = sin(rtDW->attitude_target_euler_angle[1]);
    sin_theta = fabs(c_y_tmp);
    if (sin_theta < 0.1) {
      sin_theta = 0.1;
    }

    if ((euler_accel_idx_0 == 0.0) || (euler_accel_idx_1 == 0.0) ||
        (euler_accel_idx_2 == 0.0) || (euler_accel_idx_0 < 0.0) ||
        (euler_accel_idx_1 < 0.0) || (euler_accel_idx_2 < 0.0)) {
      b_delta_ang_vel = euler_accel_idx_1;
      sin_phi = euler_accel_idx_2;
    } else {
      b_delta_ang_vel = fmin(euler_accel_idx_1 / cos_phi, euler_accel_idx_2 /
        sin_phi);
      sin_phi = fmin(fmin(euler_accel_idx_0 / sin_theta, euler_accel_idx_1 /
                          sin_phi), euler_accel_idx_2 / cos_phi);
    }

    euler_accel_idx_1 = b_delta_ang_vel;
    euler_accel_idx_2 = sin_phi;
    cos_phi = 1.0 / fmax(rtDW->input_tc, 0.01);
    euler_roll_angle = sqrt_controller(wrap_PI(euler_roll_angle -
      rtDW->attitude_target_euler_angle[0]), cos_phi, euler_accel_idx_0,
      rtDW->dt);
    if (euler_accel_idx_0 > 0.0) {
      b_delta_ang_vel = euler_accel_idx_0 * rtDW->dt;
      euler_accel_idx_0 = rtDW->attitude_target_euler_rate[0] - b_delta_ang_vel;
      sin_phi = rtDW->attitude_target_euler_rate[0] + b_delta_ang_vel;
      b_delta_ang_vel = euler_roll_angle;
      if (euler_roll_angle < euler_accel_idx_0) {
        b_delta_ang_vel = euler_accel_idx_0;
      }

      if (euler_roll_angle > sin_phi) {
        b_delta_ang_vel = sin_phi;
      }
    } else {
      b_delta_ang_vel = euler_roll_angle;
    }

    rtDW->attitude_target_euler_rate[0] = b_delta_ang_vel;
    euler_pitch_angle = sqrt_controller(wrap_PI(euler_pitch_angle -
      rtDW->attitude_target_euler_angle[1]), cos_phi, euler_accel_idx_1,
      rtDW->dt);
    if (euler_accel_idx_1 > 0.0) {
      euler_accel_idx_0 = euler_accel_idx_1 * rtDW->dt;
      euler_roll_angle = rtDW->attitude_target_euler_rate[1] - euler_accel_idx_0;
      b_delta_ang_vel = rtDW->attitude_target_euler_rate[1] + euler_accel_idx_0;
      euler_accel_idx_0 = euler_pitch_angle;
      if (euler_pitch_angle < euler_roll_angle) {
        euler_accel_idx_0 = euler_roll_angle;
      }

      if (euler_pitch_angle > b_delta_ang_vel) {
        euler_accel_idx_0 = b_delta_ang_vel;
      }
    } else {
      euler_accel_idx_0 = euler_pitch_angle;
    }

    rtDW->attitude_target_euler_rate[1] = euler_accel_idx_0;
    if (euler_accel_idx_2 > 0.0) {
      euler_roll_angle = euler_accel_idx_2 * rtDW->dt;
      euler_pitch_angle = rtDW->attitude_target_euler_rate[2] - euler_roll_angle;
      euler_accel_idx_0 = rtDW->attitude_target_euler_rate[2] + euler_roll_angle;
      euler_roll_angle = euler_yaw_rate;
      if (euler_yaw_rate < euler_pitch_angle) {
        euler_roll_angle = euler_pitch_angle;
      }

      if (euler_yaw_rate > euler_accel_idx_0) {
        euler_roll_angle = euler_accel_idx_0;
      }
    } else {
      euler_roll_angle = euler_yaw_rate;
    }

    rtDW->attitude_target_euler_rate[2] = euler_roll_angle;
    euler_pitch_angle = cos(rtDW->attitude_target_euler_angle[1]);
    rtDW->attitude_target_ang_vel[0] = rtDW->attitude_target_euler_rate[0] -
      c_y_tmp * rtDW->attitude_target_euler_rate[2];
    rtDW->attitude_target_ang_vel[1] = attitude_target_euler_angle_tmp *
      euler_pitch_angle * rtDW->attitude_target_euler_rate[2] + b_y_tmp *
      rtDW->attitude_target_euler_rate[1];
    rtDW->attitude_target_ang_vel[2] = euler_pitch_angle * b_y_tmp *
      rtDW->attitude_target_euler_rate[2] + -attitude_target_euler_angle_tmp *
      rtDW->attitude_target_euler_rate[1];
    for (i = 0; i < 3; i++) {
      tmp[i] = rtDW->attitude_target_ang_vel[i];
    }

    ang_vel_limit(tmp, rtDW->ang_vel_roll_max / 180.0 * 3.1415926535897931,
                  rtDW->ang_vel_pitch_max / 180.0 * 3.1415926535897931,
                  rtDW->ang_vel_yaw_max / 180.0 * 3.1415926535897931,
                  rtDW->attitude_target_ang_vel);
    if (euler_pitch_angle == 0.0) {
      euler_pitch_angle = 1.0E-6;
    }

    euler_roll_angle = c_y_tmp / euler_pitch_angle;
    rtDW->attitude_target_euler_rate[0] = (euler_roll_angle *
      attitude_target_euler_angle_tmp * rtDW->attitude_target_ang_vel[1] +
      rtDW->attitude_target_ang_vel[0]) + euler_roll_angle * b_y_tmp *
      rtDW->attitude_target_ang_vel[2];
    rtDW->attitude_target_euler_rate[1] = b_y_tmp *
      rtDW->attitude_target_ang_vel[1] - attitude_target_euler_angle_tmp *
      rtDW->attitude_target_ang_vel[2];
    rtDW->attitude_target_euler_rate[2] = attitude_target_euler_angle_tmp /
      euler_pitch_angle * rtDW->attitude_target_ang_vel[1] + b_y_tmp /
      euler_pitch_angle * rtDW->attitude_target_ang_vel[2];
  } else {
    rtDW->attitude_target_euler_angle[0] = euler_roll_angle;
    rtDW->attitude_target_euler_angle[1] = euler_pitch_angle;
    rtDW->attitude_target_euler_angle[2] += euler_yaw_rate * rtDW->dt;
    from_euler(rtDW->attitude_target_euler_angle, rtDW->attitude_target_quat);
    rtDW->attitude_target_euler_rate[0] = 0.0;
    rtDW->attitude_target_ang_vel[0] = 0.0;
    rtDW->attitude_target_euler_rate[1] = 0.0;
    rtDW->attitude_target_ang_vel[1] = 0.0;
    rtDW->attitude_target_euler_rate[2] = 0.0;
    rtDW->attitude_target_ang_vel[2] = 0.0;
  }

  attitude_controller_run_quat(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void rate_controller_run(DW *rtDW)
{
  real_T rate_error_rads;
  real_T tmp;
  rate_error_rads = rtDW->rate_target_ang_vel[0] - rtDW->gyro_x;
  if (rtDW->rate_roll_pid_reset_filter == 1.0) {
    rtDW->rate_roll_pid_reset_filter = 0.0;
    rtDW->rate_roll_pid_derivative = 0.0;
    rtDW->rate_roll_pid_integrator = 0.0;
    rtDW->rate_roll_pid_input = rate_error_rads;
  }

  if (rtDW->ATC_RAT_RLL_FILT == 0.0) {
    tmp = 1.0;
  } else {
    tmp = rtDW->ATC_RAT_RLL_FILT;
  }

  rtDW->rate_roll_pid_derivative += rtDW->dt / (1.0 / (6.2831853071795862 * tmp)
    + rtDW->dt) * ((rate_error_rads - rtDW->rate_roll_pid_input) / rtDW->dt -
                   rtDW->rate_roll_pid_derivative);
  rtDW->rate_roll_pid_input = rate_error_rads;
  if ((!(rtDW->motors_limit_roll_pitch != 0.0)) ||
      ((rtDW->rate_roll_pid_integrator > 0.0) && (rate_error_rads < 0.0)) ||
      ((rtDW->rate_roll_pid_integrator < 0.0) && (rate_error_rads > 0.0))) {
    rtDW->rate_roll_pid_integrator += rtDW->rate_roll_pid_input *
      rtDW->ATC_RAT_RLL_I * rtDW->dt;
    if (rtDW->rate_roll_pid_integrator < -rtDW->ATC_RAT_RLL_IMAX) {
      rtDW->rate_roll_pid_integrator = -rtDW->ATC_RAT_RLL_IMAX;
    } else {
      if (rtDW->rate_roll_pid_integrator > rtDW->ATC_RAT_RLL_IMAX) {
        rtDW->rate_roll_pid_integrator = rtDW->ATC_RAT_RLL_IMAX;
      }
    }
  }

  rtDW->roll_in = ((rtDW->ATC_RAT_RLL_P * rtDW->rate_roll_pid_input +
                    rtDW->rate_roll_pid_integrator) + rtDW->ATC_RAT_RLL_D *
                   rtDW->rate_roll_pid_derivative) + rtDW->ATC_RAT_RLL_FF *
    rtDW->rate_target_ang_vel[0];
  rate_error_rads = rtDW->rate_target_ang_vel[1] - rtDW->gyro_y;
  if (rtDW->rate_pitch_pid_reset_filter == 1.0) {
    rtDW->rate_pitch_pid_reset_filter = 0.0;
    rtDW->rate_pitch_pid_derivative = 0.0;
    rtDW->rate_pitch_pid_integrator = 0.0;
    rtDW->rate_pitch_pid_input = rate_error_rads;
  }

  if (rtDW->ATC_RAT_PIT_FILT == 0.0) {
    tmp = 1.0;
  } else {
    tmp = rtDW->ATC_RAT_PIT_FILT;
  }

  rtDW->rate_pitch_pid_derivative += rtDW->dt / (1.0 / (6.2831853071795862 * tmp)
    + rtDW->dt) * ((rate_error_rads - rtDW->rate_pitch_pid_input) / rtDW->dt -
                   rtDW->rate_pitch_pid_derivative);
  rtDW->rate_pitch_pid_input = rate_error_rads;
  if ((!(rtDW->motors_limit_roll_pitch != 0.0)) ||
      ((rtDW->rate_pitch_pid_integrator > 0.0) && (rate_error_rads < 0.0)) ||
      ((rtDW->rate_pitch_pid_integrator < 0.0) && (rate_error_rads > 0.0))) {
    rtDW->rate_pitch_pid_integrator += rtDW->rate_pitch_pid_input *
      rtDW->ATC_RAT_PIT_I * rtDW->dt;
    if (rtDW->rate_pitch_pid_integrator < -rtDW->ATC_RAT_PIT_IMAX) {
      rtDW->rate_pitch_pid_integrator = -rtDW->ATC_RAT_PIT_IMAX;
    } else {
      if (rtDW->rate_pitch_pid_integrator > rtDW->ATC_RAT_PIT_IMAX) {
        rtDW->rate_pitch_pid_integrator = rtDW->ATC_RAT_PIT_IMAX;
      }
    }
  }

  rtDW->pitch_in = ((rtDW->ATC_RAT_PIT_P * rtDW->rate_pitch_pid_input +
                     rtDW->rate_pitch_pid_integrator) + rtDW->ATC_RAT_PIT_D *
                    rtDW->rate_pitch_pid_derivative) + rtDW->ATC_RAT_PIT_FF *
    rtDW->rate_target_ang_vel[1];
  rate_error_rads = rtDW->pitch_in;
  if (rtDW->pitch_in < -1.0) {
    rtDW->pitch_in = -1.0;
  }

  if (rate_error_rads > 1.0) {
    rtDW->pitch_in = 1.0;
  }

  rate_error_rads = rtDW->rate_target_ang_vel[2] - rtDW->gyro_z;
  if (rtDW->rate_yaw_pid_reset_filter == 1.0) {
    rtDW->rate_yaw_pid_reset_filter = 0.0;
    rtDW->rate_yaw_pid_derivative = 0.0;
    rtDW->rate_yaw_pid_integrator = 0.0;
    rtDW->rate_yaw_pid_input = rate_error_rads;
  }

  if (rtDW->ATC_RAT_YAW_FILT == 0.0) {
    tmp = 1.0;
  } else {
    tmp = rtDW->ATC_RAT_YAW_FILT;
  }

  rtDW->rate_yaw_pid_derivative += rtDW->dt / (1.0 / (6.2831853071795862 * tmp)
    + rtDW->dt) * ((rate_error_rads - rtDW->rate_yaw_pid_input) / rtDW->dt -
                   rtDW->rate_yaw_pid_derivative);
  rtDW->rate_yaw_pid_input = rate_error_rads;
  if ((!(rtDW->motors_limit_yaw != 0.0)) || ((rtDW->rate_yaw_pid_integrator >
        0.0) && (rate_error_rads < 0.0)) || ((rtDW->rate_yaw_pid_integrator <
        0.0) && (rate_error_rads > 0.0))) {
    rtDW->rate_yaw_pid_integrator += rtDW->rate_yaw_pid_input *
      rtDW->ATC_RAT_YAW_I * rtDW->dt;
    if (rtDW->rate_yaw_pid_integrator < -rtDW->ATC_RAT_YAW_IMAX) {
      rtDW->rate_yaw_pid_integrator = -rtDW->ATC_RAT_YAW_IMAX;
    } else {
      if (rtDW->rate_yaw_pid_integrator > rtDW->ATC_RAT_YAW_IMAX) {
        rtDW->rate_yaw_pid_integrator = rtDW->ATC_RAT_YAW_IMAX;
      }
    }
  }

  rtDW->yaw_in = ((rtDW->ATC_RAT_YAW_P * rtDW->rate_yaw_pid_input +
                   rtDW->rate_yaw_pid_integrator) + rtDW->ATC_RAT_YAW_D *
                  rtDW->rate_yaw_pid_derivative) + rtDW->ATC_RAT_YAW_FF *
    rtDW->rate_target_ang_vel[2];
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_throttle_filter(DW *rtDW)
{
  real_T throttle_filter_temp;
  real_T alpha;
  real_T thrust_dt;
  real_T amt;
  if (rtDW->armed != 0.0) {
    throttle_filter_temp = rtDW->throttle_filter;
    if (rtDW->throttle_cutoff_frequency <= 0.0) {
      rtDW->throttle_filter = rtDW->throttle_in;
    }

    amt = rtDW->dt / (1.0 / (6.2831853071795862 *
      rtDW->throttle_cutoff_frequency) + rtDW->dt);
    alpha = amt;
    if (amt < 0.0) {
      alpha = 0.0;
    }

    if (amt > 1.0) {
      alpha = 1.0;
    }

    rtDW->throttle_filter += (rtDW->throttle_in - rtDW->throttle_filter) * alpha;
    if (rtDW->throttle_filter < 0.0) {
      rtDW->throttle_filter = 0.0;
    }

    if (rtDW->throttle_filter > 1.0) {
      rtDW->throttle_filter = 1.0;
    }

    thrust_dt = rtDW->dt / rtDW->thrust_slew_time / 3.0;
    amt = rtDW->throttle_filter;
    alpha = throttle_filter_temp - thrust_dt;
    throttle_filter_temp += thrust_dt;
    if (rtDW->throttle_filter < alpha) {
      rtDW->throttle_filter = alpha;
    }

    if (amt > throttle_filter_temp) {
      rtDW->throttle_filter = throttle_filter_temp;
    }

    if (rtDW->throttle_filter > 0.9) {
      rtDW->throttle_filter = 0.9;
    }
  } else {
    rtDW->throttle_filter = 0.0;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void output_armed_stabilizing(DW *rtDW)
{
  real_T rpy_scale;
  real_T compensation_gain;
  real_T roll_thrust;
  real_T pitch_thrust;
  real_T yaw_thrust;
  real_T throttle_thrust;
  real_T rp_low;
  real_T rp_high;
  rpy_scale = 1.0;
  compensation_gain = 1.0;
  if ((rtDW->air_density_ratio > 0.3) && (rtDW->air_density_ratio < 1.5)) {
    yaw_thrust = rtDW->air_density_ratio;
    if (rtDW->air_density_ratio < 0.5) {
      yaw_thrust = 0.5;
    }

    if (rtDW->air_density_ratio > 1.25) {
      yaw_thrust = 1.25;
    }

    compensation_gain = 1.0 / yaw_thrust;
  }

  roll_thrust = rtDW->roll_in * compensation_gain;
  pitch_thrust = rtDW->pitch_in * compensation_gain;
  yaw_thrust = rtDW->yaw_in * compensation_gain;
  throttle_thrust = rtDW->throttle_filter * compensation_gain;
  compensation_gain *= rtDW->throttle_avg_max;
  rtDW->throttle_thrust_max = (1.0 - rtDW->thrust_boost_ratio) *
    rtDW->throttle_thrust_max + rtDW->thrust_boost_ratio;
  rtDW->throttle_lower = 0.0;
  if (throttle_thrust <= 0.0) {
    throttle_thrust = 0.0;
    rtDW->throttle_lower = 1.0;
  }

  rtDW->throttle_upper = 0.0;
  if (throttle_thrust >= rtDW->throttle_thrust_max) {
    throttle_thrust = rtDW->throttle_thrust_max;
    rtDW->throttle_upper = 1.0;
  }

  rp_low = compensation_gain;
  if (compensation_gain < throttle_thrust) {
    compensation_gain = throttle_thrust;
  }

  if (rp_low > rtDW->throttle_thrust_max) {
    compensation_gain = rtDW->throttle_thrust_max;
  }

  rp_low = 1.0;
  rp_high = -1.0;
  rtDW->thrust_rpyt_out[0] = (fabs(rtDW->pitch_factor[0]) * rtDW->Kx * 0.0 +
    rtDW->pitch_factor[0]) * pitch_thrust + roll_thrust * rtDW->roll_factor[0];
  if (rtDW->thrust_rpyt_out[0] < 1.0) {
    rp_low = rtDW->thrust_rpyt_out[0];
  }

  if ((rtDW->thrust_rpyt_out[0] > -1.0) && (!(rtDW->thrust_boost != 0.0))) {
    rp_high = rtDW->thrust_rpyt_out[0];
  }

  rtDW->thrust_rpyt_out[1] = (fabs(rtDW->pitch_factor[1]) * rtDW->Kx * 0.0 +
    rtDW->pitch_factor[1]) * pitch_thrust + roll_thrust * rtDW->roll_factor[1];
  if (rtDW->thrust_rpyt_out[1] < rp_low) {
    rp_low = rtDW->thrust_rpyt_out[1];
  }

  if ((rtDW->thrust_rpyt_out[1] > rp_high) && (!(rtDW->thrust_boost != 0.0))) {
    rp_high = rtDW->thrust_rpyt_out[1];
  }

  rtDW->thrust_rpyt_out[2] = (fabs(rtDW->pitch_factor[2]) * rtDW->Kx * 0.0 +
    rtDW->pitch_factor[2]) * pitch_thrust + roll_thrust * rtDW->roll_factor[2];
  if (rtDW->thrust_rpyt_out[2] < rp_low) {
    rp_low = rtDW->thrust_rpyt_out[2];
  }

  if ((rtDW->thrust_rpyt_out[2] > rp_high) && (!(rtDW->thrust_boost != 0.0))) {
    rp_high = rtDW->thrust_rpyt_out[2];
  }

  rtDW->thrust_rpyt_out[3] = (fabs(rtDW->pitch_factor[3]) * rtDW->Kx * 0.0 +
    rtDW->pitch_factor[3]) * pitch_thrust + roll_thrust * rtDW->roll_factor[3];
  if (rtDW->thrust_rpyt_out[3] < rp_low) {
    rp_low = rtDW->thrust_rpyt_out[3];
  }

  if ((rtDW->thrust_rpyt_out[3] > rp_high) && (!(rtDW->thrust_boost != 0.0))) {
    rp_high = rtDW->thrust_rpyt_out[3];
  }

  if ((rp_high - rp_low > 1.0) || (compensation_gain < -rp_low)) {
    rtDW->limit_roll_pitch = 1.0;
  }

  roll_thrust = fmin(0.5, compensation_gain);
  roll_thrust = fmax(fmin(roll_thrust + rp_low, 1.0 - (roll_thrust + rp_high)),
                     (1.0 - rtDW->thrust_boost_ratio) * (rtDW->yaw_headroom /
    1000.0) + rtDW->thrust_boost_ratio * 0.5) / 2.5599;
  if (fabs(yaw_thrust) > roll_thrust) {
    pitch_thrust = yaw_thrust;
    if (yaw_thrust < -roll_thrust) {
      yaw_thrust = -roll_thrust;
    }

    if (pitch_thrust > roll_thrust) {
      yaw_thrust = roll_thrust;
    }

    rtDW->limit_yaw = 1.0;
  }

  roll_thrust = 1.0;
  pitch_thrust = -1.0;
  rtDW->thrust_rpyt_out[0] += yaw_thrust * rtDW->yaw_factor[0];
  if (rtDW->thrust_rpyt_out[0] < 1.0) {
    roll_thrust = rtDW->thrust_rpyt_out[0];
  }

  if (rtDW->thrust_rpyt_out[0] > -1.0) {
    pitch_thrust = rtDW->thrust_rpyt_out[0];
  }

  rtDW->thrust_rpyt_out[1] += yaw_thrust * rtDW->yaw_factor[1];
  if (rtDW->thrust_rpyt_out[1] < roll_thrust) {
    roll_thrust = rtDW->thrust_rpyt_out[1];
  }

  if (rtDW->thrust_rpyt_out[1] > pitch_thrust) {
    pitch_thrust = rtDW->thrust_rpyt_out[1];
  }

  rtDW->thrust_rpyt_out[2] += yaw_thrust * rtDW->yaw_factor[2];
  if (rtDW->thrust_rpyt_out[2] < roll_thrust) {
    roll_thrust = rtDW->thrust_rpyt_out[2];
  }

  if (rtDW->thrust_rpyt_out[2] > pitch_thrust) {
    pitch_thrust = rtDW->thrust_rpyt_out[2];
  }

  rtDW->thrust_rpyt_out[3] += yaw_thrust * rtDW->yaw_factor[3];
  if (rtDW->thrust_rpyt_out[3] < roll_thrust) {
    roll_thrust = rtDW->thrust_rpyt_out[3];
  }

  if (rtDW->thrust_rpyt_out[3] > pitch_thrust) {
    pitch_thrust = rtDW->thrust_rpyt_out[3];
  }

  rp_low = pitch_thrust - roll_thrust;
  if (rp_low > 1.0) {
    rpy_scale = 1.0 / rp_low;
  }

  if (roll_thrust < 0.0) {
    rpy_scale = fmin(rpy_scale, -compensation_gain / roll_thrust);
  }

  pitch_thrust *= rpy_scale;
  roll_thrust *= rpy_scale;
  yaw_thrust = throttle_thrust - (-roll_thrust);
  if (rpy_scale < 1.0) {
    rtDW->limit_roll_pitch = 1.0;
    rtDW->limit_yaw = 1.0;
    if (yaw_thrust > 0.0) {
      rtDW->throttle_upper = 1.0;
    }

    yaw_thrust = 0.0;
  } else if (yaw_thrust < 0.0) {
    yaw_thrust = 0.0;
  } else {
    rp_low = 1.0 - (-roll_thrust + pitch_thrust);
    if (yaw_thrust > rp_low) {
      yaw_thrust = rp_low;
      rtDW->throttle_upper = 1.0;
    }
  }

  compensation_gain = -roll_thrust + yaw_thrust;
  rtDW->thrust_rpyt_out[0] = compensation_gain + rpy_scale *
    rtDW->thrust_rpyt_out[0];
  rtDW->thrust_rpyt_out[1] = compensation_gain + rpy_scale *
    rtDW->thrust_rpyt_out[1];
  rtDW->thrust_rpyt_out[2] = compensation_gain + rpy_scale *
    rtDW->thrust_rpyt_out[2];
  rtDW->thrust_rpyt_out[3] = compensation_gain + rpy_scale *
    rtDW->thrust_rpyt_out[3];
  rpy_scale = cos(rtDW->current_tilt);
  rtDW->thrust_rpyt_out[1] *= rpy_scale;
  rtDW->thrust_rpyt_out[3] *= rpy_scale;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void AP_MotorsMulticopter_output_4a1(DW *rtDW)
{
  real_T thrust_dt;
  real_T pwm_out_temp;
  real_T low;
  real_T high;
  real_T thrust_dt_tmp;
  update_throttle_filter(rtDW);
  output_armed_stabilizing(rtDW);
  thrust_dt_tmp = rtDW->pwm_max - rtDW->pwm_min;
  thrust_dt = thrust_dt_tmp * rtDW->dt / rtDW->thrust_slew_time;
  pwm_out_temp = thrust_dt_tmp * rtDW->k_throttle + rtDW->pwm_min;
  low = rtDW->pwm_tail - thrust_dt;
  high = rtDW->pwm_tail + thrust_dt;
  rtDW->pwm_tail = pwm_out_temp;
  if (pwm_out_temp < low) {
    rtDW->pwm_tail = low;
  }

  if (pwm_out_temp > high) {
    rtDW->pwm_tail = high;
  }

  pwm_out_temp = rtDW->pwm_tail;
  if (rtDW->pwm_tail < rtDW->pwm_min) {
    rtDW->pwm_tail = rtDW->pwm_min;
  }

  if (pwm_out_temp > rtDW->pwm_max) {
    rtDW->pwm_tail = rtDW->pwm_max;
  }

  pwm_out_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[0] + rtDW->pwm_min;
  low = rtDW->pwm_out[0] - thrust_dt;
  high = rtDW->pwm_out[0] + thrust_dt;
  rtDW->pwm_out[0] = pwm_out_temp;
  if (pwm_out_temp < low) {
    rtDW->pwm_out[0] = low;
  }

  if (pwm_out_temp > high) {
    rtDW->pwm_out[0] = high;
  }

  pwm_out_temp = rtDW->pwm_out[0];
  if (rtDW->pwm_out[0] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[0] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[0] = pwm_out_temp;
  pwm_out_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[1] + rtDW->pwm_min;
  low = rtDW->pwm_out[1] - thrust_dt;
  high = rtDW->pwm_out[1] + thrust_dt;
  rtDW->pwm_out[1] = pwm_out_temp;
  if (pwm_out_temp < low) {
    rtDW->pwm_out[1] = low;
  }

  if (pwm_out_temp > high) {
    rtDW->pwm_out[1] = high;
  }

  pwm_out_temp = rtDW->pwm_out[1];
  if (rtDW->pwm_out[1] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[1] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[1] = pwm_out_temp;
  pwm_out_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[2] + rtDW->pwm_min;
  low = rtDW->pwm_out[2] - thrust_dt;
  high = rtDW->pwm_out[2] + thrust_dt;
  rtDW->pwm_out[2] = pwm_out_temp;
  if (pwm_out_temp < low) {
    rtDW->pwm_out[2] = low;
  }

  if (pwm_out_temp > high) {
    rtDW->pwm_out[2] = high;
  }

  pwm_out_temp = rtDW->pwm_out[2];
  if (rtDW->pwm_out[2] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[2] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[2] = pwm_out_temp;
  pwm_out_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[3] + rtDW->pwm_min;
  low = rtDW->pwm_out[3] - thrust_dt;
  high = rtDW->pwm_out[3] + thrust_dt;
  rtDW->pwm_out[3] = pwm_out_temp;
  if (pwm_out_temp < low) {
    rtDW->pwm_out[3] = low;
  }

  if (pwm_out_temp > high) {
    rtDW->pwm_out[3] = high;
  }

  pwm_out_temp = rtDW->pwm_out[3];
  if (rtDW->pwm_out[3] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[3] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[3] = pwm_out_temp;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void set_alt_target_from_climb_rate_(real_T b_climb_rate_cms, real_T b_dt,
  real_T force_descend, DW *rtDW)
{
  real_T accel_z_cms;
  real_T jerk_z;
  accel_z_cms = rtDW->POSCONTROL_ACCEL_Z;
  if ((rtDW->vel_desired[2] < rtDW->POSCONTROL_SPEED_DOWN) &&
      (rtDW->POSCONTROL_SPEED_DOWN != 0.0)) {
    accel_z_cms = rtDW->POSCONTROL_ACCEL_Z * rtDW->POSCONTROL_OVERSPEED_GAIN_Z *
      rtDW->vel_desired[2] / rtDW->POSCONTROL_SPEED_DOWN;
  }

  if ((rtDW->vel_desired[2] > rtDW->POSCONTROL_SPEED_UP) &&
      (rtDW->POSCONTROL_SPEED_UP != 0.0)) {
    accel_z_cms = accel_z_cms * rtDW->POSCONTROL_OVERSPEED_GAIN_Z *
      rtDW->vel_desired[2] / rtDW->POSCONTROL_SPEED_UP;
  }

  jerk_z = accel_z_cms;
  if (accel_z_cms < 0.0) {
    accel_z_cms = 0.0;
  }

  if (jerk_z > 750.0) {
    accel_z_cms = 750.0;
  }

  jerk_z = accel_z_cms * rtDW->POSCONTROL_JERK_RATIO;
  rtDW->accel_last_z_cms += jerk_z * b_dt;
  rtDW->accel_last_z_cms = fmin(fmin(accel_z_cms, sqrt(fabs(rtDW->vel_desired[2]
    - b_climb_rate_cms) * 2.0 * jerk_z)), rtDW->accel_last_z_cms);
  jerk_z = rtDW->accel_last_z_cms * b_dt;
  accel_z_cms = rtDW->vel_desired[2] - jerk_z;
  jerk_z += rtDW->vel_desired[2];
  rtDW->vel_desired[2] = b_climb_rate_cms;
  if (b_climb_rate_cms < accel_z_cms) {
    rtDW->vel_desired[2] = accel_z_cms;
  }

  if (b_climb_rate_cms > jerk_z) {
    rtDW->vel_desired[2] = jerk_z;
  }

  rtDW->use_desvel_ff_z = 1.0;
  if ((rtDW->vel_desired[2] < 0.0) && ((!(rtDW->throttle_lower != 0.0)) ||
       (force_descend != 0.0))) {
    rtDW->pos_target[2] += rtDW->vel_desired[2] * b_dt;
  } else {
    if ((rtDW->vel_desired[2] > 0.0) && ((!(rtDW->throttle_upper != 0.0)) &&
         (!(rtDW->limit_pos_up != 0.0)))) {
      rtDW->pos_target[2] += rtDW->vel_desired[2] * b_dt;
    }
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_z_controller(DW *rtDW)
{
  real_T alpha;
  real_T amt;
  if (rtDW->recalc_leash_z != 0.0) {
    alpha = rtDW->POSCONTROL_ACCEL_Z;
    if (rtDW->POSCONTROL_ACCEL_Z <= 0.0) {
      alpha = rtDW->POSCONTROL_ACCELERATION_MIN;
    }

    if (rtDW->POSCONTROL_POS_Z_P <= 0.0) {
      rtDW->leash_up_z = rtDW->POSCONTROL_LEASH_LENGTH_MIN;
    } else {
      if (rtDW->POSCONTROL_SPEED_UP <= alpha / rtDW->POSCONTROL_POS_Z_P) {
        rtDW->leash_up_z = rtDW->POSCONTROL_SPEED_UP / rtDW->POSCONTROL_POS_Z_P;
      } else {
        rtDW->leash_up_z = alpha / (2.0 * rtDW->POSCONTROL_POS_Z_P *
          rtDW->POSCONTROL_POS_Z_P) + rtDW->POSCONTROL_SPEED_UP *
          rtDW->POSCONTROL_SPEED_UP / (2.0 * alpha);
      }

      if (rtDW->leash_up_z < rtDW->POSCONTROL_LEASH_LENGTH_MIN) {
        rtDW->leash_up_z = rtDW->POSCONTROL_LEASH_LENGTH_MIN;
      }
    }

    alpha = rtDW->POSCONTROL_ACCEL_Z;
    if (rtDW->POSCONTROL_ACCEL_Z <= 0.0) {
      alpha = rtDW->POSCONTROL_ACCELERATION_MIN;
    }

    if (rtDW->POSCONTROL_POS_Z_P <= 0.0) {
      rtDW->leash_down_z = rtDW->POSCONTROL_LEASH_LENGTH_MIN;
    } else {
      if (-rtDW->POSCONTROL_SPEED_DOWN <= alpha / rtDW->POSCONTROL_POS_Z_P) {
        rtDW->leash_down_z = -rtDW->POSCONTROL_SPEED_DOWN /
          rtDW->POSCONTROL_POS_Z_P;
      } else {
        rtDW->leash_down_z = alpha / (2.0 * rtDW->POSCONTROL_POS_Z_P *
          rtDW->POSCONTROL_POS_Z_P) + -rtDW->POSCONTROL_SPEED_DOWN *
          -rtDW->POSCONTROL_SPEED_DOWN / (2.0 * alpha);
      }

      if (rtDW->leash_down_z < rtDW->POSCONTROL_LEASH_LENGTH_MIN) {
        rtDW->leash_down_z = rtDW->POSCONTROL_LEASH_LENGTH_MIN;
      }
    }

    rtDW->recalc_leash_z = 0.0;
  }

  rtDW->limit_pos_up = 0.0;
  rtDW->limit_pos_down = 0.0;
  rtDW->pos_error[2] = rtDW->pos_target[2] - rtDW->curr_alt;
  if (rtDW->pos_error[2] > rtDW->leash_up_z) {
    rtDW->pos_target[2] = rtDW->curr_alt + rtDW->leash_up_z;
    rtDW->pos_error[2] = rtDW->leash_up_z;
    rtDW->limit_pos_up = 1.0;
  }

  if (rtDW->pos_error[2] < -rtDW->leash_down_z) {
    rtDW->pos_target[2] = rtDW->curr_alt - rtDW->leash_down_z;
    rtDW->pos_error[2] = -rtDW->leash_down_z;
    rtDW->limit_pos_down = 1.0;
  }

  rtDW->vel_target[2] = sqrt_controller(rtDW->pos_error[2],
    rtDW->POSCONTROL_POS_Z_P, rtDW->POSCONTROL_ACCEL_Z, rtDW->dt);
  rtDW->limit_vel_up = 0.0;
  rtDW->limit_vel_down = 0.0;
  if (rtDW->vel_target[2] < rtDW->POSCONTROL_SPEED_DOWN) {
    rtDW->vel_target[2] = rtDW->POSCONTROL_SPEED_DOWN;
    rtDW->limit_vel_down = 1.0;
  }

  if (rtDW->vel_target[2] > rtDW->POSCONTROL_SPEED_UP) {
    rtDW->vel_target[2] = rtDW->POSCONTROL_SPEED_UP;
    rtDW->limit_vel_up = 1.0;
  }

  if (rtDW->take_off_land != 0.0) {
    rtDW->vel_target[2] = rtDW->vel_desired[2];
  } else {
    rtDW->vel_target[2] += rtDW->vel_desired[2];
  }

  rtDW->vel_last[2] = rtDW->vel_target[2];
  if (rtDW->reset_rate_to_accel_z != 0.0) {
    rtDW->vel_error[2] = 0.0;
    rtDW->vel_error_input = 0.0;
    rtDW->reset_rate_to_accel_z = 0.0;
  } else {
    if (rtDW->POSCONTROL_VEL_ERROR_CUTOFF_FRE <= 0.0) {
      rtDW->vel_error_input = rtDW->vel_target[2] - rtDW->curr_vel[2];
    } else {
      rtDW->vel_error_input += rtDW->dt / (1.0 / (6.2831853071795862 *
        rtDW->POSCONTROL_VEL_ERROR_CUTOFF_FRE) + rtDW->dt) * ((rtDW->vel_target
        [2] - rtDW->curr_vel[2]) - rtDW->vel_error_input);
    }

    rtDW->vel_error[2] = rtDW->vel_error_input;
  }

  rtDW->accel_target[2] = rtDW->POSCONTROL_VEL_Z_P * rtDW->vel_error[2];
  if (rtDW->pid_accel_z_reset_filter != 0.0) {
    rtDW->pid_accel_z_reset_filter = 0.0;
    rtDW->pid_accel_z_input = rtDW->accel_target[2];
    rtDW->pid_accel_z_derivative = 0.0;
    rtDW->pid_accel_z_integrator = 0.0;
  } else {
    if (rtDW->POSCONTROL_ACC_Z_FILT_HZ == 0.0) {
      alpha = 1.0;
    } else {
      alpha = rtDW->dt / (1.0 / (6.2831853071795862 *
        rtDW->POSCONTROL_ACC_Z_FILT_HZ) + rtDW->dt);
    }

    alpha *= rtDW->accel_target[2] - rtDW->pid_accel_z_input;
    rtDW->pid_accel_z_input += alpha;
    rtDW->pid_accel_z_derivative = alpha / rtDW->dt;
  }

  alpha = rtDW->pid_accel_z_integrator;
  if (((!(rtDW->throttle_lower != 0.0)) && (!(rtDW->throttle_upper != 0.0))) ||
      ((rtDW->pid_accel_z_integrator > 0.0) && (rtDW->accel_target[2] < 0.0)) ||
      ((rtDW->pid_accel_z_integrator < 0.0) && (rtDW->accel_target[2] > 0.0))) {
    if (rtDW->POSCONTROL_ACC_Z_I != 0.0) {
      rtDW->pid_accel_z_integrator += rtDW->pid_accel_z_input *
        rtDW->POSCONTROL_ACC_Z_I * rtDW->dt;
      if (rtDW->pid_accel_z_integrator < -rtDW->POSCONTROL_ACC_Z_IMAX) {
        rtDW->pid_accel_z_integrator = -rtDW->POSCONTROL_ACC_Z_IMAX;
      } else {
        if (rtDW->pid_accel_z_integrator > rtDW->POSCONTROL_ACC_Z_IMAX) {
          rtDW->pid_accel_z_integrator = rtDW->POSCONTROL_ACC_Z_IMAX;
        }
      }

      alpha = rtDW->pid_accel_z_integrator;
    } else {
      alpha = 0.0;
    }
  }

  alpha = ((rtDW->POSCONTROL_ACC_Z_P * rtDW->pid_accel_z_input + alpha) +
           rtDW->POSCONTROL_ACC_Z_D * rtDW->pid_accel_z_derivative) * 0.001 +
    rtDW->throttle_hover;
  amt = alpha;
  if (alpha < rtDW->thr_out_min) {
    alpha = rtDW->thr_out_min;
  }

  if (amt > 1.0) {
    alpha = 1.0;
  }

  set_throttle_out(alpha, 1.0, rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ, rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T get_weathervane_yaw_rate_cds(DW *rtDW)
{
  real_T weathervane_yaw_rate_cds;
  real_T b_roll;
  real_T output;
  b_roll = rtDW->roll_target / 100.0;
  if (fabs(b_roll) < rtDW->weathervane_min_roll) {
    rtDW->weathervane_last_output = 0.0;
    weathervane_yaw_rate_cds = 0.0;
  } else {
    if (b_roll > 0.0) {
      b_roll -= rtDW->weathervane_min_roll;
    } else {
      b_roll += rtDW->weathervane_min_roll;
    }

    b_roll = b_roll / 45.0 * rtDW->weathervane_gain;
    output = b_roll;
    if (b_roll < -1.0) {
      output = -1.0;
    }

    if (b_roll > 1.0) {
      output = 1.0;
    }

    rtDW->weathervane_last_output = 0.98 * rtDW->weathervane_last_output + 0.02 *
      output;
    weathervane_yaw_rate_cds = rtDW->yaw_rate_max / 2.0 *
      rtDW->weathervane_last_output * 100.0;
  }

  return weathervane_yaw_rate_cds;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void run_xy_controller(real_T b_dt, DW *rtDW)
{
  int32_T b_bool;
  real_T vector_length;
  real_T linear_dist;
  real_T error_length;
  real_T b_vector_length;
  int8_T n;
  real_T tmp[2];
  if (rtDW->POSCONTROL_POS_XY_P <= 0.0) {
    rtDW->vel_target[0] = 0.0;
    rtDW->vel_target[1] = 0.0;
  } else {
    rtDW->pos_error[0] = rtDW->pos_target[0] - rtDW->curr_pos[0];
    rtDW->pos_error[1] = rtDW->pos_target[1] - rtDW->curr_pos[1];
    linear_dist = rtDW->pos_error[1];
    error_length = rtDW->pos_error[0];
    tmp[0] = rtDW->pos_error[0];
    tmp[1] = rtDW->pos_error[1];
    vector_length = norm(tmp);
    b_bool = 0;
    if ((vector_length > rtDW->leash) && (vector_length > 0.0)) {
      linear_dist = rtDW->leash / vector_length;
      error_length = linear_dist * rtDW->pos_error[0];
      linear_dist *= rtDW->pos_error[1];
      b_bool = 1;
    }

    rtDW->pos_error[0] = error_length;
    rtDW->pos_error[1] = linear_dist;
    if (b_bool != 0) {
      rtDW->pos_target[0] = rtDW->curr_pos[0] + rtDW->pos_error[0];
      rtDW->pos_target[1] = rtDW->curr_pos[1] + rtDW->pos_error[1];
    }

    if ((rtDW->POSCONTROL_ACCEL_XY < 0.0) || (rtDW->POSCONTROL_ACCEL_XY == 0.0) ||
        (rtDW->POSCONTROL_POS_XY_P == 0.0)) {
      rtDW->vel_target[0] = rtDW->pos_error[0] * rtDW->POSCONTROL_POS_XY_P;
      rtDW->vel_target[1] = rtDW->pos_error[1] * rtDW->POSCONTROL_POS_XY_P;
      rtDW->vel_target[2] = rtDW->pos_error[2];
    } else {
      linear_dist = rtDW->POSCONTROL_ACCEL_XY / rtDW->POSCONTROL_POS_XY_P /
        rtDW->POSCONTROL_POS_XY_P;
      tmp[0] = rtDW->pos_error[0];
      tmp[1] = rtDW->pos_error[1];
      error_length = norm(tmp);
      if (error_length > linear_dist) {
        linear_dist = sqrt((error_length - linear_dist * 0.5) * (2.0 *
          rtDW->POSCONTROL_ACCEL_XY)) / error_length;
        rtDW->vel_target[0] = rtDW->pos_error[0] * linear_dist;
        rtDW->vel_target[1] = rtDW->pos_error[1] * linear_dist;
        rtDW->vel_target[2] = rtDW->pos_error[2];
      } else {
        rtDW->vel_target[0] = rtDW->pos_error[0] * rtDW->POSCONTROL_POS_XY_P;
        rtDW->vel_target[1] = rtDW->pos_error[1] * rtDW->POSCONTROL_POS_XY_P;
        rtDW->vel_target[2] = rtDW->pos_error[2];
      }
    }
  }

  rtDW->vel_target[0] += rtDW->vel_desired[0];
  rtDW->vel_target[1] += rtDW->vel_desired[1];
  rtDW->vel_error[0] = rtDW->vel_target[0] - rtDW->curr_vel[0];
  rtDW->vel_error[1] = rtDW->vel_target[1] - rtDW->curr_vel[1];
  if (rtDW->POSCONTROL_VEL_XY_FILT_HZ == 0.0) {
    linear_dist = 1.0;
  } else {
    linear_dist = b_dt / (1.0 / (6.2831853071795862 *
      rtDW->POSCONTROL_VEL_XY_FILT_HZ) + b_dt);
  }

  if (rtDW->POSCONTROL_VEL_XY_FILT_D_HZ == 0.0) {
    error_length = 1.0;
  } else {
    error_length = b_dt / (1.0 / (6.2831853071795862 *
      rtDW->POSCONTROL_VEL_XY_FILT_D_HZ) + b_dt);
  }

  if (rtDW->pid_vel_xy_reset_filter == 1.0) {
    rtDW->pid_vel_xy_reset_filter = 0.0;
    rtDW->pid_vel_xy_derivative[0] = 0.0;
    rtDW->pid_vel_xy_integrator[0] = 0.0;
    rtDW->pid_vel_xy_input[0] = rtDW->vel_error[0];
    rtDW->pid_vel_xy_derivative[1] = 0.0;
    rtDW->pid_vel_xy_integrator[1] = 0.0;
    rtDW->pid_vel_xy_input[1] = rtDW->vel_error[1];
  }

  vector_length = (rtDW->vel_error[0] - rtDW->pid_vel_xy_input[0]) * linear_dist;
  rtDW->pid_vel_xy_input[0] += vector_length;
  rtDW->pid_vel_xy_derivative[0] += (vector_length / b_dt -
    rtDW->pid_vel_xy_derivative[0]) * error_length;
  vector_length = (rtDW->vel_error[1] - rtDW->pid_vel_xy_input[1]) * linear_dist;
  rtDW->pid_vel_xy_input[1] += vector_length;
  rtDW->pid_vel_xy_derivative[1] += (vector_length / b_dt -
    rtDW->pid_vel_xy_derivative[1]) * error_length;
  if ((!(rtDW->limit_accel_xy != 0.0)) && (!(rtDW->motors_limit_throttle_upper
        != 0.0))) {
    rtDW->pid_vel_xy_integrator[0] += rtDW->pid_vel_xy_input[0] *
      rtDW->POSCONTROL_VEL_XY_I * b_dt;
    rtDW->pid_vel_xy_integrator[1] += rtDW->pid_vel_xy_input[1] *
      rtDW->POSCONTROL_VEL_XY_I * b_dt;
    linear_dist = norm(rtDW->pid_vel_xy_integrator);
    if ((linear_dist > rtDW->POSCONTROL_VEL_XY_IMAX) && (linear_dist > 0.0)) {
      rtDW->pid_vel_xy_integrator[0] = rtDW->pid_vel_xy_integrator[0] *
        rtDW->POSCONTROL_VEL_XY_IMAX / linear_dist;
      rtDW->pid_vel_xy_integrator[1] = rtDW->pid_vel_xy_integrator[1] *
        rtDW->POSCONTROL_VEL_XY_IMAX / linear_dist;
    }
  } else {
    linear_dist = fmin(norm(rtDW->pid_vel_xy_integrator),
                       rtDW->POSCONTROL_VEL_XY_IMAX);
    rtDW->pid_vel_xy_integrator[0] += rtDW->pid_vel_xy_input[0] *
      rtDW->POSCONTROL_VEL_XY_I * b_dt;
    rtDW->pid_vel_xy_integrator[1] += rtDW->pid_vel_xy_input[1] *
      rtDW->POSCONTROL_VEL_XY_I * b_dt;
    error_length = norm(rtDW->pid_vel_xy_integrator);
    if ((error_length > linear_dist) && (error_length > 0.0)) {
      linear_dist /= error_length;
      rtDW->pid_vel_xy_integrator[0] *= linear_dist;
      rtDW->pid_vel_xy_integrator[1] *= linear_dist;
    }
  }

  error_length = (rtDW->POSCONTROL_VEL_XY_P * rtDW->pid_vel_xy_input[0] +
                  rtDW->pid_vel_xy_integrator[0]) + rtDW->POSCONTROL_VEL_XY_D *
    rtDW->pid_vel_xy_derivative[0];
  vector_length = (rtDW->POSCONTROL_VEL_XY_P * rtDW->pid_vel_xy_input[1] +
                   rtDW->pid_vel_xy_integrator[1]) + rtDW->POSCONTROL_VEL_XY_D *
    rtDW->pid_vel_xy_derivative[1];
  if (rtDW->reset_accel_to_lean_xy == 1.0) {
    rtDW->accel_xy_input[0] = error_length;
    rtDW->accel_xy_input[1] = vector_length;
    rtDW->reset_accel_to_lean_xy = 0.0;
  }

  if (rtDW->POSCONTROL_ACCEL_FILTER_HZ <= 0.0) {
    rtDW->accel_xy_input[0] = error_length;
    rtDW->accel_xy_input[1] = vector_length;
  } else {
    linear_dist = b_dt / (1.0 / (6.2831853071795862 *
      rtDW->POSCONTROL_ACCEL_FILTER_HZ) + b_dt);
    rtDW->accel_xy_input[0] += (error_length - rtDW->accel_xy_input[0]) *
      linear_dist;
    rtDW->accel_xy_input[1] += (vector_length - rtDW->accel_xy_input[1]) *
      linear_dist;
  }

  rtDW->accel_target[0] = rtDW->accel_xy_input[0] + rtDW->accel_desired[0];
  rtDW->accel_target[1] = rtDW->accel_xy_input[1] + rtDW->accel_desired[1];
  linear_dist = rtDW->accel_xy_angle_max * 0.01;
  if (rtIsInf(linear_dist) || rtIsNaN(linear_dist)) {
    linear_dist = (rtNaN);
  } else {
    linear_dist = rt_remd_snf(linear_dist, 360.0);
    error_length = fabs(linear_dist);
    if (error_length > 180.0) {
      if (linear_dist > 0.0) {
        linear_dist -= 360.0;
      } else {
        linear_dist += 360.0;
      }

      error_length = fabs(linear_dist);
    }

    if (error_length <= 45.0) {
      linear_dist *= 0.017453292519943295;
      n = 0;
    } else if (error_length <= 135.0) {
      if (linear_dist > 0.0) {
        linear_dist = (linear_dist - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        linear_dist = (linear_dist + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (linear_dist > 0.0) {
      linear_dist = (linear_dist - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      linear_dist = (linear_dist + 180.0) * 0.017453292519943295;
      n = -2;
    }

    linear_dist = tan(linear_dist);
    if ((n == 1) || (n == -1)) {
      error_length = 1.0 / linear_dist;
      linear_dist = -(1.0 / linear_dist);
      if (rtIsInf(linear_dist) && (n == 1)) {
        linear_dist = error_length;
      }
    }
  }

  linear_dist = fmin(rtDW->GRAVITY_MSS * 100.0 * linear_dist,
                     rtDW->POSCONTROL_ACCEL_XY_MAX);
  error_length = rtDW->accel_target[1];
  vector_length = rtDW->accel_target[0];
  tmp[0] = rtDW->accel_target[0];
  tmp[1] = rtDW->accel_target[1];
  b_vector_length = norm(tmp);
  b_bool = 0;
  if ((b_vector_length > linear_dist) && (b_vector_length > 0.0)) {
    linear_dist /= b_vector_length;
    vector_length = linear_dist * rtDW->accel_target[0];
    error_length = linear_dist * rtDW->accel_target[1];
    b_bool = 1;
  }

  rtDW->limit_accel_xy = b_bool;
  rtDW->accel_target[0] = vector_length;
  rtDW->accel_target[1] = error_length;
  linear_dist = sin(rtDW->yaw);
  error_length = cos(rtDW->yaw);
  vector_length = atan(-(rtDW->accel_target[0] * error_length +
    rtDW->accel_target[1] * linear_dist) / (rtDW->GRAVITY_MSS * 100.0)) *
    5729.5779513082325;
  rtDW->roll_target = atan((-rtDW->accel_target[0] * linear_dist +
    rtDW->accel_target[1] * error_length) * cos(vector_length *
    3.1415926535897931 / 18000.0) / (rtDW->GRAVITY_MSS * 100.0)) *
    5729.5779513082325;
  rtDW->pitch_target = vector_length;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_vel_controller_xy(DW *rtDW)
{
  real_T accel_cms;
  if (rtDW->recalc_leash_xy != 0.0) {
    accel_cms = rtDW->POSCONTROL_ACCEL_XY;
    if (rtDW->POSCONTROL_ACCEL_XY <= 0.0) {
      accel_cms = rtDW->POSCONTROL_ACCELERATION_MIN;
    }

    if (rtDW->POSCONTROL_POS_XY_P <= 0.0) {
      rtDW->leash = rtDW->POSCONTROL_LEASH_LENGTH_MIN;
    } else {
      if (rtDW->POSCONTROL_SPEED <= accel_cms / rtDW->POSCONTROL_POS_XY_P) {
        rtDW->leash = rtDW->POSCONTROL_SPEED / rtDW->POSCONTROL_POS_XY_P;
      } else {
        rtDW->leash = accel_cms / (2.0 * rtDW->POSCONTROL_POS_XY_P *
          rtDW->POSCONTROL_POS_XY_P) + rtDW->POSCONTROL_SPEED *
          rtDW->POSCONTROL_SPEED / (2.0 * accel_cms);
      }

      if (rtDW->leash < rtDW->POSCONTROL_LEASH_LENGTH_MIN) {
        rtDW->leash = rtDW->POSCONTROL_LEASH_LENGTH_MIN;
      }
    }

    rtDW->recalc_leash_xy = 0.0;
  }

  if (!(rtDW->dt < 0.0)) {
    if (rtDW->reset_desired_vel_to_pos != 0.0) {
      rtDW->reset_desired_vel_to_pos = 0.0;
    } else {
      rtDW->pos_target[0] += rtDW->vel_desired[0] * rtDW->dt;
      rtDW->pos_target[1] += rtDW->vel_desired[1] * rtDW->dt;
    }
  }

  run_xy_controller(rtDW->dt, rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void calc_nav_roll(DW *rtDW)
{
  real_T commanded_roll;
  real_T amt;
  commanded_roll = atan(rtDW->latAccDem * 0.101972) * cos(rtDW->pitch) * 100.0 *
    rtDW->HD;
  amt = commanded_roll;
  if (commanded_roll < -9000.0) {
    commanded_roll = -9000.0;
  }

  if (amt > 9000.0) {
    commanded_roll = 9000.0;
  }

  rtDW->nav_roll_cd = commanded_roll;
  if (commanded_roll < -rtDW->roll_limit_cd) {
    rtDW->nav_roll_cd = -rtDW->roll_limit_cd;
  }

  if (commanded_roll > rtDW->roll_limit_cd) {
    rtDW->nav_roll_cd = rtDW->roll_limit_cd;
  }

  commanded_roll = fabs(rtDW->nav_roll_cd * 0.01);
  if (commanded_roll > 85.0) {
    commanded_roll = 85.0;
  }

  rtDW->aerodynamic_load_factor = 1.0 / sqrt(cos(commanded_roll / 180.0 *
    3.1415926535897931));
  rtDW->smoothed_airspeed = rtDW->smoothed_airspeed * 0.8 + rtDW->aspeed * 0.2;
  commanded_roll = rtDW->smoothed_airspeed / fmax(rtDW->airspeed_min, 1.0);
  if (commanded_roll <= 1.0) {
    rtDW->roll_limit_cd = 2500.0;
  } else if (commanded_roll < rtDW->aerodynamic_load_factor) {
    commanded_roll = 1.0 / commanded_roll;
    commanded_roll = acos(commanded_roll * commanded_roll) * 100.0 * rtDW->HD;
    if (commanded_roll < 2500.0) {
      commanded_roll = 2500.0;
    }

    amt = rtDW->nav_roll_cd;
    if (rtDW->nav_roll_cd < -commanded_roll) {
      rtDW->nav_roll_cd = -commanded_roll;
    }

    if (amt > commanded_roll) {
      rtDW->nav_roll_cd = commanded_roll;
    }

    rtDW->roll_limit_cd = commanded_roll;
  } else {
    commanded_roll = rtDW->nav_roll_cd;
    if (rtDW->nav_roll_cd < -rtDW->roll_limit_cd_inint) {
      rtDW->nav_roll_cd = -rtDW->roll_limit_cd_inint;
    }

    if (commanded_roll > rtDW->roll_limit_cd_inint) {
      rtDW->nav_roll_cd = rtDW->roll_limit_cd_inint;
    }

    rtDW->roll_limit_cd = rtDW->roll_limit_cd_inint;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void stabilize(DW *rtDW)
{
  real_T speed_scaler;
  real_T scale_min;
  real_T scale_max;
  int32_T inverted;
  real_T ki_rate;
  real_T rate_error;
  real_T k_I;
  real_T ki_rate_tmp;
  if (rtDW->aspeed > rtDW->highest_airspeed) {
    rtDW->highest_airspeed = rtDW->aspeed;
  }

  if (rtDW->aspeed > 0.0001) {
    speed_scaler = rtDW->scaling_speed / rtDW->aspeed;
  } else {
    speed_scaler = 2.0;
  }

  scale_min = fmin(0.5, 0.5 * rtDW->airspeed_min / rtDW->scaling_speed);
  scale_max = fmax(2.0, 1.5 * rtDW->airspeed_max / rtDW->scaling_speed);
  rate_error = speed_scaler;
  if (speed_scaler < scale_min) {
    speed_scaler = scale_min;
  }

  if (rate_error > scale_max) {
    speed_scaler = scale_max;
  }

  if (rtDW->inverted_flight != 0.0) {
    rtDW->nav_roll_cd += 18000.0;
    if (rtDW->roll < 0.0) {
      rtDW->nav_roll_cd -= 36000.0;
    }
  }

  if (rtDW->gains_tau_roll < 0.1) {
    rtDW->gains_tau_roll = 0.1;
  }

  scale_min = (rtDW->nav_roll_cd - rtDW->roll * rtDW->HD * 100.0) * 0.01 /
    rtDW->gains_tau_roll;
  rtDW->desired_rate_roll = scale_min;
  ki_rate_tmp = rtDW->gains_I_roll * rtDW->gains_tau_roll;
  if ((rtDW->gains_rmax_roll != 0.0) && (scale_min < -rtDW->gains_rmax_roll)) {
    scale_min = -rtDW->gains_rmax_roll;
  } else {
    if ((rtDW->gains_rmax_roll != 0.0) && (scale_min > rtDW->gains_rmax_roll)) {
      scale_min = rtDW->gains_rmax_roll;
    }
  }

  scale_max = rtDW->gyro_x * rtDW->HD;
  rate_error = (scale_min - scale_max) * speed_scaler;
  if ((!(rtDW->disable_integrator_roll != 0.0)) && (ki_rate_tmp > 0.0)) {
    if ((rtDW->dt > 0.0) && (rtDW->aspeed > rtDW->airspeed_min)) {
      ki_rate = rate_error * ki_rate_tmp * rtDW->dt * speed_scaler;
      if (rtDW->last_out_roll < -45.0) {
        ki_rate = fmax(ki_rate, 0.0);
      } else {
        if (rtDW->last_out_roll > 45.0) {
          ki_rate = fmin(ki_rate, 0.0);
        }
      }

      rtDW->pid_info_I_roll += ki_rate;
    }
  } else {
    rtDW->pid_info_I_roll = 0.0;
  }

  ki_rate = rtDW->gains_imax_roll * 0.01;
  k_I = rtDW->pid_info_I_roll;
  if (rtDW->pid_info_I_roll < -ki_rate) {
    rtDW->pid_info_I_roll = -ki_rate;
  }

  if (k_I > ki_rate) {
    rtDW->pid_info_I_roll = ki_rate;
  }

  rtDW->pid_info_D_roll = rate_error * rtDW->gains_D_roll * speed_scaler;
  rtDW->pid_info_P_roll = fmax((rtDW->gains_P_roll - ki_rate_tmp) *
    rtDW->gains_tau_roll - rtDW->gains_D_roll, 0.0) / rtDW->EAS2TAS * scale_min *
    speed_scaler;
  rtDW->pid_info_FF_roll = rtDW->gains_FF_roll / rtDW->EAS2TAS * scale_min *
    speed_scaler;
  rtDW->pid_info_desired_roll = scale_min;
  rtDW->pid_info_actual_roll = scale_max;
  rtDW->last_out_roll = (rtDW->pid_info_FF_roll + rtDW->pid_info_P_roll) +
    rtDW->pid_info_D_roll;
  rtDW->last_out_roll += rtDW->pid_info_I_roll;
  scale_min = rtDW->last_out_roll * 100.0;
  rtDW->k_aileron = scale_min;
  if (scale_min < -4500.0) {
    rtDW->k_aileron = -4500.0;
  }

  if (scale_min > 4500.0) {
    rtDW->k_aileron = 4500.0;
  }

  if (rtDW->gains_tau_pitch < 0.1) {
    rtDW->gains_tau_pitch = 0.1;
  }

  scale_min = fabs(rtDW->roll);
  if (scale_min < 1.5707963267948966) {
    scale_max = rtDW->roll;
    if (rtDW->roll < -1.3962634015954636) {
      scale_max = -1.3962634015954636;
    }

    if (rtDW->roll > 1.3962634015954636) {
      scale_max = 1.3962634015954636;
    }

    inverted = 0;
  } else {
    inverted = 1;
    if (rtDW->roll > 0.0) {
      scale_max = rtDW->roll;
      if (rtDW->roll < 1.7453292519943295) {
        scale_max = 1.7453292519943295;
      }

      if (rtDW->roll > 3.1415926535897931) {
        scale_max = 3.1415926535897931;
      }
    } else {
      scale_max = rtDW->roll;
      if (rtDW->roll < -3.1415926535897931) {
        scale_max = -3.1415926535897931;
      }

      if (rtDW->roll > -1.7453292519943295) {
        scale_max = -1.7453292519943295;
      }
    }
  }

  ki_rate = rtDW->pitch * rtDW->HD * 100.0;
  if (fabs(ki_rate) > 7000.0) {
    rate_error = 0.0;
  } else {
    rate_error = fabs(rtDW->GRAVITY_MSS / fmax(rtDW->aspeed * rtDW->EAS2TAS,
      rtDW->airspeed_min * rtDW->EAS2TAS) * tan(scale_max) * sin(scale_max) *
                      rtDW->HD) * cos(rtDW->pitch) * rtDW->roll_ff_pitch;
  }

  if (inverted != 0) {
    rate_error = -rate_error;
  }

  scale_max = ((rtDW->k_throttle * rtDW->kff_throttle_to_pitch +
                rtDW->nav_pitch_cd) - ki_rate) * 0.01 / rtDW->gains_tau_pitch;
  if (inverted == 0) {
    if ((rtDW->max_rate_neg != 0.0) && (scale_max < -rtDW->max_rate_neg)) {
      scale_max = -rtDW->max_rate_neg;
    } else {
      if ((rtDW->gains_rmax_pitch != 0.0) && (scale_max > rtDW->gains_rmax_pitch))
      {
        scale_max = rtDW->gains_rmax_pitch;
      }
    }
  } else {
    scale_max = -scale_max;
  }

  scale_max += rate_error;
  rtDW->desired_rate_pitch = scale_max;
  rate_error = rtDW->gyro_y * rtDW->HD;
  ki_rate = (scale_max - rate_error) * speed_scaler;
  if ((!(rtDW->disable_integrator_pitch != 0.0)) && (rtDW->gains_I_pitch > 0.0))
  {
    k_I = rtDW->gains_I_pitch;
    if (rtDW->gains_FF_pitch == 0.0) {
      k_I = fmax(rtDW->gains_I_pitch, 0.15);
    }

    if ((rtDW->dt > 0.0) && (rtDW->aspeed > 0.5 * rtDW->airspeed_min)) {
      k_I = k_I * rtDW->gains_tau_pitch * ki_rate * rtDW->dt * speed_scaler;
      if (rtDW->last_out_pitch < -45.0) {
        k_I = fmax(k_I, 0.0);
      } else {
        if (rtDW->last_out_pitch > 45.0) {
          k_I = fmin(k_I, 0.0);
        }
      }

      rtDW->pid_info_I_pitch += k_I;
    }
  } else {
    rtDW->pid_info_I_pitch = 0.0;
  }

  k_I = rtDW->gains_imax_pitch * 0.01;
  ki_rate_tmp = rtDW->pid_info_I_pitch;
  if (rtDW->pid_info_I_pitch < -k_I) {
    rtDW->pid_info_I_pitch = -k_I;
  }

  if (ki_rate_tmp > k_I) {
    rtDW->pid_info_I_pitch = k_I;
  }

  rtDW->pid_info_P_pitch = fmax((rtDW->gains_P_pitch - rtDW->gains_I_pitch *
    rtDW->gains_tau_pitch) * rtDW->gains_tau_pitch - rtDW->gains_D_pitch, 0.0) /
    rtDW->EAS2TAS * scale_max * speed_scaler;
  rtDW->pid_info_FF_pitch = rtDW->gains_FF_pitch / rtDW->EAS2TAS * scale_max *
    speed_scaler;
  rtDW->pid_info_D_pitch = ki_rate * rtDW->gains_D_pitch * speed_scaler;
  rtDW->last_out_pitch = (rtDW->pid_info_D_pitch + rtDW->pid_info_FF_pitch) +
    rtDW->pid_info_P_pitch;
  rtDW->pid_info_desired_pitch = scale_max;
  rtDW->pid_info_actual_pitch = rate_error;
  rtDW->last_out_pitch += rtDW->pid_info_I_pitch;
  scale_max = scale_min;
  if (scale_min > 9000.0) {
    scale_max = 18000.0 - scale_min;
  }

  if ((scale_max > rtDW->roll_limit_cd + 500.0) && (rtDW->roll_limit_cd < 8500.0)
      && (fabs(rtDW->pitch) < 7000.0)) {
    rtDW->last_out_pitch *= 1.0 - (scale_max - (rtDW->roll_limit_cd + 500.0)) /
      (9000.0 - rtDW->roll_limit_cd);
  }

  scale_max = rtDW->last_out_pitch * 100.0;
  rtDW->k_elevator = scale_max;
  if (scale_max < -4500.0) {
    rtDW->k_elevator = -4500.0;
  }

  if (scale_max > 4500.0) {
    rtDW->k_elevator = 4500.0;
  }

  scale_max = rtDW->airspeed_min;
  if (rtDW->airspeed_min < 1.0) {
    scale_max = 1.0;
  }

  rate_error = rtDW->roll;
  if (scale_min < 1.5707964) {
    if (rtDW->roll < -1.3962634) {
      rate_error = -1.3962634;
    }

    if (rtDW->roll > 1.3962634) {
      rate_error = 1.3962634;
    }
  }

  rate_error = (rtDW->gyro_z - rtDW->GRAVITY_MSS / fmax(rtDW->aspeed *
    rtDW->EAS2TAS, scale_max * rtDW->EAS2TAS) * sin(rate_error) * rtDW->K_FF_yaw)
    * rtDW->HD;
  scale_min = ((1.0 - 0.2 * rtDW->dt) * rtDW->last_rate_hp_out_yaw + rate_error)
    - rtDW->last_rate_hp_in_yaw;
  rtDW->last_rate_hp_out_yaw = scale_min;
  rtDW->last_rate_hp_in_yaw = rate_error;
  rate_error = (rtDW->K_A_yaw * rtDW->accel_y + scale_min) * -rtDW->K_I_yaw;
  if ((!(rtDW->disable_integrator_yaw != 0.0)) && (rtDW->K_D_yaw > 0.0)) {
    if (rtDW->aspeed > scale_max) {
      if (rtDW->last_out_yaw < -45.0) {
        rtDW->integrator_yaw += fmax(rate_error * rtDW->dt, 0.0);
      } else if (rtDW->last_out_yaw > 45.0) {
        rtDW->integrator_yaw += fmin(rate_error * rtDW->dt, 0.0);
      } else {
        rtDW->integrator_yaw += rate_error * rtDW->dt;
      }
    }
  } else {
    rtDW->integrator_yaw = 0.0;
  }

  if (rtDW->K_D_yaw < 0.0001) {
    scale_min = 0.0;
  } else {
    scale_max = rtDW->imax_yaw * 0.01 / (rtDW->K_D_yaw * speed_scaler *
      speed_scaler);
    rate_error = rtDW->integrator_yaw;
    if (rtDW->integrator_yaw < -scale_max) {
      rtDW->integrator_yaw = -scale_max;
    }

    if (rate_error > scale_max) {
      rtDW->integrator_yaw = scale_max;
    }

    if ((rtDW->K_D_yaw > rtDW->K_D_last_yaw) && (rtDW->K_D_yaw > 0.0)) {
      rtDW->integrator_yaw *= rtDW->K_D_last_yaw / rtDW->K_D_yaw;
    }

    rtDW->K_D_last_yaw = rtDW->K_D_yaw;
    rtDW->pid_info_I_yaw = rtDW->K_D_yaw * rtDW->integrator_yaw * speed_scaler *
      speed_scaler;
    rtDW->pid_info_D_yaw = rtDW->K_D_yaw * -scale_min * speed_scaler *
      speed_scaler;
    rtDW->last_out_yaw = rtDW->pid_info_I_yaw + rtDW->pid_info_D_yaw;
    speed_scaler = rtDW->last_out_yaw * 100.0;
    scale_min = speed_scaler;
    if (speed_scaler < -4500.0) {
      scale_min = -4500.0;
    }

    if (speed_scaler > 4500.0) {
      scale_min = 4500.0;
    }
  }

  scale_min += rtDW->k_aileron * rtDW->kff_rudder_mix;
  rtDW->k_rudder = scale_min;
  if (scale_min < -4500.0) {
    rtDW->k_rudder = -4500.0;
  }

  if (scale_min > 4500.0) {
    rtDW->k_rudder = 4500.0;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void output_to_motors_plane_4a1(DW *rtDW)
{
  real_T thrust_dt;
  real_T pwm_out_temp;
  real_T low;
  real_T high;
  pwm_out_temp = rtDW->pwm_max - rtDW->pwm_min;
  thrust_dt = pwm_out_temp * rtDW->dt / rtDW->thrust_slew_time;
  pwm_out_temp = pwm_out_temp * rtDW->k_throttle + rtDW->pwm_min;
  low = rtDW->pwm_tail - thrust_dt;
  high = rtDW->pwm_tail + thrust_dt;
  rtDW->pwm_tail = pwm_out_temp;
  if (pwm_out_temp < low) {
    rtDW->pwm_tail = low;
  }

  if (pwm_out_temp > high) {
    rtDW->pwm_tail = high;
  }

  pwm_out_temp = rtDW->pwm_tail;
  if (rtDW->pwm_tail < rtDW->pwm_min) {
    rtDW->pwm_tail = rtDW->pwm_min;
  }

  if (pwm_out_temp > rtDW->pwm_max) {
    rtDW->pwm_tail = rtDW->pwm_max;
  }

  pwm_out_temp = rtDW->pwm_out[0] - thrust_dt;
  low = rtDW->pwm_out[0] + thrust_dt;
  rtDW->pwm_out[0] = rtDW->pwm_min;
  if (rtDW->pwm_min < pwm_out_temp) {
    rtDW->pwm_out[0] = pwm_out_temp;
  }

  if (rtDW->pwm_min > low) {
    rtDW->pwm_out[0] = low;
  }

  pwm_out_temp = rtDW->pwm_out[0];
  if (rtDW->pwm_out[0] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[0] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[0] = pwm_out_temp;
  pwm_out_temp = rtDW->pwm_out[1] - thrust_dt;
  low = rtDW->pwm_out[1] + thrust_dt;
  rtDW->pwm_out[1] = rtDW->pwm_min;
  if (rtDW->pwm_min < pwm_out_temp) {
    rtDW->pwm_out[1] = pwm_out_temp;
  }

  if (rtDW->pwm_min > low) {
    rtDW->pwm_out[1] = low;
  }

  pwm_out_temp = rtDW->pwm_out[1];
  if (rtDW->pwm_out[1] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[1] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[1] = pwm_out_temp;
  pwm_out_temp = rtDW->pwm_out[2] - thrust_dt;
  low = rtDW->pwm_out[2] + thrust_dt;
  rtDW->pwm_out[2] = rtDW->pwm_min;
  if (rtDW->pwm_min < pwm_out_temp) {
    rtDW->pwm_out[2] = pwm_out_temp;
  }

  if (rtDW->pwm_min > low) {
    rtDW->pwm_out[2] = low;
  }

  pwm_out_temp = rtDW->pwm_out[2];
  if (rtDW->pwm_out[2] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[2] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[2] = pwm_out_temp;
  pwm_out_temp = rtDW->pwm_out[3] - thrust_dt;
  low = rtDW->pwm_out[3] + thrust_dt;
  rtDW->pwm_out[3] = rtDW->pwm_min;
  if (rtDW->pwm_min < pwm_out_temp) {
    rtDW->pwm_out[3] = pwm_out_temp;
  }

  if (rtDW->pwm_min > low) {
    rtDW->pwm_out[3] = low;
  }

  pwm_out_temp = rtDW->pwm_out[3];
  if (rtDW->pwm_out[3] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[3] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[3] = pwm_out_temp;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_50hz(DW *rtDW)
{
  rtDW->climb_rate = -rtDW->Vz;
  rtDW->vdot_filter[4] = rtDW->vdot_filter[3];
  rtDW->vdot_filter[3] = rtDW->vdot_filter[2];
  rtDW->vdot_filter[2] = rtDW->vdot_filter[1];
  rtDW->vdot_filter[1] = rtDW->vdot_filter[0];
  rtDW->vdot_filter[0] = rtDW->rot_body_to_ned[2] * rtDW->GRAVITY_MSS +
    rtDW->accel_x;
  rtDW->vel_dot = ((((rtDW->vdot_filter[0] + rtDW->vdot_filter[1]) +
                     rtDW->vdot_filter[2]) + rtDW->vdot_filter[3]) +
                   rtDW->vdot_filter[4]) / 5.0;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_speed(real_T load_factor, DW *rtDW)
{
  real_T integDTAS_input;
  real_T integDTAS_input_tmp;
  rtDW->TAS_dem = rtDW->EAS_dem * rtDW->EAS2TAS;
  rtDW->TASmax = rtDW->airspeed_max * rtDW->EAS2TAS;
  rtDW->TASmin = rtDW->airspeed_min * rtDW->EAS2TAS;
  rtDW->TASmin *= load_factor;
  if (rtDW->TASmax < rtDW->TASmin) {
    rtDW->TASmax = rtDW->TASmin;
  }

  if (rtDW->TASmin > rtDW->TAS_dem) {
    rtDW->TASmin = rtDW->TAS_dem;
  }

  integDTAS_input_tmp = (rtDW->aspeed * rtDW->EAS2TAS - rtDW->TAS_state) *
    rtDW->spdCompFiltOmega;
  integDTAS_input = integDTAS_input_tmp * rtDW->spdCompFiltOmega;
  if (rtDW->TAS_state < 3.1) {
    integDTAS_input = fmax(integDTAS_input, 0.0);
  }

  rtDW->integDTAS_state += integDTAS_input * rtDW->dt;
  rtDW->TAS_state += (integDTAS_input_tmp * 1.4142 + (rtDW->integDTAS_state +
    rtDW->vel_dot)) * rtDW->dt;
  rtDW->TAS_state = fmax(rtDW->TAS_state, 3.0);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_pitch_throttle(real_T b_hgt_dem_cm, real_T b_EAS_dem_cm,
  real_T load_factor, DW *rtDW)
{
  real_T velRateMax;
  real_T velRateMin;
  real_T STEdot_error;
  real_T cosPhi;
  real_T thrRateIncr;
  real_T integSEB_range;
  real_T velRateMax_tmp;
  real_T velRateMax_tmp_0;
  real_T velRateMin_tmp;
  real_T STEdot_error_tmp;
  rtDW->hgt_dem = b_hgt_dem_cm * 0.01;
  rtDW->EAS_dem = b_EAS_dem_cm * 0.01;
  update_speed(load_factor, rtDW);
  rtDW->THRmaxf = rtDW->throttle_max * 0.01;
  rtDW->THRminf = rtDW->throttle_min * 0.01;
  if (rtDW->pitch_max <= 0.0) {
    rtDW->PITCHmaxf = rtDW->pitch_limit_max_cd * 0.01;
  } else {
    rtDW->PITCHmaxf = fmin(rtDW->pitch_max, rtDW->pitch_limit_max_cd * 0.01);
  }

  if (rtDW->pitch_min >= 0.0) {
    rtDW->PITCHminf = rtDW->pitch_limit_min_cd * 0.01;
  } else {
    rtDW->PITCHminf = fmax(rtDW->pitch_min, rtDW->pitch_limit_min_cd * 0.01);
  }

  if (rtDW->pitch_max_limit < 90.0) {
    velRateMax = rtDW->PITCHmaxf;
    if (rtDW->PITCHmaxf < -90.0) {
      rtDW->PITCHmaxf = -90.0;
    }

    if (velRateMax > rtDW->pitch_max_limit) {
      rtDW->PITCHmaxf = rtDW->pitch_max_limit;
    }

    velRateMax = rtDW->PITCHminf;
    if (rtDW->PITCHminf < -rtDW->pitch_max_limit) {
      rtDW->PITCHminf = -rtDW->pitch_max_limit;
    }

    if (velRateMax > rtDW->PITCHmaxf) {
      rtDW->PITCHminf = rtDW->PITCHmaxf;
    }

    rtDW->pitch_max_limit = 90.0;
  }

  rtDW->PITCHmaxf = rtDW->PITCHmaxf / 180.0 * 3.1415926535897931;
  rtDW->PITCHminf = rtDW->PITCHminf / 180.0 * 3.1415926535897931;
  rtDW->STEdot_max = rtDW->maxClimbRate * rtDW->GRAVITY_MSS;
  rtDW->STEdot_min = -rtDW->minSinkRate * rtDW->GRAVITY_MSS;
  velRateMax = rtDW->TAS_dem;
  if (rtDW->TAS_dem < rtDW->TASmin) {
    rtDW->TAS_dem = rtDW->TASmin;
  }

  if (velRateMax > rtDW->TASmax) {
    rtDW->TAS_dem = rtDW->TASmax;
  }

  velRateMax = 0.5 * rtDW->STEdot_max / rtDW->TAS_state;
  velRateMin = 0.5 * rtDW->STEdot_min / rtDW->TAS_state;
  cosPhi = rtDW->TAS_dem - rtDW->TAS_dem_adj;
  STEdot_error = velRateMax * rtDW->dt;
  if (cosPhi > STEdot_error) {
    rtDW->TAS_dem_adj += STEdot_error;
    rtDW->TAS_rate_dem = velRateMax;
  } else {
    STEdot_error = velRateMin * rtDW->dt;
    if (cosPhi < STEdot_error) {
      rtDW->TAS_dem_adj += STEdot_error;
      rtDW->TAS_rate_dem = velRateMin;
    } else {
      rtDW->TAS_rate_dem = (rtDW->TAS_dem - rtDW->TAS_dem_adj) / rtDW->dt;
      rtDW->TAS_dem_adj = rtDW->TAS_dem;
    }
  }

  velRateMax = rtDW->TAS_dem_adj;
  if (rtDW->TAS_dem_adj < rtDW->TASmin) {
    rtDW->TAS_dem_adj = rtDW->TASmin;
  }

  if (velRateMax > rtDW->TASmax) {
    rtDW->TAS_dem_adj = rtDW->TASmax;
  }

  if (rtDW->inint_hgt != 0.0) {
    rtDW->hgt_dem_in_old = rtDW->hgt_dem;
    rtDW->hgt_dem_prev = rtDW->hgt_dem;
    rtDW->hgt_dem_adj_last = rtDW->hgt_dem;
    rtDW->inint_hgt = 0.0;
  }

  rtDW->hgt_dem = (rtDW->hgt_dem + rtDW->hgt_dem_in_old) * 0.5;
  rtDW->hgt_dem_in_old = rtDW->hgt_dem;
  cosPhi = rtDW->hgt_dem - rtDW->hgt_dem_prev;
  STEdot_error = rtDW->maxClimbRate * rtDW->dt;
  if (cosPhi > STEdot_error) {
    rtDW->hgt_dem = STEdot_error + rtDW->hgt_dem_prev;
  } else {
    if (cosPhi < -rtDW->maxSinkRate * rtDW->dt) {
      rtDW->hgt_dem = rtDW->hgt_dem_prev - rtDW->maxSinkRate * rtDW->dt;
    }
  }

  rtDW->hgt_dem_prev = rtDW->hgt_dem;
  rtDW->hgt_dem_adj = 0.05 * rtDW->hgt_dem + 0.95 * rtDW->hgt_dem_adj_last;
  rtDW->hgt_rate_dem = (rtDW->hgt_dem_adj - rtDW->hgt_dem_adj_last) / rtDW->dt;
  rtDW->hgt_dem_adj_last = rtDW->hgt_dem_adj;
  rtDW->SPE_dem = rtDW->hgt_dem_adj * rtDW->GRAVITY_MSS;
  rtDW->SKE_dem = 0.5 * rtDW->TAS_dem_adj * rtDW->TAS_dem_adj;
  rtDW->SPEdot_dem = rtDW->hgt_rate_dem * rtDW->GRAVITY_MSS;
  rtDW->SKEdot_dem = rtDW->TAS_state * rtDW->TAS_rate_dem;
  rtDW->SPE_est = rtDW->height * rtDW->GRAVITY_MSS;
  rtDW->SKE_est = 0.5 * rtDW->TAS_state * rtDW->TAS_state;
  rtDW->SPEdot = rtDW->climb_rate * rtDW->GRAVITY_MSS;
  rtDW->SKEdot = rtDW->TAS_state * rtDW->vel_dot;
  integSEB_range = 0.5 * rtDW->TASmax * rtDW->TASmax - rtDW->SKE_dem;
  velRateMin_tmp = 0.5 * rtDW->TASmin * rtDW->TASmin - rtDW->SKE_dem;
  STEdot_error_tmp = rtDW->SPE_dem - rtDW->SPE_est;
  cosPhi = STEdot_error_tmp;
  if (STEdot_error_tmp < velRateMin_tmp) {
    cosPhi = velRateMin_tmp;
  }

  if (STEdot_error_tmp > integSEB_range) {
    cosPhi = integSEB_range;
  }

  rtDW->STE_error = (cosPhi + rtDW->SKE_dem) - rtDW->SKE_est;
  velRateMax = rtDW->SPEdot_dem + rtDW->SKEdot_dem;
  velRateMin = velRateMax;
  if (velRateMax < rtDW->STEdot_min) {
    velRateMin = rtDW->STEdot_min;
  }

  if (velRateMax > rtDW->STEdot_max) {
    velRateMin = rtDW->STEdot_max;
  }

  STEdot_error = ((velRateMin - rtDW->SPEdot) - rtDW->SKEdot) * 0.2 + 0.8 *
    rtDW->STEdotErrLast;
  rtDW->STEdotErrLast = STEdot_error;
  velRateMax_tmp = rtDW->STEdot_max - rtDW->STEdot_min;
  velRateMax_tmp_0 = rtDW->THRmaxf - rtDW->THRminf;
  velRateMax = 1.0 / (velRateMax_tmp * rtDW->timeConstant / velRateMax_tmp_0);
  cosPhi = sqrt(rtDW->rot_body_to_ned[3] * rtDW->rot_body_to_ned[3] +
                rtDW->rot_body_to_ned[4] * rtDW->rot_body_to_ned[4]);
  cosPhi *= cosPhi;
  thrRateIncr = cosPhi;
  if (cosPhi < 0.1) {
    thrRateIncr = 0.1;
  }

  if (cosPhi > 1.0) {
    thrRateIncr = 1.0;
  }

  velRateMin += (1.0 / thrRateIncr - 1.0) * rtDW->rollComp;
  rtDW->ff_throttle = velRateMin / velRateMax_tmp * velRateMax_tmp_0 *
    rtDW->p_ff_throttle + rtDW->throttle_cruise * 0.01;
  rtDW->throttle_dem = (STEdot_error * rtDW->thrDamp + rtDW->STE_error) *
    velRateMax + rtDW->ff_throttle;
  velRateMin = rtDW->throttle_dem;
  if (rtDW->throttle_dem < rtDW->THRminf) {
    rtDW->throttle_dem = rtDW->THRminf;
  }

  if (velRateMin > rtDW->THRmaxf) {
    rtDW->throttle_dem = rtDW->THRmaxf;
  }

  velRateMin = rtDW->THRminf;
  if (rtDW->THRminf < 0.0) {
    velRateMin = 0.0;
  }

  if (rtDW->THRminf > rtDW->THRmaxf) {
    velRateMin = rtDW->THRmaxf;
  }

  if (rtDW->throttle_slewrate != 0.0) {
    thrRateIncr = (rtDW->THRmaxf - velRateMin) * rtDW->dt *
      rtDW->throttle_slewrate * 0.01;
    STEdot_error = rtDW->throttle_dem;
    cosPhi = rtDW->last_throttle_dem - thrRateIncr;
    thrRateIncr += rtDW->last_throttle_dem;
    if (rtDW->throttle_dem < cosPhi) {
      rtDW->throttle_dem = cosPhi;
    }

    if (STEdot_error > thrRateIncr) {
      rtDW->throttle_dem = thrRateIncr;
    }

    rtDW->last_throttle_dem = rtDW->throttle_dem;
  }

  STEdot_error = (rtDW->THRmaxf - velRateMin) * 0.5;
  cosPhi = (rtDW->THRmaxf - rtDW->throttle_dem) + 0.1;
  velRateMin = cosPhi;
  if (cosPhi < -STEdot_error) {
    velRateMin = -STEdot_error;
  }

  if (cosPhi > STEdot_error) {
    velRateMin = STEdot_error;
  }

  thrRateIncr = (rtDW->THRminf - rtDW->throttle_dem) - 0.1;
  cosPhi = thrRateIncr;
  if (thrRateIncr < -STEdot_error) {
    cosPhi = -STEdot_error;
  }

  if (thrRateIncr > STEdot_error) {
    cosPhi = STEdot_error;
  }

  rtDW->integTHR_state += rtDW->STE_error * rtDW->integGain * rtDW->dt *
    velRateMax;
  velRateMax = rtDW->integTHR_state;
  if (rtDW->integTHR_state < cosPhi) {
    rtDW->integTHR_state = cosPhi;
  }

  if (velRateMax > velRateMin) {
    rtDW->integTHR_state = velRateMin;
  }

  rtDW->throttle_dem += rtDW->integTHR_state;
  velRateMax = rtDW->throttle_dem;
  if (rtDW->throttle_dem < rtDW->THRminf) {
    rtDW->throttle_dem = rtDW->THRminf;
  }

  if (velRateMax > rtDW->THRmaxf) {
    rtDW->throttle_dem = rtDW->THRmaxf;
  }

  STEdot_error = rtDW->spdWeight;
  if (rtDW->spdWeight < 0.0) {
    STEdot_error = 0.0;
  }

  if (rtDW->spdWeight > 2.0) {
    STEdot_error = 2.0;
  }

  cosPhi = (2.0 - STEdot_error) * rtDW->SPEdot_dem - rtDW->SKEdot_dem *
    STEdot_error;
  velRateMax_tmp = STEdot_error_tmp;
  if (STEdot_error_tmp < -integSEB_range) {
    velRateMax_tmp = -integSEB_range;
  }

  if (STEdot_error_tmp > -velRateMin_tmp) {
    velRateMax_tmp = -velRateMin_tmp;
  }

  thrRateIncr = (2.0 - STEdot_error) * velRateMax_tmp - (rtDW->SKE_dem -
    rtDW->SKE_est) * STEdot_error;
  velRateMax = thrRateIncr * rtDW->integGain;
  if (rtDW->pitch_dem > rtDW->PITCHmaxf) {
    velRateMax = fmin(velRateMax, rtDW->PITCHmaxf - rtDW->pitch_dem);
  } else {
    if (rtDW->pitch_dem < rtDW->PITCHminf) {
      velRateMax = fmax(velRateMax, rtDW->PITCHminf - rtDW->pitch_dem);
    }
  }

  velRateMin = velRateMax * rtDW->dt;
  velRateMax = rtDW->TAS_state * rtDW->timeConstant * rtDW->GRAVITY_MSS;
  STEdot_error = (cosPhi - ((2.0 - STEdot_error) * rtDW->SPEdot - rtDW->SKEdot *
    STEdot_error)) * rtDW->ptchDamp + (cosPhi * rtDW->timeConstant + thrRateIncr);
  cosPhi = (rtDW->PITCHminf - 0.0783) * velRateMax - STEdot_error;
  thrRateIncr = (rtDW->PITCHmaxf + 0.0783) * velRateMax - STEdot_error;
  integSEB_range = thrRateIncr - cosPhi;
  velRateMax_tmp = velRateMin;
  velRateMin_tmp = -integSEB_range * 0.1;
  integSEB_range *= 0.1;
  if (velRateMin < velRateMin_tmp) {
    velRateMin = velRateMin_tmp;
  }

  if (velRateMax_tmp > integSEB_range) {
    velRateMin = integSEB_range;
  }

  cosPhi = fmin(cosPhi, rtDW->integSEB_state);
  thrRateIncr = fmax(thrRateIncr, rtDW->integSEB_state);
  velRateMin += rtDW->integSEB_state;
  rtDW->integSEB_state = velRateMin;
  if (velRateMin < cosPhi) {
    rtDW->integSEB_state = cosPhi;
  }

  if (velRateMin > thrRateIncr) {
    rtDW->integSEB_state = thrRateIncr;
  }

  rtDW->pitch_dem_unc = (STEdot_error + rtDW->integSEB_state) / velRateMax;
  rtDW->pitch_dem = rtDW->pitch_dem_unc;
  if (rtDW->pitch_dem_unc < rtDW->PITCHminf) {
    rtDW->pitch_dem = rtDW->PITCHminf;
  }

  if (rtDW->pitch_dem_unc > rtDW->PITCHmaxf) {
    rtDW->pitch_dem = rtDW->PITCHmaxf;
  }

  velRateMax = rtDW->dt * rtDW->vertAccLim / rtDW->TAS_state;
  cosPhi = rtDW->pitch_dem - rtDW->last_pitch_dem;
  if (cosPhi > velRateMax) {
    rtDW->pitch_dem = rtDW->last_pitch_dem + velRateMax;
  } else {
    if (cosPhi < -velRateMax) {
      rtDW->pitch_dem = rtDW->last_pitch_dem - velRateMax;
    }
  }

  velRateMax = rtDW->pitch_dem;
  if (rtDW->pitch_dem < rtDW->PITCHminf) {
    rtDW->pitch_dem = rtDW->PITCHminf;
  }

  if (velRateMax > rtDW->PITCHmaxf) {
    rtDW->pitch_dem = rtDW->PITCHmaxf;
  }

  rtDW->last_pitch_dem = rtDW->pitch_dem;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T get_bearing_to(const real_T loc2[2], const real_T b_loc[2], DW
  *rtDW)
{
  real_T bearing;
  real_T x;
  x = cos(b_loc[0] * 1.0E-7 / rtDW->HD);
  if (x < 0.01) {
    x = 0.01;
  }

  bearing = rt_atan2d_snf(-((loc2[0] - b_loc[0]) / x), loc2[1] - b_loc[1]) *
    rtDW->HD * 100.0 + 9000.0;
  if (bearing < 0.0) {
    bearing += 36000.0;
  }

  return bearing;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static real_T prevent_indecision(real_T Nu, DW *rtDW)
{
  real_T Nuo;
  real_T yawo;
  if (fabs(Nu) > 2.8274333882308138) {
    yawo = rtDW->yaw;
    if (rtDW->reverse != 0.0) {
      yawo = wrap_PI(rtDW->yaw + 3.1415926535897931);
    }

    if (fabs(wrap_PI(rtDW->target_bearing_cd / rtDW->HD / 100.0 - yawo)) >
        12000.0 / rtDW->HD / 100.0) {
      if (rtDW->loiter_direction == 1.0) {
        Nu = 2.8274333882308138;
      } else {
        Nu = -2.8274333882308138;
      }
    }
  }

  Nuo = Nu;
  if ((fabs(Nu) > 2.8274333882308138) && (fabs(rtDW->last_Nu) >
       2.8274333882308138)) {
    yawo = rtDW->yaw;
    if (rtDW->reverse != 0.0) {
      yawo = wrap_PI(rtDW->yaw + 3.1415926535897931);
    }

    if ((fabs(wrap_PI(rtDW->target_bearing_cd / rtDW->HD / 100.0 - yawo)) >
         12000.0 / rtDW->HD / 100.0) && (Nu * rtDW->last_Nu < 0.0)) {
      Nuo = rtDW->last_Nu;
    }
  }

  return Nuo;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_waypoint(const real_T b_prev_WP[2], const real_T b_next_WP[2],
  real_T b_dist_min, DW *rtDW)
{
  real_T groundSpeed;
  real_T AB[2];
  real_T AB_length;
  real_T A_air[2];
  real_T A_air_length;
  real_T alongTrackDist;
  real_T A_air_0;
  real_T tmp;
  rtDW->target_bearing_cd = get_bearing_to(b_next_WP, rtDW->current_loc, rtDW);
  groundSpeed = norm(rtDW->groundspeed_vector);
  if (groundSpeed < 0.1) {
    groundSpeed = 0.1;
    A_air_length = rtDW->yaw;
    if (rtDW->reverse != 0.0) {
      A_air_length = wrap_PI(rtDW->yaw + 3.1415926535897931);
    }

    AB_length = rtDW->yaw;
    if (rtDW->reverse != 0.0) {
      AB_length = wrap_PI(rtDW->yaw + 3.1415926535897931);
    }

    rtDW->groundspeed_vector[0] = cos(A_air_length) * 0.1;
    rtDW->groundspeed_vector[1] = sin(AB_length) * 0.1;
  }

  rtDW->L1_dist = fmax(0.3183099 * rtDW->L1_damping * rtDW->L1_period *
                       groundSpeed, b_dist_min);
  A_air_length = cos(b_prev_WP[0] * 1.0E-7 / rtDW->HD);
  AB_length = A_air_length;
  if (A_air_length < 0.01) {
    AB_length = 0.01;
  }

  AB[0] = (b_next_WP[0] - b_prev_WP[0]) * rtDW->LOCATION_SCALING_FACTOR;
  AB[1] = (b_next_WP[1] - b_prev_WP[1]) * rtDW->LOCATION_SCALING_FACTOR *
    AB_length;
  AB_length = norm(AB);
  if (AB_length < 1.0E-6) {
    AB_length = cos(rtDW->current_loc[0] * 1.0E-7 / rtDW->HD);
    if (AB_length < 0.01) {
      AB_length = 0.01;
    }

    AB[0] = (b_next_WP[0] - rtDW->current_loc[0]) *
      rtDW->LOCATION_SCALING_FACTOR;
    AB[1] = (b_next_WP[1] - rtDW->current_loc[1]) *
      rtDW->LOCATION_SCALING_FACTOR * AB_length;
    AB_length = norm(AB);
    if (AB_length < 1.0E-6) {
      AB_length = rtDW->yaw;
      if (rtDW->reverse != 0.0) {
        AB_length = wrap_PI(rtDW->yaw + 3.1415926535897931);
      }

      alongTrackDist = rtDW->yaw;
      if (rtDW->reverse != 0.0) {
        alongTrackDist = wrap_PI(rtDW->yaw + 3.1415926535897931);
      }

      AB[0] = cos(AB_length);
      AB[1] = sin(alongTrackDist);
      AB_length = norm(AB);
    }
  }

  AB[0] /= AB_length;
  alongTrackDist = AB[1] / AB_length;
  if (A_air_length < 0.01) {
    A_air_length = 0.01;
  }

  A_air[0] = (rtDW->current_loc[0] - b_prev_WP[0]) *
    rtDW->LOCATION_SCALING_FACTOR;
  A_air[1] = (rtDW->current_loc[1] - b_prev_WP[1]) *
    rtDW->LOCATION_SCALING_FACTOR * A_air_length;
  A_air_length = norm(A_air);
  rtDW->crosstrack_error = A_air[0] * alongTrackDist - A_air[1] * AB[0];
  A_air_0 = A_air[0] * AB[0] + A_air[1] * alongTrackDist;
  if ((A_air_length > rtDW->L1_dist) && (A_air_0 / fmax(A_air_length, 1.0) <
       -0.7071)) {
    rtDW->mode_L1 = 0.0;
  } else if (A_air_0 > groundSpeed * 4.0 + AB_length) {
    rtDW->mode_L1 = 1.0;
  } else {
    rtDW->mode_L1 = 2.0;
  }

  if ((A_air_0 > AB_length + groundSpeed) && (rtDW->mode_L1_old == 1.0) &&
      (rtDW->mode_L1 == 2.0)) {
    rtDW->mode_L1 = 1.0;
  }

  rtDW->mode_L1_old = rtDW->mode_L1;
  switch ((int32_T)rtDW->mode_L1) {
   case 0:
    A_air_0 = A_air[0] / A_air_length;
    AB_length = -A_air_0;
    tmp = rtDW->groundspeed_vector[0] * -A_air_0;
    A_air[0] = A_air_0;
    A_air_0 = A_air[1] / A_air_length;
    tmp += rtDW->groundspeed_vector[1] * -A_air_0;
    AB_length = rt_atan2d_snf(rtDW->groundspeed_vector[0] * -A_air_0 -
      rtDW->groundspeed_vector[1] * AB_length, tmp);
    rtDW->nav_bearing = rt_atan2d_snf(-A_air_0, -A_air[0]);
    break;

   case 1:
    A_air_length = cos(b_next_WP[0] * 1.0E-7 / rtDW->HD);
    if (A_air_length < 0.01) {
      A_air_length = 0.01;
    }

    AB[0] = (rtDW->current_loc[0] - b_next_WP[0]) *
      rtDW->LOCATION_SCALING_FACTOR;
    AB[1] = (rtDW->current_loc[1] - b_next_WP[1]) *
      rtDW->LOCATION_SCALING_FACTOR * A_air_length;
    A_air_length = norm(AB);
    alongTrackDist = AB[0] / A_air_length;
    AB_length = -alongTrackDist;
    tmp = rtDW->groundspeed_vector[0] * -alongTrackDist;
    AB[0] = alongTrackDist;
    alongTrackDist = AB[1] / A_air_length;
    tmp += rtDW->groundspeed_vector[1] * -alongTrackDist;
    AB_length = rt_atan2d_snf(rtDW->groundspeed_vector[0] * -alongTrackDist -
      rtDW->groundspeed_vector[1] * AB_length, tmp);
    rtDW->nav_bearing = rt_atan2d_snf(-alongTrackDist, -AB[0]);
    break;

   case 2:
    A_air_length = rtDW->crosstrack_error / fmax(rtDW->L1_dist, 0.1);
    AB_length = A_air_length;
    if (A_air_length < -0.7071) {
      A_air_length = -0.7071;
    }

    if (AB_length > 0.7071) {
      A_air_length = 0.7071;
    }

    A_air_length = asin(A_air_length);
    if ((rtDW->L1_xtrack_i_gain <= 0.0) || (rtDW->L1_xtrack_i_gain !=
         rtDW->L1_xtrack_i_gain_prev)) {
      rtDW->L1_xtrack_i = 0.0;
      rtDW->L1_xtrack_i_gain_prev = rtDW->L1_xtrack_i_gain;
    } else {
      if (fabs(A_air_length) < 0.087266462599716474) {
        rtDW->L1_xtrack_i += A_air_length * rtDW->L1_xtrack_i_gain * rtDW->dt;
        AB_length = rtDW->L1_xtrack_i;
        if (rtDW->L1_xtrack_i < -0.1) {
          rtDW->L1_xtrack_i = -0.1;
        }

        if (AB_length > 0.1) {
          rtDW->L1_xtrack_i = 0.1;
        }
      }
    }

    A_air_length += rtDW->L1_xtrack_i;
    AB_length = wrap_PI(rt_atan2d_snf(rtDW->groundspeed_vector[0] *
      alongTrackDist - rtDW->groundspeed_vector[1] * AB[0],
      rtDW->groundspeed_vector[0] * AB[0] + rtDW->groundspeed_vector[1] *
      alongTrackDist) + A_air_length);
    rtDW->nav_bearing = rt_atan2d_snf(alongTrackDist, AB[0]) + A_air_length;
    break;

   default:
    A_air_length = rtDW->crosstrack_error / fmax(rtDW->L1_dist, 0.1);
    AB_length = A_air_length;
    if (A_air_length < -0.7071) {
      A_air_length = -0.7071;
    }

    if (AB_length > 0.7071) {
      A_air_length = 0.7071;
    }

    A_air_length = asin(A_air_length);
    if ((rtDW->L1_xtrack_i_gain <= 0.0) || (rtDW->L1_xtrack_i_gain !=
         rtDW->L1_xtrack_i_gain_prev)) {
      rtDW->L1_xtrack_i = 0.0;
      rtDW->L1_xtrack_i_gain_prev = rtDW->L1_xtrack_i_gain;
    } else {
      if (fabs(A_air_length) < 0.087266462599716474) {
        rtDW->L1_xtrack_i += A_air_length * rtDW->L1_xtrack_i_gain * rtDW->dt;
        AB_length = rtDW->L1_xtrack_i;
        if (rtDW->L1_xtrack_i < -0.1) {
          rtDW->L1_xtrack_i = -0.1;
        }

        if (AB_length > 0.1) {
          rtDW->L1_xtrack_i = 0.1;
        }
      }
    }

    A_air_length += rtDW->L1_xtrack_i;
    AB_length = wrap_PI(rt_atan2d_snf(rtDW->groundspeed_vector[0] *
      alongTrackDist - rtDW->groundspeed_vector[1] * AB[0],
      rtDW->groundspeed_vector[0] * AB[0] + rtDW->groundspeed_vector[1] *
      alongTrackDist) + A_air_length);
    rtDW->nav_bearing = rt_atan2d_snf(alongTrackDist, AB[0]) + A_air_length;
    break;
  }

  AB_length = prevent_indecision(AB_length, rtDW);
  rtDW->last_Nu = AB_length;
  A_air_length = AB_length;
  if (AB_length < -1.5708) {
    AB_length = -1.5708;
  }

  if (A_air_length > 1.5708) {
    AB_length = 1.5708;
  }

  rtDW->latAccDem = 4.0 * rtDW->L1_damping * rtDW->L1_damping * groundSpeed *
    groundSpeed / rtDW->L1_dist * sin(AB_length);
  rtDW->WPcircle = 0.0;
  rtDW->bearing_error = AB_length;
  rtDW->data_is_stale = 0.0;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void update_loiter(const real_T b_center_WP[2], real_T b_radius, real_T
  b_loiter_direction, DW *rtDW)
{
  real_T groundspeed_vector_length;
  real_T A_air[2];
  real_T A_air_length;
  real_T sanitized_bank_limit;
  real_T lateral_accel_sea_level;
  real_T eas2tas_sq;
  real_T amt;
  real_T tmp;
  groundspeed_vector_length = fabs(b_radius);
  sanitized_bank_limit = rtDW->loiter_bank_limit;
  if (rtDW->loiter_bank_limit < 0.0) {
    sanitized_bank_limit = 0.0;
  }

  if (rtDW->loiter_bank_limit > 89.0) {
    sanitized_bank_limit = 89.0;
  }

  lateral_accel_sea_level = tan(sanitized_bank_limit / 180.0 *
    3.1415926535897931) * rtDW->GRAVITY_MSS;
  eas2tas_sq = rtDW->EAS2TAS * rtDW->EAS2TAS;
  if ((sanitized_bank_limit == 0.0) || (rtDW->EAS_dem == 0.0) ||
      (lateral_accel_sea_level == 0.0)) {
    b_radius = groundspeed_vector_length * eas2tas_sq;
  } else {
    sanitized_bank_limit = rtDW->EAS_dem * rtDW->EAS_dem /
      lateral_accel_sea_level;
    if (sanitized_bank_limit > groundspeed_vector_length) {
      b_radius = groundspeed_vector_length * eas2tas_sq;
    } else {
      b_radius = fmax(sanitized_bank_limit * eas2tas_sq,
                      groundspeed_vector_length);
    }
  }

  eas2tas_sq = 6.2832 / rtDW->L1_period;
  groundspeed_vector_length = norm(rtDW->groundspeed_vector);
  lateral_accel_sea_level = fmax(groundspeed_vector_length, 1.0);
  rtDW->target_bearing_cd = get_bearing_to(b_center_WP, rtDW->current_loc, rtDW);
  rtDW->L1_dist = 0.3183099 * rtDW->L1_damping * rtDW->L1_period *
    lateral_accel_sea_level;
  sanitized_bank_limit = cos(b_center_WP[0] * 1.0E-7 / rtDW->HD);
  if (sanitized_bank_limit < 0.01) {
    sanitized_bank_limit = 0.01;
  }

  A_air[0] = (rtDW->current_loc[0] - b_center_WP[0]) *
    rtDW->LOCATION_SCALING_FACTOR;
  A_air[1] = (rtDW->current_loc[1] - b_center_WP[1]) *
    rtDW->LOCATION_SCALING_FACTOR * sanitized_bank_limit;
  A_air_length = norm(A_air);
  if (A_air_length > 0.1) {
    A_air[0] /= A_air_length;
    A_air[1] /= A_air_length;
  } else if (groundspeed_vector_length < 0.1) {
    A_air[0] = cos(rtDW->yaw);
    A_air[1] = sin(rtDW->yaw);
  } else {
    A_air[0] = rtDW->groundspeed_vector[0] / groundspeed_vector_length;
    A_air[1] = rtDW->groundspeed_vector[1] / groundspeed_vector_length;
  }

  sanitized_bank_limit = A_air[0] * rtDW->groundspeed_vector[1] - A_air[1] *
    rtDW->groundspeed_vector[0];
  tmp = rtDW->groundspeed_vector[0] * A_air[0] + rtDW->groundspeed_vector[1] *
    A_air[1];
  groundspeed_vector_length = prevent_indecision(rt_atan2d_snf
    (sanitized_bank_limit, -tmp), rtDW);
  rtDW->last_Nu = groundspeed_vector_length;
  amt = groundspeed_vector_length;
  if (groundspeed_vector_length < -1.5707963267948966) {
    groundspeed_vector_length = -1.5707963267948966;
  }

  if (amt > 1.5707963267948966) {
    groundspeed_vector_length = 1.5707963267948966;
  }

  lateral_accel_sea_level = 4.0 * rtDW->L1_damping * rtDW->L1_damping *
    lateral_accel_sea_level * lateral_accel_sea_level / rtDW->L1_dist * sin
    (groundspeed_vector_length);
  A_air_length -= b_radius;
  rtDW->crosstrack_error = A_air_length;
  eas2tas_sq = 2.0 * rtDW->L1_damping * eas2tas_sq * tmp + eas2tas_sq *
    eas2tas_sq * A_air_length;
  sanitized_bank_limit *= b_loiter_direction;
  if ((-tmp < 0.0) && (sanitized_bank_limit < 0.0)) {
    eas2tas_sq = fmax(eas2tas_sq, 0.0);
  }

  eas2tas_sq = (sanitized_bank_limit * sanitized_bank_limit / fmax(0.5 *
    b_radius, b_radius + A_air_length) + eas2tas_sq) * b_loiter_direction;
  if ((A_air_length > 0.0) && (b_loiter_direction * lateral_accel_sea_level <
       b_loiter_direction * eas2tas_sq)) {
    rtDW->latAccDem = lateral_accel_sea_level;
    rtDW->WPcircle = 0.0;
    rtDW->bearing_error = groundspeed_vector_length;
    rtDW->nav_bearing = rt_atan2d_snf(-A_air[1], -A_air[0]);
  } else {
    rtDW->latAccDem = eas2tas_sq;
    rtDW->WPcircle = 1.0;
    rtDW->bearing_error = 0.0;
    rtDW->nav_bearing = rt_atan2d_snf(-A_air[1], -A_air[0]);
  }

  rtDW->data_is_stale = 0.0;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void AP_MotorsMulticopter_output(DW *rtDW)
{
  real_T thrust_dt;
  real_T tail_tilt_temp;
  real_T high;
  int8_T n;
  real_T absx;
  real_T thrust_dt_tmp;
  update_throttle_filter(rtDW);
  output_armed_stabilizing(rtDW);
  thrust_dt_tmp = rtDW->pwm_max - rtDW->pwm_min;
  thrust_dt = thrust_dt_tmp * rtDW->dt / rtDW->thrust_slew_time;
  switch ((int32_T)rtDW->mode) {
   case 1:
    rtDW->tail_tilt = 0.0;
    break;

   case 2:
    rtDW->tail_tilt = 0.0;
    break;

   case 3:
    rtDW->tail_tilt = 0.0;
    break;

   case 4:
    rtDW->tail_tilt = -9556.0;
    break;

   case 5:
    rtDW->tail_tilt = -9556.0;
    break;

   case 6:
    rtDW->tail_tilt = -9556.0;
    break;
  }

  tail_tilt_temp = rtDW->tail_tilt;
  if (rtDW->tail_tilt < rtDW->tail_tilt_c2p) {
    tail_tilt_temp = rtDW->tail_tilt_c2p;
  }

  if (rtDW->tail_tilt > 700.0) {
    tail_tilt_temp = 700.0;
  }

  tail_tilt_temp /= 100.0;
  if (rtIsInf(tail_tilt_temp) || rtIsNaN(tail_tilt_temp)) {
    tail_tilt_temp = (rtNaN);
  } else {
    tail_tilt_temp = rt_remd_snf(tail_tilt_temp, 360.0);
    absx = fabs(tail_tilt_temp);
    if (absx > 180.0) {
      if (tail_tilt_temp > 0.0) {
        tail_tilt_temp -= 360.0;
      } else {
        tail_tilt_temp += 360.0;
      }

      absx = fabs(tail_tilt_temp);
    }

    if (absx <= 45.0) {
      tail_tilt_temp *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (tail_tilt_temp > 0.0) {
        tail_tilt_temp = (tail_tilt_temp - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        tail_tilt_temp = (tail_tilt_temp + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (tail_tilt_temp > 0.0) {
      tail_tilt_temp = (tail_tilt_temp - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      tail_tilt_temp = (tail_tilt_temp + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      tail_tilt_temp = cos(tail_tilt_temp);
      break;

     case 1:
      tail_tilt_temp = -sin(tail_tilt_temp);
      break;

     case -1:
      tail_tilt_temp = sin(tail_tilt_temp);
      break;

     default:
      tail_tilt_temp = -cos(tail_tilt_temp);
      break;
    }
  }

  tail_tilt_temp = (1.0 / tail_tilt_temp - 1.0) * rtDW->p_tail_tilt + 1.0;
  rtDW->thrust_rpyt_out[1] *= tail_tilt_temp;
  rtDW->thrust_rpyt_out[3] *= tail_tilt_temp;
  tail_tilt_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[0] + rtDW->pwm_min;
  absx = rtDW->pwm_out[0] - thrust_dt;
  high = rtDW->pwm_out[0] + thrust_dt;
  rtDW->pwm_out[0] = tail_tilt_temp;
  if (tail_tilt_temp < absx) {
    rtDW->pwm_out[0] = absx;
  }

  if (tail_tilt_temp > high) {
    rtDW->pwm_out[0] = high;
  }

  tail_tilt_temp = rtDW->pwm_out[0];
  if (rtDW->pwm_out[0] < rtDW->pwm_min) {
    tail_tilt_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[0] > rtDW->pwm_max) {
    tail_tilt_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[0] = tail_tilt_temp;
  tail_tilt_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[1] + rtDW->pwm_min;
  absx = rtDW->pwm_out[1] - thrust_dt;
  high = rtDW->pwm_out[1] + thrust_dt;
  rtDW->pwm_out[1] = tail_tilt_temp;
  if (tail_tilt_temp < absx) {
    rtDW->pwm_out[1] = absx;
  }

  if (tail_tilt_temp > high) {
    rtDW->pwm_out[1] = high;
  }

  tail_tilt_temp = rtDW->pwm_out[1];
  if (rtDW->pwm_out[1] < rtDW->pwm_min) {
    tail_tilt_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[1] > rtDW->pwm_max) {
    tail_tilt_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[1] = tail_tilt_temp;
  tail_tilt_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[2] + rtDW->pwm_min;
  absx = rtDW->pwm_out[2] - thrust_dt;
  high = rtDW->pwm_out[2] + thrust_dt;
  rtDW->pwm_out[2] = tail_tilt_temp;
  if (tail_tilt_temp < absx) {
    rtDW->pwm_out[2] = absx;
  }

  if (tail_tilt_temp > high) {
    rtDW->pwm_out[2] = high;
  }

  tail_tilt_temp = rtDW->pwm_out[2];
  if (rtDW->pwm_out[2] < rtDW->pwm_min) {
    tail_tilt_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[2] > rtDW->pwm_max) {
    tail_tilt_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[2] = tail_tilt_temp;
  tail_tilt_temp = thrust_dt_tmp * rtDW->thrust_rpyt_out[3] + rtDW->pwm_min;
  absx = rtDW->pwm_out[3] - thrust_dt;
  high = rtDW->pwm_out[3] + thrust_dt;
  rtDW->pwm_out[3] = tail_tilt_temp;
  if (tail_tilt_temp < absx) {
    rtDW->pwm_out[3] = absx;
  }

  if (tail_tilt_temp > high) {
    rtDW->pwm_out[3] = high;
  }

  tail_tilt_temp = rtDW->pwm_out[3];
  if (rtDW->pwm_out[3] < rtDW->pwm_min) {
    tail_tilt_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[3] > rtDW->pwm_max) {
    tail_tilt_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[3] = tail_tilt_temp;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void copter_run(DW *rtDW)
{
  real_T temp_yaw_rate;
  real_T b_pitch;
  real_T output;
  if (fabs(rtDW->vel_desired[0]) > 0.0) {
    temp_yaw_rate = 0.0;
  } else if (fabs(rtDW->vel_desired[1]) > 0.0) {
    temp_yaw_rate = 0.0;
  } else if (fabs(rtDW->target_yaw_rate) > 0.0) {
    temp_yaw_rate = 0.0;
  } else {
    temp_yaw_rate = get_weathervane_yaw_rate_cds(rtDW);
  }

  b_pitch = rtDW->pitch_target / 100.0;
  if (b_pitch > rtDW->vel_forward_min_pitch) {
    rtDW->vel_forward_last_pct = 0.0;
    rtDW->tail_tilt = 0.0;
  } else {
    b_pitch -= rtDW->vel_forward_min_pitch;
    b_pitch = b_pitch / 25.0 * rtDW->vel_forward_gain;
    output = b_pitch;
    if (b_pitch < -1.0) {
      output = -1.0;
    }

    if (b_pitch > 0.0) {
      output = 0.0;
    }

    rtDW->vel_forward_last_pct = 0.98 * rtDW->vel_forward_last_pct + 0.02 *
      output;
    rtDW->tail_tilt = rtDW->vel_forward_last_pct *
      rtDW->vel_forward_tail_tilt_max;
  }

  update_vel_controller_xy(rtDW);
  update_z_controller(rtDW);
  input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
    rtDW->target_yaw_rate + temp_yaw_rate, rtDW);
  rate_controller_run(rtDW);
  if (rtDW->aspeed > rtDW->aspeed_cp) {
    rtDW->nav_pitch_cd = rtDW->pitch_target;
    rtDW->nav_roll_cd = rtDW->roll_target;
    stabilize(rtDW);
    rtDW->k_aileron *= rtDW->p_plane_cp;
    rtDW->k_elevator *= rtDW->p_plane_cp;
    rtDW->k_rudder *= rtDW->p_plane_cp;
  } else {
    rtDW->k_aileron = 0.0;
    rtDW->k_elevator = 0.0;
    rtDW->k_rudder = 0.0;
  }

  AP_MotorsMulticopter_output(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void get_vector_xy_from_origin_NE(const real_T b_loc[2], const real_T
  b_loc_origin[2], real_T vec_ne[2], DW *rtDW)
{
  real_T x;
  vec_ne[0] = (b_loc[0] - b_loc_origin[0]) * rtDW->LOCATION_SCALING_FACTOR;
  x = cos(b_loc_origin[0] * 1.0E-7 / rtDW->HD);
  if (x < 0.01) {
    x = 0.01;
  }

  vec_ne[1] = (b_loc[1] - b_loc_origin[1]) * rtDW->LOCATION_SCALING_FACTOR * x;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void set_alt_target_from_climb_rat_a(real_T alt_cm, real_T
  b_climb_rate_cms, real_T b_dt, real_T force_descend, DW *rtDW)
{
  real_T accel_z_cms;
  real_T jerk_z;
  real_T alt_change;
  real_T climb_rate_cms_temp;
  accel_z_cms = rtDW->POSCONTROL_ACCEL_Z;
  if ((rtDW->vel_desired[2] < rtDW->POSCONTROL_SPEED_DOWN) &&
      (rtDW->POSCONTROL_SPEED_DOWN != 0.0)) {
    accel_z_cms = rtDW->POSCONTROL_ACCEL_Z * rtDW->POSCONTROL_OVERSPEED_GAIN_Z *
      rtDW->vel_desired[2] / rtDW->POSCONTROL_SPEED_DOWN;
  }

  if ((rtDW->vel_desired[2] > rtDW->POSCONTROL_SPEED_UP) &&
      (rtDW->POSCONTROL_SPEED_UP != 0.0)) {
    accel_z_cms = accel_z_cms * rtDW->POSCONTROL_OVERSPEED_GAIN_Z *
      rtDW->vel_desired[2] / rtDW->POSCONTROL_SPEED_UP;
  }

  alt_change = accel_z_cms;
  if (accel_z_cms < 0.0) {
    accel_z_cms = 0.0;
  }

  if (alt_change > 750.0) {
    accel_z_cms = 750.0;
  }

  jerk_z = accel_z_cms * rtDW->POSCONTROL_JERK_RATIO;
  alt_change = (alt_cm - rtDW->pos_target[2]) * 6.0;
  if (alt_change < 0.0) {
    climb_rate_cms_temp = -1.0;
  } else if (alt_change > 0.0) {
    climb_rate_cms_temp = 1.0;
  } else if (alt_change == 0.0) {
    climb_rate_cms_temp = 0.0;
  } else {
    climb_rate_cms_temp = (rtNaN);
  }

  b_climb_rate_cms *= climb_rate_cms_temp;
  rtDW->accel_last_z_cms += jerk_z * b_dt;
  rtDW->accel_last_z_cms = fmin(fmin(accel_z_cms, sqrt(fabs(rtDW->vel_desired[2]
    - b_climb_rate_cms) * 2.0 * jerk_z)), rtDW->accel_last_z_cms);
  jerk_z = rtDW->accel_last_z_cms * b_dt;
  accel_z_cms = rtDW->vel_desired[2] - jerk_z;
  jerk_z += rtDW->vel_desired[2];
  climb_rate_cms_temp = b_climb_rate_cms;
  if (b_climb_rate_cms < accel_z_cms) {
    climb_rate_cms_temp = accel_z_cms;
  }

  if (b_climb_rate_cms > jerk_z) {
    climb_rate_cms_temp = jerk_z;
  }

  accel_z_cms = fabs(climb_rate_cms_temp);
  rtDW->vel_desired[2] = alt_change;
  if (alt_change < -accel_z_cms) {
    rtDW->vel_desired[2] = -accel_z_cms;
  }

  if (alt_change > accel_z_cms) {
    rtDW->vel_desired[2] = accel_z_cms;
  }

  rtDW->use_desvel_ff_z = 1.0;
  if ((rtDW->vel_desired[2] < 0.0) && ((!(rtDW->throttle_lower != 0.0)) ||
       (force_descend != 0.0))) {
    rtDW->pos_target[2] += rtDW->vel_desired[2] * b_dt;
  } else {
    if ((rtDW->vel_desired[2] > 0.0) && ((!(rtDW->throttle_upper != 0.0)) &&
         (!(rtDW->limit_pos_up != 0.0)))) {
      rtDW->pos_target[2] += rtDW->vel_desired[2] * b_dt;
    }
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void plane_run_4a1(DW *rtDW)
{
  real_T commanded_pitch;
  update_50hz(rtDW);
  update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                        rtDW->aerodynamic_load_factor, rtDW);
  commanded_pitch = rtDW->pitch_dem * rtDW->HD * 100.0;
  rtDW->nav_pitch_cd = commanded_pitch;
  if (commanded_pitch < rtDW->pitch_limit_min_cd) {
    rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
  }

  if (commanded_pitch > rtDW->pitch_limit_max_cd) {
    rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
  }

  calc_nav_roll(rtDW);
  rtDW->k_throttle = rtDW->throttle_dem;
  stabilize(rtDW);
  output_to_motors_plane_4a1(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void calc_nav_pitch(DW *rtDW)
{
  real_T commanded_pitch;
  commanded_pitch = rtDW->pitch_dem * rtDW->HD * 100.0;
  rtDW->nav_pitch_cd = commanded_pitch;
  if (commanded_pitch < rtDW->pitch_limit_min_cd) {
    rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
  }

  if (commanded_pitch > rtDW->pitch_limit_max_cd) {
    rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void get_distance_NE(const real_T loc2[2], const real_T b_loc[2], real_T
  distance_NE[2], DW *rtDW)
{
  real_T x;
  x = cos(b_loc[0] * 1.0E-7 / rtDW->HD);
  if (x < 0.01) {
    x = 0.01;
  }

  distance_NE[0] = (loc2[0] - b_loc[0]) * rtDW->LOCATION_SCALING_FACTOR;
  distance_NE[1] = (loc2[1] - b_loc[1]) * rtDW->LOCATION_SCALING_FACTOR * x;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void auto_mode_4a1(DW *rtDW)
{
  real_T pitch_target_temp;
  real_T AB[2];
  int32_T prev_WP_tmp;
  real_T k_throttle_tmp;
  if ((rtDW->PathModeOut_sl.flightTaskMode == HoverAdjustMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == TakeOffMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == LandMode)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  if (rtDW->uavMode_j == 1.0) {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
  } else {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  }

  switch (rtDW->PathModeOut_sl.flightTaskMode) {
   case TakeOffMode:
    if (rtDW->PathMode_g != TakeOffMode) {
      rtDW->PathMode_g = TakeOffMode;
      rtDW->uavMode_j = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->k_throttle = 0.0;
    } else {
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, AB, rtDW);
      rtDW->curr_pos[0] = AB[0] * 100.0;
      rtDW->curr_pos[1] = AB[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    copter_run(rtDW);
    break;

   case LandMode:
    if (rtDW->PathMode_g != LandMode) {
      rtDW->PathMode_g = LandMode;
      rtDW->uavMode_j = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->k_throttle = 0.0;
    } else {
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, AB, rtDW);
      rtDW->curr_pos[0] = AB[0] * 100.0;
      rtDW->curr_pos[1] = AB[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    copter_run(rtDW);
    break;

   case HoverAdjustMode:
    if (rtDW->PathMode_g != HoverAdjustMode) {
      rtDW->PathMode_g = HoverAdjustMode;
      rtDW->uavMode_j = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->k_throttle = 0.0;
    } else {
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, AB, rtDW);
      rtDW->curr_pos[0] = AB[0] * 100.0;
      rtDW->curr_pos[1] = AB[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    rtDW->vel_desired[0] = rtDW->PathModeOut_sl.groundspeedCmd * cos(rtDW->yaw);
    rtDW->vel_desired[1] = rtDW->PathModeOut_sl.groundspeedCmd * sin(rtDW->yaw);
    copter_run(rtDW);
    break;

   case HoverUpMode:
    if (rtDW->PathMode_g != HoverUpMode) {
      rtDW->PathMode_g = HoverUpMode;
      rtDW->uavMode_j = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run_4a1(rtDW);
    break;

   case HoverDownMode:
    if (rtDW->PathMode_g != HoverUpMode) {
      rtDW->PathMode_g = HoverUpMode;
      rtDW->uavMode_j = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    if (rtDW->PathModeOut_sl.rollCmd == 0.0) {
      rtDW->latAccDem = 0.0;
    }

    plane_run_4a1(rtDW);
    break;

   case AirStandByMode:
    if (rtDW->PathMode_g != HoverUpMode) {
      rtDW->PathMode_g = HoverUpMode;
      rtDW->uavMode_j = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run_4a1(rtDW);
    break;

   case Rotor2Fix_Mode:
    if (rtDW->PathMode_g != Rotor2Fix_Mode) {
      rtDW->PathMode_g = Rotor2Fix_Mode;
      rtDW->uavMode_j = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->roll_target = 0.0;
      rtDW->Rotor2Fix_delay_flag_n = 0.0;
    }

    if (rtDW->uavMode_j == 1.0) {
      if (rtDW->Rotor2Fix_delay_flag_n != 0.0) {
        rtDW->Rotor2Fix_delay_flag_n = 1.0;
        rtDW->nav_roll_cd = 0.0;
        update_50hz(rtDW);
        update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                              rtDW->aerodynamic_load_factor, rtDW);
        calc_nav_pitch(rtDW);
        rtDW->k_throttle = rtDW->throttle_dem;
        stabilize(rtDW);
        output_to_motors_plane_4a1(rtDW);
      } else {
        k_throttle_tmp = rtDW->throttle_cruise * 0.01 + rtDW->k_throttle_c2p;
        rtDW->k_throttle = k_throttle_tmp;
        update_speed(rtDW->aerodynamic_load_factor, rtDW);
        rtDW->pitch_target = 0.0;
        input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = 0.0;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->throttle_in = 0.0;
        pitch_target_temp = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (pitch_target_temp > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output_4a1(rtDW);
        if (rtDW->throttle_filter < 0.1) {
          rtDW->Rotor2Fix_delay_flag_n = 1.0;
          rtDW->throttle_dem = k_throttle_tmp;
          rtDW->last_throttle_dem = k_throttle_tmp;
        }
      }
    } else {
      rtDW->k_throttle = rtDW->throttle_cruise * 0.01 + rtDW->k_throttle_c2p;
      update_speed(rtDW->aerodynamic_load_factor, rtDW);
      if (rtDW->aspeed > rtDW->aspeed_c2ps) {
        rtDW->pitch_target = 0.0;
        input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = 0.0;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->throttle_in = 0.0;
        pitch_target_temp = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (pitch_target_temp > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output_4a1(rtDW);
        rtDW->uavMode_j = 1.0;
      } else if (rtDW->aspeed > rtDW->aspeed_c2p) {
        if (rtDW->pitch_target > 0.0) {
          rtDW->pitch_target = 0.0;
        }

        pitch_target_temp = rtDW->p_tilt_pitch_target * -3000.0 +
          rtDW->pitch_target;
        update_z_controller(rtDW);
        input_euler_angle_roll_pitch__o(rtDW->roll_target, pitch_target_temp,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = pitch_target_temp;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->k_aileron *= rtDW->p_plane_c2p;
        rtDW->k_elevator *= rtDW->p_plane_c2p;
        rtDW->k_rudder *= rtDW->p_plane_c2p;
        pitch_target_temp = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (pitch_target_temp > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output_4a1(rtDW);
      } else {
        if (rtDW->pitch_target > 0.0) {
          rtDW->pitch_target = 0.0;
        }

        update_z_controller(rtDW);
        input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target +
          rtDW->p_tilt_pitch_target * -3000.0, rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
        rtDW->k_aileron = 0.0;
        rtDW->k_elevator = 0.0;
        rtDW->k_rudder = 0.0;
        AP_MotorsMulticopter_output_4a1(rtDW);
      }
    }
    break;

   case Fix2Rotor_Mode:
    if (rtDW->PathMode_g != Fix2Rotor_Mode) {
      rtDW->PathMode_g = Fix2Rotor_Mode;
      rtDW->uavMode_j = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->tail_tilt = rtDW->tail_tilt_p2c;
      rtDW->roll_target = 0.0;
      rtDW->pitch_target = rtDW->pitch_target_p2c;
      rtDW->k_throttle = 0.0;
      rtDW->throttle_filter = 0.0;
    }

    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      pitch_target_temp = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (pitch_target_temp > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      AP_MotorsMulticopter_output_4a1(rtDW);
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      AP_MotorsMulticopter_output_4a1(rtDW);
    }
    break;

   case PathFollowMode:
    if (rtDW->PathMode_g != PathFollowMode) {
      rtDW->PathMode_g = PathFollowMode;
      rtDW->uavMode_j = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i_a - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    prev_WP_tmp = (int32_T)(rtDW->WP_i_a + 1.0) - 1;
    rtDW->next_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->next_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    get_distance_NE(rtDW->next_WP, rtDW->current_loc, AB, rtDW);
    if (norm(AB) < rtDW->L1_radius) {
      if (rtDW->loc.num[(int32_T)(rtDW->WP_i_a + 2.0) - 1] != 99.0) {
        rtDW->WP_i_a++;
      } else {
        rtDW->WP_i_a = 2.0;
      }
    }

    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    plane_run_4a1(rtDW);
    break;

   case GoHomeMode:
    if (rtDW->PathMode_g != GoHomeMode) {
      rtDW->PathMode_g = GoHomeMode;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i_a - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    rtDW->next_WP[0] = rtDW->loc.lat[0];
    rtDW->next_WP[1] = rtDW->loc.lon[0];
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    plane_run_4a1(rtDW);
    break;

   default:
    copter_run(rtDW);
    break;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void copter_run_4a1(DW *rtDW)
{
  real_T temp_yaw_rate;
  real_T b_pitch;
  real_T fwd_vel_error;
  if (fabs(rtDW->vel_desired[0]) > 0.0) {
    temp_yaw_rate = 0.0;
  } else if (fabs(rtDW->vel_desired[1]) > 0.0) {
    temp_yaw_rate = 0.0;
  } else if (fabs(rtDW->target_yaw_rate) > 0.0) {
    temp_yaw_rate = 0.0;
  } else {
    temp_yaw_rate = get_weathervane_yaw_rate_cds(rtDW);
  }

  b_pitch = rtDW->pitch_target / 100.0;
  fwd_vel_error = -(b_pitch - rtDW->vel_forward_min_pitch) / 15.0 * 0.3 * 0.5;
  if (b_pitch > 0.0) {
    fwd_vel_error = 0.0;
    rtDW->vel_forward_integrator *= 0.95;
  }

  rtDW->vel_forward_integrator += fwd_vel_error * rtDW->dt *
    rtDW->vel_forward_gain;
  b_pitch = rtDW->vel_forward_integrator;
  if (rtDW->vel_forward_integrator < 0.0) {
    rtDW->vel_forward_integrator = 0.0;
  }

  if (b_pitch > 0.4) {
    rtDW->vel_forward_integrator = 0.4;
  }

  update_vel_controller_xy(rtDW);
  update_z_controller(rtDW);
  input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
    rtDW->target_yaw_rate + temp_yaw_rate, rtDW);
  rate_controller_run(rtDW);
  rtDW->tail_tilt = 0.0;
  rtDW->k_throttle = rtDW->vel_forward_integrator;
  if (rtDW->aspeed > rtDW->aspeed_cp) {
    rtDW->nav_pitch_cd = rtDW->pitch_target;
    rtDW->nav_roll_cd = rtDW->roll_target;
    stabilize(rtDW);
    rtDW->k_aileron *= rtDW->p_plane_cp;
    rtDW->k_elevator *= rtDW->p_plane_cp;
    rtDW->k_rudder *= rtDW->p_plane_cp;
  } else {
    rtDW->k_aileron = 0.0;
    rtDW->k_elevator = 0.0;
    rtDW->k_rudder = 0.0;
  }

  AP_MotorsMulticopter_output_4a1(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void set_alt_target_from_climb_rat_m(real_T b_climb_rate_cms, real_T b_dt,
  real_T force_descend, real_T sign_in, DW *rtDW)
{
  real_T accel_z_cms;
  real_T jerk_z;
  real_T sign_in_0;
  accel_z_cms = rtDW->POSCONTROL_ACCEL_Z;
  if ((rtDW->vel_desired[2] < rtDW->POSCONTROL_SPEED_DOWN) &&
      (rtDW->POSCONTROL_SPEED_DOWN != 0.0)) {
    accel_z_cms = rtDW->POSCONTROL_ACCEL_Z * rtDW->POSCONTROL_OVERSPEED_GAIN_Z *
      rtDW->vel_desired[2] / rtDW->POSCONTROL_SPEED_DOWN;
  }

  if ((rtDW->vel_desired[2] > rtDW->POSCONTROL_SPEED_UP) &&
      (rtDW->POSCONTROL_SPEED_UP != 0.0)) {
    accel_z_cms = accel_z_cms * rtDW->POSCONTROL_OVERSPEED_GAIN_Z *
      rtDW->vel_desired[2] / rtDW->POSCONTROL_SPEED_UP;
  }

  jerk_z = accel_z_cms;
  if (accel_z_cms < 0.0) {
    accel_z_cms = 0.0;
  }

  if (jerk_z > 750.0) {
    accel_z_cms = 750.0;
  }

  jerk_z = accel_z_cms * rtDW->POSCONTROL_JERK_RATIO;
  if (sign_in < 0.0) {
    sign_in_0 = -1.0;
  } else if (sign_in > 0.0) {
    sign_in_0 = 1.0;
  } else if (sign_in == 0.0) {
    sign_in_0 = 0.0;
  } else {
    sign_in_0 = (rtNaN);
  }

  b_climb_rate_cms *= sign_in_0;
  rtDW->accel_last_z_cms += jerk_z * b_dt;
  rtDW->accel_last_z_cms = fmin(fmin(accel_z_cms, sqrt(fabs(rtDW->vel_desired[2]
    - b_climb_rate_cms) * 2.0 * jerk_z)), rtDW->accel_last_z_cms);
  jerk_z = rtDW->accel_last_z_cms * b_dt;
  accel_z_cms = rtDW->vel_desired[2] - jerk_z;
  jerk_z += rtDW->vel_desired[2];
  rtDW->vel_desired[2] = b_climb_rate_cms;
  if (b_climb_rate_cms < accel_z_cms) {
    rtDW->vel_desired[2] = accel_z_cms;
  }

  if (b_climb_rate_cms > jerk_z) {
    rtDW->vel_desired[2] = jerk_z;
  }

  rtDW->use_desvel_ff_z = 1.0;
  if ((rtDW->vel_desired[2] < 0.0) && ((!(rtDW->throttle_lower != 0.0)) ||
       (force_descend != 0.0))) {
    rtDW->pos_target[2] += rtDW->vel_desired[2] * b_dt;
  } else {
    if ((rtDW->vel_desired[2] > 0.0) && ((!(rtDW->throttle_upper != 0.0)) &&
         (!(rtDW->limit_pos_up != 0.0)))) {
      rtDW->pos_target[2] += rtDW->vel_desired[2] * b_dt;
    }
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void copter_run_posfree_4a1(DW *rtDW)
{
  update_z_controller(rtDW);
  rtDW->roll_target = 0.0;
  rtDW->pitch_target = 0.0;
  rtDW->target_yaw_rate = 0.0;
  input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
    rtDW->target_yaw_rate, rtDW);
  rate_controller_run(rtDW);
  rtDW->tail_tilt = 0.0;
  rtDW->k_aileron = 0.0;
  rtDW->k_elevator = 0.0;
  rtDW->k_rudder = 0.0;
  AP_MotorsMulticopter_output_4a1(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void auto_mode_sl_4a1(DW *rtDW)
{
  real_T pitch_target_temp;
  real_T throttle_in_error;
  real_T a[2];
  real_T b_high;
  if ((rtDW->PathModeOut_sl.flightTaskMode == HoverAdjustMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == TakeOffMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == LandMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == GoHomeMode)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  rtDW->take_off_land = ((rtDW->PathModeOut_sl.flightTaskMode == TakeOffMode) ||
    (rtDW->PathModeOut_sl.flightTaskMode == LandMode));
  if (rtDW->uavMode_d == 1.0) {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
    rtDW->vel_forward_integrator = 0.0;
  } else {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  }

  switch (rtDW->PathModeOut_sl.flightTaskMode) {
   case TakeOffMode:
    if ((rtDW->PathMode_d == GroundStandByMode) &&
        (rtDW->TakeOffMode_delay_flag_m == 0.0)) {
      rtDW->TakeOffMode_delay_m += rtDW->dt;
      rtDW->tail_tilt = 0.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->throttle_in = 0.1;
      rtDW->throttle_filter = 0.1;
      rtDW->pwm_out[0] = 1100.0;
      rtDW->pwm_out[1] = 1100.0;
      rtDW->pwm_out[2] = 1100.0;
      rtDW->pwm_out[3] = 1100.0;
      if (rtDW->TakeOffMode_delay_m > 1.0) {
        rtDW->TakeOffMode_delay_flag_m = 1.0;
      }
    } else {
      if (rtDW->PathMode_d != TakeOffMode) {
        rtDW->PathMode_d = TakeOffMode;
        rtDW->uavMode_d = 0.0;
        rtDW->vel_desired[2] = 0.0;
        rtDW->loc_origin[0] = rtDW->current_loc[0];
        rtDW->curr_pos[0] = 0.0;
        rtDW->pos_target[0] = 0.0;
        rtDW->loc_origin[1] = rtDW->current_loc[1];
        rtDW->curr_pos[1] = 0.0;
        rtDW->pos_target[1] = 0.0;
        from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
        rtDW->target_yaw_rate = 0.0;
      } else {
        get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a,
          rtDW);
        rtDW->curr_pos[0] = a[0] * 100.0;
        rtDW->curr_pos[1] = a[1] * 100.0;
      }

      if (rtDW->curr_alt < 100.0) {
        rtDW->POSCONTROL_ACC_Z_I = 0.0;
        rtDW->POSCONTROL_VEL_XY_I = 0.0;
        rtDW->ATC_RAT_PIT_I = 0.0;
        rtDW->ATC_RAT_RLL_I = 0.0;
        rtDW->ATC_RAT_YAW_I = 0.0;
        rtDW->pid_accel_z_reset_filter = 1.0;
        rtDW->pid_vel_xy_reset_filter = 1.0;
        rtDW->rate_pitch_pid_reset_filter = 1.0;
        rtDW->rate_roll_pid_reset_filter = 1.0;
        rtDW->rate_yaw_pid_reset_filter = 1.0;
      }

      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->pos_target[2] = rtDW->PathModeOut_sl.heightCmd;
      switch (rtDW->PathModeOut_sl.flightControlMode) {
       case RotorGoUpDownBySpeed:
        rtDW->take_off_land = 1.0;
        set_alt_target_from_climb_rat_m(rtDW->climb_rate_cms, rtDW->dt, 0.0, 1.0,
          rtDW);
        copter_run_4a1(rtDW);
        break;

       case SpotHoverMode:
        rtDW->take_off_land = 0.0;
        set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
          rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
        copter_run_4a1(rtDW);
        break;

       default:
        rtDW->take_off_land = 0.0;
        set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
          rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
        copter_run_4a1(rtDW);
        break;
      }
    }
    break;

   case LandMode:
    if (rtDW->PathMode_d != LandMode) {
      rtDW->PathMode_d = LandMode;
      rtDW->uavMode_d = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_m(rtDW->climb_rate_cms, rtDW->dt, 0.0, -1.0,
      rtDW);
    if (rtDW->PathModeOut_sl.flightControlMode ==
        RotorGoUpDownWithHorizonPosFree) {
      copter_run_posfree_4a1(rtDW);
    } else {
      copter_run_4a1(rtDW);
    }
    break;

   case HoverAdjustMode:
    if (rtDW->PathMode_d != HoverAdjustMode) {
      rtDW->PathMode_d = HoverAdjustMode;
      rtDW->uavMode_d = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    copter_run_4a1(rtDW);
    break;

   case HoverUpMode:
    if (rtDW->PathMode_d != HoverUpMode) {
      rtDW->PathMode_d = HoverUpMode;
      rtDW->uavMode_d = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
    rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run_4a1(rtDW);
    break;

   case HoverDownMode:
    if (rtDW->PathMode_d != HoverUpMode) {
      rtDW->PathMode_d = HoverUpMode;
      rtDW->uavMode_d = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
    rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    if (rtDW->PathModeOut_sl.rollCmd == 0.0) {
      rtDW->latAccDem = 0.0;
    }

    plane_run_4a1(rtDW);
    break;

   case AirStandByMode:
    if (rtDW->PathMode_d != HoverUpMode) {
      rtDW->PathMode_d = HoverUpMode;
      rtDW->uavMode_d = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
    rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run_4a1(rtDW);
    break;

   case Rotor2Fix_Mode:
    if (rtDW->PathMode_d != Rotor2Fix_Mode) {
      rtDW->PathMode_d = Rotor2Fix_Mode;
      rtDW->uavMode_d = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->roll_target = 0.0;
      rtDW->Rotor2Fix_delay_flag_i = 0.0;
    }

    if (rtDW->uavMode_d == 1.0) {
      if (rtDW->Rotor2Fix_delay_flag_i != 0.0) {
        rtDW->Rotor2Fix_delay_flag_i = 1.0;
        rtDW->nav_roll_cd = 0.0;
        update_50hz(rtDW);
        update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                              rtDW->aerodynamic_load_factor, rtDW);
        calc_nav_pitch(rtDW);
        rtDW->nav_pitch_cd = rtDW->pitch_target_c2p;
        pitch_target_temp = rtDW->throttle_cruise * 0.01 + rtDW->k_throttle_c2p;
        rtDW->k_throttle = pitch_target_temp;
        rtDW->throttle_dem = pitch_target_temp;
        rtDW->last_throttle_dem = pitch_target_temp;
        stabilize(rtDW);
        output_to_motors_plane_4a1(rtDW);
      } else {
        rtDW->inint_hgt = 1.0;
        rtDW->hgt_dem_cm = rtDW->height * 100.0;
        rtDW->k_throttle = rtDW->throttle_cruise * 0.01 + rtDW->k_throttle_c2p;
        rtDW->pitch_target = 0.0;
        input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = 0.0;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->throttle_in = 0.0;
        pitch_target_temp = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (pitch_target_temp > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output_4a1(rtDW);
        if (rtDW->throttle_filter < 0.1) {
          rtDW->Rotor2Fix_delay_flag_i = 1.0;
        }
      }
    } else {
      rtDW->k_throttle = rtDW->throttle_cruise * 0.01 + rtDW->k_throttle_c2p;
      if (rtDW->aspeed > rtDW->aspeed_c2ps) {
        rtDW->pitch_target = 0.0;
        input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = 0.0;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->throttle_in = 0.0;
        pitch_target_temp = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (pitch_target_temp > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output_4a1(rtDW);
        rtDW->uavMode_d = 1.0;
      } else if (rtDW->aspeed > rtDW->aspeed_c2p) {
        if (rtDW->pitch_target > 0.0) {
          rtDW->pitch_target = 0.0;
        }

        pitch_target_temp = rtDW->p_tilt_pitch_target * -3000.0 +
          rtDW->pitch_target;
        update_z_controller(rtDW);
        input_euler_angle_roll_pitch__o(rtDW->roll_target, pitch_target_temp,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = pitch_target_temp;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->k_aileron *= rtDW->p_plane_c2p;
        rtDW->k_elevator *= rtDW->p_plane_c2p;
        rtDW->k_rudder *= rtDW->p_plane_c2p;
        pitch_target_temp = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (pitch_target_temp > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output_4a1(rtDW);
      } else {
        if (rtDW->pitch_target > 0.0) {
          rtDW->pitch_target = 0.0;
        }

        update_z_controller(rtDW);
        input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target +
          rtDW->p_tilt_pitch_target * -3000.0, rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
        rtDW->k_aileron = 0.0;
        rtDW->k_elevator = 0.0;
        rtDW->k_rudder = 0.0;
        AP_MotorsMulticopter_output_4a1(rtDW);
      }
    }
    break;

   case Fix2Rotor_Mode:
    if (rtDW->PathMode_d != Fix2Rotor_Mode) {
      rtDW->PathMode_d = Fix2Rotor_Mode;
      rtDW->uavMode_d = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->tail_tilt = rtDW->tail_tilt_p2c;
      rtDW->roll_target = 0.0;
      rtDW->pitch_target = rtDW->pitch_target_p2c;
      rtDW->k_throttle = 0.0;
      rtDW->throttle_filter = 0.0;
    }

    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      pitch_target_temp = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (pitch_target_temp > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      AP_MotorsMulticopter_output_4a1(rtDW);
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      AP_MotorsMulticopter_output_4a1(rtDW);
    }
    break;

   case PathFollowMode:
    if (rtDW->PathMode_d != PathFollowMode) {
      rtDW->PathMode_d = PathFollowMode;
      rtDW->uavMode_d = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (pitch_target_temp > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (pitch_target_temp < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->prev_WP[0] = rtDW->PathModeOut_sl.prePathPoint_LLA[0];
    rtDW->next_WP[0] = rtDW->PathModeOut_sl.curPathPoint_LLA[0];
    rtDW->prev_WP[1] = rtDW->PathModeOut_sl.prePathPoint_LLA[1];
    rtDW->next_WP[1] = rtDW->PathModeOut_sl.curPathPoint_LLA[1];
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    plane_run_4a1(rtDW);
    break;

   case GoHomeMode:
    if (rtDW->PathMode_d != GoHomeMode) {
      rtDW->PathMode_d = GoHomeMode;
      rtDW->inint_hgt = 1.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    }

    switch ((int32_T)rtDW->uavMode_d) {
     case 1:
      if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
      }

      rtDW->prev_WP[0] = rtDW->center_WP[0];
      rtDW->next_WP[0] = rtDW->PathModeOut_sl.curPathPoint_LLA[0];
      rtDW->prev_WP[1] = rtDW->center_WP[1];
      rtDW->next_WP[1] = rtDW->PathModeOut_sl.curPathPoint_LLA[1];
      update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
      plane_run_4a1(rtDW);
      break;

     case 0:
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
      pitch_target_temp = rtDW->PathModeOut_sl.heightCmd - rtDW->pos_target[2];
      if (pitch_target_temp > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else if (pitch_target_temp < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->pos_target[2] = rtDW->PathModeOut_sl.heightCmd;
      }

      copter_run_4a1(rtDW);
      break;
    }
    break;

   case GroundStandByMode:
    if (rtDW->PathMode_d != GroundStandByMode) {
      rtDW->PathMode_d = GroundStandByMode;
      rtDW->throttle_in = rtDW->throttle_ground;
    }

    rtDW->TakeOffMode_delay_m = 0.0;
    rtDW->TakeOffMode_delay_flag_m = 0.0;
    rtDW->tail_tilt = 0.0;
    rtDW->k_aileron = 0.0;
    rtDW->k_elevator = 0.0;
    rtDW->k_rudder = 0.0;
    rtDW->k_throttle = 0.0;
    rtDW->roll_target = 0.0;
    rtDW->pitch_target = 0.0;
    rtDW->target_yaw_rate = 0.0;
    pitch_target_temp = -rtDW->throttle_off_rate * rtDW->dt;
    b_high = rtDW->throttle_off_rate * rtDW->dt;
    throttle_in_error = -rtDW->throttle_in;
    if (-rtDW->throttle_in < pitch_target_temp) {
      throttle_in_error = pitch_target_temp;
    }

    if (-rtDW->throttle_in > b_high) {
      throttle_in_error = b_high;
    }

    rtDW->throttle_in += throttle_in_error;
    rtDW->throttle_in = fmax(rtDW->throttle_in, 0.1);
    set_throttle_out(rtDW->throttle_in, 0.0,
                     rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ, rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case StallRecovery:
    if (rtDW->PathMode_d != StallRecovery) {
      rtDW->PathMode_d = StallRecovery;
      rtDW->uavMode_d = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->tail_tilt = rtDW->tail_tilt_p2c;
      rtDW->roll_target = 0.0;
      rtDW->pitch_target = rtDW->pitch_target_p2c;
    }

    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (fabs(-rtDW->tail_tilt) > 100.0) {
      rtDW->throttle_filter = 0.0;
      rtDW->throttle_in = 0.0;
    }

    pitch_target_temp = -rtDW->tail_tilt_rate * rtDW->dt;
    b_high = rtDW->tail_tilt_rate * rtDW->dt;
    throttle_in_error = -rtDW->tail_tilt;
    if (-rtDW->tail_tilt < pitch_target_temp) {
      throttle_in_error = pitch_target_temp;
    }

    if (-rtDW->tail_tilt > b_high) {
      throttle_in_error = b_high;
    }

    rtDW->tail_tilt += throttle_in_error;
    rtDW->nav_pitch_cd = rtDW->pitch_target;
    rtDW->nav_roll_cd = rtDW->roll_target;
    stabilize(rtDW);
    rtDW->k_aileron *= rtDW->p_plane_c2p;
    rtDW->k_elevator *= rtDW->p_plane_c2p;
    rtDW->k_rudder *= rtDW->p_plane_c2p;
    pitch_target_temp = rtDW->yaw_in;
    if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
      rtDW->yaw_in = -rtDW->yaw_max_c2p;
    }

    if (pitch_target_temp > rtDW->yaw_max_c2p) {
      rtDW->yaw_in = rtDW->yaw_max_c2p;
    }

    rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case VerticalMove:
    if (rtDW->PathMode_d != VerticalMove) {
      rtDW->PathMode_d = VerticalMove;
      rtDW->inint_hgt = 1.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    }

    switch ((int32_T)rtDW->uavMode_d) {
     case 1:
      if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
      }

      rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
      plane_run_4a1(rtDW);
      break;

     case 0:
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
      if (rtDW->PathModeOut_sl.heightCmd - rtDW->pos_target[2] > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else if (rtDW->PathModeOut_sl.heightCmd - rtDW->pos_target[2] < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->pos_target[2] = rtDW->PathModeOut_sl.heightCmd;
      }

      copter_run_4a1(rtDW);
      break;
    }
    break;

   default:
    copter_run_4a1(rtDW);
    break;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void run_V10(DW *rtDW)
{
  real_T temp_yaw_rate;
  real_T vel_desired_tmp;
  real_T tmp[2];
  int32_T prev_WP_tmp;
  if ((rtDW->mode == 1.0) || (rtDW->mode == 2.0) || (rtDW->mode == 3.0) ||
      (rtDW->mode == 7.0)) {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  } else {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
  }

  if ((rtDW->mode_state_j == 3.0) || (rtDW->mode_state_j == 9.0) ||
      (rtDW->mode_state_j == 10.0)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  if (rtDW->inint != 0.0) {
    setup_motors_4a1(rtDW);
    rtDW->inint = 0.0;
  }

  updata_cl(rtDW);
  rtDW->arspeed_temp += rtDW->dt / (1.0 / (6.2831853071795862 *
    rtDW->arspeed_filt) + rtDW->dt) * (rtDW->aspeed - rtDW->arspeed_temp);
  rtDW->aspeed = rtDW->arspeed_temp;
  rtDW->tail_tilt = 0.0;
  switch ((int32_T)rtDW->mode) {
   case 1:
    if (rtDW->mode_state_j != 1.0) {
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->mode_state_j = 1.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->k_throttle = 0.0;
    }

    set_throttle_out(rtDW->throttle_in, 1.0,
                     rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ, rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 2:
    if (rtDW->mode_state_j != 2.0) {
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state_j = 2.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->k_throttle = 0.0;
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 3:
    if (rtDW->mode_state_j != 3.0) {
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state_j = 3.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->k_throttle = 0.0;
    } else {
      temp_yaw_rate = cos(rtDW->loc_origin[0] * 1.0E-7 / rtDW->HD);
      if (temp_yaw_rate < 0.01) {
        temp_yaw_rate = 0.01;
      }

      rtDW->curr_pos[0] = (rtDW->current_loc[0] - rtDW->loc_origin[0]) *
        rtDW->LOCATION_SCALING_FACTOR * 100.0;
      rtDW->curr_pos[1] = (rtDW->current_loc[1] - rtDW->loc_origin[1]) *
        rtDW->LOCATION_SCALING_FACTOR * temp_yaw_rate * 100.0;
    }

    temp_yaw_rate = sin(rtDW->yaw);
    vel_desired_tmp = cos(rtDW->yaw);
    rtDW->vel_desired[0] = rtDW->pitch_target_pilot / 10.0 * vel_desired_tmp -
      rtDW->roll_target_pilot / 10.0 * temp_yaw_rate;
    rtDW->vel_desired[1] = rtDW->pitch_target_pilot / 10.0 * temp_yaw_rate +
      rtDW->roll_target_pilot / 10.0 * vel_desired_tmp;
    if (fabs(rtDW->pitch_target_pilot) > 0.0) {
      temp_yaw_rate = 0.0;
    } else if (fabs(rtDW->roll_target_pilot) > 0.0) {
      temp_yaw_rate = 0.0;
    } else if (fabs(rtDW->target_yaw_rate) > 0.0) {
      temp_yaw_rate = 0.0;
    } else {
      temp_yaw_rate = get_weathervane_yaw_rate_cds(rtDW);
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_vel_controller_xy(rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate + temp_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 4:
    if (rtDW->mode_state_j != 4.0) {
      rtDW->mode_state_j = 4.0;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 5:
    if (rtDW->mode_state_j != 5.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->mode_state_j = 5.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 6:
    if (rtDW->mode_state_j != 6.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->mode_state_j = 6.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i_m - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    prev_WP_tmp = (int32_T)(rtDW->WP_i_m + 1.0) - 1;
    rtDW->next_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->next_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    temp_yaw_rate = cos(rtDW->current_loc[0] * 1.0E-7 / rtDW->HD);
    if (temp_yaw_rate < 0.01) {
      temp_yaw_rate = 0.01;
    }

    tmp[0] = (rtDW->next_WP[0] - rtDW->current_loc[0]) *
      rtDW->LOCATION_SCALING_FACTOR;
    tmp[1] = (rtDW->next_WP[1] - rtDW->current_loc[1]) *
      rtDW->LOCATION_SCALING_FACTOR * temp_yaw_rate;
    if (norm(tmp) < rtDW->L1_radius) {
      if (rtDW->loc.num[(int32_T)(rtDW->WP_i_m + 2.0) - 1] != 99.0) {
        rtDW->WP_i_m++;
      } else {
        rtDW->WP_i_m = 2.0;
      }
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 7:
    if (rtDW->mode_state_j != 7.0) {
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state_j = 7.0;
      rtDW->k_throttle = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      temp_yaw_rate = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (temp_yaw_rate > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
    }

    rtDW->k_throttle = rtDW->throttle_dem;
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 8:
    if (rtDW->mode_state_j != 8.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->mode_state_j = 8.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 9:
    if (rtDW->mode_state_j != 9.0) {
      rtDW->mode_state_j = 9.0;
    }

    auto_mode_4a1(rtDW);
    break;

   case 10:
    if (rtDW->mode_state_j != 10.0) {
      rtDW->mode_state_j = 10.0;
    }

    auto_mode_sl_4a1(rtDW);
    break;

   default:
    rtDW->mode_state_j = rtDW->mode;
    break;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void setup_motors(DW *rtDW)
{
  rtDW->roll_factor[0] = -0.70710678118654746;
  rtDW->pitch_factor[0] = 0.70710678118654757;
  rtDW->yaw_factor[0] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CW;
  rtDW->roll_factor[1] = 0.70710678118654757;
  rtDW->pitch_factor[1] = -0.70710678118654746;
  rtDW->yaw_factor[1] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CW * 2.5599;
  rtDW->roll_factor[2] = 0.70710678118654757;
  rtDW->pitch_factor[2] = 0.70710678118654757;
  rtDW->yaw_factor[2] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CCW;
  rtDW->roll_factor[3] = -0.70710678118654768;
  rtDW->pitch_factor[3] = -0.70710678118654746;
  rtDW->yaw_factor[3] = rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CCW * 2.5599;
  rtDW->pitch_factor[3] *= rtDW->Kx + 1.0;
  rtDW->pitch_factor[0] *= 1.0 - rtDW->Kx;
  rtDW->pitch_factor[1] *= rtDW->Kx + 1.0;
  rtDW->pitch_factor[2] *= 1.0 - rtDW->Kx;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void output_to_motors_plane(DW *rtDW)
{
  real_T thrust_dt;
  real_T pwm_out_temp;
  real_T low;
  real_T thrust_dt_tmp;
  rtDW->tail_tilt = -9556.0;
  thrust_dt_tmp = rtDW->pwm_max - rtDW->pwm_min;
  thrust_dt = thrust_dt_tmp * rtDW->dt / rtDW->thrust_slew_time;
  thrust_dt_tmp = thrust_dt_tmp * rtDW->k_throttle + rtDW->pwm_min;
  low = rtDW->pwm_out[1] - thrust_dt;
  pwm_out_temp = rtDW->pwm_out[1] + thrust_dt;
  rtDW->pwm_out[1] = thrust_dt_tmp;
  if (thrust_dt_tmp < low) {
    rtDW->pwm_out[1] = low;
  }

  if (thrust_dt_tmp > pwm_out_temp) {
    rtDW->pwm_out[1] = pwm_out_temp;
  }

  pwm_out_temp = rtDW->pwm_out[1];
  if (rtDW->pwm_out[1] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[1] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[1] = pwm_out_temp;
  low = rtDW->pwm_out[3] - thrust_dt;
  pwm_out_temp = rtDW->pwm_out[3] + thrust_dt;
  rtDW->pwm_out[3] = thrust_dt_tmp;
  if (thrust_dt_tmp < low) {
    rtDW->pwm_out[3] = low;
  }

  if (thrust_dt_tmp > pwm_out_temp) {
    rtDW->pwm_out[3] = pwm_out_temp;
  }

  pwm_out_temp = rtDW->pwm_out[3];
  if (rtDW->pwm_out[3] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[3] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[3] = pwm_out_temp;
  pwm_out_temp = rtDW->pwm_out[0] - thrust_dt;
  low = rtDW->pwm_out[0] + thrust_dt;
  rtDW->pwm_out[0] = rtDW->pwm_min;
  if (rtDW->pwm_min < pwm_out_temp) {
    rtDW->pwm_out[0] = pwm_out_temp;
  }

  if (rtDW->pwm_min > low) {
    rtDW->pwm_out[0] = low;
  }

  pwm_out_temp = rtDW->pwm_out[0];
  if (rtDW->pwm_out[0] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[0] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[0] = pwm_out_temp;
  pwm_out_temp = rtDW->pwm_out[2] - thrust_dt;
  low = rtDW->pwm_out[2] + thrust_dt;
  rtDW->pwm_out[2] = rtDW->pwm_min;
  if (rtDW->pwm_min < pwm_out_temp) {
    rtDW->pwm_out[2] = pwm_out_temp;
  }

  if (rtDW->pwm_min > low) {
    rtDW->pwm_out[2] = low;
  }

  pwm_out_temp = rtDW->pwm_out[2];
  if (rtDW->pwm_out[2] < rtDW->pwm_min) {
    pwm_out_temp = rtDW->pwm_min;
  }

  if (rtDW->pwm_out[2] > rtDW->pwm_max) {
    pwm_out_temp = rtDW->pwm_max;
  }

  rtDW->pwm_out[2] = pwm_out_temp;
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void plane_run(DW *rtDW)
{
  real_T commanded_pitch;
  update_50hz(rtDW);
  update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                        rtDW->aerodynamic_load_factor, rtDW);
  commanded_pitch = rtDW->pitch_dem * rtDW->HD * 100.0;
  rtDW->nav_pitch_cd = commanded_pitch;
  if (commanded_pitch < rtDW->pitch_limit_min_cd) {
    rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
  }

  if (commanded_pitch > rtDW->pitch_limit_max_cd) {
    rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
  }

  calc_nav_roll(rtDW);
  rtDW->k_throttle = rtDW->throttle_dem;
  stabilize(rtDW);
  output_to_motors_plane(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void auto_mode(DW *rtDW)
{
  real_T tail_error;
  real_T AB[2];
  real_T amt;
  real_T low;
  real_T high;
  int32_T prev_WP_tmp;
  if ((rtDW->PathModeOut_sl.flightTaskMode == HoverAdjustMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == TakeOffMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == LandMode)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  if (rtDW->uavMode == 1.0) {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
  } else {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  }

  switch (rtDW->PathModeOut_sl.flightTaskMode) {
   case TakeOffMode:
    if (rtDW->PathMode != TakeOffMode) {
      rtDW->PathMode = TakeOffMode;
      rtDW->uavMode = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, AB, rtDW);
      rtDW->curr_pos[0] = AB[0] * 100.0;
      rtDW->curr_pos[1] = AB[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    copter_run(rtDW);
    break;

   case LandMode:
    if (rtDW->PathMode != LandMode) {
      rtDW->PathMode = LandMode;
      rtDW->uavMode = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, AB, rtDW);
      rtDW->curr_pos[0] = AB[0] * 100.0;
      rtDW->curr_pos[1] = AB[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    copter_run(rtDW);
    break;

   case HoverAdjustMode:
    if (rtDW->PathMode != HoverAdjustMode) {
      rtDW->PathMode = HoverAdjustMode;
      rtDW->uavMode = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, AB, rtDW);
      rtDW->curr_pos[0] = AB[0] * 100.0;
      rtDW->curr_pos[1] = AB[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    rtDW->vel_desired[0] = rtDW->PathModeOut_sl.groundspeedCmd * cos(rtDW->yaw);
    rtDW->vel_desired[1] = rtDW->PathModeOut_sl.groundspeedCmd * sin(rtDW->yaw);
    copter_run(rtDW);
    break;

   case HoverUpMode:
    if (rtDW->PathMode != HoverUpMode) {
      rtDW->PathMode = HoverUpMode;
      rtDW->uavMode = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run(rtDW);
    break;

   case HoverDownMode:
    if (rtDW->PathMode != HoverUpMode) {
      rtDW->PathMode = HoverUpMode;
      rtDW->uavMode = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    if (rtDW->PathModeOut_sl.rollCmd == 0.0) {
      rtDW->latAccDem = 0.0;
    }

    plane_run(rtDW);
    break;

   case AirStandByMode:
    if (rtDW->PathMode != HoverUpMode) {
      rtDW->PathMode = HoverUpMode;
      rtDW->uavMode = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run(rtDW);
    break;

   case Rotor2Fix_Mode:
    if (rtDW->PathMode != Rotor2Fix_Mode) {
      rtDW->PathMode = Rotor2Fix_Mode;
      rtDW->uavMode = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->roll_target = 0.0;
      rtDW->Rotor2Fix_delay_flag = 0.0;
      rtDW->Rotor2Fix_delay = 0.0;
    }

    tail_error = rtDW->tail_tilt_c2p - rtDW->tail_tilt;
    amt = tail_error;
    low = -rtDW->tail_tilt_rate * rtDW->dt;
    high = rtDW->tail_tilt_rate * rtDW->dt;
    if (tail_error < low) {
      tail_error = low;
    }

    if (amt > high) {
      tail_error = high;
    }

    rtDW->tail_tilt += tail_error;
    if (rtDW->uavMode == 1.0) {
      if (rtDW->Rotor2Fix_delay_flag != 0.0) {
        rtDW->Rotor2Fix_delay_flag = 1.0;
        rtDW->nav_roll_cd = 0.0;
        update_50hz(rtDW);
        update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                              rtDW->aerodynamic_load_factor, rtDW);
        calc_nav_pitch(rtDW);
        rtDW->k_throttle = rtDW->throttle_dem;
        stabilize(rtDW);
        output_to_motors_plane(rtDW);
      } else {
        rtDW->inint_hgt = 1.0;
        rtDW->hgt_dem_cm = rtDW->height * 100.0;
        rtDW->pitch_target = 0.0;
        input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = 0.0;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->throttle_in = 0.0;
        tail_error = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (tail_error > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output(rtDW);
        if (rtDW->throttle_filter < 0.1) {
          rtDW->tail_tilt = -9556.0;
          rtDW->Rotor2Fix_delay += rtDW->dt;
          if (rtDW->Rotor2Fix_delay > 0.2) {
            rtDW->Rotor2Fix_delay_flag = 1.0;
          }
        }
      }
    } else if (rtDW->aspeed > rtDW->aspeed_c2ps) {
      rtDW->pitch_target = 0.0;
      input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
        rtDW->target_yaw_rate, rtDW);
      rate_controller_run(rtDW);
      rtDW->nav_pitch_cd = 0.0;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->throttle_in = 0.0;
      tail_error = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (tail_error > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
      AP_MotorsMulticopter_output(rtDW);
      rtDW->uavMode = 1.0;
    } else if (rtDW->aspeed > rtDW->aspeed_c2p) {
      tail_error = rtDW->tail_tilt;
      if (rtDW->tail_tilt < -3000.0) {
        tail_error = -3000.0;
      }

      if (rtDW->tail_tilt > 700.0) {
        tail_error = 700.0;
      }

      if (rtDW->pitch_target > 0.0) {
        rtDW->pitch_target = 0.0;
      }

      tail_error = rtDW->p_tilt_pitch_target * tail_error + rtDW->pitch_target;
      update_z_controller(rtDW);
      input_euler_angle_roll_pitch__o(rtDW->roll_target, tail_error,
        rtDW->target_yaw_rate, rtDW);
      rate_controller_run(rtDW);
      rtDW->nav_pitch_cd = tail_error;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      tail_error = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (tail_error > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
      AP_MotorsMulticopter_output(rtDW);
    } else {
      tail_error = rtDW->tail_tilt;
      if (rtDW->tail_tilt < -3000.0) {
        tail_error = -3000.0;
      }

      if (rtDW->tail_tilt > 700.0) {
        tail_error = 700.0;
      }

      if (rtDW->pitch_target > 0.0) {
        rtDW->pitch_target = 0.0;
      }

      update_z_controller(rtDW);
      input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target +
        rtDW->p_tilt_pitch_target * tail_error, rtDW->target_yaw_rate, rtDW);
      rate_controller_run(rtDW);
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      AP_MotorsMulticopter_output(rtDW);
    }
    break;

   case Fix2Rotor_Mode:
    if (rtDW->PathMode != Fix2Rotor_Mode) {
      rtDW->PathMode = Fix2Rotor_Mode;
      rtDW->uavMode = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->tail_tilt = rtDW->tail_tilt_p2c;
      rtDW->roll_target = 0.0;
      rtDW->pitch_target = 0.0;
    }

    update_z_controller(rtDW);
    tail_error = rtDW->tail_tilt;
    if (rtDW->tail_tilt < -3000.0) {
      tail_error = -3000.0;
    }

    if (rtDW->tail_tilt > 700.0) {
      tail_error = 700.0;
    }

    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target +
      rtDW->p_tilt_pitch_target * tail_error, rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (fabs(-rtDW->tail_tilt) > 100.0) {
      rtDW->throttle_filter = 0.0;
      rtDW->throttle_in = 0.0;
    }

    amt = -rtDW->tail_tilt_rate * rtDW->dt;
    low = rtDW->tail_tilt_rate * rtDW->dt;
    tail_error = -rtDW->tail_tilt;
    if (-rtDW->tail_tilt < amt) {
      tail_error = amt;
    }

    if (-rtDW->tail_tilt > low) {
      tail_error = low;
    }

    rtDW->tail_tilt += tail_error;
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      tail_error = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (tail_error > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
      AP_MotorsMulticopter_output(rtDW);
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      AP_MotorsMulticopter_output(rtDW);
    }
    break;

   case PathFollowMode:
    if (rtDW->PathMode != PathFollowMode) {
      rtDW->PathMode = PathFollowMode;
      rtDW->uavMode = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i_o - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    prev_WP_tmp = (int32_T)(rtDW->WP_i_o + 1.0) - 1;
    rtDW->next_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->next_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    get_distance_NE(rtDW->next_WP, rtDW->current_loc, AB, rtDW);
    if (norm(AB) < rtDW->L1_radius) {
      if (rtDW->loc.num[(int32_T)(rtDW->WP_i_o + 2.0) - 1] != 99.0) {
        rtDW->WP_i_o++;
      } else {
        rtDW->WP_i_o = 2.0;
      }
    }

    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    plane_run(rtDW);
    break;

   case GoHomeMode:
    if (rtDW->PathMode != GoHomeMode) {
      rtDW->PathMode = GoHomeMode;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i_o - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    rtDW->next_WP[0] = rtDW->loc.lat[0];
    rtDW->next_WP[1] = rtDW->loc.lon[0];
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    plane_run(rtDW);
    break;

   default:
    copter_run(rtDW);
    break;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void copter_run_posfree(DW *rtDW)
{
  update_z_controller(rtDW);
  rtDW->roll_target = 0.0;
  rtDW->pitch_target = 0.0;
  rtDW->target_yaw_rate = 0.0;
  input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
    rtDW->target_yaw_rate, rtDW);
  rate_controller_run(rtDW);
  rtDW->tail_tilt = 0.0;
  rtDW->k_aileron = 0.0;
  rtDW->k_elevator = 0.0;
  rtDW->k_rudder = 0.0;
  AP_MotorsMulticopter_output(rtDW);
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void auto_mode_sl(DW *rtDW)
{
  real_T tail_error;
  real_T throttle_in_error;
  real_T a[2];
  real_T amt;
  real_T high;
  if ((rtDW->PathModeOut_sl.flightTaskMode == HoverAdjustMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == TakeOffMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == LandMode) ||
      (rtDW->PathModeOut_sl.flightTaskMode == GoHomeMode)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  rtDW->take_off_land = ((rtDW->PathModeOut_sl.flightTaskMode == TakeOffMode) ||
    (rtDW->PathModeOut_sl.flightTaskMode == LandMode));
  if (rtDW->uavMode_p == 1.0) {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
    rtDW->vel_forward_integrator = 0.0;
  } else {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  }

  switch (rtDW->PathModeOut_sl.flightTaskMode) {
   case TakeOffMode:
    if ((rtDW->PathMode_j == GroundStandByMode) && (rtDW->TakeOffMode_delay_flag
         == 0.0)) {
      rtDW->TakeOffMode_delay += rtDW->dt;
      rtDW->tail_tilt = 0.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->throttle_in = 0.1;
      rtDW->throttle_filter = 0.1;
      rtDW->pwm_out[0] = 1100.0;
      rtDW->pwm_out[1] = 1100.0;
      rtDW->pwm_out[2] = 1100.0;
      rtDW->pwm_out[3] = 1100.0;
      if (rtDW->TakeOffMode_delay > 1.0) {
        rtDW->TakeOffMode_delay_flag = 1.0;
      }
    } else {
      if (rtDW->PathMode_j != TakeOffMode) {
        rtDW->PathMode_j = TakeOffMode;
        rtDW->uavMode_p = 0.0;
        rtDW->vel_desired[2] = 0.0;
        rtDW->loc_origin[0] = rtDW->current_loc[0];
        rtDW->curr_pos[0] = 0.0;
        rtDW->pos_target[0] = 0.0;
        rtDW->loc_origin[1] = rtDW->current_loc[1];
        rtDW->curr_pos[1] = 0.0;
        rtDW->pos_target[1] = 0.0;
        from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
        rtDW->target_yaw_rate = 0.0;
      } else {
        get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a,
          rtDW);
        rtDW->curr_pos[0] = a[0] * 100.0;
        rtDW->curr_pos[1] = a[1] * 100.0;
      }

      if (rtDW->curr_alt < 100.0) {
        rtDW->POSCONTROL_ACC_Z_I = 0.0;
        rtDW->POSCONTROL_VEL_XY_I = 0.0;
        rtDW->ATC_RAT_PIT_I = 0.0;
        rtDW->ATC_RAT_RLL_I = 0.0;
        rtDW->ATC_RAT_YAW_I = 0.0;
        rtDW->pid_accel_z_reset_filter = 1.0;
        rtDW->pid_vel_xy_reset_filter = 1.0;
        rtDW->rate_pitch_pid_reset_filter = 1.0;
        rtDW->rate_roll_pid_reset_filter = 1.0;
        rtDW->rate_yaw_pid_reset_filter = 1.0;
      }

      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->pos_target[2] = rtDW->PathModeOut_sl.heightCmd;
      switch (rtDW->PathModeOut_sl.flightControlMode) {
       case RotorGoUpDownBySpeed:
        rtDW->take_off_land = 1.0;
        set_alt_target_from_climb_rat_m(rtDW->climb_rate_cms, rtDW->dt, 0.0, 1.0,
          rtDW);
        copter_run(rtDW);
        break;

       case SpotHoverMode:
        rtDW->take_off_land = 0.0;
        set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
          rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
        copter_run(rtDW);
        break;

       default:
        rtDW->take_off_land = 0.0;
        set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
          rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
        copter_run(rtDW);
        break;
      }
    }
    break;

   case LandMode:
    if (rtDW->PathMode_j != LandMode) {
      rtDW->PathMode_j = LandMode;
      rtDW->uavMode_p = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_m(rtDW->climb_rate_cms, rtDW->dt, 0.0, -1.0,
      rtDW);
    if (rtDW->PathModeOut_sl.flightControlMode ==
        RotorGoUpDownWithHorizonPosFree) {
      copter_run_posfree(rtDW);
    } else {
      copter_run(rtDW);
    }
    break;

   case HoverAdjustMode:
    if (rtDW->PathMode_j != HoverAdjustMode) {
      rtDW->PathMode_j = HoverAdjustMode;
      rtDW->uavMode_p = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    } else {
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
    }

    rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
    set_alt_target_from_climb_rat_a(rtDW->PathModeOut_sl.heightCmd,
      rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    copter_run(rtDW);
    break;

   case HoverUpMode:
    if (rtDW->PathMode_j != HoverUpMode) {
      rtDW->PathMode_j = HoverUpMode;
      rtDW->uavMode_p = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
    rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run(rtDW);
    break;

   case HoverDownMode:
    if (rtDW->PathMode_j != HoverUpMode) {
      rtDW->PathMode_j = HoverUpMode;
      rtDW->uavMode_p = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
    rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    if (rtDW->PathModeOut_sl.rollCmd == 0.0) {
      rtDW->latAccDem = 0.0;
    }

    plane_run(rtDW);
    break;

   case AirStandByMode:
    if (rtDW->PathMode_j != HoverUpMode) {
      rtDW->PathMode_j = HoverUpMode;
      rtDW->uavMode_p = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
    rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    plane_run(rtDW);
    break;

   case Rotor2Fix_Mode:
    if (rtDW->PathMode_j != Rotor2Fix_Mode) {
      rtDW->PathMode_j = Rotor2Fix_Mode;
      rtDW->uavMode_p = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->inint_hgt = 1.0;
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->roll_target = 0.0;
      rtDW->Rotor2Fix_delay_flag_h = 0.0;
      rtDW->Rotor2Fix_delay_b = 0.0;
    }

    tail_error = rtDW->tail_tilt_c2p - rtDW->tail_tilt;
    amt = tail_error;
    throttle_in_error = -rtDW->tail_tilt_rate * rtDW->dt;
    high = rtDW->tail_tilt_rate * rtDW->dt;
    if (tail_error < throttle_in_error) {
      tail_error = throttle_in_error;
    }

    if (amt > high) {
      tail_error = high;
    }

    rtDW->tail_tilt += tail_error;
    if (rtDW->uavMode_p == 1.0) {
      if (rtDW->Rotor2Fix_delay_flag_h != 0.0) {
        rtDW->Rotor2Fix_delay_flag_h = 1.0;
        rtDW->nav_roll_cd = 0.0;
        update_50hz(rtDW);
        update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                              rtDW->aerodynamic_load_factor, rtDW);
        calc_nav_pitch(rtDW);
        rtDW->nav_pitch_cd = rtDW->pitch_target_c2p;
        tail_error = rtDW->throttle_cruise * 0.01 + rtDW->k_throttle_c2p;
        rtDW->k_throttle = tail_error;
        rtDW->throttle_dem = tail_error;
        rtDW->last_throttle_dem = tail_error;
        stabilize(rtDW);
        output_to_motors_plane(rtDW);
      } else {
        rtDW->inint_hgt = 1.0;
        rtDW->hgt_dem_cm = rtDW->height * 100.0;
        rtDW->pitch_target = 0.0;
        input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
          rtDW->target_yaw_rate, rtDW);
        rate_controller_run(rtDW);
        rtDW->nav_pitch_cd = 0.0;
        rtDW->nav_roll_cd = rtDW->roll_target;
        stabilize(rtDW);
        rtDW->throttle_in = 0.0;
        tail_error = rtDW->yaw_in;
        if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
          rtDW->yaw_in = -rtDW->yaw_max_c2p;
        }

        if (tail_error > rtDW->yaw_max_c2p) {
          rtDW->yaw_in = rtDW->yaw_max_c2p;
        }

        rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
        AP_MotorsMulticopter_output(rtDW);
        if (rtDW->throttle_filter < 0.1) {
          rtDW->tail_tilt = -9556.0;
          rtDW->Rotor2Fix_delay_b += rtDW->dt;
          if (rtDW->Rotor2Fix_delay_b > 0.2) {
            rtDW->Rotor2Fix_delay_flag_h = 1.0;
          }
        }
      }
    } else if (rtDW->aspeed > rtDW->aspeed_c2ps) {
      rtDW->pitch_target = 0.0;
      input_euler_angle_roll_pitch__o(rtDW->roll_target, 0.0,
        rtDW->target_yaw_rate, rtDW);
      rate_controller_run(rtDW);
      rtDW->nav_pitch_cd = 0.0;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->throttle_in = 0.0;
      tail_error = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (tail_error > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
      AP_MotorsMulticopter_output(rtDW);
      rtDW->uavMode_p = 1.0;
    } else if (rtDW->aspeed > rtDW->aspeed_c2p) {
      tail_error = rtDW->tail_tilt;
      if (rtDW->tail_tilt < -3000.0) {
        tail_error = -3000.0;
      }

      if (rtDW->tail_tilt > 700.0) {
        tail_error = 700.0;
      }

      if (rtDW->pitch_target > 0.0) {
        rtDW->pitch_target = 0.0;
      }

      tail_error = rtDW->p_tilt_pitch_target * tail_error + rtDW->pitch_target;
      update_z_controller(rtDW);
      input_euler_angle_roll_pitch__o(rtDW->roll_target, tail_error,
        rtDW->target_yaw_rate, rtDW);
      rate_controller_run(rtDW);
      rtDW->nav_pitch_cd = tail_error;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      tail_error = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (tail_error > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
      AP_MotorsMulticopter_output(rtDW);
    } else {
      tail_error = rtDW->tail_tilt;
      if (rtDW->tail_tilt < -3000.0) {
        tail_error = -3000.0;
      }

      if (rtDW->tail_tilt > 700.0) {
        tail_error = 700.0;
      }

      if (rtDW->pitch_target > 0.0) {
        rtDW->pitch_target = 0.0;
      }

      update_z_controller(rtDW);
      input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target +
        rtDW->p_tilt_pitch_target * tail_error, rtDW->target_yaw_rate, rtDW);
      rate_controller_run(rtDW);
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      AP_MotorsMulticopter_output(rtDW);
    }
    break;

   case Fix2Rotor_Mode:
    if (rtDW->PathMode_j != Fix2Rotor_Mode) {
      rtDW->PathMode_j = Fix2Rotor_Mode;
      rtDW->uavMode_p = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->tail_tilt = rtDW->tail_tilt_p2c;
      rtDW->roll_target = 0.0;
      rtDW->pitch_target = rtDW->pitch_target_p2c;
    }

    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (fabs(-rtDW->tail_tilt) > 100.0) {
      rtDW->throttle_filter = 0.0;
      rtDW->throttle_in = 0.0;
    }

    amt = -rtDW->tail_tilt_rate * rtDW->dt;
    throttle_in_error = rtDW->tail_tilt_rate * rtDW->dt;
    tail_error = -rtDW->tail_tilt;
    if (-rtDW->tail_tilt < amt) {
      tail_error = amt;
    }

    if (-rtDW->tail_tilt > throttle_in_error) {
      tail_error = throttle_in_error;
    }

    rtDW->tail_tilt += tail_error;
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      tail_error = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (tail_error > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      AP_MotorsMulticopter_output(rtDW);
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      AP_MotorsMulticopter_output(rtDW);
    }
    break;

   case PathFollowMode:
    if (rtDW->PathMode_j != PathFollowMode) {
      rtDW->PathMode_j = PathFollowMode;
      rtDW->uavMode_p = 1.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
    }

    tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm;
    if (tail_error > 8.0) {
      rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else if (tail_error < -8.0) {
      rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    } else {
      rtDW->climb_rate_cms = 0.0;
      rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
    }

    rtDW->prev_WP[0] = rtDW->PathModeOut_sl.prePathPoint_LLA[0];
    rtDW->next_WP[0] = rtDW->PathModeOut_sl.curPathPoint_LLA[0];
    rtDW->prev_WP[1] = rtDW->PathModeOut_sl.prePathPoint_LLA[1];
    rtDW->next_WP[1] = rtDW->PathModeOut_sl.curPathPoint_LLA[1];
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    plane_run(rtDW);
    break;

   case GoHomeMode:
    if (rtDW->PathMode_j != GoHomeMode) {
      rtDW->PathMode_j = GoHomeMode;
      rtDW->inint_hgt = 1.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    }

    switch ((int32_T)rtDW->uavMode_p) {
     case 1:
      if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
      }

      rtDW->prev_WP[0] = rtDW->center_WP[0];
      rtDW->next_WP[0] = rtDW->PathModeOut_sl.curPathPoint_LLA[0];
      rtDW->prev_WP[1] = rtDW->center_WP[1];
      rtDW->next_WP[1] = rtDW->PathModeOut_sl.curPathPoint_LLA[1];
      update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
      plane_run(rtDW);
      break;

     case 0:
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
      tail_error = rtDW->PathModeOut_sl.heightCmd - rtDW->pos_target[2];
      if (tail_error > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else if (tail_error < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->pos_target[2] = rtDW->PathModeOut_sl.heightCmd;
      }

      copter_run(rtDW);
      break;
    }
    break;

   case GroundStandByMode:
    if (rtDW->PathMode_j != GroundStandByMode) {
      rtDW->PathMode_j = GroundStandByMode;
      rtDW->throttle_in = rtDW->throttle_ground;
    }

    rtDW->TakeOffMode_delay = 0.0;
    rtDW->TakeOffMode_delay_flag = 0.0;
    rtDW->tail_tilt = 0.0;
    rtDW->k_aileron = 0.0;
    rtDW->k_elevator = 0.0;
    rtDW->k_rudder = 0.0;
    rtDW->roll_target = 0.0;
    rtDW->pitch_target = 0.0;
    rtDW->target_yaw_rate = 0.0;
    tail_error = -rtDW->throttle_off_rate * rtDW->dt;
    amt = rtDW->throttle_off_rate * rtDW->dt;
    throttle_in_error = -rtDW->throttle_in;
    if (-rtDW->throttle_in < tail_error) {
      throttle_in_error = tail_error;
    }

    if (-rtDW->throttle_in > amt) {
      throttle_in_error = amt;
    }

    rtDW->throttle_in += throttle_in_error;
    rtDW->throttle_in = fmax(rtDW->throttle_in, 0.1);
    set_throttle_out(rtDW->throttle_in, 0.0,
                     rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ, rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output(rtDW);
    break;

   case StallRecovery:
    if (rtDW->PathMode_j != StallRecovery) {
      rtDW->PathMode_j = StallRecovery;
      rtDW->uavMode_p = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
      rtDW->tail_tilt = rtDW->tail_tilt_p2c;
      rtDW->roll_target = 0.0;
      rtDW->pitch_target = rtDW->pitch_target_p2c;
    }

    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (fabs(-rtDW->tail_tilt) > 100.0) {
      rtDW->throttle_filter = 0.0;
      rtDW->throttle_in = 0.0;
    }

    amt = -rtDW->tail_tilt_rate * rtDW->dt;
    throttle_in_error = rtDW->tail_tilt_rate * rtDW->dt;
    tail_error = -rtDW->tail_tilt;
    if (-rtDW->tail_tilt < amt) {
      tail_error = amt;
    }

    if (-rtDW->tail_tilt > throttle_in_error) {
      tail_error = throttle_in_error;
    }

    rtDW->tail_tilt += tail_error;
    rtDW->nav_pitch_cd = rtDW->pitch_target;
    rtDW->nav_roll_cd = rtDW->roll_target;
    stabilize(rtDW);
    rtDW->k_aileron *= rtDW->p_plane_c2p;
    rtDW->k_elevator *= rtDW->p_plane_c2p;
    rtDW->k_rudder *= rtDW->p_plane_c2p;
    tail_error = rtDW->yaw_in;
    if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
      rtDW->yaw_in = -rtDW->yaw_max_c2p;
    }

    if (tail_error > rtDW->yaw_max_c2p) {
      rtDW->yaw_in = rtDW->yaw_max_c2p;
    }

    rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
    AP_MotorsMulticopter_output(rtDW);
    break;

   case VerticalMove:
    if (rtDW->PathMode_j != VerticalMove) {
      rtDW->PathMode_j = VerticalMove;
      rtDW->inint_hgt = 1.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->target_yaw_rate = 0.0;
    }

    switch ((int32_T)rtDW->uavMode_p) {
     case 1:
      if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else if (rtDW->PathModeOut_sl.heightCmd - rtDW->hgt_dem_cm < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->hgt_dem_cm = rtDW->PathModeOut_sl.heightCmd;
      }

      rtDW->center_WP[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->center_WP[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
      plane_run(rtDW);
      break;

     case 0:
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[0] = rtDW->PathModeOut_sl.turnCenterLL[0];
      rtDW->pos_target[1] = 0.0;
      rtDW->loc_origin[1] = rtDW->PathModeOut_sl.turnCenterLL[1];
      get_vector_xy_from_origin_NE(rtDW->current_loc, rtDW->loc_origin, a, rtDW);
      rtDW->curr_pos[0] = a[0] * 100.0;
      rtDW->curr_pos[1] = a[1] * 100.0;
      if (rtDW->PathModeOut_sl.heightCmd - rtDW->pos_target[2] > 8.0) {
        rtDW->climb_rate_cms = rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else if (rtDW->PathModeOut_sl.heightCmd - rtDW->pos_target[2] < -8.0) {
        rtDW->climb_rate_cms = -rtDW->PathModeOut_sl.maxClimbSpeed;
        set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0,
          rtDW);
      } else {
        rtDW->climb_rate_cms = 0.0;
        rtDW->pos_target[2] = rtDW->PathModeOut_sl.heightCmd;
      }

      copter_run(rtDW);
      break;
    }
    break;

   default:
    copter_run(rtDW);
    break;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void run_V1000(DW *rtDW)
{
  real_T temp_yaw_rate;
  real_T vel_desired_tmp;
  real_T tmp[3];
  real_T tmp_0[2];
  int32_T prev_WP_tmp;
  real_T tmp_1[4];
  if ((rtDW->mode == 1.0) || (rtDW->mode == 2.0) || (rtDW->mode == 3.0) ||
      (rtDW->mode == 7.0)) {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  } else {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
  }

  if ((rtDW->mode_state == 3.0) || (rtDW->mode_state == 9.0) ||
      (rtDW->mode_state == 10.0)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  if (rtDW->inint != 0.0) {
    setup_motors(rtDW);
    rtDW->inint = 0.0;
  }

  tmp[0] = rtDW->roll;
  tmp[1] = rtDW->pitch;
  tmp[2] = rtDW->yaw;
  from_euler(tmp, tmp_1);
  rotation_matrix(tmp_1, rtDW->rot_body_to_ned);
  for (prev_WP_tmp = 0; prev_WP_tmp < 3; prev_WP_tmp++) {
    tmp[prev_WP_tmp] = rtDW->rot_body_to_ned[prev_WP_tmp + 6] * rtDW->accel_z +
      (rtDW->rot_body_to_ned[prev_WP_tmp + 3] * rtDW->accel_y +
       rtDW->rot_body_to_ned[prev_WP_tmp] * rtDW->accel_x);
  }

  rtDW->z_accel_meas = -(tmp[2] + rtDW->GRAVITY_MSS) * 100.0;
  rtDW->arspeed_temp += rtDW->dt / (1.0 / (6.2831853071795862 *
    rtDW->arspeed_filt) + rtDW->dt) * (rtDW->aspeed - rtDW->arspeed_temp);
  rtDW->aspeed = rtDW->arspeed_temp;
  switch ((int32_T)rtDW->mode) {
   case 1:
    if (rtDW->mode_state != 1.0) {
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->mode_state = 1.0;
    }

    set_throttle_out(rtDW->throttle_in, 1.0,
                     rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ, rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output(rtDW);
    break;

   case 2:
    if (rtDW->mode_state != 2.0) {
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state = 2.0;
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output(rtDW);
    break;

   case 3:
    if (rtDW->mode_state != 3.0) {
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state = 3.0;
    } else {
      temp_yaw_rate = cos(rtDW->loc_origin[0] * 1.0E-7 / rtDW->HD);
      if (temp_yaw_rate < 0.01) {
        temp_yaw_rate = 0.01;
      }

      rtDW->curr_pos[0] = (rtDW->current_loc[0] - rtDW->loc_origin[0]) *
        rtDW->LOCATION_SCALING_FACTOR * 100.0;
      rtDW->curr_pos[1] = (rtDW->current_loc[1] - rtDW->loc_origin[1]) *
        rtDW->LOCATION_SCALING_FACTOR * temp_yaw_rate * 100.0;
    }

    temp_yaw_rate = sin(rtDW->yaw);
    vel_desired_tmp = cos(rtDW->yaw);
    rtDW->vel_desired[0] = rtDW->pitch_target_pilot / 10.0 * vel_desired_tmp -
      rtDW->roll_target_pilot / 10.0 * temp_yaw_rate;
    rtDW->vel_desired[1] = rtDW->pitch_target_pilot / 10.0 * temp_yaw_rate +
      rtDW->roll_target_pilot / 10.0 * vel_desired_tmp;
    if (fabs(rtDW->pitch_target_pilot) > 0.0) {
      temp_yaw_rate = 0.0;
    } else if (fabs(rtDW->roll_target_pilot) > 0.0) {
      temp_yaw_rate = 0.0;
    } else if (fabs(rtDW->target_yaw_rate) > 0.0) {
      temp_yaw_rate = 0.0;
    } else {
      temp_yaw_rate = get_weathervane_yaw_rate_cds(rtDW);
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_vel_controller_xy(rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate + temp_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output(rtDW);
    break;

   case 4:
    if (rtDW->mode_state != 4.0) {
      rtDW->mode_state = 4.0;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane(rtDW);
    break;

   case 5:
    if (rtDW->mode_state != 5.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->mode_state = 5.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane(rtDW);
    break;

   case 6:
    if (rtDW->mode_state != 6.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->mode_state = 6.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    prev_WP_tmp = (int32_T)(rtDW->WP_i + 1.0) - 1;
    rtDW->next_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->next_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    temp_yaw_rate = cos(rtDW->current_loc[0] * 1.0E-7 / rtDW->HD);
    if (temp_yaw_rate < 0.01) {
      temp_yaw_rate = 0.01;
    }

    tmp_0[0] = (rtDW->next_WP[0] - rtDW->current_loc[0]) *
      rtDW->LOCATION_SCALING_FACTOR;
    tmp_0[1] = (rtDW->next_WP[1] - rtDW->current_loc[1]) *
      rtDW->LOCATION_SCALING_FACTOR * temp_yaw_rate;
    if (norm(tmp_0) < rtDW->L1_radius) {
      if (rtDW->loc.num[(int32_T)(rtDW->WP_i + 2.0) - 1] != 99.0) {
        rtDW->WP_i++;
      } else {
        rtDW->WP_i = 2.0;
      }
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane(rtDW);
    break;

   case 7:
    if (rtDW->mode_state != 7.0) {
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state = 7.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_z_controller(rtDW);
    temp_yaw_rate = rtDW->tail_tilt;
    if (rtDW->tail_tilt < -3000.0) {
      temp_yaw_rate = -3000.0;
    }

    if (rtDW->tail_tilt > 700.0) {
      temp_yaw_rate = 700.0;
    }

    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target +
      rtDW->p_tilt_pitch_target * temp_yaw_rate, rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      temp_yaw_rate = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (temp_yaw_rate > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
    }

    AP_MotorsMulticopter_output(rtDW);
    break;

   case 8:
    if (rtDW->mode_state != 8.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->mode_state = 8.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane(rtDW);
    break;

   case 9:
    if (rtDW->mode_state != 9.0) {
      rtDW->mode_state = 9.0;
    }

    auto_mode(rtDW);
    break;

   case 10:
    if (rtDW->mode_state != 10.0) {
      rtDW->mode_state = 10.0;
    }

    auto_mode_sl(rtDW);
    break;

   default:
    rtDW->mode_state = rtDW->mode;
    break;
  }
}

/* Function for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
static void run_V10s(DW *rtDW)
{
  real_T temp_yaw_rate;
  real_T vel_desired_tmp;
  real_T tmp[2];
  int32_T prev_WP_tmp;
  if ((rtDW->mode == 1.0) || (rtDW->mode == 2.0) || (rtDW->mode == 3.0) ||
      (rtDW->mode == 7.0)) {
    rtDW->disable_integrator_pitch = 1.0;
    rtDW->disable_integrator_roll = 1.0;
    rtDW->disable_integrator_yaw = 1.0;
    rtDW->roll_ff_pitch = 0.0;
    rtDW->K_FF_yaw = 0.0;
  } else {
    rtDW->disable_integrator_pitch = 0.0;
    rtDW->disable_integrator_roll = 0.0;
    rtDW->disable_integrator_yaw = 0.0;
    rtDW->roll_ff_pitch = rtDW->roll_ff_pitch_inint;
    rtDW->K_FF_yaw = rtDW->K_FF_yaw_inint;
  }

  if ((rtDW->mode_state_c == 3.0) || (rtDW->mode_state_c == 9.0) ||
      (rtDW->mode_state_c == 10.0)) {
    rtDW->POSCONTROL_ACC_Z_I = rtDW->POSCONTROL_ACC_Z_I_inint;
    rtDW->POSCONTROL_VEL_XY_I = rtDW->POSCONTROL_VEL_XY_I_inint;
    rtDW->ATC_RAT_PIT_I = rtDW->ATC_RAT_PIT_I_inint;
    rtDW->ATC_RAT_RLL_I = rtDW->ATC_RAT_RLL_I_inint;
    rtDW->ATC_RAT_YAW_I = rtDW->ATC_RAT_YAW_I_inint;
  } else {
    rtDW->POSCONTROL_ACC_Z_I = 0.0;
    rtDW->POSCONTROL_VEL_XY_I = 0.0;
    rtDW->ATC_RAT_PIT_I = 0.0;
    rtDW->ATC_RAT_RLL_I = 0.0;
    rtDW->ATC_RAT_YAW_I = 0.0;
    rtDW->pid_accel_z_reset_filter = 1.0;
    rtDW->pid_vel_xy_reset_filter = 1.0;
    rtDW->rate_pitch_pid_reset_filter = 1.0;
    rtDW->rate_roll_pid_reset_filter = 1.0;
    rtDW->rate_yaw_pid_reset_filter = 1.0;
  }

  if (rtDW->inint != 0.0) {
    setup_motors(rtDW);
    rtDW->inint = 0.0;
  }

  updata_cl(rtDW);
  rtDW->arspeed_temp += rtDW->dt / (1.0 / (6.2831853071795862 *
    rtDW->arspeed_filt) + rtDW->dt) * (rtDW->aspeed - rtDW->arspeed_temp);
  rtDW->aspeed = rtDW->arspeed_temp;
  rtDW->tail_tilt = 0.0;
  switch ((int32_T)rtDW->mode) {
   case 1:
    if (rtDW->mode_state_c != 1.0) {
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
      rtDW->mode_state_c = 1.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->k_throttle = 0.0;
    }

    set_throttle_out(rtDW->throttle_in, 1.0,
                     rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ, rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 2:
    if (rtDW->mode_state_c != 2.0) {
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state_c = 2.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->k_throttle = 0.0;
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 3:
    if (rtDW->mode_state_c != 3.0) {
      rtDW->loc_origin[0] = rtDW->current_loc[0];
      rtDW->curr_pos[0] = 0.0;
      rtDW->pos_target[0] = 0.0;
      rtDW->loc_origin[1] = rtDW->current_loc[1];
      rtDW->curr_pos[1] = 0.0;
      rtDW->pos_target[1] = 0.0;
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state_c = 3.0;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
      rtDW->k_throttle = 0.0;
    } else {
      temp_yaw_rate = cos(rtDW->loc_origin[0] * 1.0E-7 / rtDW->HD);
      if (temp_yaw_rate < 0.01) {
        temp_yaw_rate = 0.01;
      }

      rtDW->curr_pos[0] = (rtDW->current_loc[0] - rtDW->loc_origin[0]) *
        rtDW->LOCATION_SCALING_FACTOR * 100.0;
      rtDW->curr_pos[1] = (rtDW->current_loc[1] - rtDW->loc_origin[1]) *
        rtDW->LOCATION_SCALING_FACTOR * temp_yaw_rate * 100.0;
    }

    temp_yaw_rate = sin(rtDW->yaw);
    vel_desired_tmp = cos(rtDW->yaw);
    rtDW->vel_desired[0] = rtDW->pitch_target_pilot / 10.0 * vel_desired_tmp -
      rtDW->roll_target_pilot / 10.0 * temp_yaw_rate;
    rtDW->vel_desired[1] = rtDW->pitch_target_pilot / 10.0 * temp_yaw_rate +
      rtDW->roll_target_pilot / 10.0 * vel_desired_tmp;
    if (fabs(rtDW->pitch_target_pilot) > 0.0) {
      temp_yaw_rate = 0.0;
    } else if (fabs(rtDW->roll_target_pilot) > 0.0) {
      temp_yaw_rate = 0.0;
    } else if (fabs(rtDW->target_yaw_rate) > 0.0) {
      temp_yaw_rate = 0.0;
    } else {
      temp_yaw_rate = get_weathervane_yaw_rate_cds(rtDW);
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_vel_controller_xy(rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate + temp_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 4:
    if (rtDW->mode_state_c != 4.0) {
      rtDW->mode_state_c = 4.0;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 5:
    if (rtDW->mode_state_c != 5.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->mode_state_c = 5.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 6:
    if (rtDW->mode_state_c != 6.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->mode_state_c = 6.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    prev_WP_tmp = (int32_T)rtDW->WP_i_h - 1;
    rtDW->prev_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->prev_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    prev_WP_tmp = (int32_T)(rtDW->WP_i_h + 1.0) - 1;
    rtDW->next_WP[0] = rtDW->loc.lat[prev_WP_tmp];
    rtDW->next_WP[1] = rtDW->loc.lon[prev_WP_tmp];
    temp_yaw_rate = cos(rtDW->current_loc[0] * 1.0E-7 / rtDW->HD);
    if (temp_yaw_rate < 0.01) {
      temp_yaw_rate = 0.01;
    }

    tmp[0] = (rtDW->next_WP[0] - rtDW->current_loc[0]) *
      rtDW->LOCATION_SCALING_FACTOR;
    tmp[1] = (rtDW->next_WP[1] - rtDW->current_loc[1]) *
      rtDW->LOCATION_SCALING_FACTOR * temp_yaw_rate;
    if (norm(tmp) < rtDW->L1_radius) {
      if (rtDW->loc.num[(int32_T)(rtDW->WP_i_h + 2.0) - 1] != 99.0) {
        rtDW->WP_i_h++;
      } else {
        rtDW->WP_i_h = 2.0;
      }
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    update_waypoint(rtDW->prev_WP, rtDW->next_WP, rtDW->dist_min, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 7:
    if (rtDW->mode_state_c != 7.0) {
      rtDW->pos_target[2] = rtDW->curr_alt;
      rtDW->vel_desired[2] = 0.0;
      rtDW->mode_state_c = 7.0;
      rtDW->k_throttle = 0.0;
      from_rotation_matrix(rtDW->rot_body_to_ned, rtDW->attitude_target_quat);
    }

    set_alt_target_from_climb_rate_(rtDW->climb_rate_cms, rtDW->dt, 0.0, rtDW);
    update_z_controller(rtDW);
    input_euler_angle_roll_pitch__o(rtDW->roll_target, rtDW->pitch_target,
      rtDW->target_yaw_rate, rtDW);
    rate_controller_run(rtDW);
    if (rtDW->aspeed > rtDW->aspeed_c2p) {
      rtDW->nav_pitch_cd = rtDW->pitch_target;
      rtDW->nav_roll_cd = rtDW->roll_target;
      stabilize(rtDW);
      rtDW->k_aileron *= rtDW->p_plane_c2p;
      rtDW->k_elevator *= rtDW->p_plane_c2p;
      rtDW->k_rudder *= rtDW->p_plane_c2p;
      temp_yaw_rate = rtDW->yaw_in;
      if (rtDW->yaw_in < -rtDW->yaw_max_c2p) {
        rtDW->yaw_in = -rtDW->yaw_max_c2p;
      }

      if (temp_yaw_rate > rtDW->yaw_max_c2p) {
        rtDW->yaw_in = rtDW->yaw_max_c2p;
      }

      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p;
    } else {
      rtDW->POSCONTROL_ACC_Z_FILT_HZ = rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint;
      rtDW->k_aileron = 0.0;
      rtDW->k_elevator = 0.0;
      rtDW->k_rudder = 0.0;
    }

    rtDW->k_throttle = rtDW->throttle_dem;
    AP_MotorsMulticopter_output_4a1(rtDW);
    break;

   case 8:
    if (rtDW->mode_state_c != 8.0) {
      rtDW->hgt_dem_cm = rtDW->height * 100.0;
      rtDW->inint_hgt = 1.0;
      rtDW->center_WP[0] = rtDW->current_loc[0];
      rtDW->center_WP[1] = rtDW->current_loc[1];
      rtDW->mode_state_c = 8.0;
    } else {
      rtDW->hgt_dem_cm += rtDW->dt * rtDW->climb_rate_cms;
    }

    update_50hz(rtDW);
    update_pitch_throttle(rtDW->hgt_dem_cm, rtDW->EAS_dem_cm,
                          rtDW->aerodynamic_load_factor, rtDW);
    update_loiter(rtDW->center_WP, rtDW->radius, rtDW->loiter_direction, rtDW);
    temp_yaw_rate = rtDW->pitch_dem * rtDW->HD * 100.0;
    rtDW->nav_pitch_cd = temp_yaw_rate;
    if (temp_yaw_rate < rtDW->pitch_limit_min_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_min_cd;
    }

    if (temp_yaw_rate > rtDW->pitch_limit_max_cd) {
      rtDW->nav_pitch_cd = rtDW->pitch_limit_max_cd;
    }

    calc_nav_roll(rtDW);
    rtDW->k_throttle = rtDW->throttle_dem;
    stabilize(rtDW);
    output_to_motors_plane_4a1(rtDW);
    break;

   case 9:
    if (rtDW->mode_state_c != 9.0) {
      rtDW->mode_state_c = 9.0;
    }

    auto_mode_4a1(rtDW);
    break;

   case 10:
    if (rtDW->mode_state_c != 10.0) {
      rtDW->mode_state_c = 10.0;
    }

    auto_mode_sl_4a1(rtDW);
    break;

   default:
    rtDW->mode_state_c = rtDW->mode;
    break;
  }
}

/* Model step function */
void input_euler_angle_roll_pitch_eu_step(RT_MODEL *const rtM)
{
  DW *rtDW = ((DW *) rtM->dwork);

  /* MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  switch (rtDW->plane_mode) {
   case V1000:
    run_V1000(rtDW);
    break;

   case V10:
    run_V10(rtDW);
    break;

   case V10s:
    run_V10s(rtDW);
    break;

   default:
    run_V10(rtDW);
    break;
  }

  /* End of MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
}

/* Model initialize function */
void input_euler_angle_roll_pitch_eu_initialize(RT_MODEL *const rtM)
{
  DW *rtDW = ((DW *) rtM->dwork);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_1' */
  rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLLER = 12.566370614359172;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_100' */
  rtDW->TAS_dem_adj = 17.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_102' */
  rtDW->TAS_state = 17.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_103' */
  rtDW->TASmax = 23.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_104' */
  rtDW->TASmin = 15.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_105' */
  rtDW->THRmaxf = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_11' */
  rtDW->ATC_RAT_PIT_FILT = 20.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_112' */
  rtDW->accel_pitch_max = 30000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_113' */
  rtDW->accel_roll_max = 72000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_116' */
  rtDW->accel_xy_angle_max = 2000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_119' */
  rtDW->accel_yaw_max = 18000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_121' */
  rtDW->aerodynamic_load_factor = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_122' */
  rtDW->air_density_ratio = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_123' */
  rtDW->airspeed_max = 23.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_124' */
  rtDW->airspeed_min = 15.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_13' */
  rtDW->ATC_RAT_PIT_IMAX = 0.25;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_130' */
  rtDW->angle_boost_enabled = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_131' */
  rtDW->angle_limit_tc = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_132' */
  rtDW->armed = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_133' */
  rtDW->arspeed_filt = 5.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_135' */
  rtDW->aspeed = 17.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_136' */
  rtDW->aspeed_c2p = 8.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_137' */
  rtDW->aspeed_c2ps = 15.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_138' */
  rtDW->aspeed_cp = 30.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_14' */
  rtDW->ATC_RAT_PIT_I_inint = 0.1;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_139' */
  rtDW->attitude_ang_error[0] = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_144' */
  rtDW->attitude_target_quat[0] = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_139' */
  rtDW->attitude_ang_error[1] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_144' */
  rtDW->attitude_target_quat[1] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_139' */
  rtDW->attitude_ang_error[2] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_144' */
  rtDW->attitude_target_quat[2] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_139' */
  rtDW->attitude_ang_error[3] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_144' */
  rtDW->attitude_target_quat[3] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_15' */
  rtDW->ATC_RAT_PIT_P = 0.2;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_154' */
  rtDW->current_tilt = 0.35;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_161' */
  rtDW->dist_min = 50.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_162' */
  rtDW->dt = 0.012;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_165' */
  rtDW->gains_D_pitch = 0.35;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_166' */
  rtDW->gains_D_roll = 0.22;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_169' */
  rtDW->gains_I_pitch = 0.02;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_171' */
  rtDW->gains_P_pitch = 0.9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_172' */
  rtDW->gains_P_roll = 1.07;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_173' */
  rtDW->gains_imax_pitch = 3000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_174' */
  rtDW->gains_imax_roll = 3000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_177' */
  rtDW->gains_tau_pitch = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_178' */
  rtDW->gains_tau_roll = 0.5;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_18' */
  rtDW->ATC_RAT_RLL_FILT = 20.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_191' */
  rtDW->highest_airspeed = 30.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_192' */
  rtDW->imax_yaw = 1500.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_193' */
  rtDW->inint = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_194' */
  rtDW->inint_hgt = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_195' */
  rtDW->input_tc = 0.3;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_197' */
  rtDW->integGain = 0.25;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_2' */
  rtDW->AC_ATTITUDE_ACCEL_RP_CONTROLL_a = 0.69813170079773179;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_20' */
  rtDW->ATC_RAT_RLL_IMAX = 0.25;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_202' */
  rtDW->is_active_xy = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_203' */
  rtDW->is_active_z = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_208' */
  rtDW->k_throttle_c2p = 0.4;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_209' */
  rtDW->kff_rudder_mix = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_21' */
  rtDW->ATC_RAT_RLL_I_inint = 0.1;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_22' */
  rtDW->ATC_RAT_RLL_P = 0.21;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_220' */
  rtDW->leash = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_221' */
  rtDW->leash_down_z = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_222' */
  rtDW->leash_up_z = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_230' */
  rtDW->loc = rtConstP._DataStoreBlk_230_InitialValue;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_233' */
  rtDW->loiter_direction = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_234' */
  rtDW->maxClimbRate = 5.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_235' */
  rtDW->maxSinkRate = 7.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_237' */
  rtDW->minSinkRate = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_247' */
  rtDW->p_angle_pitch = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_248' */
  rtDW->p_angle_roll = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_249' */
  rtDW->p_angle_yaw = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_25' */
  rtDW->ATC_RAT_YAW_FILT = 5.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_250' */
  rtDW->p_ff_throttle = 0.5;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_251' */
  rtDW->p_plane_c2p = 0.6;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_252' */
  rtDW->p_plane_cp = 0.4;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_253' */
  rtDW->p_tail_tilt = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_254' */
  rtDW->p_tilt_pitch_target = 0.2;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_258' */
  rtDW->pid_accel_z_reset_filter = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_276' */
  rtDW->pid_vel_xy_reset_filter = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_282' */
  rtDW->pitch_limit_max_cd = 2000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_283' */
  rtDW->pitch_limit_min_cd = -1500.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_285' */
  rtDW->pitch_max_limit = 90.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_289' */
  rtDW->pitch_target_p2c = 500.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_29' */
  rtDW->ATC_RAT_YAW_P = 0.19;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_291' */
  rtDW->plane_mode = V10;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_146' */
  rtDW->center_WP[0] = 4.0E+8;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_153' */
  rtDW->current_loc[0] = 4.0E+8;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_179' */
  rtDW->groundspeed_vector[0] = 0.1;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_231' */
  rtDW->loc_origin[0] = 4.0E+8;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_246' */
  rtDW->next_WP[0] = 4.0E+8;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_294' */
  rtDW->prev_WP[0] = 4.0E+8;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_146' */
  rtDW->center_WP[1] = 1.0E+9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_153' */
  rtDW->current_loc[1] = 1.0E+9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_179' */
  rtDW->groundspeed_vector[1] = 0.1;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_231' */
  rtDW->loc_origin[1] = 1.0E+9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_246' */
  rtDW->next_WP[1] = 1.0001E+9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_294' */
  rtDW->prev_WP[1] = 1.0E+9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_295' */
  rtDW->ptchDamp = 0.7;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_296' */
  rtDW->pwm_max = 2000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_297' */
  rtDW->pwm_min = 1000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_298' */
  rtDW->pwm_out[0] = 1000.0;
  rtDW->pwm_out[1] = 1000.0;
  rtDW->pwm_out[2] = 1000.0;
  rtDW->pwm_out[3] = 1000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_299' */
  rtDW->pwm_tail = 1000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_3' */
  rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLER_ = 2.0943951023931953;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_30' */
  rtDW->EAS2TAS = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_300' */
  rtDW->radius = 60.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_301' */
  rtDW->rate_bf_ff_enabled = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_31' */
  rtDW->EAS_dem = 17.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_315' */
  rtDW->recalc_leash_xy = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_316' */
  rtDW->recalc_leash_z = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_317' */
  rtDW->reset_accel_to_lean_xy = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_318' */
  rtDW->reset_accel_to_throttle = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_319' */
  rtDW->reset_desired_vel_to_pos = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_32' */
  rtDW->EAS_dem_cm = 1900.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_320' */
  rtDW->reset_rate_to_accel_z = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_323' */
  rtDW->rollComp = 12.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_326' */
  rtDW->roll_ff_pitch_inint = 0.85;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_328' */
  rtDW->roll_limit_cd = 2500.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_329' */
  rtDW->roll_limit_cd_inint = 3500.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_33' */
  rtDW->GRAVITY_MSS = 9.80665;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_332' */
  memcpy(&rtDW->rot_body_to_ned[0], &rtConstP._DataStoreBlk_332_InitialValue[0],
         9U * sizeof(real_T));

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_333' */
  rtDW->scaling_speed = 17.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_334' */
  rtDW->slew_yaw = 6000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_336' */
  rtDW->spdCompFiltOmega = 2.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_337' */
  rtDW->spdWeight = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_339' */
  rtDW->tail_tilt_c2p = -2800.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_34' */
  rtDW->HD = 57.295779513082323;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_340' */
  rtDW->tail_tilt_p2c = -1300.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_341' */
  rtDW->tail_tilt_rate = 1500.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_345' */
  rtDW->thrDamp = 0.7;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_346' */
  rtDW->thr_out_min = 0.4;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_347' */
  rtDW->throttle_avg_max = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_348' */
  rtDW->throttle_cruise = 40.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_349' */
  rtDW->throttle_cutoff_frequency = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_352' */
  rtDW->throttle_ground = 0.55;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_353' */
  rtDW->throttle_hover = 0.6;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_354' */
  rtDW->throttle_in = 0.4816;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_356' */
  rtDW->throttle_max = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_358' */
  rtDW->throttle_off_rate = 0.03;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_360' */
  rtDW->throttle_slewrate = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_361' */
  rtDW->throttle_thrust_max = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_367' */
  rtDW->thrust_slew_time = 0.3;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_368' */
  rtDW->timeConstant = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_369' */
  rtDW->use_desvel_ff_z = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_37' */
  rtDW->K_D_yaw = 0.25;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_370' */
  rtDW->use_sqrt_controller = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_376' */
  rtDW->vel_forward_gain = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_379' */
  rtDW->vel_forward_min_pitch = -30.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_380' */
  rtDW->vel_forward_tail_tilt_max = 2000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_383' */
  rtDW->vertAccLim = 3.5;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_384' */
  rtDW->weathervane_gain = 0.2;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_386' */
  rtDW->weathervane_min_roll = 5.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_39' */
  rtDW->K_FF_yaw_inint = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_391' */
  rtDW->yaw_in_max = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_392' */
  rtDW->yaw_max_c2p = 0.05;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_393' */
  rtDW->yaw_rate_max = 50.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_4' */
  rtDW->AC_ATTITUDE_ACCEL_Y_CONTROLLE_j = 0.17453292519943295;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_40' */
  rtDW->K_I_yaw = 0.05;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_41' */
  rtDW->Kx = 0.2572944297082228;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_42' */
  rtDW->L1_damping = 0.75;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_44' */
  rtDW->L1_period = 15.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_45' */
  rtDW->L1_radius = 60.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_49' */
  rtDW->LOCATION_SCALING_FACTOR = 0.011131884502145034;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_5' */
  rtDW->AC_ATTITUDE_CONTROL_ANGLE_LIMIT = 0.8;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_50' */
  rtDW->LOCATION_SCALING_FACTOR_INV = 89.832049533689215;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_53' */
  rtDW->POSCONTROL_ACCELERATION_MIN = 50.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_54' */
  rtDW->POSCONTROL_ACCEL_FILTER_HZ = 10.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_55' */
  rtDW->POSCONTROL_ACCEL_XY = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_56' */
  rtDW->POSCONTROL_ACCEL_XY_MAX = 458.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_57' */
  rtDW->POSCONTROL_ACCEL_Z = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_58' */
  rtDW->POSCONTROL_ACC_Z_D = 0.3;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_6' */
  rtDW->AC_ATTITUDE_THRUST_ERROR_ANGLE = 0.52359877559829882;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_60' */
  rtDW->POSCONTROL_ACC_Z_FILT_HZ_c2p = 0.2;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_61' */
  rtDW->POSCONTROL_ACC_Z_FILT_HZ_inint = 4.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_63' */
  rtDW->POSCONTROL_ACC_Z_IMAX = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_64' */
  rtDW->POSCONTROL_ACC_Z_I_inint = 0.1;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_65' */
  rtDW->POSCONTROL_ACC_Z_P = 0.9;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_66' */
  rtDW->POSCONTROL_JERK_RATIO = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_67' */
  rtDW->POSCONTROL_LEASH_LENGTH_MIN = 100.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_68' */
  rtDW->POSCONTROL_OVERSPEED_GAIN_Z = 2.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_69' */
  rtDW->POSCONTROL_POS_XY_P = 1.2;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_7' */
  rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CCW = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_70' */
  rtDW->POSCONTROL_POS_Z_P = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_71' */
  rtDW->POSCONTROL_SPEED = 300.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_72' */
  rtDW->POSCONTROL_SPEED_DOWN = -300.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_73' */
  rtDW->POSCONTROL_SPEED_UP = 300.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_74' */
  rtDW->POSCONTROL_STOPPING_DIST_DOWN_M = 200.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_75' */
  rtDW->POSCONTROL_STOPPING_DIST_UP_MAX = 300.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_76' */
  rtDW->POSCONTROL_THROTTLE_CUTOFF_FREQ = 3.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_77' */
  rtDW->POSCONTROL_VEL_ERROR_CUTOFF_FRE = 1.5;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_78' */
  rtDW->POSCONTROL_VEL_XY_D = 0.12;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_79' */
  rtDW->POSCONTROL_VEL_XY_FILT_D_HZ = 5.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_8' */
  rtDW->AP_MOTORS_MATRIX_YAW_FACTOR_CW = -1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_80' */
  rtDW->POSCONTROL_VEL_XY_FILT_HZ = 2.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_82' */
  rtDW->POSCONTROL_VEL_XY_IMAX = 1000.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_83' */
  rtDW->POSCONTROL_VEL_XY_I_inint = 0.1;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_84' */
  rtDW->POSCONTROL_VEL_XY_P = 1.2;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_85' */
  rtDW->POSCONTROL_VEL_Z_P = 1.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_86' */
  rtDW->PathModeOut_sl =
    input_euler_angle_roll_pitch_eu_rtZBUS_TASK_PATH_OutParam;
  rtDW->PathModeOut_sl.flightControlMode = SpotHoverMode;
  rtDW->PathModeOut_sl.flightTaskMode = Rotor2Fix_Mode;
  rtDW->PathModeOut_sl.groundspeedCmd = 0.0;
  rtDW->PathModeOut_sl.headingCmd = 0.0;
  rtDW->PathModeOut_sl.heightCmd = 0.1;
  rtDW->PathModeOut_sl.maxClimbSpeed = 0.0;
  rtDW->PathModeOut_sl.curPathPoint_LLA[0] = 0.0;
  rtDW->PathModeOut_sl.prePathPoint_LLA[0] = 0.0;
  rtDW->PathModeOut_sl.curPathPoint_LLA[1] = 0.0;
  rtDW->PathModeOut_sl.prePathPoint_LLA[1] = 0.0;
  rtDW->PathModeOut_sl.curPathPoint_LLA[2] = 0.0;
  rtDW->PathModeOut_sl.prePathPoint_LLA[2] = 0.0;
  rtDW->PathModeOut_sl.rollCmd = 0.1;
  rtDW->PathModeOut_sl.turnCenterLL[0] = 0.0;
  rtDW->PathModeOut_sl.turnCenterLL[1] = 0.0;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_99' */
  rtDW->TAS_dem = 17.0;

  /* SystemInitialize for MATLAB Function: '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  rtDW->WP_i = 1.0;
  rtDW->WP_i_o = 1.0;
  rtDW->PathMode = NoneFlightTaskMode;
  rtDW->PathMode_j = NoneFlightTaskMode;
  rtDW->WP_i_m = 1.0;
  rtDW->WP_i_a = 1.0;
  rtDW->PathMode_g = NoneFlightTaskMode;
  rtDW->PathMode_d = NoneFlightTaskMode;
  rtDW->WP_i_h = 1.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
