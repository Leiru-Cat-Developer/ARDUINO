/*
  ARDUINO A CONTROL REMOTO

  Antes de cargar el código, tenemos que instalar una librería, la cual está en el siguiente LINK, es para AFMotor:
  - https://learn.adafruit.com/adafruit-motor-shield/library-install
  Si lo deseas, otra manera de instalar la librería es descargarla, abrir ARDUINO IDE, ir a PROGRAMA, INCLUIR LIBRERÍA, AÑADIR ZIP y SELECCIONAR EL ARCHIVO,
  cuando tengas todo listo ahora podrás compilar el código correctamente.

  También puedes buscar directamente la librería en PROGRAMA, INCLUIR LIBRERÍA y ADMINISTRAR BIBLIOTECAS, esto por que diversas páginas en internet te muestran
  como es que debes buscar la librería en dicho apartado y hacer la descarga mucho más sencilla, además de que tendrás acceso a una amplica gama de versiones
  de la misma librería.

  NOTA:
  Desconecta el modulo Bluetooth antes de darle al botón de cargar programa o de otra manera tendrás errores de compilación.
*/
#include <AFMotor.h>

//INICIALIZACIÓN DE LOS PINES DE LOS MOTORES
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 

void setup() 
{       
  Serial.begin(9600);  //COLOCA LA TASA DE BAUDIOS A TU MODULO BLUETOOTH
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //INICIALIZA CON LOS MOTORES APAGADOS
    /*
      CAMBIA A PIN_MODE SOLO SI UN NUEVO COMANDO ES DIFERENTE AL ANTERIOR

      VISUALIZA EL CAMBIO DE LOS PINES: Serial.println(command);
    */
    switch(command){
    case 'F': //FORWARD O ADELANTE
      forward();
      break;
    case 'B': //BACK O ATRAS
      back();
      break;
    case 'L': //LEFT O IZQUIERDA
      left();
      break;
    case 'R': //RIGHT O DERECHA
      right();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor1.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor2.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor2.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor3.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor3.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor4.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor4.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
}

void back()
{
  motor1.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor1.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor2.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor2.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor3.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor3.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor4.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor4.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
}

void left()
{
  motor1.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor1.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor2.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor2.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor3.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor3.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor4.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor4.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
}

void right()
{
  motor1.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor1.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor2.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor2.run(FORWARD);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor3.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor3.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor4.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor4.run(BACKWARD); //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
} 

void Stop()
{
  motor1.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor1.run(RELEASE);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor2.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor2.run(RELEASE);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor3.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor3.run(RELEASE);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
  motor4.setSpeed(255); //DEFINE LA VELOCIDAD MAXIMA
  motor4.run(RELEASE);  //ROTA EL MOTOR EN SENTIDO A LAS MANECILLAS DEL RELOJ
}
