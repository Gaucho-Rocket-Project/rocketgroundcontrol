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

    static FlightModeList availableFlightModes = {
        // Mode Name             , Custom Mode                CanBeSet  adv
        { _idleFlightMode        , APMRocketMode::IDLE,          true , true },
        { _armedFlightMode       , APMRocketMode::ARMED,         true , true },
        { _boostFlightMode       , APMRocketMode::BOOST,         true , true },
        { _coastFlightMode       , APMRocketMode::COAST,         true , true },
        { _drogueFlightMode      , APMRocketMode::DROGUE,        true , true },
        { _mainFlightMode        , APMRocketMode::MAIN,          true , true },
        { _landedFlightMode      , APMRocketMode::LANDED,        true , true },
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



void ArduRocketFirmwarePlugin::updateAvailableFlightModes(FlightModeList &modeList)
{
    for (FirmwareFlightMode &mode: modeList) {
        mode.fixedWing = false;
        mode.multiRotor = false;
    }

    _updateFlightModeList(modeList);
}

uint32_t ArduRocketFirmwarePlugin::_convertToCustomFlightModeEnum(uint32_t val) const
{
    Q_UNUSED(val);
    return UINT32_MAX;
}
