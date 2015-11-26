#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Int32.h>
#include <math.h>

ros::NodeHandle  nh;

void controleCb( const std_msgs::Int32& msg){
  
  int P;
  P=msg.data;
  
  if(P>0){
            digitalWrite(3,LOW);
          }
  else{ 
            digitalWrite(3,HIGH);
      }
  analogWrite(2,abs(P));

}

ros::Subscriber<std_msgs::Int32> sub("controle", &controleCb );

void setup(){
  TCCR3B = TCCR3B & B11111000 | B00000001;
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  
}


