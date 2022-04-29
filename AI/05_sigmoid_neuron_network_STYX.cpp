/*
implementation of a network of 3 sigmoid neuros
recognises whether a given "picture" represents S, T, Y, X, E, F, G, H
in this program, a picture is a vector containing -1 or 1 representing pixels, for example
representation of "S"  = { 1, -1, -1, -1, 1,
			              -1, 1, 1, 1, -1,
			              -1, 1, 1, 1, 1,
			               1, -1, -1, -1, 1,
			               1, 1, 1, 1, -1,
			               -1, 1, 1, 1, -1,
			               1, -1, -1, -1, 1 };
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

std::vector<double> S = { 1, -1, -1, -1, 1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, 1,
						 1, -1, -1, -1, 1,
						 1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 1, -1, -1, -1, 1 };

std::vector<double> T = { -1, -1, -1, -1, -1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1 };

std::vector<double> Y = { -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 1, -1, 1, -1, 1,
						 1, -1, 1, -1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1 };

std::vector<double> X = { -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 1, -1, 1, -1, 1,
						 1, 1, -1, 1, 1,
						 1, -1, 1, -1, 1,
						 -1, 1, 1, 1, -1,
						-1, 1, 1, 1, -1 };

std::vector<double> EE = { -1, -1, -1, -1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, -1, -1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, -1, -1, -1, 1 };

std::vector<double> F = { -1, -1, -1, -1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, -1, -1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, 1, 1 };

std::vector<double> G = { 1, -1, -1, -1, 1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, 1,
						 -1, 1, -1, -1, 1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 1, -1, -1, -1, 1 };

std::vector<double> H = { -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 -1, -1, -1, -1, -1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1 };

std::vector<double> _S = { 1, 1, -1, -1, 1,
						 -1, 1, -1, 1, -1,
						 -1, 1, 1, 1, 1,
						 1, -1, -1, -1, 1,
						 1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 1, -1, 1, -1, 1 };

std::vector<double> _T = { -1, -1, -1, -1, -1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 -1, 1, -1, 1, 1,
						 -1, 1, -1, 1, 1,
						 1, 1, 1, 1, 1 };

std::vector<double> _Y = { -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 1, 1, 1, -1, 1,
						 1, -1, -1, -1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, 1,
						 1, 1, -1, 1, -1 };

std::vector<double> _X = { -1, 1, 1, 1, -1,
						 -1, -1, 1, 1, -1,
						 1, -1, 1, -1, -1,
						 1, 1, 1, 1, 1,
						 1, -1, 1, -1, 1,
						 -1, 1, 1, 1, -1,
						-1, 1, 1, 1, -1 };

std::vector<double> _EE = { -1, -1, -1, -1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, -1, 1, 1,
						 -1, -1, -1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, -1, 1, 1, 1,
						 -1, 1, -1, -1, 1 };

std::vector<double> _F = { -1, -1, -1, -1, -1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, -1, -1, 1, 1,
						 -1, -1, 1, 1, 1,
						 -1, 1, 1, 1, 1,
						 -1, 1, 1, -1, 1 };

std::vector<double> _G = { 1, -1, -1, -1, 1,
						 -1, 1, -1, 1, -1,
						 -1, 1, 1, 1, 1,
						 -1, -1, -1, -1, 1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, -1, -1,
						 1, -1, -1, -1, 1 };

std::vector<double> _H = { -1, -1, -1, -1, -1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 -1, -1, -1, -1, -1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1,
						 -1, 1, 1, 1, -1 };






std::vector<std::vector<double>> dane = { EE, F, G, H, S, T, Y, X };

double E[8] = { 10., 10., 10., 10., 10., 10., 10., 10. };


int oczekiwane[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
int oczekiwane2[8] = { 0, 0, 1, 1, 0, 0, 1, 1 };
int oczekiwane3[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };



int main()
{
	Neuron h(35);
	int i = 0;
	int j;
	double newE, y;
	while (((E[0] + E[1] + E[2] + E[3] + E[4] + E[5] + E[6] + E[7]) / 8) > 0.0001)
	{
		j = i % 8;
		y = h.getY(dane[j]);
		h.zmiana_wag(oczekiwane[j], dane[j], h.get_sum(dane[j]));
		newE = 0.5 * pow((oczekiwane[j] - y), 2);
		E[j] = newE;
		i++;
		//cout << "oczekiwane: " << oczekiwane2[j] << ", otrzymane: " << h.getY(dane2[j]) << ", blad: " << E2[j] << std::endl;
		//if (!j)
		//	cout << "======" << endl;
	}
	cout << "Iteracje: " << i << endl;
	h.show_weights();
	cout << endl;

	Neuron hh(35);
	//i = 0;
	for (int i = 0; i < 8; i++)
		E[i] = 10.;
	while (((E[0] + E[1] + E[2] + E[3] + E[4] + E[5] + E[6] + E[7]) / 8) > 0.0001)
	{
		j = i % 8;
		y = hh.getY(dane[j]);
		hh.zmiana_wag(oczekiwane2[j], dane[j], hh.get_sum(dane[j]));
		newE = 0.5 * pow((oczekiwane2[j] - y), 2);
		E[j] = newE;
		i++;
		//cout << "oczekiwane: " << oczekiwane2[j] << ", otrzymane: " << hh.getY(dane[j]) << ", blad: " << E[j] << std::endl;
		//if (!j)
		//	cout << "======" << endl;
	}
	cout << "Iteracje: " << i << endl;
	hh.show_weights();
	cout << endl;

	Neuron hhh(35);
	//i = 0;
	for (int i = 0; i < 8; i++)
		E[i] = 10.;
	while (((E[0] + E[1] + E[2] + E[3] + E[4] + E[5] + E[6] + E[7]) / 8) > 0.0001)
	{
		j = i % 8;
		y = hhh.getY(dane[j]);
		hhh.zmiana_wag(oczekiwane3[j], dane[j], hhh.get_sum(dane[j]));
		newE = 0.5 * pow((oczekiwane3[j] - y), 2);
		E[j] = newE;
		i++;
		//cout << "oczekiwane: " << oczekiwane3[j] << ", otrzymane: " << hhh.getY(dane[j]) << ", blad: " << E[j] << std::endl;
		//if (!j)
		//	cout << "======" << endl;
	}


	cout << "Iteracje: " << i << endl;
	hhh.show_weights();
	cout << endl;


	cout << "E: " << endl;
	cout << "	neuron 1: " << h.getY(EE) << ", neuron 2: " << hh.getY(EE) << ", neuron 3: " << hhh.getY(EE) << std::endl;
	cout << "F: " << endl;
	cout << "	neuron 1: " << h.getY(F) << ", neuron 2: " << hh.getY(F) << ", neuron 3: " << hhh.getY(F) << std::endl;
	cout << "G: " << endl;
	cout << "	neuron 1: " << h.getY(G) << ", neuron 2: " << hh.getY(G) << ", neuron 3: " << hhh.getY(G) << std::endl;
	cout << "H: " << endl;
	cout << "	neuron 1: " << h.getY(H) << ", neuron 2: " << hh.getY(H) << ", neuron 3: " << hhh.getY(H) << std::endl;
	cout << "S: " << endl;
	cout << "	neuron 1: " << h.getY(S) << ", neuron 2: " << hh.getY(S) << ", neuron 3: " << hhh.getY(S) << std::endl;
	cout << "T: " << endl;
	cout << "	neuron 1: " << h.getY(T) << ", neuron 2: " << hh.getY(T) << ", neuron 3: " << hhh.getY(T) << std::endl;
	cout << "Y: " << endl;
	cout << "	neuron 1: " << h.getY(Y) << ", neuron 2: " << hh.getY(Y) << ", neuron 3: " << hhh.getY(Y) << std::endl;
	cout << "X: " << endl;
	cout << "	neuron 1: " << h.getY(X) << ", neuron 2: " << hh.getY(X) << ", neuron 3: " << hhh.getY(X) << std::endl;

	cout << endl;
	cout << endl;
	cout << "zaszumione E: " << endl;
	cout << "	neuron 1: " << h.getY(_EE) << ", neuron 2: " << hh.getY(_EE) << ", neuron 3: " << hhh.getY(_EE) << std::endl;
	cout << "zaszumione F: " << endl;
	cout << "	neuron 1: " << h.getY(_F) << ", neuron 2: " << hh.getY(_F) << ", neuron 3: " << hhh.getY(_F) << std::endl;
	cout << "zaszumione G: " << endl;
	cout << "	neuron 1: " << h.getY(_G) << ", neuron 2: " << hh.getY(_G) << ", neuron 3: " << hhh.getY(_G) << std::endl;
	cout << "zaszumione H: " << endl;
	cout << "	neuron 1: " << h.getY(_H) << ", neuron 2: " << hh.getY(_H) << ", neuron 3: " << hhh.getY(_H) << std::endl;
	cout << "zaszumione S: " << endl;
	cout << "	neuron 1: " << h.getY(_S) << ", neuron 2: " << hh.getY(_S) << ", neuron 3: " << hhh.getY(_S) << std::endl;
	cout << "zaszumione T: " << endl;
	cout << "	neuron 1: " << h.getY(_T) << ", neuron 2: " << hh.getY(_T) << ", neuron 3: " << hhh.getY(_T) << std::endl;
	cout << "zaszumione Y: " << endl;
	cout << "	neuron 1: " << h.getY(_Y) << ", neuron 2: " << hh.getY(_Y) << ", neuron 3: " << hhh.getY(_Y) << std::endl;
	cout << "zaszumione X: " << endl;
	cout << "	neuron 1: " << h.getY(_X) << ", neuron 2: " << hh.getY(_X) << ", neuron 3: " << hhh.getY(_X) << std::endl;

	cout << endl;
	cout << endl;
	cout << "Roznica: " << endl;
	cout << "E: " << endl;
	cout << "	neuron 1: " << h.getY(_EE) - h.getY(EE) << ", neuron 2: " << hh.getY(_EE) - hh.getY(EE) << ", neuron 3: " << hhh.getY(_EE) - hhh.getY(EE) << std::endl;
	cout << "F: " << endl;
	cout << "	neuron 1: " << h.getY(_F) - h.getY(F) << ", neuron 2: " << hh.getY(_F) - hh.getY(F) << ", neuron 3: " << hhh.getY(_F) - hhh.getY(F) << std::endl;
	cout << "G: " << endl;
	cout << "	neuron 1: " << h.getY(_G) - h.getY(G) << ", neuron 2: " << hh.getY(_G) - hh.getY(G) << ", neuron 3: " << hhh.getY(_G) - hhh.getY(G) << std::endl;
	cout << "H: " << endl;
	cout << "	neuron 1: " << h.getY(_H) - h.getY(H) << ", neuron 2: " << hh.getY(_H) - hh.getY(H) << ", neuron 3: " << hhh.getY(_H) - hhh.getY(H) << std::endl;
	cout << "S: " << endl;
	cout << "	neuron 1: " << h.getY(_S) - h.getY(S) << ", neuron 2: " << hh.getY(_S) - hh.getY(S) << ", neuron 3: " << hhh.getY(_S) - hhh.getY(S) << std::endl;
	cout << "T: " << endl;
	cout << "	neuron 1: " << h.getY(_T) - h.getY(T) << ", neuron 2: " << hh.getY(_T) - hh.getY(T) << ", neuron 3: " << hhh.getY(_T) - hhh.getY(T) << std::endl;
	cout << "Y: " << endl;
	cout << "	neuron 1: " << h.getY(_Y) - h.getY(Y) << ", neuron 2: " << hh.getY(_Y) - hh.getY(Y) << ", neuron 3: " << hhh.getY(_Y) - hhh.getY(Y) << std::endl;
	cout << "X: " << endl;
	cout << "	neuron 1: " << h.getY(_X) - h.getY(X) << ", neuron 2: " << hh.getY(_X) - hh.getY(X) << ", neuron 3: " << hhh.getY(_X) - hhh.getY(X) << std::endl;




	return 0;
}

