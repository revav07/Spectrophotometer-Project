#define LED_Red 13
#define LED_Green 12
#define LED_Blue 11
#define BUTTON_PIN 5
#define POT_PIN A0

byte lastButtonState;
byte ledState = LOW; 
String color; 
int ldr_value = 0;

void setup() {
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Blue, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

  lastButtonState = digitalRead(BUTTON_PIN); 

  Serial.begin(9600);
  Serial.println("Enter LED Color (red, green, blue): "); 

  while (color == ""){
    if(Serial.available()){
      color = Serial.readStringUntil('\n'); 
      color.trim();
      color.toLowerCase(); 
    }
  }
}

void loop() {
  byte buttonState = digitalRead(BUTTON_PIN); 
  
  if (buttonState != lastButtonState){
    lastButtonState = buttonState; 
    
    if (buttonState == LOW){
      
      ledState = !ledState; 

      if (color == "red"){
        digitalWrite(LED_Red, ledState); 
      }
      else if (color == "green"){
        digitalWrite(LED_Green, ledState);
      }
      else if (color == "blue"){
        digitalWrite(LED_Blue, ledState);
        Serial.println("blue");
      }

      delay(50); 
    }
  }

  ldr_value = analogRead(POT_PIN); 
  Serial.println(ldr_value); 
  delay(100); 

}