#pragma once
#include <windows.h>

#if _WIN64

#define IsWoW64 IsWoW64
__asm__("IsWoW64: \n\
	mov rax, 0 \n\
	ret \n\
");

#define ZwProtectVirtualMemory NtProtectVirtualMemory
__asm__("NtProtectVirtualMemory: \n\
	push rcx \n\
	push rdx \n\
	push r8 \n\
	push r9 \n\
	sub rsp, 0x28 \n\
	call GetSyscallAddress \n\
	add rsp, 0x28 \n\
	push rax \n\
	sub rsp, 0x28 \n\
	mov ecx, 0x0099D1B07 \n\
	call SW2_GetSyscallNumber \n\
	add rsp, 0x28 \n\
	pop r11 \n\
	pop r9 \n\
	pop r8 \n\
	pop rdx \n\
	pop rcx \n\
	mov r10, rcx \n\
	jmp r11 \n\
");

#define ZwWriteVirtualMemory NtWriteVirtualMemory
__asm__("NtWriteVirtualMemory: \n\
	push rcx \n\
	push rdx \n\
	push r8 \n\
	push r9 \n\
	sub rsp, 0x28 \n\
	call GetSyscallAddress \n\
	add rsp, 0x28 \n\
	push rax \n\
	sub rsp, 0x28 \n\
	mov ecx, 0x0CD9FF0DB \n\
	call SW2_GetSyscallNumber \n\
	add rsp, 0x28 \n\
	pop r11 \n\
	pop r9 \n\
	pop r8 \n\
	pop rdx \n\
	pop rcx \n\
	mov r10, rcx \n\
	jmp r11 \n\
");

#define ZwSetInformationProcess NtSetInformationProcess
__asm__("NtSetInformationProcess: \n\
	push rcx \n\
	push rdx \n\
	push r8 \n\
	push r9 \n\
	sub rsp, 0x28 \n\
	call GetSyscallAddress \n\
	add rsp, 0x28 \n\
	push rax \n\
	sub rsp, 0x28 \n\
	mov ecx, 0x0912F8AA0 \n\
	call SW2_GetSyscallNumber \n\
	add rsp, 0x28 \n\
	pop r11 \n\
	pop r9 \n\
	pop r8 \n\
	pop rdx \n\
	pop rcx \n\
	mov r10, rcx \n\
	jmp r11 \n\
");

#endif