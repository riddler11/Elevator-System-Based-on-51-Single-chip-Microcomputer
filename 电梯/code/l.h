#include<intrins.h>
#include<t.h>
#include<y.h>

sbit k5=P1^0;
sbit k4=P1^1;
sbit k3=P1^2;
sbit k2=P1^3;
sbit k1=P1^4; //���尴ť







int floor;//floor����



void lou()
{	
int n;
    

   
		 
        if (k1==0) //1¥
        {	
            if(floor%10==2)
            {
			 
                for(n=1; n<2; n++)
                {	
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
					  P0=0x7f;
          			 
                }
			
            }
            if(floor%10==3)
            {
                
				
                for(n=1; n<3; n++)
                {
				
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
							
                }
				
            }
            if(floor%10==4)
            {
               
				
                for(n=1; n<4; n++)
                {
				
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
					
                }
					
            }
            if(floor%10==5)
            {
                
				
                for(n=1; n<5; n++)
                {
				
                    floor--;
                   
					  xi();
					  	
                    P2=floor%10;
					
                }
				
            }
		   	yu1();
        }


        if (k2==0)
        {

            if(floor%10==1)
            {
               
                for(n=1; n<2; n++)
                {
                    floor++;
                   
					  sh();
					  	
                    P2=floor%10;
	
                }
            }
            if(floor%10==3)
            {
                
                for(n=1; n<2; n++)
                {
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
								
                }
            }
            if(floor%10==4)
            {
                
                for(n=1; n<3; n++)
                {
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
				
                }
            }
            if(floor%10==5)
            {
                
                for(n=1; n<4; n++)
                {
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
								
                }
            }
		  yu2();
		  	
        }


        if (k3==0)
        {
            if(floor%10==1)
            {
               
                for(n=1; n<3; n++)
                {
                    floor++;
                   
					  sh();
					  	
                    P2=floor%10;
									
                }
            }

            if(floor%10==2)
            {
               
                for(n=1; n<2; n++)
                {
                    floor++;
                    
					  sh();
					  	
                    P2=floor%10;
								
                }
            }
            if(floor%10==4)
            {
                
                for(n=1; n<2; n++)
                {
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
						
                }
            }
            if(floor%10==5)
            {
                
                for(n=1; n<3; n++)
                {
                    floor--;
                    
					  xi();
					  	
                    P2=floor%10;
					
                }
            }
			yu3();	
        }


        if (k4==0)
        {
            if(floor%10==1)
            {
                
                for(n=1; n<4; n++)
                {
                    floor++;
                    
					  sh();
					  	
                    P2=floor%10;
					
                }
            }

            if(floor%10==2)
            {
                
                for(n=1; n<3; n++)
                {
                    floor++;
                    
					  sh();
					  	
                    P2=floor%10;
						
                }
            }
            if(floor%10==3)
            {
                
                for(n=1; n<2; n++)
                {
                    floor++;
                   
					  sh();
					  	
                    P2=floor%10;
					
                }
            }
            if(floor%10==5)
            {
               
                for(n=1; n<2; n++)
                {
                    floor--;
                   
					  xi();
					  	
                    P2=floor%10;
						
                }
            }
			yu4();	
        }


        if (k5==0)
        {
            if(floor%10==1)
            {
                
                for(n=1; n<5; n++)
                {
                    floor++;
                   
					  sh();
					  	
                    P2=floor%10;
							
                }
            }

            if(floor%10==2)
            {
                
                for(n=1; n<4; n++)
                {
                    floor++;
                    
					  sh();
					  	
                    P2=floor%10;
							
                }
            }
            if(floor%10==3)
            {
                
                for(n=1; n<3; n++)
                {
                    floor++;
                   
					  sh();
					  	
                    P2=floor%10;
								
                }
            }
            if(floor%10==4)
            {
                
                for(n=1; n<2; n++)
                {
                    floor++;
                 
					  sh();
					  	
                    P2=floor%10;
							
                }
            }
		   
		  yu5();	
        }//���¥ͨ��ѭ�����߼�ʵ������

    
}
