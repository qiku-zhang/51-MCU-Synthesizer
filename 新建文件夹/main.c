#include <main.h>
#include <REG52.H>

extern void LCD0();

unsigned int C;
unsigned int song5_tune[11];
unsigned int song5_time[11];
void music();
void piano();
void record();
void delay(unsigned int s);
void LCD0();
void main(void)
{
  while(1){
	LED1=0;
	LED2=0;
	LED3=0;
	LCD0();
	while(key1==1&&key2==1&&key3==1)
	{}
	if(key1==0)
	{
		LED1=0;
		LED2=1;
		LED3=1;
		LCD0();
		delay(1000);
    music();
	}
		
	if(key2==0)
	{
		LED1=1;
		LED2=0;
		LED3=1;
		LCD0();
		delay(1000);
		piano();
	}
		
	if(key3==0)
	{
		LED1=1;
		LED2=1;
		LED3=0;
		LCD0();
		delay(1000);
		record();
	}
 }
} 

 
void music()
{
	unsigned char i;
	unsigned int s;
 	TMOD=0x01;
	EA=1;
	ET0=1;
	while(1){
	if(key1==0)
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
							s=100*song1_time[i];
				      delay(s);
              TR0=0;				
			      }
		    }
	  }
		break;
  }
 if(key2==0)
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
		break;
  }
 if(key3==0)
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
		break;
  }
 if(key4==0)
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
		break;
  }			
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
		if(key1==0)
		{
			delay(300);
			if(key2==0&&key3==1&&key4==1){
				C=5;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;}
			if(key2==1&&key3==0&&key4==1){
				C=6;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;}
			if(key2==1&&key3==1&&key4==0){
				C=7;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
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
}
		

void record()
{
	int i=0;
	TMOD=0x01;
	EA=1;
	ET0=1;
	while(i<=9)
	{
		if(key1==0)
		{
			delay(300);
			if(key2==0&&key3==1&&key4==1){
				C=5;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
			  song5_tune[i]=5;
			  song5_time[i]=3;
			  i++;}
			if(key2==1&&key3==0&&key4==1){
				C=6;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
			  delay(100);
			  TR0=0;
				song5_tune[i]=6;
			  song5_time[i]=3;
			  i++;}
			if(key2==1&&key3==1&&key4==0){
				C=7;
			  TH0=tune[C]/256;
			  TL0=tune[C]%256;
			  TR0=1;
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
 }