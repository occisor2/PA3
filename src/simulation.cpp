#include "simulation.h"
#include <cstddef>
#include <utility>
#include <vector>
#include <random>
#include <iostream>

static std::pair<size_t, size_t> countSuccesses(const std::vector<size_t>& win)
{
	auto sucesses = 0;
	auto lastSuccessSlot = 0;

	for (auto i = 0; i < win.size(); ++i)
	{
		if (1 == win[i])
		{
			++sucesses;
			lastSuccessSlot = i;
		}
	}

	return std::make_pair(sucesses, lastSuccessSlot);
}

size_t PA3::simlulate(std::function<size_t(size_t)> protocol, size_t protWinInit, size_t devices)
{
	auto remaining = devices;
	auto latency = 0;
	// Set each to have 0 successes
	std::vector<size_t> win(protWinInit, 0);
	// Initialize distribution for devices to pick slots
	std::random_device rd;	
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, win.size() - 1);
	
	for (;;)
	{		
		// Simulate choices
		for (auto i = 0; i < remaining; ++i)
		{
			auto choice = dist(gen);
			win[choice] += 1;
		}

		auto [sucesses, lastSuccess] = countSuccesses(win);

		if (sucesses > 0)
		{
			if (0 == (remaining -= sucesses))
				return latency += lastSuccess;	
		}

		// Add window size to latency
		latency += win.size();
		// Increase window size with the protocol
		win.resize(protocol(win.size()));
		// Remove any previous successes
		std::fill(win.begin(), win.end(), 0);
		// Reset distribution to accomodate window size
		dist = std::uniform_int_distribution<>(0, win.size() - 1);
	}
}
