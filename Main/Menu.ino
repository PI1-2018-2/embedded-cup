#include "PayloadEncoder.h"
#include "Client.h"
#include "AccessPoint.h"

void serial(){
    Serial.print("qdr = " );
    Serial.println(qdr);
}

void menu(){
    int botao = digitalRead(in1);
    int botao2 = digitalRead(in2);

    int id_cup = 1; // Número único que identifica um copo
    int partition = -1;
    String event;

    switch(qdr){
        case 0: //MENU
            oled_menu();
            if(botao == 1 && lastbotao == 0){
                qdr = 1;     
                serial();    
                delay(100); 
            }
            lastbotao= botao;
            break;
        case 1: //ALARME
            oled_alarme();

            giro_2();
            if(botao == 1 && lastbotao == 0){
                qdr = 3; 
                serial();  
                delay(100); 
            } 
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 0 ;
                serial();  
                delay(100);
            }
            lastbotao = botao;
            lastbotao2 = botao2;
            break;
        case 2: //WIFI
            giro_2();
            oled_wifi();
            if(botao ==1 && lastbotao == 0 ){
                qdr = 6;
                serial();  
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 0 ;
                serial();
                delay(100);  
            }
            lastbotao= botao;
            lastbotao2 = botao2;
            break;
        case 3: //ALARMES DEFINIDOS
            giro_3(); 
            oled_alarmes_definidos();
            if(botao == 1 && lastbotao == 0){
                qdr = 9;  
                serial(); 
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 1 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;
            break;
        case 4: //DELETAR
            giro_3();
            oled_deletar();
            if(botao == 1 && lastbotao == 0){
                qdr = 13;
                serial(); 
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 1 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;
            break;
        case 5: //CADASTRO
            flag = 0;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            giro_3(); 
            oled_cadastro();
            if(botao == 1 && lastbotao == 0){
                qdr = 17;   
                serial(); 
                delay(100);     
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 1 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;
            break;
        case 6: //START_AP
            giro_3();
            oled_startap;
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 2 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            break;
        case 7: //REDES_CONHECIDAS
            giro_3();
            oled_redesconhecidas;
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 2 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            break;
        case 8: //SINAL_MANUAL
            giro_3();
            oled_conexao_manual;
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 2 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            break;
        case 9: //ALARME1
            giro_4();
            oled_alarme1();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 3 ;
                serial();
                delay(100); 

            }
            lastbotao2 = botao2;
            break;
        case 10:  //ALARME2
            giro_4();    
            oled_alarme2();        
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 3 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;

            break;
        case 11:  //ALARME3
            giro_4();
            oled_alarme3();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 3 ;
                serial();
                delay(100);          
            }
            lastbotao2 = botao2;
            break;
        case 12:  //ALARME4
            giro_4();
            oled_alarme4();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 3 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            break;
        case 13:  //ALARME1 -- OPÇÃO DE DELETAR
            giro_4();
            deletar_1();
            oled_deletar1();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 4 ;
                serial();
                delay(100); 
            }
            lastbotao2 = botao2;
            lastbotao= botao;

            event = "cancelled";
            partition = 1;
            break;
        case 14:  //ALARME2 -- OPÇÃO DE DELETAR
            giro_4();
            deletar_2();
            oled_deletar2();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 4 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;

            event = "cancelled";
            partition = 2;
            break;
        case 15:  //ALARME3 -- OPÇÃO DE DELETAR
            giro_4();
            deletar_3();
            oled_deletar3();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 4 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;

            event = "cancelled";
            partition = 3;
            break;
        case 16:  //ALARME4 -- OPÇÃO DE DELETAR
            giro_4();
            deletar_4();
            oled_deletar4();
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 4 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;

            event = "cancelled";
            partition = 4;
            break;
        case 17:  //COMPARTIMENTO
            giro_compartimento();
            if(botao == 1 && lastbotao == 0){
                qdr = 18;
                serial(); 
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 5 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;
            break;
        case 18:  //FREQUÊNCIA(SOMENTE EM HORAS)
            frequencia();
            if(botao == 1 && lastbotao == 0){
                qdr = 19;
                serial(); 
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 17 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;
            break;
        case 19:  //HORA_INICIAL
            horario_inicial();
            if(botao == 1 && lastbotao == 0){
                qdr = 20;
                serial(); 
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 18 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;
            break;
        case 20:  //MINUTO_INICIAL
            minuto_inicial();
            if(botao == 1 && lastbotao == 0){
                qdr = 5;
                serial(); 
                delay(100);
            }
            if(botao2 == 1 && lastbotao2 == 0){
                qdr = 19 ;
                serial(); 
                delay(100);
            }
            lastbotao2 = botao2;
            lastbotao= botao;

            smc::AlarmInfo alarmInfo;
            switch(Compartimento){
                case 1:
                    alarmInfo.start.hour = alarmes[0].horario_inicial;
                    alarmInfo.start.minute = alarmes[0].minutos_inicial;
                    alarmInfo.period.hour = alarmes[0].freq;
                    alarmInfo.period.minute = 0;
                    alarmInfo.duration = 1000; // Em dias
                    break;
                case 2:
                    alarmInfo.start.hour = alarmes[1].horario_inicial;
                    alarmInfo.start.minute = alarmes[1].minutos_inicial;
                    alarmInfo.period.hour = alarmes[1].freq;
                    alarmInfo.period.minute = 0;
                    alarmInfo.duration = 1000; // Em dias
                    break;
                case 3:
                    alarmInfo.start.hour = alarmes[2].horario_inicial;
                    alarmInfo.start.minute = alarmes[2].minutos_inicial;
                    alarmInfo.period.hour = alarmes[2].freq;
                    alarmInfo.period.minute = 0;
                    alarmInfo.duration = 1000; // Em dias
                    break;
                case 4:
                    alarmInfo.start.hour = alarmes[3].horario_inicial;
                    alarmInfo.start.minute = alarmes[3].minutos_inicial;
                    alarmInfo.period.hour = alarmes[3].freq;
                    alarmInfo.period.minute = 0;
                    alarmInfo.duration = 1000; // Em dias
                    break;
            }

            event = "registered"; // Nome do evento que aconteceu, pode ser: taken, not_taken, registered ou removed
            partition = Compartimento;
            break;

            if(partition != -1){
                DateTime now = rtc.now();
                smc::Moment moment;
                moment.hour = now.hour();
                moment.minute = now.minute();
                moment.day = now.day();
                moment.month = now.month();
                moment.year = now.year();

                smc::Client client;
                smc::PayloadEncoder payload(id_cup, partition, moment, event.c_str(), alarmInfo);
                client.sendRequest(payload);
            }
    }
}
