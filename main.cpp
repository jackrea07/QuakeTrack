#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<cmath>
#include<complex>

using namespace std;

class Quake {
	float depth;
	float mag;
	string date;
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
	void EditDate(string date) {
		this->date = date;
	}
	void EditTime(float relevance) {
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
	string GetDate() {
		return date;
	}
	float GetRelevance() {
		return relevance;
	}
	Quake() {
		depth = 0;
		mag = 0;
		date = "";
		distance = 0;
		relevance = 0;
	}
	Quake(float depth, float mag, float dist, float relevance, string date, float longitude, float latitude) {
		this->depth = depth;
		this->mag = mag;
		this->date = date;
		this->distance = dist;
		this->relevance = relevance;
	}
	void UpdateDistRel(float userLat, float userLong) {
		this->distance = float(sqrt(pow(double(double(userLong) - double(longitude)), 2) + pow(double(double(userLat) - double(latitude)), 2))) * 69;
		int distRel;
		if (distance < 25)
			distRel = 10;
		else if (distance > 25 && distance < 50)
			distRel = 9;
		else if (distance > 50 && distance < 100)
			distRel = 8;
		else if (distance > 100 && distance < 200)
			distRel = 7;
		else if (distance > 200 && distance < 500)
			distRel = 6;
		else if (distance > 500 && distance < 1000)
			distRel = 5;
		else if (distance > 1000 && distance < 2000)
			distRel = 4;
		else if (distance > 2000 && distance < 5000)
			distRel = 3;
		else if (distance > 5000 && distance < 10000)
			distRel = 2;
		else
			distRel = 1;
		this->relevance = distRel * mag;
	}
};

float Relevance(float dist, float magnitude) {
	int distRel;
	if (dist < 25)
		distRel = 10;
	else if (dist > 25 && dist < 50)
		distRel = 9;
	else if (dist > 50 && dist < 100)
		distRel = 8;
	else if (dist > 100 && dist < 200)
		distRel = 7;
	else if (dist > 200 && dist < 500)
		distRel = 6;
	else if (dist > 500 && dist < 1000)
		distRel = 5;
	else if (dist > 1000 && dist < 2000)
		distRel = 4;
	else if (dist > 2000 && dist < 5000)
		distRel = 3;
	else if (dist > 5000 && dist < 10000)
		distRel = 2;
	else
		distRel = 1;
	float relevance = distRel * magnitude;
	return relevance;
}

void ReadFile(string fileName, vector<Quake>& quakes, float userLong, float userLat) {
	ifstream inFile(fileName);
	if (inFile.is_open()) {

		string fileLine;
		getline(inFile, fileLine);

		while (getline(inFile, fileLine)) {

			istringstream stream(fileLine);

			string date;
			float mag;
			float depth;
			float longitude;
			float latitude;

			string tempMag;
			string tempDepth;
			string tempLong;
			string tempLat;

			getline(stream, tempDepth, ',');
			depth = stof(tempDepth);

			getline(stream, tempMag, ',');
			mag = stof(tempMag);

			getline(stream, tempLat, ',');
			latitude = stof(tempLat);

			getline(stream, tempLong, ',');
			longitude = stof(tempLong);

			getline(stream, date);

			float distance = float(sqrt(pow(double(double(userLong) - double(longitude)), 2) + pow(double(double(userLat) - double(latitude)), 2))) * 69; //convert to miles from user location
			float relevance = Relevance(distance, mag);

			Quake quake(depth, mag, distance, relevance, date, longitude, latitude);
			quakes.push_back(quake);
		}
	}
}

int main() {
	vector<Quake> quakes;
	float userLong;
	float userLat;
	cin >> userLong;
	cin >> userLat;
	ReadFile("quakes.csv", quakes, userLong, userLat);
}
