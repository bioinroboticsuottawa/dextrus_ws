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


int x,erroant=0,calibracao[2],outant,pos_ant=0;
double t=0.00001;
float P, I=0, D=0, PI=0, j;
bool started = false;
ros::Time elapsed,k;

void encoderCallback(const phidgets::encoder_params::ConstPtr& ptr)
{
  started = true;
  //phidgets::encoder_params e = *ptr;
  x=ptr->count;
}

void posicaoCallback(const std_msgs::Float32::ConstPtr& ptr)
{
  j=ptr->data;
  outant=0;
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
  //std::cout<<calibracao[0]<<" "<<calibracao[1]<<"\n";
  }
}

int vai(int i)
{
  int pos_atual, erro, out = 0;
  pos_atual=x;
  erro=i-pos_atual;
  
  if(started){
  k=ros::Time::now();
  //std::cout<<k<<std::endl;  
  P=erro*0.053838;
  I=I+erro*0.05*t;
  D=(erro-erroant)*0.000031875/t;
  
  PI=P+I+D;

  if(PI<1&&PI>0)	PI=1;
  if(PI<0&&PI>-1)	PI=-1;
  if(PI>250)		PI=250;
  if(PI<-250)		PI=-250;
  
  out=(int)PI;
  
  ROS_INFO(" set_point %d Erro %d P %f I %f D %f PI %f pos_atual %d", i, erro, P, I, D, PI, x);  
  erroant=erro;
  pos_ant=pos_atual;
  return out;
  }
  else
        P=erro*0.053838;
        
	return (int)P;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "controle_motor");
  ros::NodeHandle n;
  ros::NodeHandle nh;
  std_msgs::Int32 msg;
  calibra();
  //std::cout<<"Digite a posicao do dedo (numero de 0 a 100): \t";
  //std::cin>>j;
  //ros::Publisher pub = n.advertise<std_msgs::Float32>("posicao", 1);
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("controle", 1);
  if(j>=0&&j<=100){
  ros::Subscriber sub = n.subscribe("/phidgets/encoder", 100, encoderCallback);
  ros::Subscriber subpos = nh.subscribe("posicao", 1, posicaoCallback);
  ros::Rate loop_rate(90);
  
  while(ros::ok()){		
	t = (ros::Time::now() - k).toSec();
	std::cout<<t<<std::endl; 
	msg.data=vai((int)j*(calibracao[1]-calibracao[0])/100+calibracao[0]);
  	chatter_pub.publish(msg);
  	ros::spinOnce();
        loop_rate.sleep();
  	}
  return 0;
  }
  else return 0;
}
