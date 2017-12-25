#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Move.h"
#include <iostream>

void boardTest() {
	Board b(15,15);
	b.setGrid(&Move(2, 2, 1));
	b.setGrid(&Move(1, 1, 2));
	b.setGrid(&Move(7,10, 1));
	b.setGrid(&Move(13,10, 2));
	std::cout << b << std::endl;
}

int main()
{
	srand(static_cast<unsigned int>(std::time(0)));
	boardTest();

    return 0;
}


