#include "PersonalInfo.h"
#include <iostream>
#include <string>

using namespace std;

void PersonalInfo::setData(string name, string gender, string staffID, string staffid)
{
	Name = name; Gender = gender;
	StaffID = staffID; Staffid = staffid;
}

PersonalInfo::PersonalInfo()
{
	Name = ""; Gender = ""; StaffID = "", Staffid = "";
}

PersonalInfo::~PersonalInfo()
{
	Name = ""; Gender = ""; StaffID = "", Staffid = "";
}
