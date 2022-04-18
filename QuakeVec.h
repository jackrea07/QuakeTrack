#pragma once
#include "Quake.h"
#include "Heap.h"
class QuakeVec
{
public:
	std::vector<Quake> quakes;

	QuakeVec(float userLat, float userLong) {
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

				getline(stream, tempMag, ',');
				mag = stof(tempMag);

				getline(stream, tempLat, ',');
				latitude = stof(tempLat);

				getline(stream, tempLong, ',');
				longitude = stof(tempLong);

				getline(stream, date);

				float distance = float(sqrt(pow(double(double(userLong) - double(longitude)), 2) + pow(double(double(userLat) - double(latitude)), 2))) * 69; //convert to miles from user location
				int distRel;
				if (distance < 50)
					distRel = 10;
				else if (distance > 50 && distance < 100)
					distRel = 9;
				else if (distance > 100 && distance < 200)
					distRel = 8;
				else if (distance > 200 && distance < 500)
					distRel = 7;
				else if (distance > 500 && distance < 1000)
					distRel = 6;
				else if (distance > 1000 && distance < 1500)
					distRel = 5;
				else if (distance > 1500 && distance < 2000)
					distRel = 4;
				else if (distance > 2000 && distance < 5000)
					distRel = 3;
				else if (distance > 5000 && distance < 10000)
					distRel = 2;
				else
					distRel = 1;
				float relevance = distRel * mag;

				Quake quake(depth, mag, distance, relevance, date, longitude, latitude);
				quakes.push_back(quake);
			}
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

	//TODO: add support for kth largest for magnitude and relevance
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
};
