/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:09 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:09 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	*lst = new;
	new -> next = tmp;
}

/* 
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
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp -> next;
	}
} */