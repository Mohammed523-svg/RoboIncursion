// Program for a line following robot by hamza ali abbasi
// Hope this is helping you
// All the very best!!!

//Motor 1
const int ena = 10;                                                                 
const int in1 = 9;
const int in2 = 8;

//Motor 2
const int enb = 5;
const int in3 = 7;
const int in4 = 6;

//Defining variable for the speed of the motor
int motorSpeed = 0;

//Defining two of the ir sensors as ir1 and ir2
const int ir1 = A0;
const int ir2 = A1;

//Defining values from the two ir sensors
int ir1Val = analogRead(ir1);
int ir2Val = analogRead(ir2); 


void setup() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

   
  

  void demo()
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(ena, 180);
    analogWrite(enb, 180);
  }

  void loop () {
    if (analogRead(ir1)<200){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ena, 70);
     
    }
    
    else  {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ena, 70);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enb, 70);
    }
      

    if(analogRead(ir2)<200){
       digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enb, 70);
    }

    else  {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(ena, 70);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enb, 70);
      
    }

    if(analogRead(ir2)>200 && analogRead(ir1)>200){
       
      analogWrite(ena, 0);
      
      analogWrite(enb, 0);

    }
   Serial.print(analogRead(ir1));
   Serial.print(" ");
   Serial.println(analogRead(ir2));
   
  }
