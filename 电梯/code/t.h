sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

//--定义要使用的IO口--//
#define COMMONPORTS		P0

//--列选通控制--//
unsigned char code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

//--点阵字码--//
unsigned char code CHARCODE[8][8]=
{

{0x00,0x18,0x3C,0x7E,0x18,0x18,0x18,0x00}, //上

{0x18,0x3C,0x7E,0x18,0x18,0x18,0x00,0x18},	//2

{0x3C,0x7E,0x18,0x18,0x18,0x00,0x18,0x3C},	 //3

{0x7E,0x18,0x18,0x18,0x00,0x18,0x3C,0x7E},	 //4

{0x18,0x18,0x18,0x00,0x18,0x3C,0x7E,0x18},	 //5

{0x18,0x18,0x00,0x18,0x3C,0x7E,0x18,0x18},	 //6

{0x18,0x00,0x18,0x3C,0x7E,0x18,0x18,0x18},	 //7

{0x00,0x18,0x3C,0x7E,0x18,0x18,0x18,0x00}	 //8


};


unsigned char code CHARCODE1[8][8]=
{

{0x00,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00}, //下

{0x18,0x00,0x18,0x18,0x18,0x7E,0x3C,0x18},	//2

{0x3C,0x18,0x00,0x18,0x18,0x18,0x7E,0x3C},	 //3

{0x7E,0x3C,0x18,0x00,0x18,0x18,0x18,0x7E},	 //4

{0x18,0x7E,0x3C,0x18,0x00,0x18,0x18,0x18},	 //5

{0x18,0x18,0x7E,0x3C,0x18,0x00,0x18,0x18},	 //6

{0x18,0x18,0x18,0x7E,0x3C,0x18,0x00,0x18},	 //7

{0x00,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00}	 //8


};

void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<121;j++);
}


void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}

void sha()
{	
 	unsigned char tab, j;
	unsigned int  i;

	
		
		for(i= 0; i<20; i++ )   //两个字之间的扫描间隔时间
		{
			for(tab=0;tab<8;tab++)
			{	

				Hc595SendByte(0x00);			     //消隐																
				COMMONPORTS	= TAB[tab];				 //输出字码	
				Hc595SendByte(CHARCODE[j][tab]);	
				delay(2);		
			}
			 
		}
		j++;
		if(j == 8)
		{
			j = 0;
		}
	}	
  

void xia()
{	
 	unsigned char tab, j;
	unsigned int  i;

	
		
		for(i= 0; i<20; i++ )   //两个字之间的扫描间隔时间
		{
			for(tab=0;tab<8;tab++)
			{	

				Hc595SendByte(0x00);			     //消隐																
				COMMONPORTS	= TAB[tab];				 //输出字码	
				Hc595SendByte(CHARCODE1[j][tab]);	
				delay(2);		
			}
			 
		}
		j++;
		if(j == 8)
		{
			j = 0;
		}
		
}
void xi(){
int i;
for(i=0;i<8;i++){
					  xia();
					  	} }
void sh(){
int i;
 for(i=0;i<8;i++){
					  sha();
					  	}
						}