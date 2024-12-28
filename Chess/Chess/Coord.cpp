
#include "Coord.h"

Coord::Coord(char h, unsigned char v)
{
	_hor = h;
	_ver = v;
}


bool Coord::operator == (Coord other) const
{
	return _hor == other._hor && _ver == other._ver;
}


char Coord::hor() const
{
	return _hor;
}

unsigned char Coord::ver() const
{
	return _ver;
}


size_t Coord::hor_index() const
{
	return _hor - 'A';
}

size_t Coord::ver_index() const
{
	return _ver - 1;
}


bool Coord::add(int hor_inc, int ver_inc, Color color)
{
	int h = color == Color_White ? (int)_hor + hor_inc : (int)_hor - hor_inc;
	if (h < 'A' || h > 'A' + Rools::HorFieldSize - 1)
	{
		return false;
	}
	int v = color == Color_White ? (int)_ver + ver_inc : (int)_ver - ver_inc;
	if (v < 1 || v > 1 + Rools::VerFieldSize - 1)
	{
		return false;
	}
	_hor = h;
	_ver = v;
	return true;
}

