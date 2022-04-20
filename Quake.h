#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<cmath>
#include<complex>

class Quake {
	float depth;
	float mag;
	std::string date;
	float distance;
	float relevance;
	float longitude;
	float latitude;

public:
	void EditDistance(float dist) {
		distance = dist;
	}
	void EditDepth(float depth) {
		this->depth = depth;
	}
	void EditMag(float mag) {
		this->mag = mag;
	}
	void EditDate(std::string date) {
		this->date = date;
	}
	void EditRelevance(float relevance) {
		this->relevance = relevance;
	}
	float GetDistance() {
		return distance;
	}
	float GetDepth() {
		return depth;
	}
	float GetMag() {
		return mag;
	}
	std::string GetDate() {
		return date;
	}
	float GetRelevance() {
		return relevance;
	}
	float GetLatitude() {
		return latitude;
	}
	float GetLongitude() {
		return longitude;
	}
	Quake() {
		depth = 0;
		mag = 0;
		date = "";
		distance = 0;
		relevance = 0;
	}
	Quake(float depth, float mag, float dist, float relevance, std::string date, float longitude, float latitude) {
		this->depth = depth;
		this->mag = mag;
		this->date = date;
		this->distance = dist;
		this->relevance = relevance;
		this->longitude = longitude;
		this->latitude = latitude;
	}
	void UpdateDistRel(float &userLat, float &userLong) {
		this->distance = (float)sqrt(pow((double)((double)userLong - (double)longitude), 2) + pow(double((double)userLat - (double)latitude), 2)) * 69;
		double distRel;
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

		double depthRel;
		if (depth <= 50)
			depthRel = 1.0;
		else if (depth > 50 && depth <= 100)
			depthRel = 0.9;
		else if (depth > 100 && depth <= 150)
			depthRel = 0.8;
		else if (depth > 150 && depth <= 200)
			depthRel = 0.7;
		else if (depth > 200 && depth <= 250)
			depthRel = 0.6;
		else if (depth > 250 && depth <= 300)
			depthRel = 0.5;
		else if (depth > 300 && depth <= 350)
			depthRel = 0.4;
		else if (depth > 350 && depth <= 400)
			depthRel = 0.3;
		else if (depth > 400)
			depthRel = 0.2;
		else
			depthRel = 0.1;
		this->relevance = sqrt(pow(distRel, 2) + pow(depthRel, 2)) * mag;
	}
};
