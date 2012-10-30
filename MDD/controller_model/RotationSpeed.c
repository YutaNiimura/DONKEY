#include "RotationSpeed.h"

static int RS_targetValue = 0;

int RS_getValue() {
	return RE_getValue();
}

int RS_getTargetValue() {
	return RS_targetValue;
}

void RS_setTargetValue(int target) {
	RS_targetValue = target;
}
