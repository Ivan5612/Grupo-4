
void setup() {
 Serial.begin(9600);

}

void loop() {
int valor_analogico = analogRead (A0);
Serial.println(valor_analogico);

delay(1000);
 
  
}
