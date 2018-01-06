#include<iostream>
#include<conio.h>

using namespace std;

const int MAX_STRING_INPUT = 10;

enum CircuitType
{
	SERIES,
	PARALLEL,
	RESISTER,
	MIXED,
	ERROR
};


struct Circuit
{
	CircuitType type;
	float value = -1;
};

void print_circuit(Circuit& circuit)
{
	cout << "==========" << endl;
	cout << "type: "<< circuit.type << endl;
	if (circuit.value >= 0)
	{
		cout << "value" << circuit.value << endl;
	}
	cout << "==========" << endl;
}

CircuitType toType(char t)
{
	switch (t)
	{
	case 'S':
	case 's':
		return SERIES;
		break;
	case 'P':
	case 'p':
		return PARALLEL;
		break;
	case 'R':
	case 'r':
		return RESISTER;
		break;
	default:
		throw invalid_argument("invalid CircuitType's char representation");
		return ERROR;
	}
}

CircuitType requestType()
{
	char c_type;
	cin >> c_type;
	return toType(c_type);
}

Circuit constructCircuit(CircuitType type, int count)
{
	struct Circuit circuit;

	// Single-Resister Circuit
	

	// Other Circuit
	for (size_t i = 0; i < count; i++)
	{
		cout << "Input for sub-circuit " << i;
	}

	return circuit;
}

void inputting()
{
	cout << "type: ";
	CircuitType type = requestType();	

	int count;
	cout << "N: ";
	cin >> count;

	struct Circuit circuit = constructCircuit(type, count);
	print_circuit(circuit);
}

int nmain()
{
	inputting();

	char c;
	cin >> c;

	return 0;
}