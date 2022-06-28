#ifndef  _MOTOR_H
#define  _MOTOR_H

#include "sys.h" 


#define Ain1  PBout(0)
#define Ain2  PBout(1)

#define Bin1  PBout(10)
#define Bin2  PBout(11)

#define Cin1  PCout(4)
#define Cin2  PCout(5)


void Motor_Init(void);/*【5】*/
int Limit(float PWM_INPUT);
int GFP_abs(int p);
void Load1(int moto1);
void Load2(int moto2);
void Load3(int moto3);

void go_1(int speedd1);
void go_2(int speedd2);
void go_3(int speedd3);

void time(int timee);

void shunshizhen(void);
void nishizhen(void);
void turnright(void);
void turnleft(void);

void pp(void);

void send_SIGNAL(void);
void recive_SIGNAL(void);

void SIGNAL_TEST(void);
#endif

