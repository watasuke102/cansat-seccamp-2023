#pragma once
#include <Arduino.h>
#include "edusat_config.hpp"
#include "FS.h"
#include "SD.h"

class MySD {
public:
    /**
     * @brief Construct a new MySD object
     * @param miso MISOピン
     * @param mosi MOSIピン
     * @param sclk SCLKピン
     * @param cs CSピン
     */
    MySD(
        uint8_t miso = SD_MISO_DEFAULT_PIN,
        uint8_t mosi = SD_MOSI_DEFAULT_PIN,
        uint8_t sclk = SD_SCLK_DEFAULT_PIN,
        uint8_t cs = SD_CS_DEFAULT_PIN
    ) {
        _pin_sd_miso = miso;
        _pin_sd_mosi = mosi;
        _pin_sd_sclk = sclk;
        _pin_sd_cs = cs;
    }

    /**
     * @brief SDカードの初期化を行う
     * @return true 成功
     * @return false 失敗
     */
    boolean init() {
        if (!SD.begin()) return false;

        if (SD.cardType() == CARD_NONE) return false;

        return true;
    }

    /**
     * @brief SDカードに新規書き込みする
     * @param path 書き込むファイルのパス
     * @param message 書き込む内容
     * @return true 成功
     * @return false 失敗
     */
    bool writeFile(const char *path, const char *message) {
        File file = SD.open(path, FILE_WRITE);
        if (!file) {
            return false;
        }
        bool result = file.print(message);
        file.close();
        return result;
    }

    /**
     * @brief SDカードに追記する
     * @param path 書き込むファイルのパス
     * @param message 書き込む内容
     * @return true 成功
     * @return false 失敗
     */
    bool appendFile(const char *path, const char *message) {
        File file = SD.open(path, FILE_APPEND);
        if (!file) {
            return false;
        }
        bool result = file.print(message);
        file.close();
        return result;
    }

private:
    uint8_t _pin_sd_miso;
    uint8_t _pin_sd_mosi;
    uint8_t _pin_sd_sclk;
    uint8_t _pin_sd_cs;
};