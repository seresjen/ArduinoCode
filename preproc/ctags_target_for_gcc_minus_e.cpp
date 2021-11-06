# 1 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
# 2 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 2
# 3 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 2

void TaskLedUno(void *pvParameters);
void TaskLedDos(void *pvParameters);
void TaskEntrada(void *pvParameters);
void TaskHX711(void *pvParameters);

//DEFINE PORT'S




HX711 lectura(A1,A0);
//DEFINE FUNCTIONS

float valor = 0;

////------------------------------------------------------------------------------
void TaskLedUno(void *pvParameters) {
    (void) pvParameters;

    pinMode(3,0x1);
    for(;;){
       digitalWrite(3, 0x1);
       vTaskDelay( 500 / ( (TickType_t) 
# 26 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                        (1 << (0 
# 26 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                        /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 4
# 26 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                        )) 
# 26 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                        ) ); // wait for 500 milisecond
       digitalWrite(3, 0x0);
       vTaskDelay( 500 / ( (TickType_t) 
# 28 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                        (1 << (0 
# 28 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                        /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 4
# 28 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                        )) 
# 28 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                        ) ); // wait for 500 milisecond
    }
}
////------------------------------------------------------------------------------
void TaskLedDos(void *pvParameters) {
    (void) pvParameters;

    pinMode(2,0x1);
    for(;;){
       digitalWrite(2, 0x1);
       vTaskDelay( 1000 / ( (TickType_t) 
# 38 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                         (1 << (0 
# 38 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                         /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 4
# 38 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                         )) 
# 38 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                         ) ); // wait for one second
       digitalWrite(2, 0x0);
       vTaskDelay( 1000 / ( (TickType_t) 
# 40 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                         (1 << (0 
# 40 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                         /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 4
# 40 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                         )) 
# 40 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                         ) ); // wait for one second
    }
}
////------------------------------------------------------------------------------
void TaskEntrada(void *pvParameters){
  (void) pvParameters;
  int pinEntrada = 9;
  pinMode(pinEntrada, 0x0);
  Serial.begin(9600);

  for(;;){
      if(digitalRead(pinEntrada)){

        }else{
                    Serial.print("valor: ");
                    Serial.println(valor);
                    vTaskDelay( 100 / ( (TickType_t) 
# 56 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                                     (1 << (0 
# 56 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                     /* portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick*/ + 4
# 56 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3
                                     )) 
# 56 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                     ) ); // wait for one second
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

  xTaskCreate(TaskLedUno,"ledUno",128,
# 75 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                     __null
# 75 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                         ,1,
# 75 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                            __null
# 75 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                                );
  xTaskCreate(TaskLedDos ,"ledDos",128,
# 76 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                      __null
# 76 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                          ,1,
# 76 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                             __null
# 76 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                                 );
  xTaskCreate(TaskEntrada ,"entrada",128,
# 77 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                        __null
# 77 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                            ,1,
# 77 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                               __null
# 77 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                                   );
  xTaskCreate(TaskHX711 ,"hx711",128,
# 78 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                    __null
# 78 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                        ,1,
# 78 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino" 3 4
                                           __null
# 78 "C:\\Users\\user\\Desktop\\Nueva Electronica\\Arduino\\RampsV3\\RampsV3.ino"
                                               );
}
////------------------------------------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  //Rtos, Don't code right here
}
