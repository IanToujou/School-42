/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:15:59 by ibour             #+#    #+#             */
/*   Updated: 2025/08/12 07:17:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <string>

template <typename T>

void iter(T *array, const size_t size, void (*f)(T&)) {
	if (!array || !size || !f) return;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif