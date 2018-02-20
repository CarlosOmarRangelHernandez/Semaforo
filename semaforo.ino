/*
 *Autor: Carlos Omar Rangel Hernández
 *Materia: Sistemas programables
 */

// Se  crean las variables de entradas y salidas 
int boton = 2;        
int verdeAutos = 11;
int amarilloAutos = 12;
int rojoAutos = 13;
int verdePeatones = 8;
int rojoPeatones = 9;

void setup() {
  // Se inicializan las variables de salida para los leds, y de entrada para el boton.
  pinMode(boton , INPUT);  
  pinMode(verdeAutos, OUTPUT);
  pinMode(amarilloAutos, OUTPUT);
  pinMode(rojoAutos, OUTPUT);
  pinMode(verdePeatones, OUTPUT);
  pinMode(rojoAutos, OUTPUT);
  Serial.begin(9600); // El serial para leer el valor del potenciometro en el consola


}

void loop(){
  int estado  = digitalRead(boton);           // Se lee el valor de boton
  if(estado == 0 ){                          // Sí el valor del boton es 0 el led verde de los autos esta encendido, y el rojo de los peatones esta encendido
    digitalWrite(verdeAutos, HIGH);
    digitalWrite(amarilloAutos, LOW);
    digitalWrite(rojoAutos, LOW);
    digitalWrite(verdePeatones, LOW);
    digitalWrite(rojoPeatones, HIGH);
  }
 
  if((estado == 1)){                          //Sí el valor del boton es 1
    int valor = analogRead(3);                //Se lee el valor del potenciometro
    valor = valor*10;                         //Se multiplica el valor leido por 10
    Serial.println(valor);                    //Se muestra el valor obtenido en la consola
    for(int i = 0;i < 3;i++){                 //Se inicializa un ciclo for para que al momento de de pulsar el boton el led amarrillo parpade 3 veces 
      digitalWrite(verdeAutos, LOW);              //Se ponen verde autos apagado
      digitalWrite(amarilloAutos, HIGH);          //Se ponen amarillo encendio
      digitalWrite(rojoAutos, LOW);               //Se ponen rojo autos apagado
      delay(200);                             //Esto pasa por dos segundos
      digitalWrite(verdeAutos, LOW);              //Se ponen las tres luces apagadas por 2 segundos
      digitalWrite(amarilloAutos, LOW);
      digitalWrite(rojoAutos, LOW);
      delay(200); 
    }
    digitalWrite(verdeAutos, LOW);                //Se apagan las luces verdes para autos
    digitalWrite(amarilloAutos, LOW);             //Se apagan las luces amarillas para autos
    digitalWrite(rojoAutos, HIGH);                //Se enciende las luces rojas para autos
    digitalWrite(verdePeatones, HIGH);               //Se enciende las luces verdes para peatones
    digitalWrite(rojoPeatones, LOW);                 // se apaga luces rojas para peatones 
    delay(valor);                             // el tiempo depende del valor del potenciometro
    digitalWrite(verdeAutos, HIGH);               //Se enciende las luces verdes para autos
    digitalWrite(amarilloAutos, LOW);             //Se apagan las luces amarillas para autos
    digitalWrite(rojoAutos, LOW);                 //Se apagan las luces rojas para autos
    digitalWrite(verdePeatones, LOW);                //Se apagan las luces verdes para peatones
    digitalWrite(rojoPeatones, HIGH);                //Se enciende luces rojas para peatones
    delay(5000);                              //No se puede pedir el cambio durante 5 segundos
  }
}
