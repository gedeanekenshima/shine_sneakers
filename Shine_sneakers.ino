#include <Adafruit_NeoPixel.h>

const int analogInPin = A9; //pino A9 onde conecta o + do piezo

Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, 6, NEO_GRB + NEO_KHZ800);

// quantidade de leds/pino digital Arduino/configuraçoes 
int sensorValue = 0; // valor lido pelo sensor

void setup() {
// inicia comunicaçao em 9600
Serial.begin(9600);

pinMode(9, INPUT_PULLUP);

strip.begin();

strip.show(); // Initialize all pixels to 'off'

}

void loop() 
{

// read the analog in value:

sensorValue = analogRead(analogInPin);

// print the results to the serial monitor:

Serial.print("sensor = " );                       

Serial.println(sensorValue);     
//se piezo verifica valores menores que 100, acende leds 


if (sensorValue < 100){

    Serial.println("leds triggered"); 

    colorWipe(strip.Color(255, 0, 0), 25);//vermelho        
    colorWipe(strip.Color(0, 0, 0), 25);//apaga leds
    colorWipe(strip.Color(0, 255, 0), 25);//verde       
    colorWipe(strip.Color(0, 0, 0), 25);//apaga leds
    colorWipe(strip.Color(0, 0, 255), 25);//azul        
    colorWipe(strip.Color(0, 0, 0), 25);//apaga leds
}

}

void colorWipe(uint32_t c, uint8_t wait) 
{

for(uint16_t i=0; i<strip.numPixels(); i++) {

strip.setPixelColor(i, c);

strip.show();

delay(wait);
}
}
