#include "../../incs/minishell.h"

void get_pwd()
{
    char *pwd = getcwd(NULL,0); // 메모리 버퍼 크기 및 사이즈 자동 설정및 해제 
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

//여러개의 경로가 들어오도 항상 첫번째 명령어만 실행이된다  파이프 x 일때 
void cd_link(char *str)
{

    if (chdir("..") == 0) {
        get_pwd();
        printf("success\n");
        // 작업 디렉토리 변경 성공
        // 변경된 작업 디렉토리에서 작업을 수행
    } else {
        get_pwd();
          printf("fail\n");
        // 작업 디렉토리 변경 실패
        // 실패 이유에 따라 적절한 처리 수행
    }

    return 0;
}



void export_link(char *str,t_list **head)
{
  int i= 0;

  //head 의 리스트의 content[0] 배열이 알파벳 이랑 _ 만 들어올수 있음 
  // check  알파벳 숫자_ 만올 수있음 
  // = 하나만 이루어져있어야하며 띄어쓰기 x = parsing 부분에서 하나로 들어와있고 = 이있을경우 정상 addback
  // = 없을겨우  list add -> 바로 딜리트 해주기 
  //export (인자가 아무것도 없을시) 사용 했을 시 아스킷 코드 순으로 나열 
  //정상으로 인자가 여러개 들어올수 있는데 그거는 제대로 작동해야함 
  //a= b  일 때 exportt 에 추가됨 단 key 값만 추가되고 value눈 없음 addback 단 key 값만 첫 value 만 
    //a =b일때는 error

 
 
  if ((str[0] >= 'a'&& str[0] <= 'z') || (str[0] >= 'A'&& str[0] <= 'Z')  || str[0] == '_')
         ft_lstadd_back(head, ft_lstnew(str));   
}