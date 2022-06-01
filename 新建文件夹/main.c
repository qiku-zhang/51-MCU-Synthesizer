#include <main.h>
#include <REG52.H>

<<<<<<< HEAD
extern void LCD0();

unsigned int C;
unsigned int song5_tune[11];
unsigned int song5_time[11];
=======
extern void HONGWAI();
extern void LCD0();

unsigned int C;
unsigned char song5_tune[20];
unsigned char song5_time[20];

>>>>>>> bff2cfa (绾㈠閬ユ帶)
void music();
void piano();
void record();
void delay(unsigned int s);
<<<<<<< HEAD
void LCD0();
=======
void HONGWAI();
void LCD0();

>>>>>>> bff2cfa (绾㈠閬ユ帶)
void main(void)
{
  while(1){
	LED1=0;
	LED2=0;
	LED3=0;
<<<<<<< HEAD
	LCD0();
	while(key1==1&&key2==1&&key3==1)
	{}
	if(key1==0)
	{
		LED1=0;
		LED2=1;
		LED3=1;
		LCD0();
=======
	P2=0x00;
  LCD0();
	HONGWAI();
	if(P2==0xF3)//按键为1选择功能1
	{
		LCD0();
		LED1=0;
		LED2=1;
		LED3=1;
>>>>>>> bff2cfa (绾㈠閬ユ帶)
		delay(1000);
    music();
	}
		
<<<<<<< HEAD
	if(key2==0)
	{
		LED1=1;
		LED2=0;
		LED3=1;
		LCD0();
=======
	if(P2==0xE7)//按键为2选择功能2
	{
		LCD0();
		LED1=1;
		LED2=0;
		LED3=1;
>>>>>>> bff2cfa (绾㈠閬ユ帶)
		delay(1000);
		piano();
	}
		
<<<<<<< HEAD
	if(key3==0)
	{
		LED1=1;
		LED2=1;
		LED3=0;
		LCD0();
=======
	if(P2==0xA1)//按键为3选择功能3
	{
		LCD0();
		LED1=1;
		LED2=1;
		LED3=0;
>>>>>>> bff2cfa (绾㈠閬ユ帶)
		delay(1000);
		record();
	}
 }
} 

 
void music()
{
	unsigned char i;
<<<<<<< HEAD
	unsigned int s;
=======
	unsigned s;
>>>>>>> bff2cfa (绾㈠閬ユ帶)
 	TMOD=0x01;
	EA=1;
	ET0=1;
	while(1){
<<<<<<< HEAD
	if(key1==0)
=======
	HONGWAI();
	if(P2==0xF3)
>>>>>>> bff2cfa (绾㈠閬ユ帶)
	{
		for(i=0;;i++)
		{
			C=song5_tune[i];
		  if(song5_time[i]==0)
		      break  ;
		  else
				{
					if(song5_tune[i]==0)
				  {s=100*song5_time[i];
				      delay(s);}
			    else
						{
							TH0=tune[C]/256;
				      TL0=tune[C]%256;
				      TR0=1;
<<<<<<< HEAD
							s=100*song1_time[i];
=======
							s=100*song5_time[i];
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				      delay(s);
              TR0=0;				
			      }
		    }
	  }
<<<<<<< HEAD
		break;
  }
 if(key2==0)
=======
  }
if(P2==0xE7)
>>>>>>> bff2cfa (绾㈠閬ユ帶)
	{
		for(i=0;;i++)
		{
			C=song2_tune[i];
		  if(song2_time[i]==0)
		       break ;
		  else
				{
					if(song2_tune[i]==0)
				  {s=100*song2_time[i];
				      delay(s);}
			    else
						{
							TH0=tune[C]/256;
				      TL0=tune[C]%256;
				      TR0=1;
				      s=100*song2_time[i];
							delay(s);
              TR0=0;				
			      }
		    }
	  }
<<<<<<< HEAD
		break;
  }
 if(key3==0)
=======
  }
 if(P2==0xA1)
>>>>>>> bff2cfa (绾㈠閬ユ帶)
	{
		for(i=0;;i++)
		{
			C=song3_tune[i];
		  if(song3_time[i]==0)
		       break ;
		  else
				{
					if(song3_tune[i]==0)
				  {s=100*song3_time[i];
				      delay(s);}
			    else
						{
							TH0=tune[C]/256;
				      TL0=tune[C]%256;
				      TR0=1;
				      s=100*song3_time[i];
							delay(s);
              TR0=0;				
			      }
		    }
	  }
<<<<<<< HEAD
		break;
  }
 if(key4==0)
=======
  }
 if(P2==0xF7)
>>>>>>> bff2cfa (绾㈠閬ユ帶)
	{
		for(i=0;;i++)
		{
			C=song4_tune[i];
		  if(song4_time[i]==0)
           break ;
		  else
				{
					if(song4_tune[i]==0)
				  {s=100*song4_time[i];
				      delay(s);}
			    else
						{
							TH0=tune[C]/256;
				      TL0=tune[C]%256;
				      TR0=1;
				      s=100*song4_time[i];
							delay(s);
              TR0=0;				
			      }
		    }
	  }
<<<<<<< HEAD
		break;
  }			
=======
  }
	
  if(P2==0xE9)
             return;				
>>>>>>> bff2cfa (绾㈠閬ユ帶)
 }
return;
}

void piano()
{
	TMOD=0x01;
	EA=1;
	ET0=1;
	while(1)
	{
<<<<<<< HEAD
		if(key1==0)
		{
			delay(300);
			if(key2==0&&key3==1&&key4==1){
=======
		HONGWAI();
		if(P2==0XF3)
		{
				C=1;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xE7)
		{
				C=2;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xA1)
		{
				C=3;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xF7)
		{
				C=4;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}			
		
	  if(P2==0xE3)
		{
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				C=5;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
<<<<<<< HEAD
			  delay(100);
			  TR0=0;}
			if(key2==1&&key3==0&&key4==1){
=======
			  delay(300);
			  TR0=0;
		}
		if(P2==0xA5)
		{
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				C=6;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
<<<<<<< HEAD
			  delay(100);
			  TR0=0;}
			if(key2==1&&key3==1&&key4==0){
=======
			  delay(300);
			  TR0=0;
		}
		if(P2==0xBD)
		{
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				C=7;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
<<<<<<< HEAD
			  delay(100);
			  TR0=0;}
			if(key2==1&&key3==1&&key4==1){
				C=1;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;}			
		}
		
	  if(key2==0)
		{
			delay(300);
			if(key1==0){
				C=5;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;}
			else{
				C=2;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
			}
		}
		
		if(key3==0)
		{
			delay(300);
			if(key1==0){
				C=6;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;}
			else{
				C=3;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
			}
		}
		
	  if(key4==0)
		{
			delay(300);
			if(key1==0){
				C=7;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;}
			else{
				C=4;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
			}
		}
	}
	return;
=======
			  delay(300);
			  TR0=0;
		}
		if(P2==0xAD)
		{
				C=8;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xB5)
		{
				C=9;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xBA)
		{
				C=10;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xB9)
		{
				C=11;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xB8)
		{
				C=12;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xBB)
		{
				C=13;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xBF)
		{
				C=14;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xBC)
		{
				C=15;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
		}
		if(P2==0xE9)
			return;
	}
>>>>>>> bff2cfa (绾㈠閬ユ帶)
}
		

void record()
{
	int i=0;
	TMOD=0x01;
	EA=1;
	ET0=1;
<<<<<<< HEAD
	while(i<=9)
	{
		if(key1==0)
		{
			delay(300);
			if(key2==0&&key3==1&&key4==1){
=======
	while(i<=100)
	{
		HONGWAI();
		if(P2==0XF3)
		{
				C=1;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=1;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xE7)
		{
				C=2;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
				song5_tune[i]=2;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xA1)
		{
				C=3;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
				song5_tune[i]=3;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xF7)
		{
				C=4;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=4;
			  song5_time[i]=3;
			  i++;
		}			
		
	  if(P2==0xE3)
		{
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				C=5;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
<<<<<<< HEAD
			  delay(100);
			  TR0=0;
			  song5_tune[i]=5;
			  song5_time[i]=3;
			  i++;}
			if(key2==1&&key3==0&&key4==1){
=======
			  delay(300);
			  TR0=0;
			  song5_tune[i]=5;
			  song5_time[i]=3;
			  i++; 
		}
		if(P2==0xA5)
		{
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				C=6;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
<<<<<<< HEAD
			  delay(100);
			  TR0=0;
				song5_tune[i]=6;
			  song5_time[i]=3;
			  i++;}
			if(key2==1&&key3==1&&key4==0){
=======
			  delay(300);
			  TR0=0;
			  song5_tune[i]=6;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xBD)
		{
>>>>>>> bff2cfa (绾㈠閬ユ帶)
				C=7;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
<<<<<<< HEAD
			  delay(100);
			  TR0=0;
				song5_tune[i]=7;
			  song5_time[i]=3;
			  i++;}
			if(key2==1&&key3==1&&key4==1){
				C=1;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=1;
			  song5_time[i]=3;
			  i++;}			
		}
		
	  if(key2==0)
		{
			delay(300);
			if(key1==0){
				C=5;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=5;
			  song5_time[i]=3;
			  i++;}
			else{
				C=2;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=2;
			  song5_time[i]=3;
			  i++;
			}
		}
		
		if(key3==0)
		{
			delay(300);
			if(key1==0){
				C=6;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=6;
			  song5_time[i]=3;
			  i++;}
			else{
				C=3;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
			  song5_tune[i]=3;
			  song5_time[i]=3;
			  i++;
			}
		}
		
	  if(key4==0)
		{
			delay(300);
			if(key1==0){
				C=7;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=7;
			  song5_time[i]=3;
			  i++;}
			else{
				C=4;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=4;
			  song5_time[i]=3;
			  i++;
			}
		}
	}
	song5_tune[10]=0;
	song5_time[10]=0;
	return;
=======
			  delay(300);
			  TR0=0;
			  song5_tune[i]=7;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xAD)
		{
				C=8;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=8;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xB5)
		{
				C=9;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=9;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xBA)
		{
				C=10;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=10;
			  song5_time[i]=3;
			  i++;
		}
	  if(P2==0xB9)
		{
				C=11;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=11;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xB8)
		{
				C=12;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=12;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xBB)
		{
				C=13;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=13;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xBF)
		{
				C=14;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=14;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xBC)
		{
				C=15;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(300);
			  TR0=0;
			  song5_tune[i]=15;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xF6)
		{
			  song5_tune[i]=0;
			  song5_time[i]=3;
			  i++;
		}
		if(P2==0xE9)
		{	 song5_tune[i]=0;
			 song5_time[i]=0;
			 i++;
			 return;
			
		}
	}
>>>>>>> bff2cfa (绾㈠閬ユ帶)
}

 void TIM0(void) interrupt 1 using 1
 {
 	buzzer=~buzzer;
  TH0=tune[C]/256;
	TL0=tune[C]%256;
 }
 
 void delay(unsigned int s)
 {
 	 unsigned int i,j;
   for(i=0;i<s;i++)
	 for(j=0;j<100;j++)
	 ;
<<<<<<< HEAD
 }
=======
 }
 
 
>>>>>>> bff2cfa (绾㈠閬ユ帶)
