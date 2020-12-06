#include <stdio.h>

int	main()
{
	int	enter;
	
	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &enter);
	if (enter == 0x149c)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
		return (0);
	}
	puts("\nInvalid Password!");
	return (1);
}
