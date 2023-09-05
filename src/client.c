/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:09:46 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/05 12:06:22 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include "utils.h"
#include <printf.h>

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	send_message(int pid, char *message)
{
	int	index;

	while (*message)
	{
		index = 0;
		while (index < 8)
		{
			printf("%d\n", index);
			if (get_bit(*message, index))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			index++;
		}
		message++;
	}
	send_null(pid);
	return (1);
}

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
	int	pid;

	if (argc != 3)
	{
		write(2, "ERROR Please supply two arguments. "
			"The PID and the string to be sent.\n", 70);
		exit(EXIT_FAILURE);
	}
	if (!check_pid(argv[1]))
	{
		write(2, "ERROR The PID should only consist of Numbers\n", 45);
		exit(EXIT_FAILURE);
	}
	if (argv[2][0] == 0)
	{
		write(2, "ERROR Please provide a string to send\n", 38);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
