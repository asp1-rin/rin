#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    printf("==================================\n");
    printf("     RIN-ENGINE v1.0 Loading...   \n");
    printf("==================================\n");

    if (argc < 3) {
        printf("[Usage] ./rin-engine [PID] [Address(Hex)]\n");
        return 1;
    }

    int pid = atoi(argv[1]);
    unsigned long long addr = strtoull(argv[2], NULL, 16);
    
    char path[64];
    sprintf(path, "/proc/%d/mem", pid);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("[-] Error: Cannot open memory. Check Root/SU.\n");
        return 1;
    }

    int value = 0;
    if (pread(fd, &value, sizeof(value), addr) == -1) {
        printf("[-] Error: Read failed at 0x%llX\n", addr);
    } else {
        printf("[+] [RIN-RESULT] 0x%llX => %d\n", addr, value);
    }

    close(fd);
    return 0;
}
