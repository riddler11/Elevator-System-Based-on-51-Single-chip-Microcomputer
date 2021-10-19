#define u8 unsigned char
#define u16 unsigned int
 
sbit SDA=P1^6;

/*
JQ8400,JQ8900系列例程。
STC89C52RC,晶振11.0592Mhz，串口波特率9600
连接方式
 
P1.0-------->8900的VPP或8400的one line 

语音模块供电5.0V

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
//串口初始化函数


void ONE_LINE_PLAY_SONG(u8 song);
void ONE_LINE_NEXT();
void yu1()
{
 
                          //一条指令发送完毕之后，需要间隔20ms在发送下一条指令 
        ONE_LINE_PLAY_SONG(1);  
}
	void yu2()
{
 
                         //一条指令发送完毕之后，需要间隔20ms在发送下一条指令 
        ONE_LINE_PLAY_SONG(2);  
}
void yu3()
{
 
                        //一条指令发送完毕之后，需要间隔20ms在发送下一条指令 
        ONE_LINE_PLAY_SONG(3);  
}
void yu4()
{
 
                           //一条指令发送完毕之后，需要间隔20ms在发送下一条指令 
        ONE_LINE_PLAY_SONG(4);  
}
void yu5()
{
                       //一条指令发送完毕之后，需要间隔20ms在发送下一条指令 
        ONE_LINE_PLAY_SONG(5);  
}


//设置音量：vol（0-30）
/*void ONE_LINE_VOL(u8 vol)
{
    if(vol>30)vol=30;
    SendData(vol/10);
    SendData(vol%10);
    SendData(0x0C);
}	 */

//指定曲目播放        song: (1-255)
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

void SendData( u8 addr )//发送函数。
{
    u8 i;
    
    EA = 0;/*发送时关掉中断，防止中断影响时序 */
    SDA = 1;/*开始拉高 */
    delay_us ( 1000 );
    
    SDA = 0;/*开始引导码*/
    delay_us ( 2000 );/*此处延时最少要大于 2ms，此参数延时为 310ms */
    for ( i = 0; i < 8; i++ ) /*总共 8 位数据 */
    {
        SDA = 1;
        if ( addr & 0x01 ) /*3:1 表示数据位 1,每个位用两个脉冲表示 */
        {
            delay_us ( 1200 );
            SDA = 0;
            delay_us ( 400 );
            }
            else /*1：3 表示数据位 0 ,每个位用两个脉冲表示 */
            {
            delay_us ( 400 );
            SDA = 0;
            delay_us ( 1200 );
        }
        addr >>= 1;
    }
    SDA = 1;
    EA = 1;//恢复中断
}

    
