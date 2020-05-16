#include <16F876A.h>
#device adc=10 // 10 bitlik adc kullanýlýyor.
#use delay(clock=4M) // osilatör frekansý
#fuses XT ,NOWDT, NOLVP, NOPROTECT // sigorta ayarlarý
#use fast_io(c) // C portunun kullanýlacaðý belirtiliyor
#define button_ileri pin_b4 // B4 pinin step motor için ileri yönde tanýmladýk
#define button_geri pin_b5 // B5 pinin step motor için geri yönde tanýmladýk
#define button_dur pin_b6 // B6 pinini step motor için durdurmak için tanýmladýn
unsigned long int bilgi,bilgi1,bilgi2,bilgi3; // bilgi adýnda iþaretsiz tam sayý deðiþkeni tanýmlanýyor.
 int motor=0;

 int hiz=100;
 int ileri[]={0x01,0x02,0x04,0x08};
 int geri[]={0x08,0x04,0x02,0x01};

void main()
{
 
setup_adc(adc_clock_div_32); // ADC clock frekansý fosc/32
setup_adc_ports(0); // A0 pini analog giriþ olarak ayarlanýyor.

set_tris_c(0x00); // c portu çýkýþ olarak ayarlanýyor.
 set_tris_b(0x70); //b portunun b0-b1-b2-b3 bacaklarý çýkýþ - b4-b5-b6 bacaklarý giriþ 
 output_c(0x00);
 output_b(0x00);


while(1)
{
if (input(button_dur))
        {
          output_low(pin_b0); // eger dur butonuna basýlýrsa step motoru durdur
          output_low(pin_b1);
          output_low(pin_b2);
          output_low(pin_b3);
         
        }
        else {                // basýlmaz ise d
        if (input(button_ileri)) // step motoru ileri yönde çalýnþtýr
        {
            for (motor=0; motor<=3; motor++)
            {
                output_b(ileri[motor]);
                delay_ms(hiz);  // 50ms bekle
            }
        }
        
          else {
      if (input(button_geri)) // step motoru geri yönde çalýþtýr
        {
            for (motor=0; motor<=3; motor++)
            {
                output_b(geri[motor]);
                delay_ms(hiz); 
                }
        }
        
        }

set_adc_channel(0); // A3 pini adc iþlemine tabi tutuluyor.
bilgi=read_adc(); // okunan deðer bilgi deðiþkenine aktarýlýyor.
bilgi=bilgi*1.024+1000; // bilgi deðiþkeninin deðeri ayarlanýyor.
delay_ms(20);


set_adc_channel(1); // A3 pini adc iþlemine tabi tutuluyor.
bilgi1=read_adc(); // okunan deðer bilgi deðiþkenine aktarýlýyor.
bilgi1=bilgi1*1.024+1000; // bilgi deðiþkeninin deðeri ayarlanýyor.
delay_ms(20);

set_adc_channel(2); // A3 pini adc iþlemine tabi tutuluyor.
bilgi2=read_adc(); // okunan deðer bilgi deðiþkenine aktarýlýyor.
bilgi2=bilgi2*1.024+1000; // bilgi deðiþkeninin deðeri ayarlanýyor.
delay_ms(20);

set_adc_channel(3); // A3 pini adc iþlemine tabi tutuluyor.
bilgi3=read_adc(); // okunan deðer bilgi deðiþkenine aktarýlýyor.
bilgi3=bilgi3*1.024+1000; // bilgi deðiþkeninin deðeri ayarlanýyor.
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

