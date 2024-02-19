/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:22:32 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:47 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	replace_char(t_char_flag *str, char c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (str[i].c)
		{
			str[i].c = str[i + 1].c;
			i++;
		}
	}
	else
		str[i].c = c;
}

/*verifie si la quote se ferme et si c'est le cas la supprime;
 si les quote forme un charactere nul supprime la quote et met un char 0 a la
 place*/
static int	quote_close(t_char_flag *str, int *quote, char a, int *count)
{
	int	j;

	j = 1;
	if (*quote != QUOTE && *quote != SQUOTE)
	{
		while (str[j].c)
		{
			if (str[j].c == a)
			{
				replace_char(str, '\0');
				*count = 0;
				return (1);
			}
			j++;
		}
	}
	if (*count == 1)
		replace_char(str, '0');
	else
		replace_char(str, '\0');
	*quote = 0;
	return (0);
}

/*verifie si le charactere est entre quote, ou si c'est une quote si elle
se ferme ou pas*/
static int	test_quote(int *quote, int *squote, t_char_flag *str, int i)
{
	int	count;

	count = 0;
	while ((str[i].c == '\'' && *quote == 0)
		|| (str[i].c == '"' && *squote == 0))
	{
		if (*quote == 0 && str[i].c == '\'')
		{
			if (quote_close(str + i, squote, '\'', &count))
				*squote ^= SQUOTE;
		}
		else if (*squote == 0 && str[i].c == '"')
		{
			if (quote_close(str + i, quote, '"', &count))
				*quote ^= QUOTE;
		}
		count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

/*verifie si il y a des charactere entre les quote si il n'y
en as pas ajoute un 0 avec le flag null sinon ajoute le flag quote ou squote
en fonction du type de quote*/
void	check_quote(t_char_flag *str)
{
	int	quote;
	int	squote;
	int	i;
	int	null;

	null = 0;
	quote = 0;
	squote = 0;
	i = 0;
	while (str[i].c)
	{
		null = test_quote(&quote, &squote, str, i);
		if (null)
		{
			str[i].c = '0';
			str[i].flag = CHAR_NULL;
		}
		if (quote || squote)
			str[i].flag = (quote | squote);
		i++;
	}
}
