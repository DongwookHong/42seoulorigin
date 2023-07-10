#include "minishell.h"



// void init_main(int ac, char **av, term termi)
// {
//     if (ac != 1)
//         exit(1);
//     if(tcgetattr(STDIN_FILENO,&termi)== -1)//터미널의 현재 속성을 불러와서 초기화. 
//         exit(1);
//     termi.c_cflag &= ~(ECHOCTL); //로컬 속성(local flags)을 제어하는 플래그입니다. 예를 들어, 입력을 줄 단위로 처리하거나, 에코 기능을 활성화하는 데 사용됩니다.
//     if (tcsetattr(STDIN_FILENO,TCSANOW, &termi)  == -1 //함수는 터미널의 특정 속성, 예를 들면 터미널 모드, 입력 및 출력 설정 등을 변경하는 데 사용됩니다.
//         || tgetent (NULL, "xterm-256color") == -1) //TCSANOW는 터미널 속성을 즉시 적용하도록 지정하는 플래그입니다.
//         //termcap 데이터베이스에서 터미널의 정보를 검색하는 함수입니다.
//         // 실제로 xterm-256color -> bash환경의 term확인을 해준다 !!  아닐경우 나가  bash  환경일ㄸ매ㅏㄴ 실행 
//     exit(1);
     
// }



int main(int ac, char **av, char **env) {
    term termi;
    // init_main(ac, av,termi);
   main_signal();
   while (1)
   {

      // printf("forum.falinux.com\n");
      sleep(1);
   }
}




// int main(int ac, char **av, char **env) {
//     // 해시테이블 메모리 할당
//     t_hashtable *hashTable;
//     init_hash(&hashTable);
//     hash_play(env, hashTable);
//     get_pwd();
//     return 0;
// }
