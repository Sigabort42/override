#include <stdio.h>

int	main()
{
	char	buf1[112];
	char	buf2[48];
	char	buf3[112];
	FILE	*f;
	size_t	n;
	
	bzero(buf1, 0xc);
	bzero(buf2, 0x5);
	bzero(buf2, 0xc);

	f = fopen("/home/users/level03/.pass", "r");
	if (!f)
	{
		fwrite("ERROR: failed to open password file\n", 0x1, 0x24, stderr);
		exit(1);
	}
	fread(buf2, 0x1, 0x29, f);
	n = strcspn(buf2, "\n");
	buf2[n] = '\0';
	if (n != 0x29)
	{
		fwrite("ERROR: failed to read password file\n", 0x1, 0x24, stderr);
		exit(1);
	}
	fclose(f);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(buf1, 0x64, stdin);
	n = strcspn(buf1, "\n");
	buf1[n] = '\0';
	printf("--[ Password: ");
	fgets(buf3, 0x64, stdin);
	n = strcspn(buf3, "\n");
	buf3[n] = '\0';
	puts("*****************************************");
	if (strncmp(buf2, buf3, 0x29))
	{
		printf(buf1);
		puts(" does not have access!");
		exit(1);
	}
	printf("Greetings, %s!\n", buf1);
	system("/bin/sh");
	return (0);
}
