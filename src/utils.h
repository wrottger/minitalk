/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:13:46 by wrottger          #+#    #+#             */
/*   Updated: 2023/09/03 19:29:47 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "libft.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);
void	set_bit(char *arr, size_t position, int bit);
int		get_bit(char arr, int bit);

#endif
