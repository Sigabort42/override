#include <stdio.h>

int	auth(char *login, unsigned int u)
{
	size_t	n;
	size_t	len;
	int	tmp;
	int	tmp2;
	
	n = strcspn(login, "\n");
	login[n] = 0;
	len = strnlen(login, 0x20);
	if (len <= 0x5)
		return (1);
	else
	{
		if (ptrace(0, 0, 1, 0) == -1)
		{
			puts("\033[32m.___________________________.");
			puts("\033[31m| !! TAMPERING DETECTED !!  |");
			puts("\033[32m.___________________________.");
			return (1);
		}
		tmp = (login[3] ^ 0x1337) + 0x5eeded;
		tmp2 = 0;
		while (tmp2 < len)
		{
			if (login[tmp] >= 0x1f)
				return (1);
			int	eax, edx, ecx;
			int	mul_res[2];

			ecx = login[tmp] ^ tmp;
			(int64_t)*mul_res = ecx * 0x88233b2b;
			eax = (ecx - mul_res[1]) >> 1;
			eax += mul_res[1];
			eax >>= 10;
			eax *= 1337;
			edx = ecx - eax;
			tmp += edx;
		}
		tmp++;
		if (u != tmp)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char		str[46];
	unsigned int	u;
	
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(str, 0x20, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &u);
	if (!auth(str, u))
	{
		puts("Authenticated!");
		system("/bin/sh");
		
	}
	//canary
	return (0);
}
