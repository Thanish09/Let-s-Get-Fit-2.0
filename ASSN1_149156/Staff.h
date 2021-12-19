#ifndef ASSN1_STAFF_H
#define ASSN1_STAFF_H
#include "FitnessInfo.h"
#include "PersonalInfo.h"
#include <string>
#include <iostream>

using namespace std;

class Staff:public FitnessInfo		//derived class
{
	private:
		int date, month, year, age;		//declare date,month,year,age,bmi,bmr,rmr
		double bmi, bmr, rmr;
	public:
		double getBMI() { return bmi; }
		double getBMR() { return bmr; }
		double getRMR() { return rmr; }
		int getAge() { return age; }
		void SetHeight(double height) { setHeight(height); }
		void SetWeight(double weight) { setWeight(weight); }
		void SetName(string name) { setName(name); }
		void SetGender(string gender) { setGender(gender); }
		void SetStaffID(string staffid) { setStaffID(staffid); }
		void SetStaffid(string staffid) { setStaffid(staffid); }
		string getic() { return getstaffID(); }
		string getic1() { return getstaffid(); }
		void setData2(string, string, string, string, double, double); //set data for setdata1 function
		void getDOBage1();												//calculate DOB and age
		friend void calcBBR(Staff&, Staff&);								//to calculate bmi,bmr,rmr
		friend void editData(Staff&, Staff&);							//to edit data of staff
		friend void statiS(Staff[], int);								//for statistical search
		void display() { disp(); }
		void display1();												//display height,weight,DOB,age,bmi,bmr,rmr
		void coutBMI() { cout << "BMI: " << bmi << endl; }				//all this cout functions used for combinational
		void coutBMR() { cout << "BMR: " << bmr << endl; }				//search to display the age,bmi,bmr and rmr
		void coutRMR() { cout << "RMR: " << rmr << endl; }				//seperately according to its category
		void coutAge() { cout << "Age: " << age << endl; }
		Staff();														//class constructor
		~Staff();														//class destructor
};
#endif