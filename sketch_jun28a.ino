byte MAP_IN[8]= { 2, 3, 4, 5, 6, 7, 8,9};
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

#define ch_max 7 
#define ch_min 0  

int c, ch;
void loop() {
 while (Serial.available()<2) {};
 int  buf =   Serial.parseInt();
 c= buf/10;
 ch = buf%10;

 if ((ch>= ch_min) && (ch<= ch_max))
 {
    switch (c){
    case 0://out
    {  
      for (int i = ch_min ; i<=ch_max; i++)
      if (i!=ch)  
      digitalWrite(  MAP_OUT[ i ], LOW); 
      delay(100);   
      digitalWrite(MAP_OUT[ch],HIGH); 
      break;
    }
   case 1: //in
     {
      for (int i = ch_min ; i<=ch_max; i++) 
      if (i!=ch)  
      digitalWrite(  MAP_IN[i], LOW);  
      delay(100);   
      digitalWrite(MAP_IN[ch],HIGH);
      break;
     }
   case 2://off
      {
      digitalWrite(  MAP_IN[ch], LOW);
      digitalWrite(  MAP_OUT[ch], LOW);  
      delay(100);
      break;
      }
  }
}
 
 Serial.print(c);
 Serial.print(" ");
 Serial.println(ch); 
Serial.flush();  
}
