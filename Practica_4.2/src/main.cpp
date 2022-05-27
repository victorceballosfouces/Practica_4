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
 
 
 
