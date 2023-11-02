#include<iostream>
using namespace std;
int StringLength(char str[]);
int FindString(char mainstr[], char substr[]);
void RightShift(char mainstr[], int starting_index, int repetition);
void replaceWithBiggerString(char mainstr[], char replacestr[], int index,int length_findstr);
void LeftShift(char mainstr[], int starting_index, int repetition);
void replaceWithSmallerString(char mainstr[], char replacestr[], int index, int length_findstr);
void replaceWithEqualStrings(char mainstr[], char replacestr[], int index);
int findreplace(char mainstr[], char findstr[], char replacestr[]);
// i have created two functions leftshift and rightshif to do all the shiffting of strings that may be required
int main()
{
	char mainstr[200];
	char findstr[50];
	char replacestr[50];
	cout<<findreplace(mainstr, findstr, replacestr);	
}
int StringLength(char str[])
{ 
	int counter=0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		counter++;
	}
	return counter;
}
int FindString(char mainstr[], char substr[])
{
	int subi = 0,index=-1;
	int mainLen = StringLength(mainstr); 
	int subLen = StringLength(substr);
	for (int maini = 0; maini <mainLen ; maini++) //subi is the index of substr and maini is the index of mainstr
	{

		if (mainstr[maini] == substr[subi])
		{

			index = maini;
			index = maini - subi;  
			subi++;

		}
		else
			index = -1;
		if (subi == subLen) //when all characters of substr match with any consecitive set of characters of substring this condition will become true
			return index;
		
	}
	return index;
}
void RightShift(char mainstr[], int starting_index, int repetition) //repetition represents the amount of time we need to repeat the shifting
{
	int MainLen = StringLength(mainstr)+1;
	int size = MainLen - starting_index;
	for (int i = 0; i < repetition; i++)
	{
		int endpoint = starting_index + size + 1; // e.g if the string is "i am good" and substring is "am" then the endpoint will represent the chracter after "am" which is a space in this case
		
		while (endpoint > starting_index)
		{
			mainstr[endpoint] = mainstr[endpoint - 1];
			endpoint--;
		}
		
		starting_index++;
	      
	}

}
void replaceWithBiggerString(char mainstr[], char replacestr[],int index,int length_findstr)
{
	
	RightShift(mainstr, index + length_findstr , StringLength(replacestr) - length_findstr);
	
	for (int i = 0; replacestr[i] != '\0'; i++)
	{
		mainstr[index] = replacestr[i];
		index++;
	}

	
}
void LeftShift(char mainstr[], int starting_index, int repetition)
{
	int MainLen = StringLength(mainstr) + 1;
	int size = MainLen - starting_index;
	for (int i = 0; i < repetition; i++)
	{
		int startpoint = starting_index - 1;
		for (int j = starting_index; j <= MainLen; j++)
		{
			mainstr[j - 1] = mainstr[j];
		}
		starting_index--;

	}

}
void replaceWithSmallerString(char mainstr[], char replacestr[], int index, int length_findstr)
{
		
	LeftShift(mainstr, index + length_findstr , length_findstr - StringLength(replacestr));
	for (int i = 0; replacestr[i] != '\0'; i++)
	{
		mainstr[index] = replacestr[i];
		index++;
	}
}
void replaceWithEqualStrings(char mainstr[], char replacestr[], int index)
{
	
	for (int i = 0; replacestr[i] != '\0'; i++)
	{
		mainstr[index] = replacestr[i];
		index++;
	}

}
int findreplace(char mainstr[], char findstr[], char replacestr[])
{
	cout << "Enter the main string: ";
	cin.getline(mainstr, 100);
	cout << "Enter the string you want to find: ";
	cin.getline(findstr, 100);
	cout << "Enter the replacement string: ";
	cin.getline(replacestr, 100);
	int index = FindString(mainstr, findstr);
	int length_findstr = StringLength(findstr);
	int length_mainstr = StringLength(mainstr);
	if (index != -1)
	{
		if (length_findstr < StringLength(replacestr))
		{

			replaceWithBiggerString(mainstr, replacestr, index, length_findstr);
			cout << mainstr<<endl;
			return index;
		}
		else if (length_findstr > StringLength(replacestr))
		{
			replaceWithSmallerString(mainstr, replacestr, index, length_findstr);
			cout << mainstr<<endl;
			return index;
		}
		else
		{
			replaceWithEqualStrings(mainstr, replacestr, index);
			cout << mainstr<<endl;
			return index;
		}
	}
	else
		return index;
}