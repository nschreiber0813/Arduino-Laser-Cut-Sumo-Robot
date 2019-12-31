#include <NewPing.h>
const int left_forward = A3;//while high moves left motor forward
const int left_backward = A2;//while high moves left motor backward
const int right_forward = A4;//while high moves right motor forward
const int right_backward = A5;//while high moves right motor backward
const int left_side = 13;//left edge sensor
const int right_side = 12;//right edge sensor
NewPing Sonar(8,9, 60);
NewPing Left_Sonar(11,10, 60);
NewPing Right_Sonar(6, 5, 60);
void setup() {
  // put your setup code here, to run once:
  //Pin setup is declared here.
  pinMode(left_forward, OUTPUT);
  pinMode(left_backward, OUTPUT);
  pinMode(right_forward, OUTPUT);
  pinMode(right_backward, OUTPUT);
  pinMode(left_side, INPUT);
  pinMode(right_side, INPUT);
  Serial.begin(9600); 
  Stop();
  delay(4000);
}
bool invert = false;
bool obstacle_mode = true;// Obstacle mode is declared true by default until an edge is reached where it is inverted from there.
int duration = 300;// Duration of the robots scan for other nearby robots is decalred here.
void loop() {
  int  dist;// Sonar.ping_cm() is this variables near equivilent.
  // put your main code here, to run repeatedly:
  
  //If the robot is in the near center of the arena and obstacle mode is true the robot moves forward.
  if (digitalRead(right_side) == HIGH && digitalRead(left_side) == HIGH && obstacle_mode == true){
    forward();
    if (obstacle_mode == true && Left_Sonar.ping_cm() <= 60 && Left_Sonar.ping_cm() != 0){
      invert = false;
      obstacle_mode = false;
    }
    if (obstacle_mode == true && Right_Sonar.ping_cm() <= 60 && Right_Sonar.ping_cm() != 0){
      invert = true;
      obstacle_mode = false;
    }
  }
  //If the robot is on an edge of the arena obstacle mode is inverted, the robot moves backwards, and then turns left.
  if (digitalRead(right_side) == LOW || digitalRead(left_side) == LOW){
    backward();
    delay(1000);
    if (obstacle_mode == false){
      obstacle_mode = true;
    }
    else{
      obstacle_mode = false; 
    }
  }
  //if obstacle mode is false robot scans the arena for another bot. The duration of the scan is defined above the loop. 
  if (obstacle_mode == false && invert == false){
    Left(); 
    delay(25);
    Stop();
    delay(50);
    duration -= 1;
    dist= Sonar.ping_cm();
    Serial.println(dist);
    if (dist <= 30 && dist != 0 || duration <= 0){//if the scan turns up something obstacle mode becomes true and the robot will run over the other bot. 
      duration = 300;
      obstacle_mode = true;
    }
  }
  if (obstacle_mode == false && invert == true){
    Right(); 
    delay(25);
    Stop();
    delay(50);
    duration -= 1;
    dist= Sonar.ping_cm();
    Serial.println(dist);
    if (dist <= 30 && dist != 0 || duration <= 0){//if the scan turns up something obstacle mode becomes true and the robot will run over the other bot. 
      duration = 300;
      obstacle_mode = true;
    }
  }
}
void backward(){//backwards code is defined here.
  digitalWrite(left_backward, HIGH);
  digitalWrite(left_forward, LOW);
  digitalWrite(right_forward, HIGH);
  digitalWrite(right_backward, LOW);
}
void forward(){//forward code is defined here.
  digitalWrite(left_backward, LOW);
  digitalWrite(left_forward, HIGH);
  digitalWrite(right_forward, LOW);
  digitalWrite(right_backward, HIGH);
}
void Left(){//Left code is defined here.
  digitalWrite(left_backward, HIGH);
  digitalWrite(left_forward, LOW);
  digitalWrite(right_forward, LOW);
  digitalWrite(right_backward, HIGH);
}
void Right(){
  digitalWrite(left_backward, LOW);
  digitalWrite(left_forward, HIGH);
  digitalWrite(right_forward, HIGH);
  digitalWrite(right_backward, LOW);
}
void Stop()//robot stop code is defined here if need be
{
  analogWrite(left_backward, 0);
  analogWrite(left_forward, 0);
  analogWrite(right_forward, 0);
  analogWrite(right_backward, 0);
}
