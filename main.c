#include <16F876A.h>
#device adc=10 // 10 bitlik adc kullan�l�yor.
#use delay(clock=4M) // osilat�r frekans�
#fuses XT ,NOWDT, NOLVP, NOPROTECT // sigorta ayarlar�
#use fast_io(c) // C portunun kullan�laca�� belirtiliyor
#define button_ileri pin_b4 // B4 pinin step motor i�in ileri y�nde tan�mlad�k
#define button_geri pin_b5 // B5 pinin step motor i�in geri y�nde tan�mlad�k
#define button_dur pin_b6 // B6 pinini step motor i�in durdurmak i�in tan�mlad�n
unsigned long int bilgi,bilgi1,bilgi2,bilgi3; // bilgi ad�nda i�aretsiz tam say� de�i�keni tan�mlan�yor.
 int motor=0;

 int hiz=100;
 int ileri[]={0x01,0x02,0x04,0x08};
 int geri[]={0x08,0x04,0x02,0x01};

void main()
{
 
setup_adc(adc_clock_div_32); // ADC clock frekans� fosc/32
setup_adc_ports(0); // A0 pini analog giri� olarak ayarlan�yor.

set_tris_c(0x00); // c portu ��k�� olarak ayarlan�yor.
 set_tris_b(0x70); //b portunun b0-b1-b2-b3 bacaklar� ��k�� - b4-b5-b6 bacaklar� giri� 
 output_c(0x00);
 output_b(0x00);


while(1)
{
if (input(button_dur))
        {
          output_low(pin_b0); // eger dur butonuna bas�l�rsa step motoru durdur
          output_low(pin_b1);
          output_low(pin_b2);
          output_low(pin_b3);
         
        }
        else {                // bas�lmaz ise d
        if (input(button_ileri)) // step motoru ileri y�nde �al�n�t�r
        {
            for (motor=0; motor<=3; motor++)
            {
                output_b(ileri[motor]);
                delay_ms(hiz);  // 50ms bekle
            }
        }
        
          else {
      if (input(button_geri)) // step motoru geri y�nde �al��t�r
        {
            for (motor=0; motor<=3; motor++)
            {
                output_b(geri[motor]);
                delay_ms(hiz); 
                }
        }
        
        }

set_adc_channel(0); // A3 pini adc i�lemine tabi tutuluyor.
bilgi=read_adc(); // okunan de�er bilgi de�i�kenine aktar�l�yor.
bilgi=bilgi*1.024+1000; // bilgi de�i�keninin de�eri ayarlan�yor.
delay_ms(20);


set_adc_channel(1); // A3 pini adc i�lemine tabi tutuluyor.
bilgi1=read_adc(); // okunan de�er bilgi de�i�kenine aktar�l�yor.
bilgi1=bilgi1*1.024+1000; // bilgi de�i�keninin de�eri ayarlan�yor.
delay_ms(20);

set_adc_channel(2); // A3 pini adc i�lemine tabi tutuluyor.
bilgi2=read_adc(); // okunan de�er bilgi de�i�kenine aktar�l�yor.
bilgi2=bilgi2*1.024+1000; // bilgi de�i�keninin de�eri ayarlan�yor.
delay_ms(20);

set_adc_channel(3); // A3 pini adc i�lemine tabi tutuluyor.
bilgi3=read_adc(); // okunan de�er bilgi de�i�kenine aktar�l�yor.
bilgi3=bilgi3*1.024+1000; // bilgi de�i�keninin de�eri ayarlan�yor.
 delay_ms(20);

output_high(PIN_c0);
delay_us(bilgi);
output_low(PIN_c0);
delay_us(25000-bilgi);

output_high(PIN_c1);
delay_us(bilgi1);
output_low(PIN_c1);
delay_us(25000-bilgi1);

output_high(PIN_c2);
delay_us(bilgi2);
output_low(PIN_c2);
delay_us(25000-bilgi2);

output_high(PIN_c3);
delay_us(bilgi3);
output_low(PIN_c3);
delay_us(25000-bilgi3);
 
}
}
}

