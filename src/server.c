/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:09:37 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/03 19:17:20 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include "utils.h"


void	*add_bit(char **msg, size_t msg_bit_len, size_t msg_len, int bit)
{
	if ((msg_bit_len % 8) == 0)
	{
		msg = ft_realloc(msg, msg_len, msg_len + 1);
	}
	set_bit(*msg, msg_bit_len, bit);
	return (msg);
}

void	handle_sent_bit(int signal)
{
	static char		*msg = NULL;
	static size_t	msg_bit_len = 0;
	size_t			msg_len;

	msg_len = msg_bit_len / sizeof(char);
	if (signal == SIGUSR1)
		add_bit(&msg, msg_bit_len, msg_len, 1);
	if (signal == SIGUSR2)
		add_bit(&msg, msg_bit_len, msg_len, 0);
	if (msg[msg_len] == 0)
	{
		write(1, msg, msg_len);
		free(msg);
		msg = NULL;
		msg_bit_len = 0;
	}
	msg_bit_len++;
}

int	main(void)
{
	signal(SIGUSR1, handle_sent_bit);
	signal(SIGUSR2, handle_sent_bit);

	write(1, "Server Started...\n", 18);
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
