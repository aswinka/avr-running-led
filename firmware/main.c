#include <avr/io.h>
#include <util/delay.h>

// leds & pins       7 6 5 4 3 2 1 0
#define MAX 0x20  // 0 0 1 0 0 0 0 0 
#define MIN 0x02  // 0 0 0 0 0 0 1 0

#define LEFT  1
#define RIGHT 0

int main (void)
{
  unsigned short direction = LEFT;
  // set pins to output: 0 0 1 1 1 1 1 0
  DDRB  = 0x2F;
  // initialize port b
  PORTB = 0x02;

  while (1) {
    // wait 600 ms
    _delay_ms(600);
    // determine direction
    if (PORTB == MIN) {
      direction = LEFT;
    }
    if (PORTB == MAX) {
      direction = RIGHT;
    }
    // shift bits in direction
    if (direction == LEFT) {
      PORTB <<= 1;
    } else {
      PORTB >>= 1;
    }
  }
  // never reached
  return 0;
}
