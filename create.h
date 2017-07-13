#include <stdio.h>
#include "clear.h"

int create(){
  int i=0;
  char glogin[N];
  char login[N];
  char passwd[N];
  char gpasswd[N];
  char name[N];
  char end[NN];
  char str[NN];
  plog:
  printf("Login:\n");
  sclear(login);
  fgets(login,N,stdin);
  login[strlen(login)-1]='\0';
  if (strlen(glogin)==N-2) {
    printf("\nOverfull!\nPut Login less then 30 number\n\n");
    fclear();
    goto plog;
  }
  if (strcmp("exit",glogin)==0)
    return 0;
  if (strlen(login)<2){
    printf("Login must be longer than 1 characters\n\n");
    goto plog;
  }
  while(login[i]!='\0'){
    if(login[i]==':'){
      printf("\nCan not use ':'\n\n");
      goto plog;
    }
    i++;
  }
  FILE *file=fopen("passwd","r");
  sclear(str);
  while (fgets(str,NN,file)!=NULL) {
    i=0;
    sclear(glogin);
    while(str[i]!=':'){
      glogin[i]=str[i];
      i++;
    }
    if(strcmp(glogin,login)==0){
      printf("\nThis name is using!\nTry again\n\n");
      goto plog;
    }
  }
  fclose(file);

  ppass:
  printf("Password:\n");
  sclear(passwd);
  fgets(passwd,N,stdin);
  passwd[strlen(passwd)-1]='\0';
  if (strlen(passwd)==N-2) {
    printf("Overfull!\nPut Password less then 30 number\n\n");
    fclear();
    goto ppass;
  }
  if (strcmp("exit",passwd)==0)
    return 0;
  if (strlen(passwd)<5){
    printf("Password must be longer than 4 characters\n\n");
    goto ppass;
  }
  i=0;
  while(passwd[i]!='\0'){
    if(passwd[i]==':'){
      printf("\nCan not use ':'\n\n");
      goto ppass;
    }
    i++;
  }
  printf("Enter the password again:\n");
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
  if (strcmp(passwd,gpasswd)!=0){
    printf("\nIncorrect password!\nTry again\n\n");
    goto ppass;
  }
  crypt(passwd);

  pname:
  printf("Name:\n");
  sclear(name);
  fgets(name,N,stdin);
  name[strlen(name)-1]='\0';
  if (strlen(name)==N-2) {
    system("clear");
    printf("Overfull!\nPut Name less then 30 number\n\n");
    fclear();
    goto pname;
  }
  if (strcmp("exit",name)==0)
    return 0;
  if (strlen(name)<2){
    printf("Name must be longer than 1 characters\n\n");
    goto pname;
  }
  i=0;
  while(name[i]!='\0'){
    if(name[i]==':'){
      printf("\nCan not use ':'\n\n");
      goto pname;
    }
    i++;
  }

  sclear(end);
  strcat(end,login);
  strcat(end,":");
  strcat(end,passwd);
  strcat(end,":");
  strcat(end,name);
  strcat(end,"\n\0");
  FILE *create=fopen("passwd","a+");
  fputs(end,create);
  fclose(create);
  return 0;
}
