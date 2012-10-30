#include "Tachometer.h"
#include "encoder_driver.h"

/**
 * 回転速度を取得
 * @return 回転速度 [rps]
 */
int T_getValue()
{
	return get_r_motor_speed();
}
