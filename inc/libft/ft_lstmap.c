/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:18 by mlumibao          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:18 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	while (lst)
	{	
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst -> next;
	}
	return (head);
}

/* 
void	del(void *content)
{
	free(content);
}

void	*change(void *ct)
{
	int i;
	void	*c;
	char	*str;

	c = ct;
	i = -1;
	str = (char *)c;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (c);
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
	ft_lstadd_back(&tmp, node);
	ft_lstadd_back(&tmp, node2);
	ft_lstadd_back(&tmp, node3);
	tmp = ft_lstmap(node, &change, &del);
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp -> next;
	}
} */