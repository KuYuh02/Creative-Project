#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void decimalToBinary(int);
void binaryToDecimal(string);
void decimalToHex(int);
void hexToDecimal(string);
int main()
{
	bool terminateFlag = false; // repeat condition in while loop
	char input = 0;
	const char FILL  = '-';
	const int  WIDTH = 40;
	while(terminateFlag == false)
	{
		cout << "Welcome to my Number Conversion Application" << endl;
		cout << setfill(FILL) << setw(WIDTH) << '\n';
		cout << "1. Decimal to Binary" << endl;
		cout << "2. Binary to Decimal" << endl;
		cout << "3. Decimal to Hex" << endl;
		cout << "4. Hex to Decimal" << endl;
		cout << "9. Exit the program" << endl;
		cout << setfill(FILL) << setw(WIDTH) << endl;
		// get the user's choice
		cout << "Please enter a menu option: ";
		cin  >> input;
		cin.ignore(256,'\n');
		//check user input and execute desired option
		if(input == '1')
		{
			int num = 0;
			cout << "Enter a Decimal number to convert: ";
			cin >> num;
			if(num < 0 || cin.fail())
			{
				cout << "Invalid input!" << endl; // gives error message and goes back to beginning if negative number
				//Don't change terminateFlag and re enter while loop
				cin.clear();
				cin.ignore(256, '\n');
			}
			else if(num >= 0)
			{
				cin.ignore(256, '\n');
				decimalToBinary(num); // convert
			}
		}
		else if(input == '2')
		{
			string num;
			bool isValid = true;
			cout << "Enter a Binary number (0 1) to convert: ";
			cin >> num;
			cin.ignore(256, '\n');
			int length = num.size();
			for(int i = 0; i < length; i++)
			{
				if(num[i] == '0' || num[i] == '1')
				{
					//continue if valid
				}
				else
				{
					isValid = false;
				}
			}
			if(isValid == true)
			{
				binaryToDecimal(num); // convert
			}
			else
			{
				cout << "Invalid input!" << endl;
			}
		}
		else if(input == '3')
		{
			int num = 0;
			cout << "Enter a Decimal number to convert: ";
			cin >> num;
			if(num < 0 || cin.fail()) //if negative, start from the beginning
			{
				cout << "Invalid number!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
			{
				cin.ignore(256, '\n');
				decimalToHex(num); // convert
			}
		}
		else if(input == '4')
		{
			string num;
			cout << "Enter a four-digit Binary number (0-9),(a-f) to convert: ";
			cin >> num;
			cin.ignore(256, '\n');
			if(num.size() > 4) // check that the input is four digits
			{
				cout << "Input is longer than four digits!" << endl;
			}
			else
			{
				bool isValid = true;
				int length = num.size();
				for(int i = 0; i < length; i++) // check that each digit is a valid character
				{
					if((num[i] < '0' || num[i] > '9' || num[i] < 'a' || num[i] > 'f') && (num[i] != '-'))
					{
						//continue if valid characters
					}
					else
					{
						isValid = false; // change valid flag if invalid character
					}
				}
				if(isValid == true) // check valid flag
				{
						hexToDecimal(num);
				}
				else
				{
					cout << "Invalid input!" << endl;
				}
			}
		}
		else if(input == '9')
		{
			terminateFlag = true;
		}
	//If not given a number or valid input, do not change terminateFlag and start from the beginning
	}

	cout << "Program ending!" << endl; // prints Program ending!
	return 0;
}
//Function Definitions
void decimalToBinary(int num)
{
	string bin; // stores binary number
	int temp = num;
	if(temp == 0)
	{
		bin = "0"; // if user enters 0, which is non negative, make bin 0;
	}
	while(temp != 0)
	{
		if(temp % 2 == 0) // if remainder is 0, add '0' to left of bin string
		{
			bin = "0" + bin;
		}
		else if (temp % 2 == 1) // if remainder is 1, add '0' to left of bin string
		{
			bin = "1" + bin;
		}
		temp = temp / 2;
	}
	cout << num << " --> " << bin << endl;
}
void binaryToDecimal(string num)
{
	bool valFlag = true;
	string temp = num;
	int dec = 0;
	int base = 1; // 2^0 = 1
	int length = temp.size() - 1;
	for(int i = length; i >= 0; i--)
	{
		if(temp[i] == '1')
		{
			dec = base + dec;
		}
		else if(temp[i] == '0')
		{
			//do nothing when reach 0
		}
		else
		{
			valFlag = false;
		}
		base = base * 2;
	}
	if(valFlag == true)
	{
		cout << num << " --> " << dec << endl;
	}
	else
	{
		cout << "Invalid input!" << endl;
	}
}
void decimalToHex(int num)
{
	string bin; // stores binary number
	int temp = num;
	if(temp == 0)
	{
		bin = "0"; // if user enters 0, which is non negative, append 0;
	}
	while(temp != 0)
	{
		if(temp%16 == 0)
		{
			bin = "0" + bin;
		}
		else if (temp%16 == 1)
		{
			bin = "1" + bin;
		}
		else if (temp%16 == 2)
		{
			bin = "2" + bin;
		}
		else if (temp%16 == 3)
		{
			bin = "3" + bin;
		}
		else if (temp%16 == 4)
		{
			bin = "4" + bin;
		}
		else if (temp%16 == 5)
		{
			bin = "5" + bin;
		}
		else if (temp%16 == 6)
		{
			bin = "6" + bin;
		}
		else if (temp%16 == 7)
		{
			bin = "7" + bin;
		}
		else if (temp%16 == 8)
		{
			bin = "8" + bin;
		}
		else if (temp%16 == 9)
		{
			bin = "9" + bin;
		}
		else if (temp%16 == 10)
		{
			bin = "a" + bin;
		}
		else if (temp%16 == 11)
		{
			bin = "b" + bin;
		}
		else if (temp%16 == 12)
		{
			bin = "c" + bin;
		}
		else if (temp%16 == 13)
		{
			bin = "d" + bin;
		}
		else if (temp%16 == 14)
		{
			bin = "e" + bin;
		}
		else if (temp%16 == 15)
		{
			bin = "f" + bin;
		}
		temp = temp/16;
	}
	cout << num << " --> " << bin << endl;
}
void hexToDecimal(string num)
{
	int dec = 0; // stores decimal number
	int length = num.size();
	int base = 1; // 16^0 = 1
	bool valFlag = true;
	for(int i = length - 1; i >= 0; i--)
	{
		if(num[i] >= '0' && num[i] <= '9')
		{
			dec = dec + (int(num[i]) - 48) * base;
			base = base * 16;
		}
		else if(num[i] == 'a')
		{
			dec = dec + 10 * base;
			base = base * 16;
		}
		else if(num[i] == 'b')
		{
			dec = dec + 11 * base;
			base = base * 16;
		}
		else if(num[i] == 'c')
		{
			dec = dec + 12 * base;
			base = base * 16;
		}
		else if(num[i] == 'd')
		{
			dec = dec + 13 * base;
			base = base * 16;
		}
		else if(num[i] == 'e')
		{
			dec = dec + 14 * base;
			base = base * 16;
		}
		else if(num[i] == 'f')
		{
			dec = dec + 15 * base;
			base = base * 16;
		}
		else
		{
			valFlag = false;
		}
	}
	//Double check input was valid
	if(valFlag == true)
	{
		cout << num << " --> " << dec << endl;
	}
	else
	{
		cout << "Invalid Input!" << endl;

	}

}