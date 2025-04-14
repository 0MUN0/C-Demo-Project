#pragma onc

#include <iostream>
#include <cstdlib> 
#include<ctime>   
using namespace std ;



class clsUntil
{

    public:

    
enum enCharType { 
    SamallLetter = 1,    // Represents lowercase letters (ASCII 97 to 122).
    CapitalLetter = 2,   // Represents uppercase letters (ASCII 65 to 90).
    Digit = 4 ,
    mixCharacter = 5           // Represents digits (ASCII 48 to 57).
};


    static void SRAND()
{
    srand((unsigned)time(NULL));
}

static int RandomNumber(int From = 1, int To = 10)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

static char GetRandomCharacter(enCharType CharType)
{

    switch (CharType)
    {
    case enCharType::SamallLetter:
    {
        return char(RandomNumber(97, 122));
        break;  
    }

    case enCharType::CapitalLetter:
    {

        return char(RandomNumber(65, 90));
        break;
    }
  
    case enCharType::Digit:
    {

        return char(RandomNumber(48, 57));
        break;
    }

    case enCharType::mixCharacter:
    {

        return char(RandomNumber(48, 122));
        break;
    }
    }


    return '\0';
}

static string GenerateWord(enCharType CharType, short Length) 
{
    string Word; 

    // Loop for the number of characters specified by Length.
    for (int i = 1; i <= Length; i++)
    {
        // Append a random character of the specified type to the word.
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

static string GenerateKey()
{
    string Key = "";  // Initialize an empty key string.


    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    
    return Key;
}

static void GenerateKeys(short NumberOfKeys)
{
    // Loop from 1 to NumberOfKeys.
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        // Print the current key number and the generated key.
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}

static void Swap(int& A, int& B)
{
    int Temp;    
    Temp = A;    
    A = B;       
    B = Temp;    
}

static void ShuffleArray(int arr[100], int arrLength)
{
    
    for (int i = 0; i < arrLength; i++)
    {
        
        int index1 = RandomNumber(1, arrLength) - 1;
        int index2 = RandomNumber(1, arrLength) - 1;
        
        Swap(arr[index1], arr[index2]);
    }
}

static void FillArrayWithRandomNumber(int arr[100], int arrLength)
{
    // Loop through each index and assign the value (index + 1) to that element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = clsUntil::RandomNumber(1,99);
}

static void FillArrayWithRandomWords(string arr[100], int arrLength)
{
    // Loop through each index and assign the value (index + 1) to that element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = clsUntil::GenerateWord(enCharType::CapitalLetter,arrLength) ;
}

static void FillArrayWithRandomKey(string arr[100], int arrLength)
{
    // Loop through each index and assign the value (index + 1) to that element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = clsUntil::GenerateKey() ;
}

static void tabs(int manyTabs)
{
    for(int c = 0 ;c<manyTabs;c++)
    {
        cout<<"    " ;
    }
}

string EncryptText(string Text, short EncryptionKey)
{
   
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text; 
}

string DecryptText(string Text, short EncryptionKey)
{
   
    for (int i = 0; i <= Text.length(); i++)
    {
         Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = { "",
        "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
        "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {
        "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
        ,"Ninety" };
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " +
            NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }
    ProgrammingAdvices.com
        © Copyright 2022
        Problem # 1 / 4 Solution Using C++
        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " +
                NumberToText(Number % 1000);
        }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " +
            NumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number %
            1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " +
            NumberToText(Number % 1000000000);
    }
}

} ;

