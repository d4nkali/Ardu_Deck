/*

  Programa do Ardu Deck com Arduino Pro Micro
  Autor: d4nkali 

*/

// Inclusão da biblioteca

  #include <HID-Project.h>

// Definindo os pinos

  #define led LED_BUILTIN // Define o pino digital 13 como led

  // Botões dos Comandos

    #define botao_1 2 // Define o pino digital 2 como botão 1 do gerenciador de tarefas
    #define botao_2 3 // Define o pino digital 3 como botão 2 do cmd
    #define botao_3 4 // Define o pino digital 4 como botão 3 do explorador de arquivos
    #define botao_4 5 // Define o pino digital 5 como botão 4 de encerrar programas 
    #define botao_5 6 // Define o pino digital 6 como botão 5 do bloco de notas 
    #define botao_6 7 // Define o pino digital 7 como botao 6 das configuraçoes rapidas
    #define botao_7 8 // Define o pino digital 8 como botao 7 das configuraçoes do PC
    #define botao_8 9 // Define o pino digital 9 como botao 8 as notificações do PC

  // Botões de Controle de Volume

    #define botao_mute 10 // Define o pino digital 10 como botao de mutar o volume do PC
    #define botao_menos 16 // Define o pino digital 16 como botao de diminuir o volume do PC
    #define botao_mais 14 // Define o pino digital 14 como botao de aumentar o volume do PC

  // Botões de Controle de Midia

    #define botao_voltar 15 // Define o pino digital 15 como botao de voltar a midia do PC
    #define botao_pause_rep A0  // Define o pino analogico A0 como botao de pausar ou reproduzir a midia do PC
    #define botao_avancar A1  // Define o pino analogico A1 como botao de avançar a midia do PC

void setup() {

  pinMode(led, OUTPUT); // Configura o pino do led como saida 

  // Botões dos Comandos como entrada com resistor pull-up

    pinMode(botao_1, INPUT_PULLUP); 
    pinMode(botao_2, INPUT_PULLUP); 
    pinMode(botao_3, INPUT_PULLUP); 
    pinMode(botao_4, INPUT_PULLUP); 
    pinMode(botao_5, INPUT_PULLUP); 
    pinMode(botao_6, INPUT_PULLUP); 
    pinMode(botao_7, INPUT_PULLUP); 
    pinMode(botao_8, INPUT_PULLUP); 

  // Botões de Contorle de Volume como entrada com resistor pull-up
  
    pinMode(botao_mute, INPUT_PULLUP); 
    pinMode(botao_menos, INPUT_PULLUP); 
    pinMode(botao_mais, INPUT_PULLUP); 

  // Botões de Controle de Midia como entrada com resistor pull-up
  
    pinMode(botao_voltar, INPUT_PULLUP); 
    pinMode(botao_pause_rep, INPUT_PULLUP); 
    pinMode(botao_avancar, INPUT_PULLUP); 

  Keyboard.begin(); // Inicializa os componentes do teclado
  Consumer.begin(); // Inicializa os componentes das teclas de midia

}

void loop() {



}

// FIM!