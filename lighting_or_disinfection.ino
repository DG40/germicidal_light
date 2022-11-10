// Pins numbers:
byte relayPin = 3;
byte dMax = 170;
const int trigPin = 4;
const int echoPin = 5;

// Variables:
long duration;
int distance;
int p;


void setup() 
{
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop() 
{   
	// Clear the trigPin:
	digitalWrite(trigPin, LOW);
	delayMicroseconds(200);
	// Set the trigPin on HIGH state for 10 micro seconds:
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(1000);
	digitalWrite(trigPin, LOW);
	// Read the echoPin, returns the sound wave travel time in microseconds:
	duration = pulseIn(echoPin, HIGH);
	// Calculate the distance:
	distance = duration*0.034/2;

	if (distance < dMax)
		p++;
	else
		p--;

	if (p > 5)
		p = 5;
	if (p < 0)
		p = 0;

	if (p == 5)
		digitalWrite(relayPin, LOW);
	if (p == 0)
		digitalWrite(relayPin, HIGH);
	  
	delay(10);     
}
