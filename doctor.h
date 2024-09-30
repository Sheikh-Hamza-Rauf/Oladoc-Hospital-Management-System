#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include"../appointment/appointment.h"
using namespace std;
class doctor
{
public:
    

	doctor();
	~doctor();
	int doctor_menu()
	{

		cout << " ********* Doctor Menu *******" << endl;
		cout << endl;
		cout << "1.LOGIN" << endl;
		cout << "2.REGISTER" << endl;
		cout << "\nEnter your choice :";
		cin >> c;
		return c;
	}
  
    bool doc_login()
    {
        //int count = 0;
        string user, pass, u, p;
        system("cls");
        cout << " ********Doctor_Login***********" << endl << endl;
        cout << "please enter the following details" << endl;
        cout << "USERNAME :";
        cin >> user;
        cout << "PASSWORD :";
        cin >> pass;
        string doctor = "";
        u = "";
        p = "";
        string spec;
        string hos;
        ifstream read("./doctor/doctor.txt");
        //loop to check all lines of file one by one
        while (!read.eof()) {
            read >> u;
            read >> p;
            read >> spec;
            read >> hos;
            
           ///* getline(read, doctor);
           // int pos = doctor.find(" ");
           // u = doctor.substr(0, pos);
           // p = doctor.substr(pos + 1, doctor.size());
            if (u == user && p == pass)
                break;
        }
        if (u == user && p == pass)

        {
            cout << "\nHello  Dr. " << user << "\nLOGIN SUCESS\n";
            return true;

        }
        else {

            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            return false;
        }
    }

    bool valid(char pass[])
    {
        bool upper = false;
        bool lower = false;
        bool digit = false;
        if (strlen(pass)<8)
        {
            cout << "Password must be 8 characters long!" << endl;
            return false;
        }
        while (*pass !=0)
        {
            if (isupper(*pass))
            {
                upper = true;

            }
            else if (islower(*pass))
            {
                lower = true;
            }
            else if (isdigit(*pass))
            {
                digit = true;
            }
            pass++;
        }
        if (!upper || !lower || !digit)
        {
            return false;
        }
        return true;
    }
   /* 
    void converter(string d, string t, string* str,int cas)
    {
        str[cas] = d;
        str[cas].append(t);

       
    }*/

    void doc_Register()
    {
       
        const int r = 20;
        string ruser, ru,rsp, rp, rc;
        string* str = new string[10];
        char rpass[r];
 
        system("cls");
        cout << " ********Doctor_Registration***********" << endl << endl;
        cout << "please enter the following details" << endl;
        cout << "Enter the username :";
        cin >> ruser;
        cout << "\nEnter the password :";

        cin >> rpass;
        if (!valid(rpass) )
        {
            cout << "Password is not Valid" << endl;
            cout << "\nEnter the password again :";
            cin.getline(rpass, r);
            if (!valid(rpass))
            {
                cout << "Password is not Valid" << endl;
                cout << "\nEnter the password again :";
                cin.getline(rpass, r);

            }
        }

        cout << "\nEnter the CNIC :";
        cin >> Cnic;
        if (Cnic>999999999999 && Cnic<9999999999999)
        {

       
            if (ru == ruser && rp == rpass)
            {
                cout << "Already Registered" << endl;
            }
            else
            {
               

                cout << "\nRegistration Sucessful\n";
                username = ruser;
                password = rpass;
                cout << " Now enter Years of specialization: " << endl;
                cin >> years;
                cout << " Enter your appointments for a week ( Not more than 10!!!)" << endl;
                cin.ignore();
                cin >> op;
                for (int i = 0; i < op; i++)
                {
                    apps[i] = new appointment;
                    cout << "Enter  Time for appointment" << endl;
                    string t;
                    cin >> t;
                    apps[i]->setTime(t);
                    cout << "Enter  DAY for appointment" << endl;
                    string d;
                    cin >> d;
                    apps[i]->setDay(d);
                    cout << "Enter  Charges for appointment" << endl;
                    int p;
                    cin >> p;
                   apps[i]->setcharges(p);
                   // converter(d, t, str, i);
                }
                cout << "Now Choose your Specilization Area!" << endl;
                cout << " Press 1 for Gynecologist!" << endl;
                cout << " Press 2 for Dermatologists!" << endl;
                cout << " Press 3 for Oncologists!" << endl;
                cout << " Press 4 for Orthopedic" << endl;
                cin.ignore();
                cin >> c;
                switch (c)
                {
                case 1:
                    sp = "Gynecologist";
                    hospital = "SAINT-MAARY";
                    break;
                case 2:
                    sp = "Dermatologist";
                    hospital = "CMH";
                    break;
                case 3:
                    sp = "Oncologists";
                    hospital = "SHIFA";
                    break;
                case 4:
                    sp = "Orthopedic";
                    hospital = "NISHTAR";
                    break;
                default:
                    cout << "Wrong Condition" << endl;
                    cout << "Enter Again: " << endl;
                    cin >> c;
                    switch (c)
                    {
                    case 1:
                        sp = "Gynecologist";
                        hospital = "lahore";
                        break;
                    case 2:
                        sp = "Dermatologist";
                        hospital = "lahore";
                        break;
                    case 3:
                        sp = "Oncologists";
                        hospital = "lahore";
                        break;
                    case 4:
                        sp = "Orthopedic";
                        hospital = "lahore";
                        break;
                    default:
                        cout << "Wrong Condition" << endl;
                        cout << "Enter Again: " << endl;
                        cin >> c;
                        break;
                    }

                }
            }
           
        
        
        }
        else
        {
            cout << " Register Again" << endl;
            doc_Register();
        }
       
        ifstream read("./doctor/doctor.txt");
        getline(read, ru);
        getline(read, rp);
        getline(read, sp);
        getline(read, hospital);
        for (int i = 0; i < op; i++)
        {
            
            
            temp[i] = apps[i]->getDay();
            getline(read, temp[i]);
 
            
            temp2[i] = apps[i]->getTime();
            getline(read, temp2[i]);
       
        }
       
        read.close();
        fstream file;
        file.open("./doctor/doctor.txt", ios::app);
        file << ruser << endl<< rpass << endl << sp <<endl<<hospital<< endl; 
        for (int i = 0; i < op; i++)
        {
            file << temp[i] << " " << temp2[i] << " ";
        }
        file << endl;
        file.close();



        

 
    }
protected:
	int op, c;
    string username;
    string password;
    long long int Cnic;
    int years;
    string sp;
    string hospital;
    int availhours;
    string city;
    appointment* apps[10];
    string temp[9];
    string temp2[9];


};

doctor::doctor()
{
    username = " ";
    password = " ";
    Cnic = 1000000000000;
    years = 0;

	
}

doctor::~doctor()
{
}
