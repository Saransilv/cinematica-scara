#include <Servo.h>
Servo servo1;
Servo servo2;
int a1, a2, ang1,ang2;
float X,Y,a;
int pontosx = 0;
int pontosy = 1;
int l1 = 9;
int l2 = 8;
float cordenadas[] = {};//acrescentar as coordenadas do seu desenho
void setup()
{
  servo1.attach(9);
  servo2.attach(10);
  Serial.begin(9600);
  servo1.write(0);
  servo2.write(180-0);
  Serial.println("Continue a nadar...."); // alerta de que o programa comecou
  delay(200);
}

void loop() {
      X = cordenadas[pontosx];
      Y = cordenadas[pontosy];
      a = sqrt(X*X+Y*Y);
      a1 = acos(X/a) - acos(((X*X+Y*Y)+(l1*l1)-(l2*l2))/(l2*a));
      ang1 = a1*(180/M_PI);
      a2 = acos(((l1*l1)+(l2*l2)-(X*X+Y*Y))/(2*l1*l2));
      ang2 = a2*(180/M_PI);
      servo1.write(ang1);
  servo2.write(180-ang2);
   delay(500);
  Serial.println((String)"Posicao do proximo ponto (x, y) do desenho no array: ["+X+"] e ["+Y+"]");
    Serial.println((String )"Novo ponto (x, y) alcancado com sucesso atraves dos angulos: ["+ang1+"] e ["+ang2+"]");
    delay(150);
	pontosx = pontosx+2;
	pontosy = pontosy+2;
     }
  
