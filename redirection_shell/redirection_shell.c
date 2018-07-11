/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_shell.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 18:20:50 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 19:01:21 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>


char		**ft_split(char *str);

void		redirection_shell_output(char *command, char *delimitateur)
{

}
void		redirection_shell(char **cmd)
{
	printf("+======> %s\n", cmd[2]);
	if (strcmp(cmd[1], ">") == 0)
	{
		redirection_shell_output(cmd[0], cmd[2]);
	}
	if (strcmp(cmd[1], ">>") == 0)
		;
}
int			main(int argc, char **argvi, char **env)
{
	char **split;
	char buff[PATH_MAX];
	int i;
	int  c = 0;
	while (101)
	{
		putchar('\r');
		bzero(buff, PATH_MAX);
		printf("==> ");
		if (!(i = read(0, buff, PATH_MAX)))
		{
			break;
		}
		split = ft_split(buff);
		redirection_shell(split);
	}
		return (0);
}
