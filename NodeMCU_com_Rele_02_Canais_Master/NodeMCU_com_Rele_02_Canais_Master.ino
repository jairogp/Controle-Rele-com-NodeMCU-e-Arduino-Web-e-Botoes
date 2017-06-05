
  #include <ESP8266WiFi.h>

  const char* ssid = "Vitorelo";
  const char* password = "setembro1309";
  WiFiServer server(80);

  void setup() {

  Serial.begin(9600);
  delay(10);
  
  conectar();
  }

  void conectar() {
  Serial.println();
  Serial.println();
  Serial.print("Connectando a ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Conectado com sucesso na rede.");
  
  // Start the server
  server.begin();
  Serial.println("IP Obtido: ");
  Serial.print(WiFi.localIP());
  }

  void loop() {
       
  if (WiFi.status() != WL_CONNECTED) {conectar();}  // Caso wifi tenha caido conecta novamente
  WiFiClient client = server.available();
  // Volta ao loop aguardando nova conexao do cliente.
  if (!client) { 
    return; 
  }     
  // um loop de 20 laços para nao ficar preso quando da erro na conexao client  problemas com o navegador Chrome           
  int conta = 0 ;
  while(conta < 20)            
  {
  if(!client.available()){ conta = conta +1;}
  else { conta = 20;}
  delay(1);
  } 
  // mesmo passando o laço e ainda nao teve conexao, para e retorna ao inicio eliminando erros de navegadores
  if (!client.available()) 
  { 
    client.stop();
    return;
  } 
  String req = client.readStringUntil('\r');
  client.flush();
  
  String buf = "";
 
  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  buf += "<html lang=\"pt\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  buf += "<title>WEB Server ESP 8266</title>";
  buf += "<h1> CONTROLE ILUMINACAO</h1>";
  buf += "<style>.c{text-align: center;} div,input{padding:5px;font-size:1em;} input{width:80%;} body{text-align: center;font-family:verdana;} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:49%;} .q{float: right;width: 64px;text-align: right;}</style>";
  buf += "<p><h3>CANAL 01</h3></p> <a href=\"?function=D0_on\"><button>LIGA</button></a> <a href=\"?function=D0_off\"><button>DESLIGA</button></a></p>";
  buf += "<p><h3>CANAL 02</h3></p> <a href=\"?function=D1_on\"><button>LIGA</button></a> <a href=\"?function=D1_off\"><button>DESLIGA</button></a></p>";
  client.print(buf);
  delay(10);

  client.flush();

       if (req.indexOf("D0_on") != -1)
    Serial.println("A");
       if (req.indexOf("D0_off") != -1)
    Serial.println("a");
       if (req.indexOf("D1_on") != -1)
    Serial.println("B");
       if (req.indexOf("D1_off") != -1)
    Serial.println("b");
  else{
    client.stop();
  }}

