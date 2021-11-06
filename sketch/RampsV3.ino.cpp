#include <Arduino.h>
#line 1 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
#include <Arduino_FreeRTOS.h>
#include "HX711.h"

void TaskLedUno(void *pvParameters);
void TaskLedDos(void *pvParameters);
void TaskEntrada(void *pvParameters);
void TaskHX711(void *pvParameters);

//DEFINE PORT'S
#define DOUT  A1 
#define CLK   A0


HX711 lectura(DOUT,CLK);
//DEFINE FUNCTIONS

float valor = 0;

////------------------------------------------------------------------------------
#line 71 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
void setup();
#line 81 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
void loop();
#line 20 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
void TaskLedUno(void *pvParameters) {
    (void) pvParameters;
    
    pinMode(3,OUTPUT);    
    for(;;){
       digitalWrite(3, HIGH);
       vTaskDelay( 500 / portTICK_PERIOD_MS ); // wait for 500 milisecond
       digitalWrite(3, LOW);
       vTaskDelay( 500 / portTICK_PERIOD_MS ); // wait for 500 milisecond
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
  Serial.begin(9600);

  for(;;){
      if(digitalRead(pinEntrada)){
          
        }else{
                    Serial.print("valor: ");
                    Serial.println(valor);
                    vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for one second
        }
    }
}
////------------------------------------------------------------------------------
void TaskHX711(void *pvParameters){
  (void) pvParameters;


  
  for(;;){
      
  }
}
////------------------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  //xTaskCreate(nombreFuncion,"nombreGenerico",128,parametrosFuncion,1,NULL);
  
  xTaskCreate(TaskLedUno,"ledUno",128,NULL,1,NULL);
  xTaskCreate(TaskLedDos ,"ledDos",128,NULL,1,NULL);    
  xTaskCreate(TaskEntrada ,"entrada",128,NULL,1,NULL);  
  xTaskCreate(TaskHX711 ,"hx711",128,NULL,1,NULL); 
}
////------------------------------------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  //Rtos, Don't code right here
}

