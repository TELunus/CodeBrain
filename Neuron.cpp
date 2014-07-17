#include "Neuron.h"
#include <math.h>

Neuron::Neuron():m_connections(),m_state(0),m_output(0)
{

}

double Neuron::getValue() const
{
    return m_output;
}

double Neuron::Activation(double state) const
{
	static const double b = 1;
	return Logistic(state*b);
}

void Neuron::Update1()
{
	double sum = 0;
	//double avg = 0;
	for(unsigned int i = 0;i<m_connections.size();i++)
	{
		sum += m_connections.at(i).m_weight*m_connections.at(i).m_source.getValue();
		//avg += m_connections.at(i).m_weight*m_connections.at(i).m_source.getValue();
	}
	//avg/=sum;
	m_state = Activation(sum);
}

void Neuron::Update2()
{
	m_output = m_state;
}

void Neuron::setValue(double value)
{
	m_state = value;
}

void Neuron::addConnection(Neuron& source)
{
	connection addition = {source,1};
	m_connections.push_back(addition);
}

double Logistic(double x)
{
	return 1.0/(1.0 + exp(-x));
}
