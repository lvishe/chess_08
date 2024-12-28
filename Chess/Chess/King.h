#pragma once
#include "Figure.h"


class King : public Figure
{
public:
	King(Color color);
		
public:
	virtual void find_targets(Coord from, Field& field, vector<Coord>& targets) const override;

	virtual void print(std::ostream& os) const override;

private:
	void add_valid_target(Coord coord, int h, int v, std::vector<Coord>& targets, const Field& field) const;
};

