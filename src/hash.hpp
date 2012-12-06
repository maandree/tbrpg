// -*- mode: c++, coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __GUARD_HASH_HPP__
#define __GUARD_HASH_HPP__


#include <vector>
#include <unordered_map>


/**
 * Text based roll playing game
 * 
 * DD2387 Program construction with C++
 * Laboration 3
 * 
 * @author  Mattias Andrée <maandree@kth.se>
 */
namespace std
{
  #define __hash_vector(E, e)					\
  class hash<vector<E>>						\
  {								\
  public:							\
    size_t operator()(const vector<E>& vector) const		\
    {								\
      size_t rc = 0;						\
      size_t mul = 3;						\
      hash<E> hasher = hash<E>();				\
								\
      for (e element : vector)					\
	{							\
	  rc += mul * hasher(element);				\
	  mul = (mul >> 1) ^ ((-(mul & 1) & 0xF1) & 255);	\
	}							\
								\
      return rc;						\
    }								\
  }
  
    
  template<>
  template<typename E>
  __hash_vector(E, auto&);
  
  
  
  #define __hash_unordered_map(V) \
  class hash<unordered_map<K, V>>				\
  {								\
  public:							\
    size_t operator()(const unordered_map<K, V>& map) const	\
    {								\
      size_t rc = 0;						\
      size_t mul = 3;						\
      hash<K> hasherK = hash<K>();				\
      hash<V> hasherV = hash<V>();				\
								\
      auto ptr = map.begin();					\
      auto end = map.end();					\
								\
      while (ptr != end)					\
	{							\
	  auto& k = ptr->first;					\
	  auto& v = ptr->second;				\
	  ptr++;						\
								\
	  rc += mul * (hasherK(k) ^ hasherV(v));		\
	  mul = (mul >> 1) ^ ((-(mul & 1) & 0xF1) & 255);	\
	}							\
								\
      return rc;						\
    }								\
  }
  
  
  template<>
  template<typename K, typename V>
  __hash_unordered_map(V);
  
  
  #define __hash(T)		\
  template<>			\
  template<typename K>		\
  __hash_unordered_map(T);	\
  				\
  template<>			\
  __hash_vector(T, auto)
  
  
  __hash(bool);
  __hash(float);
  __hash(double);
  
  #define __hash_int(M)		\
  __hash(M char);		\
  __hash(M short int);		\
  __hash(M int);		\
  __hash(M long int);		\
  __hash(M long long int)
  
  __hash_int(signed);
  __hash_int(unsigned);
}


#undef __hash
#undef __hash_int
#undef __hash_vector
#undef __hash_unordered_map


#endif//__GUARD_HASH_HPP__

