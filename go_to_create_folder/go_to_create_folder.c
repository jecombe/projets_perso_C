/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   go_to_create_folder.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 15:52:55 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 15:52:56 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int		ft_change_direction(char *go)
{
	char cwd[1024];
	char cwd2[1024];

	if (go == NULL)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			go = cwd;
	}
	if (chdir(go) != 0)
	{
		perror("chdir()");
		return (-1);
	}
	if (getcwd(cwd2, sizeof(cwd2)) != NULL)
	{
		printf("Current directory: %s\n",cwd2);
		return (0);
	}
	return (-1);
}

int			ft_check_file(char *file)
{
	struct stat st;

	if (lstat(file, &st) == 0)
		return (-1);
	else
		return (0);
}

void		ft_create_directory(char *str)
{
	if (ft_check_file(str) == -1)
	{
		printf("Erreur file existing\n");
		return ;
	}
	if (mkdir(str,0777) == -1)
	{
		printf("Erreur\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_change_direction(argv[2]) == 0)
		ft_create_directory(argv[1]);
	}
	else
		printf("Erreur syntax : ""./a.out {'name_folder'} {'to_directory'}\n""");
	return (0);
}
