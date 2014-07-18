#include "BrainTests.h"

bool dequal(double comparitand, double comparisee)
{
	static const double threshold = 0.001;
	double result = (comparitand - comparisee);
	result *= result;
	return result <= threshold*threshold;
}

void BrainTests()
{
    std::vector<Neuron> testNeurons;
    for(unsigned long i = 0;i<5;i++)
	{
		testNeurons.push_back(Neuron());
	}
    testNeurons.at(0).setValue(0.5);
    testNeurons.at(0).UpdateOutput();

    for(unsigned long i = 1;i<3;i++)
    {
    	testNeurons.at(0).addConnection(testNeurons.at(i));
    }

    //std::cout<<testNeuron.getValue();
    std::cout<<std::endl<<"test1:";
    assert(dequal(testNeurons.at(0).getValue() , 0.5));
    std::cout<<std::endl<<"test2:";
    Brain("5;2");
    std::cout<<std::endl<<"test3:";
    Brain("5,2");
    std::cout<<std::endl<<"test4:";
    for(unsigned long i = 0; i<testNeurons.size();i++)
	{
		std::cout<<testNeurons.at(i).print();
	}
	std::cout<<std::endl<<"test5:";
	Brain testBrain("5; 0 1 3, 2 4 1;");
	std::cout<<testBrain.print();
}
