#include <OneWire.h> //INCLUSÃO DE BIBLIOTECA
#include <DallasTemperature.h> //INCLUSÃO DE BIBLIOTECA
#include <PID_v1.h> //INCLUSÃO DE BIBLIOTECA

#define termopar1 7 //DEFINE O PINO DIGITAL UTILIZADO PELO SENSOR DO TERMOPAR 1 - ENTRADA DO CASCO
#define termopar2 6 //DEFINE O PINO DIGITAL UTILIZADO PELO SENSOR DO TERMOPAR 2 - SAÍDA DO CASCO
#define termopar3 5 //DEFINE O PINO DIGITAL UTILIZADO PELO SENSOR DO TERMOPAR 3 - ENTRADA DOS TUBOS
#define termopar4 4 //DEFINE O PINO DIGITAL UTILIZADO PELO SENSOR DO TERMOPAR 4 - SAÍDA DOS TUBOS
#define motor 9   //DEFINE O PINO DIGITAL PWM UTILIZADO PELO DRIVER PWM

double Setpoint, Input, Output; //DEFINE AS VARIÁVEIS QUE SERÃO UTILIZADAS ITERATIVAMENTE

//unsigned float l_min; // Calculated litres/min
unsigned long currentTime;
unsigned long cloopTime;

OneWire ourWire1(termopar1); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR DO TERMOPAR 1
DallasTemperature sensors1(&ourWire1); //BIBLIOTECA DallasTemperature UTILIZA A OneWire PARA O SENSOR DO TERMOPAR 1

OneWire ourWire2(termopar2); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR DO TERMOPAR 2
DallasTemperature sensors2(&ourWire2); //BIBLIOTECA DallasTemperature UTILIZA A OneWire PARA O SENSOR DO TERMOPAR 2

OneWire ourWire3(termopar3); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR DO TERMOPAR 3
DallasTemperature sensors3(&ourWire3); //BIBLIOTECA DallasTemperature UTILIZA A OneWire PARA O SENSOR DO TERMOPAR 3

OneWire ourWire4(termopar4); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR DO TERMOPAR 4
DallasTemperature sensors4(&ourWire4); //BIBLIOTECA DallasTemperature UTILIZA A OneWire PARA O SENSOR DO TERMOPAR 4

PID myPID(&Input, &Output, &Setpoint,22,2,4, REVERSE); //ESPECIFICA AS CONEXÕES E PARÂMETROS DO CONTROLADOR

void setup()
{
    Serial.begin(9600);
    currentTime = millis();
    cloopTime = currentTime;

    pinMode(motor, OUTPUT); //saída para o motor
    digitalWrite(motor, LOW); //motor inicia desligado
    
    sensors2.begin(); //INICIA O SENSOR DO TERMOPAR
    
    Input = sensors2.getTempCByIndex(0); //INICIALIZA A VARIÁVEL DE ENTRADA DO CONTROLADOR
    Setpoint = 34.5; //INDICA O VALOR DESEJADO PARA A VARIÁVEL CONTROLADA
    
    myPID.SetMode(AUTOMATIC); //INICIA O CONTROLADOR PID
    myPID.SetOutputLimits(120, 255); //LIMITA O FUNCIONAMENTO DA VARIÁVEL DE SAÍDA

    //DEVERIA SER DE 0-255, PORÉM, COM UM VALOR DE SAÍDA MENOR QUE 120 A PERDA DE CARGA INIBE O FUNCIONAMENTO DA BOMBA
}

void loop(){
  currentTime = millis();
  Serial.print(currentTime);
  Serial.print(',');

  sensors1.requestTemperatures();//SOLICITA QUE A FUNÇÃO INFORME A TEMPERATURA DO SENSOR 1
  //Serial.print("Temperatura TERMOPAR 1: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(sensors1.getTempCByIndex(0)); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  //Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  Serial.print(',');

  sensors2.requestTemperatures();//SOLICITA QUE A FUNÇÃO INFORME A TEMPERATURA DO SENSOR 2
  //Serial.print("Temperatura TERMOPAR 2: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(sensors2.getTempCByIndex(0)); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  //Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  Serial.print(',');

  sensors3.requestTemperatures();//SOLICITA QUE A FUNÇÃO INFORME A TEMPERATURA DO SENSOR 3
  //Serial.print("Temperatura TERMOPAR 3: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(sensors3.getTempCByIndex(0)); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  //Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  Serial.print(',');

  sensors4.requestTemperatures();//SOLICITA QUE A FUNÇÃO INFORME A TEMPERATURA DO SENSOR 4
  //Serial.print("Temperatura TERMOPAR 4: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(sensors4.getTempCByIndex(0)); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  //Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  Serial.print(',');  

  delay(250);//INTERVALO DE 250 MILISSEGUNDOS

  Input = sensors2.getTempCByIndex(0); //ATUALIZA O VALOR DE TEMPERATURA PARA ENTRADA DO CONTROLADOR PID
  myPID.Compute(); //FAZ O CÁLCULO DO CONTROLE PID
  analogWrite(motor,Output); //FAZ O MOTOR RODAR COM O VALOR ESPECIFICADO PARA myPID.SetOutputLimits

  //Serial.print("Saída PID: "); //IMPRIME O TEXTO NA SERIAL
  Serial.println(Output); //IMPRIME NA SERIAL O VALOR DE SAÍDA DO PID
} //end loop