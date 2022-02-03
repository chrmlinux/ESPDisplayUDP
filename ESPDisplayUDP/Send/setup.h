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

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
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
tinyUDP tudp(TUDP_SEND);
#include "draw.h"

//===============================
// spr2udp
//===============================
void spr2udp()
{
  uint8_t *buf = tudp.get();
  uint32_t bufSize = tudp.getArySize();
  buf = (uint8_t *)spr.getBuffer();
  tudp.put(buf, bufSize);
}

//===============================
// setupSpr
//===============================
void setupSpr()
{
  spr.setColorDepth(COLOR_DEPTH);
  spr.createSprite(WIDTH, HEIGHT);
  spr.setTextFont(&fonts::Font0);
  spr.setTextColor(TFT_WHITE);
}
