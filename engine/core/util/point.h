/***************************************************************************
 *   Copyright (C) 2005-2008 by the FIFE team                              *
 *   http://www.fifengine.de                                               *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_VIDEO_POINT_H
#define FIFE_VIDEO_POINT_H

// Standard C++ library includes
#include <iostream>
#include <cassert>

// Platform specific includes
#include "fife_math.h"
#include "fife_stdint.h"

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder

namespace FIFE {

	/** A 2D Point
	 *
	 * This is a small helper class to aid in 2d vector arithmetics.
	 * @see Rect
	 */
	template <typename T> class PointType2D {
	public:
		union {
			T val[2];
			struct {
				T x,y;
			};
		};

		/** Constructor
		 *
		 * Creates a with 0 as default values.
		 */
		explicit PointType2D(T _x = 0, T _y = 0): x(_x), y(_y) {
		}

		/** Vector addition
		 */
		PointType2D<T> operator+(const PointType2D<T>& p) const {
			return PointType2D<T>(x + p.x, y + p.y);
		}

		/** Vector substraction
		 */
		PointType2D<T> operator-(const PointType2D<T>& p) const {
			return PointType2D<T>(x - p.x, y - p.y);
		}

		/** Vector inplace addition
		 */
		PointType2D<T>& operator+=(const PointType2D<T>& p) {
			x += p.x;
			y += p.y;
			return *this;
		}

		/** Vector inplace substraction
		 */
		PointType2D<T>& operator-=(const PointType2D<T>& p) {
			x -= p.x;
			y -= p.y;
			return *this;
		}

		/** Scalar multiplication with an integer value
		 */
		PointType2D<T> operator*(const T& i) const {
			return PointType2D<T>(x * i, y * i);
		}

		/** Scalar division with an integer value
		 */
		PointType2D<T> operator/(const T& i) const {
			return PointType2D<T>(x / i, y / i);
		}

		/** Equality comparision
		 */
		bool operator==(const PointType2D<T>& p) const {
			return x == p.x && y == p.y;
		}

		/** Equality comparision
		 */
		bool operator!=(const PointType2D<T>& p) const {
			return !(x == p.x && y == p.y);
		}

		/** Return length
		 */
		T length() const {
			double sq;
			sq = x*x + y*y;
			return static_cast<T>(sqrt(sq));
		}

		inline T& operator[] (int ind) { 
			assert(ind > -1 && ind < 2);
			return val[ind];
		}
	};

	/** Print coords of the Point to a stream
	 */
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const PointType2D<T>& p) {
		return os << "(" << p.x << ":" << p.y << ")";
	}

	typedef PointType2D<int> Point;
	typedef PointType2D<double> DoublePoint;

	/** A 3D Point
	 *
	 * This is a small helper class to aid in 3d vector arithmetics.
	 * @see Rect
	 */
	template <typename T> class PointType3D {
	public:
		union {
			T val[3];
			struct {
				T x,y,z;
			};
		};

		/** Constructor
		 *
		 * Creates a with 0 as default values.
		 */
		explicit PointType3D(T _x = 0, T _y = 0, T _z = 0): x(_x), y(_y), z(_z) {
		}

		/** Vector addition
		 */
		PointType3D<T> operator+(const PointType3D<T>& p) const {
			return PointType3D<T>(x + p.x, y + p.y, z + p.z);
		}

		/** Vector substraction
		 */
		PointType3D<T> operator-(const PointType3D<T>& p) const {
			return PointType3D<T>(x - p.x, y - p.y, z - p.z);
		}

		/** Vector inplace addition
		 */
		PointType3D<T>& operator+=(const PointType3D<T>& p) {
			x += p.x;
			y += p.y;
			z += p.z;
			return *this;
		}

		/** Vector inplace substraction
		 */
		PointType3D<T>& operator-=(const PointType3D<T>& p) {
			x -= p.x;
			y -= p.y;
			z -= p.z;
			return *this;
		}

		/** Scalar multiplication with an integer value
		 */
		PointType3D<T> operator*(const T& i) const {
			return PointType3D<T>(x * i, y * i, z * i);
		}

		/** Scalar division with an integer value
		 */
		PointType3D<T> operator/(const T& i) const {
			return PointType3D<T>(x / i, y / i, z / i);
		}

		/** Equality comparision
		 */
		bool operator==(const PointType3D<T>& p) const {
			return x == p.x && y == p.y && z == p.z;
		}

		/** Equality comparision
		 */
		bool operator!=(const PointType3D<T>& p) const {
			return !(x == p.x && y == p.y && z == p.z);
		}

		/** Return length
		 */
		T length() const {
			double sq;
			sq = x*x + y*y + z*z;
			return static_cast<T>(sqrt(sq));
		}

		inline T& operator[] (int ind) { 
			assert(ind > -1 && ind < 3); 
			return val[ind]; 
		}
	};

	/** Print coords of the Point to a stream
	 */
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const PointType3D<T>& p) {
		return os << "(" << p.x << ":" << p.y << ":" << p.z << ")";
	}

	typedef PointType3D<int> Point3D;
	typedef PointType3D<double> DoublePoint3D;

	/** Convert from 2D double point to 2D int point
	 */
	inline Point doublePt2intPt(DoublePoint pt) {
		Point tmp(static_cast<int>(pt.x), static_cast<int>(pt.y));
		return tmp;
	}

	/** Convert from 3D double point to 3D int point
	 */
	inline Point3D doublePt2intPt(DoublePoint3D pt) {
		Point3D tmp(static_cast<int>(pt.x), static_cast<int>(pt.y), static_cast<int>(pt.z));
		return tmp;
	}

	/** Convert from 2D int point to 2D double point
	 */
	inline DoublePoint intPt2doublePt(Point pt) {
		DoublePoint tmp(static_cast<double>(pt.x), static_cast<double>(pt.y));
		return tmp;
	}

	/** Convert from 3D int point to 3D double point
	 */
	inline DoublePoint3D intPt2doublePt(Point3D pt) {
		DoublePoint3D tmp(static_cast<double>(pt.x), static_cast<double>(pt.y), static_cast<double>(pt.z));
		return tmp;
	}

}

#endif
