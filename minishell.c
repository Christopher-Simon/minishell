/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:57:58 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/04 20:49:56 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

char	*ft_realloc(char *buf, size_t nmemb, size_t size)
{
	char	*str;

	str = ft_calloc(nmemb, size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)buf, nmemb);
	free(buf);
	return (str);
}

int	main(void)
{
	char	cwd[1024];
	char	*ptr;
	// int		size;
	// char	*str;

	// ptr = NULL;
	// size = 1024;
	// cwd = malloc(size * sizeof(char));
	// if (!cwd)
	// 	return (0);
	// int i = 0;
	// while ()
	// while (size < 250)
	// {
		// cwd = ft_realloc(cwd, size, sizeof(char));
		ptr = getcwd(cwd, sizeof(cwd));
		if (!ptr)
			printf("zizi");
		// printf("%ld\n", sizeof(cwd));
		// if (cwd == NULL)
		// if (cwd)
		// 	break ;
		// size += 5;
	// }
	printf("%s\n", cwd);
	// free(cwd);
	// signal(SIGINT, sig_handler);
	// while (1)
	// {
	// 	str = readline("Minishell > ");
	// 	if (str)
	// 		add_history(str);
	// 	free(str);
	// }
	return (1);
}
