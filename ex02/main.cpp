/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:24:48 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/22 17:25:04 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void	test_comparisons()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;

	std::cout << "a > c is " << (a > c) << std::endl;
	std::cout << "a < c is " << (a < c) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a == c is " << (a == c) << std::endl;
	std::cout << "a != c is " << (a != c) << std::endl;

	std::cout << "b > c is " << (b > c) << std::endl;
	std::cout << "b < c is " << (b < c) << std::endl;
	std::cout << "b >= c is " << (b >= c) << std::endl;
	std::cout << "b <= c is " << (b <= c) << std::endl;
	std::cout << "b == c is " << (b == c) << std::endl;
	std::cout << "b != c is " << (b != c) << "\n" << std::endl;
}

void	test_arithmetic()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "a + b is " << (a + b) << std::endl;
	std::cout << "a - b is " << (a - b) << std::endl;
	std::cout << "a * b is " << (a * b) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;

	std::cout << "a + c is " << (a + c) << std::endl;
	std::cout << "a - c is " << (a - c) << std::endl;
	std::cout << "a * c is " << (a * c) << std::endl;
	std::cout << "a / c is " << (a / c) << std::endl;

	std::cout << "b + c is " << (b + c) << std::endl;
	std::cout << "b - c is " << (b - c) << std::endl;
	std::cout << "b * c is " << (b * c) << std::endl;
	std::cout << "b / c is " << (b / c) << "\n" << std::endl;
}

void	test_increment_decrement()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;

	std::cout << "--b is " << --b << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "b-- is " << b-- << std::endl;
	std::cout << "b is " << b << std::endl;

	std::cout << "++c is " << ++c << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "c++ is " << c++ << std::endl;
	std::cout << "c is " << c << "\n" << std::endl;
}

void	test_min_max()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);
	Fixed const d(30);
	Fixed const e(40);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) is " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, c) is " << Fixed::min(a, c) << std::endl;
	std::cout << "max(a, c) is " << Fixed::max(a, c) << std::endl;
	std::cout << "min(d, e) is " << Fixed::min(d, e) << std::endl;
	std::cout << "max(d, e) is " << Fixed::max(d, e) << std::endl;
}


int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << "\n" << std::endl;

	test_comparisons();
	test_arithmetic();
	test_increment_decrement();
	test_min_max();

	return (0);
}
