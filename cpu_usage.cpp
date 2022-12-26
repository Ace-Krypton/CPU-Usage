#include <chrono>
#include <iostream>
#include <thread>

typedef long long long_2;
typedef unsigned long long u_long_2;

auto main() -> int {
    std::uint32_t leaf_extract[0x4];
    __asm__ __volatile__("mov $0x00000001, %eax\n\t");
    __asm__ __volatile__("cpuid\n\t");
    __asm__ __volatile__("mov %%ebx, %0\n\t":"=r" (leaf_extract[0x0]));
    __asm__ __volatile__("mov %%edx, %0\n\t":"=r" (leaf_extract[0x1]));
    __asm__ __volatile__("mov %%ecx, %0\n\t":"=r" (leaf_extract[0x2]));

    std::cout << ((leaf_extract[0x2] & (1 << 0x15)) ? "OK" : "NOT OK") << std::endl;

    uint clock_speed;
    long_2 elapsed_time;

    u_long_2 MSR_value;
    __asm__ __volatile__("rdmsr" : "=A"(MSR_value) : "c"(0x198));
    uint current_clock_speed = (uint)(MSR_value & 0xFFFFFFFF);

    uint new_clock_speed = 0x3E8;
    MSR_value &= ~0xFFFFFFFF;
    MSR_value |= new_clock_speed;
    __asm__ __volatile__("wrmsr" : : "c"(0x198), "A"(MSR_value));

    clock_speed = new_clock_speed;

    long_2 start_time = 0x0;
    __asm__ __volatile__("rdtsc" : "=A"(start_time));
    std::this_thread::sleep_for(std::chrono::milliseconds(0x3E8));
    long_2 end_time = 0x0;
    __asm__ __volatile__("rdtsc" : "=A"(end_time));
    elapsed_time = end_time - start_time;

    double usage_percentage = 0x64 * (double)elapsed_time / (double)(clock_speed * 0x3E8);
    std::cout << "CPU usage: " << usage_percentage << "%" << std::endl;

    MSR_value &= ~0xFFFFFFFF;
    MSR_value |= current_clock_speed;
    __asm__ __volatile__("wrmsr" : : "c"(0x198), "A"(MSR_value));

    return 0x0;
}
