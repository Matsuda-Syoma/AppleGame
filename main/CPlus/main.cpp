#include"POS.h"

int main(void) {

	POS pos;
	POS pos1;

	pos.x = 100.0;
	pos.y = 200.0;
	pos1.x = 300.0;
	pos1.y = 10.0;

	pos.print();
	pos1.print();

	return 0;
}