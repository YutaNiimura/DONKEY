#include "PControlMethod.h"

static float hensa = 0;
static int cmd_turn_bf = 0;

//����p�����[�^���擾����
float PC_getControlParm(void)
{
	return PCP_getKParm();
}

//����p�����[�^��ݒ肷��
void PC_setControlParm(float parm)
{
	PCP_setKParm(parm);
}

//����ʂ��Z�o����
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

//����������
void PC_initialize(void)
{
	hensa = 0;
}

