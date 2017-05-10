/*
** Example Arduino sketch for SainSmart I2C LCD Screen 16x2
** based on https://bitbucket.org/celem/sainsmart-i2c-lcd/src/3adf8e0d2443/sainlcdtest.ino
** by
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)

** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal 

** Modified - Ian Brennan ianbren at hotmail.com 23-10-2012 to support Tutorial posted to Arduino.cc

** Written for and tested with Arduino 1.0
**
** NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL
 
** Some changes done 10.5.2017 - Kirsi Oikarinen and Maija Prove

*/

#include <NewPing.h>
#define maximum 200
#define trig 3
#define echo 2

int usec;
int cm;
float inch;
NewPing sonar(trig, echo, maximum);
int voltagepin = 9;


#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
lcd.begin (16,2); // LCD is 16x2
Serial.begin(9600);
pinMode(voltagepin, OUTPUT);
digitalWrite(voltagepin, HIGH);
 
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); 

}

void loop()
{
 lcd.setCursor(2,0);
 lcd.print("Range Finder");
 usec=sonar.ping();
 cm=usec/58;
 inch=usec/148;
 lcd.setCursor(0,1);
 lcd.print(cm);
 lcd.print(" cm");
 lcd.setCursor(7,1);
 lcd.print(inch);
 lcd.print(" inch");
 delay(50);
}
