#define DEL 250
String DF = "$HEHDT,%a,T*; NMEA_COURSE: %a";
String EX = "NMEA %a";
String SN = "";

void setup() {
  Serial.begin(4800);
  pinMode(13, OUTPUT);
  EX = DF;
}
float AZ;
int Cou, Val;
String CMD;
void loop() {
  if (Serial.available()){
    EX = Serial.readString();
//    CMD = Serial.readString();
//    if (CMD
  }
  SN = EX;
  Val = analogRead(A0);
  Cou = analogRead(A1);
  AZ = (Val / 2.8764) + (Cou / 256);
  AZ = (AZ > 360.0) ? 360.0 : AZ;
  SN.replace("%a", String(AZ, 1));
  SN.replace("%b", String(Val));
  SN.replace("%c", String(Cou));
  Serial.println(SN);
  digitalWrite(13,1);
  delay(DEL / 2);
  digitalWrite(13,0);
  delay(DEL / 2);
  
}
