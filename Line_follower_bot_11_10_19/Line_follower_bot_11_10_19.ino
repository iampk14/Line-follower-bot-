int forwardRight = 12;   //right motor, forward action
int forwardLeft = 9;    //left motor, forward action
int backwardRight = 10;   //right motor, backward action
int backwardLeft = 8;    //left motor, backward action

const int IrSensorR=A5;   //Ir sensor on right side
const int IrSensorL=A3;   //Ir sensor on left side
int IrReadingR, IrReadingL ;
void setup()
{
  pinMode(IrSensorR,INPUT);
  pinMode(IrSensorL,INPUT);
  pinMode(forwardRight, OUTPUT);
  pinMode(forwardLeft, OUTPUT);
  pinMode(backwardRight, OUTPUT);
  pinMode(backwardLeft, OUTPUT);
  Serial.begin(9600);  
}

void FR()   //function for forward action of the right motor
{
  digitalWrite(forwardRight, HIGH);
  digitalWrite(backwardRight, LOW);
}

void FL()   //function for forward action of the left motor
{
  digitalWrite(forwardLeft, HIGH);
  digitalWrite(backwardLeft, LOW);
}

void right()   //function for right action of the robot
{
  digitalWrite(forwardLeft, HIGH);
  digitalWrite(backwardRight, LOW);
}

void left()    //function for left action of the robot
{
  digitalWrite(forwardRight, HIGH);
  digitalWrite(backwardLeft, LOW);
}

void allstop()    //function for stopping the robot
{
  digitalWrite(forwardRight, LOW);
  digitalWrite(backwardRight, LOW);
  digitalWrite(backwardLeft, LOW);
  digitalWrite(forwardLeft, LOW);
}

void loop()
{
 IrReadingR=analogRead(IrSensorR);         //Taking values
 IrReadingL=analogRead(IrSensorL);
 if(IrReadingR>=50)                       
  {
    IrReadingR=1;
  }
  else
  {
    IrReadingR=0;
  }
   if(IrReadingL>=50)
  {
    IrReadingL=1;
  }
  else
  {
    IrReadingL=0;
  }
  if(IrReadingR==1 && IrReadingL==1)                     //Condition for the bot to move forward 
  {
    FR();
    FL();
  }
  else if(IrReadingR==1 && IrReadingL==0)                //Condition for the bot to move right
  {
    right();
  }
  else if(IrReadingR==0 && IrReadingL==1)                //Condition for the bot to move left
  {
    left();
  }
  else
  {
    allstop();                                          
  }
} 
