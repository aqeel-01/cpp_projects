
#include<iostream>

#include<windows.h>

#include<fstream>

#include<conio.h>

#include<stdio.h>

#include<string>





using namespace std;


class bus
{

protected:

    unsigned int bus_seats,bus_no;


    string bus_name,driver_name;


public:
    void menu();
    void new_bus();
    void view_bus();
    void single_bus_view();
    void all_bus_view();

    void update_bus_record();
    void delete_bus_record();
    void route_bus();

};

void bus::menu()
{

p:


system ("cls");
int choice;

cout<<"\n \n \t\t     ***BUS RESERVATION SYSTEM***  "   ;

cout<<"\n  please select from following ";

cout<<"\n\n  press 1 for ADD BUS RECORED ";
cout<<"\n  press 2 VIEW BUSES RECORD";
cout<<"\n  press 3 UPDATE BUS DETAIL ";
cout<<"\n  press 4 DELETE BUS DETAIL ";
cout<<"\n  press 5 ROUTES OF BUSES ";
cout<<"\n  press 6 BOOKING RECORD ";
cout<<"\n  press 7 SEAT RENEW ";
cout<<"\n  press 8 SEARCH BOOKING RECORED";
cout<<"\n  press 9 UPDATE BOOKING RECORD ";
cout<<"\n  press 10 DELETE BOOKING RECORD ";
cout<<"\n  press 11 SHOW ALL BOOKING RECORD ";
cout<<"\n  press 12 EXIT";

cout<<"\n\n enter required choice ";
cin>>choice;

switch(choice)
{

case 1:
    new_bus();
    break;

case 2:
    view_bus();
    break;

case 3:
     update_bus_record();
    break;

case 4:
    delete_bus_record();
    break;

case 5:
    route_bus();
    break;

case 6:
    break;

case 7:
    break;

case 8:
    break;

case 9:
    break;

case 10:
    break;

case 11:
    break;

case 12:
    exit(0);

default:
    cout<<"\n try again ! invalid choice ";



}
 getch();
 goto p;

}

void bus::new_bus()
{


p:

    system("cls");

    int found=0;
    unsigned int tbus_no,tbus_seats;
    string tbus_name,tdriver_name;

    cout<<"\n \n _______BUS MANAGEMENT SYSTEM_______";

    cout<<"\n\n enter bus no ";
    cin>>bus_no;

    cout<<"\n \n enter  bus name ";
    cin>>bus_name;

    cout<<"\n \n enter driver name ";
    cin>>driver_name;

    cout<<"\n \n enter total seats ";
    cin>>bus_seats;


    fstream file;
    file.open("bus.txt",ios::in);
if(!file)
{
   file.open("bus.txt",ios::app|ios::out);

   file<<bus_no<<"  "<<bus_name<<"  "<<driver_name<<" "<<bus_seats<<"\n ";
   file.close();
}

else
{
    file>>tbus_no>>tbus_name>>tdriver_name>>tbus_seats;
    while(!file.eof())
    {
        if(bus_no==tbus_no)
        {
            found++;
        }

        file>>tbus_no>>tbus_name>>tdriver_name>>tbus_seats;
    }

file.close();
if(found==0)
{
    file.open("bus.txt",ios::app|ios::out);

   file<<bus_no<<"  "<<bus_name<<"  "<<driver_name<<" "<<bus_seats<<"\n ";
   file.close();
}

else
{
    cout<<"\n\n\n  record already exist..... ";
    getch();
    goto p;
}

}
cout<<" \n\n  new bus information successfully inserted ...";

}

void bus::view_bus()
{
    p:

    system ("cls");
     cout<<"\n \n _______BUS MANAGEMENT SYSTEM_______";

     unsigned int choice2;

     cout<<"\n press 1 to view single bus only";
     cout<<"\n press 2 to view all buses";
     cout<<"\n press 3 to go back ";
     cin>>choice2;

     switch(choice2)
     {
        case 1:
        single_bus_view();
        break;

        case 2:
        all_bus_view();
        break;

        case 3:
        menu();

        default:
        cout<<"\n try again! invalid choice";


     }
     getch();
     goto p;


}

void bus::single_bus_view()
{
    system("cls");
    cout<<"\n \n _______BUS MANAGEMENT SYSTEM_______";

    unsigned int tbus_no,tbus_seats;

    string tbus_name,tdriver_name;


     int found2=0;
    fstream file;

    file.open("bus.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n error file dosen't exist ";
    }
    else
    {
        cout<<"\n\n enter bus no ";
      cin>>tbus_no;

      file>>tbus_no>>tbus_name>>tdriver_name>>tbus_seats;

      while(!file.eof())
      {
        if(tbus_no==bus_no)
        {
            cout<<" \n\n bus no \t bus name \t driver name \t no of seats";
            cout<<"\n "<<bus_no<<"\t\t"<<bus_name<<"\t \t "<<driver_name<<"\t\t"<<bus_seats;

            found2++;
        }
        file>>bus_no>>bus_name>>driver_name>>bus_seats;
      }
      file.close();
      if(found2==0)
      {
        cout<<" try again ,not found required  bus no ";
      }
    }
}

void bus::all_bus_view()
{
    system("cls");
    cout<<"\n \n _______BUS MANAGEMENT SYSTEM_______";

    unsigned int tbus_no,tbus_seats;

    string tbus_name,tdriver_name;


    fstream file;

    file.open("bus.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n error file dosen't exist ";
    }
    else
    {

       cout<<" \n\n bus no \t bus name \t driver name \t no of seats";
      file>>tbus_no>>tbus_name>>tdriver_name>>tbus_seats;

      while(!file.eof())
      {

            cout<<"\n "<<bus_no<<"\t\t"<<bus_name<<"\t \t "<<driver_name<<"\t\t"<<bus_seats;

        file>>bus_no>>bus_name>>driver_name>>bus_seats;
      }
      file.close();

    }
}

void bus::update_bus_record()
{

    system("cls");
    cout<<"\n\n\t ________BUS management system_______";

    fstream file,file2;
    unsigned int tbus_no;

    unsigned int upd_no,upd_seats;
    string upd_name,upd_dname;
unsigned int    found3=0;

    file.open("bus.txt",ios::in);
    {
        if(!file)
        {
            cout<<"\n\n file not exist ";
        }
        else
        {
            cout<<"\n\n enter bus no ";
            cin>>tbus_no;

             file2.open("bus2.txt",ios::app|ios::out);
            file>>bus_no>>bus_name>>driver_name>>bus_seats;

            while(!file.eof())
            {
                if(tbus_no==bus_no)
                {
                    cout<<"\n\n  enter new bus no";
                    cin>>upd_no;

                    cout<<"\n\n  enter bus name ";
                    cin>>upd_name;

                    cout<<"\n\n enter driver name";
                    cin>>upd_dname;

                    cout<<"\n\n enter no of seats ";
                    cin>>upd_seats;

                    file2<<upd_no<<" "<<upd_name<<" "<<upd_dname<<" "<<upd_seats<<"\n ";

                    cout<<"\n\n updated bus record ...";

                    found3++;
                }

                else
                {
                   file2<<bus_no<<" "<<bus_name<<"  "<<driver_name<<"  "<<bus_seats<<"\n ";

                }
                 file>>bus_no>>bus_name>>driver_name>>bus_seats;

            }
            file.close();
            file2.close();

            remove("bus.txt");

            rename("bus2.txt","bus.txt");

            if(found3==0)
            {
                cout<<"\n\n try again invalid bus no ";
            }
        }
    }
}

void bus::delete_bus_record()
{

    system("cls");
    cout<<"\n\n\t ________BUS management system_______";

    fstream file,file2;
    unsigned int tbus_no;

  unsigned int  found3=0;

    file.open("bus.txt",ios::in);
    {
        if(!file)
        {
            cout<<"\n\n file not exist ";
        }
        else
        {
            cout<<"\n\n enter bus no ";
            cin>>tbus_no;

             file2.open("bus2.txt",ios::app|ios::out);
            file>>bus_no>>bus_name>>driver_name>>bus_seats;

            while(!file.eof())
            {
                if(tbus_no==bus_no)
                {

                    cout<<"\n\n deleted the  bus record ...";

                    found3++;
                }

                else
                {
                   file2<<bus_no<<" "<<bus_name<<"  "<<driver_name<<"  "<<bus_seats<<"\n ";

                }
                 file>>bus_no>>bus_name>>driver_name>>bus_seats;

            }
            file.close();
            file2.close();

            remove("bus.txt");

            rename("bus2.txt","bus.txt");

            if(found3==0)
            {
                cout<<"\n\n try again invalid bus no ";
            }
        }
    }
}

void bus::route_bus()
{

    //p:
    system("cls");
    unsigned int choice4;

    cout<<"\n\\t\t______bus management system______";
    cout<<"\n\n\n";

    cout<<"\n press 1 for ist route";
    cout<<"\n press 2 for 2nd route";
    cout<<"\n press 3 for 3rd route";
    cout<<"\n press 4 for 4th route";
    cout<<"\n press 5 for 5th route";

    cout<<" \n\n enter your desired route ";
    cin>>choice4;

    switch(choice4)
    {
        case 1:
        break;

        case 2:
        break;
        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        default:
        cout<<"\n\n try again ...invalid choice";
        cin>>choice4;
        //getch();
        //goto p;
    }

}


 int main()
{
    bus b;

    p:
        system("cls");

    string pass,email;

    cout<<" \n\t\t\t\t\t\t\t  please verify your identity \t \t ";
    cout<<"\n \n  please enter your email ";
    cin>>email;

    char ch;
    cout<<"\n \n  please  enter your  password  ";
    for(int i=1;i<=4;i++)
    {

        ch=getch();
        pass=pass+ch;
        cout<<"*";
    }

    if(email=="aqeel@gmail.com"&& pass=="a700")
    {
        cout<<"\n\n \t\t\t\t\t loadingg.... ";
        for(int i=1;i<=3;i++)
        {

            Sleep(800);
            cout<<"*";
        }
        b.menu();

    }
    else
    {

        cout<<" \n  \t \t sorry ! your credentials are wrong ,try again thanks... ";
        getch();
        goto p;
    }
    //cin>>

}


