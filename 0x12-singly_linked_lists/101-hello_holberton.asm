section .data
    hello_message db 'Hello, Holberton,', 0xA ; Null-terminated string with newline character (0xA)

section .text
    global _start

_start:
    ; syscall number for sys_write (1), sys_exit (60)
    mov rax, 1                   ; syscall number for sys_write
    mov rdi, 1                   ; file descriptor 1 (stdout)
    mov rsi, hello_message       ; pointer to the message to print
    mov rdx, 18                  ; length of the message (excluding null-terminator)
    syscall                      ; invoke the syscall to print the message

    ; Exit the program
    mov rax, 60                  ; syscall number for sys_exit
    xor rdi, rdi                 ; exit code 0
    syscall                      ; invoke the syscall to exit


