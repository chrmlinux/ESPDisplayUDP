//===============================================================
//
// ESPDisplayUDP OUTPUT M5StickC::setup.h
// update/author : 2022/02/03 @chrmlinux03
// LICENCE : 
//   MIT 2022 @chrmlinux03 setup.h
//   ??? 2022 @chrmlinux03 tinyUDP https://github.com/chrmlinux/tinyUDP
//   FreeBSD 2020 @lovyan03 lovyanGFX https://github.com/lovyan03/LovyanGFX
//
//===============================================================
#define LGFX_AUTODETECT
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>
static LGFX lcd;
static LGFX_Sprite spr;
#define COLOR_DEPTH (8)
#define WIDTH (160)
#define HEIGHT (80)

//=======================================
// Select a color depth macro
//=======================================
#if   COLOR_DEPTH==24
#define SETRGB(r, g, b) color888(r, g, b)
#elif COLOR_DEPTH==16
#define SETRGB(r, g, b) color565(r, g, b)
#elif COLOR_DEPTH==8
#define SETRGB(r, g, b) color332(r, g, b)
#endif

//=======================================
// include tinyUDP
//=======================================
#include "tinyUDP.h"
tinyUDP tudp(TUDP_RECV);

//===============================
// getFps
//===============================
uint32_t getFps()
{
  static uint32_t psec = 0;
  static uint32_t cnt = 0;
  static uint32_t fps = 0;
  uint32_t sec = 0;

  sec = millis() / 1000;
  ++cnt;
  if (psec != sec) {
    psec = sec;
    fps = cnt;
    cnt = 0;
  }
  return fps;
}

//===============================
// udp2spr
//===============================
void udp2spr()
{
  uint8_t *buf = tudp.get();
  uint32_t recvSize = tudp.getRecvSize();
  if (tudp.isRecv()) {
    if (recvSize == (WIDTH * HEIGHT)) {
      spr.startWrite();
      spr.pushImage(0, 0, WIDTH, HEIGHT, (uint8_t *)buf);
      spr.setCursor(8, HEIGHT - 16); spr.printf("%d fps", getFps());
      spr.pushSprite(&lcd, 0, 0);
      spr.endWrite();
    }
  }
}

//===============================
// setupSpr
//===============================
void setupSpr()
{
  lcd.init();
  lcd.setBrightness(128);
  lcd.setRotation(1);
  lcd.setColorDepth(COLOR_DEPTH);
  lcd.setTextColor(TFT_WHITE);

  spr.setColorDepth(COLOR_DEPTH);
  spr.createSprite(lcd.width(), lcd.height());
  spr.setTextFont(&fonts::Font0);
  spr.setTextColor(TFT_WHITE);
}
