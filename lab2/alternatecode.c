#define delayOn(iInput, oInputPrev, oOutput, iDelayOn, iSystemTime,
oSignalStartTime)  \
if(iInput \
&& oInputPrev) \
{\
 oOutput = ((oSignalStartTime + iDelayOn) < iSystemTime);\
}\
else if ((iInput\
&& !oInputPrev) \
|| (iSystemTime < oSignalStartTime))\
{\
  oInputPrev = true;\
  oSignalStartTime = iSystemTime;\
}\
else\
{\
  oOutput = false;\
  oInputPrev = false;\
}


#define pulseUp(iInput, oPrevInput, oOutput)  \
if(iInput \
&& !oPrevInput)\
{\
  oOutput = true; \
}\
else\
{\
  oOutput = false;\
}\
oPrevInput = iInput;


bool pbswitch = false;
bool pbswitchprev = false;
long buff;
bool signalon = false;
bool pulseup = false;
bool pulseupprev = false;
int x = 50;


void setup()
{
  pinMode(26, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(17, INPUT);
}

void loop()
{

  if(HIGH == digitalRead(17))
  {
    pbswitch = true;
  }
  else
  {
    pbswitch = false;
  }

  bool temp;
  delayOn(pbswitch,pbswitchprev, signalon,80, millis(), buff);
  pulseUp(signalon, pulseupprev, pulseup);

  if(pulseup)
  {
    analogWrite(26,x);

    x+=50;
    if (x >= 250)
    {
      x = 50;
    }
  }

}
