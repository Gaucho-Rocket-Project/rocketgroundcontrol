/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "ArduRocketFirmwarePlugin.h"
#include "ParameterManager.h"
#include "Vehicle.h"

bool ArduRocketFirmwarePlugin::_remapParamNameIntialized = false;
FirmwarePlugin::remapParamNameMajorVersionMap_t ArduRocketFirmwarePlugin::_remapParamName;

ArduRocketFirmwarePlugin::ArduRocketFirmwarePlugin(QObject *parent)
    : APMFirmwarePlugin(parent)
{
    _setModeEnumToModeStringMapping({
        { APMRocketMode::STABILIZE,    _stabilizeFlightMode     },
        { APMRocketMode::ACRO,         _acroFlightMode          },
        { APMRocketMode::ALT_HOLD,     _altHoldFlightMode       },
        { APMRocketMode::AUTO,         _autoFlightMode          },
        { APMRocketMode::GUIDED,       _guidedFlightMode        },
        { APMRocketMode::LOITER,       _loiterFlightMode        },
        { APMRocketMode::RTL,          _rtlFlightMode           },
        { APMRocketMode::CIRCLE,       _circleFlightMode        },
        { APMRocketMode::LAND,         _landFlightMode          },
        { APMRocketMode::DRIFT,        _driftFlightMode         },
        { APMRocketMode::SPORT,        _sportFlightMode         },
        { APMRocketMode::FLIP,         _flipFlightMode          },
        { APMRocketMode::AUTOTUNE,     _autotuneFlightMode      },
        { APMRocketMode::POS_HOLD,     _posHoldFlightMode       },
        { APMRocketMode::BRAKE,        _brakeFlightMode         },
        { APMRocketMode::THROW,        _throwFlightMode         },
        { APMRocketMode::AVOID_ADSB,   _avoidADSBFlightMode     },
        { APMRocketMode::GUIDED_NOGPS, _guidedNoGPSFlightMode   },
        { APMRocketMode::SMART_RTL,    _smartRtlFlightMode      },
        { APMRocketMode::FLOWHOLD,     _flowHoldFlightMode      },
        { APMRocketMode::FOLLOW,       _followFlightMode        },
        { APMRocketMode::ZIGZAG,       _zigzagFlightMode        },
        { APMRocketMode::SYSTEMID,     _systemIDFlightMode      },
        { APMRocketMode::AUTOROTATE,   _autoRotateFlightMode    },
        { APMRocketMode::AUTO_RTL,     _autoRTLFlightMode       },
        { APMRocketMode::TURTLE,       _turtleFlightMode        },
    });

    static FlightModeList availableFlightModes = {
        // Mode Name             , Custom Mode                CanBeSet  adv
        { _stabilizeFlightMode   , APMRocketMode::STABILIZE,     true , true },
        { _acroFlightMode        , APMRocketMode::ACRO,          true , true },
        { _altHoldFlightMode     , APMRocketMode::ALT_HOLD,      true , true },
        { _autoFlightMode        , APMRocketMode::AUTO,          true , true },
        { _guidedFlightMode      , APMRocketMode::GUIDED,        true , true },
        { _loiterFlightMode      , APMRocketMode::LOITER,        true , true },
        { _rtlFlightMode         , APMRocketMode::RTL,           true , true },
        { _circleFlightMode      , APMRocketMode::CIRCLE,        true , true },
        { _landFlightMode        , APMRocketMode::LAND,          true , true },
        { _driftFlightMode       , APMRocketMode::DRIFT,         true , true },
        { _sportFlightMode       , APMRocketMode::SPORT,         true , true },
        { _flipFlightMode        , APMRocketMode::FLIP,          true , true },
        { _autotuneFlightMode    , APMRocketMode::AUTOTUNE,      true , true },
        { _posHoldFlightMode     , APMRocketMode::POS_HOLD,      true , true },
        { _brakeFlightMode       , APMRocketMode::BRAKE,         true , true },
        { _throwFlightMode       , APMRocketMode::THROW,         true , true },
        { _avoidADSBFlightMode   , APMRocketMode::AVOID_ADSB,    true , true },
        { _guidedNoGPSFlightMode , APMRocketMode::GUIDED_NOGPS,  true , true },
        { _smartRtlFlightMode    , APMRocketMode::SMART_RTL,     true , true },
        { _flowHoldFlightMode    , APMRocketMode::FLOWHOLD,      true , true },
        { _followFlightMode      , APMRocketMode::FOLLOW,        true , true },
        { _zigzagFlightMode      , APMRocketMode::ZIGZAG,        true , true },
        { _systemIDFlightMode    , APMRocketMode::SYSTEMID,      true , true },
        { _autoRotateFlightMode  , APMRocketMode::AUTOROTATE,    true , true },
        { _autoRTLFlightMode     , APMRocketMode::AUTO_RTL,      true , true },
        { _turtleFlightMode      , APMRocketMode::TURTLE,        true , true },
    };
    updateAvailableFlightModes(availableFlightModes);

    if (!_remapParamNameIntialized) {
        FirmwarePlugin::remapParamNameMap_t &remapV4_0 = _remapParamName[4][0];

        remapV4_0["TUNE_MIN"] = QStringLiteral("TUNE_LOW");
        remapV4_0["TUNE_MAX"] = QStringLiteral("TUNE_HIGH");

        _remapParamNameIntialized = true;
    }
}

ArduRocketFirmwarePlugin::~ArduRocketFirmwarePlugin()
{

}

int ArduRocketFirmwarePlugin::remapParamNameHigestMinorVersionNumber(int majorVersionNumber) const
{
    return ((majorVersionNumber == 4) ? 0 : Vehicle::versionNotSetValue);
}

bool ArduRocketFirmwarePlugin::multiRotorXConfig(Vehicle *vehicle) const
{
    return (vehicle->parameterManager()->getParameter(ParameterManager::defaultComponentId, "FRAME")->rawValue().toInt() != 0);
}

QString ArduRocketFirmwarePlugin::pauseFlightMode() const
{
    return _modeEnumToString.value(APMRocketMode::BRAKE, _brakeFlightMode);
}

QString ArduRocketFirmwarePlugin::landFlightMode() const
{
    return _modeEnumToString.value(APMRocketMode::LAND, _landFlightMode);
}

QString ArduRocketFirmwarePlugin::takeControlFlightMode() const
{
    return _modeEnumToString.value(APMRocketMode::LOITER, _loiterFlightMode);
}

QString ArduRocketFirmwarePlugin::followFlightMode() const
{
    return _modeEnumToString.value(APMRocketMode::FOLLOW, _followFlightMode);
}

QString ArduRocketFirmwarePlugin::stabilizedFlightMode() const
{
    return _modeEnumToString.value(APMRocketMode::STABILIZE, _stabilizeFlightMode);
}

void ArduRocketFirmwarePlugin::updateAvailableFlightModes(FlightModeList &modeList)
{
    for (FirmwareFlightMode &mode: modeList) {
        mode.fixedWing = false;
        mode.multiRotor = true;
    }

    _updateFlightModeList(modeList);

}

uint32_t ArduRocketFirmwarePlugin::_convertToCustomFlightModeEnum(uint32_t val) const
{
    switch (val) {
    case APMCustomMode::AUTO:
        return APMRocketMode::AUTO;
    case APMCustomMode::GUIDED:
        return APMRocketMode::GUIDED;
    case APMCustomMode::RTL:
        return APMRocketMode::RTL;
    case APMCustomMode::SMART_RTL:
        return APMRocketMode::SMART_RTL;
    default:
        return UINT32_MAX;
    }
}
