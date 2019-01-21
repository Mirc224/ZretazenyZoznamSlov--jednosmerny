#include "ZretazenyZoznam.h"



ZretazenyZoznam::ZretazenyZoznam()
{
}

void ZretazenyZoznam::nacitaj(std::string fileName)
{
	std::ifstream inputFile(fileName);
	std::set<std::string> zoradenyZSlov;
	while (!inputFile.eof())
	{
		std::string tempSlovo;
		inputFile >> tempSlovo;
		zoradenyZSlov.insert(tempSlovo);
	}
	Dvojica* previous = NULL;
	for (auto &slovoZ : zoradenyZSlov)
	{
		Dvojica* tempDvojica = new Dvojica(slovoZ);
		if (previous != NULL)
		{
			previous->setNasledovnik(tempDvojica);
		}

		previous = tempDvojica;
		m_zoznam.push_back(tempDvojica);
	}
	std::ofstream outputFile("vystup.txt");
	for (auto &slovo : zoradenyZSlov)
	{
		outputFile << slovo << std::endl;
	}
	m_zoznam.front()->show();
}

void ZretazenyZoznam::prvePismeno()
{
	std::cout << "Zadajte pismeno: ";
	char temp;
	std::cin >> temp;
	std::vector<std::string> zoznamSlovNaPismeno;
	for (auto &p : m_zoznam)
	{
		if (p->zacinaNaPismeno(temp))
			zoznamSlovNaPismeno.push_back(p->getSlovo());
	}
	if (zoznamSlovNaPismeno.size() != 0)
	{
		for (auto &p : zoznamSlovNaPismeno)
		{
			std::cout << p;
			if(p != zoznamSlovNaPismeno.back())
			{
				std::cout << ", ";
			}
		}
			
	}
	else
		std::cout << "Take slovo neexistuje! \n";
}


ZretazenyZoznam::~ZretazenyZoznam()
{
	for (auto &p : m_zoznam)
		delete p;
}
