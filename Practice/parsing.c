/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:58:55 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/09 22:01:35 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "parsing.h"
#include "libft/libft.h"

void	command_init(char *str, t_list *list, int idx, int type)
{
	t_token *token;
	char	*temp;
	int		i;

	i = 0;
	token = ft_calloc(1, sizeof(t_token));
	temp = ft_calloc(sizeof(char), idx);
	if (!token || !temp)
		exit(-1); // 널가드 에러처리
	ft_strlcpy(temp, str, idx + 1);
	token->content = temp;
	token->type = type;
	token->next = NULL;
	list = ft_lstnew(token);
	printf("%s\n", ((t_token*)list->content)->content);
}

void	parsing(char *str, t_commandlist *cmd_list)
{
	int	i;
	
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '>' || str[i] == '<' || str[i] == '|' || str[i] == ' ' || str[i] == '\0')
		{
			command_init(str, cmd_list->command, i, T_WORD);
			
		}
		i++;
	}
}

int main()
{
	t_commandlist lst;
	char *str = "hello ";

	parsing(str, &lst);
	printf("%s\n", ((t_token*)lst.command->content)->content);
}
