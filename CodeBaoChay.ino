int const senVal = A0;
int const SW = 7;
int senValue = 0;
int PUMP_STATUS = 0;
int const BUZZ = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(senVal , INPUT);
  pinMode(SW ,OUTPUT);
  pinMode(BUZZ , OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  senValue = analogRead(senVal);
  Serial.println(senValue);
  if(senValue >= 300 && senValue <2000){
    Serial.println("Co nguy co chay no!");
    digitalWrite(SW, HIGH);
    PUMP_STATUS = 1;
    tone(BUZZ , 220);
    //delay(2000);
    }
  else if(senValue >=0 && senValue < 300){
   digitalWrite(SW, LOW);
   PUMP_STATUS = 0;
   noTone(BUZZ);
  }else{
    Serial.println("Gia tri loi!");
    digitalWrite(SW , LOW);
    noTone(BUZZ);
    delay(1000);
    }
  delay(2000);   
}
