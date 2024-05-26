#include <NewPing.h>

#define FTRIGGER_PIN 26 
#define FECHO_PIN 27
#define MAX_DISTANCE 100
#define SONAR_NUM 1

NewPing sonar_front(FTRIGGER_PIN, FECHO_PIN, MAX_DISTANCE);

int k=1;
int preAvg=0;
int alpha;
int avg;

void read_ultrasonic_sensor(void)
{
  alpha=(k-1)/k;
  avg=alpha*preAvg+(1-alpha)*sonar_front.ping_cm();
  preAvg=avg;
  k=k+1;
}

void setup()
{
    Serial.begin(9600);
}



void loop()
{
  read_ultrasonic_sensor();
  Serial.print("재귀 평균 필터:");
  Serial.print(avg);
  Serial.print("   필터 X:");
  Serial.println(sonar_front.ping_cm());
}
