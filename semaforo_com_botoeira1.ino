int carroVermelho = 13; 
int carroAmarelo = 12; 
int carroVerde = 11; 
int pessoaVerde = 2;
int pessoaVermelho = 3; 
int botao = 7;
int tempoAtravessando = 5000;
unsigned long mudaTempo;
 
void setup() {
  
  mudaTempo = millis();
  
  pinMode(carroVermelho, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(pessoaVermelho, OUTPUT);
  pinMode(pessoaVerde, OUTPUT);
  pinMode(botao, INPUT);
  
  
  digitalWrite(carroVerde, HIGH);
  digitalWrite(pessoaVermelho, HIGH);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(pessoaVerde, LOW);
  Serial.begin(9600);
}
 
void loop() {
  
  
  int estado = digitalRead(botao);
  delay(50);
  Serial.println(estado);
  
  // Se o botão está sendo pressionado E se já passou 5 segundos desde a última pressão.
  
  if (estado == HIGH && (millis() - mudaTempo) > 5000) {
    
    //Então SE SIM, executa a função de mudar o estado das luzes abaixo:
    mudaLuzes();
  }
}
 
void mudaLuzes() {
  digitalWrite(carroVerde, LOW);    // A luz verde é desligada
  digitalWrite(carroAmarelo, HIGH); // A luz amarela vai ligar por 4 segundos
  delay(4000); 
  
  digitalWrite(carroAmarelo, LOW); // A luz amarela vai desligar
  digitalWrite(carroVermelho, HIGH); // A luz vermelha vai ligar por 5 segundos
 
  digitalWrite(pessoaVermelho, LOW);
  digitalWrite(pessoaVerde, HIGH);
  delay(tempoAtravessando);
  
  // Pisca a luz verde dos PEDESTRES
  for (int x=0; x<10; x++) {
    digitalWrite(pessoaVerde, LOW);
    delay(160);
    digitalWrite(pessoaVerde, HIGH);
    delay(160);
  }
  digitalWrite(pessoaVerde, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pessoaVermelho, HIGH);
  digitalWrite(carroVerde, HIGH);
 
  mudaTempo = millis();
 }