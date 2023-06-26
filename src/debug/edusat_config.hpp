#pragma once
#include <Arduino.h>

// LED
constexpr uint8_t LED_DEFAULT_PIN = 2;
// 電熱線
constexpr uint8_t HEAT_DEFAULT_PIN = 15;
// タクトスイッチ
constexpr uint8_t BUTTON_DEFAULT_PIN = 35;
// 左モータ
constexpr uint8_t LEFT_MOTOR_PLUS_DEFAULT_PIN = 4;
constexpr uint8_t LEFT_MOTOR_MINUS_DEFAULT_PIN = 13;
constexpr uint8_t LEFT_MOTOR_PWM_DEFAULT_PIN = 25;
constexpr uint8_t LEFT_MOTOR_LEDC_CHANNEL = 0;
// 右モータ
constexpr uint8_t RIGHT_MOTOR_PLUS_DEFAULT_PIN = 14;
constexpr uint8_t RIGHT_MOTOR_MINUS_DEFAULT_PIN = 27;
constexpr uint8_t RIGHT_MOTOR_PWM_DEFAULT_PIN = 26;
constexpr uint8_t RIGHT_MOTOR_LEDC_CHANNEL = 1;
// モータLEDC設定
constexpr uint8_t LEDC_TIMER_8_BIT = 8;
constexpr double LEDC_BASE_FREQ_490 = 490.0;
// SDカード
constexpr uint8_t SD_MISO_DEFAULT_PIN = 19;
constexpr uint8_t SD_MOSI_DEFAULT_PIN = 23;
constexpr uint8_t SD_SCLK_DEFAULT_PIN = 18;
constexpr uint8_t SD_CS_DEFAULT_PIN = 5;
// スピーカー
constexpr uint8_t SPEAKER_DEFAULT_PIN = 12;
constexpr uint8_t SPEAKER_LEDC_CHANNEL = 2;
// スピーカーLEDC設定
constexpr uint8_t LEDC_TIMER_13_BIT = 13;
constexpr double LEDC_BASE_FREQ_5000 = 5000.0;
// GPSセンサ
constexpr uint8_t GPS_TX_DEFAULT_PIN = 16;
constexpr uint8_t GPS_RX_DEFAULT_PIN = 17;
// 9軸センサ
constexpr uint8_t I2C_SDA_DEFAULT_PIN = 21;
constexpr uint8_t I2C_SCL_DEFAULT_PIN = 22;
