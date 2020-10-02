#include "Storage.h"

Storage::Storage(){
	SizeX = 40;
	SizeY = 20;

	Data = new int [SizeY*SizeX];
}

Storage::Storage(int sizeX, int sizeY)
{
	SizeX = sizeX;
	SizeY = sizeY;

	Data = new int [SizeY*SizeX];
}


Storage::Storage(const Storage& source)
{
	SizeX = source.GetSizeX();
	SizeY = source.GetSizeX();

	Data = new int [SizeY * SizeX];
}

Storage::~Storage()
{
	delete[] Data;
}

void Storage::operator=(const Storage& source)
{
	SizeX = source.GetSizeX();
	SizeY = source.GetSizeX();

	Data = new int[SizeY * SizeX];
}

bool Storage::operator !=(const Storage& source)
{
	bool tmp = false;
	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			int	a = Data[i * SizeX + j];
			if (Data[i*SizeX + j] != source.Get(i, j))
			{
				tmp = true;
				break;
			}
		}
		if (tmp == true)
		{
			break;
		}
	}
	return tmp;
}




int Storage::Get(int X, int Y) const
{
	return Data[Y * SizeX + X];
}

int Storage::GetSizeX() const
{
	return SizeX;
}

int Storage::GetSizeY() const
{
	return SizeY;
}


bool Storage::isFreeMove(Coordinate& point)
{
	if (this->Get(point.X, point.Y) == 0)
	{
		return true;
	}
	else
		return false;

}

void Storage::SetObject(int X, int Y, int index)
{
	Data[Y * SizeX + X] = index;
}

void Storage::EraseObject(const Coordinate& location)
{
	this->SetObject(location.X, location.Y, 0);
}

void Storage::SetObject(int index, const Coordinate& location)
{
	this->SetObject(location.X, location.Y, index);
}