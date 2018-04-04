/*
 * CONFIG1.ino Written by Igor Ovchinnikov 04/12/2016
 */

#define ENABLE_XYZ_PIN 8 //Enable X,Y,Z pin
#define DX_STEP_PIN  5  //Контакт ардуино идущий на STEP драйвера ПВ
#define DX_DIR_PIN   2  //Контакт ардуино идущий на DIR  драйвера ПВ
#define DX_FORCE_PIN 9  //Разгонный пин драйвера ПВ

int iStepsDX=48;      //Полных шагов на 1 оборот двигателя ПВ
int iStepsXPS = 200;  //Полных шагов в секунду на двигателе ПВ
int iXStepX   =  16;  //Кратность шага драйвера ПВ
double dRDX =1780.69; //Передаточное число редуктора ПВ
