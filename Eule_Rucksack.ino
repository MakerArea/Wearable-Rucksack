#include<Adafruit_NeoPixel.h>
#ifdef __AVR__
#include<avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      101

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int received = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int rot = 0;
int gruen = 0;
int blau = 0;
int weiss = 0;
int val = 0;
int led=0;
int error = 0;
int farbe=0;
int i=0;

void setup()
{
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop()
{
  if (Serial.available() > 0)
  {
    received = Serial.read();
  }

  if (received > 0)
  {
    if (received < 48 or received > 57)
    {
      if (received != 44 and received != 13)
      {
        error = 1;
      }
    }
    if (error == 0)
    {
      if (received != 44 and received != 13)
      {
        val++;
        if (val == 1)
        {
          if(received==48)
          {
            i=0;
          }
          else if(received==49)
          {
            i=1;
          }
          else if(received==50)
          {
            i=2;
          }
          else if(received==51)
          {
            i=3;
          }
          else if(received==52)
          {
            i=4;
          }
          else if(received==53)
          {
            i=5;
          }
          else if(received==54)
          {
            i=6;
          }
          else if(received==55)
          {
            i=7;
          }
          else if(received==56)
          {
            i=8;
          }
          else if(received==57)
          {
            i=9;
          }
          
          num1 = i;
        }
        else if (val == 2)
        {
          if(received==48)
          {
            i=0;
          }
          else if(received==49)
          {
            i=1;
          }
          else if(received==50)
          {
            i=2;
          }
          else if(received==51)
          {
            i=3;
          }
          else if(received==52)
          {
            i=4;
          }
          else if(received==53)
          {
            i=5;
          }
          else if(received==54)
          {
            i=6;
          }
          else if(received==55)
          {
            i=7;
          }
          else if(received==56)
          {
            i=8;
          }
          else if(received==57)
          {
            i=9;
          }
          
          num2 = i;
        }
        else if (val == 3)
        {
          if(received==48)
          {
            i=0;
          }
          else if(received==49)
          {
            i=1;
          }
          else if(received==50)
          {
            i=2;
          }
          else if(received==51)
          {
            i=3;
          }
          else if(received==52)
          {
            i=4;
          }
          else if(received==53)
          {
            i=5;
          }
          else if(received==54)
          {
            i=6;
          }
          else if(received==55)
          {
            i=7;
          }
          else if(received==56)
          {
            i=8;
          }
          else if(received==57)
          {
            i=9;
          }
          
          num3 = i;
        }
        else
        {
          val--;
        }
      }
      else if(received==44)
      {
        farbe++;
        if(farbe==1)
        {
          if(val==1)
          {
            led=num1;
          }
          else if(val==2)
          {
            num1=num1*10;
            led=num1+num2;
          }
          else if(val==3)
          {
            num1=num1*100;
            num2=num2*10;
            led=num1+num2+num3;
          }
          
          if(led>NUMPIXELS)
          {
            error=1;
          }
        }
        else if(farbe==2)
        {
          if(val==1)
          {
            rot=num1;
          }
          else if(val==2)
          {
            num1=num1*10;
            rot=num1+num2;
          }
          else if(val==3)
          {
            num1=num1*100;
            num2=num2*10;
            rot=num1+num2+num3;
          }
          if(rot>255)
          {
            error=1;
          }
        }
        else if(farbe==3)
        {
          if(val==1)
          {
            gruen=num1;
          }
          else if(val==2)
          {
            num1=num1*10;
            gruen=num1+num2;
          }
          else if(val==3)
          {
            num1=num1*100;
            num2=num2*10;
            gruen=num1+num2+num3;
          }
          if(gruen>255)
          {
            error=1;
          }
        }
        else if(farbe==4)
        {
          if(val==1)
          {
            blau=num1;
          }
          else if(val==2)
          {
            num1=num1*10;
            blau=num1+num2;
          }
          else if(val==3)
          {
            num1=num1*100;
            num2=num2*10;
            blau=num1+num2+num3;
          }
          if(blau>255)
          {
            error=1;
          }
        }
        val=0;
      }
      else if(received==13)
      {
        farbe++;
        
        if(farbe==5)
        {
          if(val==1)
          {
            weiss=num1;
          }
          else if(val==2)
          {
            num1=num1*10;
            weiss=num1+num2;
          }
          else if(val==3)
          {
            num1=num1*100;
            num2=num2*10;
            weiss=num1+num2+num3;
          }
          if(weiss>255)
          {
            error=1;
          }
        }
        
        if(error==0)
        {
          pixels.setPixelColor(led, pixels.Color(rot, gruen, blau, weiss));
          pixels.show();
        }
        else
        {
          error=0;
        }
        rot=0;
        gruen=0;
        blau=0;
        weiss=0;
        farbe=0;
        num1=0;
        num2=0;
        num3=0;
        val=0;
      }
    }
    received=0;
  }
}
