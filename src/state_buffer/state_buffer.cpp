#include "state_buffer.h"


StateBuffer::StateBuffer(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	data = new int* [sizeY];

	for (int i = 0; i < sizeY; i++)
		data[i] = new int[sizeX];
}

StateBuffer::StateBuffer(const StateBuffer& source)
{
	sizeX = source.getSizeX();
	sizeY = source.getSizeX();

	data = new int* [sizeY];

	for (int y = 0; y < sizeY; y++) {
		data[y] = new int[sizeX];

		for (int x = 0; x < sizeX; x++)
			data[y][x] = source.get({x, y});
	}
}

StateBuffer::~StateBuffer()
{
	for (int i = 0; i < sizeY; i++)
		delete[] data[i];

	delete[] data;
}

StateBuffer& StateBuffer::operator=(const StateBuffer& source)
{
	if (this == &source)
		return *this;

	for (int i = 0; i < sizeY; i++)
	{
		delete[] data[i];
	}
	delete[] data;

	sizeX = source.getSizeX();
	sizeY = source.getSizeX();

	data = new int* [sizeY];

	for (int y = 0; y < sizeY; y++)
	{
		data[y] = new int[sizeX];

		for (int x = 0; x < sizeX; y++)
		{
			data[y][x] = source.get({x, y});
		}
	}

	return *this;
}

bool StateBuffer::operator !=(const StateBuffer& source) const
{
	if (sizeX != source.getSizeX() || sizeY != source.getSizeY())
		return true;

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (data[i][j] != source.get({j, i}))
			{
				return true;
			}
		}
	}

	return false;
}

GAME_OBJECTS StateBuffer::get(const Coordinate& coordinate) const
{
	return static_cast<GAME_OBJECTS>(data[coordinate.Y][coordinate.X]);
}

int StateBuffer::getSizeX() const
{
	return sizeX;
}

int StateBuffer::getSizeY() const
{
	return sizeY;
}

void StateBuffer::setObject(const int& X,const int& Y,const GAME_OBJECTS& object)
{
	data[Y][X] = object;
}

void StateBuffer::eraseObject(const Coordinate& location)
{
	this->setObject(location.X, location.Y, GAME_OBJECTS::CARPET);
}

void StateBuffer::setObject(const Coordinate& location, const GAME_OBJECTS& object)
{
	this->setObject(location.X, location.Y, object);
}