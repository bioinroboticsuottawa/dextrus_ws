#include <ros/ros.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include "phidgets/encoder_params.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int x, k=0,erroant=0,calibracao[2],delta=0;
float P, I=0, D=0, PI=0, j,t=0.0001;
bool started = false;
ros::Time elapsed;

void encoderCallback(const phidgets::encoder_params::ConstPtr& ptr)
{
  started = true;
  x = ptr->count;
  t = ptr->time;
  delta = ptr->count_change;
  //ROS_INFO("count %d; time %d; count_change %d.", x, t, delta);
}

void posicaoCallback(const std_msgs::Float32::ConstPtr& ptr)
{
  started=true;
  elapsed = ros::Time::now();
  j=ptr->data;
  
}


void calibratexto(){
  
  std::ofstream myfile;
  myfile.open ("//home/rafaelpaiva/ros_sand_box/phidgets/calibra.txt");
  myfile << calibracao[0]<<"\n"<<calibracao[1];
  myfile.close();  

}

void lecalibra(){
  std::ifstream infile("//home/rafaelpaiva/ros_sand_box/phidgets/calibra.txt");
  std::string line;
  std::vector<int> v;
  while (std::getline(infile, line))
  {
  std::istringstream iss(line);
  int n;
  
  while (iss >> n)
  {
    v.push_back(n);
  }
  }
 calibracao[0]=v[0];
 calibracao[1]=v[1];
}

void calibra(){
  bool cal;
  std::cout<<"Deseja calibrar? 1-sim 0-nao \n";
  std::cin>>cal;
  if(cal){
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("controle", 1);
  std_msgs::Int32 msg_calibracao;
  usleep(500000);
  ros::Subscriber sub = n.subscribe("/phidgets/encoder", 100, encoderCallback);
  usleep(500000);
  msg_calibracao.data=250;
  chatter_pub.publish(msg_calibracao);
  usleep(5000000);
  ros::spinOnce();
  int max=x;
  std::cout<<"\n Contagem Maxima = "<< max <<"\n";
  msg_calibracao.data=-250;
  chatter_pub.publish(msg_calibracao);
  usleep(5000000);
  ros::spinOnce();
  int min=x;
  std::cout<<"\n Contagem Minima = "<< min <<"\n";
  msg_calibracao.data=0;
  chatter_pub.publish(msg_calibracao);
  calibracao[0]=min;
  calibracao[1]=max;
  calibratexto();
  }
  else{
  lecalibra();
  //std::cout<<calibracao[0]<<"\n"<<calibracao[1]<<"\n";
  }
}

int vai(int i)
{
  int pos_atual, erro,out=0;
  float x2, vel_atual;
  double deltaT = (ros::Time::now() - elapsed).toSec();
  pos_atual=x;
  vel_atual=1000*delta/t;
  std::cout << deltaT << std::endl;
  x2=-0.04014*vel_atual+0.2584*pos_atual;
  if (deltaT < 2.5)
    PI=-0.130007*(pos_atual-i)-0.0056111*(x2-i*0.2584);
  else
    PI=-0.2112537*(pos_atual-i)-0.007949809*(x2-i*0.2584);
  ROS_INFO("set_point %d PI %f ; pos atual %d", i, PI, pos_atual); 
  
  if(PI<1&&PI>0)	PI=1;
  if(PI<0&&PI>-1)	PI=-1;
  if(PI>250)		PI=250;
  if(PI<-250)		PI=-250;
  
  out=(int)PI;
  
  erroant=erro;
  delta=0;
  return out;
}


int main(int argc, char **argv)
{
  int p;
  ros::init(argc, argv, "controle_motor");
  ros::NodeHandle n;
  std_msgs::Int32 msg;
  calibra();
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("controle", 1);
  if(j>=0&&j<=100){
  ros::Subscriber sub = n.subscribe("/phidgets/encoder", 100, encoderCallback);
  ros::Subscriber subpos = n.subscribe("posicao", 1, posicaoCallback);
  ros::Rate loop_rate(120);
  
  while(ros::ok()){		
	p=(int)(j*(calibracao[1]-calibracao[0])/100)+calibracao[0];
	msg.data=vai(p);  	
	chatter_pub.publish(msg);
  	ros::spinOnce();
        loop_rate.sleep();
  	}
  return 0;
  }
  else return 0;
}
