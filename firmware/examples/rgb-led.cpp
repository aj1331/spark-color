// This #include statement was automatically added by the Spark IDE.
#include "color/color.h"

int LED_R = A1;
int LED_G = A0;
int LED_B = D0;

Color::Hsv hsv;
Color::Rgb rgb;

void setup() 
{
	// Configure outputs for LED
	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_B, OUTPUT);
	
	// Initialize HSV
	hsv.h = 0;
	hsv.s = 255;
	hsv.v = 255;
}


void loop() 
{
    // Convert HSV to RGB
    hsv.toRgb(rgb);
    
	// Set LED color
	analogWrite(LED_R, 255 - rgb.r);
	analogWrite(LED_G, 255 - rgb.g);
	analogWrite(LED_B, 255 - rgb.b);
	
	// Cycle hue
	hsv.h += 1;
	
	delay(10);
}
