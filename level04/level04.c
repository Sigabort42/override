#include <unistd.h>

int	main()
{
	pid_t	pid;
	long	pt;
	int	status = 0;
	char	str[0x20];
	
	pid = fork();
	bzero(str, 0x20);
	if (!pid)
	{
		prctl(0x1, 0x1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(str);
		
	}
	else
	{
		while (1)
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0x7f)
			{
				puts("child is exiting...");
				break ;
			}
			else
			{
				pt = ptrace(0x3, pid, 0x2c, 0);
				if (pt == 0xb)
				{
					puts("no exec() for you");
					kill(pid, 0x9);
					break;
				}
			}	
		}
	}
	return (0);
}
