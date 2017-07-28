#include"config.h"
#include"1602.h"
void main(void)
{
    unsigned char key;
    DDRE = 0xFF;
    PORTE = 0xFF;
    DDRA=0xff;
    PORTA=0xff;
    DDRC=0xff;
    PORTC=0xff;
    LcdInit();
    Key_init();
    Buzz_init();

    while(1)
    {
        key=get_key();
        switch(key)
        {
            case (0x7f):
                {
                    //PORTE =~ (1<<3);
                    Beep(100,50);
                    Beep(100,50);
                    Beep(100,50);
                    Beep(100,50);
                    WriteNum(1,14,0x34);
                    break;
                }
            case (0xbf):
                {
                    //PORTE =~ (1<<2);
                    Beep(100,50);
                    Beep(100,50);
                    Beep(100,50);
                    WriteNum(1,14,0x33);
                    break;
                }
            case (0xdf):
                {
                    //PORTE =~ (1<<1);
                    Beep(100,50);
                    Beep(100,50);
                    WriteNum(1,14,0x32);
                    break;
                }
            case (0xef):
                {
                    //PORTE =~ (1<<0);
                    while(1)
                    {
                        Music_HappyBirthday();
						WriteChar(1,0,14,"Happy Birthday");
						WriteChar(2,2,9,"to HuaHua");

                        delay_nms(2000);
                    }
                    break;
                }
            case (0xfe):					  
                {
                    //PORTE =~ (1<<0);
                    while(1)                    
                    {
                        Music_HappyBirthday();
                        delay_nms(2000);
                    }
                    break;
                }
            case (0xfd):					  
                {
                    //PORTE =~ (1<<1);
                    Beep(100,50);
                    Beep(100,50);
                    WriteNum(1,14,0x32);
                    break;
                }
            case (0xfb):					  
                {
                    //PORTE =~ (1<<1);
                    Beep(100,50);
                    Beep(100,50);
                    Beep(100,50);
                    WriteNum(1,14,0x33);
                    break;
                }
            case (0xf7):						  
                {
                    //PORTE =~ (1<<1);
                    Beep(100,50);
                    Beep(100,50);
                    Beep(100,50);
                    Beep(100,50);
                    WriteNum(1,14,0x34);
                    break;
                }										 
		 
            default:
                {
                    break;
                }
        }
    }
}
