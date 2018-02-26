
int pot1 = 0;
int pot2 = 0;

int inByte;

int led1 = 7;
int led2 = 8;

int NumberOfFlashesLeft = 0;
int NumberOfFlashesRight = 0;

bool led1state = false;
bool led2state = false;

unsigned long LastledStateChange = 0;
long CurrentTime = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() 
{
  CurrentTime = millis();
  
  if (CurrentTime - LastledStateChange > 50 && NumberOfFlashesRight > 0)
      {
        led2state = !led2state;
        digitalWrite(led2, led2state);
        LastledStateChange = CurrentTime;
        NumberOfFlashesRight--;
     }
  if (CurrentTime - LastledStateChange > 50 && NumberOfFlashesLeft > 0)
  {
        led1state = !led1state;
        digitalWrite(led1, led1state);
        LastledStateChange = CurrentTime;
        NumberOfFlashesLeft--;
  }
     
  if(Serial.available() > 0)
  {
    inByte = Serial.read();

    if (inByte == 'P')
    {
      sendPositions();
    }
    
    if (inByte == 'L')
    {
      NumberOfFlashesLeft = 20;
      led2state = false;
      digitalWrite(led2, LOW);
    }
    
    if (inByte == 'R')
    {
      NumberOfFlashesRight = 20;
      led1state = false;
      digitalWrite(led1, LOW);
    }
  }
  delay(20);
}

void sendPositions()
{
  pot1 = analogRead(A1);
  pot2 = analogRead(A0);
  
  Serial.print(getPadded(pot1));
  Serial.print("-");
  Serial.println(getPadded(pot2));
}

String getPadded(int num)
{
  char buff[5];
  char padded[6];

  sprintf(buff, "%.4u", num);

  for(int i = 0; i < 5; i++)
  {
    padded[i] = buff[i];
  }
  padded[5] = '\0';

  return String(padded);
}

