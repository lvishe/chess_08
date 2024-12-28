#pragma once

#include "Field.h"

#include "King.h"
#include "Rook.h"

#include <iostream>
#include "Figure.h"

class Game
{
	Field _field;
	King* _white_king;
	King* _black_king;

public:
	void start()
	{
		_white_king = new King(Color_White);
		_black_king = new King(Color_Black);

		_field[Coord('A', 1)] = new Rook(Color_White);
		_field[Coord('E', 1)] = _white_king;
		_field[Coord('H', 1)] = new Rook(Color_White);

		_field[Coord('A', 8)] = new Rook(Color_Black);
		_field[Coord('E', 8)] = _black_king;
		_field[Coord('H', 8)] = new Rook(Color_Black);
	}


	bool step(Coord from, Coord to)
	{
		Figure* f = _field[from];
		if (!f)
		{
			return false;
		}

		Figure* captured_figure = nullptr;
		
		bool result = f->go_to(from, to, _field, captured_figure);
		
		if (result && captured_figure != nullptr)
		{
			delete captured_figure;
		}

		if (check_is_check(f->color()))
		{
			std::cout << "\ncheck\n";
		}

		return result;
	}


	bool check_is_check(Color color)
	{
		King* king = color == Color_Black ? _white_king : _black_king;

		for (char h = 'A'; h < 'A' + Rools::HorFieldSize; h++)
		{
			for (unsigned char v = 1; v < 1 + Rools::VerFieldSize; v++)
			{
				Coord c(h, v);
				Figure* f = _field[c];
				if (f == nullptr || f->color() != color)
				{
					continue;
				}
				std::vector<Coord> targets;
				f->find_targets(c, _field, targets);
				for (size_t i = 0; i < targets.size(); i++)
				{
					Figure* potential_king = _field[targets[i]];
					if (potential_king == king)
					{
						return true;
					}
				}
			}
		}
		
		return false;
	}

	void print_board() const 
	{
		_field.print();
	}
};
