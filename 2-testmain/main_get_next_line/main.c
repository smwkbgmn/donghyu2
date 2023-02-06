#include "main.h"

int	main(void)
{
	// printf("BUFFER_SIZE --- [%d]\n\n", BUFFER_SIZE);

	/////////////////////////////////////////////////////

	int fd = open("test1", O_RDONLY);

	char *line;

	clock_t begin;
	clock_t end;
	double result;

	// while (1)
	// {
	// 	if((line = get_next_line(fd)) != NULL)
	// 	{
	// 		printf("%s", line);
	// 		free(line);
	// 	}
	// 	else
	// 		break;
	// }
	
	begin = clock();

	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
		else
			break;
	}

	end = clock();

	// result = (double)end - (double)begin;
	result = (double)(end - begin);
	printf("\ntime measurment --- %.0f ms\n", result);

	close(fd);

	// char buf[10];

	// printf("return of read --- [%zd]\n", read(fd, buf, 10));
	// printf("%s\n", buf);

	// line = get_next_line(fd);
	// printf("%s", line);
	// if (line)
	// 	free(line);

	/////////////////////////////////////////////////////

	// int fd1 = open("test1", O_RDONLY);
	// int fd2 = open("test2", O_RDONLY);
	// int fd3 = open("test3", O_RDONLY);

	// char *line;

	// ver 1.0

	// while (1)
	// {
	// 	if((line = get_next_line(fd1)) != NULL)
	// 	{
	// 		printf("%s", line);
	// 		free(line);
	// 	}
	// 	if((line = get_next_line(fd2)) != NULL)
	// 	{
	// 		printf("%s", line);
	// 		free(line);
	// 	}
	// 	if((line = get_next_line(fd3)) != NULL)
	// 	{
	// 		printf("%s", line);
	// 		free(line);
	// 	}
	// 	else
	// 		break;
	// }

	// ver 2.0

	// int cnt = 0;

	// while (cnt < 10)
	// {
	// 	printf("\ncycle [%d]\n", cnt + 1);

	// 	line = get_next_line(fd1);
	// 	printf("%s", line);
	// 	if (line)
	// 		free(line);

	// 	line = get_next_line(fd2);
	// 	printf("%s", line);
	// 	if (line)
	// 		free(line);

	// 	line = get_next_line(fd3);
	// 	printf("%s", line);
	// 	if (line)
	// 		free(line);

	// 	cnt++;
	// }

	// close(fd1);
	// close(fd2);
	// close(fd3);

	/////////////////////////////////////////////////////

	// system("leaks gnl_man.out");

	return (0);
}