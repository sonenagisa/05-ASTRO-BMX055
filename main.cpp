#include "mbed.h"
#include "BMX055.h"

DigitalOut myled(LED1);
BMX055 bmx(PB_7,PB_6);//SDA,SCL
Serial pc(USBTX, USBRX);

int main() {
    while(1) {
        bmx.getAcc();
        pc.printf("%2.4lf, %2.4lf, %2.4lf, ",(bmx.accel[0]/512)*9.8,(bmx.accel[1]/512)*9.8,(bmx.accel[2]/512)*9.8);
        bmx.getGyro();
        pc.printf("%2.4lf, %2.4lf, %2.4lf, ",(bmx.gyroscope[0]*125)/2048,(bmx.gyroscope[1]*125)/2048,(bmx.gyroscope[2]*125)/2048);       
        bmx.getMag();
        pc.printf("%2.4lf, %2.4lf, %2.4lf\r\n",bmx.magnet[0],bmx.magnet[1],bmx.magnet[2]);
        wait(0);
    }
}
