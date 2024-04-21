#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 5
#define GREEN_LED_PIN 3
#define LED_RED_PIN 4
#define BUZZER_PIN 8
#define IR_PIN 2
#define SERVO_PIN A2 

MFRC522 mfrc522(SS_PIN, RST_PIN);

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo lockServo;

void setup() {
    Serial.begin(9600);

    lcd.init();
    lcd.backlight();
    lcd.begin(16,2);

    lockServo.write(0);
    delay(2000);
    lockServo.write(90);
    lockServo.attach(SERVO_PIN);

    lcd.setCursor(5,0);
    lcd.print ("WELCOME");
    lcd.setCursor(3,1);
    lcd.print("ADAMSONIAN");
    delay(2000);
    lcd.clear();

    SPI.begin();
    mfrc522.PCD_Init();

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(IR_PIN, INPUT);
}

void loop() {
    int print;
    int IR_Val = digitalRead(IR_PIN);

    if (IR_Val == LOW) {
        lcd.clear();
        lcd.print("TAP ID");
        delay(1000);

        if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
            Serial.print("Card UID: ");
            String tagID = "";

            for (byte i = 0; i < mfrc522.uid.size; i++) {
                tagID += String(mfrc522.uid.uidByte[1] < 0x10 ? "0" : "");
                tagID += String(mfrc522.uid.uidByte[i], HEX);
                tagID.toUpperCase();
            }
            
            Serial.println(tagID);

            if (tagID == "F38074AD"){
                lcd.clear();
                lcd.print("Access Granted!");

                lockServo.write(90);
                delay(2000);
                lockServo.write(0);

                digitalWrite(GREEN_LED_PIN, HIGH);
                delay(2000);
                digitalWrite(GREEN_LED_PIN, LOW);

                for(print=5; print>=0; print--){
                    lockServo.write(0);
                    lcd.clear();
                    lcd.print(print);
                    delay(1000);
                    lockServo.write(90);
                } 
            }

            else {
                lcd.clear();
                lcd.print("Access Denied!");

                digitalWrite(LED_RED_PIN, HIGH);
                tone(BUZZER_PIN, 1000, 2000);
                delay(2000);
                digitalWrite(LED_RED_PIN, LOW);

                lcd.clear();
            }
        }
    } 

    else {
        lcd.clear();
        lcd.print("GET CLOSER");
    }
}
