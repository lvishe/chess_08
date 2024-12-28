#pragma once

#include "StrightGouingFigure.h"

class Rook : public StrightGouingFigure
{
public:
	Rook(Color color);

public:
	virtual void find_targets(Coord from, Field& field, vector<Coord>& targets) const override;

	virtual void print(std::ostream& os) const override;
};