
  #define ch1 3
  #define ch2 4
  #define botao1 8
  #define botao2 9
  int leitura_ch1;
  int leitura_ch2;
  int status_ch1 = 1;
  int status_ch2 = 1;
   
  void setup() {
    Serial.begin(9600);
    pinMode(ch1, OUTPUT);
    pinMode(botao1, INPUT);
    digitalWrite(ch1, HIGH);
    pinMode(ch2, OUTPUT);
    pinMode(botao2, INPUT);
    digitalWrite(ch2, HIGH);  }

  void Controle() {
     Canal_01:
     leitura_ch1 = digitalRead(botao1);
     if (leitura_ch1 != 0)
     { while(digitalRead(botao1) != 0)
     delay(100);
     status_ch1 = !status_ch1;
     digitalWrite(ch1, status_ch1); }
     
     Canal_02:
     leitura_ch2 = digitalRead(botao2);
     if (leitura_ch2 != 0)
     { while(digitalRead(botao2) != 0)
     delay(100);
     status_ch2 = !status_ch2;
     digitalWrite(ch2, status_ch2); }
     }
  
  void loop() {
    
  Controle();  
    
  char caracter = Serial.read();
  if(caracter == 'A')
  {digitalWrite(ch1,LOW);
  {status_ch1 = 0;}}
  if(caracter == 'a')
  {digitalWrite(ch1,HIGH);
  {status_ch1 = 1;}}
  if(caracter == 'B')
  {digitalWrite(ch2,LOW);
  {status_ch2 = 0;}}
  if(caracter == 'b')
  {digitalWrite(ch2,HIGH);
  {status_ch2 = 1;}}
  delay(10);  }
