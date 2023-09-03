/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:14:49 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/03 18:25:33 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
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

void	set_bit(char *arr, size_t position, int bit)
{
	arr[position / sizeof(char)] |= ((char)bit << (position % sizeof(char)));
}

int	get_bit(char *arr, size_t position, int bit)
{
	return (arr[position / sizeof(char)]
		& ((char)bit << (position % sizeof(char))));
}
