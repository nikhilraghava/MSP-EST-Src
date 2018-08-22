#include "ae.h"
#include <dos.h>

#define DIGITALSENSOR 0x41
#define LEDS          0x81

void main(void) {
  unsigned char inpt, blink = 0xFF, ledStrip = 0x01;

  while(1) {
    inpt = inport(DIGITALSENSOR) & 0x04
    if (inpt) {
      blink ^= 0xFF;
      outport(LEDS, blink);
      delay_ms(300);
    } else {
      ledStrip <<= 1;
      outport(LEDS, ledStrip);
      delay_ms(500);
    }
  }
}
