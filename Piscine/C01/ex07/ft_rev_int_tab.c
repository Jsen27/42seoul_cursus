/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:41:29 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/07 17:54:57 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	size--;
	if (size % 2 == 0)
	{
		while (!(i == size))
		{
			temp = tab[i];
			tab[i++] = tab[size];
			tab[size--] = temp;
		}
	}
	else
	{
		while (i < size)
		{
			temp = tab[i];
			tab[i++] = tab[size];
			tab[size--] = temp;
		}
	}
}
