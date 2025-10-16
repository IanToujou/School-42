/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   given.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:01:53 by ibour             #+#    #+#             */
/*   Updated: 2025/10/16 12:05:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	enum {
		ADD,
		MULTI,
		VAL
	}   type;
	int val;
	struct node *l;
	struct node *r;
}   node;

node    *new_node(node n)
{
	node *ret = calloc(1, sizeof(n));
	if (!ret)
		return (NULL);
	*ret = n;
	return (ret);
}

void    destroy_tree(node *n)
{
	if (!n)
		return ;
	if (n->type != VAL)
	{
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void unexpected(char c) {
	if (c) printf("Unexpected token '%c'\n", c);
	else printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
	if (**s == c) { // Add c
		(*s)++;
		return (1);
	}
	return (0);
}

int expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected(**s);
	return (0);
}

node	*parse_addition(char **s);

node	*parse_par(char **s) {

	const int value = **s - '0';

	if (isdigit(**s)) {
		(*s)++;
		const node n = {VAL, value, NULL, NULL};
		node *res = new_node(n);
		if (!res)
			return (NULL);
		return res;
	}

	if (accept(s, '(')) {
		node *ret = parse_addition(s);
		if (!ret)
			return (NULL);
		if (!expect(s, ')')) {
			destroy_tree(ret);
			return (NULL);
		}
		return (ret);
	}

	unexpected(**s ? **s : 0);
	return (NULL);

}

node	*parse_multiplication(char **s) {

	node *left = parse_par(s);
	if (!left)
		return (NULL);

	while (accept(s, '*')) {

		node *right = parse_par(s);
		if (!right) {
			destroy_tree(left);
			return (NULL);
		}
		const node n = {MULTI, 0, left, right};
		node *temp = new_node(n);
		if (!temp) {
			destroy_tree(left);
			destroy_tree(right);
			return (NULL);
		}
		left = temp;

	}

	return left;

}

node	*parse_addition(char **s) {

	node *left = parse_multiplication(s);
	if (!left)
		return (NULL);

	while (accept(s, '+')) {

		node *right = parse_multiplication(s);
		if (!right) {
			destroy_tree(left);
			return (NULL);
		}
		const node n = {ADD, 0, left, right};
		node *temp = new_node(n);
		if (!temp) {
			destroy_tree(left);
			destroy_tree(right);
			return (NULL);
		}
		left = temp;

	}

	return left;

}

node    *parse_expr(char *s)
{
	node *ret = parse_addition(&s); // Create new node
	if (!ret) // Error handling is important here
		return (NULL);
	if (*s)
	{
		destroy_tree(ret);
		unexpected(*s); // Add this
		return (NULL);
	}
	return (ret);
}

int eval_tree(node *tree)
{
	if (!tree) // Add this check
		return 0;
	switch (tree->type)
	{
		case ADD:
			return (eval_tree(tree->l) + eval_tree(tree->r));
		case MULTI:
			return (eval_tree(tree->l) * eval_tree(tree->r));
		case VAL:
			return (tree->val);
	}
	return 0; // Add this
}

int main(const int argc, char **argv)
{
	if (argc != 2)
		return (1);
	node *tree = parse_expr(argv[1]);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
}