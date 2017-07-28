/************************************************
文件：buzz.h
用途：
注意：内部8M晶振
************************************************/
#ifndef __BUZZ_H__
#define __BUZZ_H__

#define BUZZ_PORT PORTG
#define BUZZ_PIN PING
#define BUZZ_DDR DDRG

#define SPK 4

extern void Buzz_init(void);
extern void Beep(unsigned int H_time,unsigned int L_time);
extern void Music_HappyBirthday();

#endif