#include "Field.h"

#include "Figure.h"


Field::Field()
{
	{
		for (int i = 0; i < Rools::VerFieldSize; i++)
		{
			for (int j = 0; j < Rools::HorFieldSize; j++)
			{
				_field[i][j] = nullptr;
			}
		}
	}
}


Figure*& Field::operator [] (Coord coord)
{
	return _field[coord.hor_index()][coord.ver_index()];
}

const Figure* Field::operator [] (Coord coord) const
{
	return _field[coord.hor_index()][coord.ver_index()];
}


bool Field::is_cell_empty(Coord coord) const
{
	return _field[coord.hor_index()][coord.ver_index()] == nullptr;
}

Figure* Field::move_figure(Coord from, Coord to)
{
	Figure* src_figure = (*this)[from];
	Figure* dest_figure = (*this)[to];
	(*this)[from] = nullptr;
	(*this)[to] = src_figure;
	return dest_figure;
}


void Field::print() const
{
	for (int i = Rools::VerFieldSize - 1; i >= 0; i--)
	{
		for (int j = 0; j < Rools::HorFieldSize; j++)
		{
			if (_field[j][i] != nullptr)
			{
				_field[j][i]->print(std::cout);
				std::cout << " ";
			}
			else
			{
				std::cout << "# ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}