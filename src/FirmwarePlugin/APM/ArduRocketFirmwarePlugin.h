/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "APMFirmwarePlugin.h"

struct APMRocketMode
{
    enum Mode : uint32_t{
        STABILIZE   = 0,   // Active stabilization (e.g., thrust vectoring)
        IDLE        = 1,   // Waiting on pad
        ARMED       = 1,   // Ready for launch
        BOOST       = 2,   // Engine firing
        COAST       = 3,   // Engine off, coasting up
        DROGUE      = 4,   // Drogue chute deployed
        MAIN        = 5,   // Main chute deployed
        LANDED      = 6,   // Safely on the ground
        GUIDED      = 7,   // Navigating to coordinates
        AUTO        = 8,   // Executing programmed mission
    };
};

class ArduRocketFirmwarePlugin : public APMFirmwarePlugin
{
    Q_OBJECT

public:
    explicit ArduRocketFirmwarePlugin(QObject *parent = nullptr);
    ~ArduRocketFirmwarePlugin();

    void guidedModeLand(Vehicle *vehicle) const override { _setFlightModeAndValidate(vehicle, landFlightMode()); }
    const FirmwarePlugin::remapParamNameMajorVersionMap_t &paramNameRemapMajorVersionMap() const override { return _remapParamName; }
    int remapParamNameHigestMinorVersionNumber(int majorVersionNumber) const override;
    QString offlineEditingParamFile(Vehicle *vehicle) const override { Q_UNUSED(vehicle); return QStringLiteral(":/FirmwarePlugin/APM/Rocket.OfflineEditing.params"); }
    QString pauseFlightMode() const override;
    QString landFlightMode() const override;
    QString takeControlFlightMode() const override;
    QString followFlightMode() const override { return QString(); }
    QString gotoFlightMode() const override { return guidedFlightMode(); }
    QString takeOffFlightMode() const override { return guidedFlightMode(); }
    QString stabilizedFlightMode() const override { return _stabilizeFlightMode; }
    QString autoDisarmParameter(Vehicle *vehicle) const override { Q_UNUSED(vehicle); return QStringLiteral("DISARM_DELAY"); }
    bool supportsSmartRTL() const override { return false; }

    void updateAvailableFlightModes(FlightModeList &modeList) override;

protected:
    uint32_t _convertToCustomFlightModeEnum(uint32_t val) const override;

private:
    const QString _stabilizeFlightMode = tr("Stabilize");
    const QString _acroFlightMode = tr("Acro");
    const QString _altHoldFlightMode = tr("Altitude Hold");
    const QString _autoFlightMode = tr("Auto");
    const QString _guidedFlightMode = tr("Guided");
    const QString _loiterFlightMode = tr("Loiter");
    const QString _rtlFlightMode = tr("RTL");
    const QString _circleFlightMode = tr("Circle");
    const QString _landFlightMode = tr("Land");

    // Sequence
    const QString _idleFlightMode = tr("Idle");
    const QString _armedFlightMode = tr("Armed");
    const QString _boostFlightMode = tr("Boost");
    const QString _coastFlightMode = tr("Coast");
    const QString _drogueFlightMode = tr("Drogue");
    const QString _mainFlightMode = tr("Main Parachute");
    const QString _landedFlightMode = tr("Landed");

    // Advanced
    const QString _posHoldFlightMode = tr("Position Hold");
    const QString _brakeFlightMode = tr("Brake");
    const QString _avoidADSBFlightMode = tr("Avoid ADSB");
    const QString _smartRtlFlightMode = tr("Smart RTL");
    const QString _systemIDFlightMode = tr("SystemID");
    const QString _autoRTLFlightMode = tr("AutoRTL");

    static bool _remapParamNameIntialized;
    static FirmwarePlugin::remapParamNameMajorVersionMap_t _remapParamName;
};
