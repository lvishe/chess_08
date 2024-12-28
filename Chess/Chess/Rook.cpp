#include "Rook.h"


Rook::Rook(Color color) : StrightGouingFigure(color) {}

void Rook::find_targets(Coord from, Field& field, vector<Coord>& targets) const 
{
	add_valid_targets(from, 0, 1, targets, field);
	add_valid_targets(from, 0, -1, targets, field);
	add_valid_targets(from, 1, 0, targets, field);
	add_valid_targets(from, -1, 0, targets, field);
}


void Rook::print(std::ostream& os) const
{
	os << (_color == Color_White ? "R" : "r");
}