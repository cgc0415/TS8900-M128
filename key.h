#ifndef _key_h_
#define _key_h_

#define S1 4
#define S2 5
#define S3 6
#define S4 7

#define KEY_DDR DDRD
#define KEY_PORT PORTD
#define KEY_PIN PIND

extern void key_init(void);
extern unsigned char get_key(void);

#endif
