#include "Field.h"
#include "Game.h"


Figure::Figure(Color color)
{
	_color = color;
}


Color Figure::color() const
{
	return _color;
}


bool Figure::go_to(Coord from, Coord to, Field& field, Figure*& captured_figure)
{
	vector<Coord> targets;
	find_targets(from, field, targets);


	if (std::find(targets.begin(), targets.end(), to) == targets.end())
	{
		return false;
	}

	captured_figure = field.move_figure(from, to);
	return true;
}


bool Figure::add_valid_target(Coord target, const Field& field, vector<Coord>& targets) const
{
	const Figure* figure = field[target];
	if (figure != nullptr)
	{
		if (figure->color() != _color)
		{
			targets.push_back(target);
		}
		return true;
	}
	targets.push_back(target);
	return false;
}