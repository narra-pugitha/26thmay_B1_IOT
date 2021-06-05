#include<Keypad.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
char keys[4][4] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'},
};
byte rows[4] = {13, 12, 11, 10};
byte cols[4] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rows, cols, 4, 4);

char signMath[4] = {'+', '-', '*', '/'};
// This function returns true(1) if entered sign is from above operators
int isSign(char sign) {
  for (int i = 0; i < 4; i++) {
    if (sign == signMath[i]) {
      return 1;
    }
  }
  return 0;
}

// calculate the result
float calculate(float val1, float val2, char op) {
  if (op == '+') {
    return (val1 + val2);
  } else if (op == '-') {
    return (val1 - val2);
  } else if (op == '*') {
    return (val1 * val2);
  } else {
    return (val1 / val2);
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

float num1 = 0;
float num2 = 0;
bool operation = false; // use to seperate number1 and number2
char sign = '\0'; // Null char to store operating sign

void loop() {
  char k = keypad.getKey();
  if (k) {
    if (k == 'C') {   // Clear all parameters
      num1 = 0;
      num2 = 0;
      sign = '\0';
      operation = false;
      lcd.clear();
      lcd.setCursor(0, 0);
    } else if (k >= 48 && k <= 57) { // ascii value of 0-9 (48-57)
      if (operation) {  // operation == true
        num2 = 10 * num2 + (long)(k - 48); // extract the number from ascii and store it in variable
      } else {
        num1 = 10 * num1 + (long)(k - 48);
      }
      lcd.print(k);
    } else if (k == '=') {
      lcd.setCursor(0, 1);
      lcd.print('=');
      lcd.print(calculate(num1, num2, sign));
    }
    if (isSign(k)) {
      sign = k;
      operation = true;
      lcd.print(sign);
    }
  }
}
