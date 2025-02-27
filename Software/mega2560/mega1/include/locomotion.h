#ifndef LOCOMOTION_H
#define LOCOMOTION_H

#include <Arduino.h>
#include <ros.h>
#include <util/atomic.h>

#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Float32MultiArray.h>

// Locomotion Defs
// same driver
// Front Left Motor Out34 Yellow -, Brown +
// Front Right Motor Out12 Brown +, Orange -

// same driver
// Rear Left Motor Out12 Yellow -. Black +
// Rear Right Motor Out34 Red +, Black -

#define FRONT_LEFT_PIN1 30
#define FRONT_LEFT_PIN2 32
#define FRONT_RIGHT_PIN1 34
#define FRONT_RIGHT_PIN2 36
#define REAR_LEFT_PIN1 26
#define REAR_LEFT_PIN2 28
#define REAR_RIGHT_PIN1 22
#define REAR_RIGHT_PIN2 24

#define REAR_LEFT_SPEED_PIN 10
#define REAR_RIGHT_SPEED_PIN 11
#define FRONT_LEFT_SPEED_PIN 12
#define FRONT_RIGHT_SPEED_PIN 13

// ENCA always need to be at an interrupt pin
#define FRONT_RIGHT_ENCA 19
#define FRONT_RIGHT_ENCB 5
#define FRONT_LEFT_ENCA 2
#define FRONT_LEFT_ENCB 6
#define REAR_RIGHT_ENCA 18
#define REAR_RIGHT_ENCB 7
#define REAR_LEFT_ENCA 3
#define REAR_LEFT_ENCB 4

#define MAX_ERROR_COUNT 14

#define CLICKS_PER_ROTATION 562.2

namespace locomotion
{
// Locomotion Data
extern geometry_msgs::Twist t_stateMotorLocomotion;
extern std_msgs::Int32MultiArray i32_motorPosData;
// array format front_left, front_right, rear_left, rear_right
extern int32_t enc_pos[4];
extern volatile int32_t enc_pos_i[4];
extern float enc_vel[4];
extern volatile float enc_vel_i[4];
extern volatile float xyz[4];

extern int error_count[4];
extern bool startCheck;
extern bool newDir;

extern float deltaT;

extern std_msgs::Float32MultiArray af32_velocity;
extern ros::Publisher velocity;

// Locomotion Pub/Sub
extern ros::Publisher motorState;
extern ros::Publisher encoder;
extern ros::Subscriber<geometry_msgs::Twist> cmd_vel;

/**
 * @brief Digital write to motor_pin1 and motor_pin2 to command direction and speed. Used for the locomotion subsystem.
 *
 * @param motor_pin1 Pin1 (digital value) for locomotion motor for which the direction is being set
 * @param motor_pin2 Pin2 (digital value) for locomotion motor for which the direction is being set
 * @param speed_pin Speed pin (analog value) for locomotion motor for which the speed is being set
 * @param motor_speed [-255.0,255.0] range for from Twist message which encodes cmd direction and speed
 */
void set_motor_speed(int motor_pin1, int motor_pin2, int speed_pin, float motor_speed);

/**
 * @brief Decodes geometry_msgs::Twist message to get linear x and y and angular z. Calculates each wheel speed and
 * directions and then writes values to pins.
 *
 * @param cmd_vel Updated geometry_msgs::Twist value published to /locomotion/cmd_vel
 */
void cmdVelCallback(const geometry_msgs::Twist& cmd_vel);

/**
 * @brief Set the locomotion speed for each motor based on the pi_control output
 *
 */
void set_locomotion_speed();

/**
 * @brief Update published encoder value
 *
 */
void updateEncoder();

/**
 * @brief Update published velocity value
 *
 */
void updateVelocity();

/**
 * @brief interrupt service routine for front left encoder , increments position + or - based on direction
 *
 */
void readFrontLeftEncoder();

/**
 * @brief interrupt service routine for front right encoder , increments position + or - based on direction
 *
 */
void readFrontRightEncoder();

/**
 * @brief interrupt service routine for rear left encoder , increments position + or - based on direction
 *
 */
void readRearLeftEncoder();

/**
 * @brief interrupt service routine for rear right encoder , increments position + or - based on direction
 *
 */
void readRearRightEncoder();

/**
 * @brief Compute velocity from encoder position data and deltaT
 *
 * @param vel value updated by reference
 */
void computeVelocity(volatile float* vel);

/**
 * @brief Low-pass filter for the velocity to remove high frequency oscillations from velocity measurements
 *
 * @param vel value updated by reference
 */
void lowPassFilter(volatile float* vel);

// updates value pointed to by pwr
/**
 * @brief PI controller for locomotion velocity control
 *
 * @param vel value read by reference
 * @param pwr value updated by reference
 * @param xyz velocity in RPM for each motor (front left, front right, rear left, rear right)
 */
void pi_control(float* vel, int* pwr, volatile float* xyz);

/**
 * @brief Stop all motors
*/
void e_stop();

/**
 * @brief Initialization for the locomotion namespace
 *
 * @param nh Pointer to the ROS node handle
 */
void init(ros::NodeHandle* nh);

}  // namespace locomotion

#endif
