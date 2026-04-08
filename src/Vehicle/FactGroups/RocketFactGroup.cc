#include "RocketFactGroup.h"
#include "QGCApplication.h"
#include "FactMetaData.h"
#include <cstring>

static const char* kRocketFactJson =
    "qrc:/json/Vehicle/RocketFact.json";


void RocketFactGroup::handleMessage(Vehicle* vehicle, const mavlink_message_t& message)
{
    Q_UNUSED(vehicle);

    switch (message.msgid) {

    case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT:
    {
        mavlink_named_value_float_t namedValue;
        mavlink_msg_named_value_float_decode(&message, &namedValue);

        // MAVLink named_value name field is at most 10 characters and might not be null-terminated
        QString name = QString::fromLatin1(namedValue.name, strnlen(namedValue.name, 10));

        if (name == "CHAMBER_PR")
            _chamberPressure.setRawValue(namedValue.value);
        else if (name == "BURN_TIME")
            _burnTime.setRawValue(namedValue.value);
        else if (name == "THROTTLE")
            _throttle.setRawValue(namedValue.value);
        else if (name == "MASS_FLOW")
            _massFlowRate.setRawValue(namedValue.value);
        else if (name == "ENGINE_POS")
            _enginePosition.setRawValue(namedValue.value);
        else if (name == "POSITION")
            _position.setRawValue(namedValue.value);
        else if (name == "ALTITUDE")
            _altitude.setRawValue(namedValue.value);
        else if (name == "LIN_ACCEL")
            _linearAcceleration.setRawValue(namedValue.value);
        else if (name == "ANG_VEL")
            _angularVelocity.setRawValue(namedValue.value);
        else if (name == "TIME_BURN2")
            _timeOfSecondBurn.setRawValue(namedValue.value);
        else if (name == "H_BURN2")
            _heightOfSecondBurn.setRawValue(namedValue.value);
        else if (name == "H0")
            _h0.setRawValue(namedValue.value);
        else if (name == "H1")
            _h1.setRawValue(namedValue.value);
        else if (name == "AMBIENT_PR")
            _ambientPressure.setRawValue(namedValue.value);

        break;
    }

    case MAVLINK_MSG_ID_NAMED_VALUE_INT:
    {
        mavlink_named_value_int_t namedValue;
        mavlink_msg_named_value_int_decode(&message, &namedValue);

        QString name = QString::fromLatin1(namedValue.name, strnlen(namedValue.name, 10));

        if (name == "SERVO_STAT")
            _servoState.setRawValue(namedValue.value);

        break;
    }

    default:
        break;
    }
}    

RocketFactGroup::RocketFactGroup(QObject* parent)
    : FactGroup(100, ":/json/Vehicle/RocketFact.json", parent)

    // Engine / HALO
    , _chamberPressure     (0, "chamberPressure",     FactMetaData::valueTypeDouble)
    , _burnTime            (0, "burnTime",            FactMetaData::valueTypeDouble)
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
    , _timeOfSecondBurn     (0, "timeOfSecondBurn",     FactMetaData::valueTypeDouble)
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
