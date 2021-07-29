#include <Adafruit_GFX.h>
#include "HD_0158_RG0019A.h"

HD_0158_RG0019A::HD_0158_RG0019A(
  int8_t n_panel,
  int8_t pin_a3, int8_t pin_a2, int8_t pin_a1, int8_t pin_a0,
  int8_t pin_dg, int8_t pin_clk, int8_t pin_we, int8_t pin_dr, int8_t pin_ale) :
  GRAPHICS_LIB(DOT_PANEL_WIDTH * n_panel, DOT_PANEL_HEIGHT),
  pinA3(pin_a3), pinA2(pin_a2), pinA1(pin_a1), pinA0(pin_a0),
  pinDG(pin_dg), pinCLK(pin_clk), pinWE(pin_we), pinDR(pin_dr), pinALE(pin_ale),
  nPanel(n_panel), transactionCounter(0) {
  if (!bufferR) {
    bufferR = (uint32_t*) calloc(n_panel * DOT_PANEL_HEIGHT, sizeof(uint32_t));
  }
  if (!bufferG) {
    bufferG = (uint32_t*) calloc(n_panel * DOT_PANEL_HEIGHT, sizeof(uint32_t));
  }
}

HD_0158_RG0019A::~HD_0158_RG0019A(void) {
  if (bufferR) {
    free(bufferR);
  }
  if (bufferG) {
    free(bufferG);
  }
}

void HD_0158_RG0019A::begin() {
  pinMode(pinA3, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA0, OUTPUT);
  pinMode(pinDG, OUTPUT);
  pinMode(pinCLK, OUTPUT);
  pinMode(pinWE, OUTPUT);
  pinMode(pinDR, OUTPUT);
  pinMode(pinALE, OUTPUT);

  digitalWrite(pinA3, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA0, LOW);
  digitalWrite(pinDG, LOW);
  digitalWrite(pinCLK, LOW);
  digitalWrite(pinWE, LOW);
  digitalWrite(pinDR, LOW);
  digitalWrite(pinALE, LOW);

  fillScreen(DOT_BLACK);
}

void HD_0158_RG0019A::drawPixel(int16_t x, int16_t y, uint16_t color) {
  startWrite();
  writePixel(x, y, color);
  endWrite();
}

void HD_0158_RG0019A::startWrite() {
  transactionCounter++;
}

void HD_0158_RG0019A::endWrite() {
  if (--transactionCounter) {
    return;
  }
  if (!bufferR || !bufferG) {
    return;
  }

  for (uint16_t y = 0; y < DOT_PANEL_HEIGHT; y++) {
    // Select RAM (Y) address
    digitalWrite(pinA0, y & 1);
    digitalWrite(pinA1, y & 2);
    digitalWrite(pinA2, y & 4);
    digitalWrite(pinA3, y & 8);

    // Write X dots to shift register
    for (uint16_t x = 0; x < DOT_PANEL_WIDTH * nPanel; x++) {
      uint16_t i = (x >> 5) + (y * nPanel);
      uint8_t panelX = x & 31;

      digitalWrite(pinDR, (bufferR[i] >> panelX) & 1);
      digitalWrite(pinDG, (bufferG[i] >> panelX) & 1);
      digitalWrite(pinCLK, HIGH);
      digitalWrite(pinCLK, LOW);
    }

    // Write data from shift register to RAM
    digitalWrite(pinALE, HIGH);
    digitalWrite(pinWE, HIGH);
    digitalWrite(pinWE, LOW);
    digitalWrite(pinALE, LOW);
  }

  // For auto RAM A/B changing
  digitalWrite(pinA0, 0);
  digitalWrite(pinA1, 0);
  digitalWrite(pinA2, 0);
  digitalWrite(pinA3, 0);
}

void HD_0158_RG0019A::writePixel(int16_t x, int16_t y, uint16_t color) {
  if (!bufferR || !bufferG || x < 0 || x >= DOT_PANEL_WIDTH * nPanel || y < 0 || y >= DOT_PANEL_HEIGHT) {
    return;
  }

  uint16_t i = (x >> 5) + (y * nPanel);
  uint8_t panelX = x & 31;

  switch (color) {
    case DOT_RED:
      bufferR[i] |= 1 << panelX;
      bufferG[i] &= ~(1 << panelX);
      break;
    case DOT_GREEN:
      bufferR[i] &= ~(1 << panelX);
      bufferG[i] |= 1 << panelX;
      break;   
    case DOT_ORANGE:
      bufferR[i] |= 1 << panelX;
      bufferG[i] |= 1 << panelX;
      break;
    default:
      bufferR[i] &= ~(1 << panelX);
      bufferG[i] &= ~(1 << panelX);
      break;
  }
}
