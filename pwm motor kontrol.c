#include <16F877A.h> // kullanaca��m�z pic'in k�t�phanesini ekliyoruz
#FUSES NOWDT         //Watch dog timer kapat�yoruz
#FUSES NOBROWNOUT    //Brownout Reset kapat�yoruz
#FUSES NOLVP         //D���k voltaj programlama kapal�

#use delay(crystal=4000000) //Osilat�r frekans� ayarlan�yor.

#use fast_io(c)
unsigned long int k; //data=adc , k pwm de�eri olacak

//
#define ILERI PIN_D0
#define GERI PIN_D1

void main()
{
//16F877A p�c ayarlar�n� 
  setup_psp(PSP_DISABLED);
  setup_spi(SPI_SS_DISABLED);
  setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
  setup_timer_1(T1_DISABLED);//T1 Timerini kapat�yoruz
  setup_timer_2(T2_DIV_BY_16,255,1);//PWM i�in timer 2 kullan�l�yor , maksimum de�eri 255 olarak ayarl�yoruz
  set_tris_c(0x00);
  setup_ccp1(CCP_PWM);//CCP1 ayarlan�yor Pic C2 portunu kullan�lacak
  set_pwm1_duty(k);//PWM AYAR
  delay_us(20);


while(1)
{
while(input(ILERI)){//while ile ileri butonuna bas�l�p bas�lmad���n� kontrol ediyoruz.
k = k+20;
set_pwm1_duty(k);//k de�i�kenin de�erini PWM e aktard�k
delay_us(100);//100ns beklendi
}
while(input(GERI)){//while ile geri butonun bas�l�p bas�lmad��� kontrol edilir
k=k-20;//k de�i�kenin de�erini azalt�yoruz.
set_pwm1_duty(k);//k de�erini PWM aktar�l�r
delay_ms(100);//100ns bekleniyor
}
}
}
//           ***SON***    //    
