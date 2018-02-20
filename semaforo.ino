/*
 *Autor: Carlos Omar Rangel Hernández
 *Materia: Sistemas programables
 */

// Se  crean las variables de entradas y salidas 
int boton = 2;        
int verdeA = 11;
int amarilloA = 12;
int rojoA = 13;
int verdeP = 8;
int rojoP = 9;

void setup() {
  // Se inicializan las variables de salida para los leds, y de entrada para el boton.
  pinMode(boton , INPUT);  
  pinMode(verdeA, OUTPUT);
  pinMode(amarilloA, OUTPUT);
  pinMode(rojoA, OUTPUT);
  pinMode(verdeP, OUTPUT);
  pinMode(rojoA, OUTPUT);
  Serial.begin(9600); // El serial para leer el valor del potenciometro en el consola


}

void loop(){
  int estado  = digitalRead(boton);           // Se lee el valor de boton
  if(estado == 0 ){                          // Sí el valor del boton es 0 el led verde de los autos esta encendido, y el rojo de los peatones esta encendido
    digitalWrite(verdeA, HIGH);
    digitalWrite(amarilloA, LOW);
    digitalWrite(rojoA, LOW);
    digitalWrite(verdeP, LOW);
    digitalWrite(rojoP, HIGH);
  }
 
  if((estado == 1)){                          //Sí el valor del boton es 1
    int valor = analogRead(3);                //Se lee el valor del potenciometro
    valor = valor*10;                         //Se multiplica el valor leido por 10
    Serial.println(valor);                    //Se muestra el valor obtenido en la consola
    for(int i = 0;i < 3;i++){                 //Se inicializa un ciclo for para que al momento de de pulsar el boton el led amarrillo parpade 3 veces 
      digitalWrite(verdeA, LOW);              //Se ponen verde autos apagado
      digitalWrite(amarilloA, HIGH);          //Se ponen amarillo encendio
      digitalWrite(rojoA, LOW);               //Se ponen rojo autos apagado
      delay(200);                             //Esto pasa por dos segundos
      digitalWrite(verdeA, LOW);              //Se ponen las tres luces apagadas por 2 segundos
      digitalWrite(amarilloA, LOW);
      digitalWrite(rojoA, LOW);
      delay(200); 
    }
    digitalWrite(verdeA, LOW);                //Se apagan las luces verdes para autos
    digitalWrite(amarilloA, LOW);             //Se apagan las luces amarillas para autos
    digitalWrite(rojoA, HIGH);                //Se enciende las luces rojas para autos
    digitalWrite(verdeP, HIGH);               //Se enciende las luces verdes para peatones
    digitalWrite(rojoP, LOW);                 // se apaga luces rojas para peatones 
    delay(valor);                             // el tiempo depende del valor del potenciometro
    digitalWrite(verdeA, HIGH);               //Se enciende las luces verdes para autos
    digitalWrite(amarilloA, LOW);             //Se apagan las luces amarillas para autos
    digitalWrite(rojoA, LOW);                 //Se apagan las luces rojas para autos
    digitalWrite(verdeP, LOW);                //Se apagan las luces verdes para peatones
    digitalWrite(rojoP, HIGH);                //Se enciende luces rojas para peatones
    delay(5000);                              //No se puede pedir el cambio durante 5 segundos
  }
}
