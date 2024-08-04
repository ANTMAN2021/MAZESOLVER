#include "micromouse.h"

void setup() {
  Serial.begin(115200);
  gpioInit();
}

void loop() {
  //Reading Sensor Values
  int distance1 = sonar1.ping_cm(); //right
  int distance2 = sonar2.ping_cm(); //forward
  int distance3 = sonar3.ping_cm(); //left

  // Print sensor readings for debugging
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Distance 3: ");
  Serial.println(distance3);


  if (distance2 > 14 && distance3 > 14  )
  {
    delay(100);
    moveforward();
      Serial.print("forward");
          delay(100);
    stopmouse();
    delay(50);
    moveright();                           //front right blank
          Serial.print("right");
    delay(170);
    stopmouse();
    
  }


  if (distance1 > 14 && distance2 > 14  )
  {
    delay(100);
    moveforward();
      Serial.print("forward");
          delay(100);
    stopmouse();
    delay(50);
    moveright();                           //front left blank
          Serial.print("right");
    delay(170);
    stopmouse();
    
  }
  //reverse
 /* if ( distance1 < 7 && distance3 < 7)
  {
    delay(100);
    moveforward();
      Serial.print("forward");
          delay(100);
    stopmouse();
    delay(50);
    moveright();                           //front right blank
          Serial.print("right");
    delay(170);
    stopmouse();
  */
 //reverse
 /* if (distance1 < 8 && distance2 < 7  && distance3 < 8 )
  {
    stopmouse();

    backward();
    delay(500);
    stopmouse();
    
  // }*/
//always right
  if ( distance1 > 14 && distance3 > 14)
  {
    delay(100);
    moveforward();
      Serial.print("forward");
          delay(100);
    stopmouse();
    delay(50);
    moveleft();
              Serial.print("left");
    delay(140);
    stopmouse();
    
  }
 
 
  //if only right sensor detects wall
  if (distance1 > 14 && distance3 < 8 )
  {
    delay(100);
    moveforward();
      Serial.print("forward");
          delay(100);
    stopmouse();
    delay(50);
    moveright();                         //left right blank
          Serial.print("right");
    delay(170);
    stopmouse();
    
  }
   if ( distance1 <8 && distance3 > 14)
  {
    delay(100);
    moveforward();
      Serial.print("forward");
          delay(100);
    stopmouse();
    delay(50);
    moveleft();
              Serial.print("left");
    delay(170);
    stopmouse();
    
  }
  if (distance1 < distance3 )
  {
    delay(100);
    moveleft();
              Serial.print("left");
    delay(15);
    stopmouse();
    moveforward();
      Serial.print("forward");
          delay(50);
    stopmouse();
    delay(10);
    
  }
  if ( distance3 < distance1 )
  {
    delay(100);
    moveright();
              Serial.print("right");
    delay(15);
    stopmouse();
    moveforward();
      Serial.print("forward");
          delay(50);
    stopmouse();
    delay(10);
    
  }
 
  
  
}/* void loop() */
