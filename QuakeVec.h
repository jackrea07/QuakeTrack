#pragma once
#include "Quake.h"
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
				float relevance = distRel * mag;

				Quake quake(depth, mag, distance, relevance, date, longitude, latitude);
				quakes.push_back(quake);
			}
		}
	}
	std::vector<Quake> ReturnTop5(){
		std::vector<Quake> solution;
		for (int i = 0; i < 4; i++) {
			solution.push_back(quakes[i]);
		}
		return solution;
	}
};
