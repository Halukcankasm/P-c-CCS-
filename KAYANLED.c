#include <LED2.h>

void main()
{

   
      set_tris_b(0x00);
   while(TRUE)
   {
   output_high(pin_b4);
      
      output_high(pin_b0);
      delay_ms(100);
      output_low(pin_b0);
      delay_ms(100);
      
      output_high(pin_b1);
      delay_ms(100);
      output_low(pin_b1);
      delay_ms(100);
      
      output_high(pin_b2);
      delay_ms(100);
      output_low(pin_b2);
      delay_ms(100);
      
      output_high(pin_b3);
      delay_ms(100);
      output_low(pin_b3);
      delay_ms(100);
      
      output_high(pin_b3);
      delay_ms(100);
      output_low(pin_b3);
      delay_ms(100);
      
      output_high(pin_b2);
      delay_ms(100);
      output_low(pin_b2);
      delay_ms(100);
      
      output_high(pin_b1);
      delay_ms(100);
      output_low(pin_b1);
      delay_ms(100);
      
      output_high(pin_b0);
      delay_ms(100);
      output_low(pin_b0);
      delay_ms(100);
      
   }

}
