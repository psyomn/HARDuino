int a = 38;  // Light1 pin index
int b = 46;  // Light2 pin index

void setup()
{
 pinMode(38, OUTPUT);
 pinMode(39, OUTPUT);
 pinMode(40, OUTPUT);
 pinMode(41, OUTPUT);
 pinMode(42, OUTPUT);
 pinMode(43, OUTPUT);
 pinMode(44, OUTPUT);
 pinMode(45, OUTPUT);
 pinMode(46, OUTPUT);
}

void loop()
{
 digitalWrite(a, LOW);
 a++;
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 b--;
 digitalWrite(b, HIGH);

 if(a >= 46)
 {
  a = 38;
 }
 if(b <= 38)
 {
  b = 46;
 }

 delay(100);
}
