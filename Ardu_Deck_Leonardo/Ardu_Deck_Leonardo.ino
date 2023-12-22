/*

  Programa do Ardu Deck com Arduino Leornado
  Autor: d4nkali 21/12/2023 v1.0

*/

// Inclusão da biblioteca

  #include <HID-Project.h>

// Definindo os pinos

  #define led LED_BUILTIN // Define o pino digital 13 como led

  // Botões dos Comandos

    #define botao_1 12 // Define o pino digital 12 como botão 1 do gerenciador de tarefas
    #define botao_2 11 // Define o pino digital 11 como botão 2 do cmd
    #define botao_3 10 // Define o pino digital 10 como botão 3 do explorador de arquivos
    #define botao_4 9 // Define o pino digital 9 como botão 4 de encerrar programas 
    #define botao_5 8 // Define o pino digital 8 como botão 5 do bloco de notas 
    #define botao_6 7 // Define o pino digital 7 como botao 6 das configuraçoes rapidas
    #define botao_7 6 // Define o pino digital 6 como botao 7 das configuraçoes do PC
    #define botao_8 5 // Define o pino digital 5 como botao 8 as notificações do PC

  // Botões de Controle de Volume

    #define botao_mute 4 // Define o pino digital 4 como botao de mutar o volume do PC
    #define botao_menos 3 // Define o pino digital 3 como botao de diminuir o volume do PC
    #define botao_mais 2 // Define o pino digital 2 como botao de aumentar o volume do PC

  // Botões de Controle de Midia

    #define botao_voltar A0 // Define o pino analogico A0 como botao de voltar a midia do PC
    #define botao_pause_rep A1  // Define o pino analogico A0 como botao de pausar ou reproduzir a midia do PC
    #define botao_avancar A2  // Define o pino analogico A0 como botao de avançar a midia do PC

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

  // Executar Comandos de Teclado

    // Abrir Gerenciador de tarefas

    if (digitalRead(botao_1) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  // Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led  
    
      Keyboard.press(KEY_LEFT_SHIFT); // Pressiona a tecla Shift
      Keyboard.press(KEY_LEFT_CTRL); // Pressiona a tecla Ctrl
      Keyboard.press(KEY_ESC); // Pressiona a tecla Esc
      delay(100); // Aguarda um tempo para soltar as teclas
      Keyboard.releaseAll(); // Solta todas as teclas
    
      delay(3000); // Aguarda um tempo para o Gerenciador de tarefas aparecer
      digitalWrite(led, LOW); // Desliga o led

    }

    // Abrir o CMD

    if (digitalRead(botao_2) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  //Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar/Super
      Keyboard.press('r');  // Pressiona a tecla R
      Keyboard.releaseAll();  // Solta todas as teclas
    
      delay(2000);  // Aguarda um tempo para a janela Executar aparecer
    
      Keyboard.print("cmd");  // Digita "cmd" na janela Executar    
      Keyboard.press(KEY_RETURN);  // Pressiona a tecla Enter para executar o comando
      Keyboard.releaseAll();  // Solta todas as teclas
        
      delay(5000);  // Aguarda um tempo para o prompt de comando aparecer
      digitalWrite(led, LOW); // Desliga o led
    
    }

    // Abrir o Explorer

    if (digitalRead(botao_3) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  // Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar/Super
      Keyboard.press('e');  // Pressiona a tecla E
      Keyboard.releaseAll();  // Solta todas as teclas
    
      delay(3000);  // Aguarda um tempo para a janela do Explorador aparecer
      digitalWrite(led, LOW); // Desliga o led    
    
    }

    // Fechar Janela

    if (digitalRead(botao_4) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  // Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_ALT);  // Pressiona a tecla Alt
      Keyboard.press(KEY_F4);  // Pressiona a tecla F4
      Keyboard.releaseAll();  // Solta todas as teclas
    
      delay(3000);  // Aguarda um tempo para a janela fechar
      digitalWrite(led, LOW); // Desliga o led    
    
    }

    // Abrir Notepad

    if (digitalRead(botao_5) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  //Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar/Super
      Keyboard.press('r');  // Pressiona a tecla R
      Keyboard.releaseAll();  // Solta todas as teclas
    
      delay(2000);  // Aguarda um tempo para a janela Executar aparecer
    
      Keyboard.print("notepad");  // Digita "cmd" na janela Executar    
      Keyboard.press(KEY_RETURN);  // Pressiona a tecla Enter para executar o comando
      Keyboard.releaseAll();  // Solta todas as teclas
        
      delay(5000);  // Aguarda um tempo para o prompt de comando aparecer
      digitalWrite(led, LOW); // Desliga o led
    
    }

    // Menu de Configurações Rapidas

    if (digitalRead(botao_6) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  //Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar/Super
      Keyboard.press('a');  // Pressiona a tecla A
      Keyboard.releaseAll();  // Solta todas as teclas

      delay(2000);  // Aguarda um tempo para as configurações rapidas aparecer
      digitalWrite(led, LOW); // Desliga o led
    
    }

    // Abrir as Configurações Gerais do PC

    if (digitalRead(botao_7) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  //Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar/Super
      Keyboard.press('i');  // Pressiona a tecla I
      Keyboard.releaseAll();  // Solta todas as teclas

      delay(2000);  // Aguarda um tempo para as configurações aparecer
      digitalWrite(led, LOW); // Desliga o led
    
    }

    // Abre o Menu Notificações

    if (digitalRead(botao_8) == LOW) {  // Se o botão estiver pressionado, então:
  
      delay(150);  //Aguarda um curto período para evitar debounce
      digitalWrite(led, HIGH); // Liga o led
    
      Keyboard.press(KEY_LEFT_GUI);  // Pressiona a tecla Windows/Iniciar/Super
      Keyboard.press('n');  // Pressiona a tecla N
      Keyboard.releaseAll();  // Solta todas as teclas

      delay(2000);  // Aguarda um tempo para as notificações aparecerem
      digitalWrite(led, LOW); // Desliga o led
    
    }

  // Controle de volume 

    // Silenciar o Volume

    if (digitalRead(botao_mute) == LOW) { // Se o botão de mudo for precionado, então:

      Consumer.write(MEDIA_VOLUME_MUTE); // Emula a tecla de mudo
      digitalWrite(LED_BUILTIN, HIGH);  // Liga o led
      delay(500); // Aguarda 0,5 s
      digitalWrite(LED_BUILTIN, LOW); // Desliga o led

    }

    // Diminuir o Volume

    if (digitalRead(botao_menos) == LOW) { // Se o botão de menos for precionado, então:

      Consumer.write(MEDIA_VOLUME_DOWN); // Emula a tecla de abaixar o volume
      digitalWrite(LED_BUILTIN, HIGH);  // Liga o led
      delay(150); // Aguarda 150 ms
      digitalWrite(LED_BUILTIN, LOW); // Desliga o led

    }

    // Aumentar Volume

    if (digitalRead(botao_mais) == LOW) { // Se o botão de mais for precionado, então:

      Consumer.write(MEDIA_VOLUME_UP); // Emula a tecla de aumentar o volume
      digitalWrite(LED_BUILTIN, HIGH); // Liga o led
      delay(150); // Aguarda 150 ms
      digitalWrite(LED_BUILTIN, LOW); // Desliga o led

    }

  // 

}

// FIM!