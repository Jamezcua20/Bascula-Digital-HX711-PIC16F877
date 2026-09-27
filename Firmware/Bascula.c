#include <16F877.h>
#fuses XT,NOWDT
#use delay(clock= 4 MHz)  
#Include <Lcd_c.c>
#include "hx711.c"

   // Declaración de variables //
float referencia = 0;
int32 zero = 0;
   // Declaración de variables //

void zeroin(){

   // Declaración de variables //
   int1 PVR = 0; 
   // Declaración de variables //
      
   printf(lcd_putc,"\f   Despejar la \n    balanza");
   delay_ms(2500);
   Printf(lcd_putc,"\fPresionar boton \n 1 para iniciar");
   While(PVR == 0){        
    if((input(pin_b5)==0)){
       PVR = 1;
       delay_ms(500);
                          }
                   }
     Printf(lcd_putc,"\fEspere...");
     zero = get_value(50);
     printf(lcd_putc,"\f Listo\n Ref = %Lu", zero);
     delay_ms(3000);
}


void calibracion (){

   // Declaración de variables //
   int DVR = 0;
   int16 Ref = 3700;
   int32 Valor_leido  = 0;
   float div;
   // Declaración de variables //
      
   Printf(lcd_putc,"\f   Calibracion \n   inicial");
   delay_ms(2000);
         Printf(lcd_putc,"\fPoner valor de \n referencia 1");
         delay_ms(2000);
         Printf(lcd_putc,"\fPresionar boton \n 1 para iniciar");
         While(DVR == 0){        
            if((input(pin_b5)==0)){
               DVR = 1;
               delay_ms(500);
                                  }
                        }
                        
        Printf(lcd_putc,"\fRef = 3700 g");
        Valor_leido = get_value(50);
        Lcd_gotoxy(1,2);
        printf(lcd_putc,"\fADC = %Lu", Valor_leido);
        DVR = 0;
        div =  (Valor_leido - zero );
        Referencia = (ref/div);
        delay_ms(1500);
        
         
        printf(lcd_putc,"\f Calibracion \n terminada");          
}

void main (){
   port_b_pullups(true);
   
   // Declaración de variables //
   int32 adc_lecture;
   int unidades = 0;
   float peso = 0;
   Char Cadena[16] = "Gramos";
   float rest = 0;
   int32 AVR = 0;
   // Declaración de variables // 
   
   init_hx(128);
   lcd_init();
   
   printf(lcd_putc,"\fBascula digital");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Instrumentacion");
   delay_ms(2000);
   
   zeroin();
   calibracion();
   AVR = Zero;
   printf(lcd_putc,"\f");
   
   While(true){
      lcd_gotoxy(1,1);
      adc_lecture = get_value(15);
      Rest = (adc_lecture - zero);
      
      
      Peso = rest * referencia;
      if(adc_lecture <= zero)
         peso = 0;
         
      if (unidades == 1){
         
         peso = peso / 28.35;
      }
      if (unidades == 2){
         peso = peso * .00220462;
      }
      
      for(int i = 0; i<15;i++){
      delay_ms(5);
      if((input(pin_b5)==0) && (input(pin_b6)==1) && (input(pin_b7)==1)){
         if(cadena == "Onza")
           peso = 0; 
           
         cadena = "Gramos";
         Peso = rest * referencia;
         unidades = 0;
      }
      
      if((input(pin_b5)==1) && (input(pin_b6)==0) && (input(pin_b7)==1)){
         cadena = "Onza";
         peso = peso / 28.35;
         unidades = 1;
      }
      if((input(pin_b5)==1) && (input(pin_b6)==1) && (input(pin_b7)==0)){
         cadena = "Libras";
         peso = peso * .00220462;
         unidades = 2;
      }
      printf(lcd_putc,"Valor: %.3f            ", peso);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"    %s           ",cadena);
      lcd_gotoxy(1,1);
      
      if((input(pin_b5)==0)  && (input(pin_b7)==0)){
         delay_ms(1000);
         
         if((input(pin_b5)==0)  && (input(pin_b7)==0)){
            printf(lcd_putc,"\f Desea tarar?");
            delay_ms(2500);
            Printf(lcd_putc,"\fBoton 1 ----> Si \nBoton 2 ----> No");
            delay_ms(2500);
            
            if((input(pin_b5)==0)){
               printf(lcd_putc,"\f Espere...");
               zero = get_value(50);
               printf(lcd_putc,"\f");
                                  }
            
            if((input(pin_b6)==0)){
               Zero = AVR;
               printf(lcd_putc,"\f");
                                  }
                                                      }
         
                                                      }
                               }
   }
}
