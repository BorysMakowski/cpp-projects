/*
implementation of sigmoid neuron
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
	return (1 / (1 + pow(2.7, -beta * x)));
}
double ff(double x)
{
	double beta = 1;
	return beta * f(x) * (1 - f(x));
}
class Neuron
{
public:
	Neuron(int size)
	{
		for (int i = 0; i < size; i++)
		{
			w.push_back(0);
		}
	}
	double getY(std::vector<double> dane)
	{
		return f(get_sum(dane));
	}
	double get_sum(std::vector<double> dane)
	{
		double suma = 0;

		for (int i = 0; i < dane.size(); i++) {
			suma += dane[i] * w[i];
		}
		suma += bias;

		return suma;
	}
	void zmiana_wag(double oczekiwane, std::vector<double> dane, double suma)
	{
		for (int i = 0; i < w.size(); i++)
		{
			w[i] += wspuczenia * (oczekiwane - f(suma)) * ff(suma) * dane[i];
		}
		bias += wspuczenia * (oczekiwane - f(suma)) * ff(suma);
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
	double bias = 0.0;
	double wspuczenia = 0.123;
	std::vector<double> w;
};

std::vector<double> jeden = { -1,-1, 1, -1,-1, 1, -1,-1, 1, -1, -1, 1 };
std::vector<double> cztery = { 1,-1, 1, 1, 1, 1, -1,-1, 1, -1, -1, 1 };
std::vector<std::vector<double>> dane = { jeden,  cztery };

double E[2] = { 10., 10. };
int oczekiwane[2] = { 0, 1 };



int main()
{
	Neuron h(12);
	int i = 0;
	int j;
	double newE, Y;
	while (((E[0] + E[1]) / 2) > 0.0001)
	{
		j = i % 2;
		Y = h.getY(dane[j]);
		h.zmiana_wag(oczekiwane[i % 2], dane[j], h.get_sum(dane[j]));
		newE = 0.5 * pow((oczekiwane[j] - Y), 2);
		E[i % 2] = newE;

		i++;
	}

	cout << "oczekiwane: " << oczekiwane[0] << ", otrzymane: " << h.getY(dane[0]) << ", blad: " << E[0] << std::endl;
	cout << "oczekiwane: " << oczekiwane[1] << ", otrzymane: " << h.getY(dane[1]) << ", blad: " << E[1] << std::endl;
	cout << "Iteracje: " << i << endl;
	h.show_weights();

	std::vector<double> zaszumionejeden = { -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1 };
	std::vector<double> zaszumionecztery = { 1, 1, 1, 1, 1, 1, -1,-1, 1, -1, -1, 1 };
	std::cout << "Wartosc zwrocona dla zaszumionej jedynki: " << h.getY(zaszumionejeden) << std::endl;
	std::cout << "Wartosc zwrocona dla zaszumionej czworki: " << h.getY(zaszumionecztery) << std::endl;

	return 0;
}
