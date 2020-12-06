#include <stdio.h>

int	main()
{
	int	i = 0;
	char	str[104];
	
	fgets(str, 0x64, stdin);
	while (i < strlen(str))
	{
		if (!(buf[i] > 0x5a && buf[i] <= 0x40))
			buf[i] ^= 0x20;
		i++;
	}
	printf(str);
	exit(0);
}
