#ifndef ASSN1_PERSONALINFO_H
#define ASSN1_PERSONALINFO_H
#include <string>

using namespace std;

class PersonalInfo{                             //Class Composition
	private:
		string Name, Gender, StaffID, Staffid;		//declaration of name,gender,staffID.StaffID got two because two files got staffid
	public:
		string getName() { return Name; }
		string getGender() { return Gender; }
		string getStaffID() { return StaffID; }
		string getStaffid() { return Staffid; }
		void setname(string name) { Name = name; }
		void setgender(string gender) { Gender = gender; }
		void setstaffID(string staffid) { StaffID = staffid; }
		void setstaffid(string staffid) { Staffid = staffid; }
		void setData(string, string, string, string);	//set name,gender and staffid
		PersonalInfo();		//class constructor
		~PersonalInfo();	//class destructor
};
#endif