#include "RocketFactGroup.h"
#include "QGCApplication.h"
#include "FactMetaData.h"

static const char* kRocketFactJson =
    "qrc:/json/Vehicle/RocketFact.json";

RocketFactGroup::RocketFactGroup(QObject* parent)
    : FactGroup(100, ":/json/Vehicle/RocketFact.json", parent)

    // Engine / HALO
    , _chamberPressure     (0, "chamberPressure",     FactMetaData::valueTypeDouble)
    , _burnTime            (0, "burnTime",            FactMetaData::valueTypeElapsedTime)
    , _throttle            (0, "throttle",            FactMetaData::valueTypeDouble)
    , _massFlowRate        (0, "massFlowRate",        FactMetaData::valueTypeDouble)
    , _servoState          (0, "servoState",          FactMetaData::valueTypeInt32)
    , _enginePosition      (0, "enginePosition",      FactMetaData::valueTypeDouble)

    // Kinematics
    , _position             (0, "position",             FactMetaData::valueTypeDouble)
    , _altitude             (0, "altitude",             FactMetaData::valueTypeDouble)
    , _linearAcceleration   (0, "linearAcceleration",   FactMetaData::valueTypeDouble)
    , _angularVelocity      (0, "angularVelocity",      FactMetaData::valueTypeDouble)

    // Flight events
    , _timeOfSecondBurn     (0, "timeOfSecondBurn",     FactMetaData::valueTypeElapsedTime)
    , _heightOfSecondBurn   (0, "heightOfSecondBurn",   FactMetaData::valueTypeDouble)
    , _h0                   (0, "h0",                   FactMetaData::valueTypeDouble)
    , _h1                   (0, "h1",                   FactMetaData::valueTypeDouble)

    // Environment
    , _ambientPressure      (0, "ambientPressure",      FactMetaData::valueTypeDouble)
{
    // Register facts with the group
    _addFact(&_chamberPressure);
    _addFact(&_burnTime);
    _addFact(&_throttle);
    _addFact(&_massFlowRate);
    _addFact(&_servoState);
    _addFact(&_enginePosition);

    _addFact(&_position);
    _addFact(&_altitude);
    _addFact(&_linearAcceleration);
    _addFact(&_angularVelocity);

    _addFact(&_timeOfSecondBurn);
    _addFact(&_heightOfSecondBurn);
    _addFact(&_h0);
    _addFact(&_h1);

    _addFact(&_ambientPressure);
}
