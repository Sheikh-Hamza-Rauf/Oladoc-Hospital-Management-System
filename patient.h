#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include"../appointment/appointment.h"
#include "../doctor/doctor.h"
using namespace std;
class patient
{
public:
    patient()
    {
        c = 0;
        username = " ";
        password = " ";
        money = 0;
        Cnic = 1000000000000;
        a = NULL;
    }

    patient(int d, string us, string pas, long long int cn, int mon, appointment* ad)
    {
        c = d;
        username = us;
        password = pas;
        money = mon;
        Cnic = cn;
        a = ad;

    }
    void setUsername(string d)
    {
        username = d;
    }
    string getUsername() const {
        return username;
    }
    void setdoc(string d)
    {
        doc = d;
    }
    string getdoc() const {
        return doc;
    }


    int patient_menu()
    {

        cout << " ********* Patient Menu *******" << endl;
        cout << endl;
        cout << "1.LOGIN" << endl;
        cout << "2.REGISTER" << endl;
        cout << "\nEnter your choice :";
        cin >> c;
        return c;
    }

    bool pat_login()
    {
        //int count = 0;
        string user, pass, u, p;
        system("cls");
        cout << " ********Patient_Login***********" << endl << endl;
        cout << "please enter the following details" << endl;
        cout << "USERNAME :";
        cin >> user;
        cout << "PASSWORD :";
        cin >> pass;
        string patient = "";
        u = "";
        p = "";
        ifstream read("./patient/patient.txt");
        //loop to check all lines of file one by one
        while (!read.eof()) {
            getline(read, patient);
            int pos = patient.find(" ");
            u = patient.substr(0, pos);
            p = patient.substr(pos + 1, patient.size());
            if (u == user && p == pass)
                break;
        }
        if (u == user && p == pass)

        {
            cout << "\nHello " << user << "\nLOGIN SUCESS\n";
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
        if (strlen(pass) < 8)
        {
            cout << "Password must be 8 characters long!" << endl;
            return false;
        }
        while (*pass != 0)
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



    void pat_Register()
    {
        const int r = 20;
        string ruser, ru, rp, rc;
        char rpass[r];

        system("cls");
        cout << " ********Patient_Registration***********" << endl << endl;
        cout << "please enter the following details" << endl;
        cout << "Enter the username :";
        cin >> ruser;
        cout << "\nEnter the password :";

        cin >> rpass;
        if (!valid(rpass))
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
        if (Cnic > 999999999999 && Cnic < 9999999999999)
        {
            string a = " ";
            ifstream read("./patient/patient.txt");
            getline(read, ru);
            getline(read, rp);

            if (ru == ruser && rp == rpass)
            {
                cout << "Already Registered" << endl;
            }
            else
            {
                fstream file;
                file.open("./patient/patient.txt", ios::app);
                file << ruser << " " << rpass << endl;
                file.close();

                cout << "\nRegistration Sucessful\n" << endl;
                username = ruser;
                password = rpass;
            
                cout << " Money 3500PKR HAS BEEN ADDED TO Ola Wallet!" << endl;
                money=3500;
                cout << "Press any key to continue: ";
                cin >> a;
            }

        }
        else
        {
            cout << " Register Again" << endl;
            pat_Register();
        }





    }

    void book_appointment() {
        cout << "Find Doctor by speciality: " << endl;
        string consultant;
        //cin >> consultant;
        cout << "Now Choose your Specilization Area!" << endl;
        cout << " Press 1 for Gynecologist!" << endl;
        cout << " Press 2 for Dermatologists!" << endl;
        cout << " Press 3 for Oncologists!" << endl;
        cout << " Press 4 for Orthopedic" << endl;
        cin.ignore();
        cin >> c;
        //put switch case to check doctor speciality
        string u = "";
        string p = "";
        string spec;
        string hos;
        string uname = "";
        string hosp="";
        string appoint = "";

        bool flag = 0;
        ifstream read("./doctor/doctor.txt");
        while (!read.eof()) {
            read >> u;
            read >> p;
            read >> spec;
            read >> hos;
        


            switch (c)
            { 
            case1:
                if (spec == "Gynecologist") {
                    cout << "Name: " << u << endl;
                    cout << "Hospital: " << hos << endl;
                    cout << "If you want to book an appointment with this doctor press 1/0" << endl;
                    cin >> flag; //input from user
                 
               
                    break;
                }
            case 2:
                 if (spec == "Dermatologist") {
                cout << "Name: " << u << endl;
                cout << "Hospital: " << hos << endl;
                cout << "If you want to book an appointment with this doctor press 1 / 0: " << endl;
                cin >> flag; //input from user
              
                break;
            }
            case 3:
                if (spec == "Oncologists") {
                    cout << "Name: " << u << endl;
                    cout << "Hospital: " << hos << endl;
                    cout << "If you want to book an appointment with this doctor press 1 / 0: " << endl;
                    cin >> flag; //input from user
                   
                    break;
                }
            case 4:
                if (spec == "Orthopedic") {
                    cout << "Name: " << u << endl;
                    cout << "Hospital: " << hos << endl;
                    cout << "If you want to book an appointment with this doctor press 1 / 0: " << endl;
                    cin >> flag; //input from user
                    
                    break;
                }
          
            default:
                cout << "Doctor Not found by Speciality!" << endl;
                break;
            }
            
            if (flag)
                break;
                
      

        }
        
        setdoc(u);

    
    }
    void pat_sub_menu()
    {
        cout << endl << endl;
        cout << "Press  1 to Book an appointment with our Doctors!" << endl;
        cout << "Press  2 to Check Walllet" << endl;
        cout << "Press  3 to lOGOUT" << endl;
        cin.ignore();
        cin >> c;
        switch (c)
        {
        case 1: 
            book_appointment();
            break;
        case 2:
            cout << "You have " << money << "PKR" << endl;
            break;
        case 3:
            patient_menu();
            break;
        default:
            cout << "Wrong Value Entered!" << endl;
            break;
        }

    }

    void show_appointment(string uname)
    {
       
        cout << "***********Dr. " << uname << " Appointment Schedule:   ***********" << endl << endl;
        string l;
        int comRes;
        ifstream inp("./doctor/doctor.txt");
        if (inp.is_open())
        {

            while (getline(inp, l))    //loop through input file line by line
            {

                if (l.length() > 0)    //skip empty lines
                {
                    //lineCounter++;    //keeps track of what line you're at
                    comRes = l.compare(uname);    //compare each line of the document with the entered mail
                    if (comRes == 0)    //if match..
                    {
                        getline(inp, l); 
                        getline(inp, l);
                        getline(inp, l);
                        getline(inp, l);
                     //get next line (appointments)
                        cout << l << endl;

                       
                    }

                }

            }

            inp.close();
        }


    }
protected:
    int c;
    string username;
    string password;
    long long int Cnic;
    int money;
   appointment * a;
   string doc;

};

