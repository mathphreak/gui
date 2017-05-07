import QtQuick 2.7

Page1Form {
    button.onClicked: {
        console.log("Button Pressed. Entered text: " + textField.text);
    }

    comboBox.onCurrentTextChanged: {
        console.log("Combo Box Changed. Selected item: " + comboBox.currentText);
    }

    checkBox.onCheckedChanged: {
        console.log("Check box " + (checkBox.checked ? "" : "un") + "checked");
    }

    radioOne.onCheckedChanged: {
        if (radioOne.checked) {
            console.log("Radio One checked");
        }
    }

    radioTwo.onCheckedChanged: {
        if (radioTwo.checked) {
            console.log("Radio Two checked");
        }
    }

    slider.onValueChanged: {
        console.log("Slider slid to " + slider.value);
    }

    spinBox.onValueChanged: {
        console.log("Spinner spun to " + spinBox.value);
    }
}
