/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
<<<<<<<< HEAD:libs/libft/src/ft_memcpy.c
=======
>>>>>>> main
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:09 by alsaeed           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 03:02:09 by alsaeed          ###   ########.fr       */
========
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:45:20 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
>>>>>>>> main:libs/libft/src/ft_lstadd_front.c
=======
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

<<<<<<< HEAD
<<<<<<<< HEAD:libs/libft/src/ft_memcpy.c
void	*ft_memcpy(void *dst, const void *src, size_t n)
=======
void	*ft_memcpy(void *dst, void *src, size_t n)
>>>>>>> main
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*(d++) = *(s++);
	return (dst);
<<<<<<< HEAD
========
void	ft_lstadd_front(t_list *head, int integer)
{
	t_list	*new_node;

	if (head != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			exit (1);
		new_node->index = integer;
		new_node->next = head;
		head = new_node;
	}
>>>>>>>> main:libs/libft/src/ft_lstadd_front.c
=======
>>>>>>> main
}
