#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("line found %s", line);
	}
}