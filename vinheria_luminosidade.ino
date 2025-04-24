#include <LiquidCrystal.h> // Biblioteca para controle do LCD 16x2 sem I2C

// Definindo os pinos do LCD conectados ao Arduino (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// Definição dos pinos dos sensores e atuadores
const int ldrPin = A0;           // Sensor de luminosidade (LDR) no pino analógico A0
const int ledVerde = 7;          // LED verde no pino digital 7
const int ledAmarelo = 9;        // LED amarelo no pino digital 9
const int ledVermelho = 8;       // LED vermelho no pino digital 8
const int buzzer = 6;            // Buzzer (alarme sonoro) no pino digital 6

void setup() {
  // Configura os LEDs e buzzer como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600); // Inicia comunicação serial para depuração (monitoramento)

  // Inicializa o LCD e exibe mensagem de boas-vindas
  lcd.begin(16, 2); // Define o tamanho do LCD (16 colunas, 2 linhas)
  lcd.setCursor(0, 0); // Define o cursor na primeira linha
  lcd.print("Vinheria Agnello"); // Nome da empresa
  lcd.setCursor(0, 1); // Segunda linha
  lcd.print("Bem-vindo!"); // Mensagem de boas-vindas
  delay(3000); // Espera 3 segundos
  lcd.clear(); // Limpa o LCD após a mensagem inicial
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
  if (luminosidade <= 30) {
    // Ambiente OK
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer); // Buzzer desligado
    lcd.setCursor(0, 1);
    lcd.print("Ambiente OK    "); // Mensagem de ambiente ideal

  } else if (luminosidade > 30 && luminosidade <= 60) {
    // Nível de Alerta
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    tone(buzzer, 1000); // Toca buzzer em 1kHz
    delay(3000); // Buzzer toca por 3 segundos
    noTone(buzzer); // Desliga o buzzer
    lcd.setCursor(0, 1);
    lcd.print("Niv. de Alerta "); // Mensagem de alerta

  } else {
    // Problema grave de luminosidade
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1000); // Buzzer contínuo
    lcd.setCursor(0, 1);
    lcd.print("Problema Lum.  "); // Mensagem de problema grave
  }

  delay(500); // Aguarda meio segundo antes de repetir
}