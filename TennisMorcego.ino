

#define echoPin   13                                       // Pino 13 recebe o pulso do echo
#define trigPin   12                                       // Pino 12 envia o pulso para gerar o echo
#define vibraPin  11                                       // Pino 11 saida sinal para motor vibra
#define led1Pin   10                                       // Pino 10 saida LED 1
#define led2Pin   9                                        // Pino 9  saida LED 2
#define led3Pin   8                                        // Pino 8  saida LED 3
#define led4Pin   7                                        // Pino 7  saida LED 4
#define BuzzerPin 6                                        // Pino 6  saida Buzzer

void setup()
{
   Serial.begin(9600);                                     // Inicia a porta serial
   pinMode(echoPin,   INPUT);                              // Define o pino 13 como entrada (recebe)
   pinMode(trigPin,   OUTPUT);                             // Define o pino 12 como saida (envia)
   pinMode(vibraPin,  OUTPUT);                             // Define o pino 11 como saida
   pinMode(led1Pin,   OUTPUT);                             // Define o pino 10 como saida LED 1
   pinMode(led2Pin,   OUTPUT);                             // Define o pino 9  como saida LED 2
   pinMode(led3Pin,   OUTPUT);                             // Define o pino 8  como saida LED 3
   pinMode(led4Pin,   OUTPUT);                             // Define o pino 7  como saida LED 4
   pinMode(BuzzerPin, OUTPUT);                             // Define o pino 6  como saida Buzzer
}  
  
void loop()  
 {    
    digitalWrite(trigPin, LOW);                             // Seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    delayMicroseconds(2);                                   // Delay de 2 microssegundos
    digitalWrite(trigPin, HIGH);                            // Seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    delayMicroseconds(10);                                  // Delay de 10 microssegundos
    digitalWrite(trigPin, LOW);                             // Seta o pino 12 com pulso baixo novamente
    long duration = pulseIn(echoPin,HIGH);                  // PulseInt lê o tempo entre a chamada e o pino entrar em high
 
    long distancia = duration /29 / 2 ;                     // Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado,
                                                            // porque é o tempo de ida e volta do ultrassom
    
    
    if(distancia <= 75)                                     // Distância menor ou igual a 75
     {
      digitalWrite(vibraPin,  HIGH);
      digitalWrite(led3Pin,   HIGH);
      digitalWrite(BuzzerPin, HIGH);
      delay(250);
      digitalWrite(vibraPin,  LOW);
      digitalWrite(led3Pin,   LOW);
      digitalWrite(BuzzerPin, LOW);
      delay(100);
     }
     
    else if(distancia <= 150 && distancia > 75)             // Distância menor ou igual a 150 e Distâcia maior 75
     {
      digitalWrite(vibraPin, HIGH);
      digitalWrite(led2Pin,  HIGH);
      delay(500);
      digitalWrite(vibraPin, LOW);
      digitalWrite(led2Pin,  LOW);
      delay(250);
     }
     
    else if(distancia <= 250 && distancia > 150)             // Distância menor ou igual a 250 e Distância maior 150
     {
      digitalWrite(vibraPin, HIGH);
      digitalWrite(led1Pin,  HIGH);
      delay(1000);
      digitalWrite(vibraPin, LOW);
      digitalWrite(led1Pin,  LOW);
      delay(500);
     }
     
    else if(distancia > 250)                                  // Distância maior que 250
     {
       digitalWrite(vibraPin, LOW);
       digitalWrite(led4Pin,  HIGH);
       delay(50);
       digitalWrite(led4Pin,  LOW);
       delay(1000);
     }


Serial.print("Tennis Morcego informa Distancia em CM: ");
Serial.println(distancia);
delay(10);                                                     // Espera 10 milisegundo para fazer a leitura novamente
  }

