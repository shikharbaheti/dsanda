#pragma once
#include <vector>
#include <list>
#include <utility>
using namespace std;
template <typename T>
class HashTable
{
private:
	int size;
	int usedChains;
	//create a new vector of lists of pairs
	vector<list<pair<int, T>>> hashVector;

	int hash(const int _key)
	{
		return _key % size;
	}

public:
	//constructs a hastable of size of the input size
	HashTable(const int _size)
	{
		size = _size;
		usedChains = 0;
		hashVector.resize(_size);
	}
	//clear and delete everything from the hastable
	~HashTable()
	{
		hashVector.clear();
		size = 0;
	}
	//inserts a value into an index provided by the hash function
	void insert(const int _key, T _value)
	{
		int index = hash(_key);
		pair<int, T> insertPair(_key, _value);
		if (hashVector[index].size() == 0)
		{
			usedChains++;
		}
		hashVector[index].push_back(insertPair);
	}
	// returns the smallest chain in the vector
	int minChainLen()
	{
		int min = 1000; // some big number
		for (const auto &itList : hashVector)
		{
			int numPairs = 0;
			// Making sure list isn't empty
			if (itList.size() != 0)
			{
				// WRITE IT IN THE REPORT!
				for (const auto &itPair : itList)
				{
					numPairs++;
				}
				if (numPairs < min)
				{
					min = numPairs;
				}
			}
		};
		return min;
	}
	//returns the biggest chain in the vector
	int maxChainLen()
	{
		int max = 0;
		for (const auto &itList : hashVector)
		{
			int numPairs = 0;
			for (const auto &itPair : itList)
			{
				numPairs++;
			}
			if (numPairs > max)
			{
				max = numPairs;
			}
		};
		return max;
	}
	//returns the average length of vectors in the vector
	double averageChainLen()
	{
		double lengthOfChains = 0;
		for (const auto &itList : hashVector)
		{
			for (const auto &itPair : itList)
			{
				lengthOfChains++;
			}
		}
		return (lengthOfChains / usedChains);
	}
	//returns the index of a key in the vector
	T *search(int _key)
	{
		int index = hash(_key);
		for (auto &itPair : hashVector[index])
		{
			if (itPair.first == _key)
			{
				return &itPair.second;
			}
		};
		return NULL;
	}

	//helper functions
	vector<list<pair<int, T>>> helperPrinter()
	{
		return hashVector;
	}
	int getSize()
	{
		return size;
	}
	int getUsedChains()
	{
		return usedChains;
	}
};
