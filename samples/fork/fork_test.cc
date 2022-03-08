#include <stdio.h>  
#include <unistd.h>  
#include <signal.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <sys/wait.h>  
#include <string.h> 

void wait4children(int signo) {  
  int status;  
  while(waitpid(-1, &status, WNOHANG) > 0);  
}  
   
int main()
{
    pid_t ret;

    signal(SIGCHLD, wait4children);  
    if ((ret = fork()) < 0)
    {
        fprintf(stderr,"fork fail. ErrNo[%d],ErrMsg[%d]\n", errno, strerror(errno));
    }
    else if (0 == ret)
    {
        fprintf(stdout,"** child  process run. pid:[%6d], ppid:[%6d],ret:[%6d]  **\n", getpid(), getppid(), ret);
        sleep(3);
        //exit(0);  //  可以结束掉子进程,那么程序将不会再运行最后一行的printf,原因在于:fork之后的代码父子进程都可见都会执行,通过if可以控制父子进程进行执行不同的内容,原理在于fork不同于其他函数他返回两个值,给父进程返回的是子进程的pid,给子进程自己返回的是0,失败返回 -1,于是当在if中碰到exit自然子进程就结束了
    }
    else
    {
        fprintf(stdout,"** parent process run. pid:[%6d], ppid:[%6d],ret:[%6d]  **\n",getpid(), getppid(),ret);
    }

    printf("========== last line.  pid:[%6d], ppid:[%6d],ret:[%6d] ==========\n",getpid(),getppid(),ret);
}