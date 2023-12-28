/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:30 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/22 16:10:17 by luide-so         ###   ########.fr       */
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

		// Arithmetic operators
		Fixed	&operator=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		// Comparison operators
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		// Increment and decrement operators
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		// Min and Max member functions
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);

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
