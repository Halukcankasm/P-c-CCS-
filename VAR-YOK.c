#include <16f876A.h>
#device adc=10
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay(clock=4000000)

#include <lcd.c>
int var,yok,mesafe;
void main()
{
set_tris_a(0x01);
setup_adc(ADC_CLOCK_INTERNAL);
setup_adc_ports(AN0);
lcd_init();
set_adc_channel(0);
delay_us(20);

while(1)
{
mesafe=read_adc()/1024;
if(mesafe==0)
{printf(lcd_putc,"yok%d",mesafe);}
else if(mesafe==1)
{printf(lcd_putc,"var%d",mesafe);}


}
}
