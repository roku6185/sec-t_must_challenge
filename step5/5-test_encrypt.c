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
  unsigned long long int r12 = 0x4142434445464748;
  unsigned long long int r13 = 0x494a4b4c4d4e4f50;
  unsigned long long int r14 = 0x5152535455565758;
  unsigned long long int r15 = 0x595a303132333435;
  unsigned long long int rax, rbx, rcx;

  for (int i = 0; i < 34; i++)
  {
    // print first byte of stream: rbx=0x??
    rbx = r12;
    rbx = rbx >> 56;
    printf("{0x%x, %d, %c}\n", (int)rbx, (int)rbx, (int)rbx);
    printreg("1] R12=0x", r12);
    //printf("R12=0x%llx\n", r12);
    //printf("R13=0x%llx\n", r13);
    //printf("R14=0x%llx\n", r14);
    //printf("R15=0x%llx\n", r15);



    // rcx: 0x00??00??00??00??
    // H?J?O?I?
    // ?
    rcx = (rbx << 48) | (rbx << 32) | (rbx << 16) | rbx;
    //printf("RCX=0x%llx\n", rcx);

    // shift stream 1 byte to the left
    r12 = (r12 << 8) | (r13 >> 56);
    r13 = (r13 << 8) | (r14 >> 56);
    r14 = (r14 << 8) | (r15 >> 56);
    r15 = (r15 << 8);
    printreg("2] R12=0x", r12);
    //printf("R12=0x%llx\n", r12);
    //printf("R13=0x%llx\n", r13);
    //printf("R14=0x%llx\n", r14);
    //printf("R15=0x%llx\n", r15);
    printreg("3] RCX=0x", rcx);

    // XOR each part of stream with rcx
    r12 = r12 ^ rcx;
    r13 = r13 ^ rcx;
    r14 = r14 ^ rcx;
    r15 = r15 ^ rcx;
    printreg("3] R12=0x", r12);
  }
}
