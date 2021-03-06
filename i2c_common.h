#include "stdint.h"

#ifndef COMMON_H
#define COMMON_H

/* Package signed value before sending it on the 12c bus.
 *
 * Data is lost if num uses more than 14 bits. */
inline uint16_t package_signed(int16_t num) {
    return num & 0x7fff;
}

/* Restore the signed form of an integer sent over the i2c bus. */
inline int16_t restore_signed(uint16_t num) {
    return (int16_t)(((num & 0x4000) << 1) | num);
}

#define STEERING_MODULE_SLAVE_ADDRESS 0x51
#define SENSOR_MODULE_SLAVE_ADDRESS   0x52

#define STEERING_MANUAL_GAS       0xfff0
#define STEERING_MANUAL_ANG       0xfff1
#define STEERING_CUR_VEL          0xfff2
#define STEERING_REF_VEL          0xfff3
#define STEERING_CUR_LAT          0xfff4
#define STEERING_CUR_ANG          0xfff5
#define STEERING_STEERING_KP      0xfff6
#define STEERING_STEERING_KD      0xfff7
#define STEERING_SPEED_KP         0xfff8
#define STEERING_SPEED_KI         0xfff9
#define STEERING_ANGLE_OFFSET     0xfffA
#define STEERING_TURN_KD          0xfffB
#define STEERING_REGULATION_MODE  0xfffC

#define REGULATION_MODE_MANUAL       0
#define REGULATION_MODE_AUTO_FORWARD 1
#define REGULATION_MODE_AUTO_TURN    2

#define STEERING_RETURN_GAS       0xfff0
#define STEERING_RETURN_ANG       0xfff1

#define SENSOR_OBSTACLE_DISTANCE      0xfff0
#define SENSOR_LEFT_DRIVING_DISTANCE  0xfff1
#define SENSOR_RIGHT_DRIVING_DISTANCE 0xfff2
#define SENSOR_LEFT_SPEED             0xfff3
#define SENSOR_RIGHT_SPEED            0xfff4

#endif  // COMMON_H
