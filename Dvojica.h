#pragma once
#include <iostream>
#include <string>
class Dvojica
{
public:
	Dvojica();
	bool zacinaNaPismeno(char zPismeno) 
	{
		if (m_slovo.at(0) == zPismeno)
			return true;
		return false;
	}
	Dvojica(std::string slovo): m_nasledovnik(NULL), m_slovo(slovo) {}
	friend std::istream& operator >>(std::istream& is, Dvojica* b)
	{
		b->nacitaj(is);
		return is;
	}
	friend std::ostream& operator <<(std::ostream& os, Dvojica* b) //takyto zapis aby sa to dalo retazit
	{
		b->vypis(os);
		return os;
	}
	void setNasledovnik(Dvojica* next)
	{
		m_nasledovnik = next;
	}
	void show()
	{
		std::cout << m_slovo << std::endl;
		if (m_nasledovnik != NULL)
		{
			m_nasledovnik->show();
		}
	}
	void nacitaj(std::istream& is) { is >> m_slovo; };
	void vypis(std::ostream& os) { os << m_slovo; };
	std::string getSlovo() { return m_slovo; }
	virtual ~Dvojica();
private:
	std::string m_slovo;
	Dvojica* m_nasledovnik;
};

