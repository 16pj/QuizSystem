#include<reg51.h>
unsigned int digi_val[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};
// Hex value corresponding to the digits 0 to 9

int flag;
sbit output_on_pin = P3^0;// Enable pin to enable the seven segment.
sbit stop_pin = P3^1;// Stop pin to reset the buzzer.
//sbit buzzer_pin=P0^0;// Buzzer pin to sound the buzzer.

sbit clkin = P0^0; //Clock input to Counter
sbit buzzerp = P0^2; //Pin to set Buzzer
sbit swit = P3^2; //Timer Reset pin
sbit torb = P3^3; //Timer or Buzzer Pin


void delay(int b) // one sec delay function
{
int i,j,k;
	for (k=0;k<b;k++)
for(i=0;i<82;i++)
for(j=0;j<1275;j++);
}



void timerckt(int a) // TIMER CONTROL
{ 
	buzzerp=0;
if(torb == 0){
	while (swit == 0 )
	{ if (a == 0)
		{ clkin=0;
			buzzerp=1;
			delay(3);
			buzzerp=0;
			if(torb == 1) return;
}
		
		else  {
			if (torb == 1) return;
		clkin=0;
	delay(1);
	clkin=1;
		delay(1);
	}
	if(swit == 0)
	a=a-1;
	else return;
}}
return;
}


void display(unsigned int current_dig) // Function to display result in seven segment and sound the buzzer.
{
	if(torb == 1 ){
P2=digi_val[current_dig];
output_on_pin = 1;
	
while(stop_pin != 0) if(torb == 0) return;}
}
void buzzer() //Function to monitor the input switches
{
flag = 0;
	if(torb == 0) return;
while(1)
{
  while (P1 == 0xFF) if(torb == 0) return;;
  while (P1 == 0xFE) //Check if switch 1 is pressed
{
flag = 1;
display(1);
}
while (P1 == 0xFD) //Check if switch 2 is pressed
{
flag = 2;
display(2);
}
while (P1 == 0xFB ) 
{
flag = 3;
display(3);
}
while (P1 == 0xF7 ) 
{
flag = 4;
display(4);
}
while (P1 == 0xEF ) 
{
flag = 5;
display(5);
}
while (P1 == 0xDF) 
{
flag = 6;
display(6);
}
while (P1 == 0xBF ) 
{
flag = 7;
display(7);
}
while (P1 == 0x7F ) 
{
flag = 8;
display(8);
} 
stop_pin = 1;
output_on_pin = 0;

}
}

void main()
{
int	a=6;
buzzerp=0;
if(torb == 1){
output_on_pin=0;
stop_pin = 1;
P1 = 0xFF;
buzzer();}

else timerckt(a);
return ;
}


