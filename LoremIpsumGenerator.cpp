// LoremIpsum++.cpp : Defines the entry point for the application.
//

#include "LoremIpsumGenerator.hpp"
#include <iostream>
#include <numeric>
#include <functional>
#include <chrono>

void measure_time(std::string prefix, std::function<void(int)> functionForMeasure, long rounds)
{
	auto startTime = std::chrono::high_resolution_clock::now();

	for (long i = 0; i < rounds; ++i)
	{
		functionForMeasure(i % 4);
	}

	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration< double > fs = endTime - startTime;

	std::cout << prefix << " function time (ms): "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(fs) << std::endl;

}

int main()
{
	std::cout << "3:" << lorem_ipsum::generate_lorem_ipsum_lines<3>() << std::endl << std::endl;

	std::cout << "R3:" << lorem_ipsum::generate_lorem_ipsum_lines(3) << std::endl << std::endl;


	measure_time("Runtime", [](int i) {
		lorem_ipsum::generate_lorem_ipsum_lines(24);
		}, 100000);

	measure_time("Static", [](int) {
		lorem_ipsum::generate_lorem_ipsum_lines<24>();
		}, 100000);
}