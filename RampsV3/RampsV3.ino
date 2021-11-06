#include <Arduino_FreeRTOS.h>
#include "HX711.h"

//TASK FUNCTION
void TaskLedUno(void *pvParameters);
void TaskLedDos(void *pvParameters);

void TaskEntrada(void *pvParameters);
void TaskEntradaSerial(void *pvParameters);
void TaskSalidaSerial(void *pvParameters);

void TaskFuerzaDerecha(void *pvParameters);
void TaskFuerzaIzquierda(void *pvParameters);
void TaskPesoDerecho(void *pvParameters);
void TaskPesoIzquierdo(void *pvParameters);

//DEFINE PORT'S
#define DOUT  A1 
#define CLK   A0

HX711 lectura(DOUT,CLK);

//DEFINE VAR
int valor = 0;
String comando="";
String val="";
bool flag = true;
////------------------------------------------------------------------------------
void TaskLedUno(void *pvParameters) {
    (void) pvParameters;
    
    pinMode(3,OUTPUT);    
    for(;;){
      
       digitalWrite(3, HIGH);
       vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for 500 milisecond
       digitalWrite(3, LOW);
       vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for 500 milisecond
    
    }
}
////------------------------------------------------------------------------------
void TaskLedDos(void *pvParameters) {
    (void) pvParameters;
    
    pinMode(2,OUTPUT);
    for(;;){
      
       digitalWrite(2, HIGH);
       vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
       digitalWrite(2, LOW);            
       vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    }
}
////------------------------------------------------------------------------------
void TaskEntrada(void *pvParameters){
  (void) pvParameters;
  int pinEntrada = 9;
  pinMode(pinEntrada, INPUT);

  for(;;){
      if(digitalRead(pinEntrada)){
          
        }else{
                    
        }
    }
}
////------------------------------------------------------------------------------FUERZA
////------------------------------------------------------------------------------DERECHA
void TaskFuerzaDerecha(void *pvParameters){
  (void) pvParameters;

  for(;;){
                
  }
}
////------------------------------------------------------------------------------FUERZA
////------------------------------------------------------------------------------IZQUIERDA
void TaskFuerzaIzquierda(void *pvParameters){
  (void) pvParameters;
  
  for(;;){
      
  }
}
////------------------------------------------------------------------------------PESO
////------------------------------------------------------------------------------DERECHO
void TaskPesoDerecho(void *pvParameters){
  (void) pvParameters;
  
  for(;;){

  }
}
////------------------------------------------------------------------------------PESO
////------------------------------------------------------------------------------IZQUIERDO
void TaskPesoIzquierdo(void *pvParameters){
  (void) pvParameters;
  
  for(;;){
   
  }
}
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
void TaskEntradaSerial(void *pvParameters){
  (void) pvParameters;
  
  for(;;){
     if(Serial.available()>0){
             
          val = Serial.read();
             
          if(val=="112"){
                flag=false;
           }else{
               //Serial.println(val);
           }
     }
  } 
}
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
void TaskSalidaSerial(void *pvParameters){
  (void) pvParameters;
  
  for(;;){
       
       if(flag){
                    Serial.print("valor: ");
                    valor = lectura.read();
                    Serial.println(valor);
                    vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for one seconD
          }else{
                    Serial.print("Prueba: ");
                    Serial.println(20000);
                    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second  
                    flag=true;        
            }  
  } 
}
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  //xTaskCreate(nombreFuncion,"nombreGenerico",128,parametrosFuncion,1,NULL);
  
  Serial.begin(9600);
  Serial.setTimeout(50);
  
  xTaskCreate(TaskLedUno,"ledUno",128,NULL,1,NULL);
  xTaskCreate(TaskLedDos ,"ledDos",128,NULL,1,NULL);    
  xTaskCreate(TaskEntrada ,"entrada",128,NULL,1,NULL);  
   
   xTaskCreate(TaskFuerzaDerecha    ,"FD",128,NULL,1,NULL); 
   xTaskCreate(TaskFuerzaIzquierda  ,"FI",128,NULL,1,NULL); 
   xTaskCreate(TaskPesoDerecho      ,"PD",128,NULL,1,NULL); 
   xTaskCreate(TaskPesoIzquierdo    ,"PI",128,NULL,1,NULL); 
  
  xTaskCreate(TaskEntradaSerial ,"entradaSerial",128,NULL,1,NULL); 
  xTaskCreate(TaskSalidaSerial ,"salidaSerial",128,NULL,1,NULL); 

}
////------------------------------------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  //Rtos, Don't code right here
}
