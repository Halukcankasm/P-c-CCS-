#include <16F877A.h> // kullanacaðýmýz pic'in kütüphanesini ekliyoruz
#FUSES NOWDT         //Watch dog timer kapatýyoruz
#FUSES NOBROWNOUT    //Brownout Reset kapatýyoruz
#FUSES NOLVP         //Düþük voltaj programlama kapalý

#use delay(crystal=4000000) //Osilatör frekansý ayarlanýyor.

#use fast_io(c)
unsigned long int k; //data=adc , k pwm deðeri olacak

//
#define ILERI PIN_D0
#define GERI PIN_D1

void main()
{
//16F877A pýc ayarlarýný 
  setup_psp(PSP_DISABLED);
  setup_spi(SPI_SS_DISABLED);
  setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
  setup_timer_1(T1_DISABLED);//T1 Timerini kapatýyoruz
  setup_timer_2(T2_DIV_BY_16,255,1);//PWM için timer 2 kullanýlýyor , maksimum deðeri 255 olarak ayarlýyoruz
  set_tris_c(0x00);
  setup_ccp1(CCP_PWM);//CCP1 ayarlanýyor Pic C2 portunu kullanýlacak
  set_pwm1_duty(k);//PWM AYAR
  delay_us(20);


while(1)
{
while(input(ILERI)){//while ile ileri butonuna basýlýp basýlmadýðýný kontrol ediyoruz.
k = k+20;
set_pwm1_duty(k);//k deðiþkenin deðerini PWM e aktardýk
delay_us(100);//100ns beklendi
}
while(input(GERI)){//while ile geri butonun basýlýp basýlmadýðý kontrol edilir
k=k-20;//k deðiþkenin deðerini azaltýyoruz.
set_pwm1_duty(k);//k deðerini PWM aktarýlýr
delay_ms(100);//100ns bekleniyor
}
}
}
//           ***SON***    //    
