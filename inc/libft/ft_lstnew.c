/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:20 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:20 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/* int main()
{
	t_list	*new;
	char	str[] = "abcdefg";
	long i = 0;

	new = ft_lstnew(str);
	i = strlen(new->content);
	if (!(new = ft_lstnew(str)))
		write(1, "NULL", 4);
	else
	{
		if (!(new->content))
			write(1, "NULL", 4);
		else
			write(1, new->content, i);
		if (!(new->next))
			write(1, "\n", 1);
			write(1, "NULL", 4);
	}
} */