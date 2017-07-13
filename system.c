#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "signin.h"
#include "clear.h"

int main() {
  int a;
    while(1) {
    system("clear");
    printf("Welcome to the best system in the world!\n(You can enter exit and go out)\n1.Sign in\n2.Exit\n");
    scanf("%d",&a);
    fclear();
    switch (a) {
      case 1:
        sign();
        break;

      case 2:
        exit(1);

      default:
        break;
    }
  }
  return 0;
}
