//Sensores de proximidad:
int trigPin1 = 6;
int echoPin1 = 7;
int trigPin2 = 8;
int echoPin2 = 9;
int trigPin3 = 10;
int echoPin3 = 11;
int duracion, distancia;
int Sensor1, Sensor2, Sensor3;

//La siguiente matriz representa el almacen, donde 0 siginifca casilla desocupada
//y 1 significa casilla ocupada
int almacen[3][3] = {
    {1,0,0},
    {0,0,0},
    {0,0,0}};

//Motores:
int LM1 = 2;
int LM2 = 3;
int RM1 = 4;
int RM2 = 5;

//Programa de lectura del sensor
void sensor_ultrasonido(int trigPin,int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion/2) / 29.1;
}

void avanzar_hacia_adelante(){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  delay(300);
}

void giro_hacia_la_izquierda(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  delay(357);
}

void detener(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void giro_hacia_la_derecha(){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  delay(357);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  
  //Lectura de los sensores de proximidad
  sensor_ultrasonido(trigPin1, echoPin1);
  Sensor1 = distancia;
  sensor_ultrasonido(trigPin2, echoPin2);
  Sensor2 = distancia;
  sensor_ultrasonido(trigPin3, echoPin3);
  Sensor3 = distancia;

  Serial.print(Sensor1);
  Serial.print(" - ");
  Serial.print(Sensor2);
  Serial.print(" - ");
  Serial.print(Sensor3);

  if (sensor1 > 30 && sensor 2 > 30){
    avanzar_hacia_adelante();
    delay(500);
    if (sensor1 > 30 && sensor 2 > 30){
      avanzar_hacia_adelante();
      giro_hacia la izquierda();
      delay(500);
      if (sensor1 > 30){
        avanzar_hacia_adelante();
        if (sensor 1 >30 && sensor2 > 30){
          avanzar_hacia_adelante();
          if (sensor 1 >30 && sensor2 > 30){
            avanzar_hacia_adelante();
            }
            else if(sensor 1 > 30 && sensor2 <30){
              avanzar_hacia_adelante();
              }
            }
        else if(sensor 1 > 30 && sensor2 <30){
          avanzar_hacia_adelante();
          if (sensor 1 >30 && sensor2 > 30){
            avanzar_hacia_adelante();
            }
          else if(sensor 1 > 30 && sensor2 <30){
            avanzar_hacia_adelante();
            }
          }
      }
    }
    else if(sensor1 > 30  && sensor2 < 30){
      avanzar_hacia_adelante();
      delay(500);
    }
    else if(sensor1 < 30  && sensor2 > 30){
      giro_hacia la izquierda();
      avanzar_hacia_adelante();
      delay(500);
    }
  }
  else if(sensor1 >30  && sensor2 < 30){
    avanzar_hacia_adelante();
    delay(500);
  }
  else if(sensor2 > 30  && sensor2 > 30){
    giro_hacia la izquierda();
    avanzar_hacia_adelante();
    delay(500);
  }
  
}
