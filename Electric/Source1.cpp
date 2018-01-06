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
	RESISTER,
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
		return RESISTER;
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
	cout << "parallel" << endl;
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
	cout << "type: ";
	cin >> c_type;
	CircuitType type = toType(c_type);

	print_padding();
	switch (type)
	{
	case SERIES:
	case PARALLEL:
		size_t N;

		cout << "N: ";
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
	case RESISTER:
		float R;
		cout << "R:";
		cin >> R;
		return R;
		break;
	}
}

int main()
{
	
	float out = inputting();
	cout << "Output: " << out;
	char c;
	cin >> c;

	return 0;
}