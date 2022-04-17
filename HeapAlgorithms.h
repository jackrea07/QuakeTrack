#pragma once
#include "Heap.h"
class HeapAlgorithms
{
public:
	static vector<Quake> kthSmallest(vector<Quake>& quakes, int k);
	static vector<Quake> heapSort(Quake* quakes, int size, string type);
};

