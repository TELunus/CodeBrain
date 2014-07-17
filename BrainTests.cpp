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
    Neuron testNeuron;
    testNeuron.setValue(0.5);
    testNeuron.UpdateOutput();
    //std::cout<<testNeuron.getValue();
    assert(dequal(testNeuron.getValue() , 0.5));
}
