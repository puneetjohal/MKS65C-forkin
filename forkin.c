#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  srand(time(NULL));

  int ppid = getpid();
  printf("PPID: %d\n", ppid);

  int firstChild, secondChild;
  firstChild = fork();
  if (getpid() == ppid) {secondChild = fork();}

  if (getpid() != ppid) {
    printf("PID: %d\n", getpid());
    int sleepTime = (rand() % 15) + 5;
    sleep(sleepTime);
    printf("slept\n");
    return sleepTime;
  }

  if (getpid() == ppid){
    int status;
    int child = wait(&status);
    printf("child with PID %d has exited. It slept for %d seconds\n", child, status);
    printf("parent done");
  }


  return 0;
}
