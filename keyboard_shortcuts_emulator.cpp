#include <Arduino.h>
#include <BleKeyboard.h>

// Create a BLE keyboard object
BleKeyboard bleKeyboard("EasyAccess Button", "RadiantTech", 100); // custom device name, manufacturer, and battery level (optional)
#define statusLED 2

#define blue_copy 25
#define yellow_paste 26
#define red_cut 4
#define black_all 16
#define white_undo 17

const unsigned long debounceDelay = 50;
// INITIAL BUTTON STATES
// COPY BUTTON
bool copyButtonState = HIGH;
bool lastCopyReading = HIGH;

// PASTE BUTTON
bool pasteButtonState = HIGH;
bool lastPasteReading = HIGH;

// CUT BUTTON
bool cutButtonState = HIGH;
bool lastCutReading = HIGH;

// SELECT ALL BUTTON
bool allButtonState = HIGH;
bool lastAllReading = HIGH;

// UNDO BUTTON
bool undoButtonState = HIGH;
bool lastUndoReading = HIGH;

// Timing
unsigned long lastCopyDebounceTime = 0;
unsigned long lastPasteDebounceTime = 0;
unsigned long lastCutDebounceTime = 0;
unsigned long lastAllDebounceTime = 0;
unsigned long lastUndoDebounceTime = 0;

void flashLED(); // Function prototype

void setup()
{
  Serial.begin(115200);

  pinMode(blue_copy, INPUT_PULLUP);
  pinMode(yellow_paste, INPUT_PULLUP);
  pinMode(red_cut, INPUT_PULLUP);
  pinMode(black_all, INPUT_PULLUP);
  pinMode(white_undo, INPUT_PULLUP);

  bleKeyboard.begin();
  delay(1000);

  Serial.println("BLE Keyboard started...");
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    flashLED();

    // Read input from COPY BUTTON
    bool copyReading = digitalRead(blue_copy);
    if (copyReading != lastCopyReading)
    {
      lastCopyDebounceTime = millis();
    }
    if ((millis() - lastCopyDebounceTime) > debounceDelay)
    {
      if (copyReading != copyButtonState)
      {
        copyButtonState = copyReading;

        if (copyButtonState == LOW) // rising edge detected
        {
          Serial.println("Copy triggered");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('c');
          delay(50);
          bleKeyboard.releaseAll();
        }
      }
    }
    lastCopyReading = copyReading;

    // reading input from PASTE BUTTON
    bool pasteReading = digitalRead(yellow_paste);
    if (pasteReading != lastPasteReading)
    {
      lastPasteDebounceTime = millis();
    }
    if ((millis() - lastPasteDebounceTime) > debounceDelay)
    {
      if (pasteReading != pasteButtonState)
      {
        pasteButtonState = pasteReading;

        if (pasteButtonState == LOW)
        {
          Serial.println("Paste triggered");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('v');
          delay(50);
          bleKeyboard.releaseAll();
        }
      }
    }
    lastPasteReading = pasteReading;

    // reading input from CUT BUTTON
    bool cutReading = digitalRead(red_cut);
    if (cutReading != lastCutReading)
    {
      lastCutDebounceTime = millis();
    }
    if ((millis() - lastCutDebounceTime) > debounceDelay)
    {
      if (cutReading != cutButtonState)
      {
        cutButtonState = cutReading;

        if (cutButtonState == LOW)
        {
          Serial.println("Cut triggered");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('x');
          delay(50);
          bleKeyboard.releaseAll();
        }
      }
    }
    lastCutReading = cutReading;

    // reading input from SELECT ALL BUTTON
    bool allReading = digitalRead(black_all);
    if (allReading != lastAllReading)
    {
      lastAllDebounceTime = millis();
    }
    if ((millis() - lastAllDebounceTime) > debounceDelay)
    {
      if (allReading != allButtonState)
      {
        allButtonState = allReading;

        if (allButtonState == LOW)
        {
          Serial.println("Select All triggered");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('a');
          delay(50);
          bleKeyboard.releaseAll();
        }
      }
    }
    lastAllReading = allReading;

    // reading input from UNDO BUTTON
    bool undoReading = digitalRead(white_undo);
    if (undoReading != lastUndoReading)
    {
      lastUndoDebounceTime = millis();
    }
    if ((millis() - lastUndoDebounceTime) > debounceDelay)
    {
      if (undoReading != undoButtonState)
      {
        undoButtonState = undoReading;

        if (undoButtonState == LOW)
        {
          Serial.println("Undo triggered");
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('z');
          delay(50);
          bleKeyboard.releaseAll();
        }
      }
    }
    lastUndoReading = undoReading;
  }

  delay(10);
}

void flashLED()
{
  digitalWrite(statusLED, HIGH);
  delay(50);
  digitalWrite(statusLED, LOW);
  delay(4000);
}
