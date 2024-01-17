#include "get_next_line.h"
#include "stdio.h"

int main (void)
{
	int fd = open("test.txt", O_RDONLY);
	char * test = get_next_line(fd);

	printf("%s",test);
	while (test)
	{
		test = get_next_line(fd);
		if (test)
			printf("%s",test);
	}
}