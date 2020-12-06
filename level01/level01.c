#include <stdio.h>

char	*a_user_name = "";

int	verify_user_name()
{
	puts("verifying username....\n");
	return (strncmp(a_user_name, "dat_wil", 0x7));
}

int	verify_user_pass(char *pass)
{
	return (strncmp(pass, "admin", 0x5))
}

int	main()
{
	char	pass[0x60];
	int	check;
	
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 0x100, stdin);
	if (verify_user_name())
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
	fgets(pass, 0x64, stdin);
	check = verify_user_pass(pass);
	if (!check || check)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}
	return (0);
}
