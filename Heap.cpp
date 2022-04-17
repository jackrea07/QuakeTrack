#include "Heap.h"
float Heap::FLOAT_MIN = std::numeric_limits<float>::max() * -1;
float Heap::FLOAT_MAX = std::numeric_limits<float>::max();

Heap::Heap(string t) {
	type = t;
	currentSize = 0;
	capacity = 1;
	nextOpenIndex = 0;
	heap = new Quake[capacity];
}

Heap::Heap() {}
void Heap::insert(Quake q) {
	heap[nextOpenIndex] = q;
	heapifyUp(nextOpenIndex);
	currentSize++;
	nextOpenIndex++;
	if (currentSize >= capacity) {
		expandHeap();
	}
}

Quake Heap::extract() {
	Quake root = heap[0];
	currentSize--;
	nextOpenIndex--;
	heap[0] = heap[nextOpenIndex];
	heapifyDown(0);
	if (currentSize < capacity / 2) {
		contractHeap();
	}
	return root;
}

void Heap::buildHeapInPlace(Quake* quakes, string t, int n) {
	delete[] heap;
	type = t;
	heap = quakes;
	currentSize = n;
	nextOpenIndex = n;
	capacity = n;
	for (int i = currentSize / 2; i >= 0; i--) {
		heapifyDown(i);
	}
}
void Heap::contractHeap() {
	capacity /= 2;
	Quake* newHeap = new Quake[capacity];
	for (int i = 0; i < currentSize; i++) {
		newHeap[i] = heap[i];
	}
	delete[] heap;
	heap = newHeap;
}

void Heap::expandHeap() {
	capacity *= 2;
	Quake* newHeap = new Quake[capacity];
	for (int i = 0; i < currentSize; i++) {
		newHeap[i] = heap[i];
	}
	delete[] heap;
	heap = newHeap;
}

void Heap::heapifyUp(int index) {
	int parentPosition = floor((index - 1) / 2);
	if (heapifyUpCheck(parentPosition, index)) {
		Quake temp = heap[parentPosition];
		heap[parentPosition] = heap[index];
		heap[index] = temp;
		heapifyUp(parentPosition);
	}
}

bool Heap::heapifyUpCheck(int parent, int current) {
	if (type == "min") {
		return heap[parent].GetRelevance() > heap[current].GetRelevance();
	}
	else {
		return heap[parent].GetRelevance() < heap[current].GetRelevance();
	}
}

void Heap::heapifyDown(int index) {
	if (index >= currentSize - 1 || currentSize == 0) {
		return;
	}
	int leftPosition = 2 * index + 1;
	int rightPosition = 2 * index + 2;
	Quake current = heap[index];
	float left, right;
	if (leftPosition > currentSize - 1) {
		left = type == "min" ? FLOAT_MAX : FLOAT_MIN; 
		return;
	}
	else {
		left = heap[leftPosition].GetRelevance();
	}

	if (rightPosition > currentSize - 1) {
		right = type == "min" ? FLOAT_MAX : FLOAT_MIN; 
	}
	else {
		right = heap[rightPosition].GetRelevance();
	}
	if (type == "min") {
		if (current.GetRelevance() > left || current.GetRelevance() > right) {
			int minIndex;
			if (left <= right) {
				minIndex = leftPosition;
			}
			else {
				minIndex = rightPosition;
			}
			heap[index] = heap[minIndex];
			heap[minIndex] = current;
			heapifyDown(minIndex);
		}
	}
	else if(type == "max") {
		if (current.GetRelevance() < left || current.GetRelevance() < right) {
			int maxIndex;
			if (left >= right) {
				maxIndex = leftPosition;
			}
			else {
				maxIndex = rightPosition;
			}
			heap[index] = heap[maxIndex];
			heap[maxIndex] = current;
			heapifyDown(maxIndex);
		}
	}	
}

unsigned int Heap::size() {
	return currentSize;
}

Quake Heap::top() {
	return heap[0];
}

void Heap::printHeap() {
	int next = 1;
	for (int i = 0; i < currentSize; i++) {
		if (i == next - 1) {
			cout << endl;
			next *= 2;
		}
		cout << heap[i].GetRelevance() << " ";
	}
	cout << endl;
}

void Heap::printHeap2() {
	for (int i = 0; i < currentSize; i++) {
		cout << "heap[" << i << "]: " << heap[i].GetRelevance() << endl;
	}
}