/*
implementation of a network of 2 sigmoid neurons
recognises whether a given "picture" is a 1, 2, 4 or a 7
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

std::vector<double> jeden = { -1, -1, 1, -1, -1, 1, -1,-1, 1, -1, -1, 1 };
std::vector<double> cztery = { 1, -1, 1, 1, 1, 1, -1,-1, 1, -1, -1, 1 };
std::vector<double> siedem = { 1, 1, 1, -1,-1, 1, -1,-1, 1, -1, -1, 1 };
std::vector<double> dwa = { -1, -1, -1, 1,1, -1, 1,-1, 1, -1, -1, -1 };
std::vector<std::vector<double>> dane = { jeden, dwa,  cztery, siedem };


double E[4] = { 10., 10., 10., 10. }; // błąd
int oczekiwane[4] = { 0, 0, 1, 1 };
int oczekiwane2[4] = { 0, 1, 0, 1 };



int main()
{
	Neuron h(12);
	int i = 0;
	int j;
	double newE, Y;
	while (((E[0] + E[1] + E[2] + E[3]) / 4) > 0.0001)
	{
		j = i % 4;
		Y = h.getY(dane[j]);
		h.zmiana_wag(oczekiwane[j], dane[j], h.get_sum(dane[j]));
		newE = 0.5 * pow((oczekiwane[j] - Y), 2);
		E[i % 4] = newE;
		i++;
		//cout << "oczekiwane: " << oczekiwane2[j] << ", otrzymane: " << h.getY(dane2[j]) << ", blad: " << E2[j] << std::endl;
		//if (!j)
		//	cout << "======" << endl;
	}
	cout << "Iteracje: " << i << endl;
	h.show_weights();

	Neuron hh(12);
	//i = 0;
	for (int i = 0; i < 4; i++)
		E[i] = 10.;
	while (((E[0] + E[1] + E[2] + E[3]) / 4) > 0.0001)
	{
		j = i % 4;
		Y = hh.getY(dane[j]);
		hh.zmiana_wag(oczekiwane2[j], dane[j], hh.get_sum(dane[j]));
		newE = 0.5 * pow((oczekiwane2[j] - Y), 2);
		E[i % 4] = newE;
		i++;
		//cout << "oczekiwane: " << oczekiwane2[j] << ", otrzymane: " << hh.getY(dane[j]) << ", blad: " << E[j] << std::endl;
		//if (!j)
		//	cout << "======" << endl;
	}


	cout << endl;
	cout << "Iteracje: " << i << endl;
	hh.show_weights();
	cout << endl;

	cout << "cyfra 1, " << endl;
	cout << "	neuron 1: " << h.getY(jeden) << ", neuron 2: " << hh.getY(jeden) << std::endl;
	cout << "cyfra 2, " << endl;
	cout << "	neuron 1: " << h.getY(dwa) << ", neuron 2: " << hh.getY(dwa) << std::endl;
	cout << "cyfra 4, " << endl;
	cout << "	neuron 1: " << h.getY(cztery) << ", neuron 2: " << hh.getY(cztery) << std::endl;
	cout << "cyfra 7, " << endl;
	cout << "	neuron 1: " << h.getY(siedem) << ", neuron 2: " << hh.getY(siedem) << std::endl;




	return 0;
}


