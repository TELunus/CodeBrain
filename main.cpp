#include <iostream>
#include "Neuron.h"
#ifdef DEBUG
#include "BrainTests.h"
#endif // DEBUG

using namespace std;

int main()
{
	#ifdef DEBUG
	BrainTests();
	#endif // DEBUG
    cout << "Hello world!" << endl;

    return 0;
}
