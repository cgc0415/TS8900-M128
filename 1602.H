#define uchar unsigned char 
#define uint unsigned int 

#define RS 0
#define RW 1
#define EN 2

void s_ms(uint ms)
{
	for(;ms>1;ms--);
}	

//��æ
void busy(void)
{
    uchar temp;
	s_ms(500);
	PORTC&=~(1<<RS);    //RS=0
	s_ms(500);
	PORTC|=(1<<RW);     //RW=1
	s_ms(500);
	while(temp)
	{
		PORTC|=(1<<EN); //EN=1
		s_ms(500);
		DDRA=0x00;      //A�ڱ�����
		PORTA=0xff;     //����ʹ��
		s_ms(500);
		temp = PINA&0x80;    //��ȡA��
		s_ms(500);      
		DDRA=0xff;      
		PORTA=0xff;        //A�ڱ����
		s_ms(500);
		PORTC&=~(1<<EN);   //EN=0
		s_ms(500);
	}
}

//дָ��
void writecom(uchar	com)
{
	busy();
	s_ms(500);
	PORTC&=~(1<<RS);   //RS=0
	s_ms(500);
	PORTC&=~(1<<RW);   //RW=0
	s_ms(500);
	PORTC|=(1<<EN);    //EN=1
	s_ms(500);
	PORTA = com;       //���ָ��
	s_ms(500);
	PORTC&=~(1<<EN);   //EN=0
	s_ms(500);
}

//1602��ʼ��
void	LcdInit(void)
{
	writecom(0x38);
	s_ms(1000);
	writecom(0x01);
	s_ms(10000);
	s_ms(1000);
	s_ms(1000);
	s_ms(1000);
	s_ms(1000);
	s_ms(1000);
	s_ms(1000);
	writecom(0x02);
	s_ms(1000);
	writecom(0x06);
	s_ms(1000);
	writecom(0x0c);
	s_ms(1000);
	writecom(0x38);	
	s_ms(1000);
}	

//д����
void	writedata(uchar data)
{
	busy();
	s_ms(500);
	PORTC|=(1<<RS);   //RS=1
	s_ms(500);
	PORTC&=~(1<<RW);   //RW=0
	s_ms(500);
	PORTC|=(1<<EN);    //EN=1
	s_ms(500);
	PORTA = data;      //�������
	s_ms(500);
	PORTC&=~(1<<EN);   //EN=0
	s_ms(500);
}


//������
uchar	readdata(void)
{
	uchar temp;
	busy();
	s_ms(500);
	PORTC|=(1<<RS);  //RS=1
	s_ms(500);
	PORTC|=(1<<RW);  //RW=1
	s_ms(500);
	PORTC|=(1<<EN);  //EN=1
	s_ms(500);
	DDRA=0x00;       //A�˿ڱ�����
	s_ms(500);
	temp = PINA;     //��A�˿�
	s_ms(500);
	DDRA=0xff;       //A�˿ڱ����
	s_ms(500);
	PORTC&=~(1<<EN); //EN=0
	s_ms(500);
	return temp;	
}

//=================================================
// ������ дLCD�ڲ�CGRAM����
// ��ڣ� ��num��Ҫд�����ݸ���
//        ��pbuffer��Ҫд�����ݵ��׵�ַ
// ���ڣ� ��
//================================================
void	WriteCGRAM(uint	num, const uint	*pBuffer)
{
	uint	i,t;
	writecom(0x40);
	PORTC|=(1<<RS);
	PORTC&=~(1<<RW);
	for(i=num;i!=0;i--)
	{
		t = *pBuffer;
		PORTC|=(1<<EN);
		PORTA = t;
		PORTC&=~(1<<EN);				
		pBuffer++;
	}
	
}

//=================================================
//������д�˵�������������ʹ�õ�LCD���Ϊ 16 * 2
//��ڣ��˵������׵�ַ
//���ڣ���
//=================================================
void	WriteMenu(const uchar *pBuffer)
{
	uchar	i,t;
	writecom(0x80);   //���ݵ�ַ
	
	PORTC|=(1<<RS);
	PORTC&=~(1<<RW);
	s_ms(50);
	for(i=0;i<16;i++)
	{
		t = *pBuffer;
		PORTA = t;
		PORTC|=(1<<EN);
		s_ms(50);
		PORTC&=~(1<<EN);				
		pBuffer++;
	}
	writecom(0xC0);

	PORTC|=(1<<RS);
	PORTC&=~(1<<RW);
	s_ms(50);	
	for(i=0;i<16;i++)
	{
		t = *pBuffer;
		PORTA = t;
		PORTC|=(1<<EN);
		s_ms(50);
		PORTC&=~(1<<EN);				
		pBuffer++;
	}
}
//====================================================
// ������������λ��д���ֺ���
// ��ڣ���row����ʾҪд�������ڵ��е�ַ��ֻ��Ϊ1��2
//       ��col����ʾҪд�������ڵ��е�ַ��ֻ��Ϊ0--15
//		 ��num����ʾҪд�����֣�ֻ��Ϊ0--9
// ���ڣ���
//===================================================
void WriteNum(uchar row,uchar col,uchar num)
{
	if (row == 1)	row = 0x80 + col;
	else	row = 0xC0 + col;
	writecom(row);

	PORTC|=(1<<RS);
	s_ms(500);
	PORTC&=~(1<<RW);
	s_ms(500);
	PORTA = num;
	s_ms(500);
	PORTC|=(1<<EN);
	s_ms(500);
	PORTC&=~(1<<EN);	
	s_ms(500);			
}
//================================================================
// ������������λ��д�������ַ�
// ��ڣ���row��Ҫд���ַ����ڵ��У�ֻ��Ϊ1��2��
//       ��col��Ҫд���ַ����ڵ��У�ֻ��Ϊ0---15
//       ��num��Ҫд�ַ��ĸ���
//       ��pbuffer��Ҫд�ַ����׵�ַ
//================================================================== 
void	WriteChar(uchar row,uchar col,uint num,uchar *pBuffer)
{
	uchar i,t;
	if (row == 1)	row = 0x80 + col;
	else	row = 0xC0 + col;
	writecom(row);


	PORTC|=(1<<RS);
	s_ms(500);
	PORTC&=~(1<<RW);
	s_ms(500);
	for(i=num;i!=0;i--)
	{
		t = *pBuffer;
		s_ms(500);
		PORTA = t;
		s_ms(500);
		PORTC|=(1<<EN);
		s_ms(500);
		PORTC&=~(1<<EN);		
		s_ms(500);		
		pBuffer++;
	}
	
}