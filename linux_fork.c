#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//work only on POSIX
//program run one parent process and two child processes

int ProcesPotomny(char);
int ProcesMacierzysty(pid_t, pid_t);

void main()
{
	pid_t id, second_child;
	printf("To jest proces macierzysty - poczatek\n");
	switch (id = fork())
	{
	case -1:
		perror("fork");
		exit(EXIT_FAILURE);
		break;
	case 0:
		ProcesPotomny('A');
		break;
	default:
		second_child = fork();
		if (second_child == 0)
		{
			ProcesPotomny('B');
		}
		else
		{
			ProcesMacierzysty(id, second_child);
		}
		break;
	}


}

int ProcesPotomny(char a)
{
	int i;
	printf("To dzieciak %c!\n", a);
	for (i = 0; i < 20; i++)
	{
		sleep(1);
		printf("Pid dzieciaka %c: %i\n", a, getpid());
	}
	exit(EXIT_SUCCESS);
	return 0;
}

int ProcesMacierzysty(pid_t pid, pid_t second)
{
	printf("A to rodzic!\n");
	printf("Pid rodzica: %u\n", getpid());
	sleep(3);
	printf("Rodzic wie ze ma dziecko: %u oraz drugie dziecko: %u\n", pid, second);
	kill(pid, SIGKILL);
	kill(second, SIGKILL);
	wait(NULL);
	exit(EXIT_SUCCESS);
	return 0;

}
