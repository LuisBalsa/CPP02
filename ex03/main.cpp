/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:24:48 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/28 14:53:41 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <iomanip>

#define GREY "\033[90m"
#define YELLOW "\033[93m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

float area(const Point p1, const Point p2, const Point p3);

bool bsp_mod(Point const a, Point const b, Point const c, Point const point)
{
	float areaABC = area(a, b, c);
	float subABP = area(a, b, point);
	float subBCP = area(b, c, point);
	float subCAP = area(c, a, point);

	return (areaABC == subABP + subBCP + subCAP);
}

void drawTriangle(Point a, Point b, Point c, Point p, int mode)
{
	std::string	fill = " X  ";
	std::string	empty = " .  ";
	Fixed	minX = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX());
	Fixed	maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX());
	Fixed	minY = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY());
	Fixed	maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY());

	std::cout << "\033c" << std::endl;
	for (int y = maxY.toInt(); y >= minY.toInt(); y--)
	{
		std::cout << GREY << std::setfill(' ') << std::setw(3) << y << " " << RESET;
		for (int x = minX.toInt(); x <= maxX.toInt(); x++)
		{
			if (mode == 1 && (Fixed)x == p.getX() && (Fixed)y == p.getY() && bsp(a, b, c, Point(x, y)))
				std::cout << BOLD << GREEN << " I  " << RESET;
			else if (mode == 1 && (Fixed)x == p.getX() && (Fixed)y == p.getY() && bsp_mod(a, b, c, Point(x, y)))
				std::cout << BOLD << RED << " E  " << RESET;
			else if (mode == 1 && (Fixed)x == p.getX() && (Fixed)y == p.getY() && !bsp_mod(a, b, c, Point(x, y)))
				std::cout << BOLD << RED << " O  " << RESET;
			else if (bsp_mod(a, b, c, Point(x, y)))
				std::cout << YELLOW << fill << RESET;
			else
				std::cout << GREY << empty << RESET;
		}
		std::cout << std::endl;
	}
	std::cout << "   ";
	for (int x = minX.toInt(); x <= maxX.toInt(); x++)
		std::cout << GREY << std::setfill(' ') << std::setw(3) << x << " " << RESET;
	std::cout << std::endl;
	if (mode == 1)
		std::cout << "Legend: I = Inside, E = Edge, O = Outside" << std::endl;
}

int main(void)
{
	Point a(5, 10);
	Point b(-5, -12);
	Point c(-11, -3);
	float x;
	float y;

	drawTriangle(a, b, c, Point(0, 0), 0);
	std::cout << "Enter an x and y value (x y): " << std::endl;
	std::cin >> x >> y;
	if (std::cin.fail())
	{
		std::cout << RED << "\n\tWrong input\n" << std::endl;
		return (EXIT_FAILURE);
	}
	drawTriangle(a, b, c, Point(x, y), 1);
	if (bsp(a, b, c, Point(x, y)))
		std::cout << GREEN << "\n\tThe position (" << x << "," << y << ") is inside the triangle" << RESET << std::endl << std::endl;
	else
		std::cout << RED << "\n\tThe position (" << x << "," << y << ") is outside the triangle" << RESET << std::endl << std::endl;
	return 0;
}
