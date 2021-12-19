#include "FitnessInfo.h"
#include <iostream>
#include <string>

using namespace std;

void FitnessInfo::setData1(string name, string gender, string staffID, string staffid, double weight, double height)
{
	Weight = weight; Height = height;
	BB.setData(name, gender, staffID, staffid);
}

void FitnessInfo::disp()
{
	cout << "Name: " << BB.getName() << endl;
	cout << "StaffID: " << BB.getStaffID() << endl;
	cout << "Gender: " << BB.getGender() << endl;
}

FitnessInfo::FitnessInfo()
{
	Height = 0; Weight = 0;
}

FitnessInfo::~FitnessInfo()
{
	Height = 0; Weight = 0;
}
