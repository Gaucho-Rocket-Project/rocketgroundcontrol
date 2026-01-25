#pragma once

#include "FactGroup.h"

class RocketFactGroup : public FactGroup
{
    Q_OBJECT

public:
    explicit RocketFactGroup(QObject* parent = nullptr);

    // Engine / HALO
    Q_PROPERTY(Fact* chamberPressure READ chamberPressure CONSTANT)
    Q_PROPERTY(Fact* burnTime READ burnTime CONSTANT)
    Q_PROPERTY(Fact* throttle READ throttle CONSTANT)
    Q_PROPERTY(Fact* massFlowRate READ massFlowRate CONSTANT)
    Q_PROPERTY(Fact* servoState READ servoState CONSTANT)
    Q_PROPERTY(Fact* enginePosition READ enginePosition CONSTANT)

    // Kinematics
    Q_PROPERTY(Fact* position READ position CONSTANT)
    Q_PROPERTY(Fact* altitude READ altitude CONSTANT)
    Q_PROPERTY(Fact* linearAcceleration READ linearAcceleration CONSTANT)
    Q_PROPERTY(Fact* angularVelocity READ angularVelocity CONSTANT)

    // Flight events
    Q_PROPERTY(Fact* timeOfSecondBurn READ timeOfSecondBurn CONSTANT)
    Q_PROPERTY(Fact* heightOfSecondBurn READ heightOfSecondBurn CONSTANT)
    Q_PROPERTY(Fact* h0 READ h0 CONSTANT)
    Q_PROPERTY(Fact* h1 READ h1 CONSTANT)

    // Environment
    Q_PROPERTY(Fact* ambientPressure READ ambientPressure CONSTANT)

    // Getters
    Fact* chamberPressure()      { return &_chamberPressure; }
    Fact* burnTime()             { return &_burnTime; }
    Fact* throttle()             { return &_throttle; }
    Fact* massFlowRate()         { return &_massFlowRate; }
    Fact* servoState()           { return &_servoState; }
    Fact* enginePosition()       { return &_enginePosition; }

    Fact* position()             { return &_position; }
    Fact* altitude()             { return &_altitude; }
    Fact* linearAcceleration()   { return &_linearAcceleration; }
    Fact* angularVelocity()      { return &_angularVelocity; }

    Fact* timeOfSecondBurn()     { return &_timeOfSecondBurn; }
    Fact* heightOfSecondBurn()   { return &_heightOfSecondBurn; }
    Fact* h0()                   { return &_h0; }
    Fact* h1()                   { return &_h1; }

    Fact* ambientPressure()      { return &_ambientPressure; }

private:
    // Engine / HALO
    Fact _chamberPressure;
    Fact _burnTime;
    Fact _throttle;
    Fact _massFlowRate;
    Fact _servoState;
    Fact _enginePosition;

    // Kinematics
    Fact _position;
    Fact _altitude;
    Fact _linearAcceleration;
    Fact _angularVelocity;

    // Flight events
    Fact _timeOfSecondBurn;
    Fact _heightOfSecondBurn;
    Fact _h0;
    Fact _h1;

    // Environment
    Fact _ambientPressure;
};
