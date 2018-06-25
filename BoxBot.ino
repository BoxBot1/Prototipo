//Sensores de proximidad:
int trigPin1 = 3;
int echoPin1 = 6;
int trigPin2 = 7;
int echoPin2 = 9;
int trigPin3 = 10;
int echoPin3 = 11;

//Distancias entre el sensor y un obstáculo
float duracion, distancia;
float SensorFrontal, SensorDerecho, SensorIzquierdo;

int pedido = 1;

//Motores
int LM1 = 2;
int LM2 = 8;
int RM1 = 5;
int RM2 = 4;
int VelocidadLM = 13;
int VelocidadRM = 12;

//Funcion para detener el robot
void detener(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

//Funcion para avanzar el robot por un tiempo establecido
void avanzar_hacia_adelante(){
  digitalWrite (RM1, HIGH);
  digitalWrite (RM2, LOW);
  digitalWrite (LM1, HIGH);
  digitalWrite (LM2, LOW);
  analogWrite(VelocidadLM,140);
  delay(50);
  analogWrite(VelocidadRM,140);
  delay(700);
  // Apagamos el motor y esperamos 5 seg
  analogWrite(VelocidadRM,0);
  delay(90);
  analogWrite(VelocidadLM,0);
}

//Funcion para que el robot haga un giro de 90 grados hacia la izquierda
void giro_hacia_la_izquierda(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(VelocidadRM,140);
  delay(382);
  analogWrite(VelocidadRM, 0);
  digitalWrite(RM1, LOW);
}

//Funcion para que el robot haga un giro de 90 grados hacia la derecha
void giro_hacia_la_derecha(){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  analogWrite(VelocidadLM,140);
  delay(500);
  analogWrite(VelocidadLM,0);
  digitalWrite(LM1, LOW);
}

//Funcion de lectura de un solo sensor
void sensor_ultrasonido(int trigPin,int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion/2) / 29.1;
}

//Funcion de lectura de los tres sensores
void lectura_de_sensores(){
  sensor_ultrasonido(trigPin1, echoPin1);
  SensorFrontal = distancia;
  delay(100);
  sensor_ultrasonido(trigPin3, echoPin3);
  SensorDerecho = distancia;
  delay(100);
  sensor_ultrasonido(trigPin2, echoPin2);
  SensorIzquierdo = distancia;

  delay(100);
  
  Serial.print(SensorFrontal);
  Serial.print(" - ");
  Serial.print(SensorDerecho);
  Serial.print(" - ");
  Serial.println(SensorIzquierdo);
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
  if (Serial.available()>0){
      char option = Serial.read();
      if (option == '1'){
        lectura_de_sensores();
        delay(100);
    
        if(SensorFrontal > 30){
          Serial.println("El auto avanza");
          delay(100);
          avanzar_hacia_adelante();
          delay(100);
          lectura_de_sensores();
          delay(100);
          
          if(SensorFrontal > 30){
            Serial.println("El auto avanza");
            delay(100);
            avanzar_hacia_adelante();
            delay(100);
            lectura_de_sensores();
            delay(100);
    
            if(SensorIzquierdo > 30){
              Serial.println("El robot gira la izquierda y luego avanza");
              delay(100);
              giro_hacia_la_izquierda();
              delay(250);
              avanzar_hacia_adelante();
              delay(100);
              lectura_de_sensores();
              delay(100);
    
              if(SensorFrontal > 30){
                Serial.println("El robot avanza hacia adelante y llega su destino");
                delay(100);
                avanzar_hacia_adelante();
                delay(100);
                lectura_de_sensores();
                delay(100);
                }
              }
            }
          else if(SensorIzquierdo > 30){
            Serial.println("El robot gira hacia la izquierda y luego avanza");
            delay(100);
            giro_hacia_la_izquierda();
            delay(100);
            avanzar_hacia_adelante();
            delay(100);
            lectura_de_sensores();
            delay(100);
    
            if (SensorFrontal > 30){
              Serial.println("EL robot avanza hacia adelante y gira hacia la derecha");
              delay(100);
              avanzar_hacia_adelante();
              delay(100);
              giro_hacia_la_derecha();
              delay(100);
              lectura_de_sensores();
              delay(100);
    
              if (SensorFrontal > 30){
                Serial.println("El robot avanza hacia adelante y llega a su destino");
                delay(100);
                avanzar_hacia_adelante();
                delay(100);
                lectura_de_sensores();
                delay(100);
              }
            }
            else if(SensorDerecho > 30){
              Serial.println("El robot gira hacia la derecha y avanza hacia adelante");
              delay(100);
              giro_hacia_la_derecha();
              delay(100);
              avanzar_hacia_adelante();
              delay(100);
              lectura_de_sensores();
              delay(100);
    
              if (SensorIzquierdo > 30){
                Serial.println("El robot gira hacia la izquierda, avanza hacia adelante y llega a su destino");
                delay(100);
                giro_hacia_la_izquierda();
                delay(100);
                avanzar_hacia_adelante();
                delay(100);
                lectura_de_sensores();
                delay(100);
              }
            }
          }
        }
        else if (SensorIzquierdo > 30){
          Serial.println("El robot gira hacia la izquierda y luego avanza hacia adelante");
          delay(100);
          giro_hacia_la_izquierda();
          delay(250);
          avanzar_hacia_adelante();
          delay(100);
          lectura_de_sensores();
          delay(100);
          
          if (SensorFrontal > 30){
            Serial.println("El robot avanza hacia adelante y luego gira hacia la derecha");
            delay(100);
            avanzar_hacia_adelante();
            delay(100);
            giro_hacia_la_derecha();
            delay(100);
            lectura_de_sensores();
            delay(100);
    
            if (SensorFrontal > 30){
              Serial.println("El robot avanza hacia adelante");
              delay(100);
              avanzar_hacia_adelante();
              delay(100);
              lectura_de_sensores();
              delay(100);
    
              if (SensorFrontal > 30){
                Serial.println("El robot avanza hacia adelante y llega a su destino");
                delay(100);
                avanzar_hacia_adelante();
                delay(100);
                lectura_de_sensores();
                delay(100);
                }
              }
            }
          else if(SensorDerecho > 30){
            Serial.println("El robot gira hacia la derecha y luego avanza");
            delay(100);
            giro_hacia_la_derecha();
            delay(250);
            avanzar_hacia_adelante();
            delay(100);
            lectura_de_sensores();
            delay(100);
    
            if (SensorFrontal > 30){
              Serial.println("El robot avanza hacia adelante");
              delay(100);
              avanzar_hacia_adelante();
              delay(100);
              lectura_de_sensores();
              delay(100);
    
              if (SensorFrontal > 30){
                Serial.println("El robot avanza hacia adelante y llega a su destino");
                delay(100);
                avanzar_hacia_adelante();
                delay(100);
                lectura_de_sensores();
                delay(100);
              }
            }
            else if (SensorIzquierdo > 30){
              Serial.println("El robot gira hacia la izquierda y avanza hacia adelante");
              delay(100);
              giro_hacia_la_izquierda();
              delay(100);
              avanzar_hacia_adelante();
              delay(100);
              lectura_de_sensores();
              delay(100);
    
              if (SensorDerecho > 30){
                Serial.println("El robot gira hacia la derecha, avanza hacia adelante y llega a su destino");
                delay(100);
                giro_hacia_la_derecha();
                delay(100);
                avanzar_hacia_adelante();
                delay(100);
                lectura_de_sensores();
                delay(100);
              }
            }
          }
        }
      }
  }
}
