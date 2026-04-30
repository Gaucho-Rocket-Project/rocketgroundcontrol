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
        // Custom Rocket Sequence
        IDLE        = 10,  // Waiting on pad
        ARMED       = 11,  // Ready for launch
        BOOST       = 12,  // Engine firing
        COAST       = 13,  // Engine off, coasting up
        DROGUE      = 14,  // Drogue chute deployed
        MAIN        = 15,  // Main chute deployed
        LANDED      = 16,  // Safely on the ground
    };
};

class ArduRocketFirmwarePlugin : public APMFirmwarePlugin
{
    Q_OBJECT

public:
    explicit ArduRocketFirmwarePlugin(QObject *parent = nullptr);
    ~ArduRocketFirmwarePlugin();

    void guidedModeLand(Vehicle *vehicle) const override { Q_UNUSED(vehicle); }
    const FirmwarePlugin::remapParamNameMajorVersionMap_t &paramNameRemapMajorVersionMap() const override { return _remapParamName; }
    int remapParamNameHigestMinorVersionNumber(int majorVersionNumber) const override;
    QString offlineEditingParamFile(Vehicle *vehicle) const override { Q_UNUSED(vehicle); return QStringLiteral(":/FirmwarePlugin/APM/Rocket.OfflineEditing.params"); }
    QString pauseFlightMode() const override { return QString(); }
    QString landFlightMode() const override { return QString(); }
    QString takeControlFlightMode() const override { return QString(); }
    QString followFlightMode() const override { return QString(); }
    QString gotoFlightMode() const override { return QString(); }
    QString takeOffFlightMode() const override { return QString(); }
    QString stabilizedFlightMode() const override { return QString(); }
    QString autoDisarmParameter(Vehicle *vehicle) const override { Q_UNUSED(vehicle); return QStringLiteral("DISARM_DELAY"); }
    bool supportsSmartRTL() const override { return false; }

    void updateAvailableFlightModes(FlightModeList &modeList) override;

protected:
    uint32_t _convertToCustomFlightModeEnum(uint32_t val) const override;

private:
    // Sequence
    const QString _idleFlightMode = tr("Idle");
    const QString _armedFlightMode = tr("Armed");
    const QString _boostFlightMode = tr("Boost");
    const QString _coastFlightMode = tr("Coast");
    const QString _drogueFlightMode = tr("Drogue");
    const QString _mainFlightMode = tr("Main Parachute");
    const QString _landedFlightMode = tr("Landed");

    static bool _remapParamNameIntialized;
    static FirmwarePlugin::remapParamNameMajorVersionMap_t _remapParamName;
};
