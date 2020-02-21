
#include "Templates.h"

template <typename T>
T maximum(T a, T b)
{
	if (b > a) 
	{ 
		return b; 
	}
	return a;
}

int randBetween(int a, int b)
{
	return (rand() + a) % b;
}


template <typename T>
void shuffle(T& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int index = randBetween(i, vec.size());
		auto a = vec[index];
		vec[index] = vec[i];
		vec[i] = a;
	}
}

template <typename T>
void print(const T vec) 
{
	for (auto x : vec)
	{
		cout << x << " ";
	}
	cout << endl;
}

void testTemplate()
{
	int a = 1;
	int b = 2;
	int c = maximum(a, b);
	// c er nå 2.
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	double d = 2.4;
	double e = 3.2;
	double f = maximum(d, e);
	// f er nå 3.2
	cout << "d: " << d << " e: " << e << " f: " << f << endl << endl;

	//koden vil ikke kompilere fordi operatoren < eller > ikke er overlastet for den respektive klassen
	//løses ved å overlaste operatoren for den respektive klassen
	vector<string> cc{ "one", "two", "three", "four" };
	shuffle(cc); // Resultat, rekkefølgen i c er endret.
	print(cc);
	vector<int> aa{ 1, 2, 3, 4, 5, 6, 7 };
	shuffle(aa); // Resultat, rekkefølgen i a er endret.
	print(aa);
	vector<double> bb{ 1.2, 2.2, 3.2, 4.2 };
	shuffle(bb);
	print(bb);
}