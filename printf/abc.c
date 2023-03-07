#include <stdio.h>
#include <string.h>
#include <unistd.h>
void	ft_str(char *s,int fd)
{
	if (!s)
		return ;
	write(1, s, strlen(s));
}


int main(){

	char * abc = "rew";
	int cnt = 0;

	cnt = ft_str(abc,1);
	printf("%d",cnt);
}
