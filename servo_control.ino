Servo myservo;
int pos = 0;
/* This circuit requires a potentiometer and a servo motor that is compatible with the Spark Core. */
void setup() {
    Serial.begin(9600);
    pinMode(A1, INPUT);
    pinMode(D6, OUTPUT);
    myservo.attach(A0);
    pinMode(D5, OUTPUT);
}

void loop() {
    digitalWrite(D6, HIGH);
    digitalWrite(D5, HIGH);
    int degrees;
    degrees = getDegree();
    Serial.println(degrees);
    myservo.write(degrees);
    delay(15);

}

/*Function: Get the angle between the mark and the starting position	*/
/*Parameter:-void														*/
/*Return:	-int,the range of degrees is 0~300							*/
int getDegree()
{
	int sensor_value = analogRead(A1);
	float voltage;
	voltage = (float)sensor_value*5/1023;
	float degrees = (voltage*300)/5;
	return degrees;
}
