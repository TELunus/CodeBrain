#include <iostream>
#include "Neuron.h"
#ifdef DEBUG
#include "BrainTests.h"
#endif // DEBUG

using namespace std;

int main()
{
	#ifdef DEBUG
	cout << "Welcome" << endl;
	BrainTests();
	#endif // DEBUG

    return 0;
}
