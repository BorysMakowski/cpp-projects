/*
implementation of hebb neuron
recognises whether a given "picture" is a 1 or a 4
in this program, a picture is a vector containing -1 or 1 representing pixels, for example
representation of "1" = { -1, -1, 1,
			  -1, -1, 1,
			  -1, -1, 1,
			  -1, -1, 1 };
*/
#include <vector>
#include <iostream>
using namespace std;

double f(double x)
{
	double beta = 1;
	return (1 - exp(-beta * x)) / (1 + exp(-beta * x));
}

class Hebb
{
public:
	Hebb(int size)
	{
		for (int i = 0; i < size; i++)
		{
			w.push_back(0);
		}
	}
	double getY(std::vector<double> dane)
	{
		double suma = 0;

		for (int i = 0; i < dane.size(); i++) {
			suma += dane[i] * w[i];
		}
		suma += bias;

		return f(suma);
	}
	void zmiana_wag(double oczekiwane, std::vector<double> dane, double Y)
	{
		for (int i = 0; i < w.size(); i++)
		{
			w[i] += wspuczenia * oczekiwane * dane[i];
		}
		bias += wspuczenia * oczekiwane * Y;
	}
	void show_weights()
	{
		std::cout << "bias: " << bias << "," << std::endl;
		for (int i = 0; i < w.size(); i++)
		{
			std::cout << "W[" << i << "] = " << w[i] << std::endl;
		}
	}
private:
	double wspuczenia = 0.123;
	std::vector<double> w;
	double bias = 0.0;
};

std::vector<double> jeden = { -1, -1, 1, 
							  -1, -1, 1, 
							  -1, -1, 1, 
							  -1, -1, 1 };
std::vector<double> cztery = { 1, -1, 1, 
                               1, 1, 1, 
	                          -1, -1, 1, 
	                          -1, -1, 1 };
std::vector<std::vector<double>> dane = { jeden,  cztery };

double E[2] = { 10., 10. };
int oczekiwane[2] = { -1, 1 };

int main()
{
	Hebb h(12);
	int i = 0;

	while (((E[0] + E[1]) / 2) > 0.00001)
	{
		int j = i % 2;
		double Y = h.getY(dane[j]);
		h.zmiana_wag(oczekiwane[i % 2], dane[j], Y);
		double newE = 0.5 * pow((oczekiwane[j] - Y), 2);
		E[i % 2] = newE;
		cout << "oczekiwane: " << oczekiwane[j] << ", otrzymane: " << Y << ", blad: " << newE << std::endl;
		if (!j)
			cout << "------------" << endl;
		i++;
	}

	cout << "Iteracje: " << i << std::endl;
	h.show_weights();

	std::vector<double> zaszumionejeden = { -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1 };
	std::vector<double> zaszumionecztery = { 1, 1, 1, 1, 1, 1, -1,-1, 1, -1, -1, 1 };
	std::cout << "Wartosc zwrocona dla zaszumionej jedynki: " << h.getY(zaszumionejeden) << std::endl;
	std::cout << "Wartosc zwrocona dla zaszumionej czworki: " << h.getY(zaszumionecztery) << std::endl;

	return 0;
}
