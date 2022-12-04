/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:03:02 by donghong          #+#    #+#             */
/*   Updated: 2022/11/30 20:12:41 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
t_list  *ft_lstnew(void * content)
{
    t_list  *next1;

    next1 = (t_list *)malloc(sizeof(t_list));
    if (!next1)
        return (0);
    next1 -> content = content;
    next1 -> next = NULL;
    return (next1);
}
#include <stdio.h>
int main()
{
	t_list  *next;
    t_list  *next2;
    t_list  *next3;
    t_list  *next4;
    
    char l1[10] = "abcedf";// stack
    char *abc = "abcdef";// data
   
    int l2[10] ={1,2,3,4};

int *arr = l2;
  //  int *l3 = {1,2};


    next = ft_lstnew(abc);
    next2  = ft_lstnew(l1);
    next3 = ft_lstnew(arr);
    //next4  = ft_lstnew(l3);
    printf("%s\n", next -> content) ;
    printf("%s\n", next2 -> content);
    //  for(int i = 0; i < 5; ++i)
    // {
    //     printf("%d : \n", ((int *)next3->content)[i]);
    // }

    // for(int i = 0; i < 5; ++i)
    // {
    //     printf("%d : ", ((int *)next3->content)[i]);
    // }
    //printf("%d\n", next2 -> content);
    

}
