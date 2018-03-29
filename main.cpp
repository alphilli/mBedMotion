#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx
DigitalOut myled(LED1);
AnalogIn   ain(A0);
float last_ain;
int led_count = 0;

int main() {
    //start with a default value...
    last_ain = ain.read();
    
    while(1) {
        if(abs(ain.read() - last_ain) > 0.1)
        {
            last_ain = ain.read();
            myled = 1;
            led_count = 10;
        }
        else
        {
            if(led_count > 0)
            {
                led_count--;
            }
            else
            {
                myled = 0;
            }
        }
        
        pc.printf("Sensor Value: %3.3f%%\r\n", ain.read());
        wait(0.05); //short delay for responsiveness
    }
}
