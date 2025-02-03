#ifndef SIMULATED_DRAM_H
#define SIMULATED_DRAM_H

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <vector>

class DRAM {
public:
    std::unordered_map<uint64_t, uint32_t> memory; // Address -> Data mapping

    void save(uint64_t address, uint64_t data);
    void print_memory(uint64_t address);
    void save_simd(uint64_t address, const std::vector<uint64_t> &data);
};

#endif 
//use parser to parse through the tracefile 
//store the data into the specified physical address into the dram array from the tracefile