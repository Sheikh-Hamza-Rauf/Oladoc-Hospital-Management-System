#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"../patient/patient.h"
using namespace std;

class admin
{

public:
	admin();
	~admin();
	int admin_menu()
	{
		
		cout << " ********* Admin Menu *******" << endl;
		cout << endl;
		cout << "1.LOGIN" << endl;
		cout << "2.REGISTER" << endl; 
		cout << "\nEnter your choice :";
		cin >> c;
		return c;
	}
    bool admin_login()
    {
        int count = 0;
        string user, pass, u, p;
        system("cls");
        cout << " ********Admin_Login***********" << endl << endl;
        cout << "please enter the following details" << endl;
        cout << "USERNAME :";
        cin >> user;
        cout << "PASSWORD :";
        cin >> pass;
        string admin = "";
        u = "";
        p = "";

        ifstream read("./admin/admin.txt");
        //loop to check all lines of file one by one
        while (!read.eof()) {
            getline(read, admin);
            int pos = admin.find(" ");
            u = admin.substr(0, pos);
            p = admin.substr(pos + 1, admin.size());
            if (u == user && p == pass)
                break;
        }
        if (u == user && p == pass)

        {
            cout << "\nHello " << user << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
            return true;

        }
        else {

            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            return false;
        }
    }
       
    
    void admin_Register()
    {
        
        string reguser, regpass, ru, rp;
        ;
        system("cls");
        cout << " ********Admin_Registration***********" << endl << endl;
        cout << "Please enter the following details" << endl;
        cout << "Enter the username :";
        cin >> reguser;
        cout << "\nEnter the password :";
        cin >> regpass;

        fstream file;
        file.open("./admin/admin.txt",ios::app);
        file << reguser << " " << regpass<<endl;
        file.close();
        cout << "\nRegistration Sucessful\n";

    }

protected:
	int c;
    string name;
    string pass;
    patient pat1;
};

admin::admin()
{
    name = "admin";
    pass = "admin123";
    c = 0;
}

admin::~admin()
{
}
