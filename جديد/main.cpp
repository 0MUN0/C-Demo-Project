#include <iostream>
#include"clsBankClinte.h"

using namespace std;

static string ReadString()
{
    string  S1="";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, S1);
    return S1;
}
static float ReadFloatNumber()
{
    float num ;
    cout<<"Enter Number : " ;
    cin>>num ;
    return num ;
}

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.FirstName() = ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName() = ReadString();

    cout << "\nEnter Email: ";
    Client.Email() = ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone() = ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode()=ReadString();

    
}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber =ReadString();
    
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";

  
    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
}

int main()

{
    UpdateClient();
    system("pause>0");
    return 0;
}