/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:58:53 by ibour             #+#    #+#             */
/*   Updated: 2025/06/24 21:01:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

	std::string str = "HI THIS IS BRAIN!";
	std::string *stringPTR = &str;
	const std::string &stringREF = str;

	std::cout << "Addr of str:\t" << &str << std::endl;
	std::cout << "Addr of stringPTR:\t" << &stringPTR << std::endl;
	std::cout << "Addr of stringREF:\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str:\t\t" << str <<std::endl;
	std::cout << "Value pointed by stringPTR:\t" << stringPTR <<std::endl;
	std::cout << "Value of stringREF:\t\t" << stringREF <<std::endl;

	return 0;

}