/**
 * Example for HD-0158-RG0019A 32x16 dot matrix LED panel with ESP32-DevKitC
 * Using efontWrapper.
 */

#include <Arduino.h>
#define USE_EFONT //Switch for using efontWrapper
#include <HD_0158_RG0019A.h>

// HD_0158_RG0019A library doesn't use manual RAM control.
// Set SE and AB low.
#define PANEL_PIN_A3  23
#define PANEL_PIN_A2  21
#define PANEL_PIN_A1  25
#define PANEL_PIN_A0  26
#define PANEL_PIN_DG  19
#define PANEL_PIN_CLK 18
#define PANEL_PIN_WE  17
#define PANEL_PIN_DR  16
#define PANEL_PIN_ALE 22
#define PANEL_PIN_SE  13
#define PANEL_PIN_AB  27
#define PANEL_NUM     2  //two panels setting

HD_0158_RG0019A matrix(
    PANEL_NUM,
    PANEL_PIN_A3, PANEL_PIN_A2, PANEL_PIN_A1, PANEL_PIN_A0,
    PANEL_PIN_DG, PANEL_PIN_CLK, PANEL_PIN_WE, PANEL_PIN_DR, PANEL_PIN_ALE);

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");
  
  pinMode(PANEL_PIN_SE, OUTPUT);
  pinMode(PANEL_PIN_AB, OUTPUT);
  digitalWrite(PANEL_PIN_SE, LOW);
  digitalWrite(PANEL_PIN_AB, LOW);
  
  matrix.begin();
  Serial.println("Initialized LED panel successfully.");

  delay(100);
  
  matrix.fillScreen(DOT_BLACK);
  matrix.setTextWrap(false);
  matrix.setTextSize(1);  // x1
  matrix.setRotation(0);

  matrix.startWrite();
  matrix.setCursor(0, 0);
  matrix.setTextColor(DOT_GREEN, DOT_BLACK);
  matrix.printEfont("Hi!!令和");
  matrix.endWrite();
}

void loop() {
}
