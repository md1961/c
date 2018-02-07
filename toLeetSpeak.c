#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toLeetSpeak (char *speak) {
  char* charsFrom = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* charsTo   = "@8(D3F6#!JK1MN0PQR$7UVWXY2";
  
  char* result = (char *)malloc(strlen(speak) + 1);
  for (int i = 0, sz = strlen(speak); i < sz; i++) {
    char c = speak[i];
    char* p = strchr(charsFrom, c);
    if (p != NULL) {
      int offset = (int)p - (int)charsFrom;
      c = charsTo[offset];
    }
    result[i] = c;
  }
  result[strlen(speak)] = '\0';
  return result;
}

int main(void) {
    printf("%s\n", toLeetSpeak("!@#$%^&*JUMPS!()[];';<>,."));
    printf("%s\n", toLeetSpeak("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG"));

    return 0;
}
