#include "StrightGouingFigure.h"


StrightGouingFigure::StrightGouingFigure(Color color) : Figure(color) {}


void StrightGouingFigure::add_valid_targets(Coord coord, int h, int v, std::vector<Coord>& targets, const Field& field) const
{
	while (coord.add(h, v, _color))
	{
		if (Figure::add_valid_target(coord, field, targets))
		{
			break;
		}
	}
}