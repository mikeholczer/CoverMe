int enable_pin = 18;
int coil_A_1_pin = 4;
int coil_A_2_pin = 17;
int coil_B_1_pin = 23;
int coil_B_2_pin = 24;

int red_led = 25;
int green_led = 22;

void setup(){
  pinMode(enable_pin, OUTPUT);
  pinMode(coil_A_1_pin, OUTPUT);
  pinMode(coil_A_2_pin, OUTPUT);
  pinMode(coil_B_1_pin, OUTPUT);
  pinMode(coil_B_2_pin, OUTPUT);
  
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
  digitalWrite(enable_pin, HIGH);
}

void loop(){
  if(RCtime(18) > 500)
  {
    digitalWrite(red_led, LOW);
    if(random(1,10) < 2)
    {
      forward(10 / 1000.0, 10);
    }
    else
    {
      backwards(10 / 1000.0, 10);
    }
  }
  else
  {
    digitalWrite(red_led, HIGH);
  }
}

void forward(int delay_time, int steps){
  digitalWrite(green_led, HIGH);
  
  for(int i = 0; i<steps; i++)
  {
    setStep(1, 0, 1, 0);
    delay(delay_time);
    setStep(0, 1, 1, 0);
    delay(delay_time);
    setStep(0, 1, 0, 1);
    delay(delay_time);
    setStep(1, 0, 0, 1);
    delay(delay_time);
  }
  
    digitalWrite(green_led, LOW);
}

void backwards(int delay_time, int steps){
  digitalWrite(green_led, HIGH);
  
  for(int i = 0; i<steps; i++)
  {
    setStep(1, 0, 0, 1);
    delay(delay_time);
    setStep(0, 1, 0, 1);
    delay(delay_time);
    setStep(0, 1, 1, 0);
    delay(delay_time);
    setStep(1, 0, 1, 0);
    delay(delay_time);
  }
  
    digitalWrite(green_led, LOW);
}

void setStep(int w1, int w2, int w3, int w4)
{
  digitalWrite(coil_A_1_pin, w1);
  digitalWrite(coil_A_2_pin, w2);
  digitalWrite(coil_B_1_pin, w3);
  digitalWrite(coil_B_2_pin, w4);
}

int RCtime(int RCpin)
{
  int reading = 0;
  pinMode(RCpin, OUTPUT);
  digitalWrite(RCpin, LOW);
  delay(.1);
  
  digitalWrite(RCpin, INPUT);
  while(digitalRead(RCpin) == LOW)
  {
    reading++;
  }
  return reading;
}
