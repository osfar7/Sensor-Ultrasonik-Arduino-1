#include <Arduino.h>

#include <Arduino.h>

const int echoPin = 2;
const int trigPin = 3;

const int ledMerahPin = 6;
const int ledHijauPin = 7;

void setup() {

    Serial.begin(9600);

    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(ledHijauPin, OUTPUT);
    pinMode(ledMerahPin, OUTPUT);

}

// Membuat fungsi ultrasonik untuk mendapatkan jarak dari sensor ultrasonik
float ultrasonik() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int durasiPantulan = pulseIn(echoPin, HIGH);

    // Menghitung jarak berdasarkan waktu pantulan
    return durasiPantulan * 0.034 / 2;

}

void loop() {

    float jarak = ultrasonik();

    if (jarak >= 10) {

        digitalWrite(ledHijauPin, HIGH);
        digitalWrite(ledMerahPin, LOW);

        Serial.println("Tidak ada objek");

    } else {

        digitalWrite(ledHijauPin, LOW);
        digitalWrite(ledMerahPin, HIGH);

        Serial.println("Ada objek");
        
    }

    delay(1000);

}