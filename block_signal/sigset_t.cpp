#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

void show(sigset_t* pending)
{
	int i=1;
	for(; i <= 31; i++){
	   cout<<sigismember(pending,i);
    }
	cout << endl;
}
void handler(int signal)
{
	cout << signal << endl;
}
int main()
{
//	signal(SIGINT,handler);
	sigset_t set;               //新的信号集
	sigset_t oset;              //旧的信号集
	sigset_t pending;           //未决信号集（是否收到信号）
	sigemptyset(&set);
	sigemptyset(&oset);
	sigemptyset(&pending);

	sigaddset(&set,2);

//	sigaddset(&pending,SIGINT);  //把SIGINT添加到pending信号集
	sigprocmask(SIG_SETMASK,&set,&oset); //重置信号屏蔽字 
//	sigprocmask(SIG_BLOCK,&set,&oset); //设置阻塞信号集，阻塞SIGINT信号
	while(1){
		sigpending(&pending);  //读取当前进程的未决信号集
		show(&pending);
		sleep(1);
	}
	return 0;
}
