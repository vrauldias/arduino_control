//Coded and Tested By:
// Sheekar Banerjee, AI-ML-IOT Solution Engineer and Researcher

/*
Arduino Water flow meter
YF- S201 Hall Effect Water Flow Sensor
Water Flow Sensor output processed to read in litres/min

Adapted by Raul G. Dias, at Universidade Tecnológica Federal do Paraná
*/
volatile int flow_frequency; // Measures flow sensor pulses
double l_min;
//unsigned float l_min; // Calculated litres/min
unsigned char flowsensor = 2; // Sensor Input
unsigned long currentTime;
unsigned long cloopTime;
void flow () // Interrupt function
{
flow_frequency++;
}

void setup() {
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);  // Optional Internal Pull-Up
  Serial.begin(9600);
  attachInterrupt(0, flow, RISING);  // Setup Interrupt
  sei();                             // Enable interrupts
  currentTime = millis();
  cloopTime = currentTime;
}

void loop ()
{
currentTime = millis();
 // Every second, calculate and print litres/min
if(currentTime >= (cloopTime + 1000))
{
 cloopTime = currentTime; // Updates cloopTime

 // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
 l_min = (flow_frequency / 7.5);
 //l_hour = (flow_frequency * 60 / 7.5);
 // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour

 flow_frequency = 0; // Reset Counter
 //Serial.print(l_hour, DEC); // Print litres/hour
 //Serial.println(" L/hour");
 Serial.print(currentTime);
 Serial.print(",");
 Serial.println(l_min, DEC); // Print litres/min
}
}
