/* ----- Includes referentes ao PIC ----- */
#include <16F628A.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES INTRC_IO                 //Clock interno de 4MHz
#FUSES PUT                      //Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading

#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES MCLR

#use delay(clock=4000000)

#use fast_io(a)
#use fast_io(b)

/* ----- Configuração das portas ----- */

#byte PORT_A = 0x05
#byte PORT_B = 0x06

#byte TRIS_A = 0x85
#byte TRIS_B = 0x86

#bit BUTTON = PORT_A.2   //BOTAO DE CALIBRACAO
#bit RESERVA = PORT_A.1 //ENTRADA VINDA DO ZIGBEE
#bit LED1 = PORT_B.1 //LED QUE VERIFICA SE O BOTAO FOI APERTADO
#bit B0 = PORT_B.0 //BIT DE INTERRUPCAO
#bit VERMELHO = PORT_B.4  //LED VERMELHO
#bit VERDE = PORT_B.5  //LED VERDE
#bit AMARELO = PORT_B.6 //LED AMARELO

int16 ref = 0;
int16 tempo = 0;
int count;

#INT_EXT
void pulsin(){
   disable_interrupts(GLOBAL);
   disable_interrupts(INT_EXT);
   
   count = 0;
   
   while(B0){
      count++;
      delay_ms(1);
   }
   tempo = count;
   
   enable_interrupts(GLOBAL | INT_EXT);
}


void main(){
   TRIS_A = 0b00000110; // 
   TRIS_B = 0b00000001; //Habilitado para leitura
   
   VERDE = 0;
   VERMELHO = 0;
   AMARELO = 0;
   BUTTON = 0;
   RESERVA = 0;
   B0 = 0;
   LED1 = 0;
   
   ext_int_edge(L_TO_H);      
   enable_interrupts(GLOBAL | int_ext);
   
   while(true){
      if(RESERVA){ 
         if(tempo < ref){
            VERMELHO = 1;
            VERDE = 0;
            AMARELO = 0;
         }else{
            VERMELHO = 0;
            VERDE = 0;
            AMARELO = 1;
         }
      }else{
         if(tempo < ref){
            VERMELHO = 1;
            VERDE = 0;
            AMARELO = 0;
         }else{
            VERMELHO = 0;
            VERDE = 1;
            AMARELO = 0;
         }
      }
     
      if(BUTTON){
            ref = tempo;
            LED1 = 1;
         }else{
            LED1 = 0;
      }
   }
}
