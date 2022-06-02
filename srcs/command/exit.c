#include "minishell.h"

void	cmd_exit(void)
{
	/*
	* 여기에서 고려해야 할 것 - 아름다운 마무리
	* 프로그램 종료 경우가 여러 가지 있음! signal(Ctrl-D), exit 명령어
	* 이때 내부적으로 어떻게 다르게 처리할지 고민해 보자 !
	*/
	exit(0);
}
