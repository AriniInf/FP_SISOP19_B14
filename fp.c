#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

struct{
  int tgl, bul, jam, hari, men;
  char path[256]; 
}line[1000];

int main(){
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  time_t rawtime;
  struct tm * timeinfo;
  int ind =0;
  int jumlah_line;
  FILE * file = fopen( "/home/ariniinf/Praktikum/FP/crontab.data","r");
  char s1[10], s2[10], s3[10], s4[10], s5[10], s6[256];
  while(fscanf(file,"%s %s %s %s %s",s1,s2,s3,s4,s5) != EOF){
    fgets(s6, 256, file);
    printf("%s\n %s\n %s\n %s\n %s\n %s\n", s1,s2,s3,s4,s5,s6);
    line[ind].men = s1[0]=='*'? -1 : atoi(s1);
    line[ind].jam = s2[0] =='*'? -1 : atoi(s2);
    line[ind].tgl = s3[0]=='*'? -1 :  atoi(s3);
    line[ind].bul = s4[0]=='*'? -1 : atoi(s4);
    line[ind].hari = s5[0]=='*'? -1 : atoi(s5);
    strcpy(line[ind].path, s6);
    ind++;
  }
  jumlah_line = ind;
  while(1){
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    for(ind=0;ind<jumlah_line;ind++){
    if(line[ind].men==timeinfo->tm_min || line[ind].men == -1){
      if(line[ind].jam==timeinfo->tm_hour || line[ind].jam == -1){
        if(line[ind].tgl==timeinfo->tm_mday || line[ind].tgl == -1){
          if(line[ind].bul==timeinfo->tm_mon+1 || line[ind].bul == -1){
            if(line[ind].hari==timeinfo->tm_wday || line[ind].hari == -1){
                system(line[ind].path);
            }
          }
        }
      }
    }
  }
  sleep(60); 
  }

  fclose(file);
  exit(EXIT_SUCCESS);
}