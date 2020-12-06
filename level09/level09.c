#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
	char	msg[140];
	char	name[40];
	int    	n;
};

void    secret_backdoor()
{
	char    buf[128];

	fgets(buf, 128, stdin);
	system(buf);
}

void set_username(struct user *user)
{
	char buf[128];
	int i;

	i = 0;
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buf, 128, stdin);
	while (i <= 40 && buf[i])
	{
		user->name[i] = buf[i];
		i++;
	}
	printf(">: Welcome, %s", user->name);
}

void set_msg(struct user *user)
{
	char buf[1024];

	puts("Message @Unix-Dude");
	printf(">>: ");
	fgets(buf, 128, stdin);
	strncpy(user->msg, buf, user->n);
}

void handle_msg()
{
	struct user user;

	user.name = {0};
	user.n = 140;
	set_username(&user);
	set_msg(&user);
	puts(">: Msg sent!");
}

int main()
{
	puts("--------------------------------------------\n"
	     "|   ~Welcome to l33t-m$n ~    v1337        |\n"
	     "--------------------------------------------");
	handle_msg();
}
