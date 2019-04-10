#include <bits/stdc++.h>
#include "BruteForce.h"
#include "JiushaoQin.h"

template<class T>
std::pair<double, double> Test(T func, int argc, double argv[])
{
	double c0 = clock();
	for (int i = 0; i < 10000; ++i)
		for (int j = 0; j < 10000; ++j)
			func(argc, argv);
	double total = (clock() - c0) / CLOCKS_PER_SEC;
	return std::make_pair(total, func(argc, argv));
}

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cout << "Please input like ./main 1 1 1 3" << std::endl;
		return 0;
	}
	double arr[100] = {0};
	for (int i = 1; i < argc; ++i)
		arr[i] = atof(argv[i]);
	std::pair<double, double>
	pol_bf = Test(BF::polynomial, argc, arr),
	pos_bf = Test(BF::posynomial, argc, arr),
	pol_qin = Test(Qin::polynomial, argc, arr),
	pos_qin = Test(Qin::posynomial, argc, arr);
	std::cout << "Brute Force:" << std::endl;
	std::cout << "\tPolynomial: Time " << pol_bf.first / 100 << "us\t Result " << pol_bf.second << std::endl;
	std::cout << "\tPosynomial: Time " << pos_bf.first / 100 << "us\t Result " << pos_bf.second << std::endl;
	std::cout << "Jiushao Qin:" << std::endl;
	std::cout << "\tPolynomial: Time " << pol_qin.first / 100 << "us\t Result " << pol_qin.second << std::endl;
	std::cout << "\tPosynomial: Time " << pos_qin.first / 100 << "us\t Result " << pos_qin.second << std::endl;

	std::cout << "Brute Force / Jiushao Qin = { " << pol_bf.first / pol_qin.first << ", " << pos_bf.first / pos_qin.first << " }" << std::endl;
	return 0;
}
