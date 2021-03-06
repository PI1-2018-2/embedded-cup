//Compara Horas e minutos (A FUNÇÃO ALARME UTILIZA PARA FUNCIONAR)
int comparaA(int Hora_x, int Min_x) {
    DateTime now = rtc.now();
    if (Hora_x == now.hour() && Min_x == now.minute() && now.second()<=1) {
        flag_compA = 1;
    }
    return flag_compA;
}

//Gerenciados de Alarme
void GerenciadorAlarme(int horario_inicial[2], int freq, int A) {

    //Verificar se a data inicial < data atual < data final
    DateTime now = rtc.now();

    //Verificar se o alarme foi modificado
    if ((freq != Cfreq[A]) || (Chorario_inicial[A][0] != horario_inicial[0]) || (Chorario_inicial[A][1] != horario_inicial[1])) {
        n[A] = 0;
        Cfreq[A] = freq;
        horario_referencia[A] = horario_inicial[0];
        Minuto_x[A] = horario_inicial[1];
        for (int i = 0; i < 2; i++) {
            Chorario_inicial[A][i] = horario_inicial[i];
        }
    }
    //Serial.println(n[A]);
    Hora_x[A] = horario_referencia[A] + freq * n[A];

    if (Hora_x[A] >= 24) {
        Hora_x[A] = Hora_x[A] - 24;
        horario_referencia[A] = Hora_x[A];
        n[A] = 0;
    }

    if (comparaA(Hora_x[A], Minuto_x[A])) {
        n[A] = n[A] + 1;
        C_Leds[A] = 1;
        flag_compA = 0;
    } else {
        flag_compA = 0;
        C_Leds[A] = 0;
    }

}

void Gerenciador_LED(void) {
    for (int i = 0; i <= 3; i++) {
        if (C_Leds[i]) {
            Ac_LED[i] = 1;
        }
    }

    for (int i = 0; i <= 3; i++) {
        if (Ac_LED[i]) {
            digitalWrite(Leds[i], HIGH);
        } else {
            digitalWrite(Leds[i], LOW);
        }
    }
    if (digitalRead(B_REM_OK) == HIGH) {
        for (int i = 0; i <= 3; i++) {
            Ac_LED[i] = 0;
            digitalWrite(Leds[i], LOW);


        }
        digitalWrite(pinBuzzer, LOW);
        flag_Des = 0;

        DateTime now = rtc.now();
        smc::Moment moment;
        moment.hour = now.hour();
        moment.minute = now.minute();
        moment.day = now.day();
        moment.month = now.month();
        moment.year = now.year();

        int id_cup = 1; // Número único que identifica um copo
        char event[] = "taken"; // Nome do evento que aconteceu, pode ser: taken, not_taken, registered ou removed

        int partition = -1;
        for(partition = 0; partition < 4; ++partition){
            if(Ac_LED[partition]) break;
        }
        partition++;

        smc::AlarmInfo alarmInfo;
        smc::Client client;
        smc::PayloadEncoder payload(id_cup, partition, moment, event, alarmInfo);
        client.sendRequest(payload);
    }

}
void Descanso(void){
    DateTime now = rtc.now();

    if ((C_Leds[0]==1)||(C_Leds[1]==1)||(C_Leds[2]==1)||(C_Leds[3]==1)) {
        digitalWrite(pinBuzzer, HIGH);
        T_Alar= now.minute()+1;
        if(T_Alar == 60){
            T_Alar= 0;
        }
    }
    if (T_Alar== now.minute()){
        digitalWrite(pinBuzzer, LOW);
        flag_Des = 1;
        T_Alar= -1;
    }

    if (flag_Des == 1){
        for (int i = 0; i <= 3; i++) {
            LED_Des[i] = Ac_LED[i]; 
        }  
    }
    if ((digitalRead(Leds[0])||digitalRead(Leds[1])||digitalRead(Leds[2])||digitalRead(Leds[3])) && digitalRead(in1)) {

        flag_Des = 1;
        T_Alar= -1;
        digitalWrite(pinBuzzer, LOW);
    }

    if(flag_Des){
        DateTime now = rtc.now();
        smc::Moment moment;
        moment.hour = now.hour();
        moment.minute = now.minute();
        moment.day = now.day();
        moment.month = now.month();
        moment.year = now.year();

        int id_cup = 1; // Número único que identifica um copo
        char event[] = "not_taken"; // Nome do evento que aconteceu, pode ser: taken, not_taken, registered ou removed

        int partition = -1;
        for(partition = 0; partition < 4; ++partition){
            if(Ac_LED[partition]) break;
        }
        partition++;

        smc::AlarmInfo alarmInfo;
        smc::Client client;
        smc::PayloadEncoder payload(id_cup, partition, moment, event, alarmInfo);
        client.sendRequest(payload);
    }
    /*
       int hor_x[4];
       int mn_x[4];

       hor_x[0] = Hora_x[0];
       mn_x[0] = Minuto_x[0];
       hor_x[1] = Hora_x[1];
       mn_x[1] = Minuto_x[1];
       hor_x[2] = Hora_x[2];
       mn_x[2] = Minuto_x[2];
       hor_x[3] = Hora_x[3];
       mn_x[3] = Minuto_x[3];

       if (mn_x[0] >= 60) {
       mn_x[0] = mn_x[0] - 60;
       hor_x[0] = hor_x[0] + 1;
       }
       if (mn_x[1] >= 60) {
       mn_x[1] = mn_x[1] - 60;
       hor_x[1] = hor_x[1] + 1;
       }
       if (mn_x[2] >= 60) {
       mn_x[2] = mn_x[2] - 60;
       hor_x[2] = hor_x[2] + 1;
       }
       if (mn_x[3] >= 60) {
       mn_x[3] = mn_x[3] - 60;
       hor_x[3] = hor_x[3] + 1;
       }

    //Parte de tocar o alarme por uma hora e meia a cada quinze minutos
    if(flag_Des == 1){
    if(hor_x[0] == now.hour() && (mn_x[0] + 15) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }
    else if(hor_x[0] == now.hour() && (mn_x[0] + 30) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }else if(hor_x[0] == now.hour() && (mn_x[0] + 45) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }else if((hor_x[0] + 1) == now.hour() && mn_x[0] == now.minute() && now.second()<=1){
    flag_compA = 1;
    }
    }
    else{
    flag_compA = 0;
    }
    //Parte de tocar o alarme por uma hora e meia a cada quinze minutos
    if(flag_Des == 1){
    if(hor_x[1] == now.hour() && (mn_x[1] + 15) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }
    else if(hor_x[1] == now.hour() && (mn_x[1] + 30) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }else if(hor_x[1] == now.hour() && (mn_x[1] + 45) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }else if((hor_x[1] + 1) == now.hour() && mn_x[1] == now.minute() && now.second()<=1){
    flag_compA = 1;
    }
    }
    else{
    flag_compA = 0;
    }
    //Parte de tocar o alarme por uma hora e meia a cada quinze minutos
    if(flag_Des == 1){
    if(hor_x[2] == now.hour() && (mn_x[2] + 15) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }
    else if(hor_x[2] == now.hour() && (mn_x[2] + 30) == now.minute() && now.second()<=1){
    flag_compA = 1;
    }else if(hor_x[2] == now.hour() && (mn_x[2] + 45) == now.minute() && now.second()<=1){
    flag_compA = 1;
}else if((hor_x[2] + 1) == now.hour() && mn_x[2] == now.minute() && now.second()<=1){
    flag_compA = 1;
}
}
else{
    flag_compA = 0;
}
//Parte de tocar o alarme por uma hora e meia a cada quinze minutos
if(flag_Des == 1){
    if(hor_x[3] == now.hour() && (mn_x[3] + 15) == now.minute() && now.second()<=1){
        flag_compA = 1;
    }
    else if(hor_x[3] == now.hour() && (mn_x[3] + 30) == now.minute() && now.second()<=1){
        flag_compA = 1;
    }else if(hor_x[3] == now.hour() && (mn_x[3] + 45) == now.minute() && now.second()<=1){
        flag_compA = 1;
    }else if((hor_x[3] + 1) == now.hour() && mn_x[3] == now.minute() && now.second()<=1){
        flag_compA = 1;
    }
}
else{
    flag_compA = 0;
}
*/
}
