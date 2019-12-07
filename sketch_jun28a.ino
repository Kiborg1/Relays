byte MAP_IN[8]={2,3,4,5,6,7,8,9};
byte MAP_OUT[8]={10,11,12,13,A0,A1,A2,A3};

void setup() {
DDRB |= B00111111;
DDRD |= B11111100;
DDRC |= B00111111;
PORTB = B00000000;
PORTD = B00000000;
PORTC = B00000000;
Serial.begin(57600);     
Serial.println("STARTED");
Serial.flush();
} 

#define ch_max 3 
#define ch_min 0  

int c, ch;
void loop() {
 while (Serial.available()==0) {};
 int  buf =   Serial.parseInt();
 c= buf/10;
 ch = buf%10;
 
 Serial.print(c);
 Serial.print(" ");
 Serial.println(ch); 
Serial.flush();
 if ((ch>= ch_min) && (ch<= ch_max))
 {
  if (c == 0 )//out
  {
  for (int i = 0 ; i<4; i++)
    if (i!=ch)  
      digitalWrite(  MAP_OUT[2*i+1], LOW); 
   // else
    //  digitalWrite(  MAP_IN[2*i+1], LOW);
    delay(100);  
    for (int i = 0 ;i<4; i++)
      if (i!=ch)  
      digitalWrite(  MAP_OUT[2*i], LOW);   
    //  else
    //  digitalWrite(  MAP_IN[2*i], LOW);
  digitalWrite(MAP_OUT[2*ch],HIGH);
  delay(100) ;
  digitalWrite(MAP_OUT[2*ch+1],HIGH);
  }
 if (c == 1 )//in
  {
  for (int i = 0 ; i<4; i++)
    if (i!=ch)  
      digitalWrite(  MAP_IN[2*i+1], LOW); 
  //  else
   //   digitalWrite(  MAP_OUT[2*i+1], LOW);
    delay(100);  
  for (int i = 0; i<4; i++)
      if (i!=ch)  
      digitalWrite(  MAP_IN[2*i], LOW);   
  //    else
  //    digitalWrite(  MAP_OUT[2*i], LOW);
  digitalWrite(MAP_IN[2*ch],HIGH);
  delay(100) ;
  digitalWrite(MAP_IN[2*ch+1],HIGH);
  }
}
}
