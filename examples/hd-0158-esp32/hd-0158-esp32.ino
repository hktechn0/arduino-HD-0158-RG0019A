#include <HD_0158_RG0019A.h>

/**
 * Example for HD-0158-RG0019A 32x16 dot matrix LED panel with ESP32-DevKitC
 */

// HD_0158_RG0019A library doesn't use manual RAM control.
// Set SE and ABB low.
#define PANEL_PIN_A3  16
#define PANEL_PIN_A2  17
#define PANEL_PIN_A1  18
#define PANEL_PIN_A0  19
#define PANEL_PIN_DG  12
#define PANEL_PIN_CLK 14
#define PANEL_PIN_WE  27
#define PANEL_PIN_DR  26
#define PANEL_PIN_ALE 25

HD_0158_RG0019A matrix(
  1,
  PANEL_PIN_A3, PANEL_PIN_A2, PANEL_PIN_A1, PANEL_PIN_A0,
  PANEL_PIN_DG, PANEL_PIN_CLK, PANEL_PIN_WE, PANEL_PIN_DR, PANEL_PIN_ALE);

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");

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
