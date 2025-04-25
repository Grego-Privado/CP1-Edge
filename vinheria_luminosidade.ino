#include <LiquidCrystal.h> // Biblioteca para controle do LCD 16x2 sem I2C

// Definindo os pinos do LCD conectados ao Arduino (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// desenhando os bytes:
byte z0 [8] = {
  
  B00000,
  B11111,
  B01111,
  B00011,
  B00001,
  B00000,
  B00000,
};
  
byte z1[8] = {
  
  
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B10000,
  B00011,
  B00111,
};

byte z2[8] = {
  
  
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B00111,
  B11111,
  B11111,
};

byte z3[8] = {
  
  
  B00000,
  B11111,
  B11110,
  B11100,
  B11000,
  B10000,
  B10000,
  B00000,
};

byte z4[8] = {
 
  B00000,
  B00000,
  B00001,
  B00011,
  B00111,
  B01111,
  B11111,
  
};

byte z5[8] = {
  
  B01111,
  B11111,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  
};

byte z6[8] = {
  
  B11111,
  B11110,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  
};

byte z7[8] = {
  
  B00000,
  B00000,
  B10000,
  B11000,
  B11100,
  B11110,
  B11111,
  
};

byte ok1[8] = {
  
  B00000,
  B00000,
  B00000,
  B00011,
  B01110,
  B01100,
  B11000,
  B11000,
  
};

byte ok1_2[8] = {
  
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00001,
  B00001,
  B00011,
  
};

byte ok2[8] = {
  
  B00000,
  B00000,
  B00000,
  B11000,
  B01110,
  B00110,
  B00011,
  B00011,
  
};

byte ok3[8] = {
  
  B00011,
  B00011,
  B00110,
  B01110,
  B11000,
  B00000,
  B00000,
  B00000,
  
};

byte ok3_2[8] = {
  
  B00010,
  B10110,
  B11100,
  B01000,
  B00000,
  B11111,
  B00000,
  B00000,
  
};

byte ok4[8] = {
  
  B11011,
  B11001,
  B01100,
  B01110,
  B00011,
  B00000,
  B00000,
  B00000,
  
};

// Definição dos pinos dos sensores e atuadores
const int ldrPin = A0;           // Sensor de luminosidade (LDR) no pino analógico A0
const int ledVerde = 7;          // LED verde no pino digital 7
const int ledAmarelo = 8;        // LED amarelo no pino digital 9
const int ledVermelho = 9;       // LED vermelho no pino digital 8
const int buzzer = 6;            // Buzzer (alarme sonoro) no pino digital 6

void setup() {
  // Configura os LEDs e buzzer como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // inicializando o LCD e animando a logo
  lcd.begin(1,2);                                
  lcd.setCursor(0,0);           
  lcd.setCursor(0,1);           
  // criando os chars
  lcd.createChar(0, z0);
  lcd.createChar(1, z1);
  lcd.createChar(2, z2);
  lcd.createChar(3, z3);
  lcd.createChar(4, z4);
  lcd.createChar(5, z5);
  lcd.createChar(6, z6);
  lcd.createChar(7, z7);
  
  lcd.display();
  
  for(int i = 0;i < 4; i++){ // printando parte de cima do "Z"
    lcd.setCursor(i, 0);
      lcd.write(byte(i));
      delay(80);
  }
  
  // printando parte de baixo do "Z"
  lcd.setCursor(0, 1);
  lcd.write(byte(4));
  delay(80);
  
  lcd.setCursor(1, 1);
  lcd.write(byte(5));
  delay(80);
  
  lcd.setCursor(2, 1);
  lcd.write(byte(6));
  delay(80);
  
  lcd.setCursor(3, 1);
  lcd.write(byte(7));
  delay(80);
  
  for (int j = 0; j < 2; j++) { // quantidade de vezes que o "Z" vai ir e voltar
  for (int i = 0; i < 12; i++) {// fazendo o "Z" percorrer a tela
    lcd.scrollDisplayRight(); // indo para a direita
    delay(80);
  }

  delay(100);  // pausa antes de voltar

  for (int i = 0; i < 12; i++) { // indo para a esquerda
    lcd.scrollDisplayLeft();
    delay(80);
  }
}
  // printando nome do time
  lcd.print("e");
  delay(100);
  lcd.print("t");
  delay(100);
  lcd.print("t");
  delay(100);
  lcd.print("a");
  delay(100);
  lcd.print(" ");
  delay(100);
  lcd.print("W");
  delay(100);
  lcd.print("o");
  delay(100);
  lcd.print("r");
  delay(100);
  lcd.print("k");
  delay(100);
  lcd.print("s");
  delay(3000);
  
  for(int i = 13;i >= 0; i--) { //nome do time e parte de baixo do "Z" desaparecendo da tela
    lcd.setCursor(i, 1);
      lcd.print(" ");
      delay(100);
}
  // resto do "Z" desaparecendo
  lcd.setCursor(3,0);
  lcd.print(" ");
  delay(100);
  
  lcd.setCursor(2,0);
  lcd.print(" ");
  delay(100);
  
  lcd.setCursor(1,0);
  lcd.print(" ");
  delay(100);
    
  lcd.setCursor(0,0);
  lcd.print(" ");
  delay(100);
    


  Serial.begin(9600); // Inicia comunicação serial para depuração (monitoramento)
}


void loop() {
  // Lê o valor da luminosidade do ambiente através do LDR
  int leituraLDR = analogRead(ldrPin); 
  int luminosidade = map(leituraLDR, 0, 1023, 0, 100); // Converte para 0 a 100%
  Serial.print("Luminosidade: ");
  Serial.print(luminosidade);
  Serial.println("%");

  // Exibe o valor da luminosidade no LCD
  lcd.setCursor(0, 0); // Primeira linha
  lcd.print("Luz: ");
  lcd.print(luminosidade); // Mostra a luminosidade em %
  lcd.print("%     "); // Espaço extra para apagar valores antigos

  // Verifica a faixa de luminosidade e aciona LEDs/buzzer/mensagem correspondente
  if (luminosidade <= 10) {
    // Ambiente OK
    
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer); // Buzzer desligado
    lcd.setCursor(0, 1);
    lcd.print("Ambiente OK    "); // Mensagem de ambiente ideal

  } else if (luminosidade > 10 && luminosidade <= 20) {
    // Nível de Alerta
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    
    tone(buzzer, 1000); // Toca buzzer em 1kHz
    delay(50); // Buzzer toca por 0,05 segundos
    
    noTone(buzzer); // Desliga o buzzer
    
    lcd.setCursor(0, 1);
    lcd.print("Niv. de Alerta"); // Mensagem de alerta

  } else {
    // Problema grave de luminosidade
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 10000); // Buzzer
    delay(500);
    noTone(buzzer); // Desliga o buzzer
    lcd.setCursor(0, 1);
    lcd.print("Luz critica!"); // Mensagem de problema grave
  }

  delay(500); // Aguarda meio segundo antes de repetir
}