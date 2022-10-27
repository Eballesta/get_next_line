#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("file.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
