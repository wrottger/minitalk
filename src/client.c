/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:09:46 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/03 18:39:08 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <printf.h>


int	check_pid(char *pid)
{
	while (*pid)
	{
		if (!ft_isdigit(*pid))
			return (0);
		pid++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "ERROR Please supply two arguments. "
			"The PID and the string to send.\n", 67);
		exit(EXIT_FAILURE);
	}
	if (!check_pid(argv[1]))
	{
		write(2, "ERROR The PID should only consist of Numbers", 44);
		exit(EXIT_FAILURE);
	}
	printf("%s", argv[1]);
	return (0);
}
