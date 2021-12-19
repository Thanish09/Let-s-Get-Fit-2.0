#ifndef ASSN1_FITNESSINFO_H
#define ASSN1_FITNESSINFO_H
#include "PersonalInfo.h"
#include <string>

using namespace std;

class FitnessInfo{                   //Class Inheritance
	private:
		double Weight, Height;			//declaration of weight and height
		PersonalInfo BB;				//declaration of composition class
	public:
		double getHeight() { return Height; }
		double getWeight() { return Weight; }
		string getgender() { return BB.getGender(); }
		string getname() { return BB.getName(); }
		string getstaffID() { return BB.getStaffID(); }
		string getstaffid() { return BB.getStaffid(); }
		void setHeight(double height) { Height = height; }
		void setWeight(double weight) { Weight = weight; }
		void setName(string name) { BB.setname(name); }
		void setGender(string gender) { BB.setgender(gender); }
		void setStaffID(string staffid) { BB.setstaffID(staffid); }
		void setStaffid(string staffid) { BB.setstaffid(staffid); }
		void setData1(string, string, string, string, double, double);	//set data of height,weight and setdata function
		void disp();													//display name,staffid and gender
		long long int calcDOBage() { return std::stoll(BB.getStaffid()); }	//to change the data type of staffid of second file from string to integer
		FitnessInfo();		//class constructor
		~FitnessInfo();		//class destructor
};
#endif

