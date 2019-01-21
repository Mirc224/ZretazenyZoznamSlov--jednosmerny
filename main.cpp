#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include "ZretazenyZoznam.h"
#include <string>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ZretazenyZoznam temp = ZretazenyZoznam();
	temp.nacitaj("slova.txt");
	temp.prvePismeno();

	return 0;
}