/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:09:27 by ibour             #+#    #+#             */
/*   Updated: 2025/08/12 07:12:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
#define TEMPLATE_H

template<typename T>

const T &max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

template<typename U>

const U &min(const U &a, const U &b) {
	return (a < b) ? a : b;
}

template<typename V>

void swap(V &a, V &b) throw() {
	V temp = a;
	a = b;
	b = temp;
}

#endif