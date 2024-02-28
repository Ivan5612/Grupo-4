int cupos_disponibles = 8; 
long int valor_recaudado = 0;
int costo= 5000;

bool subida1,subida2;
const int botonIngresoPin = D7;  
const int botonEgresoPin = D1;  
const int ledVerdePin = D5;      
const int ledRojoPin = D6;       

int ingreso=0;
int egreso=0;

void setup() {
  pinMode(botonIngresoPin, INPUT);
  pinMode(botonEgresoPin, INPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("CUPO MAXIMO: 7");
}

void loop() {
  ingreso=digitalRead(botonIngresoPin);
  egreso=digitalRead(botonEgresoPin);
  
  if(ingreso==1 && cupos_disponibles>0 && subida1==0){
    cupos_disponibles=cupos_disponibles-1;
    Serial.print("Cupos: ");
    Serial.print(cupos_disponibles);
    Serial.print("\tRecaudo = $");
    Serial.print(valor_recaudado);
    Serial.println(" COP");
    delay(100);
  }
  subida1=digitalRead(botonIngresoPin);
  
  if(egreso==HIGH && cupos_disponibles<7 && subida2==0){
    cupos_disponibles=cupos_disponibles+1;
    valor_recaudado=valor_recaudado+5000;
    Serial.print("Cupos: ");
    Serial.print(cupos_disponibles);
    Serial.print("\tRecaudo = $");
    Serial.print(valor_recaudado);
    Serial.println(" COP");
    delay(100);
  }
  subida2=digitalRead(botonEgresoPin);
  
  if(cupos_disponibles>0 && cupos_disponibles<=7){
    digitalWrite(ledRojoPin,LOW);
    digitalWrite(ledVerdePin,HIGH);
  }  
  
  if(cupos_disponibles==0){
    digitalWrite(ledVerdePin,LOW);
    digitalWrite(ledRojoPin,HIGH);
  }
 
  delay(100); 

}
