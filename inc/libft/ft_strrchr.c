/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:54:16 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:54:16 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (0);
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = (char *) s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (ptr);
}

/* int main()
{
	char	*str = "abc def";

	printf("%s", ft_strrchr(str, 'd'));
} */