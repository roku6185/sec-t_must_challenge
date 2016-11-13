#include <stdio.h>

void main()
{
  unsigned long long int r12 = 0x53d606005744190c;
  unsigned long long int r13 = 0x5458020b474e131a;
  unsigned long long int r14 = 0x5a5d110b58cf1d0a;
  unsigned long long int r15 = 0x4e441c0e5e5e7e20;
  unsigned long long int rax, rbx, rcx;

  for (int i = 0; i < 34; i++)
  {
    // print first byte of stream: rbx=0x??
    rbx = r12;
    rbx = rbx >> 56;
    printf("{0x%x, %d, %c}\n", (int)rbx, (int)rbx, (int)rbx);

    // rcx: 0x00??00??00??00??
    rax = rbx;
    rax = rax << 48;
    rcx = rbx;
    rcx = rcx << 32;
    rcx = rcx | rbx;
    rbx = rbx << 16;
    rcx = rcx | rax;
    rcx = rcx | rbx;

    // shift stream 1 byte to the left
    r12 = r12 << 8;
    r12 = r12 | (r13 >> 56);
    r13 = r13 << 8;
    r13 = r13 | (r14 >> 56);
    r14 = r14 << 8;
    r14 = r14 | (r15 >> 56);
    r15 = r15 << 8;

    // XOR each part of stream with rcx
    r12 = r12 ^ rcx;
    r13 = r13 ^ rcx;
    r14 = r14 ^ rcx;
    r15 = r15 ^ rcx;
  }
}
