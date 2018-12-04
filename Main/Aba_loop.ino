void loop() {
    Serial.println("loop");
    // ADC = analogRead(ADC_PIN);
    // put your main code here, to run repeatedly:
    menu();

    //Horário atual no DS1307
    DateTime now = rtc.now();


    //FUNÇÕES CHAMADAS E ATIVADAS

    Hora_In1[0]=alarmes[0].horario_inicial;
    Hora_In1[1]=alarmes[0].minutos_inicial;
    GerenciadorAlarme(Hora_In1,alarmes[0].freq, A_1);

    Hora_In2[0]=alarmes[1].horario_inicial;
    Hora_In2[1]=alarmes[1].minutos_inicial;
    GerenciadorAlarme(Hora_In2,alarmes[1].freq, A_2);

    Hora_In3[0]=alarmes[2].horario_inicial;
    Hora_In3[1]=alarmes[2].minutos_inicial;
    GerenciadorAlarme(Hora_In3,alarmes[2].freq, A_3);

    Hora_In4[0]=alarmes[3].horario_inicial;
    Hora_In4[1]=alarmes[3].minutos_inicial;
    GerenciadorAlarme(Hora_In4,alarmes[3].freq, A_4);
    Gerenciador_LED();
    Descanso();


    //PARTE DO WIFI

    ap.handle_request(); // Deixar isso aqui rodando no loop sempre
}
