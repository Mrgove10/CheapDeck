#include <Arduino.h>

class button
{
private:
    bool status;
    int clickPin;
    int ledPin;

public:
    /*
    * Constructor
    * @param cp Clickpin, pin that is connected to the switch
    * @param lp Ledpin, pin that is connected to the led
    */
    button(int cp, int lp)
    {
        clickPin = cp;
        ledPin = lp;
        status = false;
        pinMode(clickPin, INPUT_PULLUP);
        pinMode(ledPin, OUTPUT);
    };
    /*
    * Blink the LED
    * @param number of miliseconds led should be on
    */
    void blink(int miliseconds)
    {
        ledOn();
        delay(miliseconds);
        ledOff();
    };
    /*
    * turn the LED On
    */
    void ledOn()
    {
        digitalWrite(ledPin, HIGH);
    };
    /*
    * turn the LED Off
    */
    void ledOff()
    {
        digitalWrite(ledPin, LOW);
    };
    /*
    * Get the whereaver the button is pressed or not
    * 1 = pressed 
    * 0 = not pressed
    */
    int getClickStatus()
    {
        return !digitalRead(clickPin);
    }
    /*
    * Change the status od the key (this makes the key togglable)
    * setting the status to trrue allows to use the routine() funtion
    */
    void changeStatus()
    {
        status = !status;
    }
    /*
    *  routine
    */
    void routine()
    {
        if (status)
        {
            ledOn();
        }
        else{
            ledOff();
        }
    }
};