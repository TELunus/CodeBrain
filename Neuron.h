#ifndef NEURON_H
#define NEURON_H

#include <vector>
#ifdef NERON_PRINT
#include <iostream>
#endif // NERON_PRINT

class Neuron
{
public:
	struct connection
	{
		Neuron& m_source;
		double m_weight;
	};
	Neuron();
	void UpdateState();
	void UpdateOutput();
	double getValue() const;
	void setValue(double);
	void addConnection(Neuron& source);
private:
	std::vector<connection> m_connections;
	double m_state;
	double m_output;
	double Activation(double) const;
};

double Logistic(double x);

#endif // NEURON_H
