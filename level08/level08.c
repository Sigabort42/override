#include <stdio.h>

void	log_wrapper(FILE *f, const char *p, char *str)
{
	char buf[264];

	strcpy(buf, p);
	snprintf(&buf[strlen(buf) - 1], 255 - strlen(buf) - 1, str);
	buf[strcspn(buf, "\n")] = 0;
	fprintf(f, "LOG: %s\n", buf);
}

int	main(int ac, char **av)
{
	char	backup[100];
	int	c;
	FILE	*af;
	FILE	*lf;
	int	fd;

	c = 255;
	if (ac != 2)
		printf("Usage: %s filename\n", *av);
	lf = fopen("./backups/.log", "w");
	if (lf == NULL)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(lf, "Starting back up: ", av[1]);
	af = fopen(av[1], "r");
	if (af == NULL)
	{
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}

	backup = "./backups";
	strncat(backup, av[1], 99 - strlen(backup));

	fd = open(backup, 0301, 0660);

	if (fd != 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}

	do
	{
		write(fd, c, 1);
		c = fgetc(af)
	} while (c != 255);

	log_wrapper(lf, "Finished back up ", av[1]);
	fclose(af);
	close(fd);
	return 0;
}
