#include <obniz.h>
#include "MPU9250.h"
#include "edusat_config.hpp"
#include "mysd.hpp"

MPU9250 mpu;
MySD sd;
char message[50];

void setup() {
    Serial.begin(115200);

    obnizInit();

    // Wire.begin は obnizInit の処理のあとに書く
    // ※9軸センサで使用するピンをobnizOSの管理から外していないと利用できないため
    Wire.begin();
    delay(2000);

    // 9軸センサの初期化処理
    if (!mpu.setup(0x68)) {
        Serial.println("failed to connect sensor");
        while(1);
    }

    // SDカードの初期化処理
    if (!sd.init()) {
        Serial.println("failed to initialize sd card");
        while(1);
    }
    sd.writeFile("/log.txt", "debug sample start\n"); // ログ用のファイルを作成する

    delay(2000);
}

void loop() {
    if (mpu.update()) {

        // 有線（シリアル通信）でデバッグする場合
        Serial.print("acc x: ");
        Serial.print(mpu.getAccX());
        Serial.print(", y: ");
        Serial.print(mpu.getAccY());
        Serial.print(", z: ");
        Serial.println(mpu.getAccZ());

        // 無線 または SDカード 用にメッセージを用意
        snprintf(
            message,
            sizeof(message),
            "acc x: %.2f, y: %.2f, z: %.2f\n",
            mpu.getAccX(), mpu.getAccY(), mpu.getAccZ()
        );

        // 無線（Wi-Fi）でデバッグする場合
        obniz.commandSend((uint8_t*)message, strlen(message));

        // SDカードに記録する場合
        sd.appendFile("/log.txt", message);

        delay(100);
    }
}

/** obnizOSの初期化処理 */
void obnizInit() {
    obniz.start();
    obniz.pinReserve(I2C_SDA_DEFAULT_PIN); // 9軸センサで使用するピンをobnizOSの管理から外す
    obniz.pinReserve(I2C_SCL_DEFAULT_PIN); // 9軸センサで使用するピンをobnizOSの管理から外す
    obniz.pinReserve(SD_MISO_DEFAULT_PIN); // SDカードで使用するピンをobnizOSの管理から外す
    obniz.pinReserve(SD_MOSI_DEFAULT_PIN); // SDカードで使用するピンをobnizOSの管理から外す
    obniz.pinReserve(SD_SCLK_DEFAULT_PIN); // SDカードで使用するピンをobnizOSの管理から外す
    obniz.pinReserve(SD_CS_DEFAULT_PIN); // SDカードで使用するピンをobnizOSの管理から外す

    while(!obniz.getId());
    Serial.printf("obnizID : %s\n", obniz.getId());
}
