#include "unistd.h"
#include "stdio.h"

int line_size(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int main(void)
{
	printf("line size is: %d", line_size("Hello"));
}