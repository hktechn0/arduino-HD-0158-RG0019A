#include <HD_0158_RG0019A.h>

/**
 * Example for HD-0158-RG0019A 32x16 dot matrix LED panel with Adafruit Feather nRF52 Bluefruit LE [nRF52832]
 */

#define PANEL_PIN_SE  PIN_A5
#define PANEL_PIN_ABB PIN_A4
#define PANEL_PIN_A3  PIN_A3
#define PANEL_PIN_A2  PIN_A2
#define PANEL_PIN_A1  PIN_A1
#define PANEL_PIN_A0  PIN_A0
#define PANEL_PIN_DG  16
#define PANEL_PIN_CLK 15
#define PANEL_PIN_WE  7
#define PANEL_PIN_DR  11
#define PANEL_PIN_ALE 30

HD_0158_RG0019A matrix(
  1,
  PANEL_PIN_A3, PANEL_PIN_A2, PANEL_PIN_A1, PANEL_PIN_A0,
  PANEL_PIN_DG, PANEL_PIN_CLK, PANEL_PIN_WE, PANEL_PIN_DR, PANEL_PIN_ALE);

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");

  // HD_0158_RG0019A library doesn't use manual RAM control.
  // Set SE and ABB low.
  digitalWrite(PANEL_PIN_SE, LOW);
  digitalWrite(PANEL_PIN_ABB, LOW);

  delay(100);
  
  matrix.begin();
  Serial.println("Initialized LED panel successfully.");
}

void loop() {
  Serial.println("DOT_GREEN");
  matrix.fillScreen(DOT_GREEN);
  delay(5000);
  Serial.println("DOT_RED");
  matrix.fillScreen(DOT_RED);
  delay(5000);
  Serial.println("DOT_ORANGE");
  matrix.fillScreen(DOT_ORANGE);
  delay(5000);

  matrix.setTextWrap(false);
  matrix.setTextSize(2);

  for (uint32_t i = INT32_MAX; ; i--) {
    matrix.startWrite();
    matrix.fillScreen(DOT_BLACK);
    matrix.setCursor((i & 0xff) - (0xff - 64), 0);
    matrix.setTextColor(DOT_GREEN);
    matrix.println(F("Hello world!!"));
    matrix.endWrite();

    delay(50);
  }
}
