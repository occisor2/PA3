#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "simulation.h"
#include "protocols.h"

static void logLatency(std::ofstream& logFile, size_t latency, size_t devices)
{
	logFile << devices << " " << latency << std::endl;
}

static void runSimulation(std::function<size_t(size_t)> protocol, size_t protocolInit,
						  const std::filesystem::path& logFilePath)
{
	constexpr auto reps = 10;
	std::ofstream logFile(logFilePath);
	
	for (auto devices = 100; devices <= 6000; devices += 100)
	{
		auto avgLatency = 0;

		std::cout << "Running Simulation for " << devices << " devices..." << std::endl;

		// Run multiple times to get an average latency
		for (auto i = 0; i < reps; ++i)
			avgLatency += PA3::simlulate(protocol, protocolInit, devices);

		avgLatency /= reps;
		
		logLatency(logFile, avgLatency, devices);
		std::cout << "Average latency: " << avgLatency << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		runSimulation(PA3::linear, PA3::linearInit, "linear.txt");
		runSimulation(PA3::logLog, PA3::logLogInit, "loglog.txt");
		runSimulation(PA3::binaryExp, PA3::binaryExpInit, "binexp.txt");
	}
	
	return EXIT_SUCCESS;
}
