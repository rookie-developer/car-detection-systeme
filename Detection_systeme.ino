// Project by : Rookie_developer
//link for the youtube channel : https://www.youtube.com/channel/UC92gG4BBWAYu4vw_OgsgSLA?view_as=subscriber

//for this project you will need : Arduino (i am using the mega) , ultrasonic sensor (hc-sr04 is used in here) , 16x4 lcd display , led , buzzer 


#include<LiquidCrystal.h>

// this is where i declared my Inputs/Outputs might be messy but i like to make them this way

#define trigPin 9  // these 2 pins are for the ultrasonic sensor 
#define echoPin 8  
#define led1 50    // all these 4 are leds i chose that sort of input cause i am working on an arduino Mega-2560 which has 53 I/O
#define led2 51    // if you have an uno or a nano just change the input numbs
#define led3 52
#define led4 53
#define buzzer 10  // this is the buzzer

  long duration;
  long distance;

LiquidCrystal lcd(7,6,2,3,4,5);   

void setup()
{
  
  Serial.begin(9600);
  lcd.begin(16,4);                                                                     // i have a 16x4 lcd you should chack the refrence for your lcd before preceding might be a 16x2 or a 20x4
  pinMode(led1,OUTPUT);pinMode(led2,OUTPUT);pinMode(led3,OUTPUT);pinMode(led4,OUTPUT); //these are the leds
  pinMode(buzzer,OUTPUT); 
  pinMode(trigPin,OUTPUT);                                                             //trigPin is an output since it emitts the signal
  pinMode(echoPin,INPUT);                                                              //echoPin in the input since it recieves back signal of distress

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("project by :");
  lcd.setCursor(0,1);
  lcd.print("Rookie_dev");
  delay(5000);
  lcd.clear();
  delay(2000);  
}

  void loop(){    

  //this first part of the code is to tell the trigPin to start emitting a 10ms signal to activate it
     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;     // Divide by 58 to find the exact distance

  

  //i chose the distance to be 50cm=2900/58 you can change it if you want

  if(duration <= 5800) {
    int delai;
    delai=5*distance;  //this is the delay use it according to the distance

  //the mess below me is something that i am not really proud of , after all i am a rookie..
    
  lcd.setCursor(0,1);
  lcd.print("                     ");  
  lcd.setCursor(0,0);
  lcd.print("object detected!");  
  lcd.setCursor(0,2);
  lcd.print("distance:");
  lcd.setCursor(9,2);
  lcd.print(distance);
  lcd.setCursor(11,2);
  lcd.print("cm");
  if(duration<580){
    lcd.setCursor(10,2);
    lcd.print(" ");
  }
    
  digitalWrite(led1,HIGH);digitalWrite(led2,HIGH);digitalWrite(led3,HIGH);digitalWrite(led4,HIGH);
  tone(buzzer,200);
  delay(delai);
  digitalWrite(led1,LOW);digitalWrite(led2,LOW);digitalWrite(led3,LOW);digitalWrite(led4,LOW);
  noTone(buzzer);
  delay(delai);
  }

  //i still don't know how to properly clear out my lcd which is why you are seeing so many lcd commands ... sorry ...
  
  else 
  {
    digitalWrite(led1,LOW);digitalWrite(led2,LOW);digitalWrite(led3,LOW);digitalWrite(led4,LOW);
    noTone(buzzer);
    lcd.setCursor(0,0);
    lcd.print("no objects        ");
    lcd.setCursor(0,2);
    lcd.print("                     ");
    lcd.setCursor(0,1);
    lcd.print("detected....       ");
  }
  }

  //thank you for watching please subscribe ^^ !
 
