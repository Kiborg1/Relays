void blink_13()
{ 
PORTB  |=   B00100000;
delay(50);
PORTB  &=   B11011111;
}


byte bit_reverse(byte in)
{
  byte buf =0;
  for (byte  i = 0 ; i<8; i++)
  {
     buf = buf<<1;
     buf+= in & B00000001;
  }
  return buf;
}
void setup() {
  delay(1000);
  // put your setup code here, to run once:
DDRB |= B00111111;
DDRD |= B11111100;
DDRC |= B00111111;
PORTB = B00000000;
PORTD = B00000000;
PORTC = B00000000;
blink_13();
Serial.begin(9600);     
blink_13();
Serial.println("STARTED");
}



void loop() {
}

/*
byte relay_in_status = B00000000 ;
byte relay_out_status =  B00000000;
byte no_com = 0;
byte relay_addr = 0  ;
byte cmd =0;
// 0 = off
// 1 = in
// 2 = out

void loop() {
  byte pd;
  byte pb;
  byte pc;
  byte pb1;
  // put your main code here, to run repeatedly:
relay_addr =(byte) Serial.parseInt();
cmd = (byte) Serial.parseInt();
Serial.println("ACCEPTED");
if ( (0<=relay_addr<8) & (0<=cmd<3))
  {
  byte mask =  1<< relay_addr;
  switch (cmd) 
  {
    case 0:
    mask = ~mask;
    relay_in_status &= mask;
    relay_out_status &= mask;
  
    pd = relay_in_status ; 
    pd = pd<< 2 ;
    pb  = relay_in_status ; 
    pb = pb>> 6;
    PORTD  &=pd ;
    PORTB  &= pb;

    pb = relay_out_status ; 
    pb = pb<< 2 ;
    pb&= B00111100;
    pc  = relay_out_status ; 
    pc = pc>> 4;
    pc&= B00001111;
    PORTB  &=pb ;
    PORTC  &= pc;
    break;
  
    case 1:
    relay_out_status &= ~mask;
    relay_in_status |= mask;
 
    pd = relay_in_status ; 
    pd = pd<< 2 ;
    pb1  = relay_in_status ; 
    pb1 = pb>> 6; 
    pb = relay_out_status ; 
    pb = pb<< 2 ;
    pb&= B00111100;
    pb|= pb1;
    pc  = relay_out_status ; 
    pc = pc>> 4;
    pc&= B00001111;
  
    PORTD  &=pd ;
    PORTB  &=pd ;
    PORTC  &= pc;

    delay(100);
  
    PORTD  |=pd ;
    PORTB  |=pd ;
    PORTC  |= pc;
    break;
  
    case 2:
    relay_in_status &= ~mask;
    relay_out_status |= mask;
    
    pd = relay_in_status ; 
    pd = pd<< 2 ;
    pb1  = relay_in_status ; 
    pb1 = pb>> 6; 
    pb = relay_out_status ; 
    pb = pb<< 2 ;
    pb&= B00111100;
    pb|= pb1;
    pc  = relay_out_status ; 
    pc = pc>> 4;
    pc&= B00001111;
  
    PORTD  &=pd ;
    PORTB  &=pd ;
    PORTC  &= pc;

    delay(100);
  
    PORTD  |=pd ;
    PORTB  |=pd ;
    PORTC  |= pc;
    break;

    delay(100);
}



Serial.println("OK");
}
else
{
  Serial.println("ERROR");
  }
}

*/
