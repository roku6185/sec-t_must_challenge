#include <stdio.h>

void printreg(const char *str, unsigned long long int reg)
{
  printf("%s", str);

  for (int i = 7; i >= 0; i--)
  {
    int tmp = (reg >> i*8) & 0xFF;
    printf("%02x", tmp);
  }

  printf("\n");
}

void main()
{
  unsigned long long int r12 = 0x414202060602020e;
  unsigned long long int r13 = 0x0e0202060602021e;
  unsigned long long int r14 = 0x1e0202060602020e;
  unsigned long long int r15 = 0x0e02696b02020606;
  const char *input = "\x41\x42\x02\x06\x06\x02\x02\x0e" \
  		      "\x0e\x02\x02\x06\x06\x02\x02\x1e" \
  		      "\x1e\x02\x02\x06\x06\x02\x02\x0e" \
  		      "\x0e\x02\x69\x6b\x02\x02\x06\x06";
  unsigned long long int rax, rbx, rcx;
  unsigned long long one = 0x0, two = 0x0;

  for (int i = 0; i < 32; i++)
  {
    // print first byte of stream: rbx=0x??
    rbx = r12;
    rbx = rbx >> 56;
    printf("{0x%x, %d, %c}\n", (int)rbx, (int)rbx, (int)rbx);
    printreg("1] R12=0x", r12);

    // rcx: 0x00??00??00??00??
    unsigned long long int tmp = input[i] & 0xff;
    rcx = (tmp << 48) | (tmp << 32) | (tmp << 16) | tmp;

    // shift stream 1 byte to the left
    r12 = (r12 << 8) | (r13 >> 56);
    r13 = (r13 << 8) | (r14 >> 56);
    r14 = (r14 << 8) | (r15 >> 56);
    r15 = (r15 << 8);
    printreg("2] R12=0x", r12);

    printreg("3] RCX=0x", rcx);

    // XOR each part of stream with rcx
    r12 = r12 ^ rcx;
    r13 = r13 ^ rcx;
    r14 = r14 ^ rcx;
    r15 = r15 ^ rcx;
    printreg("4] R12=0x", r12);
  }
}
