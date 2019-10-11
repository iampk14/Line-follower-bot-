const int forwardRight = 12;   //right motor, forward action
const int forwardLeft = 9;    //left motor, forward action

const int IrSensorR=A5;   //Ir sensor on right side
const int IrSensorL=A3;   //Ir sensor on left side

int IrReadingR, IrReadingL ;

void setup()
{
  pinMode(IrSensorR,INPUT);
  pinMode(IrSensorL,INPUT);
  pinMode(forwardRight, OUTPUT);
  pinMode(forwardLeft, OUTPUT);
  Serial.begin(9600);  
}

void Forward()   //function for forward action
{
  digitalWrite(forwardRight, HIGH);
  digitalWrite(forwardLeft, HIGH);
}

void right()   //function for right action of the robot
{
  digitalWrite(forwardLeft, HIGH);
  digitalWrite(forwardRight, LOW);
}

void left()    //function for left action of the robot
{
  digitalWrite(forwardRight, HIGH);
  digitalWrite(forwardLeft, LOW);
}

void allstop()    //function for stopping the robot
{
  digitalWrite(forwardRight, LOW);
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
    Forward();
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
