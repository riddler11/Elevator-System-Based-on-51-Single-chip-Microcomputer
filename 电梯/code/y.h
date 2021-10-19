#define u8 unsigned char
#define u16 unsigned int
 
sbit SDA=P1^6;

/*
JQ8400,JQ8900ϵ�����̡�
STC89C52RC,����11.0592Mhz�����ڲ�����9600
���ӷ�ʽ
 
P1.0-------->8900��VPP��8400��one line 

����ģ�鹩��5.0V

*/

 
 
void SendData ( u8 addr );
void ONE_LINE_VOL(u8 vol);



void delay_us(u16 x)
{
    while(x--); 
}
/*void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	//_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
void delay_ms(u16 x)
{
    while(x--)
    Delay1ms();
}	   */
//���ڳ�ʼ������


void ONE_LINE_PLAY_SONG(u8 song);
void ONE_LINE_NEXT();
void yu1()
{
 
                          //һ��ָ������֮����Ҫ���20ms�ڷ�����һ��ָ�� 
        ONE_LINE_PLAY_SONG(1);  
}
	void yu2()
{
 
                         //һ��ָ������֮����Ҫ���20ms�ڷ�����һ��ָ�� 
        ONE_LINE_PLAY_SONG(2);  
}
void yu3()
{
 
                        //һ��ָ������֮����Ҫ���20ms�ڷ�����һ��ָ�� 
        ONE_LINE_PLAY_SONG(3);  
}
void yu4()
{
 
                           //һ��ָ������֮����Ҫ���20ms�ڷ�����һ��ָ�� 
        ONE_LINE_PLAY_SONG(4);  
}
void yu5()
{
                       //һ��ָ������֮����Ҫ���20ms�ڷ�����һ��ָ�� 
        ONE_LINE_PLAY_SONG(5);  
}


//����������vol��0-30��
/*void ONE_LINE_VOL(u8 vol)
{
    if(vol>30)vol=30;
    SendData(vol/10);
    SendData(vol%10);
    SendData(0x0C);
}	 */

//ָ����Ŀ����        song: (1-255)
void ONE_LINE_PLAY_SONG(u8 song)
{
    u8 i;
    u8 tmp[3];
    
    tmp[0]=song/100;song%=100;
    tmp[1]=song/10;
    tmp[2]=song%10;
    
    SendData(0x0a);
    for(i=0;i<3;i++)
    {
       if(tmp[i]!=0)
       {
          SendData(tmp[i]);
       }   
    }
    SendData(0x0b);
    
}

void SendData( u8 addr )//���ͺ�����
{
    u8 i;
    
    EA = 0;/*����ʱ�ص��жϣ���ֹ�ж�Ӱ��ʱ�� */
    SDA = 1;/*��ʼ���� */
    delay_us ( 1000 );
    
    SDA = 0;/*��ʼ������*/
    delay_us ( 2000 );/*�˴���ʱ����Ҫ���� 2ms���˲�����ʱΪ 310ms */
    for ( i = 0; i < 8; i++ ) /*�ܹ� 8 λ���� */
    {
        SDA = 1;
        if ( addr & 0x01 ) /*3:1 ��ʾ����λ 1,ÿ��λ�����������ʾ */
        {
            delay_us ( 1200 );
            SDA = 0;
            delay_us ( 400 );
            }
            else /*1��3 ��ʾ����λ 0 ,ÿ��λ�����������ʾ */
            {
            delay_us ( 400 );
            SDA = 0;
            delay_us ( 1200 );
        }
        addr >>= 1;
    }
    SDA = 1;
    EA = 1;//�ָ��ж�
}

    
