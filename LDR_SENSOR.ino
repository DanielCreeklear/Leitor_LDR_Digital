void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  Serial.println(LDR_READ());
}

int LDR_READ()
{
  int count = 0;
  
  DDRD |= (1 << DDD7);
  PORTD &= ~(1 << PORTD7);
  delayMicroseconds(10);

  DDRD &= ~(1 << DDD7);

  while((PIND & (1 << PIND7)) == LOW)
  {
    count++;
  }
  return count;
}
