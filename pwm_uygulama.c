#include <16f628A.h>
#fuses XT, NOWDT  
#use delay(clock=4M)


unsigned int8 duty_oran=0;  // pwm duty oran de�i�keni 
unsigned int8 hassasiyet=10; // 1 en y�ksek ��z�n�rl�kte

Void buton_kontrol(){
if(input(pin_a0)){while(input(pin_a0)); delay_ms(30); if(duty_oran<250)duty_oran+=hassasiyet; }
if(input(pin_a1)){while(input(pin_a1)); delay_ms(30); if(duty_oran>0)duty_oran-=hassasiyet;   }
set_pwm1_duty(duty_oran);  // butondan sonraki duty_oran�n� aktif ediyoruz.  
}
Void main(){
setup_timer_1(T1_DISABLED);          // timer 1 mod�l� devred���

setup_timer_2(T2_DIV_BY_16,254,1);   // pwm periyodunu 4.08ms olarak ayarlad�k.
setup_CCP1(CCP_PWM);                // pwm mod�l� aktif ettik

set_pwm1_duty(duty_oran);    // ba�lang�� i�in pwm duty oran�n� ayarlad�k
for(;;){                      // sonsuz d�ng�
buton_kontrol();
 }
}

/*
Timer 2 periyot hesaplamas�.
Osilat�r frekans�m�z 4MHz 
denetleyicinin kulland��� h�z, 4Mhz/4 = 1MHz (komut) 1/1MHz = komut periyot

pwm periyot = (1/1000000)*(pr2(254 Olarak ayarlad�k)+1)*b�lme oran�
4.08ms = 0.000001 * 255 * 16

ilk ba�ta duty oran�m�z 0, yani duty oran� 0 oldu�u s�rece pwm ��k��� 4.08ms boyunca s�rekli
lojik 1 de kalacak. Duty oran�m�z� 25 defa artt�rd���m�z� d���nelim yani duty oran�m�z 25 olsun.
 Basit bir orant� ile; 
 254 iken 4.08ms lojik 1'de kal�yorsa 
 25 iken ka� ms 1 de kal�r? 
 _____________i�ler d��lar �arp�m� ile do�ru orant�
 25*4.08/254= 0,40157480314960629921259842519685 ms 
 
 Yani duty oran�m�z 25 iken 
 %100       4,08ms
  x         0,40157480314960629921259842519685 ms
 _______do�ru orant�
 100*0,40157480314960629921259842519685/4,08 = %9,84 '� kadar lojik 1 de 
 kalacak arta kalan s�re lojik 0 olacak.
 
*/
