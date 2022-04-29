/*
implementation of perceptron
finds constants of a linear function that separates points (x1,x2) with different classifiers d[]
linear function: x1 * w1 + x2 * w2 + w0 = 0
*/
#include <iostream>

int main()
{
	double x1[7] = { 2, 2, 0, -2, -2, 0, 4 };
	double x2[7] = { 1, 2, 6, 10, 0, 0, -20 };
	double d[7] = { 1, 1, 1, -1, -1, -1, -1 };
	double w[3] = { 0, 0, 0 };
	bool mod = 1;
	int it = 0;

	while (mod)
	{
		mod = 0;
		std::cout << "================================" << std::endl;
		for (int i = 0; i < 7; i++)
		{
			int y = 0;
			double s = w[0] + x1[i] * w[1] + x2[i] * w[2];
			if (s > 0)
				y = 1;
			else
				y = -1;
			std::cout << "Y: " << y << ", D: " << d[i];
			if (y != d[i])
			{
				std::cout << "  <-- modify" << std::endl;
				w[0] = w[0] + d[i];
				w[1] = w[1] + x1[i] * d[i];
				w[2] = w[2] + x2[i] * d[i];
				mod = 1;
			}
			else
				std::cout << std::endl;
		}
		it++;
	}
	std::cout << "W[0]= " << w[0] << "  W[1]= " << w[1] << "  W[2]= " << w[2] << std::endl;
	std::cout << "Iteracje: " << it << std::endl;


}

