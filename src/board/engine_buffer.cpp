#include "engine_buffer.h"

EngineBuffer::EngineBuffer(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	data = new int [sizeY*sizeX];
}


EngineBuffer::EngineBuffer(const EngineBuffer& source)
{
	sizeX = source.getSizeX();
	sizeY = source.getSizeX();

	data = new int [sizeY * sizeX];
}

EngineBuffer::~EngineBuffer()
{
	delete[] data;
}

EngineBuffer& EngineBuffer::operator=(const EngineBuffer& source)
{
	sizeX = source.getSizeX();
	sizeY = source.getSizeX();

	data = new int[sizeY * sizeX];

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			data[i*sizeX + j] = source.get(i, j);
		}
	}

	return *this;
}

bool EngineBuffer::operator !=(const EngineBuffer& source) const
{
	bool isNonEqual = false;
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (data[i*sizeX + j] != source.get(i, j))
			{
				isNonEqual = true;
				break;
			}
		}
	}

	return isNonEqual;
}




int EngineBuffer::get(int X, int Y) const
{
	return data[Y * sizeX + X];
}

int EngineBuffer::getSizeX() const
{
	return sizeX;
}

int EngineBuffer::getSizeY() const
{
	return sizeY;
}


bool EngineBuffer::isFreeMove(Coordinate& point)
{
	return this->get(point.X, point.Y) == 0;
}

void EngineBuffer::setObject(int X, int Y, int index)
{
	data[Y * sizeX + X] = index;
}

void EngineBuffer::eraseObject(const Coordinate& location)
{
	this->setObject(location.X, location.Y, 0);
}

void EngineBuffer::setObject(int index, const Coordinate& location)
{
	this->setObject(location.X, location.Y, index);
}