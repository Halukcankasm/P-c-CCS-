#include<16f876a.h>
#fuses XT,NOPROTECT,NOWDT,NOLVP
#USE delay(clock=4000000)
#byte   portc=0x06
#include <lcd.c>

#define sut1 pin_c0
#define sut2 pin_c1
#define sut3 pin_c2
#define sut4 pin_c3

#define sat1 pin_c4
#define sat2 pin_c5
#define sat3 pin_c6
#define sat4 pin_c7

#define use_portb_lcd TRUE
char tus=0;
int i;
char keypad_oku(){

output_c(0x00);

output_high(sat1);
if(input(sut1))
{delay_ms(20); tus=1;}
if(input(sut2))
{delay_ms(20); tus=2;}
if(input(sut3))
{delay_ms(20); tus=3;}
if(input(sut4))
{delay_ms(20); tus=0xA;}
output_low(sat1);

output_high(sat2);
if(input(sut1))
{delay_ms(20); tus=4;}
if(input(sut2))
{delay_ms(20); tus=5;}
if(input(sut3))
{delay_ms(20); tus=6;}
if(input(sut4))
{delay_ms(20); tus=0xB;}
output_low(sat2);

output_high(sat3);
if(input(sut1))
{delay_ms(20); tus=7;}
if(input(sut2))
{delay_ms(20); tus=8;}
if(input(sut3))
{delay_ms(20); tus=9;}
if(input(sut4))
{delay_ms(20); tus=0xC;}
output_low(sat2);

output_high(sat3);
if(input(sut1))
{delay_ms(20); tus=0xE;}
if(input(sut2))
{delay_ms(20); tus=0;}
if(input(sut3))
{delay_ms(20); tus=0xF;}
if(input(sut4))
{delay_ms(20); tus=0xD;}
output_low(sat1);

return tus;

}

void main()
{
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_adc(ADC_OFF);
setup_adc_ports(NO_ANALOGS);
setup_CCP1(CCP_OFF);
setup_CCP2(CCP_OFF);

set_tris_b(0x00);
set_tris_c(0x0F);
output_c(0x00);
output_b(0x00);

lcd_init();

lcd_putc("\f");

while(1){



lcd_gotoxy(i,1);
printf(lcd_putc,"%d",keypad_oku() );


}

i=i+1;
}

