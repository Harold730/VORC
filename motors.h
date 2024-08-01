#include <stdio.h>
#include <Wire.h>
#include <cmath>
#include <PCA9685.h>

#define MIN_PWM 0
#define MAX_PWM 4095

// PWM channels of pca9685 0-16
#define PWM_CHANNEL1 9
#define PWM_CHANNEL2 8
#define PWM_CHANNEL3 11
#define PWM_CHANNEL4 10

PCA9685 pwm;

void setPWMMotors(int c1, int c2, int c3, int c4)
{
  char dbg_str[30];
  sprintf(dbg_str,"C1: %d\tC2: %d\tC3: %d\tC4: %d",c1,c2,c3,c4);
  Serial.println(dbg_str);

  pwm.setChannelPwm(PWM_CHANNEL1, c1);
  pwm.setChannelPwm(PWM_CHANNEL2, c2);
  pwm.setChannelPwm(PWM_CHANNEL3, c3);
  pwm.setChannelPwm(PWM_CHANNEL4, c4);
}

void initMotors()
{
  Wire.begin();

  pwm.resetDevices();

  pwm.init();

  pwm.setPWMFrequency(50);

  setPWMMotors(0, 0, 0, 0);
}