/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:16:41 by ltalia            #+#    #+#             */
/*   Updated: 2022/03/27 20:16:43 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_elem	*head_a;
	char			*str;

	if (argc == 2)
	{
		str = ft_strjoin("!push_swap ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = splited_size(argv);
	}
	if (not_valid_arguments(argc, argv) > 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (argv[0][0] == '!')
			free_after_split(argv);
		return (-1);
	}
	if (argc > 1)
	{
		head_a = stack_init(argc, argv);
		stack_sort(&head_a);
		free_stack(&head_a);
		if (argv[0][0] == '!')
			free_after_split(argv);
	}
}
