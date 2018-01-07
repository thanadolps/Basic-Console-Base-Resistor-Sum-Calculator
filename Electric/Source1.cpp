/** @file */

#include<iostream>
#include<conio.h>

using namespace std;

const int MAX_STRING_INPUT = 10;

// TODO: AUTO NUMBERING
// TODO[HARD]: Direct input of R in type (int/char reconize)
// TODO: re-input after wrong type inputting
// TODO: string type inputting (accept series,parallel as a word as a option)

float input_circuit_and_calculate_resistor();
void print_padding();

int indent_level = 0;

enum CircuitType
{
	SERIES,
	PARALLEL,
	RESISTER,
};

/**
	@param t 
	@return CircuitType assosiated with t
*/
CircuitType toType(char t)
{
	while (true)
	{
		switch (t)
		{
		case 'S':
		case 's':
			return SERIES;
		case 'P':
		case 'p':
			return PARALLEL;
		case 'R':
		case 'r':
		case 'C':
		case 'c':
			return RESISTER;
		default:
			print_padding();
			cout << "invalid CircuitType's char representation";
		}
	}
}

/** 
	@brief print padding (indent) whose length depend on [indent_level]

	print tabs to cout [inden_level] amount of time
*/
void print_padding()
{
	for (size_t i = 0; i < indent_level; i++)
	{
		cout << "\t";
	}
}


/**
	Print a header text before executing wrapping function input_circuit_and_calculate_resistor()
	header text is in format: Input({index}) where index come from parameter
	It's handle indent_level by increment and decrement it before and after excuting input_circuit_and_calculate_resistor() respectivly
	@brief function wrapper of input_circuit_and_calculate_resistor() used when inputting sub-circuit
	@param i index to display in header
	@return output from wrapping function: input_circuit_and_calculate_resistor()
*/
float circuit_input_with_header(size_t i)
{
	print_padding();
	cout << "Input (" << i << ")" << endl;
	indent_level += 1;
	float out = input_circuit_and_calculate_resistor();
	indent_level -= 1;
	return out;
}

/**
	@brief prompt input all sub-circuit and calculate overall resistance in series manner 
	This function try to calculate sum of all of it's sub-circuit resistance
	each of sub-circuit's resistance is found out by excuting circuit_input_with_header() 
	therefor prompting user to input sub-circuit on the go
	@param N Number of sub-circuit
	@return Overall Resistance
*/
float series(size_t N)
{
	cout << "Series" << endl;
	float sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += circuit_input_with_header(i+1); // R = Sum = R1 + R2 + ...
	}
	return sum;
}

/**
	@brief prompt input all sub-circuit and calculate overall resistance in parllel manner
	This function calculate combine of all of it's sub-circuit resistance using parllel equation
	each of sub-circuit's resistance is found out by excuting circuit_input_with_header()
	therefor prompting user to input sub-circuit on the go
	@param N Number of sub-circuit
	@return Overall Resistance
*/
float parallel(size_t N)
{
	cout << "parallel" << endl;
	float sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += 1/ circuit_input_with_header(i + 1); // 1/R = Sum = 1/R1 + 1/R2 + ...
	}
	return 1/sum; // 1/Sum = 1/1/R = R
}

/**
	prompt sub-circuit when type is series (S) or parallel (P) and resistance value when type is resistor (C or R)
	resistor resistance come from direct prompting 
	series and parallel come from excuting series(N) or parallel(N) respectivly
	those two function will endup calling input_circuit_and_calculate_resistor() again, making this recursive
	@brief prompt input type of circuit and either number of sub-circuit or resistance value (depands on type) 
	then calculate overall resistance value using it's type formula
	@return Overall Resistance
*/
float input_circuit_and_calculate_resistor()
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

		print_padding();
		switch (type)
		{
		case SERIES:
			return series(N);
				break;
		case PARALLEL:
			return parallel(N);
			break;
		}
	case RESISTER:
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

	if (g_type == 'Y') {
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

/**
	@brief main function, primally use for calling input_circuit_and_calculate_resistor() and display final output
*/
int main()
{
	guide();
	float out = input_circuit_and_calculate_resistor();
	cout << "--------------------" << endl;
	cout << "Output: " << out;
	cout << endl;
	cout << "--------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Input anything to end the program." << endl;

	// Stop Program from Instant Termination
	char c;
	cin >> c;

	return 0;
}