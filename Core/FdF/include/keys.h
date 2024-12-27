/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:36:05 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 04:45:47 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__

enum e_keys
{
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_NUMPAD_ZERO = 65438,
	KEY_NUMPAD_ONE = 65436,
	KEY_NUMPAD_TWO = 65433,
	KEY_NUMPAD_THREE = 65435,
	KEY_NUMPAD_FOUR = 65430,
	KEY_NUMPAD_FIVE = 65437,
	KEY_NUMPAD_SIX = 65432,
	KEY_NUMPAD_SEVEN = 65429,
	KEY_NUMPAD_EIGHT = 65431,
	KEY_NUMPAD_NINE = 65434,
	KEY_NUMPAD_PLUS = 65451,
	KEY_NUMPAD_MINUS = 65453,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_SEVEN = 55,
	KEY_EIGHT = 56,
	KEY_NINE = 57,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_R = 114,
	KEY_T = 116,
	KEY_Y = 121,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_L = 108,
	KEY_C = 99,
	KEY_V = 118,
	MOUSE_LEFT_CLICK = 1,
	MOUSE_RIGHT_CLICK = 2,
	MOUSE_SCROLL_CLICK = 3,
	MOUSE_SCROLL_DOWN = 4,
	MOUSE_SCROLL_UP = 5,
};

# else

enum e_keys
{
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_SIX = 22,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_R = 15,
	KEY_T = 17,
	KEY_Y = 16,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_L = 37,
	MOUSE_LEFT_CLICK = 1,
	MOUSE_RIGHT_CLICK = 2,
	MOUSE_SCROLL_CLICK = 3,
	MOUSE_SCROLL_DOWN = 4,
	MOUSE_SCROLL_UP = 5,
};
# endif

#endif