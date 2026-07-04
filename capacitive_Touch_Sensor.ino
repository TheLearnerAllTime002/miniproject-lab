#include <CapacitiveSensor.h>

CapacitiveSensor sensor1 = CapacitiveSensor(4, 2);
CapacitiveSensor sensor2 = CapacitiveSensor(4, 6);

const int led1 = 8;
const int led2 = 9;

long threshold = 1000;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

    sensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);
    sensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);

    Serial.begin(9600);
}

void loop()
{
    long value1 = sensor1.capacitiveSensor(30);
    long value2 = sensor2.capacitiveSensor(30);

    Serial.print("Sensor1 : ");
    Serial.print(value1);

    Serial.print("   Sensor2 : ");
    Serial.println(value2);

    if (value1 > threshold)
        digitalWrite(led1, HIGH);
    else
        digitalWrite(led1, LOW);

    if (value2 > threshold)
        digitalWrite(led2, HIGH);
    else
        digitalWrite(led2, LOW);

    delay(50);
}