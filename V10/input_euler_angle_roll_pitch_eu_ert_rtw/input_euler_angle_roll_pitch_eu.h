/*
 * File: input_euler_angle_roll_pitch_eu.h
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

#ifndef RTW_HEADER_input_euler_angle_roll_pitch_eu_h_
#define RTW_HEADER_input_euler_angle_roll_pitch_eu_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef input_euler_angle_roll_pitch_eu_COMMON_INCLUDES_
# define input_euler_angle_roll_pitch_eu_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                    /* input_euler_angle_roll_pitch_eu_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_Bus_wp_
#define DEFINED_TYPEDEF_FOR_Bus_wp_

typedef struct {
  real_T num[11];
  real_T lat[11];
  real_T lon[11];
} Bus_wp;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_plane_mode_
#define DEFINED_TYPEDEF_FOR_ENUM_plane_mode_

typedef enum {
  V1000 = 0,                           /* Default value */
  V10,
  V10s,
  V10ss
} ENUM_plane_mode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_FlightTaskMode_
#define DEFINED_TYPEDEF_FOR_ENUM_FlightTaskMode_

typedef enum {
  NoneFlightTaskMode = 0,              /* Default value */
  GroundStandByMode = 1,
  TakeOffMode = 2,
  Rotor2Fix_Mode = 3,
  HoverAdjustMode = 4,
  HoverUpMode = 5,
  PathFollowMode = 6,
  AirStandByMode = 7,
  GoHomeMode = 8,
  HoverDownMode = 9,
  Fix2Rotor_Mode = 10,
  LandMode = 11,
  FenceRecoverMode = 12,
  SpotCircleMode = 13,
  StallRecovery = 14,
  VerticalMove = 15,
  Test_HeightKeep = 101,
  Test_AttitudeKeep = 102,
  Test_HeadingKeep = 103,
  Test_SpotCircle = 104
} ENUM_FlightTaskMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_FlightControlMode_
#define DEFINED_TYPEDEF_FOR_ENUM_FlightControlMode_

typedef enum {
  NoneFlightControlMode = 0,           /* Default value */
  SpotHoverMode,
  HeightKeepMode,
  AttitudeKeepMode,
  HeadingKeepMode,
  PathFollowControlMode,
  CircleHoverMode,
  Move3dMode,
  GroundStandByControlMode,
  DoNothinig,
  OnlyStablizePitchAndRoll,
  RotorGoUpDownBySpeed,
  RotorUnloadToStandby,
  RotorShutDown,
  RotorStable_RollPitchHeight,
  RotorGoUpDownWithHorizonPosFree
} ENUM_FlightControlMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_UAVMode_
#define DEFINED_TYPEDEF_FOR_ENUM_UAVMode_

typedef enum {
  NoneUAVMode = 0,                     /* Default value */
  Rotor,
  Fix,
  Rotor2Fix,
  Fix2Rotor
} ENUM_UAVMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_ControlMode_
#define DEFINED_TYPEDEF_FOR_ENUM_ControlMode_

typedef enum {
  NoneControlMode = 0,                 /* Default value */
  Auto,
  FCS,
  Manual
} ENUM_ControlMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_ComStatus_
#define DEFINED_TYPEDEF_FOR_ENUM_ComStatus_

typedef enum {
  ComNormal = 0,                       /* Default value */
  RemoteOrStationLost
} ENUM_ComStatus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_Where_
#define DEFINED_TYPEDEF_FOR_ENUM_Where_

typedef enum {
  OnGround = 0,                        /* Default value */
  InTheAir,
  OnWater,
  UnderWater
} ENUM_Where;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_AutoModeType_
#define DEFINED_TYPEDEF_FOR_ENUM_AutoModeType_

typedef enum {
  NotAutoMode = 0,                     /* Default value */
  AutoProfile,
  SuspendTaskToLand,
  SuspendTaskToHome,
  ManualToAuto,
  SuspendTaskToHomeThenLand,
  Fix2Rotor2HoverAdjust,
  PauseInAir,
  Fix2Rotor2Home2Land
} ENUM_AutoModeType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_TASK_PATH_OutParam_
#define DEFINED_TYPEDEF_FOR_BUS_TASK_PATH_OutParam_

typedef struct {
  /* 当前目标航点号(home为1号) */
  real_T currentPointNum;

  /* 前置航点号 */
  real_T prePointNum;

  /* 有效航点数量（包括home点） */
  real_T validPathNum;

  /* 目标航向角[rad] */
  real_T headingCmd;

  /* 距离当前目标点的距离 */
  real_T distToGo;

  /* 航线跟踪模式中计算的侧偏距[m] */
  real_T dz;

  /* 目标地速[m/s] */
  real_T groundspeedCmd;

  /* 目标滚转角[rad] */
  real_T rollCmd;

  /* 目标盘旋半径[m] */
  real_T turnRadiusCmd;

  /* 目标高度[m] */
  real_T heightCmd;

  /* 固定翼模式的盘旋中心的纬度、经度，
     或旋翼模式的悬停点 */
  real_T turnCenterLL[2];

  /* 固定翼盘旋时的盘旋半径偏差[m] */
  real_T dR_turn;

  /* 无人机模式，旋翼、固定翼、旋翼转固定翼、固定翼转旋翼 */
  ENUM_UAVMode uavMode;

  /* 飞行任务模式，地面模式、起飞模式等 */
  ENUM_FlightTaskMode flightTaskMode;

  /* 飞行控制模式 */
  ENUM_FlightControlMode flightControlMode;

  /* 飞行流程模式 */
  ENUM_ControlMode AutoManualMode;

  /* 通信状态 */
  ENUM_ComStatus comStatus;

  /* 最大爬升下降速度[m/s] */
  real_T maxClimbSpeed;

  /* 前置航点的纬度、经度、高度 */
  real_T prePathPoint_LLA[3];

  /* 当前航点的纬度、经度、高度 */
  real_T curPathPoint_LLA[3];

  /* 无人机位置，地面、空中 */
  ENUM_Where whereIsUAV;

  /* 自动或手动模式状态 */
  ENUM_AutoModeType typeAutoMode;

  /* 空速指令,[m/s] */
  real_T airspeedCmd;

  /* 执行倾转模式的高度 */
  real_T switchHeight;

  /* 任务中断点的纬度、经度、高度 */
  real_T LLATaskInterrupt[3];

  /* 任务完成标志，当抵达最后一个航点后，标志置true */
  boolean_T isTaskComplete;

  /* 起飞架次 */
  real_T numTakeOff;

  /* 航向是否在地面模式下自旋 */
  boolean_T isHeadingRotate_OnGround;

  /* 是否允许进入暂停模式 */
  boolean_T isAllowedToPause;

  /* 是否需要进行断点记录 */
  boolean_T isNeedToRecordBreak;

  /* 最后一个目标航点号（home点为1，航线航点从2开始） */
  real_T lastTargetPathPoint;
} BUS_TASK_PATH_OutParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_sU8UtumGmRbe8OcfmlVmIG_
#define DEFINED_TYPEDEF_FOR_struct_sU8UtumGmRbe8OcfmlVmIG_

typedef struct {
  real_T headingCmd;
  real_T groundspeedCmd;
  real_T heightCmd;
  ENUM_FlightTaskMode flightTaskMode;
  ENUM_FlightControlMode flightControlMode;
  real_T maxClimbSpeed;
  real_T turnCenterLL[2];
  real_T prePathPoint_LLA[3];
  real_T curPathPoint_LLA[3];
  real_T rollCmd;
} struct_sU8UtumGmRbe8OcfmlVmIG;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  Bus_wp loc;                          /* '<Root>/_DataStoreBlk_230' */
  BUS_TASK_PATH_OutParam PathModeOut_sl;/* '<Root>/_DataStoreBlk_86' */
  real_T accel_desired[3];             /* '<Root>/_DataStoreBlk_109' */
  real_T accel_error[3];               /* '<Root>/_DataStoreBlk_110' */
  real_T accel_target[3];              /* '<Root>/_DataStoreBlk_114' */
  real_T accel_xy_input[2];            /* '<Root>/_DataStoreBlk_117' */
  real_T attitude_ang_error[4];        /* '<Root>/_DataStoreBlk_139' */
  real_T attitude_error_vector[3];     /* '<Root>/_DataStoreBlk_140' */
  real_T attitude_target_ang_vel[3];   /* '<Root>/_DataStoreBlk_141' */
  real_T attitude_target_euler_angle[3];/* '<Root>/_DataStoreBlk_142' */
  real_T attitude_target_euler_rate[3];/* '<Root>/_DataStoreBlk_143' */
  real_T attitude_target_quat[4];      /* '<Root>/_DataStoreBlk_144' */
  real_T center_WP[2];                 /* '<Root>/_DataStoreBlk_146' */
  real_T curr_pos[2];                  /* '<Root>/_DataStoreBlk_151' */
  real_T curr_vel[3];                  /* '<Root>/_DataStoreBlk_152' */
  real_T current_loc[2];               /* '<Root>/_DataStoreBlk_153' */
  real_T groundspeed_vector[2];        /* '<Root>/_DataStoreBlk_179' */
  real_T loc_origin[2];                /* '<Root>/_DataStoreBlk_231' */
  real_T next_WP[2];                   /* '<Root>/_DataStoreBlk_246' */
  real_T pid_vel_xy_derivative[2];     /* '<Root>/_DataStoreBlk_273' */
  real_T pid_vel_xy_input[2];          /* '<Root>/_DataStoreBlk_274' */
  real_T pid_vel_xy_integrator[2];     /* '<Root>/_DataStoreBlk_275' */
  real_T pitch_factor[4];              /* '<Root>/_DataStoreBlk_280' */
  real_T pos_error[3];                 /* '<Root>/_DataStoreBlk_292' */
  real_T pos_target[3];                /* '<Root>/_DataStoreBlk_293' */
  real_T prev_WP[2];                   /* '<Root>/_DataStoreBlk_294' */
  real_T pwm_out[4];                   /* '<Root>/_DataStoreBlk_298' */
  real_T rate_target_ang_vel[3];       /* '<Root>/_DataStoreBlk_310' */
  real_T roll_factor[4];               /* '<Root>/_DataStoreBlk_324' */
  real_T rot_body_to_ned[9];           /* '<Root>/_DataStoreBlk_332' */
  real_T thrust_rpyt_out[4];           /* '<Root>/_DataStoreBlk_366' */
  real_T vdot_filter[5];               /* '<Root>/_DataStoreBlk_371' */
  real_T vel_desired[3];               /* '<Root>/_DataStoreBlk_372' */
  real_T vel_error[3];                 /* '<Root>/_DataStoreBlk_374' */
  real_T vel_last[3];                  /* '<Root>/_DataStoreBlk_381' */
  real_T vel_target[3];                /* '<Root>/_DataStoreBlk_382' */
  real_T yaw_factor[4];                /* '<Root>/_DataStoreBlk_388' */
  real_T AC_ATTITUDE_ACCEL_RP_CONTROLLER;/* '<Root>/_DataStoreBlk_1' */
  real_T ATC_RAT_PIT_FF;               /* '<Root>/_DataStoreBlk_10' */
  real_T TAS_dem_adj;                  /* '<Root>/_DataStoreBlk_100' */
  real_T TAS_rate_dem;                 /* '<Root>/_DataStoreBlk_101' */
  real_T TAS_state;                    /* '<Root>/_DataStoreBlk_102' */
  real_T TASmax;                       /* '<Root>/_DataStoreBlk_103' */
  real_T TASmin;                       /* '<Root>/_DataStoreBlk_104' */
  real_T THRmaxf;                      /* '<Root>/_DataStoreBlk_105' */
  real_T THRminf;                      /* '<Root>/_DataStoreBlk_106' */
  real_T Vz;                           /* '<Root>/_DataStoreBlk_107' */
  real_T WPcircle;                     /* '<Root>/_DataStoreBlk_108' */
  real_T ATC_RAT_PIT_FILT;             /* '<Root>/_DataStoreBlk_11' */
  real_T accel_last_z_cms;             /* '<Root>/_DataStoreBlk_111' */
  real_T accel_pitch_max;              /* '<Root>/_DataStoreBlk_112' */
  real_T accel_roll_max;               /* '<Root>/_DataStoreBlk_113' */
  real_T accel_x;                      /* '<Root>/_DataStoreBlk_115' */
  real_T accel_xy_angle_max;           /* '<Root>/_DataStoreBlk_116' */
  real_T accel_y;                      /* '<Root>/_DataStoreBlk_118' */
  real_T accel_yaw_max;                /* '<Root>/_DataStoreBlk_119' */
  real_T ATC_RAT_PIT_I;                /* '<Root>/_DataStoreBlk_12' */
  real_T accel_z;                      /* '<Root>/_DataStoreBlk_120' */
  real_T aerodynamic_load_factor;      /* '<Root>/_DataStoreBlk_121' */
  real_T air_density_ratio;            /* '<Root>/_DataStoreBlk_122' */
  real_T airspeed_max;                 /* '<Root>/_DataStoreBlk_123' */
  real_T airspeed_min;                 /* '<Root>/_DataStoreBlk_124' */
  real_T althold_lean_angle_max;       /* '<Root>/_DataStoreBlk_125' */
  real_T ang_vel_pitch_max;            /* '<Root>/_DataStoreBlk_126' */
  real_T ang_vel_roll_max;             /* '<Root>/_DataStoreBlk_127' */
  real_T ang_vel_yaw_max;              /* '<Root>/_DataStoreBlk_128' */
  real_T angle_boost;                  /* '<Root>/_DataStoreBlk_129' */
  real_T ATC_RAT_PIT_IMAX;             /* '<Root>/_DataStoreBlk_13' */
  real_T angle_boost_enabled;          /* '<Root>/_DataStoreBlk_130' */
  real_T angle_limit_tc;               /* '<Root>/_DataStoreBlk_131' */
  real_T armed;                        /* '<Root>/_DataStoreBlk_132' */
  real_T arspeed_filt;                 /* '<Root>/_DataStoreBlk_133' */
  real_T arspeed_temp;                 /* '<Root>/_DataStoreBlk_134' */
  real_T aspeed;                       /* '<Root>/_DataStoreBlk_135' */
  real_T aspeed_c2p;                   /* '<Root>/_DataStoreBlk_136' */
  real_T aspeed_c2ps;                  /* '<Root>/_DataStoreBlk_137' */
  real_T aspeed_cp;                    /* '<Root>/_DataStoreBlk_138' */
  real_T ATC_RAT_PIT_I_inint;          /* '<Root>/_DataStoreBlk_14' */
  real_T bearing_error;                /* '<Root>/_DataStoreBlk_145' */
  real_T climb_rate;                   /* '<Root>/_DataStoreBlk_147' */
  real_T climb_rate_cms;               /* '<Root>/_DataStoreBlk_148' */
  real_T crosstrack_error;             /* '<Root>/_DataStoreBlk_149' */
  real_T ATC_RAT_PIT_P;                /* '<Root>/_DataStoreBlk_15' */
  real_T curr_alt;                     /* '<Root>/_DataStoreBlk_150' */
  real_T current_tilt;                 /* '<Root>/_DataStoreBlk_154' */
  real_T data_is_stale;                /* '<Root>/_DataStoreBlk_155' */
  real_T desired_rate_pitch;           /* '<Root>/_DataStoreBlk_156' */
  real_T desired_rate_roll;            /* '<Root>/_DataStoreBlk_157' */
  real_T disable_integrator_pitch;     /* '<Root>/_DataStoreBlk_158' */
  real_T disable_integrator_roll;      /* '<Root>/_DataStoreBlk_159' */
  real_T ATC_RAT_RLL_D;                /* '<Root>/_DataStoreBlk_16' */
  real_T disable_integrator_yaw;       /* '<Root>/_DataStoreBlk_160' */
  real_T dist_min;                     /* '<Root>/_DataStoreBlk_161' */
  real_T dt;                           /* '<Root>/_DataStoreBlk_162' */
  real_T ff_throttle;                  /* '<Root>/_DataStoreBlk_163' */
  real_T freeze_ff_z;                  /* '<Root>/_DataStoreBlk_164' */
  real_T gains_D_pitch;                /* '<Root>/_DataStoreBlk_165' */
  real_T gains_D_roll;                 /* '<Root>/_DataStoreBlk_166' */
  real_T gains_FF_pitch;               /* '<Root>/_DataStoreBlk_167' */
  real_T gains_FF_roll;                /* '<Root>/_DataStoreBlk_168' */
  real_T gains_I_pitch;                /* '<Root>/_DataStoreBlk_169' */
  real_T ATC_RAT_RLL_FF;               /* '<Root>/_DataStoreBlk_17' */
  real_T gains_I_roll;                 /* '<Root>/_DataStoreBlk_170' */
  real_T gains_P_pitch;                /* '<Root>/_DataStoreBlk_171' */
  real_T gains_P_roll;                 /* '<Root>/_DataStoreBlk_172' */
  real_T gains_imax_pitch;             /* '<Root>/_DataStoreBlk_173' */
  real_T gains_imax_roll;              /* '<Root>/_DataStoreBlk_174' */
  real_T gains_rmax_roll;              /* '<Root>/_DataStoreBlk_175' */
  real_T gains_rmax_pitch;             /* '<Root>/_DataStoreBlk_176' */
  real_T gains_tau_pitch;              /* '<Root>/_DataStoreBlk_177' */
  real_T gains_tau_roll;               /* '<Root>/_DataStoreBlk_178' */
  real_T ATC_RAT_RLL_FILT;             /* '<Root>/_DataStoreBlk_18' */
  real_T gyro_x;                       /* '<Root>/_DataStoreBlk_180' */
  real_T gyro_y;                       /* '<Root>/_DataStoreBlk_181' */
  real_T gyro_z;                       /* '<Root>/_DataStoreBlk_182' */
  real_T height;                       /* '<Root>/_DataStoreBlk_183' */
  real_T hgt_dem;                      /* '<Root>/_DataStoreBlk_184' */
  real_T hgt_dem_adj;                  /* '<Root>/_DataStoreBlk_185' */
  real_T hgt_dem_adj_last;             /* '<Root>/_DataStoreBlk_186' */
  real_T hgt_dem_cm;                   /* '<Root>/_DataStoreBlk_187' */
  real_T hgt_dem_in_old;               /* '<Root>/_DataStoreBlk_188' */
  real_T hgt_dem_prev;                 /* '<Root>/_DataStoreBlk_189' */
  real_T ATC_RAT_RLL_I;                /* '<Root>/_DataStoreBlk_19' */
  real_T hgt_rate_dem;                 /* '<Root>/_DataStoreBlk_190' */
  real_T highest_airspeed;             /* '<Root>/_DataStoreBlk_191' */
  real_T imax_yaw;                     /* '<Root>/_DataStoreBlk_192' */
  real_T inint;                        /* '<Root>/_DataStoreBlk_193' */
  real_T inint_hgt;                    /* '<Root>/_DataStoreBlk_194' */
  real_T input_tc;                     /* '<Root>/_DataStoreBlk_195' */
  real_T integDTAS_state;              /* '<Root>/_DataStoreBlk_196' */
  real_T integGain;                    /* '<Root>/_DataStoreBlk_197' */
  real_T integSEB_state;               /* '<Root>/_DataStoreBlk_198' */
  real_T integTHR_state;               /* '<Root>/_DataStoreBlk_199' */
  real_T AC_ATTITUDE_ACCEL_RP_CONTROLL_a;/* '<Root>/_DataStoreBlk_2' */
  real_T ATC_RAT_RLL_IMAX;             /* '<Root>/_DataStoreBlk_20' */
  real_T integrator_yaw;               /* '<Root>/_DataStoreBlk_200' */
  real_T inverted_flight;              /* '<Root>/_DataStoreBlk_201' */
  real_T is_active_xy;                 /* '<Root>/_DataStoreBlk_202' */
  real_T is_active_z;                  /* '<Root>/_DataStoreBlk_203' */
  real_T k_aileron;                    /* '<Root>/_DataStoreBlk_204' */
  real_T k_elevator;                   /* '<Root>/_DataStoreBlk_205' */
  real_T k_rudder;                     /* '<Root>/_DataStoreBlk_206' */
  real_T k_throttle;                   /* '<Root>/_DataStoreBlk_207' */
  real_T k_throttle_c2p;               /* '<Root>/_DataStoreBlk_208' */
  real_T kff_rudder_mix;               /* '<Root>/_DataStoreBlk_209' */
  real_T ATC_RAT_RLL_I_inint;          /* '<Root>/_DataStoreBlk_21' */
  real_T kff_throttle_to_pitch;        /* '<Root>/_DataStoreBlk_210' */
  real_T last_Nu;                      /* '<Root>/_DataStoreBlk_211' */
  real_T last_out_pitch;               /* '<Root>/_DataStoreBlk_212' */
  real_T last_out_roll;                /* '<Root>/_DataStoreBlk_213' */
  real_T last_out_yaw;                 /* '<Root>/_DataStoreBlk_214' */
  real_T last_pitch_dem;               /* '<Root>/_DataStoreBlk_215' */
  real_T last_rate_hp_in_yaw;          /* '<Root>/_DataStoreBlk_216' */
  real_T last_rate_hp_out_yaw;         /* '<Root>/_DataStoreBlk_217' */
  real_T last_throttle_dem;            /* '<Root>/_DataStoreBlk_218' */
  real_T latAccDem;                    /* '<Root>/_DataStoreBlk_219' */
  real_T ATC_RAT_RLL_P;                /* '<Root>/_DataStoreBlk_22' */
  real_T leash;                        /* '<Root>/_DataStoreBlk_220' */
  real_T leash_down_z;                 /* '<Root>/_DataStoreBlk_221' */
  real_T leash_up_z;                   /* '<Root>/_DataStoreBlk_222' */
  real_T limit_accel_xy;               /* '<Root>/_DataStoreBlk_223' */
  real_T limit_pos_down;               /* '<Root>/_DataStoreBlk_224' */
  real_T limit_pos_up;                 /* '<Root>/_DataStoreBlk_225' */
  real_T limit_roll_pitch;             /* '<Root>/_DataStoreBlk_226' */
  real_T limit_vel_down;               /* '<Root>/_DataStoreBlk_227' */
  real_T limit_vel_up;                 /* '<Root>/_DataStoreBlk_228' */
  real_T limit_yaw;                    /* '<Root>/_DataStoreBlk_229' */
  real_T ATC_RAT_YAW_D;                /* '<Root>/_DataStoreBlk_23' */
  real_T loiter_bank_limit;            /* '<Root>/_DataStoreBlk_232' */
  real_T loiter_direction;             /* '<Root>/_DataStoreBlk_233' */
  real_T maxClimbRate;                 /* '<Root>/_DataStoreBlk_234' */
  real_T maxSinkRate;                  /* '<Root>/_DataStoreBlk_235' */
  real_T max_rate_neg;                 /* '<Root>/_DataStoreBlk_236' */
  real_T minSinkRate;                  /* '<Root>/_DataStoreBlk_237' */
  real_T mode;                         /* '<Root>/_DataStoreBlk_238' */
  real_T mode_L1;                      /* '<Root>/_DataStoreBlk_239' */
  real_T ATC_RAT_YAW_FF;               /* '<Root>/_DataStoreBlk_24' */
  real_T motors_limit_roll_pitch;      /* '<Root>/_DataStoreBlk_240' */
  real_T motors_limit_throttle_upper;  /* '<Root>/_DataStoreBlk_241' */
  real_T motors_limit_yaw;             /* '<Root>/_DataStoreBlk_242' */
  real_T nav_bearing;                  /* '<Root>/_DataStoreBlk_243' */
  real_T nav_pitch_cd;                 /* '<Root>/_DataStoreBlk_244' */
  real_T nav_roll_cd;                  /* '<Root>/_DataStoreBlk_245' */
  real_T p_angle_pitch;                /* '<Root>/_DataStoreBlk_247' */
  real_T p_angle_roll;                 /* '<Root>/_DataStoreBlk_248' */
  real_T p_angle_yaw;                  /* '<Root>/_DataStoreBlk_249' */
  real_T ATC_RAT_YAW_FILT;             /* '<Root>/_DataStoreBlk_25' */
  real_T p_ff_throttle;                /* '<Root>/_DataStoreBlk_250' */
  real_T p_plane_c2p;                  /* '<Root>/_DataStoreBlk_251' */
  real_T p_plane_cp;                   /* '<Root>/_DataStoreBlk_252' */
  real_T p_tail_tilt;                  /* '<Root>/_DataStoreBlk_253' */
  real_T p_tilt_pitch_target;          /* '<Root>/_DataStoreBlk_254' */
  real_T pid_accel_z_derivative;       /* '<Root>/_DataStoreBlk_255' */
  real_T pid_accel_z_input;            /* '<Root>/_DataStoreBlk_256' */
  real_T pid_accel_z_integrator;       /* '<Root>/_DataStoreBlk_257' */
  real_T pid_accel_z_reset_filter;     /* '<Root>/_DataStoreBlk_258' */
  real_T pid_info_D_pitch;             /* '<Root>/_DataStoreBlk_259' */
  real_T ATC_RAT_YAW_I;                /* '<Root>/_DataStoreBlk_26' */
  real_T pid_info_D_roll;              /* '<Root>/_DataStoreBlk_260' */
  real_T pid_info_D_yaw;               /* '<Root>/_DataStoreBlk_261' */
  real_T pid_info_FF_pitch;            /* '<Root>/_DataStoreBlk_262' */
  real_T pid_info_FF_roll;             /* '<Root>/_DataStoreBlk_263' */
  real_T pid_info_I_pitch;             /* '<Root>/_DataStoreBlk_264' */
  real_T pid_info_I_roll;              /* '<Root>/_DataStoreBlk_265' */
  real_T pid_info_I_yaw;               /* '<Root>/_DataStoreBlk_266' */
  real_T pid_info_P_pitch;             /* '<Root>/_DataStoreBlk_267' */
  real_T pid_info_P_roll;              /* '<Root>/_DataStoreBlk_268' */
  real_T pid_info_actual_pitch;        /* '<Root>/_DataStoreBlk_269' */
  real_T ATC_RAT_YAW_IMAX;             /* '<Root>/_DataStoreBlk_27' */
  real_T pid_info_actual_roll;         /* '<Root>/_DataStoreBlk_270' */
  real_T pid_info_desired_pitch;       /* '<Root>/_DataStoreBlk_271' */
  real_T pid_info_desired_roll;        /* '<Root>/_DataStoreBlk_272' */
  real_T pid_vel_xy_reset_filter;      /* '<Root>/_DataStoreBlk_276' */
  real_T pitch;                        /* '<Root>/_DataStoreBlk_277' */
  real_T pitch_dem;                    /* '<Root>/_DataStoreBlk_278' */
  real_T pitch_dem_unc;                /* '<Root>/_DataStoreBlk_279' */
  real_T ATC_RAT_YAW_I_inint;          /* '<Root>/_DataStoreBlk_28' */
  real_T pitch_in;                     /* '<Root>/_DataStoreBlk_281' */
  real_T pitch_limit_max_cd;           /* '<Root>/_DataStoreBlk_282' */
  real_T pitch_limit_min_cd;           /* '<Root>/_DataStoreBlk_283' */
  real_T pitch_max;                    /* '<Root>/_DataStoreBlk_284' */
  real_T pitch_max_limit;              /* '<Root>/_DataStoreBlk_285' */
  real_T pitch_min;                    /* '<Root>/_DataStoreBlk_286' */
  real_T pitch_target;                 /* '<Root>/_DataStoreBlk_287' */
  real_T pitch_target_c2p;             /* '<Root>/_DataStoreBlk_288' */
  real_T pitch_target_p2c;             /* '<Root>/_DataStoreBlk_289' */
  real_T ATC_RAT_YAW_P;                /* '<Root>/_DataStoreBlk_29' */
  real_T pitch_target_pilot;           /* '<Root>/_DataStoreBlk_290' */
  real_T ptchDamp;                     /* '<Root>/_DataStoreBlk_295' */
  real_T pwm_max;                      /* '<Root>/_DataStoreBlk_296' */
  real_T pwm_min;                      /* '<Root>/_DataStoreBlk_297' */
  real_T pwm_tail;                     /* '<Root>/_DataStoreBlk_299' */
  real_T AC_ATTITUDE_ACCEL_Y_CONTROLLER_;/* '<Root>/_DataStoreBlk_3' */
  real_T EAS2TAS;                      /* '<Root>/_DataStoreBlk_30' */
  real_T radius;                       /* '<Root>/_DataStoreBlk_300' */
  real_T rate_bf_ff_enabled;           /* '<Root>/_DataStoreBlk_301' */
  real_T rate_pitch_pid_derivative;    /* '<Root>/_DataStoreBlk_302' */
  real_T rate_pitch_pid_input;         /* '<Root>/_DataStoreBlk_303' */
  real_T rate_pitch_pid_integrator;    /* '<Root>/_DataStoreBlk_304' */
  real_T rate_pitch_pid_reset_filter;  /* '<Root>/_DataStoreBlk_305' */
  real_T rate_roll_pid_derivative;     /* '<Root>/_DataStoreBlk_306' */
  real_T rate_roll_pid_input;          /* '<Root>/_DataStoreBlk_307' */
  real_T rate_roll_pid_integrator;     /* '<Root>/_DataStoreBlk_308' */
  real_T rate_roll_pid_reset_filter;   /* '<Root>/_DataStoreBlk_309' */
  real_T EAS_dem;                      /* '<Root>/_DataStoreBlk_31' */
  real_T rate_yaw_pid_derivative;      /* '<Root>/_DataStoreBlk_311' */
  real_T rate_yaw_pid_input;           /* '<Root>/_DataStoreBlk_312' */
  real_T rate_yaw_pid_integrator;      /* '<Root>/_DataStoreBlk_313' */
  real_T rate_yaw_pid_reset_filter;    /* '<Root>/_DataStoreBlk_314' */
  real_T recalc_leash_xy;              /* '<Root>/_DataStoreBlk_315' */
  real_T recalc_leash_z;               /* '<Root>/_DataStoreBlk_316' */
  real_T reset_accel_to_lean_xy;       /* '<Root>/_DataStoreBlk_317' */
  real_T reset_accel_to_throttle;      /* '<Root>/_DataStoreBlk_318' */
  real_T reset_desired_vel_to_pos;     /* '<Root>/_DataStoreBlk_319' */
  real_T EAS_dem_cm;                   /* '<Root>/_DataStoreBlk_32' */
  real_T reset_rate_to_accel_z;        /* '<Root>/_DataStoreBlk_320' */
  real_T reverse;                      /* '<Root>/_DataStoreBlk_321' */
  real_T roll;                         /* '<Root>/_DataStoreBlk_322' */
  real_T rollComp;                     /* '<Root>/_DataStoreBlk_323' */
  real_T roll_ff_pitch;                /* '<Root>/_DataStoreBlk_325' */
  real_T roll_ff_pitch_inint;          /* '<Root>/_DataStoreBlk_326' */
  real_T roll_in;                      /* '<Root>/_DataStoreBlk_327' */
  real_T roll_limit_cd;                /* '<Root>/_DataStoreBlk_328' */
  real_T roll_limit_cd_inint;          /* '<Root>/_DataStoreBlk_329' */
  real_T GRAVITY_MSS;                  /* '<Root>/_DataStoreBlk_33' */
  real_T roll_target;                  /* '<Root>/_DataStoreBlk_330' */
  real_T roll_target_pilot;            /* '<Root>/_DataStoreBlk_331' */
  real_T scaling_speed;                /* '<Root>/_DataStoreBlk_333' */
  real_T slew_yaw;                     /* '<Root>/_DataStoreBlk_334' */
  real_T smoothed_airspeed;            /* '<Root>/_DataStoreBlk_335' */
  real_T spdCompFiltOmega;             /* '<Root>/_DataStoreBlk_336' */
  real_T spdWeight;                    /* '<Root>/_DataStoreBlk_337' */
  real_T tail_tilt;                    /* '<Root>/_DataStoreBlk_338' */
  real_T tail_tilt_c2p;                /* '<Root>/_DataStoreBlk_339' */
  real_T HD;                           /* '<Root>/_DataStoreBlk_34' */
  real_T tail_tilt_p2c;                /* '<Root>/_DataStoreBlk_340' */
  real_T tail_tilt_rate;               /* '<Root>/_DataStoreBlk_341' */
  real_T take_off_land;                /* '<Root>/_DataStoreBlk_342' */
  real_T target_bearing_cd;            /* '<Root>/_DataStoreBlk_343' */
  real_T target_yaw_rate;              /* '<Root>/_DataStoreBlk_344' */
  real_T thrDamp;                      /* '<Root>/_DataStoreBlk_345' */
  real_T thr_out_min;                  /* '<Root>/_DataStoreBlk_346' */
  real_T throttle_avg_max;             /* '<Root>/_DataStoreBlk_347' */
  real_T throttle_cruise;              /* '<Root>/_DataStoreBlk_348' */
  real_T throttle_cutoff_frequency;    /* '<Root>/_DataStoreBlk_349' */
  real_T K_A_yaw;                      /* '<Root>/_DataStoreBlk_35' */
  real_T throttle_dem;                 /* '<Root>/_DataStoreBlk_350' */
  real_T throttle_filter;              /* '<Root>/_DataStoreBlk_351' */
  real_T throttle_ground;              /* '<Root>/_DataStoreBlk_352' */
  real_T throttle_hover;               /* '<Root>/_DataStoreBlk_353' */
  real_T throttle_in;                  /* '<Root>/_DataStoreBlk_354' */
  real_T throttle_lower;               /* '<Root>/_DataStoreBlk_355' */
  real_T throttle_max;                 /* '<Root>/_DataStoreBlk_356' */
  real_T throttle_min;                 /* '<Root>/_DataStoreBlk_357' */
  real_T throttle_off_rate;            /* '<Root>/_DataStoreBlk_358' */
  real_T throttle_rpy_mix;             /* '<Root>/_DataStoreBlk_359' */
  real_T K_D_last_yaw;                 /* '<Root>/_DataStoreBlk_36' */
  real_T throttle_slewrate;            /* '<Root>/_DataStoreBlk_360' */
  real_T throttle_thrust_max;          /* '<Root>/_DataStoreBlk_361' */
  real_T throttle_upper;               /* '<Root>/_DataStoreBlk_362' */
  real_T thrust_boost;                 /* '<Root>/_DataStoreBlk_363' */
  real_T thrust_boost_ratio;           /* '<Root>/_DataStoreBlk_364' */
  real_T thrust_error_angle;           /* '<Root>/_DataStoreBlk_365' */
  real_T thrust_slew_time;             /* '<Root>/_DataStoreBlk_367' */
  real_T timeConstant;                 /* '<Root>/_DataStoreBlk_368' */
  real_T use_desvel_ff_z;              /* '<Root>/_DataStoreBlk_369' */
  real_T K_D_yaw;                      /* '<Root>/_DataStoreBlk_37' */
  real_T use_sqrt_controller;          /* '<Root>/_DataStoreBlk_370' */
  real_T vel_dot;                      /* '<Root>/_DataStoreBlk_373' */
  real_T vel_error_input;              /* '<Root>/_DataStoreBlk_375' */
  real_T vel_forward_gain;             /* '<Root>/_DataStoreBlk_376' */
  real_T vel_forward_integrator;       /* '<Root>/_DataStoreBlk_377' */
  real_T vel_forward_last_pct;         /* '<Root>/_DataStoreBlk_378' */
  real_T vel_forward_min_pitch;        /* '<Root>/_DataStoreBlk_379' */
  real_T K_FF_yaw;                     /* '<Root>/_DataStoreBlk_38' */
  real_T vel_forward_tail_tilt_max;    /* '<Root>/_DataStoreBlk_380' */
  real_T vertAccLim;                   /* '<Root>/_DataStoreBlk_383' */
  real_T weathervane_gain;             /* '<Root>/_DataStoreBlk_384' */
  real_T weathervane_last_output;      /* '<Root>/_DataStoreBlk_385' */
  real_T weathervane_min_roll;         /* '<Root>/_DataStoreBlk_386' */
  real_T yaw;                          /* '<Root>/_DataStoreBlk_387' */
  real_T yaw_headroom;                 /* '<Root>/_DataStoreBlk_389' */
  real_T K_FF_yaw_inint;               /* '<Root>/_DataStoreBlk_39' */
  real_T yaw_in;                       /* '<Root>/_DataStoreBlk_390' */
  real_T yaw_in_max;                   /* '<Root>/_DataStoreBlk_391' */
  real_T yaw_max_c2p;                  /* '<Root>/_DataStoreBlk_392' */
  real_T yaw_rate_max;                 /* '<Root>/_DataStoreBlk_393' */
  real_T z_accel_meas;                 /* '<Root>/_DataStoreBlk_394' */
  real_T AC_ATTITUDE_ACCEL_Y_CONTROLLE_j;/* '<Root>/_DataStoreBlk_4' */
  real_T K_I_yaw;                      /* '<Root>/_DataStoreBlk_40' */
  real_T Kx;                           /* '<Root>/_DataStoreBlk_41' */
  real_T L1_damping;                   /* '<Root>/_DataStoreBlk_42' */
  real_T L1_dist;                      /* '<Root>/_DataStoreBlk_43' */
  real_T L1_period;                    /* '<Root>/_DataStoreBlk_44' */
  real_T L1_radius;                    /* '<Root>/_DataStoreBlk_45' */
  real_T L1_xtrack_i;                  /* '<Root>/_DataStoreBlk_46' */
  real_T L1_xtrack_i_gain;             /* '<Root>/_DataStoreBlk_47' */
  real_T L1_xtrack_i_gain_prev;        /* '<Root>/_DataStoreBlk_48' */
  real_T LOCATION_SCALING_FACTOR;      /* '<Root>/_DataStoreBlk_49' */
  real_T AC_ATTITUDE_CONTROL_ANGLE_LIMIT;/* '<Root>/_DataStoreBlk_5' */
  real_T LOCATION_SCALING_FACTOR_INV;  /* '<Root>/_DataStoreBlk_50' */
  real_T PITCHmaxf;                    /* '<Root>/_DataStoreBlk_51' */
  real_T PITCHminf;                    /* '<Root>/_DataStoreBlk_52' */
  real_T POSCONTROL_ACCELERATION_MIN;  /* '<Root>/_DataStoreBlk_53' */
  real_T POSCONTROL_ACCEL_FILTER_HZ;   /* '<Root>/_DataStoreBlk_54' */
  real_T POSCONTROL_ACCEL_XY;          /* '<Root>/_DataStoreBlk_55' */
  real_T POSCONTROL_ACCEL_XY_MAX;      /* '<Root>/_DataStoreBlk_56' */
  real_T POSCONTROL_ACCEL_Z;           /* '<Root>/_DataStoreBlk_57' */
  real_T POSCONTROL_ACC_Z_D;           /* '<Root>/_DataStoreBlk_58' */
  real_T POSCONTROL_ACC_Z_FILT_HZ;     /* '<Root>/_DataStoreBlk_59' */
  real_T AC_ATTITUDE_THRUST_ERROR_ANGLE;/* '<Root>/_DataStoreBlk_6' */
  real_T POSCONTROL_ACC_Z_FILT_HZ_c2p; /* '<Root>/_DataStoreBlk_60' */
  real_T POSCONTROL_ACC_Z_FILT_HZ_inint;/* '<Root>/_DataStoreBlk_61' */
  real_T POSCONTROL_ACC_Z_I;           /* '<Root>/_DataStoreBlk_62' */
  real_T POSCONTROL_ACC_Z_IMAX;        /* '<Root>/_DataStoreBlk_63' */
  real_T POSCONTROL_ACC_Z_I_inint;     /* '<Root>/_DataStoreBlk_64' */
  real_T POSCONTROL_ACC_Z_P;           /* '<Root>/_DataStoreBlk_65' */
  real_T POSCONTROL_JERK_RATIO;        /* '<Root>/_DataStoreBlk_66' */
  real_T POSCONTROL_LEASH_LENGTH_MIN;  /* '<Root>/_DataStoreBlk_67' */
  real_T POSCONTROL_OVERSPEED_GAIN_Z;  /* '<Root>/_DataStoreBlk_68' */
  real_T POSCONTROL_POS_XY_P;          /* '<Root>/_DataStoreBlk_69' */
  real_T AP_MOTORS_MATRIX_YAW_FACTOR_CCW;/* '<Root>/_DataStoreBlk_7' */
  real_T POSCONTROL_POS_Z_P;           /* '<Root>/_DataStoreBlk_70' */
  real_T POSCONTROL_SPEED;             /* '<Root>/_DataStoreBlk_71' */
  real_T POSCONTROL_SPEED_DOWN;        /* '<Root>/_DataStoreBlk_72' */
  real_T POSCONTROL_SPEED_UP;          /* '<Root>/_DataStoreBlk_73' */
  real_T POSCONTROL_STOPPING_DIST_DOWN_M;/* '<Root>/_DataStoreBlk_74' */
  real_T POSCONTROL_STOPPING_DIST_UP_MAX;/* '<Root>/_DataStoreBlk_75' */
  real_T POSCONTROL_THROTTLE_CUTOFF_FREQ;/* '<Root>/_DataStoreBlk_76' */
  real_T POSCONTROL_VEL_ERROR_CUTOFF_FRE;/* '<Root>/_DataStoreBlk_77' */
  real_T POSCONTROL_VEL_XY_D;          /* '<Root>/_DataStoreBlk_78' */
  real_T POSCONTROL_VEL_XY_FILT_D_HZ;  /* '<Root>/_DataStoreBlk_79' */
  real_T AP_MOTORS_MATRIX_YAW_FACTOR_CW;/* '<Root>/_DataStoreBlk_8' */
  real_T POSCONTROL_VEL_XY_FILT_HZ;    /* '<Root>/_DataStoreBlk_80' */
  real_T POSCONTROL_VEL_XY_I;          /* '<Root>/_DataStoreBlk_81' */
  real_T POSCONTROL_VEL_XY_IMAX;       /* '<Root>/_DataStoreBlk_82' */
  real_T POSCONTROL_VEL_XY_I_inint;    /* '<Root>/_DataStoreBlk_83' */
  real_T POSCONTROL_VEL_XY_P;          /* '<Root>/_DataStoreBlk_84' */
  real_T POSCONTROL_VEL_Z_P;           /* '<Root>/_DataStoreBlk_85' */
  real_T SKE_dem;                      /* '<Root>/_DataStoreBlk_87' */
  real_T SKE_est;                      /* '<Root>/_DataStoreBlk_88' */
  real_T SKEdot;                       /* '<Root>/_DataStoreBlk_89' */
  real_T ATC_RAT_PIT_D;                /* '<Root>/_DataStoreBlk_9' */
  real_T SKEdot_dem;                   /* '<Root>/_DataStoreBlk_90' */
  real_T SPE_dem;                      /* '<Root>/_DataStoreBlk_91' */
  real_T SPE_est;                      /* '<Root>/_DataStoreBlk_92' */
  real_T SPEdot;                       /* '<Root>/_DataStoreBlk_93' */
  real_T SPEdot_dem;                   /* '<Root>/_DataStoreBlk_94' */
  real_T STE_error;                    /* '<Root>/_DataStoreBlk_95' */
  real_T STEdotErrLast;                /* '<Root>/_DataStoreBlk_96' */
  real_T STEdot_max;                   /* '<Root>/_DataStoreBlk_97' */
  real_T STEdot_min;                   /* '<Root>/_DataStoreBlk_98' */
  real_T TAS_dem;                      /* '<Root>/_DataStoreBlk_99' */
  real_T mode_state; /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T WP_i;       /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T mode_L1_old;/* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T WP_i_o;     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T uavMode;    /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T Rotor2Fix_delay;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T Rotor2Fix_delay_flag;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T uavMode_p;  /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T Rotor2Fix_delay_b;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T Rotor2Fix_delay_flag_h;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T TakeOffMode_delay;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T TakeOffMode_delay_flag;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T mode_state_j;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T WP_i_m;     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T WP_i_a;     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T uavMode_j;  /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T Rotor2Fix_delay_flag_n;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T uavMode_d;  /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T Rotor2Fix_delay_flag_i;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T TakeOffMode_delay_m;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T TakeOffMode_delay_flag_m;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T mode_state_c;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  real_T WP_i_h;     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  ENUM_plane_mode plane_mode;          /* '<Root>/_DataStoreBlk_291' */
  ENUM_FlightTaskMode PathMode;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  ENUM_FlightTaskMode PathMode_j;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  ENUM_FlightTaskMode PathMode_g;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
  ENUM_FlightTaskMode PathMode_d;
                     /* '<Root>/input_euler_angle_roll_pitch_euler_rate_yaw4' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: loc
   * Referenced by: '<Root>/_DataStoreBlk_230'
   */
  Bus_wp _DataStoreBlk_230_InitialValue;

  /* Expression: rot_body_to_ned
   * Referenced by: '<Root>/_DataStoreBlk_332'
   */
  real_T _DataStoreBlk_332_InitialValue[9];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

/* External data declarations for dependent source files */
extern const BUS_TASK_PATH_OutParam
  input_euler_angle_roll_pitch_eu_rtZBUS_TASK_PATH_OutParam;/* BUS_TASK_PATH_OutParam ground */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void input_euler_angle_roll_pitch_eu_initialize(RT_MODEL *const rtM);
extern void input_euler_angle_roll_pitch_eu_step(RT_MODEL *const rtM);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Copter_Plane_h2g_4_and_1/input_euler_angle_roll_pitch_euler_rate_yaw4')    - opens subsystem Copter_Plane_h2g_4_and_1/input_euler_angle_roll_pitch_euler_rate_yaw4
 * hilite_system('Copter_Plane_h2g_4_and_1/input_euler_angle_roll_pitch_euler_rate_yaw4/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Copter_Plane_h2g_4_and_1'
 * '<S1>'   : 'Copter_Plane_h2g_4_and_1/input_euler_angle_roll_pitch_euler_rate_yaw4'
 */
#endif                       /* RTW_HEADER_input_euler_angle_roll_pitch_eu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
