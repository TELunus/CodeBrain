#ifndef BRAIN_H
#define BRAIN_H

#include<vector>
#include<string>
#include<iostream>
#include<sstream>

#include"Neuron.h"

class Brain
{
public:
	Brain(std::string initializationString);
	void Update();
	std::string print()const;
private:
	std::vector<Neuron> m_greyMatter;
};

#endif // BRAIN_H
