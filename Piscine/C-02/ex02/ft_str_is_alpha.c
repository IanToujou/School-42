/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:20:18 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 13:20:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	char	c;

	c = *str;
	while (c != '\0')
	{
		c = *str;
		if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') && c != 0)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*int main(int argc, char** argv)
{
    printf("Testing string: %s\n", argv[1]);
    printf("Result: %d\n", ft_str_is_alpha(argv[1]));
}*/
