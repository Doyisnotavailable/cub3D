/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:56 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:56 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, (s + i));
		++i;
	}
}

/* void	test(unsigned int i, char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
	else if (*str >= 'A' && *str <= 'Z')
		*str = *str + 32;
	i *= 2;
}

int main()
{
	char	*str;

	str = malloc(sizeof(*str) * 10);
	strcpy(str, "aBcDeFg");
	printf("Before striteri: %s\n", str);
	ft_striteri(str, &test);
	printf("striteri result: %s", str);
}
 */