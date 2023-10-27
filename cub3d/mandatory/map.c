#include "../include/cube3d.h"

 void map_setting(t_map *map,t_list *list)
 {
    t_list *temp;
    temp = list;
    set_comp(map->elements, &temp);
    set_map(&map->down_map,temp);
 
 }

 t_bool ft_split_check(char *line,char space, char **str)
 {
    char **element;
    int i = 0;
    int check = 0;
    element = ft_split(line,space);
    check = get_element_id(element[0]);
    while(element[i])
        i++;
    if(i >=2 || check <0)
        return (FALSE);
    str[check]= ft_substr(element[1],0,ft_strlen(element[1])-1);
    return TRUE;    
 }

 void set_comp(char **componets,t_list **list)
 {
    t_list *temp;
    int check = 0;
    int i =0;

    temp = *list;
    while(i <6 && temp)
    {
        check=ft_split_check(temp -> content,' ',componets);
        if (!check)
            return ; 
        i++;
        temp= temp ->next;
    }
    *list = temp;
 }

  void set_map(char ***componets,t_list *list)
  {
    int i =0;
    int len;
    char **down;

    t_list *temp;
    temp = list;
    len = ft_lstsize(list);
    
    down = (char **)ft_calloc(len+1,sizeof(char *));
    while(temp)
    {
        down[i] = ft_substr(temp->content,0,ft_strlen(temp->content)-1);
        i++;
        temp= temp->next;
    }
    *componets=down;
  }


t_id	get_element_id(char *str)
{
	if (!ft_strncmp("WE\0", str, 3))
		return (we);
	else if (!ft_strncmp("SO\0", str, 3))
		return (so);
	else if (!ft_strncmp("NO\0", str, 3))
		return (no);
	else if (!ft_strncmp("EA\0", str, 3))
		return (ea);
	else if (!ft_strncmp("F\0", str, 2))
		return (f);
	else if (!ft_strncmp("C\0", str, 2))
		return (c);
	else
		return (invalid);
}


