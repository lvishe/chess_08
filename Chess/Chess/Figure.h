#pragma once

#include <vector>

#include "Coord.h"
#include "Field.h"
#include <ostream>

using namespace std;

class Figure
{
protected:
	Color _color;

public:
	Figure(Color color);

public:
	Color color() const;


public:
	virtual bool go_to(Coord from, Coord to, Field& field, Figure*& captured_figure);

	virtual void find_targets(Coord from, Field& field, vector<Coord>& targets) const = 0;

	virtual void print(std::ostream& os) const = 0;

protected:
	bool add_valid_target(Coord target, const Field& field, vector<Coord>& targets) const;

};
