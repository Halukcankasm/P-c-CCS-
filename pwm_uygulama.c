#include <16f628A.h>
#fuses XT, NOWDT  
#use delay(clock=4M)


unsigned int8 duty_oran=0;  // pwm duty oran deðiþkeni 
unsigned int8 hassasiyet=10; // 1 en yüksek çözünürlükte

Void buton_kontrol(){
if(input(pin_a0)){while(input(pin_a0)); delay_ms(30); if(duty_oran<250)duty_oran+=hassasiyet; }
if(input(pin_a1)){while(input(pin_a1)); delay_ms(30); if(duty_oran>0)duty_oran-=hassasiyet;   }
set_pwm1_duty(duty_oran);  // butondan sonraki duty_oranýný aktif ediyoruz.  
}
Void main(){
setup_timer_1(T1_DISABLED);          // timer 1 modülü devredýþý

setup_timer_2(T2_DIV_BY_16,254,1);   // pwm periyodunu 4.08ms olarak ayarladýk.
setup_CCP1(CCP_PWM);                // pwm modülü aktif ettik

set_pwm1_duty(duty_oran);    // baþlangýç için pwm duty oranýný ayarladýk
for(;;){                      // sonsuz döngü
buton_kontrol();
 }
}

/*
Timer 2 periyot hesaplamasý.
Osilatör frekansýmýz 4MHz 
denetleyicinin kullandýðý hýz, 4Mhz/4 = 1MHz (komut) 1/1MHz = komut periyot

pwm periyot = (1/1000000)*(pr2(254 Olarak ayarladýk)+1)*bölme oraný
4.08ms = 0.000001 * 255 * 16

ilk baþta duty oranýmýz 0, yani duty oraný 0 olduðu sürece pwm çýkýþý 4.08ms boyunca sürekli
lojik 1 de kalacak. Duty oranýmýzý 25 defa arttýrdýðýmýzý düþünelim yani duty oranýmýz 25 olsun.
 Basit bir orantý ile; 
 254 iken 4.08ms lojik 1'de kalýyorsa 
 25 iken kaç ms 1 de kalýr? 
 _____________içler dýþlar çarpýmý ile doðru orantý
 25*4.08/254= 0,40157480314960629921259842519685 ms 
 
 Yani duty oranýmýz 25 iken 
 %100       4,08ms
  x         0,40157480314960629921259842519685 ms
 _______doðru orantý
 100*0,40157480314960629921259842519685/4,08 = %9,84 'ü kadar lojik 1 de 
 kalacak arta kalan süre lojik 0 olacak.
 
*/
