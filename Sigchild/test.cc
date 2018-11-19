#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
using namespace std;

void handler(int signo)
{
    if(pid_t ret=(wait(NULL)) != -1)
    {
        cout << "child exit process" << ret <<endl;
    }
}
int main()
{
    struct sigaction act,oact;
    act.sa_handler=handler;
    act.sa_flags=0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD,&act,&oact);
    pid_t id = fork();
    if(id == 0)
    {
        cout << "i am child run..." << endl;
        sleep(3);
        _exit(1);
    }
    else{
        while(1)
        {
            cout << "i am a parent:"<<getpid()<<endl;
            sleep(1);
        }
    }
}
