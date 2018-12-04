//Entrada de dados
#include "RTClib.h"//Biblioteca do DS1307
#include <RotaryEncoder.h>
#include <Wire.h>//Para comunicação I2C
#include <SSD1306Wire.h>

#include "PayloadEncoder.h"
#include "Client.h"
#include "AccessPoint.h"

smc::AccessPoint ap;

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
#define Serial SerialUSB
#endif
RTC_DS1307 rtc, hor_X;

SSD1306Wire display(0x3c, 21, 22);

int qdr = 0;
int lastPos = -1;
int lastbotao;
int lastbotao2;
int Compartimento;

struct Dados {
    int horario_inicial;
    int minutos_inicial;
    int freq;
};
struct Dados alarmes[4];

//Configura algumas variáveis utilizadas em Gerenciador de Alarme
int Hora_In1[2];
int Hora_In2[2];
int Hora_In3[2];
int Hora_In4[2];
int C_Leds[4] = {0, 0, 0, 0};         //Flag para ligar os LEDS
int Cfreq[4];
int Chorario_inicial[4][3];
int horario_referencia[4];
int n[4] = {0, 0, 0, 0};
int Hora_x[4];
int Minuto_x[4];
int A_1 = 0;
int A_2 = 1;
int A_3 = 2;
int A_4 = 3;
int flag_compA = 0;                      //flag_comp=1 Hora_x=Hora_Atual e Minuto_x=Minuto_Atual, flag_comp=0 CC
int flag_Des = 0;                        //flag_comp=1 Hora_x=Hora_Atual e Minuto_x=Minuto_Atual, flag_comp=0 CC
int Ac_LED[4] = {0, 0, 0, 0};           // Guardar o valor do led até o botão de confirmar o remedio ser apertado REMO_K
int LED_Des[4] = {0, 0, 0, 0};          // Guardar o valor do led para descanso
int T_Desc[4]={-1};
int T_Alar=-1;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

//Entradas
#define B_REM_OK  12                      //Botão Confirma de remedio ligado as pino D13
#define  in1  2 
#define  in2  15
RotaryEncoder encoder(4,16);

//Saidas
int Leds[4] = {26, 25, 33, 32};        //Leds dos compartimento 1,2,3 e 4 ligados aos pino D26,D25,D33,D32 respectivamentes
#define pinBuzzer 14
