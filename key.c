#include"config.h"

void Key_init(void)
{
    KEY_DDR=0x00;
    KEY_PORT=0xff;
}

unsigned char get_key(void)
{
    unsigned char Key_Value=0xff;
    Key_Value=KEY_PIN&0xff;

    if(Key_Value!=0xff)
    {
        delay_nms(2);
        if((KEY_PIN&0xff)!=0xff)
        {
            Key_Value=KEY_PIN&0xff;
            while((KEY_PIN&0xff)!=0xff);
            delay_nms(1);
            while((KEY_PIN&0xff)!=0xff);
        }
    }
    return Key_Value;
}