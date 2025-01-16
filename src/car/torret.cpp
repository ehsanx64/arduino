#include <Arduino.h>
#include <Stepper.h>
#include <Servo.h>
#include <Wire.h>
#include "../../config.h"
#include "torret.h"

#ifdef TORRET_ENABLED
// Constants
#define STEP_VAL 1
#define X_PIN A7                // X-axis pin
#define X_VAL 1
#define X_MAX 200
#define X_MIN -200

#define Y_PIN A6                // Y-axis 
#define Y_VAL 2
#define Y_MAX 140
#define Y_MIN 0

#define VERBOSE false 


// Variables
const float stepsPerRevolution = 360;               // How many steps for a complete revolution
Servo servo;                                        // servo control y-axis
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);  // stepper control x-axis rotation
int pos = 0;                    // y-axis position
int xpos = 0;                   // x-axis position
int x_value = 0;
int y_value = 0;


// Functions
/*
** Given a joystick value it returns the increment factor for
*/
int get_speed(int value, int axis) {
    switch (value) {
    case 820 ... 1024:
        if (axis == Y_VAL) return -3;
        else return 3;
        break;

    case 720 ... 819:
        if (axis == Y_VAL) return -2;
        else return 2;
        break;

    case 520 ... 719:
        if (axis == Y_VAL) return -1;
        else return 1;
        break;

    case 280 ... 480:
        if (axis == Y_VAL) return 1;
        else return -1;
        break;

    case 100 ... 279:
        if (axis == Y_VAL) return 2;
        else return -2;
        break;

    case 0 ... 99:
        if (axis == Y_VAL) return 3;
        else return -3;
        break;

    default:
        return 0;
        break;
    }
}

void Torret_Main_Setup() {
    servo.attach(7);
    servo.write(Y_MAX);
    stepper.setSpeed(360);
    stepper.step(0);
}

void Torret_Main_Loop() {
    // Read jostick's x and y values
    x_value = analogRead(X_PIN);
    y_value = analogRead(Y_PIN);

    // Get increment factor for y-axis
    int spd = get_speed(y_value, Y_VAL);            
    if (spd > 0) {                  
        if (pos + STEP_VAL * spd > Y_MAX) {
            pos = Y_MAX;
        } else {
            pos += STEP_VAL * spd;
        }
    }

    if (spd < 0) {
        if (pos + STEP_VAL * spd < Y_MIN) {
            pos = Y_MIN;
        } else {
            pos += STEP_VAL * spd;
        }
    }

    if (x_value < 470) {
        stepper.step(1);
        if (VERBOSE) Serial.println("CW");
    }

    if (x_value > 520) {
        stepper.step(-1);
        if (VERBOSE) Serial.println("CCW");
    }

    if (VERBOSE) {
        Serial.print("X: ");
        Serial.println(x_value);
        Serial.print("Y: ");
        Serial.println(y_value);
        Serial.print("Y SPD: ");
        Serial.println(spd);
        Serial.print("Y POS: ");
        Serial.println(pos);
    }

    servo.write(pos);
    delay(25);
}
#endif // TORRET_ENABLED

void Torret_Setup() {
    Serial.println("Torret_Setup()");

#ifdef TORRET_ENABLED
    Torret_Main_Setup();
#endif
}

void Torret_Loop() {
#ifdef TORRET_ENABLED
    Torret_Main_Loop();
#endif
}

