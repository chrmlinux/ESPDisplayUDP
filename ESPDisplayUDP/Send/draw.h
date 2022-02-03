//===============================================================
//
// ESPDisplayUDP OUTPUT M5StickC::draw.h
// update/author : 2022/02/03 @chrmlinux03
// LICENCE : 
//   MIT 2022 @chrmlinux03 draw.h
//   ??? 2022 @chrmlinux03 tinyUDP https://github.com/chrmlinux/tinyUDP
//   FreeBSD 2020 @lovyan03 lovyanGFX https://github.com/lovyan03/LovyanGFX
//
//===============================================================
// =============================================================
// textRain
// -------------------------------------------------------------
// usage textRain(column(1..40), row(1..max), fontheight(1..max)
// =============================================================
void px(int x, int y, int h, int c) {
  spr.setTextColor(spr.SETRGB(0, c, 0));
  spr.setCursor(x * h, y * h);
  spr.printf("%c", random(0x21, 0x7e));
}

void textRain(int x, int y, int h) {
  spr.clear(TFT_BLACK);
  static int yp[40] = {1};
  for (int i = 0; i < x; i++) {
    px(i, yp[i], h, 0xff);
    int p = 0;
    for (int j = yp[i] - y; j < yp[i]; j++) {
      px(i, j, h, (p << 3));
      p++;
    }
    if (yp[i] > y) {
      if (random(1000) > 975) yp[i] = 0;
    }
    yp[i]++;
  }
}

//===============================
// draw
//===============================
void draw()
{
  textRain(40, 10, 8);
}
