/*  vs���Ҳ������ͷ�ļ�  */
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t  pid = fork();
	if (pid < 0)
		printf("error in fork!");
	else if (pid == 0)
		printf("�������ӽ���,�ҵĽ��̺���%d\n", getpid());
	else
		printf("�����ڸ�����,�ҵĽ��̺��� %\/n", getpid());

	return 0;
}