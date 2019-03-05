#pragma once
#include <Arduino.h>
class myLib
{
    volatile byte pulseCount;
    static void pulseCounter();
    static myLib * instance0_;
    void handleINT();

  public:
    myLib(const byte bStatusLed, const byte bSensorInterrupt, const byte bSensorPin, const float fCalibrationFactor);
    virtual ~myLib();
    void
        init(),
        count();
    float getWaterFlowRate();
    unsigned long getTotalWaterFlow();

  private:
    const byte
        statusLed,
        sensorInterrupt,
        sensorPin,
        calibrationFactor;
    float flowRate;
    unsigned int
        flowMilliLitres,
        totalMilliLitres,
        oldTime;
};