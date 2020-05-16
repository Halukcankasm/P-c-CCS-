#include<16f876a.h>
#device ADC = 10 
#fuses XT
#fuses NOWDT
#fuses NOLVP
#fuses NOPROTECT

#USE delay(clock = 4000000)



int a;
int i;
int potvalue,yzaman,bekle;


void main(){
setup_adc(ADC_CLOCK_INTERNAL);
setup_adc_ports(AN0);
setup_ccp1(CCP_OFF);
setup_ccp2(CCP_OFF);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);




set_tris_a(0xff);
set_tris_b(0x00);
set_tris_c(0x00);
output_b(0x00);
output_c(0x00);

 

while(1){
set_adc_channel(0); 
delay_us(20);
potvalue=read_adc();
a=((potvalue*10)+600);

if(a>2600){
a=2650;}
for(i=0;i<50;i++){
output_high(pin_b0);
delay_us(a);
output_low(pin_b0);
delay_us(20000-a);

}

}

}

