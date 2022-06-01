#include <REG52.H>
sbit LED1=P1^0;
sbit LED2=P1^1;
sbit LED3=P1^2;//LED=0时，亮灯

sbit key1=P3^2;
sbit key2=P3^3;
sbit key3=P3^4;
sbit key4=P3^5;

sbit buzzer=P2^4;

code unsigned int tune[]={0,64260,64400,64524,64580,64684,64777,64820,64898,64968,65030,65058,65110,65157,65178,65217};//存放各个音调所对应的定时时长 
code unsigned int song1_tune[]={5,5,6,5,8,7,0,5,5,6,5,9,8,0,5,5,12,10,8,7,6,0,11,11,10,8,10,9,0};
code unsigned int song1_time[]={3,3,6,6,6,6,6,3,3,6,6,6,6,6,3,3,6,6,6,3,3,6,3,3,6,6,6,6,0};
code unsigned int song2_tune[]={8,9,10,8,8,9,10,8,10,11,12,10,11,12,12,13,12,11,10,8,12,13,12,11,10,8,9,5,8,0,9,5,8,0};
code unsigned int song2_time[]={3,3,3,3,3,3,3,3,3,3,6,3,3,6,3,3,3,3,6,6,3,3,3,3,6,6,6,6,6,6,6,6,6,0};
code unsigned int song3_tune[]={6,7,8,12,11,0,5,6,7,11,10,0,10,10,13,12,11,9,0,7,7,8,9,11,10,0};
code unsigned int song3_time[]={3,3,6,6,6,6,3,3,6,6,6,6,3,3,6,6,6,6,3,3,6,3,6,6,6,0};
code unsigned int song4_tune[]={6,7,8,7,8,10,7,0,3,6,5,6,8,5,0,3,4,3,4,8,3,0,8,7,4,4,7,7,0};
code unsigned int song4_time[]={3,6,9,3,6,6,6,6,6,9,3,6,6,6,6,6,9,3,3,6,6,6,6,9,3,6,6,6,0};

//存放第一首音乐，其中高四位为音调，低四位为拍子

