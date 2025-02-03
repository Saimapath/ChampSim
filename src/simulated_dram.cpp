#include "simulated_dram.h"

#define SIMD_size 2
void DRAM::save(uint64_t address, uint64_t data) {
    uint64_t physical_address = v2p_address(address);
    memory[physical_address] = data;
}

void DRAM::save_simd(uint64_t address, const std::vector<uint64_t> &data) {
    // if (data.size() != 8) {
    //     std::cerr << "Error: SIMD store requires 8 elements (256 bits)\n";
    //     return;
    // }
    uint64_t physical_address = v2p_address(address);
    for (size_t i = 0; i < SIMD_size; i++) {
        memory[physical_address + (i * sizeof(uint64_t))] = data[i];
    }
}

void DRAM::print_memory(uint64_t address) {
    uint64_t physical_address = v2p_address(address);
    if (memory.find(physical_address) != memory.end()) {
        std::cout << "Data at " << std::hex << physical_address << ": " << memory[physical_address] << std::endl;
    } else {
        std::cout << "No data found at " << std::hex << physical_address << std::endl;
    }
}
