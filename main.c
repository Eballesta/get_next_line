#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("file.txt", O_RDONLY);
	int i = 0;
	while (i++ < 7)
		printf("Line: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
