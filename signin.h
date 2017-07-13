#include <stdio.h>
#include <string.h>
#include "clear.h"
#include "amend.h"

int sign(){
  int k=0,i,num=0;
  char str[NN];
  char glogin[N];
  char login[N];
  char gpasswd[N];
  char passwd[N];
  char name[N];
  system("clear");
  plog:
  printf("Login:\n");
  sclear(glogin);
  fgets(glogin,N,stdin);
  glogin[strlen(glogin)-1]='\0';
  if (strlen(glogin)==N-2) {
    system("clear");
    printf("Overfull!\nPut Login less then 30 number\n\n");
    fclear();
    goto plog;
  }
  if (strcmp("exit",glogin)==0)
    return 0;
  FILE *file=fopen("passwd","r");
  sclear(str);
  while (fgets(str,NN,file)!=NULL) {
    i=0;
    sclear(login);
    while(str[i]!=':'){
      login[i]=str[i];
      i++;
    }
    num+=strlen(str);
    if(strcmp(glogin,login)==0) {
      i++;
      k=0;
      sclear(passwd);
      while(str[i]!=':') {
        passwd[k]=str[i];
        i++;
        k++;
      }
      crypt(passwd);
      i++;
      k=0;
      sclear(name);
      while (str[i]!='\n') {
        name[k]=str[i];
        i++;
        k++;
      }
      k=1;
      break;
    }
  }
  fclose(file);
  if(k==1){
    k=0;
    while(1){
      ppass:
      printf("Password:\n");
      sclear(gpasswd);
      fgets(gpasswd,N,stdin);
      gpasswd[strlen(gpasswd)-1]='\0';
      if (strlen(gpasswd)==N-2) {
        system("clear");
        printf("Overfull!\nPut Password less then 30 number\n\n");
        fclear();
        goto ppass;
      }
      if (strcmp("exit",gpasswd)==0)
        return 0;
      if(strcmp(gpasswd,passwd)==0)
        break;
      else
        k++;
      if(k>2){
        system("clear");
        printf("Error!\nIncorrect password!\n\n");
        exit(1);
      }
    }
  }
  else {
    system("clear");
    printf("This user is not found!\nTry again\n\n");
    goto plog;
  }
  while(1){
    system("clear");
    printf("Hello, %s\n",name);
    printf("What do you want?\n1.Change accaunt\n2.Sign out\n");
    scanf("%d",&k);
    crypt(passwd);

    switch (k) {
      case 1:
        amend(login,passwd,name,num);

      case 2:
      return 0;

      default:
        break;
    }
  }
  return 0;
}
