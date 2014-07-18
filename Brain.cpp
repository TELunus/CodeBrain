#include "Brain.h"

Brain::Brain(std::string initializationString):m_greyMatter()
{
	std::stringstream stringProcessor(initializationString);
	unsigned long numNeurons;
	char mostRecentDelimiter;
	stringProcessor>>numNeurons;
	std::cout<<"num neurons: "<<numNeurons<<std::endl;
	mostRecentDelimiter = stringProcessor.peek();
	//std::cout<<"got delimiter: '"<<mostRecentDelimiter<<"'"<<std::endl;
	for(unsigned long i = 0;i<numNeurons;i++)
	{
		m_greyMatter.push_back(Neuron());
	}
	if(mostRecentDelimiter != ';')
	{
		std::cout<<"Error: brain initialized with incorrect delimiter following neuron count"<<std::endl;
		return;
	}
	mostRecentDelimiter = ',';
	long targetNeuronIndex;
	long sourceNeuronIndex;
	char sinkChar;
	while(mostRecentDelimiter == ','&& stringProcessor.good())
	{
		stringProcessor>>sinkChar;
		//std::cout<<"next char is: '"<<(char)stringProcessor.peek()<<"'"<<std::endl;
		stringProcessor>>targetNeuronIndex;
		std::cout<<"got target: "<<targetNeuronIndex<<std::endl;
		mostRecentDelimiter = stringProcessor.peek();
		//std::cout<<"got delimiter: '"<<mostRecentDelimiter<<"'"<<std::endl;
		while(mostRecentDelimiter == ' '&&stringProcessor.good())
		{
			stringProcessor>>sourceNeuronIndex;
			std::cout<<"got source: "<<sourceNeuronIndex<<std::endl;
			mostRecentDelimiter = stringProcessor.peek();
			//std::cout<<"got delimiter: '"<<mostRecentDelimiter<<"'"<<std::endl;
			m_greyMatter.at(targetNeuronIndex).addConnection(m_greyMatter.at(sourceNeuronIndex));
		}
	}

}

std::string Brain::print()const
{
	std::string result = "";
	for(unsigned long i = 0;i < m_greyMatter.size();i++)
	{
		char num = '0'+i;
		result += num;
		result += ": ";
		result += m_greyMatter.at(i).print();
	}
	return result;
}
