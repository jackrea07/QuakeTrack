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
	unsigned int currentSize;
	unsigned int capacity;
	unsigned int nextOpenIndex;
	Quake* heap;

	void expandHeap();
	void contractHeap();
	void heapifyUp(int index);
	void heapifyDown(int index);
	bool heapifyUpCheck(int parent, int current);
	
public:
	Heap(string t);
	Heap();
	void insert(Quake q);
	Quake extract();
	unsigned int size();
	Quake top();
	void printHeap();
	void printHeap2();
	void buildHeapInPlace(Quake* quakes, string t, int n);
};

