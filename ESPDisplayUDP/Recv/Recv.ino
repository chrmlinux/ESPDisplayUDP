//===============================================================
//
// ESPDisplayUDP OUTPUT M5StickC::Recv.ino
// update/author : 2022/02/03 @chrmlinux03
// LICENCE : 
//   MIT 2022 @chrmlinux03 Recv.ino
//   ??? 2022 @chrmlinux03 tinyUDP https://github.com/chrmlinux/tinyUDP
//   FreeBSD 2020 @lovyan03 lovyanGFX https://github.com/lovyan03/LovyanGFX
//
//===============================================================
#include "setup.h"

//===============================
// setup
//===============================
void setup()
{
  Serial.begin( 115200 );
  while (!Serial);
  tudp.setResult(0);
  tudp.begin(HEIGHT * WIDTH);
  setupSpr();
}

//===============================
// loop
//===============================
void loop()
{
  udp2spr();
  tudp.update(false);
}
