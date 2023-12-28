/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:58:08 by luide-so          #+#    #+#             */
/*   Updated: 2023/12/28 14:52:15 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Point const &src);
		Point(float const x, float const y);
		~Point(void);

		Point	&operator=(Point const &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
