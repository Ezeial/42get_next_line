#include "get_next_line.h"
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
	
int main(int ac, char **av)
{
	char *line;
	int yikes;
	line = calloc(1, 1);
	yikes = open("yikes.txt", O_RDONLY);
	get_next_line(yikes, &line);
	printf("final |%s|\n", line);
	get_next_line(yikes, &line);
	printf("final2 |%s|\n", line);
	get_next_line(yikes, &line);
	printf("final3 |%s|\n", line);
	close(yikes);
	free(line);
	return (0);
}