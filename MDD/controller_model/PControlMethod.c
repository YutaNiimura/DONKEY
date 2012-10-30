#include "PControlMethod.h"

static float hensa = 0;
static int cmd_turn_bf = 0;

//制御パラメータを取得する
float PC_getControlParm(void)
{
	return PCP_getKParm();
}

//制御パラメータを設定する
void PC_setControlParm(float parm)
{
	PCP_setKParm(parm);
}

//操作量を算出する
int PC_calcControlValue(int targvalue,int getvalue,int time)
{
	int cmd_turn;
	
	hensa = (float)targvalue - (float)getvalue;
		
	cmd_turn = (int)(cmd_turn_bf + (PCP_getKParm() * (int)hensa * (float)time/1000));
	
	if(cmd_turn > 100)
		cmd_turn = 100;
	else if(cmd_turn < -100)
		cmd_turn = -100;
				
	cmd_turn_bf = cmd_turn;
				
	return cmd_turn;
}	

//初期化する
void PC_initialize(void)
{
	hensa = 0;
}

