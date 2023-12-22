/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:30 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/21 18:18:36 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);

		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif
