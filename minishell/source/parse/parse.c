/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 20:29:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse.h"

t_list	*parse(char *line)
{
	t_list	*tokens;

	// Check unclosed things and errors for parsing.
	// This also used when getting input from heredoc.
	tokens = lexer(line);
	expand_env_var(tokens);
	return (tokens);
}

t_list	*list_metachar(t_list *tokens, t_metachar name)
{
	if (!tokens || ((t_token *)tokens->content)->type == name)
		return (tokens);
	else
		return (list_metachar(tokens->next, name));
}
