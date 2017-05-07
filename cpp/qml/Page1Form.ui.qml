import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    property alias textField: textField
    property alias button: button
    property alias comboBox: comboBox
    property alias checkBox: checkBox
    property alias slider: slider
    property alias spinBox: spinBox
    property alias listView: listView
    property alias radioOne: radioOne
    property alias radioTwo: radioTwo

    Label {
        id: textButtonLabel
        text: qsTr("Text & Button")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    RowLayout {
        id: textButton
        y: 57
        width: 624
        height: 40
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.topMargin: 8
        anchors.top: textButtonLabel.bottom

        TextField {
            id: textField
            Layout.fillWidth: true
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button
            text: qsTr("Press Me")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
        }
    }

    Label {
        id: comboBoxLabel
        text: qsTr("Combo Box")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: textButton.bottom
        anchors.topMargin: 8
    }

    ComboBox {
        id: comboBox
        width: 624
        height: 40
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: comboBoxLabel.bottom
        anchors.topMargin: 8
        model: ListModel {
            ListElement {
                text: "A"
            }
            ListElement {
                text: "B"
            }
            ListElement {
                text: "C"
            }
        }
    }

    Label {
        id: widgetsLabel
        text: qsTr("Basic Input Widgets")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: comboBox.bottom
        anchors.topMargin: 8
    }

    RowLayout {
        id: widgets
        width: 624
        height: 40
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: widgetsLabel.bottom
        anchors.topMargin: 8

        CheckBox {
            id: checkBox
            text: qsTr("Check Box")
        }

        RadioButton {
            id: radioOne
            text: qsTr("One")
        }

        RadioButton {
            id: radioTwo
            text: qsTr("Two")
        }

        Slider {
            id: slider
            Layout.fillWidth: true
            value: 0.5
        }

        SpinBox {
            id: spinBox
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
        }
    }

    Label {
        id: listViewLabel
        text: qsTr("Scrollable List")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: widgets.bottom
        anchors.topMargin: 8
    }

    ListView {
        id: listView
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        anchors.top: listViewLabel.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 8
        clip: true
        delegate: Item {
            x: 8
            y: 0
            height: 30
            Text {
                text: model.text
                verticalAlignment: Text.AlignVCenter
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                font.bold: true
            }
        }
        model: ListModel {
            ListElement {
                text: "A"
            }
            ListElement {
                text: "B"
            }
            ListElement {
                text: "C"
            }
            ListElement {
                text: "D"
            }
            ListElement {
                text: "E"
            }
            ListElement {
                text: "F"
            }
            ListElement {
                text: "G"
            }
            ListElement {
                text: "H"
            }
            ListElement {
                text: "I"
            }
            ListElement {
                text: "J"
            }
            ListElement {
                text: "K"
            }
            ListElement {
                text: "L"
            }
        }
        ScrollBar.vertical: ScrollBar { }
    }
}
