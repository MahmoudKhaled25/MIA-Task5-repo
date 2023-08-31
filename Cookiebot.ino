#define SOUND_SPEED 0.0343  /* in centimeter per microseconds */
#define ROOM_WIDTH 500
#define ROOM_LENGTH 600

// Front Side Ultrasonic 
#define FS_TRIG_PIN 3
#define FS_ECHO_PIN 4

// Back Side Ultrasonic 
#define BS_TRIG_PIN 5
#define BS_ECHO_PIN 6

// Left Side Ultrasonic
#define LS_TRIG_PIN 7 
#define LS_ECHO_PIN 8

// Right Side Ultrasonic 
#define RS_TRIG_PIN 9
#define RS_ECHO_PIN 10

 // time the ultra sound go and back in microsecond
unsigned long fsTimeMicroseconds = 0;
unsigned long bsTimeMicroseconds = 0;
unsigned long lsTimeMicroseconds = 0;
unsigned long rsTimeMicroseconds = 0;

 // distance between the obstacle and ultrasonic in cm
unsigned int fsDistanceCentimeters = 0;
unsigned int bsDistanceCentimeters = 0;
unsigned int lsDistanceCentimeters = 0;
unsigned int rsDistanceCentimeters = 0;

// Coordiantes
int x = 0;
int y = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode (FS_TRIG_PIN, OUTPUT);
  pinMode (FS_ECHO_PIN, INPUT);

  pinMode (BS_TRIG_PIN, OUTPUT);
  pinMode (BS_ECHO_PIN, INPUT);

  pinMode (LS_TRIG_PIN, OUTPUT);
  pinMode (LS_ECHO_PIN, INPUT);

  pinMode (RS_TRIG_PIN, OUTPUT);
  pinMode (RS_ECHO_PIN, INPUT);

  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:

  digitalWrite (FS_TRIG_PIN, LOW);
  digitalWrite (BS_TRIG_PIN, LOW);
  digitalWrite (LS_TRIG_PIN, LOW);  
  digitalWrite (RS_TRIG_PIN, LOW);

  /************ Front Side Ultrasonic ************/
  delayMicroseconds (2);

  digitalWrite (FS_TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (FS_TRIG_PIN, LOW);

  fsTimeMicroseconds = pulseIn(FS_ECHO_PIN, HIGH); 
  fsDistanceCentimeters = SOUND_SPEED * (fsTimeMicroseconds / 2);

 /************ Back Side Ultrasonic ************/
  delayMicroseconds (2);

  digitalWrite (BS_TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (BS_TRIG_PIN, LOW);

  bsTimeMicroseconds = pulseIn(BS_ECHO_PIN, HIGH); 
  bsDistanceCentimeters = SOUND_SPEED * (bsTimeMicroseconds / 2);

  /************ Left Side Ultrasonic ************/
  delayMicroseconds (2);

  digitalWrite (LS_TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (LS_TRIG_PIN, LOW);

  lsTimeMicroseconds = pulseIn(LS_ECHO_PIN, HIGH); 
  lsDistanceCentimeters = SOUND_SPEED * (lsTimeMicroseconds / 2);

  /************ Right Side Ultrasonic ************/
  delayMicroseconds (2);

  digitalWrite (RS_TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (RS_TRIG_PIN, LOW);

  rsTimeMicroseconds = pulseIn(RS_ECHO_PIN, HIGH); 
  rsDistanceCentimeters = SOUND_SPEED * (rsTimeMicroseconds / 2);

  /************ Assining x and y Coordinates ************/

  if (bsDistanceCentimeters > (ROOM_LENGTH - fsDistanceCentimeters))
  {
    x = (lsDistanceCentimeters + (ROOM_WIDTH - rsDistanceCentimeters)) / 2;
    y = bsDistanceCentimeters;
  }
  else if ((ROOM_WIDTH - rsDistanceCentimeters) > lsDistanceCentimeters)
  {
    x = ROOM_WIDTH - rsDistanceCentimeters;
    y = (bsDistanceCentimeters + (ROOM_LENGTH - fsDistanceCentimeters)) / 2;
  }
  else if ((ROOM_LENGTH - fsDistanceCentimeters) > bsDistanceCentimeters)
  {
    x = (lsDistanceCentimeters + (ROOM_WIDTH - rsDistanceCentimeters)) / 2;
    y = ROOM_LENGTH - fsDistanceCentimeters;
  }
  else if (lsDistanceCentimeters > (ROOM_WIDTH - rsDistanceCentimeters))
  {
    x = lsDistanceCentimeters;
    y = (bsDistanceCentimeters + (ROOM_LENGTH - fsDistanceCentimeters)) / 2;
  }
  else 
  {
    x = (lsDistanceCentimeters + (ROOM_WIDTH - rsDistanceCentimeters)) / 2;
    y = (bsDistanceCentimeters + (ROOM_LENGTH - fsDistanceCentimeters)) / 2;
  }

  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.println(")");
}
