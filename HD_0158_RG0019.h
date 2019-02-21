#ifndef _HD_0158_RG0019_H_
#define _HD_0158_RG0019_H_

#include <Adafruit_GFX.h>

#define DOT_PANEL_WIDTH 32
#define DOT_PANEL_HEIGHT 16

#define DOT_BLACK 0x0000
#define DOT_RED 0xF800
#define DOT_GREEN 0x07C0
#define DOT_ORANGE (DOT_RED | DOT_GREEN)

class HD_0158_RG0019 : public Adafruit_GFX {
  public:
    HD_0158_RG0019(
      int8_t n_panel,
      int8_t pin_se, int8_t pin_abb,
      int8_t pin_a3, int8_t pin_a2, int8_t pin_a1, int8_t pin_a0,
      int8_t pin_dg, int8_t pin_clk, int8_t pin_we, int8_t pin_dr, int8_t pin_ale);
    ~HD_0158_RG0019(void);

    void begin();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    // TRANSACTION API / CORE DRAW API
    void startWrite(void);
    void writePixel(int16_t x, int16_t y, uint16_t color);
    void endWrite(void);

  private:
    int8_t pinSE, pinABB, pinA3, pinA2, pinA1, pinA0, pinDG, pinCLK, pinWE, pinDR, pinALE;
    uint8_t nPanel;
    uint32_t transactionCounter;
    uint32_t *bufferR, *bufferG;
};

#endif // _HD_0158_RG0019_H_
