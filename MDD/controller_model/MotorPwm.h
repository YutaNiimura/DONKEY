/*
 * Pwm.h
 * Pwmクラス (ControlLeverクラスを実装)
 *
 * クラス名: Pwm(P)
 * 属性:
 * 操作: setLevel
 * 関連:
 */
 
#ifndef _MOTORPWM
#define _MOTORPWM

/**
 * モータへのPWM信号を設定する。
 * @param level duty比[%] (-100<= level <=100) level>0の時はモータが正転、level<0の時はモーターが逆転する。
 */
extern void MP_setLevel(int level);

#endif // _MOTORPWM