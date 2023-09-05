/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:14:49 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/05 11:08:30 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		if (old_ptr)
			free(old_ptr);
		return (NULL);
	}
	if (old_ptr != NULL)
	{
		ft_memcpy(
			new_ptr,
			old_ptr,
			old_size);
		free(old_ptr);
	}
	return (new_ptr);
}

void	set_bit(char *c, size_t position, int bit)
{
	*c |= ((char)bit << (position));
}

int	get_bit(char c, int bit)
{
	return (c & ((char)1 << bit));
}
