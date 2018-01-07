#include<iostream>
#include<conio.h>

using namespace std;

const int MAX_STRING_INPUT = 10;

// TODO: AUTO INDENTATION, AUTO NUMBERING
// TODO[HARD]: Direct input of R in type (int/char reconize)
// TODO: re-input after wrong type inputting
// TODO: string type inputting (accept series,parallel as a word as a option)

float inputting();
void print_padding();

int indent_level = 0;

enum CircuitType
{
	SERIES,
	PARALLEL,
	RESISTOR,
};

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
	case 'C':
	case 'c':
		return RESISTOR;
		break;
	default:
		/*throw invalid_argument("invalid CircuitType's char representation");
		return ERROR;*/
		print_padding();
		cout << "invalid CircuitType's char representation";
	}
}

void print_padding()
{
	for (size_t i = 0; i < indent_level; i++)
	{
		cout << "\t";
	}
}

float n_in(size_t i)
{
	print_padding();
	cout << "Input (" << i << ")" << endl;
	indent_level += 1;
	return inputting();
}

float series(size_t N)
{
	print_padding();
	cout << "Series" << endl;
	float sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += n_in(i+1); // R = Sum = R1 + R2 + ...
		indent_level -= 1;
	}
	return sum;
}

float parallel(size_t N)
{
	print_padding();
	cout << "Parallel" << endl;
	float sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += 1/n_in(i + 1); // 1/R = Sum = 1/R1 + 1/R2 + ...
		indent_level -= 1;
	}
	return 1/sum; // 1/Sum = 1/1/R = R
}

float inputting()
{
	char c_type;
	print_padding();
	cout << "Circuit Type: ";
	cin >> c_type;
	CircuitType type = toType(c_type);

	print_padding();
	switch (type)
	{
	case SERIES:
	case PARALLEL:
		size_t N;

		cout << "Quantity: ";
		cin >> N;

		switch (type)
		{
		case SERIES:
			return series(N);
				break;
		case PARALLEL:
			return parallel(N);
			break;
		}
	case RESISTOR:
		float R;
		cout << "Resistance: ";
		cin >> R;
		return R;
		break;
	}
}

void guide()
{
	char g_type;
	cout << "Need a guide? (Y for Yes | Others for No) : ";
	cin >> g_type;
	
	if(g_type=='Y'){
		cout << endl;
		cout << "--Guide--" << endl;
		cout << endl;
		cout << "This calculator can calculate the summary of resistance in finite circuit." << endl;
		cout << endl;
		cout << "Start with looking a circuit in a big picture, it should be in Series, Parallel or Single resistor." << endl;
		cout << endl;
		cout << "Firstly, type off the type of the circuit from looking it in the big picture." << endl;
		cout << endl;
		cout << "Type S or s for Series circuit." << endl;
		cout << "Type P or p for Parallel circuit." << endl;
		cout << "Type R or r for Single Resistor" << endl;
		cout << endl;
		cout << "After that, you need to put in the quantity of the type of circuit you lastly put in." << endl;
		cout << endl;
		cout << "Then start submitting the rest of the circuit with the same code : S,s,P,p,R,r" << endl;
		cout << endl;
		cout << "Want a full guide? Visit : https://goo.gl/yRyjyB" << endl;
	}
	cout << endl;
	cout << "-----------------------" << endl;
	cout << endl;
}

int main()
{
	guide();
	float out = inputting();
	cout << "--------------------" << endl;
	cout << "Output: " << out;
	cout << endl;
	cout << "--------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Input anything to end the program." << endl;
	char c;
	cin >> c;

	return 0;
}
