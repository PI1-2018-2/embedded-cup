//DISPLAY 

void oled_menu(){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior();
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "MENU DO SMU");
    display.display();
}

void oled_alarme(){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "ALARME");   
    display.display();   
} 

void oled_wifi (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "WIFI");
    display.display();
}
void oled_alarmes_definidos (){        
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "ALARMES DEFINIDOS");
    display.display();
}   

void oled_deletar (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "DELETAR ALARME");
    display.display();
}   

void oled_cadastro (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "CADASTRAR ALARME");
    display.display();
}       
void oled_startap (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "START AP");
    display.display();
}

void oled_redesconhecidas (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "REDES CONHECIDAS");
    display.display();
}

void oled_conexao_manual (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 22, "CONEXAO MANUAL");
    display.display();
}   

void oled_alarme1 (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(64, 24, "ALARME 1");
    display.drawString(12, 35, "HORARIO = " + String(alarmes[0].horario_inicial) + ":" + String(alarmes[0].minutos_inicial) );
    display.drawString(12, 46, "FREQUENCIA = " + String(alarmes[0].freq));
    display.display();
}        

void oled_alarme2 (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(64, 24, "ALARME 2");
    display.drawString(12, 35, "HORARIO = " + String(alarmes[1].horario_inicial) + ":" + String(alarmes[1].minutos_inicial) );
    display.drawString(12, 46, "FREQUENCIA = " + String(alarmes[1].freq));
    display.display();
}          

void oled_alarme3 (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(64, 24, "ALARME 3");
    display.drawString(12, 35, "HORARIO = " + String(alarmes[2].horario_inicial) + ":" + String(alarmes[2].minutos_inicial) );
    display.drawString(12, 46, "FREQUENCIA = " + String(alarmes[2].freq));
    display.display();
}

void oled_alarme4 (){
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(64, 24, "ALARME 4");
    display.drawString(12, 35, "HORARIO = " + String(alarmes[3].horario_inicial) + ":" + String(alarmes[3].minutos_inicial) );
    display.drawString(12, 46, "FREQUENCIA = " + String(alarmes[3].freq));
    display.display();
}

void oled_deletar1 (){
    int botao = digitalRead(in1);
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 24, "DELETAR 1"); 
    display.display();
    if(botao == 1 && lastbotao == 0){
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 35, "DELETADO ALARME 1"); 
        display.display();
    }
    lastbotao = botao;
}

void oled_deletar2 (){
    int botao = digitalRead(in1);
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 24, "DELETAR 2"); 
    display.display();
    if(botao == 1 && lastbotao == 0){
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 35, "DELETADO ALARME 2"); 
        display.display();
    }
    lastbotao = botao;
}

void oled_deletar3 (){
    int botao = digitalRead(in1);
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 24, "DELETAR 3"); 
    display.display();
    if(botao == 1 && lastbotao == 0){
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 35, "DELETADO ALARME 3"); 
        display.display();
    }
    lastbotao = botao;
}

void oled_deletar4 (){
    int botao = digitalRead(in1);
    display.clear(); //limpa a tela
    display.setFont(ArialMT_Plain_10);
    superior(); // chama a função superior
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 24, "DELETAR 4"); 
    display.display();
    if(botao == 1 && lastbotao == 0){
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 35, "DELETADO ALARME 4"); 
        display.display();
    }
    lastbotao = botao;
}  


/*
   void bateria() // função para mostrar condição de bateria
   {
   BAT_LVL = map(ADC, 0, 540, 0, 100); // chama a função que lê o nível de bateria
   myOLED.print(BAT_LVL, LEFT, 6); // imprime a porcentagem de bateria
   myOLED.print("   %", LEFT, 6); // deixa espaço para a impressão do nivel de bateria e insere o simbolo de porcentagem à direira
   }
 */

/*
   void wifi() // função para mostrar condição de wifi
   {
   boolean wifi = HIGH;
   boolean dat = HIGH;
// wifi = func_wifi(); // chama a função de conexão com o wifi e iguala a variavel wifi
//  dat = dados_a_enviar(); // chama a função que verifica se existem dados a enviar e iguaa a variavel dat
if (wifi == HIGH) { // considerando a conexão com o wifi um parametro booleano, caso conectado = 1, caso desconectado = 0
myOLED.print("CONECT", CENTER, 6);
}
if (wifi == LOW && dat == HIGH) { // caso não haja conexão, verificar se existem dados a serem enviados ou não e, em caso positivo, avisar que está procurando rede
myOLED.print("RECONECT", CENTER, 6);
}
if (wifi == LOW && dat == LOW) { // caso não haja conexão, verificar se existem dados a serem enviados ou não e, em caso negativo, avisar que está desconectado
myOLED.print("DESCONECT", CENTER, 6); 
}
}
 */

void hora() // função para mostrar hora
{
    DateTime now = rtc.now();
    /*
       char hour[5];
       leitor_hora(); // recebe a função que realiza a leitura da hora no relógio do SMC
       hour = leitor_hora; // considerando a saida da função do leitor como uma string
     */

    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    display.drawString(128, 0, String(now.hour()) + ":" +String(now.minute()));


}

void superior() // função para imprimir na tela a bateria, o wifi e a hora
{
    //  bateria();
    // wifi();
    hora();

}
