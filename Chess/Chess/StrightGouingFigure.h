#pragma once

#include "Figure.h"


class StrightGouingFigure : public Figure
{
public:
	StrightGouingFigure(Color color);
	
	virtual void print(std::ostream& os) const = 0;

protected:
	void add_valid_targets(Coord coord, int h, int v, std::vector<Coord>& targets, const Field& field) const;
};