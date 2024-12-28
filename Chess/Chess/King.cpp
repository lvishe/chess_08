#include "King.h"


King::King(Color color) : Figure(color) {}


void King::find_targets(Coord from, Field & field, vector<Coord>&targets) const
{
	add_valid_target(from, 0, 1, targets, field);
	add_valid_target(from, 0, -1, targets, field);
	add_valid_target(from, 1, 0, targets, field);
	add_valid_target(from, -1, 0, targets, field);
	add_valid_target(from, 1, 1, targets, field);
	add_valid_target(from, 1, -1, targets, field);
	add_valid_target(from, -1, 1, targets, field);
	add_valid_target(from, -1, -1, targets, field);
}


void King::add_valid_target(Coord coord, int h, int v, std::vector<Coord>& targets, const Field& field) const
{
	if (coord.add(h, v, _color))
	{
		Figure::add_valid_target(coord, field, targets);
	}
}

void King::print(std::ostream& os) const
{
	os << (_color == Color_White ? "K" : "k");
}