/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:58:38 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/28 14:49:53 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	abs(float x)
{
	return (x < 0 ? -x : x);
}

float area(const Point p1, const Point p2, const Point p3)
{
	Fixed first(p1.getX() * p2.getY() - p3.getX() * p2.getY());
	Fixed second(p3.getX() * p1.getY() - p1.getX() * p3.getY());
	Fixed third(p2.getX() * p3.getY() - p2.getX() * p1.getY());
	Fixed result(first + second + third);

	return (abs(result.toFloat()) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float areaABP = area(a, b, point);
	float areaBCP = area(b, c, point);
	float areaCAP = area(c, a, point);
	float areaABC = area(a, b, c);

	bool notInSegment = areaABP && areaBCP && areaCAP;
	bool inside = areaABC == areaABP + areaBCP + areaCAP;

	return (notInSegment && inside);
}
