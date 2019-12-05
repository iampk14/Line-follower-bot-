int forwardRight = 12;   //right motor, forward action
int forwardLeft = 9;    //left motor, forward action
int backwardRight = 10;   //right motor, backward action
int backwardLeft = 8;    //left motor, backward action

const int IrSensorR=A5;   //Ir sensor on right side
const int IrSensorL=A3;   //Ir sensor on left side
const int IrSensorM=A1;
int IrReadingR, IrReadingL, IrReadingM, path1[3]; 

void setup()
{
  pinMode(IrSensorR,INPUT);
  pinMode(IrSensorL,INPUT);
  pinMode(IrSensorM,INPUT);
  pinMode(forwardRight, OUTPUT);
  pinMode(forwardLeft, OUTPUT);
  pinMode(backwardRight, OUTPUT);
  pinMode(backwardLeft, OUTPUT);
  Serial.begin(9600);   //for establishing communication between arduino and others at 9600 bauds(standard value)
}

void Forward()   //function for forward action of the right motor
{
  digitalWrite(forwardRight, HIGH);
  digitalWrite(backwardRight, LOW);
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
 IrReadingM=analogRead(IrSensorM);
 if(IrReadingR<=50)                       
  {
    IrReadingR=1;
  }
  else
  {
    IrReadingR=0;
  }
   if(IrReadingL<=50)
  {
    IrReadingL=1;
  }
  else
  {
    IrReadingL=0;
  }
 if(IrReadingM<=50)                       
  {
    IrReadingM=1;
  }
  else
  {
    IrReadingM=0;
  }  
  if(IrReadingL==0 && IrReadingM==1 && IrReadingR==0)                     //Condition for the bot to move forward 
  {
    Forward();
  }
  else if(IrReadingL==0 && IrReadingM==1 && IrReadingR==1)                //Condition for the bot to move right
  {
    right();
  }
  else if(IrReadingL==1 && IrReadingM==1 && IrReadingL==0)                //Condition for the bot to move left
  {
    left();
  }
  else
  {
    allstop();                                          
  }
} 
