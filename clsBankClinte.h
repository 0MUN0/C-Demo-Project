#pragma once

#include<iostream>
#include <vector>
#include<fstream>
#include"clsPerson.h"
#include "clsString.h"
using namespace std ;

static string FileName ="Clients.txt " ;


class clsBankClient : public clsPerson 
{


public :
enum enMode {EmpytMode = 0 , UpdateMode = 1} ;
private:
enMode _Mode ;
string _AccountNumber ;
string _PinCode ;
float _AccountBalance ;

//"Clients.txt"


static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#") 
{
    vector <string> vCliBeS  = clsString::Split(Line,Seperator) ;
    
    return clsBankClient(enMode::UpdateMode,vCliBeS[0],vCliBeS[1],vCliBeS[2],vCliBeS[3],vCliBeS[4],vCliBeS[5],stod(vCliBeS[6])) ;
     
}

static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.FirstName() + Seperator;
    stClientRecord += Client.LastName() + Seperator;
    stClientRecord += Client.Email() + Seperator;
    stClientRecord += Client.Phone() + Seperator;
    stClientRecord += Client.AccountNumber() + Seperator;
    stClientRecord += Client.PinCode() + Seperator;
    stClientRecord += to_string(Client.AccountBalance());

    return stClientRecord;}

public :

clsBankClient(enMode Mode, string FirstName,
     string LastName,string Email, string Phone, string AccountNumber, string PinCode,float AccountBalance)
:clsPerson(FirstName,LastName,Email,Phone) 
{

    _AccountBalance = AccountBalance ;
    _AccountNumber = AccountBalance ;
    _PinCode = PinCode ;
    
}

static  vector <clsBankClient> _LoadClientsDataFromFile()
{
    vector<clsBankClient> vClintes ;

    fstream File ;
    
    File.open(FileName,ios::in) ;

    if(File.is_open())
    {
        string Line ;

        while(getline(File,Line))
        {
            vClintes.push_back(_ConvertLinetoClientObject(Line)) ;

        }
        File.close() ;
    }
    return vClintes ;

}

static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
{
    fstream File ;
    File.open(FileName,ios::out) ;
    if(File.is_open())
    {
        for(clsBankClient & C : vClients)
    {
        string Line = _ConverClientObjectToLine(C) ;
        File<<Line<<endl ;

        File.close() ;
    }
    }

    
}

void _AddDataLineToFile(string  stDataLine)
{
    fstream File ;

    File.open(FileName,ios::app) ;

    if(File.is_open())
    {
        File<<stDataLine<<endl ;

        File.close() ;
    }

}

static clsBankClient _GetEmptyClientObject()
{
    return clsBankClient(enMode::EmpytMode,"","","","","","",0) ;
}

static clsBankClient Find(string AccountNumber)
{

    fstream MyFile;
    MyFile.open("Clients.txt", ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            clsBankClient Client = _ConvertLinetoClientObject(Line);
            if (Client.AccountNumber() == AccountNumber)
            {
                MyFile.close();
                return Client;
            }
        }
    }
    return _GetEmptyClientObject() ;
}

static bool IsClinteExist(string AccountNumber)
{
    clsBankClient Clinte = clsBankClient::Find(AccountNumber) ;
    return(!Clinte.IsEmpty()) ;
}

static clsBankClient Find(string AccountNumber, string PinCode)
{

    fstream MyFile;
    MyFile.open("Clients.txt", ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            clsBankClient Client = _ConvertLinetoClientObject(Line);
            if (Client.AccountNumber() == AccountNumber&&Client.PinCode() == PinCode)
            {
                MyFile.close();
                return Client;
            }
        }
    }
    return _GetEmptyClientObject() ;
    }
    
bool IsEmpty()
{}

float AccountBalance()
{
    return _AccountBalance ;
}

string AccountNumber()
{
return _AccountNumber ;
}

string PinCode()
{
    return _PinCode ;
}

void setPinCode(string Code)
{
    _PinCode = Code ;
}

string FullName()
{
    return FirstName()+" "+LastName() ;
}

void Print()
{
    cout << "\nClient Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << FirstName();
    cout << "\nLastName    : " << LastName();
    cout << "\nFull Name   : " << FullName();
    cout << "\nEmail       : " << Email();
    cout << "\nPhone       : " << Phone();
    cout << "\nAcc. Number : " << _AccountNumber;
    cout << "\nPassword    : " << _PinCode;
    cout << "\nBalance     : " << _AccountBalance;
    cout << "\n___________________\n";

}


enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };

enSaveResults Save()
{

    switch (_Mode)
    {
    case enMode::EmpytMode ;
    {
    
            return enSaveResults::svFaildEmptyObject;
    }

    case enMode::UpdateMode:
    {


        _Update();

        return enSaveResults::svSucceeded;

        break;
    }


    }



}

static bool IsClientExist(string AccountNumber)
{

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    return (!Client1.IsEmpty());
}



} ;







































