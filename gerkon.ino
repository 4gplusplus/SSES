#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 9
#define DIO 8

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000


TM1637Display display(CLK, DIO);
int Led_1_flor = 13; //  контакт для led 1 поверх
int Led_2_flor = 12; //  контакт для led 2 поверх
int Led_3_flor = 11; //  контакт для led 3 поверх
int Led_4_flor = 10; //  контакт для led 4 поверх
int Gerkon_1_flor = 2; // контакт для геркона 1 поверх
int Gerkon_2_flor = 3; // контакт для геркона 2 поверх
int Gerkon_3_flor = 4; // контакт для геркона 3 поверх
int Gerkon_4_flor = 5; // контакт для геркона 4 поверх
int val_1_flor = 0; // змніна для  стану геркона 1 поверх
int val_2_flor = 0; // змніна для  стану геркона 2 поверх
int val_3_flor = 0; // змніна для  стану геркона 3 поверх
int val_4_flor = 0; // змніна для  стану геркона 4 поверх

void setup() {
pinMode(Led_1_flor, OUTPUT); // установить Door_Led_Pin как выход
pinMode(Gerkon_1_flor, INPUT); // установить Door_Sensor_Pin как вход
  
}


   
void loop(){
   display.setBrightness(0x0f);

  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
val_1_flor = digitalRead(Gerkon_1_flor); // зчитутвати Gerkon_1_flor
val_2_flor = digitalRead(Gerkon_2_flor); // зчитутвати Gerkon_2_flor
val_3_flor = digitalRead(Gerkon_3_flor); // зчитутвати Gerkon_3_flor
val_4_flor = digitalRead(Gerkon_4_flor); // зчитутвати Gerkon_4_flor

if (val_1_flor == HIGH) { // якщо ліфт на поверсі то включити лед 
digitalWrite(Led_1_flor, HIGH); //включити led 

display.showNumberDec(1, false, 3, 1);// вивід на екран номер поверха 


} else {
digitalWrite(Led_1_flor, LOW); //виключити led 
}
if (val_2_flor == HIGH) { // якщо ліфт на поверсі то включити лед 
digitalWrite(Led_2_flor, HIGH); //включити led 
display.showNumberDec(2, false, 3, 1);// вивід на екран номер поверха 
}else {
digitalWrite(Led_2_flor, LOW); //виключити led 
}
if (val_3_flor == HIGH) { // якщо ліфт на поверсі то включити лед 
digitalWrite(Led_3_flor, HIGH); //включити  led
display.showNumberDec(3, false, 3, 1);// вивід на екран номер поверха 
}else {
digitalWrite(Led_3_flor, LOW); //виключити  led
}
if (val_4_flor == HIGH) { // якщо ліфт на поверсі то включити лед 
digitalWrite(Led_4_flor, HIGH); //включити  led
display.showNumberDec(4, false, 3, 1);// вивід на екран номер поверха 
}else {
digitalWrite(Led_4_flor, LOW); //виключити  led
}
}
