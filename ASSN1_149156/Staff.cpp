#include "Staff.h"
#include "FitnessInfo.h"
#include "PersonalInfo.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void Staff::setData2(string name, string gender, string staffID, string staffid, double weight, double height)
{
	setData1(name, gender, staffID, staffid, weight, height);
}

void Staff::getDOBage1()
{	//NOTE:DOB,age,bmi,bmr,rmr ARE CALCULATED USING STAFFID FROM SECOND FILE.
	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, dat = 0;
	long long int staf = calcDOBage();   //assign string staffid from second file to integer variable
	year = staf / 10000000000;			//take out first two digits of staffid to know staff year
	if (year >= 0 && year <= 20)		//get staff birth year
	{
		year += 2000;
	}
	else if (year >= 30 && year <= 99)
	{
		year += 1900;
	}
	dat = staf / 1000000;			//to seperate the staffid digits to know staff month and date
	for (int i = 0; i < 6; i++)
	{
		int digit = dat % 10;
		dat /= 10;
		if (i == 0) {			//get staff birth date
			d1 = digit;
		}
		if (i == 1) {
			d2 = digit * 10;
		}
		if (i == 2) {		//get staff birth month
			m1 = digit;
		}
		if (i == 3) {
			m2 = digit * 10;
		}
	}
	month = m1 + m2;
	date = d1 + d2;
	age = 2020 - year; //calculate age of the staff
}

void calcBBR(Staff& A, Staff& G) //A is for second file staffid,G for first file staffid
{
	//NOTE:DOB,age,bmi,bmr,rmr ARE CALCULATED USING STAFFID FROM SECOND FILE.
	A.bmi = round(A.getWeight() / ((A.getHeight() / 100) * (A.getHeight() / 100)) * 100) / 100;  //calculate bmi
	if (G.getgender() == "Male" || G.getgender() == "male")					//calculate bmi and rmr for male
	{
		A.bmr = 10 * A.getWeight() + 6.25 * A.getHeight() - 5 * A.age + 5;
		A.rmr = 88.362 + (13.397 * A.getWeight()) + (4.799 * A.getHeight()) - (5.677 * A.age);
	}
	else if (G.getgender() == "Female" || G.getgender() == "female")		//calculate bmi and rmr for female
	{
		A.bmr = 10 * A.getWeight() + 6.25 * A.getHeight() - 5 * A.age - 161;
		A.rmr = 447.593 + (9.247 * A.getWeight()) + (3.098 * A.getHeight()) - (4.330 * A.age);
	}
}

void Staff::display1()
{
	cout << "Height: " << getHeight() << endl;
	cout << "Weight: " << getWeight() << endl;
	cout << "Date of Birth: " << date << "/" << month << "/" << year << endl;
	cout << "Age: " << age << endl;
	cout << "BMI: " << bmi << endl;
	cout << "BMR: " << bmr << endl;
	cout << "RMR: " << rmr << endl;
}

void editData(Staff& E, Staff& D)  //E for first file staffid,D for second file staffid.
{
	string name, staffid, staffID, gender;
	double height, weight;
	int edit;

	cout << "Enter criteria u want to edit.\n1.Name\n2.StaffID\n3.Gender\n4.Height\n5.Weight" << endl; cin >> edit;
	while (edit < 1 || edit>5)
	{
		cout << "Incorrect number.Enter criteria u want to edit.\n1.Name\n2.StaffID\n3.Gender\n4.Height\n5.Weight" << endl; cin >> edit;
	}system("CLS");
	if (edit == 1)	//for name
	{
		cout << "Enter your name: " << endl; cin.ignore(); getline(cin, name);
		E.SetName(name);
	}
	else if (edit == 2)	//for staffID
	{
		cout << "Enter your staffID: " << endl; cin >> staffid;
		E.SetStaffID(staffid); D.SetStaffid(staffid);
	}
	else if (edit == 3)	//for gender
	{
		cout << "Enter your gender(Male/Female): " << endl; cin >> gender;
		while (gender != "Male" && gender != "male" && gender != "Female" && gender != "female")
		{
			cout << "Incorrect gender.Enter your gender(Male/Female): " << endl; cin >> gender;
		}
		E.SetGender(gender);
	}
	else if (edit == 4)	//for height
	{
		cout << "Enter your height: " << endl; cin >> height;
		while (height < 50 || height > 270)
		{
			cout << "Irrelevent height.Enter your height: " << endl; cin >> height;
		}
		D.SetHeight(height);
	}
	else if (edit == 5)	//for weight
	{
		cout << "Enter your weight: " << endl; cin >> weight;
		while (weight <= 20)
		{
			cout << "Irrelevent weight.Enter your weight: " << endl; cin >> weight;
		}
		D.SetWeight(weight); 
	}
}

void statiS(Staff S[], int z)
{
	int cat, a = 0, b = 0, p = 0;
	string g, g1;

	cout << "Choose weight category\n1.Underweight\n2.Normal weight\n3.Overweight\n4.Obese" << endl; cin >> cat;  //choose category
	while (cat < 1 || cat >4)
	{
		cout << "Incorrect choosing.Choose again: " << endl;
		cout << "Choose weight category\n1.Underweight\n2.Normal weight\n3.Overweight\n4.Obese" << endl; cin >> cat;
	}
	cout << "Choose gender(Male/Female): " << endl; cin >> g;  //choose gender
	if (g == "male") { g1 = "Male"; }				//As the data for example in file can be Male or male.
	else if (g == "female") { g1 = "Female"; }		//So,when matching the input gender with the data this
	else if (g == "Male") { g1 = "male"; }			// statements are required.
	else if (g == "Female") { g1 = "female"; }

	while (g != "")		//validate gender
	{
		if (g == "male" || g == "Male" || g == "female" || g == "Female") { break; }
		else if (g != "male" && g != "female" && g != "Male" && g != "Female")
		{
			cout << "Incorrect gender.Choose gender(Male/Female): " << endl; cin >> g;
		}
	}
	cout << "Enter range of age: " << endl; cin >> a >> b;     //choose age range
	while (a < 17 || a > 70 || b < 17 || b > 70)
	{
		cout << "Incorect range.Enter range of age: " << endl; cin >> a >> b;
	}

	if (cat == 1)    //for Underweight
	{
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (S[i].getic() == S[j].getic1())
				{
					S[j].getDOBage1();
					calcBBR(S[j], S[i]);
					if ((S[i].getgender() == g || S[i].getgender() == g1) && S[j].getAge() > a&& S[j].getAge() < b)
					{
						if (S[j].bmi < 20)
						{
							p += 1;
						}
					}
				}
			}
		}cout << "Number of people BMI <20: " << p << endl;
	}
	else if (cat == 2)    //for Normal weight
	{
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (S[i].getic() == S[j].getic1())
				{
					S[j].getDOBage1();
					calcBBR(S[j], S[i]);
					if ((S[i].getgender() == g || S[i].getgender() == g1) && S[j].getAge() > a&& S[j].getAge() < b)
					{
						if (S[j].bmi >= 20 && S[j].bmi < 25)
						{
							p += 1;
						}
					}
				}
			}
		}cout << "Number of people 20<= BMI <25: " << p << endl;
	}
	else if (cat == 3)    //for Overweight
	{
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (S[i].getic() == S[j].getic1())
				{
					S[j].getDOBage1();
					calcBBR(S[j], S[i]);
					if ((S[i].getgender() == g || S[i].getgender() == g1) && S[j].getAge() > a&& S[j].getAge() < b)
					{
						if (S[j].bmi >= 25 && S[j].bmi < 30)
						{
							p += 1;
						}
					}
				}
			}
		}cout << "Number of people 25<= BMI <30: " << p << endl;
	}
	else if (cat == 4)    //for Obese
	{
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (S[i].getic() == S[j].getic1())
				{
					S[j].getDOBage1();
					calcBBR(S[j], S[i]);
					if ((S[i].getgender() == g || S[i].getgender() == g1) && S[j].getAge() > a&& S[j].getAge() < b)
					{
						if (S[j].bmi >= 30)
						{
							p += 1;
						}
					}
				}
			}
		}cout << "Number of people BMI >=30: " << p << endl;
	}system("PAUSE");
}

Staff::Staff()
{
	date = 0; month = 0; year = 0; age = 0;
	bmi = 0; bmr = 0; rmr = 0;
}

Staff::~Staff()
{
	date = 0; month = 0; year = 0; age = 0;
	bmi = 0; bmr = 0; rmr = 0;
}
