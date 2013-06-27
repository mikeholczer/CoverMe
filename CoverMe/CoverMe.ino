const int rc_pin = 2;

const int blue_led = 5;
const int green_led = 4;

void setup(){
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
  //digitalWrite(enable_pin, HIGH);
}

void loop(){  
  if(RCtime() > 2000)
  {
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, HIGH);
  }
  else
  {
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, LOW);
  }
}

int RCtime()
{
  int reading = 0;
  pinMode(rc_pin, OUTPUT);
  digitalWrite(rc_pin, LOW);

  delay(.1);

  digitalWrite(rc_pin, INPUT);

  pinMode(rc_pin, INPUT);
  while(digitalRead(rc_pin) == LOW)
  {
    reading++;
  }
  return reading;
}
