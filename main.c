
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inc/libft/libft.h"

char	**ft_split(char const *s, char c);

/* void	free_array(char ***str)
{
	int i = 0;
	char **tmp;

	tmp = *str;
	while (*str)
	{
		free(*str[i]);
		i++;
	}
	free(tmp);
} */
void	free_array(char **str)
{
	char **tmp;

	tmp = str;
	while (*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(tmp);
}


int main()
{
	char **test = ft_split("asd bcd efg hik", ' ');

	for (size_t i = 0; i < 4; i++)
		printf("%s\n", test[i]);
	free_array(test);
	test = NULL;
	if (!test)
	{
		printf("proper free");
		return (0);
	}
	while(*test)
		printf("%s\n", *test++);
}