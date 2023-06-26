# デバッグサンプルプログラムの構成

```txt
.
|- debug.ino         # CanSatの制御プログラム
|- edusat_config.hpp # CanSatの制御ピン定義
|- mysd.hpp          # SDカードに関する処理のライブラリ
|- obniz.html        # ObnizのHTMLプログラム
```

# サンプルプログラムの動作

このサンプルプログラムでは3つの方法でCanSatの状態を確認するサンプルを示しています。

- 有線（シリアル通信、USBケーブルを使う）
- 無線（Wi-Fi、Obnizを使う）
- SDカード

プログラムを実行すると、上記3つのそれぞれに9軸センサから取得した加速度の値を出力します。

# サンプルプログラムの説明

## debug.ino

Arduino IDEで開きます。

### 使用ライブラリ（外部）

|ライブラリ名|URL|
|:---|:---|
|MPU9250.h|https://github.com/hideakitai/MPU9250|
|obniz.h|https://obniz.com/ja/doc/reference/obnizos-for-esp32/plugin/|


### setup()

最初に一度だけ`setup`関数が実行されます。
この関数では主に初期化処理を行います。

### loop()

`setup`関数の次に実行されます。
この関数は繰り返し実行されます。

`mpu.update`関数から`true`が返却される（9軸センサの値が更新される）と取得した値のうち、加速度センサの値を有線・無線・SDカードにそれぞれ出力します。

### obnizInit()

`setup`関数の中で呼ばれています。
ObnizOSの初期化処理を行います。
初期状態ではマイコンのGPIOがObnizOSに専有されているため、Arduinoプラグイン側で使用したいピンをObnizOSの管理から外しています。

## edusat_config.hpp

CanSatで使用しているピンの定義ファイルです。

下記例ではLEDのピンをESPマイコンの2番ピンに接続していることを表しています。

```h
// LED
constexpr uint8_t LED_DEFAULT_PIN = 2;
```

## mysd.hpp

SDカードの処理に関するライブラリです。

|関数名|概要|
|:---|:---|
|init|初期化処理を行います|
|writeFile|ファイルを新規作成して、書き込みします|
|appendFile|存在するファイルに追記書き込みします|

## obniz.html

Obnizの開発者コンソールで開きます。

CanSatから送信したデータを受け取って、ブラウザの画面に表示するプログラムとなっています。
