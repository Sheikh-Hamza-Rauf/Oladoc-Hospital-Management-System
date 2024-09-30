#include<iostream>
#include"admin/admin.h"
#include "doctor/doctor.h"
#include "patient/patient.h"
#include "appointment/appointment.h"
#include "payment.h"
using namespace std;

class User: public admin , public patient , public doctor
{
public:
	User();
	~User();
   /* void selection(int c)
    {
        switch (c)
        {
        case 1:
            c

        default:
            break;
        }
    }*/
    
private:

};

User::User()
{
}

User::~User()
{
}
class Oladoc
{
public:
 
    User u1, u2, u3;

	void display();
	Oladoc();
	~Oladoc();
    void setA(int a)
    {
        this->a = a;
    }
    int getA()const
    {
        return a;
    }
private:
    int a;

};

Oladoc::Oladoc()
{
    a = 0;

}

Oladoc::~Oladoc()
{
}
void Oladoc::display()
{
  
    cout << " ***** WELCOME TO OLADOC APPLICATION *****\n";
    cout << endl;
    cout << endl;
    cout << "        ***MAIN MENU***\n";
    cout << endl;
    cout << "press 1 to enter as an Admin\n";
    cout << "press 2 to enter as a  Doctor\n";
    cout << "press 3 to enter as a  Patient\n";
    cin >> a;


}


int main()
{
    Oladoc o1;
    appointment *a1= new appointment;
    appointment a2;
    patient p1(0, " ", " ", 1000000000000, 0,a1 );
    o1.display();
    
    if (o1.getA() == 1)
    {
        o1.setA(o1.u1.admin_menu());
        if (o1.getA() ==1)
        {
            o1.u1.admin_login();
        }
        else if (o1.getA() == 2)
        {
            o1.u1.admin_Register();
            o1.u1.admin_login();
        }

    }
    else if (o1.getA() == 2)
    {
        o1.setA(o1.u1.doctor_menu());
        if (o1.getA() == 1)
        {
            o1.u1.doc_login();
        }
        else if (o1.getA() == 2)
        {
            o1.u1.doc_Register();
            o1.u1.doc_login();
        }


    }
    else if (o1.getA() == 3)
    {
        o1.setA(o1.u1.patient_menu());
        if (o1.getA() == 1)
        {
           bool flag= o1.u1.pat_login();
            if (flag == true)
            {
                o1.u1.pat_sub_menu();
              o1.u1.show_appointment(o1.u1.getdoc());
              a2.TypeAppointment();
              int z=a2.show();
              /*switch (z)
              {
              case 1:
                  payment * pay1 = new JazzCash;
                  break;
              case 2:
                  payment * pay2 = new EasyPaisa;
                  break;
              case 3:
                  payment * pay3 = new UnionPay;
                  
                  break;
              case 4:
                  payment * pay4 = new PakPay;
                  break;
              default:
                  break;
              }*/
            }
            

        }
        else if (o1.getA() == 2)
        {
            o1.u1.pat_Register();
            bool flag = o1.u1.pat_login();
            if (flag == true)
            {
                o1.u1.pat_sub_menu();
               o1.u1.show_appointment(o1.u1.getdoc());
               a2.TypeAppointment();
               int z = a2.show();
               /*switch (z)
               {
               case 1:
                   payment * pay5 = new JazzCash;
                   break;
               case 2:
                   payment * pay6 = new EasyPaisa;
                   break;
               case 3:
                   payment * pay7 = new UnionPay;

                   break;
               case 4:
                   payment * pay8 = new PakPay;
                   break;
               default:
                   break;
               }*/
            }
           
        }

    }
    else {
        cout << "Wrong selection! Try Again" << endl;
        o1.display();
    }
}