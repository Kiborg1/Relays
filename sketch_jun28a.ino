
byte MAP_IN[8]={2,3,4,5,6,7,8,9};

byte MAP_OUT[8]={10,11,12,13,A0,A1,A2,A3};


void setup() {
  // put your setup code here, to run once:

DDRB |= B00111111;
DDRD |= B11111100;
DDRC |= B00111111;
PORTB = B00000000;
PORTD = B00000000;
PORTC = B00000000;
Serial.begin(57600);     
Serial.println("STARTED");
}

void loop() {
  // put your main code here, to run repeatedly:

 while (Serial.available()==0) {};
 int  buf =   Serial.parseInt();
 int relay_kind  = buf/ 100;
 buf -= relay_kind*100;
 int relay_addr  = buf/ 10;
 int cmd = buf % 10;
 
 Serial.print(relay_kind);
 Serial.print(" ");
 Serial.print(relay_addr);
 Serial.print(" ");
 Serial.println(cmd);
 
if (cmd == 0 )//off
{
if (relay_kind == 0 )//  in
digitalWrite(MAP_IN[relay_addr], LOW);
if (relay_kind == 1 )//  out
digitalWrite(MAP_OUT[relay_addr], LOW);
delay(100);
}
if (cmd == 1 )//on
{
if (relay_kind == 0 )//  in
digitalWrite(MAP_IN[relay_addr], HIGH);
if (relay_kind == 1 )//  out
digitalWrite(MAP_OUT[relay_addr], HIGH);
delay(100);
}

}
