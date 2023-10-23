
// turn on peltier
void turnonpeltier(){
  digitalWrite(Peltier,HIGH);
  delay(200);
}
// turn off peltier
void turnoffpeltier(){
  digitalWrite(Peltier,LOW);
  delay(200);
}
// turn on heat
void turnonheat(){
  digitalWrite(Heat,HIGH);
  delay(200);
}
// turn off heat
void turnoffheat(){
  digitalWrite(Heat,LOW);
  delay(200);
}
// setup
void setup() {
  Serial.begin(9600);
  pinMode(Peltier,OUTPUT);
  pinMode(Heat,OUTPUT);
  pinMode(Switch,INPUT);
 
}
//
 
 
void loop() {
if (digitalRead(Switch) == HIGH)
{
  side = 'H';
}
else
{
  side = 'C';
}
// if its high hot else cold
  // read thermometer
  int temp1 = analogRead(A0);
  int temp2 = analogRead(A1);
  int temp3 = analogRead(A2);
  // -- 
  // mathematical conversions
  temp1 = (temp1 * 5.0) / 1024.0;
  temp2 = (temp2 * 5.0) / 1024.0;
  temp3 = (temp3 * 5.0) / 1024.0;
  tempf1 = temp1 * 100;
  tempf2 = temp2 * 100;
  tempf3 = temp3 * 100;
  // --
  // serial print
  Serial.print("Temperature 1: ");
  Serial.print(tempf1);
  Serial.print("Temperature 2: ");
  Serial.print(tempf2);
  Serial.print("Temperature 3: ");
  Serial.print(tempf3);
  // --
  // --------------------------HERE THE MAIN STUFF STARTS--------------------
  // side selector
  if (side == 'H'){
    turnonheat();
    turnoffpeltier();
    else if (side == 'C'){
      turnonpeltier();
      turnoffheat();
    }
  }
  if (side == 'H'){
    if (tempf1 > 45.0) turnoffheat();
    else if (tempf1 < 41.0) turnonheat();
    else delay(200);
  }
  if (side == 'C'){
    if (tempf2 < 10.0) turnoffpeltier();
    else if (tempf2 > 14.0) turnonpeltier();
    else delay(200);
  }
  
  


}