#include "PayloadEncoder.h"
#include "Client.h"
#include "AccessPoint.h"

void setup() {
	void inicializar_dados(); // inicialização dos dados
	encoder.setPosition(0); //encoder

	//botões
	pinMode(in1, INPUT);
	pinMode(in2, INPUT);

	Serial.begin(9600);
	lastbotao = digitalRead(in1);
	lastbotao2 = digitalRead(in2);

	pinMode(B_REM_OK, INPUT); //Definindo pino digital 13 como Botão de confirmação de toma de remédio
	digitalWrite(B_REM_OK, LOW);

	//buzzer
	pinMode(pinBuzzer, OUTPUT);
	digitalWrite(pinBuzzer, LOW);

	//leds
	pinMode(Leds[A_1], OUTPUT); //Definindo pino digital 33 como de saída.
	pinMode(Leds[A_2], OUTPUT); //Definindo pino digital 32 como de saída.
	pinMode(Leds[A_3], OUTPUT); //Definindo pino digital 35 como de saída.
	pinMode(Leds[A_4], OUTPUT); //Definindo pino digital 34 como de saída.

#ifndef ESP32
	while (!Serial); 
#endif

	if (!rtc.begin()) {
		Serial.println("RTC não encontrado");
		while (1);
	}

	if (! rtc.isrunning()) {
		Serial.println("RTC não está funcionando!");
		// following line sets the RTC to the date & time this sketch was compiled
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

		// This line sets the RTC with an explicit date & time, for example to set
		// January 21, 2014 at 3am you would call:
		//rtc.adjust(DateTime(2018, 11, 14, 11, 29, 0));
	}
	rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //Atualiza a data e hora


	//PARTE DO OLED
	display.init();

	display.flipScreenVertically();
	display.setFont(ArialMT_Plain_10);


	//PARTE DO WIFI
	ap.begin(); // Importante dar o begin do access point no setup antes de qualquer ação com ele 
}
