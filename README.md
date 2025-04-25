# Projeto: Monitoramento de Luminosidade - Vinheria Agnello 🍷💡

Este projeto foi desenvolvido para monitorar as condições de luminosidade no ambiente de armazenamento de vinhos, garantindo a qualidade dos produtos da Vinheria Agnello.

## 🎯 Objetivo
Criar um sistema com Arduino que:
- Monitore a luminosidade com um sensor LDR.
- Indique visualmente (LEDs) e sonoramente (buzzer) os níveis de alerta.
- Exiba informações no LCD 16x2.

## 🛠 Componentes Utilizados
- Arduino UNO
- Sensor LDR
- 3 LEDs (Verde, Amarelo, Vermelho)
- Buzzer
- Display LCD 16x2 (sem I2C)
- Potenciômetro (ajuste de contraste do LCD)
- Resistores (10kΩ para LDR e 220Ω para LEDs)

## ⚙ Funcionamento
- *0-10%*: Ambiente OK → LED Verde
- *11-20%*: Nível de Alerta → LED Amarelo + Buzzer apitando
- *20-100%*: Problema → LED Vermelho + Buzzer contínuo
- Exibe mensagens no LCD conforme o estado.

## 🖥 Simulação Tinkercad
https://www.tinkercad.com/things/0qyCnuIpgxx/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=SXRoWm5BGkK9gftt19nlzhL8Y6UM2VbXA1ujkjO1fdk

## 🎥 Vídeo Explicativo
https://youtu.be/d4QD7l57fjA?si=Njd2He4AHcCvhh6q

## 🧠 Dificuldades e Soluções
- Problema de pinos: Ajustado para evitar conflitos entre LCD e buzzer.
- Contraste do LCD: Uso de potenciômetro para ajuste fino.

---
