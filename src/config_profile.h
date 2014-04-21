#pragma once

typedef struct profile_s {
    uint8_t pidController;                  // 0 = multiwii original, 1 = rewrite from http://www.multiwii.com/forum/viewtopic.php?f=8&t=3671
    uint8_t P8[PID_ITEM_COUNT];
    uint8_t I8[PID_ITEM_COUNT];
    uint8_t D8[PID_ITEM_COUNT];

    controlRateConfig_t controlRateConfig;

    uint8_t dynThrPID;
    uint16_t tpaBreakPoint;                  // Breakpoint where TPA is activated
    int16_t mag_declination;                // Get your magnetic decliniation from here : http://magnetic-declination.com/
    int16_t angleTrim[ANGLE_INDEX_COUNT];   // accelerometer trim

    // sensor-related stuff
    uint8_t acc_lpf_factor;                 // Set the Low Pass Filter factor for ACC. Increasing this value would reduce ACC noise (visible in GUI), but would increase ACC lag time. Zero = no filter
    uint8_t accz_deadband;                  // set the acc deadband for z-Axis, this ignores small accelerations
    uint8_t accxy_deadband;                 // set the acc deadband for xy-Axis
    uint8_t baro_tab_size;                  // size of baro filter array
    float baro_noise_lpf;                   // additional LPF to reduce baro noise
    float baro_cf_vel;                      // apply Complimentary Filter to keep the calculated velocity based on baro velocity (i.e. near real velocity)
    float baro_cf_alt;                      // apply CF to use ACC for height estimation
    uint8_t acc_unarmedcal;                 // turn automatic acc compensation on/off

    uint16_t activate[CHECKBOX_ITEM_COUNT]; // activate switches

    // Radio/ESC-related configuration
    uint8_t deadband;                       // introduce a deadband around the stick center for pitch and roll axis. Must be greater than zero.
    uint8_t yawdeadband;                    // introduce a deadband around the stick center for yaw axis. Must be greater than zero.
    uint8_t alt_hold_throttle_neutral;      // defines the neutral zone of throttle stick during altitude hold, default setting is +/-40
    uint8_t alt_hold_fast_change;           // when disabled, turn off the althold when throttle stick is out of deadband defined with alt_hold_throttle_neutral; when enabled, altitude changes slowly proportional to stick movement
    uint16_t throttle_correction_angle;     // the angle when the throttle correction is maximal. in 0.1 degres, ex 225 = 22.5 ,30.0, 450 = 45.0 deg
    uint8_t throttle_correction_value;      // the correction that will be applied at throttle_correction_angle.

    // Servo-related stuff
    servoParam_t servoConf[MAX_SUPPORTED_SERVOS]; // servo configuration

    // Failsafe related configuration
    failsafeConfig_t failsafeConfig;

    // mixer-related configuration
    int8_t yaw_direction;
    uint8_t tri_unarmed_servo;              // send tail servo correction pulses even when unarmed

    // gimbal-related configuration
    uint8_t gimbal_flags;                   // in servotilt mode, various things that affect stuff

    // gps-related stuff
    uint16_t gps_wp_radius;                 // if we are within this distance to a waypoint then we consider it reached (distance is in cm)
    uint8_t gps_lpf;                        // Low pass filter cut frequency for derivative calculation (default 20Hz)
    uint8_t nav_slew_rate;                  // Adds a rate control to nav output, will smoothen out nav angle spikes
    uint8_t nav_controls_heading;           // copter faces toward the navigation point, maghold must be enabled for it
    uint16_t nav_speed_min;                 // cm/sec
    uint16_t nav_speed_max;                 // cm/sec
    uint16_t ap_mode;                       // Temporarily Disables GPS_HOLD_MODE to be able to make it possible to adjust the Hold-position when moving the sticks, creating a deadspan for GPS
} profile_t;
