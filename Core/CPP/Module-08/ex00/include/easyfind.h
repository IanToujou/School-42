/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:29:43 by ibour             #+#    #+#             */
/*   Updated: 2025/10/22 08:35:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <iterator>
#include <exception>

class NotFoundException: public std::exception {
public:
	virtual const char *what() const throw() {
		return "Not found.";
	}
};

template<typename T>
typename T::iterator easyfind(T &input, int i) {
	typename T::iterator iter = find(input.begin(), input.end(), i);
	if (iter == input.end())
		throw NotFoundException();
	return iter;
}

#endif