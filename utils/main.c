#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {

 int fd[2];

 if (pipe(fd) < 0)
    printf("pipe error");
int id = fork();
if (id < 0)
  printf("id 1 error");
if (id == 0)
{
    printf("id1\n");
  dup2(fd[1],STDOUT_FILENO);
  close(fd[0]);
  close(fd[1]);
 execlp("ping","ping","-c","5","google.com",NULL);
}
int id2 = fork();


if (id2 < 0)
  printf("id 2 error");
if (id2 == 0) {
  dup2(fd[0],STDIN_FILENO);
  close(fd[0]);
  close(fd[1]);
  execlp("grep","grep","ttl",NULL);
  printf("id2\n");
}

close(fd[0]);
close(fd[1]);
waitpid(id,NULL,0);
waitpid(id2,NULL,0);
return(0);
 }
