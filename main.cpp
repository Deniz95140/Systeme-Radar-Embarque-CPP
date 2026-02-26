#include <LiquidCrystal.h>

// Initialisation de l'afficheur (Pins: RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 2, 8);

// Classe pour la gestion du capteur ultrason
class UltrasonicSensor {
private:
    int _trig;
    int _echo;

public:
    UltrasonicSensor(int t, int e) : _trig(t), _echo(e) {
        pinMode(_trig, OUTPUT);
        pinMode(_echo, INPUT);
    }

    int getDistance() {
        digitalWrite(_trig, LOW);
        delayMicroseconds(2);
        digitalWrite(_trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(_trig, LOW);
        long duration = pulseIn(_echo, HIGH);
        return duration * 0.034 / 2;
    }
};

// Configuration des Pins
UltrasonicSensor radar(9, 10);
const int PIN_BUZ   = 3;
const int LED_GREEN = 7;
const int LED_YEL   = 6;
const int LED_RED   = 13;

void setup() {
    lcd.begin(16, 2);
    pinMode(PIN_BUZ, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YEL, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    
    lcd.print("SYSTEM BOOTING");
    delay(1000);
}

void loop() {
    int dist = radar.getDistance();

    // Reset des sorties (On éteint tout avant de tester)
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YEL, LOW);
    digitalWrite(LED_RED, LOW);
    noTone(PIN_BUZ);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RANGE: ");
    lcd.print(dist);
    lcd.print(" CM");

    lcd.setCursor(0, 1);

    // --- LOGIQUE DE SECURITE ---
    if (dist > 50) {
        // ZONE SECURE
        lcd.print("STATUS: SECURE");
        digitalWrite(LED_GREEN, HIGH);
    } 
    else if (dist <= 50 && dist >= 20) {
        // ZONE WARNING
        lcd.print("STATUS: WARNING");
        digitalWrite(LED_YEL, HIGH);
        tone(PIN_BUZ, 500, 50); // Bip intermittent
    } 
    else {
        // ZONE CRITICAL
        lcd.print("STATUS: DANGER");
        digitalWrite(LED_RED, HIGH);
        tone(PIN_BUZ, 1200); // Bip continu
    }

    delay(250);
}