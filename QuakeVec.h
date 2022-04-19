#pragma once
#include "Quake.h"
#include "Heap.h"
class QuakeVec
{
public:
	std::vector<Quake> quakes;
	Quake* q;

	QuakeVec() {
		std::ifstream inFile("quakes.csv");
		if (inFile.is_open()) {

			std::string fileLine;
			std::getline(inFile, fileLine);

			while (getline(inFile, fileLine)) {

				std::istringstream stream(fileLine);

				std::string date;
				float mag;
				float depth;
				float longitude;
				float latitude;

				std::string tempMag;
				std::string tempDepth;
				std::string tempLong;
				std::string tempLat;

				std::getline(stream, tempDepth, ',');
				depth = stof(tempDepth);
				depth = depth * 0.621371;

				getline(stream, tempMag, ',');
				mag = stof(tempMag);

				getline(stream, tempLat, ',');
				latitude = stof(tempLat);

				getline(stream, tempLong, ',');
				longitude = stof(tempLong);

				getline(stream, date);

				Quake quake(depth, mag, 0, 0, date, longitude, latitude);
				quakes.push_back(quake);
			}
		}
		q = new Quake[quakes.size()];
		for (int i = 0; i < quakes.size(); i++) {
			q[i] = quakes[i];
		}
	}

	void parseData() {
		std::ifstream inFile("quakes.csv");
		if (inFile.is_open()) {

			std::string fileLine;
			std::getline(inFile, fileLine);

			while (getline(inFile, fileLine)) {

				std::istringstream stream(fileLine);

				std::string date;
				float mag;
				float depth;
				float longitude;
				float latitude;

				std::string tempMag;
				std::string tempDepth;
				std::string tempLong;
				std::string tempLat;

				std::getline(stream, tempDepth, ',');
				depth = stof(tempDepth);
				depth = depth * 0.621371;

				getline(stream, tempMag, ',');
				mag = stof(tempMag);

				getline(stream, tempLat, ',');
				latitude = stof(tempLat);

				getline(stream, tempLong, ',');
				longitude = stof(tempLong);

				getline(stream, date);

				Quake quake(depth, mag, 0.0f, 0.0f, date, longitude, latitude);
				quakes.push_back(quake);
			}
		}
	}

	void updateDistanceAndRelevance(float userLat, float userLong) {
		for (int i = 0; i < quakes.size(); i++) {
			quakes[i].UpdateDistRel(userLat, userLong);
			q[i].UpdateDistRel(userLat, userLong);
		}
	}

	std::vector<Quake> ReturnTop5(int sortParam) {
		std::vector<Quake> solution;
		for (int i = 0; i < 5; i++) {
			solution.push_back(quakes[i]);
		}
		return solution;
	}

	std::vector<Quake> ReturnBottom5(int sortParam) {
		std::vector<Quake> solution;
		for (int i = 0; i < 5; i++) {
			solution.push_back(quakes[quakes.size() - 1 - i]);
		}
		return solution;
	}

	std::vector<Quake> ReturnTop5_2() {
		std::vector<Quake> solution;
		for (int i = 0; i < 5; i++) {
			solution.push_back(q[i]);
		}
		return solution;
	}

	int Partition(int sortParam, int first, int last, int pivotindex)
	{
		if (sortParam == 1)
		{
			if (first + pivotindex < last)
			{
				float pivot = quakes[first + pivotindex].GetRelevance();
				int up = first;
				int down = last;

				while (up < down)
				{
					while (up < last)
					{
						if (quakes[up].GetRelevance() > pivot)
						{
							break;
						}
						up++;
					}
					while (down > first)
					{
						if (quakes[down].GetRelevance() < pivot)
						{
							break;
						}
						down--;
					}
					if (up < down)
					{
						Quake temp = quakes[down];
						quakes[down] = quakes[up];
						quakes[up] = temp;
					}
				}

				Quake temp = quakes[down];
				quakes[down] = quakes[first + pivotindex];
				quakes[first + pivotindex] = temp;
				return down;
			}
			return last;
		}
		else if (sortParam == 2)
		{
			if (first + pivotindex < last)
			{
				float pivot = quakes[first + pivotindex].GetMag();
				int up = first;
				int down = last;

				while (up < down)
				{
					while (up < last)
					{
						if (quakes[up].GetMag() > pivot)
						{
							break;
						}
						up++;
					}
					while (down > first)
					{
						if (quakes[down].GetMag() < pivot)
						{
							break;
						}
						down--;
					}
					if (up < down)
					{
						Quake temp = quakes[down];
						quakes[down] = quakes[up];
						quakes[up] = temp;
					}
				}

				Quake temp = quakes[down];
				quakes[down] = quakes[first + pivotindex];
				quakes[first + pivotindex] = temp;
				return down;
			}
			return last;
		}
		else if (sortParam == 3)
		{
			if (first + pivotindex < last)
			{
				float pivot = quakes[first + pivotindex].GetDistance();
				int up = first;
				int down = last;

				while (up < down)
				{
					while (up < last)
					{
						if (quakes[up].GetDistance() > pivot)
						{
							break;
						}
						up++;
					}
					while (down > first)
					{
						if (quakes[down].GetDistance() < pivot)
						{
							break;
						}
						down--;
					}
					if (up < down)
					{
						Quake temp = quakes[down];
						quakes[down] = quakes[up];
						quakes[up] = temp;
					}
				}

				Quake temp = quakes[down];
				quakes[down] = quakes[first + pivotindex];
				quakes[first + pivotindex] = temp;
				return down;
			}
			return last;
		}
		return 0;
	}
	void QuickSort(int sortParam, int first, int last, int pivotindex)
	{
		if (first < last)
		{
			int pivot = Partition(sortParam, first, last, pivotindex);
			QuickSort(sortParam, first, pivot - 1, pivotindex);
			QuickSort(sortParam, pivot + 1, last, pivotindex);
			int i = 0;
		}
	}

	vector<Quake> heapSort(Quake* quakes, int size, string type, int metric) {
		if (type == "ascending") {
			type = "min";
		}
		else if (type == "descending") {
			type = "max";
		}
		Heap heap;
		heap.buildHeapInPlace(q, type, (char)metric, size);
		vector<Quake> result;
		for (int i = 0; i < size; i++) {
			result.push_back(heap.heapSortExtract());
		}
		return result;
	}

	std::vector<Quake> kthSmallest(std::vector<Quake>& quakes, int k, int metric) {
		Heap heap("max", (char)metric);
		for (int i = 0; i < quakes.size(); i++) {
			float currentValue = 0;
			float heapTopValue = 0;
			updateMetricValues(quakes, metric, heap, i, currentValue, heapTopValue);
			if (heap.size() >= k && currentValue > heapTopValue)
				continue;
			heap.insert(quakes[i]);
			if (heap.size() > k)
				heap.extract();

		}
		vector<Quake> result;
		for (int i = 0; i < k; i++) {
			result.push_back(heap.extract());
		}
		for (int i = 0; i < 2; i++) { //reverses result vector so that when displaying results, smallest value is displayed first
			Quake temp = result[i];
			result[i] = result[4 - i];
			result[4 - i] = temp;
		}
		return result;
	}

	std::vector<Quake> kthLargest(std::vector<Quake>& quakes, int k, int metric) {
		Heap heap("min", (char)metric);
		for (int i = 0; i < quakes.size(); i++) {
			float currentValue = 0;
			float heapTopValue = 0;
			updateMetricValues(quakes, metric, heap, i, currentValue, heapTopValue);
			if (heap.size() >= k && currentValue < heapTopValue)
				continue;
			heap.insert(quakes[i]);
			if (heap.size() > k)
				heap.extract();

		}
		vector<Quake> result;
		for (int i = 0; i < k; i++) {
			result.push_back(heap.extract());
		}
		for (int i = 0; i < 2; i++) { //reverses result vector so that when displaying results, largest value is displayed first
			Quake temp = result[i];
			result[i] = result[4 - i];
			result[4 - i] = temp;
		}
		return result;
	}

	//Helper function for kth smallest/largest
	void updateMetricValues(std::vector<Quake>& quakes, int& metric, Heap& heap, int& index, float& currentValue, float& heapTopValue) {
		if (metric == 1) {
			currentValue = quakes[index].GetRelevance();
			heapTopValue = heap.top().GetRelevance();
		}
		else if (metric == 2) {
			currentValue = quakes[index].GetMag();
			heapTopValue = heap.top().GetMag();
		}
		else if (metric == 3) {
			currentValue = quakes[index].GetDistance();
			heapTopValue = heap.top().GetDistance();
		}
	}

	void mergesort(int left, int right, int metric)
	{
		if (left < right)
		{
			int middle = left + (right - left) / 2;
			mergesort(left, middle, metric);
			mergesort(middle + 1, right, metric);
			merge(left, middle, right, metric);
		}

	}
	void merge(int left, int middle, int right, int metric)
	{
		vector<Quake> vectL(middle - left + 1);
		vector<Quake> vectR(right - middle);

		for (int i = 0; i < vectL.size(); i++)
			vectL[i] = quakes[left + i];
		for (int i = 0; i < vectR.size(); i++)
			vectR[i] = quakes[middle + 1 + i];

		int i = 0;
		int j = 0;
		int q = left;
		while (i < vectL.size() && j < vectR.size())
		{
			if (metric == 1) 
			{
				if (vectL[i].GetRelevance() <= vectR[j].GetRelevance())
				{
					quakes[q] = vectL[i];
					i++;
				}
				else
				{
					quakes[q] = vectR[j];
					j++;
				}
			}
			else if (metric == 2) 
			{
				if (vectL[i].GetMag() <= vectR[j].GetMag())
				{
					quakes[q] = vectL[i];
					i++;
				}
				else
				{
					quakes[q] = vectR[j];
					j++;
				}
			}
			else if (metric == 3)
			{
				if (vectL[i].GetDistance() <= vectR[j].GetDistance())
				{
					quakes[q] = vectL[i];
					i++;
				}
				else
				{
					quakes[q] = vectR[j];
					j++;
				}
			}
			q++;
		}

		// If i vector hits the end and j isn't at the end copy rest of j vector 
		if (i == vectL.size())
		{
			while (j < vectR.size())
			{
				quakes[q] = vectR[j];
				q++;
				j++;
			}
		}

		// If j vector hits the end and i isn't at the end copy rest of i vector
		if (j == vectR.size())
		{
			while (i < vectL.size())
			{
				quakes[q] = vectL[i];
				q++;
				i++;
			}
		}
	}
};
