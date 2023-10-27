#include "../include/cube3d.h"

// void file_down(t_list **head,char *filename);


void setting_mlx(t_monitor *monitor)
{
    monitor->mlx =mlx_init();
    monitor->win= mlx_new_window(monitor->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
    mlx_hook(monitor->win, EVENT_KEY_PRESS, 0, \
				&press_event_handler, &monitor->move);
	mlx_hook(monitor->win, EVENT_KEY_RELEASE, 0, \
				&release_event_handler, &monitor->move);
	mlx_hook(monitor->win, EVENT_KEY_EXIT, 0, \
				&exit_event_handler, &monitor->move);
    mlx_loop(monitor->mlx);
}

t_bool check_empty_line(char *str)
{          
    char *empty;
    char *line;

    empty= " ";
    line =ft_strtrim(str,empty);
    if(*line == '\n')
        return TRUE;
    else
        return FALSE;
    return TRUE;
}

t_list  *component_set(t_list *list)
{
    t_list *current;
    t_list *pre;
    t_list *remove;

    current = list;
    int i =0;

    while(i <= 6 && current)
    {
       if (check_empty_line(current->content) == TRUE)
       {
          pre->next = current->next;
          remove = current;
          current = pre;
          ft_lstdelone(remove,free);
       }
       else
            i++;
        pre = current;
        current = current->next;
    }

    return (list);
}

void init_map(char *filename)
{
    t_map  *map;
    t_list *head;
    t_list *list;

    head = NULL;
    map = (t_map *)ft_calloc(1,sizeof(t_map));
    file_down(&head,filename); 
    list = component_set(head);
    map_setting(map, list);

}


void file_down(t_list **head,char *filename)
 {
    int fd;
    char *line;
    t_list *list;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return ;
    while(1)
    {
        line =get_next_line(fd);
        if (line)
        {
            list = ft_lstnew(line);
            if (!list)
                return ;
            ft_lstadd_back(head,list);
        }
        else 
            return ;
    }
 }


