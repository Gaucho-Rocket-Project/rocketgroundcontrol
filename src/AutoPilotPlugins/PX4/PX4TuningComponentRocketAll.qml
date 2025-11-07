/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QGroundControl
import QGroundControl.Controls
import QGroundControl.ScreenTools

PX4TuningComponent {
    model: ListModel {
        ListElement { 
            buttonText: qsTr("Rate Controller")
            tuningPage: "PX4TuningComponentRocketRate.qml"
        }
        ListElement { 
            buttonText: qsTr("Attitude Controller")
            tuningPage: "PX4TuningComponentRocketAttitude.qml"
        }
        ListElement { 
            buttonText: qsTr("Velocity Controller")
            tuningPage: "PX4TuningComponentRocketVelocity.qml"
        }
        ListElement { 
            buttonText: qsTr("Position Controller")
            tuningPage: "PX4TuningComponentRocketPosition.qml"
        }
    }
}
