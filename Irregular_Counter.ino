int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
int button = 9;

int counter = 0;
int previous = HIGH;

int sequence[] = {1, 4, 7, 2, 9, 5, 0, 8};

byte digits[10][7] =
    {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayDigit(int num)
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segmentPins[i], digits[num][i]);
    }
}

void setup()
{
    for (int i = 0; i < 7; i++)
        pinMode(segmentPins[i], OUTPUT);

    pinMode(button, INPUT_PULLUP);

    displayDigit(sequence[counter]);
}

void loop()
{
    int reading = digitalRead(button);

    if (previous == HIGH && reading == LOW)
    {
        counter++;

        if (counter >= 8)
            counter = 0;

        displayDigit(sequence[counter]);

        delay(250);
    }

    previous = reading;
}