#include <stdio.h>

int check(int pin[], int n){
  int i;
  int cnt = 0;
  if (n == 10){
    int left = pin[0] + pin[1] + pin[3] + pin[5];
    int right = pin[0] + pin[2] + pin[4] + pin[8];
    int bottom = pin[5] + pin[6] + pin[7] + pin[8];
    if ((left == right) && (left == bottom)){
      return 1;
    } else {
      return 0;
    }
  }
  for (i = 0; i < 10; i++){
    if (pin[i] == 0){
      pin[i] = n;
      cnt += check(pin, n + 1);
      pin[i] = 0;
    }
  }
  return cnt;
}

int main(void){
  int pin[10] = {0};

  printf("%d", check(pin, 1));

  return 0;
}
