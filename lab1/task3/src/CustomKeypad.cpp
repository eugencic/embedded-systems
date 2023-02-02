#include "CustomKeypad.h"

CustomKeypad::CustomKeypad() {}

Keypad CustomKeypad::customKey()
{
    Keypad customPad = Keypad(makeKeymap(hexKeys), rowPins, colPins, rows, cols);
    return customPad;
}