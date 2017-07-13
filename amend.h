#include <stdio.h>
#include "clear.h"

int delstr(int num){
  char str[NN];
  int len=0;
  FILE *in=fopen("passwd","r");
  FILE *out=fopen("passwd2","w");
  sclear(str);
  while (fgets(str,NN,in)!=NULL) {
    len+=strlen(str);
    if (len!=num)
      fputs(str,out);
  }
  fclose(out);
  fclose(in);
  return 0;
  }

int del(){
  system("rm passwd");
  system("mv passwd2 passwd");
}

int chLogin(char *passwd, char *name){
  int i;
  char str[NN];
  char glogin[N];
  char login[N];
  char end[NN];
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
  if (strcmp("exit",glogin)==0){
    system("clear");
    printf("Do not use 'exit'\n");
    goto plog;
  }
  if (strlen(glogin)<2){
    system("clear");
    printf("Login must be longer than 1 characters\n\n");
    goto plog;
  }
  i=0;
  while(glogin[i]!='\0'){
    if(glogin[i]==':'){
      system("clear");
      printf("Can not use ':'\n\n");
      goto plog;
    }
    i++;
  }
  FILE *file=fopen("passwd","r");
  sclear(str);
  while (fgets(str,NN,file)!=NULL) {
    i=0;
    sclear(login);
    while(str[i]!=':'){
      login[i]=str[i];
      i++;
    }
    if(strcmp(glogin,login)==0){
      system("clear");
      printf("This name is using!\nTry again\n\n");
      goto plog;
    }
  }
  fclose(file);
  sclear(end);
  strcat(end,glogin);
  strcat(end,":");
  strcat(end,passwd);
  strcat(end,":");
  strcat(end,name);
  strcat(end,"\n\0");
  FILE *logfile=fopen("passwd2","a+");
  fputs(end,logfile);
  fclose(logfile);
  return 0;
}

int chPasswd(char *login, char *name){
  int i;
  char passwd[N];
  char end[NN];
  ppass:
  sclear(passwd);
  printf("Password:\n");
  fgets(passwd,N,stdin);
  passwd[strlen(passwd)-1]='\0';
  if (strlen(passwd)==N-2) {
    system("clear");
    printf("Overfull!\nPut Password less then 30 number\n\n");
    fclear();
    goto ppass;
  }
  if (strcmp("exit",passwd)==0){
    system("clear");
    printf("Do not use 'exit'\n");
    goto ppass;
  }
  if (strlen(passwd)<5){
    system("clear");
    printf("Password must be longer than 4 characters\n\n");
    goto ppass;
  }
  i=0;
  while(passwd[i]!='\0'){
    if(passwd[i]==':'){
      system("clear");
      printf("Can not use ':'\n\n");
      goto ppass;
    }
    i++;
  }
  crypt(passwd);
  sclear(end);
  strcat(end,login);
  strcat(end,":");
  strcat(end,passwd);
  strcat(end,":");
  strcat(end,name);
  strcat(end,"\n\0");
  FILE *passfile=fopen("passwd2","a+");
  fputs(end,passfile);
  fclose(passfile);
  return 0;
}

int chName(char *login, char *passwd){
  int i;
  char name[N];
  char end[NN];
  pname:
  sclear(name);
  printf("Name:\n");
  fgets(name,N,stdin);
  name[strlen(name)-1]='\0';
  if (strlen(name)==N-2) {
    system("clear");
    printf("Overfull!\nPut Name less then 30 number\n\n");
    fclear();
    goto pname;
  }
  if (strcmp("exit",name)==0){
    system("clear");
    printf("Do not use 'exit'\n");
    goto pname;
  }
  if (strlen(name)<2){
    system("clear");
    printf("Name must be longer than 1 characters\n\n");
    goto pname;
  }
  i=0;
  while(name[i]!='\0'){
    if(name[i]==':'){
      system("clear");
      printf("Can not use ':'\n\n");
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
  FILE *namefile=fopen("passwd2","a+");
  fputs(end,namefile);
  fclose(namefile);
  return 0;
}

int amend(char *login, char *passwd, char *name, int num){
  int a;
  in:
  system("clear");
  printf("What do you want to change?\n1.Login\n2.Password\n3.Name\n4.Exit\n");
  scanf("%d",&a);
  fclear();
  switch (a) {
    case 1:
      delstr(num);
      chLogin(passwd,name);
      del();
      break;

    case 2:
      delstr(num);
      chPasswd(login,name);
      del();
      break;

    case 3:
      delstr(num);
      chName(login,passwd);
      del();
      break;

    case 4:
      exit(1);

    default:
      goto in;
  }
  return 0;
}
