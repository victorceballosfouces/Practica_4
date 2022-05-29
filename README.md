# Practica_4

## Codigo_4.1
```cpp
#include <Arduino.h>
 
/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
/* loop forever */
for(;;)
{
Serial.println("this is another Task");
delay(1000);
}
 
/* delete a task when finish,
this will never happen because this is infinity loop */
vTaskDelete( NULL );
}
 
void setup()
{
Serial.begin(112500);
/* we create a new task here */
xTaskCreate(
anotherTask, /* Task function. */
"another Task", /* name of task. */
10000, /* Stack size of task */
NULL, /* parameter of the task */
1, /* priority of the task */
NULL); /* Task handle to keep track of created task */
}
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
Serial.println("this is ESP32 Task");
delay(1000);
}
```

## Funcionamiento

## Codigo_4.2
```cpp
#include <Arduino.h>
 
// This TaskHandle will allow
TaskHandle_t task1Handle = NULL;
 
const int led1 = 17; // Pin of the LED
const int led2 = 21; // Pin of the LED
 
 
 
void toggleLED(void * parameter){
for(;;){
 
vTaskDelay(500 / portTICK_PERIOD_MS);
// Turn the LED on
digitalWrite(led1, HIGH);
// Pause the task for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
// Turn the LED off
digitalWrite(led1, LOW);
 
// Kill task1 if it's running
   if(task1Handle != NULL) {
   vTaskDelete(task1Handle);
   }
 
}
// vTaskDelete( NULL );
 
 
}
 
void toggleLED2(void * parameter){
for(;;){ // infinite loop
// Turn the LED on
digitalWrite(led2, HIGH);
// Pause the task for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
// Turn the LED off
digitalWrite(led2, LOW);
// Pause the task again for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
}
vTaskDelete( NULL );
}
 
 
 
void setup()
{
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
Serial.begin(112500);
 
/* we create a new task here */
xTaskCreate(
toggleLED, /* Task function. */
"toggleLED", /* name of task. */
10000, /* Stack size of task */
NULL, /* parameter of the task */
1, /* priority of the task */
NULL); /* Task handle to keep track of created task */
 
xTaskCreate(
toggleLED2, /* Task function. */
"toggleLED2", /* name of task. */
10000, /* Stack size of task */
NULL, /* parameter of the task */
1, /* priority of the task */
NULL);
 
}
 
 
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
}
```
## Funcionamiento

## Codigo_4.extra
```cpp
#include <Arduino.h>
 
 
const int led1 = 19;
const int led2 = 18;
const int led3 = 5;
 
 
void ToggleLED_green( void * parameter )
{
  /* loop forever */
  for(;;){
 
 
 
  // Turn the LED on
  digitalWrite(led1, HIGH);
  Serial.print("Led Green ON\n");
  // Pause the task for 5000ms
  vTaskDelay(3000 / portTICK_PERIOD_MS);
  Serial.print("Pause the task for 3000ms\n");
  // Turn the LED off
  digitalWrite(led1, LOW);
  Serial.print("Led Green OFF\n");
  // Pause the task for 5000ms
  vTaskDelay(6000 / portTICK_PERIOD_MS);
  Serial.print("Pause the task for 6000ms\n");
 
 
  }
}
 
void ToggleLED_yellow( void * parameter )
{
  /* loop forever */
  for(;;){
 
  vTaskDelay(3000 / portTICK_PERIOD_MS);
  
  // Turn the LED on
  digitalWrite(led2, HIGH);
  Serial.print("Yellow intermitent:\n");
 for(int i=0;i!=10;i++)
      { 
        vTaskDelay(150 / portTICK_PERIOD_MS);
        digitalWrite(led2, LOW);
        Serial.print("Yellow on--");
        vTaskDelay(150 / portTICK_PERIOD_MS);
        digitalWrite(led2, HIGH);
        Serial.print("Yellow off--");
      }
 
  // Turn the LED off
  digitalWrite(led2, LOW);
 
  // Pause the task for 5000ms
  vTaskDelay(3000 / portTICK_PERIOD_MS);
   
 
 
  }
}
 
void ToggleLED_red( void * parameter )
{
  /* loop forever */
  for(;;){
 
  vTaskDelay(6000 / portTICK_PERIOD_MS);
  Serial.print("Pause the task for 6000ms\n");
  // Turn the LED on
  digitalWrite(led3, HIGH);
  Serial.print("Led RED ON\n");
  // Pause the task for 5000ms
  vTaskDelay(3000 / portTICK_PERIOD_MS);
  Serial.print("Pause the task for 3000ms\n");
  // Turn the LED off
  digitalWrite(led3, LOW);
 Serial.print("Led RED OFF\n");
 
  }
}
 
 
 
void setup()
{
  Serial.begin(112500);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
 
  /* we create a new task here */
  xTaskCreate(
    ToggleLED_green, /* Task function. */
    "Green", /* name of task. */
    1000, /* Stack size of task */
    NULL, /* parameter of the task */
    1, /* priority of the task */
   NULL); /* Task handle to keep track of created task */
 
  xTaskCreate(
    ToggleLED_yellow, /* Task function. */
    "Yellow", /* name of task. */
    1000, /* Stack size of task */
    NULL, /* parameter of the task */
    1, /* priority of the task */
   NULL); /* Task handle to keep track of created task */
 
    xTaskCreate(
    ToggleLED_red, /* Task function. */
    "Red", /* name of task. */
    1000, /* Stack size of task */
    NULL, /* parameter of the task */
    1, /* priority of the task */
   NULL); /* Task handle to keep track of created task */
 
 
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
 
}
```
## Funcionamiento
