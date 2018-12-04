int flag = 0;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;

void inicializar_dados(){
    alarmes[0].horario_inicial = -1;
    alarmes[0].minutos_inicial = -1;
    alarmes[0].freq = 0;
    alarmes[1].horario_inicial = -1;
    alarmes[1].minutos_inicial = -1;
    alarmes[1].freq = 0;
    alarmes[2].horario_inicial = -1;
    alarmes[2].minutos_inicial = -1;
    alarmes[2].freq = 0;
    alarmes[3].horario_inicial = -1;
    alarmes[3].minutos_inicial = -1;
    alarmes[3].freq = 0;
}

void deletar_1(){
    int botao = digitalRead(in1);
    if(botao == 1 && lastbotao == 0){
        alarmes[0].horario_inicial = -1;
        alarmes[0].minutos_inicial = -1;
        alarmes[0].freq = 0;
        Serial.println("deletado alarme1");
        Serial.println("Dados = ");
        Serial.print(alarmes[0].horario_inicial );
        Serial.print(":");
        Serial.println(alarmes[0].minutos_inicial );
        Serial.println(alarmes[0].freq );
    }
    lastbotao= botao;
}
void deletar_2(){
    int botao = digitalRead(in1);
    int botao2 = digitalRead(in2);
    if(botao == 1 && lastbotao == 0){
        alarmes[1].horario_inicial = -1;
        alarmes[1].minutos_inicial = -1;
        alarmes[1].freq = 0;
        Serial.println("deletado alarme2");
    }
    lastbotao= botao;
}
void deletar_3(){
    int botao = digitalRead(in1);
    int botao2 = digitalRead(in2);
    if(botao == 1 && lastbotao == 0){
        alarmes[2].horario_inicial = -1;
        alarmes[2].minutos_inicial = -1;
        alarmes[2].freq = 0;
        Serial.println("deletado alarme3");
    }
    lastbotao= botao;
}

void deletar_4(){
    int botao = digitalRead(in1);
    int botao2 = digitalRead(in2);
    if(botao == 1 && lastbotao == 0){
        alarmes[3].horario_inicial = -1;
        alarmes[3].minutos_inicial = -1;
        alarmes[3].freq = 0;
        Serial.println("deletado alarme4");
    }
    lastbotao= botao;
}

void minuto_inicial(){
    encoder.tick();
    if (flag1 == 0){
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "MINUTO INICIAL "); 
        display.display();
    }

    int newPos = encoder.getPosition();
    if (newPos < 0) {
        encoder.setPosition(0);
        newPos = 0;

    } else if (newPos > 59) {
        encoder.setPosition(59);
        newPos = 59;
    } 

    if (lastPos != newPos) {
        switch(Compartimento){
            case 1:
                alarmes[0].minutos_inicial = newPos;
                break; 
            case 2:
                alarmes[1].minutos_inicial = newPos;
                break;
            case 3:
                alarmes[2].minutos_inicial = newPos;
                break;
            case 4:
                alarmes[3].minutos_inicial = newPos;
                break;
        }
        flag1 = 1;
        Serial.print("minuto incial = ");
        Serial.println(newPos);
        lastPos = newPos;
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "MINUTO INICIAL = " + String(newPos)); 
        display.display();
    }
}

void horario_inicial(){
    encoder.tick();
    if (flag2 == 0){
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "HORA INICIAL "); 
        display.display();
    }
    int newPos = encoder.getPosition();
    if (newPos < 0) {
        encoder.setPosition(0);
        newPos = 0;

    } else if (newPos > 24) {
        encoder.setPosition(24);
        newPos = 24;
    } 

    if (lastPos != newPos) {
        switch(Compartimento){
            case 1:
                alarmes[0].horario_inicial = newPos;
                break; 
            case 2:
                alarmes[1].horario_inicial = newPos;
                break;
            case 3:
                alarmes[2].horario_inicial = newPos;
                break;
            case 4:
                alarmes[3].horario_inicial = newPos;
                break;
        }
        Serial.print("horario inicial = ");
        Serial.println(newPos);
        lastPos = newPos;
        flag2 = 1;
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "HORA INICIAL = " + String(newPos)); 
        display.display();
    }
}

void frequencia(){
    encoder.tick();
    if (flag3 == 0){
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "FREQUENCIA "); 
        display.display();
    }
    int newPos = encoder.getPosition();
    if (newPos < 1) {
        encoder.setPosition(1);
        newPos = 1;

    } else if (newPos > 168) {
        encoder.setPosition(168);
        newPos = 168;
    } 
    if (lastPos != newPos) {
        switch(Compartimento){
            case 1:
                alarmes[0].freq = newPos;
                break; 
            case 2:
                alarmes[1].freq = newPos;
                break;
            case 3:
                alarmes[2].freq = newPos;
                break;
            case 4:
                alarmes[3].freq = newPos;
                break;
        }

        Serial.print("Frequencia = ");
        Serial.println(newPos);
        lastPos = newPos;
        flag3 = 1;
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "FREQUENCIA = " + String(newPos)); 
        display.display();
    }   
}

void giro_compartimento(){
    encoder.tick();
    if(flag == 0){
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "COMPARTIMENTO"); 
        display.display();
    }
    int newPos = encoder.getPosition();
    if (newPos < 1) {
        encoder.setPosition(1);
        newPos = 1;

    } else if (newPos > 4) {
        encoder.setPosition(4);
        newPos = 4;
    } 
    if (lastPos != newPos) {
        Compartimento = newPos;
        flag = 1;
        Serial.print("Compartimento = ");
        Serial.println(Compartimento);
        lastPos = newPos;
        display.clear(); //limpa a tela
        display.setFont(ArialMT_Plain_10);
        superior(); // chama a função superior
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 32, "COMPARTIMENTO = " + String(newPos)); 
        display.display();
    }
}
