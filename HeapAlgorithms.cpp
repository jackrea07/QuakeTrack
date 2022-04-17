#include "HeapAlgorithms.h"

//metric is "relevance", "distance", or "magnitude"
vector<Quake> HeapAlgorithms::kthSmallest(vector<Quake>& quakes, int k, string metric) {
	Heap heap("max", metric);
	for (int i = 0; i < quakes.size(); i++) {
		if (heap.size() >= k && quakes[i].GetRelevance() > heap.top().GetRelevance())
			continue;
		heap.insert(quakes[i]);
		if (heap.size() > k)
			heap.extract();

	}
	vector<Quake> result;
	for (int i = 0; i < k; i++) {
		result.push_back(heap.extract());
	}
	return result;
}

//type is either "ascending" or "descending"
vector<Quake> HeapAlgorithms::heapSort(Quake* quakes, int size, string type, string metric) {
	if (type == "ascending") {
		type = "min";
	}
	else if (type == "descending") {
		type = "max";
	}
	Heap heap;
	heap.buildHeapInPlace(quakes, type, metric, size);
	vector<Quake> result;
	for (int i = 0; i < size; i++) {
		result.push_back(heap.extract());
	}
	return result;
}
