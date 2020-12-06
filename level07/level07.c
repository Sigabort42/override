#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	clear_stdin()
{
	char c = 0;

	while (42) {
		c = getchar();
		if (c == '\n' || c == -1)
			break ;
	}
}

int	get_unum()
{
	unsigned int n;

	fflush(stdout);
	scanf("%u", &n);
	clear_stdin();
	return (n);
}

int	store_number(char *buf)
{
	unsigned int n = 0;
	unsigned int i = 0;

	printf(" Number: ");
	n = get_unum();
	printf(" Index: ");
	i = get_unum();
	if (i % 3 == 0 || (n >> 0x18) == 0xb7) {
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
	*(unsigned int *)(buf + i * 4) = n;
	return (0);
}

int read_number(char *buf)
{
	unsigned int i;

	printf(" Index: ");
	i = get_unum();
	printf(" Number at data[%u] is %u\n", i, *(unsigned int *)(buf + i * 4));
	return (0);
}

int	main(int ac, char **av, char **evp)
{
	char		str[20];
	int		ret;
	int		i  = 0;
	unsigned int	tab[100] = {0};

        while (av[i])
        {
                memset(av[i], 0x0, strlen(av[i]));
                i++;
        }
        while (evp[i])
        {
                memset(evp[i], 0x0, strlen(evp[i]));
                i++;
        }
	puts("----------------------------------------------------\n" \
	     "  Welcome to wil's crappy number storage service!   \n" \
	     "----------------------------------------------------\n" \
	     " Commands:                                          \n" \
	     "    store - store a number into the data storage    \n" \
	     "    read  - read a number from the data storage     \n" \
	     "    quit  - exit the program                        \n" \
	     "----------------------------------------------------\n" \
	     "   wil has reserved some storage :>                 \n" \
	     "----------------------------------------------------\n" \
		);
	while(42)
	{
		printf("Input command: ");
		ret = 1;
		fgets(str, 0x14, stdin);
		str[strlen(str) - 1] = '\0';

		if(!strncmp(str, "store", 0x5))
			ret = store_number(data);
		else if(!strncmp(str, "read", 0x4))
			ret = read_number(data);
		else if(!strncmp(str, "quit", 0x4))
			break;
		if(str)
			printf(" Failed to do %s command\n", str);
		else
			printf(" Completed %s command successfully\n", str);
		memset(str, 0, 20);
	}
	return (0);
}
