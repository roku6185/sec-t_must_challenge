#include <stdio.h>

void main()
{
  asm("movabs $0x53d606005744190c,%r12");
  asm("movabs $0x5458020b474e131a,%r13");
  asm("movabs $0x5a5d110b58cf1d0a,%r14");
  asm("movabs $0x4e441c0e5e5e7e20,%r15");

  for (int i = 0; i < 34; i++)
  {
    asm("mov    %r12,%rbx");
    asm("shr    $0x38,%rbx");
    asm("mov    %rbx,%rax");
    asm("shl    $0x30,%rax");
    asm("mov    %rbx,%rcx");
    asm("shl    $0x20,%rcx");
    asm("or     %rbx,%rcx");
    asm("shl    $0x10,%rbx");
    asm("or     %rax,%rcx");
    asm("or     %rbx,%rcx");
    asm("shld   $0x8,%r13,%r12");
    asm("xor    %rcx,%r12");
    asm("shld   $0x8,%r14,%r13");
    asm("xor    %rcx,%r13");
    asm("shld   $0x8,%r15,%r14");
    asm("xor    %rcx,%r14");
    asm("shl    $0x8,%r15");
    asm("xor    %rcx,%r15");
  }
}
