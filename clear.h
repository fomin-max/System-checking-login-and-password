#include <stdio.h>
#define N 33
#define NN 101
#pragma once

int fclear(){
  int b;
  while (1) {
    b=fgetc(stdin);
    if (b=='\n')
      break;
  }
  return 0;
}
int sclear (char *str){
  int i;
  i=sizeof(str);
  while (i!=0) {
    str[i]='\0';
    i--;
  }
  str[0]='\0';
  return 0;
}
char crypt (char *text){
	int i,key;
	key=1997;
	for(i=0;i!=strlen(text);i++)
		text[i]=text[i]^key;
}
