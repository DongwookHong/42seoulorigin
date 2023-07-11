#include "../../incs/minishell.h"

void get_pwd()
{
    char *pwd = getcwd(NULL,0);
    printf("pwd:%s\n", pwd);
}

static size_t cut_len(char *str)
{
    int i =0;
    while(str[i])
    {
        if(str[i] == '=')
            break;
        i++;
    }
    return i+1;
}


void unset_link(char *str,t_list **head)
{
    t_list *temp = *head;
    t_list *previous = NULL;

    size_t len = cut_len(str);

    while (temp)
    {
        if (ft_strncmp(temp->content, str, ft_strlen(str)) == 0 && len == cut_len(temp->content))
        {
            if (previous == NULL) // 첫 번째 노드인 경우
                *head = temp->next;
            else
                previous->next = temp->next;
            ft_lstdelone(temp);
            break;
        }

        previous = temp;
        temp = temp->next;
    }
}

void print_env(t_list **head)
{
    t_list *temp = *head;
    while(temp)
    {
        printf("%s\n",temp->content);
        temp= temp->next;
    }
}

void export_link(char *str,t_list **head)
{
  int i= 0;

  if ((str[0] >= 'a'&& str[0] <= 'z') || (str[0] >= 'A'&& str[0] <= 'Z')  || str[0] == '_')
  ft_lstadd_back(head, ft_lstnew(str));   
}