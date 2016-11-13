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
  unsigned long long r12 = 0x53d655d651444e48;
  unsigned long long r13 = 0x4d54565345455454;
  unsigned long long r14 = 0x49474b5649c445c5;
  unsigned long long r15 = 0x534e524a4250207e;
  const char *input = "\x53\xd6\x55\xd6\x51\x44\x4e\x48" \
  		      "\x4d\x54\x56\x53\x45\x45\x54\x54" \
  		      "\x49\x47\x4b\x56\x49\xc4\x45\xc5" \
  		      "\x53\x4e\x52\x4a\x42\x50\x20\x7e";

/*
  unsigned long long int r12 = 0x53d606005744190c;
  unsigned long long int r13 = 0x5458020b474e131a;
  unsigned long long int r14 = 0x5a5d110b58cf1d0a;
  unsigned long long int r15 = 0x4e441c0e5e5e7e20;
  const char *input = "\x53\xd6\x06\x00\x57\x44\x19\x0c" \
  		      "\x54\x58\x02\x0b\x47\x4e\x13\x1a" \
  		      "\x5a\x5d\x11\x0b\x58\xcf\x1d\x0a" \
  		      "\x4e\x44\x1c\x0e\x5e\x5e\x7e\x20";
*/
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
