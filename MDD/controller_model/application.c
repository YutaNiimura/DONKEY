#include "sfr29.h"
#include "utility.h"
#include "led_driver.h"
#include "encoder_driver.h"
#include "motor_driver.h"
#include "MotorSpeed.h"
#include "MotorPwm.h"
#include "Controller.h"
#include "PControlMethod.h"
#include "PControlMethodParm.h"
#include "RotaryEncoder.h"

void init();
void test_RS();
void test_P();
void test_C();
void test_PCP();
void test_PC();
void test_T();

void main() 
{
	//test_RS();
	//test_P();
	test_C();
	//test_PCP();
	//test_PC();
	//test_T();
}

void test_C() {
	init();
	C_setControlMethodParm(0.1);
	C_setTargetValue(80);

	while(1){
		C_doControl();
		wait_ms(100);
	}
}

void test_P() {
	init();
	
	MP_setLevel(30);
	wait_ms(2000);
	MP_setLevel(60);
	wait_ms(2000);
	MP_setLevel(-30);
	wait_ms(2000);
	MP_setLevel(-60);
	wait_ms(2000);
	MP_setLevel(0);
	
}

void test_RS() {
	init();
	
	while(1) {
		set_led((char)MS_getValue());
		wait_ms(100);
		/*
		set_led(RS_getTargetValue());
		wait_ms(1000);		
		RS_setTargetValue(50.0);
		set_led(RS_getTargetValue());
		wait_ms(1000);
		RS_setTargetValue(120.0);
		set_led(RS_getTargetValue());
		wait_ms(1000);
		*/
	}
}	 

void test_PCP() {
	init();
	PCP_setKParm(3.0);
	
}

void test_PC() {
	init();
	PC_initialize();
	PC_setControlParm(1.0);
	MP_setLevel(20);
	
	/*
	while(1) {
		set_led((char)PC_calcControlValue(20,T_getValue()));
		wait_ms(100);
	}
	*/
	
	while(1) {
		MP_setLevel(PC_calcControlValue(30,RE_getValue(),0));
		wait_ms(4);
	}
	
}

void test_T()
{
	init();
	MP_setLevel(20);

	
	while(1) {
		set_led((char)RE_getValue());
		wait_ms(100);
	}
	
}

void init()
{
	prc2 = 1;			/*PACRの書込み許可*/
	pacr = 3;			/*80ピンに設定*/
	
	/*クロック設定*/
	prc0=1;
	cm21=0;
	cm06=0;
	prc0=0;
	
	//
	init_led();
	init_encoder();
	init_motor();
}			