#include <dos.h>

#define DIGITALSENSOR 0x41
#define LEDS          0x81

void main(void) {
  unsigned char inpt;
  unsigned char blink = 0xFF;
  unsigned char ledStrip = 0x01;
  
  while(1) {
    inpt = inport(DIGITALSENSOR) & 0x04
    if (inpt) {
      outport(LEDS, blink ^ 0xFF);
      delay_ms(300);
    } else {
      outport(LEDS, ledStrip <<= 1);
      delay_ms(500);
    }
  }
}
