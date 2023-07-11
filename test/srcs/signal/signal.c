// #include "../../incs/minishell.h"

// #include <signal.h> 
// void (*signal(int signum, void (*handler)(int)))(int);

// -> sig num -> 정해진 (SIGINT SIGQUIT etc ...)
// 구현 해야 할 것 ctl +c , ctl +d , (ctrl- \)
// SIGINT - >  인트럽트로  cntl +c 입력
// SIGQUIT -> (ctrl -\) 
// EoF -> ctrl -D
// kill -l 시그널 목록을 확인 할 수있음 
// 나머지 동일 ctrl -c 와 부모의 진행 과 자식의 진행 만다름 
// 자식에서 ctl -c 실행시 ^c 시행 부모에서는 줄바꿈 실행 이됨 

// sign  은 old 한 방식 sign 은 안쓰고  signaction을 쓰는이유는  더욱 표준화 되있고 안정 적이고 신뢰 할 수있음 


// void signal_handler(int signum)
// {
//     if (signum == SIGINT)
//     {
// 		write(1, "\n", 1);//개행 문자를 표준 출력으로 직접 쓰는 것으로, 현재 입력 라인이 종료되었음을 나타냅니다.
// 		rl_on_new_line();//readline 라이브러리 함수로, 현재 입력 라인을 새 줄로 이동시킵니다.
// 		rl_replace_line("", 0);//는 입력 라인을 빈 문자열로 대체하는 역할을 합니다.  이로 인해 현재 입력 라인이 화면에서 사라지고, 커서는 다음 줄로 이동합니다. 
// 		rl_redisplay();// readline 라이브러리 함수로, 화면에 변경된 입력 라인을 다시 표시합니다.
//         exit(0);
// 	}
//  if (signum ==SIGQUIT)
//         exit(1);
// }




void child_handler(int signum)
{
    if (signum == SIGINT)
    {
		write(1, "\n", 1);//개행 문자를 표준 출력으로 직접 쓰는 것으로, 현재 입력 라인이 종료되었음을 나타냅니다.
		rl_on_new_line();//readline 라이브러리 함수로, 현재 입력 라인을 새 줄로 이동시킵니다.
		rl_replace_line("", 0);//는 입력 라인을 빈 문자열로 대체하는 역할을 합니다.  이로 인해 현재 입력 라인이 화면에서 사라지고, 커서는 다음 줄로 이동합니다. 
		rl_redisplay();// readline 라이브러리 함수로, 화면에 변경된 입력 라인을 다시 표시합니다.
        exit(0);
	}
   
}

void main_signal()
{
    sig sign;

    sign.sa_handler =  signal_handler; 
    sigemptyset(&sign.sa_mask);// 시그널 집합을 초기화해주는 역할   mask 의 역할 ->  시그널 중복방지 
    sign.sa_flags=0; // flag
    if(sigaction(SIGINT, &sign, NULL) == -1)
        exit(1);
    if(sigaction(SIGQUIT, &sign, NULL) == -1)
        exit(1);
}








// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// void (*old_fun)(int);

// void sigint_handler(int signo)
// {
//    printf("signumber : %d", signo);
//    printf("Ctrl-C 키를 누르셨죠!!\n");
//    printf("또 누르시면 종료됩니다.\n");
// //    signal(SIGINT, old_fun);
// //    signal( SIGINT, SIG_DFL);
// }

// int main( void)
// {
//    old_fun = signal(SIGINT, sigint_handler);
//    // printf("asdf : %d", SIGTSTP);
//    // printf("zxcv : %d", SIGCHLD);
//    while (1)
//    {

//       printf("forum.falinux.com\n");
//       sleep(1);
//    }
// }






// void handle_signal(int signum) {
//     printf("Received signal: %d\n", signum);
//     // 시그널에 대한 추가 동작 수행
// }

// int main() {
//     // SIGINT 시그널에 대한 핸들러 등록
//     signal(SIGINT, handle_signal);
//      signal(SIGQUIT, handle_signal);
//     // 프로그램 실행 중 계속 실행됨
//     while (1) {
//         // 프로그램 동작
//     }

//     return 0;
// }

