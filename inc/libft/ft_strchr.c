/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:52 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:52 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*sptr;

	sptr = (char *)s;
	while (*sptr)
	{
		if (*sptr == (unsigned char)c)
			return (sptr);
		sptr++;
	}
	if (c == 0)
		return (sptr);
	return (0);
}

/* int main()
{
	char	*str;

	str = ft_strchr("abcdef", 'd');
	printf("%s", str);
} */