/*
	Name: Thanish A/L Natarajan
	Matric No: 149156
	Class: D2
	Lecturer Name: Dr.Nur Hana Samsudin

	This program is about healthy lifestyle of Usm staff. This program is designed to get
	Usm staff's information such as name,staffID,gender,height and weight and will
	calculate their BMI,BMR,RMR,Date of Birth and Age.Besides that, this program also doing some searches
	like simple searches using staffID,combinational search,statistical search and also got target 
	calculator where Usm staff will get to know their limit for achieve their ideal weight.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Staff.h"
#include "FitnessInfo.h"
#include "PersonalInfo.h"

using namespace std;

void combiS1(int, Staff[], int);

void targetCalc(Staff[], int);

int main()
{
	const int size = 210;
	fstream Usm, Usm1;
	ofstream UsmFile;
	Staff obj[size];
	int z = 0, num1, num2, num3, start;
	string file, file1, name, gender, staffID, staffid, exStaff;
	double weight = 0, height = 0;
	char yesno;
	bool ID = true;

	int menu();      //declaration of main menu
	int staff();	//declaration of staff
	int features();	//declaration of search menu
	int combiS();	//declaration of combinational search

	cout << "\t\t\t\t*************" << endl;             //Display Titile
	cout << "\t\t\t\tLet's Get Fit" << endl;
	cout << "\t\t\t\t*************" << endl;
	cout << "Welcome to Let's Get Fit App." << endl;
	cout << "Please enter the files name: " << endl;
	cin >> file; cin.ignore();
	cin >> file1;

	while (file != "" && file1 != "")
	{
		file += ".txt"; file1 += ".txt";	//adding .txt automatically
		Usm.open(file, ios::in); Usm1.open(file1, ios::in);		//read the files

		if (Usm && Usm1)
		{
			cout << "Files have been retrieved.\nLet's continue.." << endl; break;
		}
		else if (!Usm || !Usm1)
		{
			Usm.close(); Usm1.close();
			cout << "Files you have entered could not be found,Please enter correct file name." << endl;
			cin >> file; cin.ignore();
			cin >> file1;
		}
	}
	for (int i = 0; i < size && !Usm.eof() && !Usm1.eof(); i++)
	{
		Usm >> staffID; Usm.ignore();		//stores data from files in varialbles
		getline(Usm, name, '\t');
		Usm >> gender;
		Usm.ignore();
		Usm1 >> staffid;
		Usm1 >> weight;
		Usm1 >> height;
		Usm1.ignore();
		obj[i].setData2(name, gender, staffID, staffid, weight, height);	//stores all the data from files into object array
		z = z + 1;		//to know how many data is in the files
	}
	Usm.close(); Usm1.close();

	while (start = menu())
	{
		switch (start)
		{
		case 1:
			system("CLS");
			num1 = staff(); system("CLS");
			if (num1 == 1)	//to know the data in the files
			{
				while (ID)  //validate the StaffID search
				{
					cout << "Enter your StaffID: " << endl; cin >> exStaff;	//identify specific data in the files
					for (int i = 0; i < z; i++)
					{
						if (exStaff == obj[i].getic())
						{
							for (int j = 0; j < z; j++)
							{
								if (exStaff == obj[j].getic1())	//display all information of that specific data
								{
									obj[i].display();			//display first file data
									obj[j].getDOBage1();		//calculate date of birth and age
									calcBBR(obj[j], obj[i]);	//calculate BMI,BMR and RMR
									obj[j].display1();			//display second file data

									cout << "Do you want to update data? (Y/N)" << endl; cin >> yesno;	//Ask for update any data
									while (yesno)
									{
										if (yesno == 'Y' || yesno == 'y')
										{
											editData(obj[i], obj[j]);	//for edit the data
											obj[i].display();  
											obj[j].getDOBage1(); 
											calcBBR(obj[j], obj[i]);
											obj[j].display1();
											cout << "Do you want to update data again? (Y/N)" << endl; cin >> yesno;
										}
										else if (yesno == 'N' || yesno == 'n' || yesno != 'Y' || yesno != 'y')
										{
											system("CLS"); break;
										}
									}break;
								}
							}ID = true; break;
						}
						else if (exStaff != obj[i].getic())		//if data cannot found in the file
						{
							ID = false;
						}
					}
					while (!ID)
					{
						cout << "Your Staff Id not the the data.\nPls go to new staff and add ur information.\n";
						ID = true; break;
					}break;
				}
			}
			else if (num1 == 2)		//for new Staff to add data
			{
				cout << "Welcome new staff :)\nEnter your name: " << endl; cin.ignore(); getline(cin, name);
				cout << "Enter your StaffID: " << endl; cin >> staffID; staffid = staffID;
				cout << "Enter your Gender (Male/Female): " << endl; cin >> gender;
				while (gender != "Male" && gender != "Female")
				{
					cout << "Make sure your follow as in the brackett.Please enter again\n";
					cout << "Enter your Gender (Male/Female): " << endl; cin >> gender;
				}
				cout << "Enter your Height: " << endl; cin >> height;
				while (height <= 50 || height >= 270)
				{
					cout << "Height not relevent.Please enter again: " << endl; cin >> height;
				}
				cout << "Enter your Weight: " << endl; cin >> weight;
				while (weight <= 20)
				{
					cout << "Weight not relevent.Please enter again: " << endl; cin >> weight;
				}//system("CLS");
				obj[z].setData2(name, gender, staffID, staffid, weight, height);	//display data that entered
				obj[z].display();													//togeteher with DOB and age
				obj[z].getDOBage1(); calcBBR(obj[z], obj[z]);						//and BMI,BMR,RMR
				obj[z].display1();

				cout << "Do you want to edit data? (Y/N)" << endl; cin >> yesno;	//perform editing
				while (yesno)
				{
					if (yesno == 'Y' || yesno == 'y')
					{
						editData(obj[z], obj[z]);
						obj[z].display(); 
						obj[z].getDOBage1(); 
						calcBBR(obj[z], obj[z]);
						obj[z].display1();
						cout << "Do you want to edit data again? (Y/N)" << endl; cin >> yesno;
					}
					else if (yesno == 'N' || yesno == 'n' || yesno != 'Y' || yesno != 'y')
					{
						system("CLS"); break;
					}
				}z += 1;		//increase the object array index every time adding new staff
			}
			else if (num1 == 3)
				cout << "Thank you.You will be return to main menu in a while." << endl; break;
		case 2:		//for search
			system("CLS");
			num2 = features(); system("CLS");
			if (num2 == 1)		//combinational search
			{
				num3 = combiS();
				combiS1(num3, obj, z);
			}
			else if (num2 == 2)	//statistical search
			{
				statiS(obj, z);
			}
			else if (num2 == 3)	//target calculator
			{
				targetCalc(obj, z);
			}
			else if (num2 == 4)	//exit to menu
			{
				cout << "Thank you.You will be directed to main menu now." << endl;
			}break;
		case 3:		//for save all the data in output file
			cout << "Your information has been stored in the output file.\nThank you for using this app ;)" << endl;

			UsmFile.open("Let_Get_Fit.txt");	//create output file

			UsmFile << left << setw(40) << "Name" << "\t" << left << setw(12) << "StaffID" << "\t" << left << setw(6) << "Gender" << "\t";
			UsmFile << internal << setw(3) << "Age" << "\t" << internal << setw(7) << "Height" << "\t" << internal << setw(7) << "Weight" << "\t";
			UsmFile << right << setw(9) << "BMI" << "\t" << right << setw(9) << "BMR" << "\t" << right << setw(9) << "RMR" << "\t" << endl;

			for (int i = 0; i < z; i++)
			{
				for (int j = 0; j < z; j++)
				{
					if (obj[i].getic() == obj[j].getic1())
					{
						obj[j].getDOBage1();
						calcBBR(obj[j], obj[i]);
						UsmFile << left << setw(40) << obj[i].getname() << "\t";	//store all the data from object arrays
						UsmFile << left << setw(12) << obj[j].getic1() << "\t";
						UsmFile << left << setw(6) << obj[i].getgender() << "\t";
						UsmFile << internal << setw(3) << obj[j].getAge() << "\t";
						UsmFile << internal << setw(7) << obj[j].getHeight() << "\t";
						UsmFile << internal << setw(7) << obj[j].getWeight() << "\t"; 
						UsmFile << right << setw(9) << obj[j].getBMI() << "\t";
						UsmFile << right << setw(9) << obj[j].getBMR() << "\t";
						UsmFile << right << setw(9) << obj[j].getRMR() << "\n";
					}
				}
			}UsmFile.close();
			break;
		}
		if (start == 3) { break; }	//to exit the program after case 3.
	}
	return 0;
}

int menu()
{
	int num;

	cout << "Choose the number of your choice.\n1.Staff\n2.Features\n3.Save & Exit" << endl;
	cin >> num;
	while (num < 1 || num > 3)
	{
		cout << "Incorrect choosing.Choose again.\n1.Staff\n2.Features\n3.Save & Exit" << endl;
		cin >> num;
	}
	return num;
}

int staff()
{
	int num1;
	cout << "Choose your choice.\n1.Existing Staff\n2.New Staff\n3.Exit" << endl; cin >> num1;
	while (num1 < 1 || num1>3)
	{
		cout << "Incorrect choosing.Choose your choice.\n1.Existing Staff\n2.New Staff\n3.Exit" << endl; cin >> num1;
	}
	return num1;
}

int features()
{
	int search;
	cout << "Enter features you want to see.\n1.Combinational search\n2.Statistical search\n3.MyTarget\n4.Exit" << endl; cin >> search;
	while (search < 1 || search >4)
	{
		cout << "Irrelevent choosing.Please choose again.";
		cout << "Enter features you want to see.\n1.Combinational search\n2.Statistical search\n3.MyTarget\n4.Exit" << endl; cin >> search;
	}
	return search;
}

int combiS()
{
	int com, com1, cho;
	cout << "Enter number of two information you want to search:\n1.Age\n2.BMI\n3.BMR\n4.RMR\n"; cin >> com >> com1;
	while (com < 1 || com > 4 || com1 < 1 || com1 > 4)
	{
		cout << "Incorrect choosing.Enter number of two information you want to search:\n1.Age\n2.BMI\n3.BMR\n4.RMR\n"; cin >> com >> com1;
	}
	if ((com == 1 && com1 == 2) || (com == 2 && com1 == 1)) { return cho = 1; }
	else if ((com == 1 && com1 == 3) || (com == 3 && com1 == 1)) { return cho = 2; }
	else if ((com == 1 && com1 == 4) || (com == 4 && com1 == 1)) { return cho = 3; }
	else if ((com == 2 && com1 == 3) || (com == 3 && com1 == 2)) { return cho = 4; }
	else if ((com == 2 && com1 == 4) || (com == 4 && com1 == 2)) { return cho = 5; }
	else if ((com == 3 && com1 == 4) || (com == 4 && com1 == 3)) { return cho = 6; }
	system("CLS");
}

void combiS1(int n, Staff obj[], int z)
{
	int a, a1 = 0, a2 = 1000, a3 = 0, a4 = 0, b, c, d;
	double b1 = 0, b2 = 100000, b3 = 0, b4 = 0, c1 = 0, c2 = 100000, c3 = 0, c4 = 0, d1 = 0, d2 = 100000, d3 = 0, d4 = 0;
	if (n == 1) //compare Age with BMI
	{
		cout << "1.Age less than\n2.Age more than\n3.Age range" << endl; cin >> a;
		while (a < 1 || a>3)
		{
			cout << "Invalid choosing.Choose again:\n1.Age less than\n2.Age more than\n3.Age range" << endl; cin >> a;
		}
		if (a == 1) //age less than
		{
			cout << "Enter the value: " << endl; cin >> a1;
			while (a1 < 17 || a1 > 70)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a1;
			}
		}
		else if (a == 2)  //age more than
		{
			cout << "Enter the value: " << endl; cin >> a2;
			while (a2 < 17 || a2 > 70)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a2;
			}
		}
		else if (a == 3)  //age range
		{
			cout << "Enter the values: " << endl; cin >> a3 >> a4;
			while ((a3 < 17 || a3 > 70) && (a4 < 17 || a4 > 70))
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a3 >> a4;
			}
		}
		cout << "1.BMI less than\n2.BMI more than\n3.BMI range" << endl; cin >> b;
		while (b < 1 || b>3)
		{
			cout << "Invalid choosing.Choose again:\n1.BMI less than\n2.BMI more than\n3.BMI range" << endl; cin >> b;
		}
		if (b == 1)  //bmi less than
		{
			cout << "Enter the value: " << endl; cin >> b1;
			while (b1 < 8 || b1 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b1;
			}
		}
		else if (b == 2)  //bmi more than
		{
			cout << "Enter the value: " << endl; cin >> b2;
			while (b2 < 8 || b2 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b2;
			}
		}
		else if (b == 3)  //bmi range
		{
			cout << "Enter the values: " << endl; cin >> b3 >> b4;
			while (b3 < 8 || b3 > 100 || b4 < 8 || b4 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b3 >> b4;
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (obj[i].getic() == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					if (obj[j].getAge() < a1 && obj[j].getBMI() < b1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() < a1 && obj[j].getBMI() > b2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() < a1 && obj[j].getBMI() > b3&& obj[j].getBMI() < b4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getBMI() < b1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getBMI() > b2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getBMI() > b3&& obj[j].getBMI() < b4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getBMI() < b1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getBMI() > b2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getBMI() > b3&& obj[j].getBMI() < b4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMI(); cout << "\n";
					}
				}
			}
		}
	}
	else if (n == 2)	//compare Age with BMR
	{
		cout << "1.Age less than\n2.Age more than\n3.Age range" << endl; cin >> a;
		while (a < 1 || a>3)
		{
			cout << "Invalid choosing.Choose again:\n1.Age less than\n2.Age more than\n3.Age range" << endl; cin >> a;
		}
		if (a == 1) //age less than
		{
			cout << "Enter the value: " << endl; cin >> a1;
			while (a1 < 17 || a1 > 70)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a1;
			}
		}
		else if (a == 2)  //age more than
		{
			cout << "Enter the value: " << endl; cin >> a2;
			while (a2 < 17 || a2 > 70)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a2;
			}
		}
		else if (a == 3)  //age range
		{
			cout << "Enter the values: " << endl; cin >> a3 >> a4;
			while ((a3 < 17 || a3 > 70) && (a4 < 17 || a4 > 70))
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a3 >> a4;
			}
		}
		cout << "1.BMR less than\n2.BMR more than\n3.BMR range" << endl; cin >> c;
		while (c < 1 || c>3)
		{
			cout << "Invalid choosing.Choose again:\n1.BMR less than\n2.BMR more than\n3.BMR range" << endl; cin >> c;
		}
		if (c == 1)  //bmr less than
		{
			cout << "Enter the value: " << endl; cin >> c1;
			while (c1 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c1;
			}
		}
		else if (c == 2)  //bmr more than
		{
			cout << "Enter the value: " << endl; cin >> c2;
			while (c2 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c2;
			}
		}
		else if (c == 3)  //bmr range
		{
			cout << "Enter the values: " << endl; cin >> c3 >> c4;
			while (c3 < 300 || c4 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c3 >> c4;
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (obj[i].getic() == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					if (obj[j].getAge() < a1 && obj[j].getBMR() < c1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() < a1 && obj[j].getBMR() > c2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() < a1 && obj[j].getBMR() > c3&& obj[j].getBMR() < c4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getBMR() < c1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getBMR() > c2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getBMR() > c3&& obj[j].getBMR() < c4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getBMR() < c1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getBMR() > c2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getBMR() > c3&& obj[j].getBMR() < c4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutBMR(); cout << "\n";
					}
				}
			}
		}
	}
	else if (n == 3)	//compare Age with RMR
	{
		cout << "1.Age less than\n2.Age more than\n3.Age range" << endl; cin >> a;
		while (a < 1 || a>3)
		{
			cout << "Invalid choosing.Choose again:\n1.Age less than\n2.Age more than\n3.Age range" << endl; cin >> a;
		}
		if (a == 1) //age less than
		{
			cout << "Enter the value: " << endl; cin >> a1;
			while (a1 < 17 || a1 > 70)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a1;
			}
		}
		else if (a == 2)  //age more than
		{
			cout << "Enter the value: " << endl; cin >> a2;
			while (a2 < 17 || a2 > 70)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a2;
			}
		}
		else if (a == 3)  //age range
		{
			cout << "Enter the values: " << endl; cin >> a3 >> a4;
			while ((a3 < 17 || a3 > 70) && (a4 < 17 || a4 > 70))
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> a3 >> a4;
			}
		}
		cout << "1.RMR less than\n2.RMR more than\n3.RMR range" << endl; cin >> d;
		while (d < 1 || d>3)
		{
			cout << "Invalid choosing.Choose again:\n1.RMR less than\n2.RMR more than\n3.RMR range" << endl; cin >> d;
		}
		if (d == 1)  //rmr less than
		{
			cout << "Enter the value: " << endl; cin >> d1;
			while (d1 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d1;
			}
		}
		else if (d == 2)  //rmr more than
		{
			cout << "Enter the value: " << endl; cin >> d2;
			while (d2 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d2;
			}
		}
		else if (d == 3)  //rmr range
		{
			cout << "Enter the values: " << endl; cin >> d3 >> d4;
			while (d3 < 300 || d4 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d3 >> d4;
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (obj[i].getic() == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					if (obj[j].getAge() < a1 && obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() < a1 && obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() < a1 && obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a2&& obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getAge() > a3&& obj[j].getAge() < a4&& obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutAge(); obj[j].coutRMR(); cout << "\n";
					}
				}
			}
		}
	}
	else if (n == 4)	//compare BMI with BMR
	{
		cout << "1.BMI less than\n2.BMI more than\n3.BMI range" << endl; cin >> b;
		while (b < 1 || b>3)
		{
			cout << "Invalid choosing.Choose again:\n1.BMI less than\n2.BMI more than\n3.BMI range" << endl; cin >> b;
		}
		if (b == 1)  //bmi less than
		{
			cout << "Enter the value: " << endl; cin >> b1;
			while (b1 < 8 || b1 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b1;
			}
		}
		else if (b == 2)  //bmi more than
		{
			cout << "Enter the value: " << endl; cin >> b2;
			while (b2 < 8 || b2 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b2;
			}
		}
		else if (b == 3)  //bmi range
		{
			cout << "Enter the values: " << endl; cin >> b3 >> b4;
			while (b3 < 8 || b3 > 100 || b4 < 8 || b4 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b3 >> b4;
			}
		}
		cout << "1.BMR less than\n2.BMR more than\n3.BMR range" << endl; cin >> c;
		while (c < 1 || c>3)
		{
			cout << "Invalid choosing.Choose again:\n1.BMR less than\n2.BMR more than\n3.BMR range" << endl; cin >> c;
		}
		if (c == 1)  //bmr less than
		{
			cout << "Enter the value: " << endl; cin >> c1;
			while (c1 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c1;
			}
		}
		else if (c == 2)  //bmr more than
		{
			cout << "Enter the value: " << endl; cin >> c2;
			while (c2 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c2;
			}
		}
		else if (c == 3)  //bmr range
		{
			cout << "Enter the values: " << endl; cin >> c3 >> c4;
			while (c3 < 300 || c4 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c3 >> c4;
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (obj[i].getic() == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					if (obj[j].getBMI() < b1 && obj[j].getBMR() < c1)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() < b1 && obj[j].getBMR() > c2)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() < b1 && obj[j].getBMR() > c3&& obj[j].getBMR() < c4)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b2&& obj[j].getBMR() < c1)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b2&& obj[j].getBMR() > c2)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b2&& obj[j].getBMR() > c3&& obj[j].getBMR() < c4)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b3&& obj[j].getBMI() < b4&& obj[j].getBMR() < c1)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b3&& obj[j].getBMI() < b4&& obj[j].getBMR() > c2)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b3&& obj[j].getBMI() < b4&& obj[j].getBMR() > c3&& obj[j].getBMR() < c4)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutBMR(); cout << "\n";
					}
				}
			}
		}
	}
	else if (n == 5)	//compare BMI with RMR
	{
		cout << "1.BMI less than\n2.BMI more than\n3.BMI range" << endl; cin >> b;
		while (b < 1 || b>3)
		{
			cout << "Invalid choosing.Choose again:\n1.BMI less than\n2.BMI more than\n3.BMI range" << endl; cin >> b;
		}
		if (b == 1)  //bmi less than
		{
			cout << "Enter the value: " << endl; cin >> b1;
			while (b1 < 8 || b1 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b1;
			}
		}
		else if (b == 2)  //bmi more than
		{
			cout << "Enter the value: " << endl; cin >> b2;
			while (b2 < 8 || b2 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b2;
			}
		}
		else if (b == 3)  //bmi range
		{
			cout << "Enter the values: " << endl; cin >> b3 >> b4;
			while (b3 < 8 || b3 > 100 || b4 < 8 || b4 > 100)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> b3 >> b4;
			}
		}
		cout << "1.RMR less than\n2.RMR more than\n3.RMR range" << endl; cin >> d;
		while (d < 1 || d>3)
		{
			cout << "Invalid choosing.Choose again:\n1.RMR less than\n2.RMR more than\n3.RMR range" << endl; cin >> d;
		}
		if (d == 1)  //rmr less than
		{
			cout << "Enter the value: " << endl; cin >> d1;
			while (d1 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d1;
			}
		}
		else if (d == 2)  //rmr more than
		{
			cout << "Enter the value: " << endl; cin >> d2;
			while (d2 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d2;
			}
		}
		else if (d == 3)  //rmr range
		{
			cout << "Enter the values: " << endl; cin >> d3 >> d4;
			while (d3 < 300 || d4 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d3 >> d4;
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (obj[i].getic() == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					if (obj[j].getBMI() < b1 && obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() < b1 && obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() < b1 && obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b2&& obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b2&& obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b2&& obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b3&& obj[j].getBMI() < b4&& obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b3&& obj[j].getBMI() < b4&& obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMI() > b3&& obj[j].getBMI() < b4&& obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutBMI(); obj[j].coutRMR(); cout << "\n";
					}
				}
			}
		}
	}
	else if (n == 6)	//compare BMR with RMR
	{
		cout << "1.BMR less than\n2.BMR more than\n3.BMR range" << endl; cin >> c;
		while (c < 1 || c>3)
		{
			cout << "Invalid choosing.Choose again:\n1.BMR less than\n2.BMR more than\n3.BMR range" << endl; cin >> c;
		}
		if (c == 1)  //bmr less than
		{
			cout << "Enter the value: " << endl; cin >> c1;
			while (c1 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c1;
			}
		}
		else if (c == 2)  //bmr more than
		{
			cout << "Enter the value: " << endl; cin >> c2;
			while (c2 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c2;
			}
		}
		else if (c == 3)  //bmr range
		{
			cout << "Enter the values: " << endl; cin >> c3 >> c4;
			while (c3 < 300 || c4 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> c3 >> c4;
			}
		}
		cout << "1.RMR less than\n2.RMR more than\n3.RMR range" << endl; cin >> d;
		while (d < 1 || d>3)
		{
			cout << "Invalid choosing.Choose again:\n1.RMR less than\n2.RMR more than\n3.RMR range" << endl; cin >> d;
		}
		if (d == 1)  //rmr less than
		{
			cout << "Enter the value: " << endl; cin >> d1;
			while (d1 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d1;
			}
		}
		else if (d == 2)  //rmr more than
		{
			cout << "Enter the value: " << endl; cin >> d2;
			while (d2 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d2;
			}
		}
		else if (d == 3)  //rmr range
		{
			cout << "Enter the values: " << endl; cin >> d3 >> d4;
			while (d3 < 300 || d4 < 300)
			{
				cout << "Invalid value.Enter the value: " << endl; cin >> d3 >> d4;
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (obj[i].getic() == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					if (obj[j].getBMR() < c1 && obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() < c1 && obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() < c1 && obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() > c2&& obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() > c2&& obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() > c2&& obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() > c3&& obj[j].getBMR() < c4&& obj[j].getRMR() < d1)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() > c3&& obj[j].getBMR() < c4&& obj[j].getRMR() > d2)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
					else if (obj[j].getBMR() > c3&& obj[j].getBMR() < c4&& obj[j].getRMR() > d3&& obj[j].getRMR() < d4)
					{
						obj[i].display(); obj[j].coutBMR(); obj[j].coutRMR(); cout << "\n";
					}
				}
			}
		}
	}
	system("PAUSE"); system("CLS");
}

void targetCalc(Staff obj[], int z)  //Calculate the target weight
{
	string staf;
	double newbmr = 0, win = 0, remain = 0;
	int days;
	bool ID = true;

	cout << "Enter your StaffID: " << endl; cin >> staf;   //ask for specific StaffID

	for (int i = 0; i < z; i++)                            //search for specific StaffID
	{
		if (staf == obj[i].getic())
		{
			for (int j = 0; j < z; j++)
			{
				if (staf == obj[j].getic1())
				{
					obj[j].getDOBage1();
					calcBBR(obj[j], obj[i]);
					newbmr = 0.75 * obj[j].getBMR();     //calculate calories

					cout << "Enter your ideal weight: " << endl; cin >> win;        //ask for ideal weight
					while (win <= 20)
					{
						cout << "Irrelevent weight.Enter your weight: " << endl; cin >> win;
					}
					if (obj[j].getWeight() > win)    //if weight more than ideal weight
					{
						remain = obj[j].getWeight() - win;   //difference of weight
						days = remain / (0.5 / 7);
						cout << "You need to consume " << newbmr << " calories in order to lose " << remain << "kg in " << days << " days.\n";
					}
					else if (obj[j].getWeight() < win)  //if weight less than ideal weight
					{
						remain = win - obj[j].getWeight();  //difference of weight
						days = remain / (0.5 / 7);
						cout << "You need to consume " << newbmr << " calories in order to gain " << remain << "kg in " << days << " days.\n";
					}ID = true; break;
				}
			}break;
		}
		else
		{
			ID = false;
		}
	}
	if (!ID)
	{
		cout << "Incorrect staffID.You will be directed to main menu.";
	}system("PAUSE");
}