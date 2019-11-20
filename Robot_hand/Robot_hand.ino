#include <Servo.h>

Servo srv0, srv1, srv2, srv3, srv4, srv5;
char i, chk, r;
int a = 90, b = 80, c = 180, d = 90, e = 90, f = 160;

void setup() 
{
  srv0.attach(42); //A
  srv1.attach(44); //B
  srv2.attach(46); //C
  srv3.attach(48); //D
  srv4.attach(50); //E
  srv5.attach(52); //F
  srv0.write (a); //A
  delay(10);
  srv1.write (b); //B
  delay(10);
  srv2.write (c); //C
  delay(10);
  srv3.write (d); //D
  delay(10);
  srv4.write (e); //E
  delay(10);
  srv5.write (f); //F
  delay(10);
  Serial1.begin(38400);
  Serial.begin(9600);
}

void loop()
{ 
  if( Serial1.available() > 0 ) {    
    r = Serial1.read(); 
    Serial.write(r);   
  }
  if(r == '0' || r == '1' || r == '2')
    i = r;
  if(r == 'A' || r == 'B' || r == 'C' || r == 'D' || r == 'E' || r == 'F')
    chk = r;
  switch (chk) {
    case 'A':
      if(i == '0' && a >= 0)
        a--;
      if(i == '1' && a <= 180)
        a++;
      srv0.write (a);
      delay(20);
      break;
      
    case 'B':
      if(i == '1' && b >= 0)
        b--;
      if(i == '0' && b <= 180)
        b++;
      srv1.write (b);
      delay(50);
      break;
      
    case 'C':
      if(i == '0' && c >= 0)
        c--;
      if(i == '1' && c <= 180)
        c++;
      srv2.write (c);
      delay(20);
      break;
      
    case 'D':
      if(i == '1' && d >= 0)
        d--;
      if(i == '0' && d <= 180)
        d++;
      srv3.write (d);
      delay(10);
      break;
      
    case 'E':
      if(i == '1'  && e >= 0)
        e--;
      if(i == '0' && e <= 180)
        e++;
      srv4.write (e);
      delay(10);
      break;
    
    case 'F':
      if(i == '1' && f >= 80)
        f--;
      if(i == '0' && f <= 160)
        f++;
      srv5.write (f);
      delay(10);
      break;
  }  
}
