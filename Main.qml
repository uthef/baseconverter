import QtQuick

import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ApplicationWindow {
    Material.theme: Material.Light
    Material.accent: Material.BlueGrey

    width: 640
    minimumWidth: 500
    minimumHeight: 250
    height: 480
    visible: true
    title: qsTr("Base converter")

    ListModel {
        id: baseList

        ListElement {
            name: "Hexadecimal"
            base: 16
        }
        ListElement {
            name: "Decimal"
            base: 10
        }
        ListElement {
            name: "Octal"
            base: 8
        }
        ListElement {
            name: "Binary"
            base: 2
        }
    }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            id: label
            font.pixelSize: 16
            text: "Base"
        }

        RowLayout {
            Layout.preferredWidth: 400

            ComboBox {
                id: combo
                Layout.preferredWidth: 150
                font.pixelSize: 16
                onCurrentValueChanged: window.onComboIndexChanged(currentValue)
                model: baseList
                textRole: "name"
                valueRole: "base"
            }

            TextField {
                id: field
                Layout.fillWidth: true
                font.pixelSize: 16
                width: 200
                text: window.fieldText
                onTextChanged: window.onFieldInput(text)
            }
        }

        RowLayout {
            Layout.preferredWidth: parent.width

            Label {
                font.pixelSize: 14
                text: "HEX"
            }

            Label {
                font.pixelSize: 14
                Layout.alignment: Qt.AlignRight
                text: window.hexStr
            }
        }


        RowLayout {
            Layout.preferredWidth: parent.width

            Label {
                font.pixelSize: 14
                text: "DEC"
            }

            Label {
                font.pixelSize: 14
                Layout.alignment: Qt.AlignRight
                text: window.decStr
            }
        }

        RowLayout {
            Layout.preferredWidth: parent.width

            Label {
                font.pixelSize: 14
                text: "OCT"
            }

            Label {
                font.pixelSize: 14
                Layout.alignment: Qt.AlignRight
                text: window.octStr
            }
        }

        RowLayout {
            Layout.preferredWidth: parent.width

            Label {
                font.pixelSize: 14
                text: "BIN"
            }

            Label {
                font.pixelSize: 14
                Layout.alignment: Qt.AlignRight
                text: window.binStr
            }
        }
    }
}
