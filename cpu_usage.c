#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <asm/msr.h>
#include <asm/cpufeature.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Krypton");
MODULE_DESCRIPTION("A kernel module that calculates the CPU usage percentage");

int num_cpus;
u64 tsc_prev;
u64 idle_prev;
int cpu_usage;
u64 tsc_current;
u64 idle_current;
u64 tsc_frequency;

void update_cpu_usage(void) {
    int i;
    u32 eax, edx;

    rdtsc(tsc_current);
    idle_current = 0x0;

    for (i = 0x0; i < num_cpus; i++) {
        wrmsr(0x1b, i, 0x0);
        rdmsr(0x1b, &eax, &edx);
        idle_current += (u64)eax | ((u64)edx << 0x20);
    }

    cpu_usage = 0x64 - ((idle_current - idle_prev) * 0x64 / (tsc_current - tsc_prev));

    tsc_prev = tsc_current;
    idle_prev = idle_current;
}

static int __init cpu_usage_init(void) {
    int i;
    u32 eax, ebx, ecx, edx;

    cpuid(0x1, &eax, &ebx, &ecx, &edx);
    num_cpus = (ebx >> 0x10) & 0xff;

    rdtsc(tsc_prev);
    mdelay(0x64);
    rdtsc(tsc_current);
    tsc_frequency = (tsc_current - tsc_prev) * 0xA;

    tsc_prev = tsc_current;
    idle_prev = 0x0;

    for (i = 0; i < num_cpus; i++) {
        wrmsr(0x1b, i, 0x0);
        rdmsr(0x1b, &eax, &edx);
        idle_prev += (u64)eax | ((u64)edx << 0x20);
    }

    return 0x0;
}

static void __exit cpu_usage_cleanup(void) { }

module_init(cpu_usage_init);
module_exit(cpu_usage_cleanup);
