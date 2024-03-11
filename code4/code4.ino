//#code 1
int value=77;
void setup(){
  Serial.begin(9600);
  Serial.print("DEC:");
  Serial.println(value); 
  Serial.print("BIN:");
  Serial.println(value, BIN);
  Serial.print("OCT:");
  Serial.println("value, OCT");
  Serial.print("HEX:");
  Serial.print(value, HEX);
}

void loop(){

}
