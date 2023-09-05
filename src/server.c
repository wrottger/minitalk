/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:09:37 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/05 15:33:55 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <printf.h>

void	*add_bit(char **msg, size_t msg_bit_len, size_t msg_len, int bit)
{
	char	*old_msg;

	if (!*msg)
	{
		*msg = ft_calloc(1, 1);
	}
	else if (((msg_bit_len) % 8) == 0)
	{
		old_msg = *msg;
		*msg = malloc(sizeof(char) * (msg_len + 1));
		ft_memcpy(*msg, old_msg, msg_len);
		(*msg)[msg_len] = 0;
		free(old_msg);
	}
	(*msg)[msg_len] |= ((char)bit << (msg_bit_len % 8));
	return (*msg);
}

void	handle_sent_bit(int sig)
{
	static char		*msg = NULL;
	static size_t	msg_bit_len = 0;
	size_t			msg_len;

	msg_len = (msg_bit_len) / 8;
	if (sig == SIGUSR1)
		add_bit(&msg, msg_bit_len, msg_len, 1);
	if (sig == SIGUSR2)
		add_bit(&msg, msg_bit_len, msg_len, 0);
	msg_bit_len++;
	if ((msg_bit_len) % 8 == 0 && msg[msg_len] == 0)
	{
		write(1, msg, msg_len);
		if (msg)
			free(msg);
		msg = NULL;
		msg_bit_len = 0;
		return ;
	}
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
