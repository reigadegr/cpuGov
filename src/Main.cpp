#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#if 0
    路径:
    for i in 0 4 7; do
        负载: cat /sys/devices/system/cpu/cpu$i/core_ctl/global_state
        频率表: /sys/devices/system/cpu/cpu$i/cpufreq/scaling_available_frequencies
    done
#endif

auto readFreqMap(int cpuGroup, std::vector<int>& numbers) -> bool
{
    std::string path;
    path = ("/sys/devices/system/cpu/cpu" + std::to_string(cpuGroup) +
            "/cpufreq/scaling_available_frequencies")
               .c_str();

    if (!std::filesystem::exists(path)) {
        return false;
    }

    std::ifstream map(path);
    std::string line;
    while (std::getline(map, line)) {
        std::istringstream iss(line);
        int freq;
        while (iss >> freq) {
            numbers.push_back(freq);
        }
    }

    return true;
}

auto main(int argc, char** argv) -> int
{
    std::vector<int> numbers0;
    std::vector<int> numbers4;
    std::vector<int> numbers7;

    readFreqMap(0, numbers0);
    readFreqMap(4, numbers4);
    readFreqMap(7, numbers7);

    for (const auto& tmp : numbers0) {
        std::cout << tmp << std::endl;
    }
    std::cout << "下一个" << std::endl;

    for (const auto& tmp : numbers4) {
        std::cout << tmp << std::endl;
    }
    std::cout << "下一个" << std::endl;

    for (const auto& tmp : numbers7) {
        std::cout << tmp << std::endl;
    }
}
