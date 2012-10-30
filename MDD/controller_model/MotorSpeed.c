#include "MotorSpeed.h"

static int MS_targetValue = 0;

int MS_getValue() {
	return RE_getValue();
}

int MS_getTargetValue() {
	return MS_targetValue;
}

void MS_setTargetValue(int target) {
	MS_targetValue = target;
}
