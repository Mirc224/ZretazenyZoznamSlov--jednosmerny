#pragma once
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include "Dvojica.h"
class ZretazenyZoznam
{
public:
	ZretazenyZoznam();
	void nacitaj(std::string fileName);
	void prvePismeno();

	virtual ~ZretazenyZoznam();
private:
	std::vector<Dvojica*> m_zoznam;
};

