#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_str_length(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

char	*ft_strdup(const char *src)
{
	int	i = 0;
	char	*dest;
	char	*d;

	d = (dest = (char *)malloc((ft_str_length(src) + 1) * sizeof(char)));
	if (!d)
	{
		return 0;
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return dest;
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i = 0;
	struct s_stock_str	*array;
	struct s_stock_str	*d;

	d = (array = malloc((ac + 1) * sizeof(struct s_stock_str)));
	if (!d)
	{
		return 0;
	}
	while (i < ac)
	{
		array[i].size = ft_str_length(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		i++;
	}
	array[i].str = 0;
	array[i].copy = 0;
	return array;
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	struct s_stock_str	*structs;

	structs = ft_strs_to_tab(argc, argv);
	i = 1;

	while (i < argc)
	{
		printf("%d\n", i);
		printf("\t| original : %s\n", structs[i].str);
		printf("\t|   copied : %s\n", structs[i].copy);
		printf("\t|     size : %d\n", structs[i].size);
		i++;
	}

	for (i = 0; i < argc; i++)
	{
		free(structs[i].copy);
	}
	free(structs);

	return 0;
} */