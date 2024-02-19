bool A,B,C,D,W,X,Y,Z;
void setup() {
  // put your setup code here, to run once:
pinMode (D4,OUTPUT);
pinMode (D3,OUTPUT);
pinMode (D2,OUTPUT);
pinMode (D1,OUTPUT);
pinMode (D8,INPUT);
pinMode (D7,INPUT);
pinMode (D6,INPUT);
pinMode (D5,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
A=digitalRead(D5);

B=digitalRead(D6);

C=digitalRead(D7);

D=digitalRead(D8);

W= C&&(A||B)||D&&(B||!A&&!C);
digitalWrite (D4,!W);

X=!D&&(A||C)||!A&&!C&&D||A&&B&&C;
digitalWrite (D3,X);

Y=C&&!(B^D)||!A&&D&&(B||C)||A&&!C&&!D;
digitalWrite (D2,Y);

Z=B&&(A^C)||A&&!B&&!D||C&&D;
digitalWrite(D1,Z);
}
