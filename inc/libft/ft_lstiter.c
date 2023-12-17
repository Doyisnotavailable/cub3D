/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:15 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:15 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst -> content);
		lst = lst -> next;
	}
}
/* 
void	change(void *content)
{
	int	i;
	char	*str;
	
	str = (char *)content;
	i = 0;
	while (str[i])
		str[i++] = '1';
}

int main()
{
	t_list *node;
	t_list *node2;
	t_list *node3;
	t_list *tmp;

	char	str[] = "abc";
	char	str2[] = "def";
	char	str3[] = "ghi";

	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node3 = ft_lstnew(str3);

	tmp = NULL;
	ft_lstadd_front(&tmp, node);
	ft_lstadd_front(&tmp, node2);
	ft_lstadd_front(&tmp, node3);
	ft_lstiter(tmp, &change);
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp -> next;
	}
} */