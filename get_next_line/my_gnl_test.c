// int main()
// {
// 	int fd;
// 	int ret;
// 	char *line;

// 	fd = open("mix_marge1", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);

// 	printf("=============================\n");
	
// 	fd = open("empty_lines", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);

// 	printf("=============================\n");

// 	fd = open("empty_file", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);
// }

int main()
{
	int fd1;
	int fd2;
	int ret;
	char *line;

	fd1 = open("mix_marge1", O_RDONLY);
	ret = get_next_line(fd1, &line);
	printf("[%s] %d\n", line, ret);
	free(line);
	fd2 = open("alphabet", O_RDONLY);
	ret = get_next_line(fd2, &line);
	printf("[%s] %d\n", line, ret);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("[%s] %d\n", line, ret);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("[%s] %d\n", line, ret);
	free(line);
}

// #include <stdio.h>
// int main()
// {
// 	char *line;
// 	while (get_next_line(0, &line) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	free(line);
// }