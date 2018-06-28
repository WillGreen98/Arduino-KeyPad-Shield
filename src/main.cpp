#include <Arduino.h>
#include <LiquidCrystal.h>

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

int lcd_key = 0;
int adc_key_in = 0;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int read_LCD_buttons() {
    adc_key_in = analogRead(0);

    if(adc_key_in > 1000) { return btnNONE; }
    if(adc_key_in < 50) { return btnRIGHT; }
    if(adc_key_in < 250) { return btnUP; }
    if(adc_key_in < 450) { return btnDOWN; }
    if(adc_key_in < 650) { return btnLEFT; }
    if(adc_key_in < 850) { return btnSELECT; }
}

void setup() {
    lcd.begin(16, 2);
    lcd.print("Push a button");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd_key = read_LCD_buttons();

    switch(lcd_key) {
        case btnRIGHT: {
            lcd.print("Right");
            break;
        }
        case btnLEFT: {
            lcd.print("Left");
            break;
        }
        case btnUP: {
            lcd.print("Up");
            break;
        }
        case btnDOWN: {
            lcd.print("Down");
            break;
        }
        case btnSELECT: {
            lcd.print("Select");
            break;
        }
        case btnNONE: {
            lcd.print("None");
            break;
        }
    }
}