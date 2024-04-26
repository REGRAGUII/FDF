#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"

static char **free_mem(char **str)
{
	int	i;
	
	i = -1;
	if (str)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
	return (NULL);
}


int	get_height(int fd)
{
	char *line;
	int height;

	height = 0;
	line = get_next_line(fd);
	printf("he ->%s", line);
	if(!line)
		ft_error("reading line error");
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	return(height);
	close(fd);
}


int	get_width(int fd)
{
	int		width;
	char	*line;
	int		i;
	char	**str;

	i = 0;
	width = 0;
	line = get_next_line(fd);
	printf("wi ->%s", line);
	if (!line)
		ft_error("invalid map (empty)");
	str = ft_split(line, ' ');
	while (str[i])
	{
		if(!ft_strchr(str[i],'\n'))
			width++;
		i++;
	}
	free(line);
	str = free_mem(str);
	return (width);	
}

void	ft_get_map(char *str)
 {
	int	fd;
	int	i;
	int ordinate = 0;
	int width = 0;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("open file fail");
	ordinate = get_height(fd);
	printf("\nhi :: %d\n\n",ordinate);
	fd = open(str,O_RDONLY);
	width = get_width(fd);
	close(fd);
	printf("\n wi ::%d\n", width);

 }

int main(int ac, char **av)
{
		ft_get_map(av[1]);
		system("leaks a.out");
}
