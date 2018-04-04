/*
 * GOTO1.ino Written by Igor Ovchinnikov 04/12/2016
 */

#include "CONFIG1.h"

int imStepsXPS = iStepsXPS*iXStepX; //Микрошагов в секунду на двигателе прямого восхождения
unsigned long ulSPRA = iStepsDX*dRDX*iXStepX; //Микрошагов двигателя на полный оборот оси прямого восхождения

const unsigned long StarMSPS=86164091; //Милисекунд в Звездных сутках
double udRAStepsPMS=double(ulSPRA)/double(StarMSPS); //Микрошагов двигателя на 1 мс

int iSt1D = -1;  //Направление шага двигателя прямого восхождения
unsigned long iMilisec=0; //Время выполнения основного цикла программы

boolean bDebug=false; //Режим отладки

//Здесь надо указать не D:\YandexDisk\Home\Arduino\_MySketches\GOTO1\ как у меня,
//а реальный путь, где GOTO1.h хранится:

#include "GOTO1.h"

void setup()
{
  pinMode(ENABLE_XYZ_PIN,  OUTPUT);  // ENABLE XYZ PIN
  digitalWrite(ENABLE_XYZ_PIN, LOW); // LOW
  pinMode(DX_STEP_PIN,  OUTPUT);     // DX STEP PIN
  digitalWrite(DX_STEP_PIN, LOW);    // LOW
  pinMode(DX_DIR_PIN,  OUTPUT);      // DX DIR PIN
  digitalWrite(DX_DIR_PIN, LOW);     // LOW
  pinMode(DX_FORCE_PIN,  OUTPUT);    // DX FORCE PIN
  digitalWrite(DX_FORCE_PIN, HIGH);  // HIGH
  pinMode(13,  OUTPUT);  // LED на плате ардуино
  digitalWrite(13, LOW); // Выключен
  Serial.begin(9600);    // Подключаем COM порт
  Serial.flush();        // Сбрасываем содержимое COM порта
  iMilisec=millis();     // Фиксируем время начала работы
 }

void loop()
{
 long LoopTime=millis()-iMilisec;
 long StepsNeed=LoopTime*udRAStepsPMS;
 if(StepsNeed>=1)
  {
   digitalWrite(13, HIGH);    // Зажигаем LCD
   Stepper_X_step(StepsNeed*iSt1D);  // Шагаем
   iMilisec+=double(StepsNeed)/udRAStepsPMS; // Временной эквивалент поворота трекера
  }
 if (bDebug) {Serial.print(" StepsNeed "); Serial.print(StepsNeed); Serial.print(" udRAStepsPMS "); Serial.println(udRAStepsPMS);}
 digitalWrite(13, LOW); // Тушим LCD
}
