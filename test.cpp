#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

void handler(int signo)
{
	cout << "catch a signo :" << signo << "pid :"<< getpid() <<endl;
	sleep(5);
	exit(1);
}

int main()
{
	alarm(5);
	signal(SIGALRM,NULL); //捕捉8号信号，执行hander指针指向的自定义函数的动作,若为空，执行默认处理动作
    //5秒后，给进程发送SIGALRM,14信号，返回值是0
	int i=0;
	while(1) {
		i++;
	}
//	cout << i  << endl;
//	while(1){
//		if(i++ > 5){
//			i /= 0;  //程序运行错误，发送SIGFPE,8信号
//		}
//		cout << "hello word : pid :" << getpid() << endl;
//		sleep(1);
//	}
////////////////////////////////////////////////////////////
//	pid_t id = fork();
//	if(id==0){
//		while(1){
//			cout << "pid: " << getpid() << endl;
//			sleep(5);
//		//	kill(getppid(),9);  
//		//	raise(1);   //给当前进程发信号
//		//	abort();    //使当前进程接收到信号而终止
//		}
//	}
//	else
//	{
//		sleep(10);
//	}
	return 0;
}
