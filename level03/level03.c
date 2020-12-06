#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	decrypt(int decalage)
{
	int	str = 0x757c7d51;
	int	str2 = 0x67667360;
	int	str3 = 0x7b66737e;
	int	str4 = 0x33617c7d;
	unsigned int	str_len = strlen((char*)&str);
	char	c = 0;
	int	i = 0;
	char   	*tmp;

	while (i < str_len) {
		tmp = (char*)&str + i;
		*tmp = (int)*tmp ^ decalage;
		i++;
	}
	if (strncmp((char*)&str, "Congratulations!", 17) == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
}

void	test(int pass, unsigned int x)
{
	int	tmp;

	tmp = x - pass;
	if (tmp >= 0x15)
		decrypt(rand());
	else
	{
		tmp << 2;
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
		decrypt(tmp);
	}
}

int	main()
{
	time_t	t;
	int	pass;

	t = time(0);
	srand(t);
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	puts("Password:");
	scanf("%d", &pass);
	test(pass, 0x1337d00d);
}
