#pragma once

#include "Rools.h"

class Coord
{
public:
	char _hor;
	unsigned char _ver;

public:
	Coord(char h, unsigned char v);

public:
	bool operator == (Coord other) const;
	

public:
	char hor() const;

	unsigned char ver() const;

	size_t hor_index() const;

	size_t ver_index() const;

	bool add(int hor_inc, int ver_inc, Color color);
};
