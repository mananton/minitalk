/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mananton <telesmanuel@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:58:58 by mananton          #+#    #+#             */
/*   Updated: 2025/01/27 12:15:01 by mananton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>

void    print_list(t_list *list)
{
        while (list != NULL)
        {
                printf("%s -> ", (char *)list->content);
                list = list->next;
        }
        printf("NULL\n");
}

int     main(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;
        t_list  *current;
        t_list  *next;

        list = NULL;
        node1 = ft_lstnew("Node 1");
        node2 = ft_lstnew("Node 2");
        node3 = ft_lstnew("Node 3");
        ft_lstadd_back(&list, node1);
        ft_lstadd_back(&list, node2);
        ft_lstadd_back(&list, node3);

        print_list(list);
        current = list;
        while (current != NULL)
        {
                next = current->next;
                free(current);
                current = next;
        }
        return 0;
}*/
