#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Quake.h"
using std::string;
using std::cout;
using std::endl;
using std::floor;
using std::vector;
class Heap
{
	static float FLOAT_MIN;
	static float FLOAT_MAX;
	string type;
	char metric;
	unsigned int currentSize;
	unsigned int capacity;
	unsigned int nextOpenIndex;
	Quake* heap;

	void expandHeap();
	void contractHeap();
	void heapifyUp(int index);
	void heapifyDown(int index);
	bool heapifyUpCheck(int parent, int current);
	float getMetricValue(Quake q);
	
public:
	Heap(string t, char m);
	Heap();
	void insert(Quake q);
	Quake extract();
	unsigned int size();
	Quake top();
	void printHeap();
	void printHeap2();
	void buildHeapInPlace(Quake* quakes, string t, char m, int n);
};

