#pragma once

#include "Rools.h"
#include "Coord.h"
#include <iostream>

class Figure;

class Field
{
	Figure* _field[Rools::HorFieldSize][Rools::VerFieldSize];

public:
	Field();

private:
	Field(const Field&);

public:

	Figure*& operator [] (Coord coord);

	const Figure* operator [] (Coord coord) const;

	bool is_cell_empty(Coord coord) const;

	Figure* move_figure(Coord from, Coord to);


	void print() const;
};