/*******************************************************************************
*  Week 06 Programming Assignment
*  Eric Harrington
********************************************************************************
**********************************before main***********************************
* 1: declare and initialize const ints "playerCount" and "scoresCount" for use 
*    in array declarations and index bounds in loops
* 
* 2: declare prototype functions
* 
* 3: include int argc and char* argv[] so program can also be run using CLI args
* 
* *********************************within main***********************************
* 4: declare arrays "names" and "averageScore" and a 2-dimensional array "scores"
*    that will hold each player's scores
* 
* 5: declare ifstream variable "infile" and declare a string variable "filename" 
*    for file opening; declare string variable filenameExt and initialize it to
*    ".txt" (this will be appended to user input if the user neglects to include 
*    a file ext
* 
* 6: use an if_else statement to check whether argc is greater than 1; if it is,
*    the user must have used the CLI, so set assign filename to argv[1]; if argc
*    is not greater than 1, then user must have run the program without CLI args,
*    so in the else statement use cin to extract the file name from user input
* 
* 7: use an if statement to check whether the user's input--CLI arg or string
*    extracted by cin--contains ".txt"; if filename.find(".txt") returns 
*    string::npos, then append filenameExt to filename
* 
* 8: set up another if-else statement; in the if statement, check whether infile
*    is true after infile.open(filename); if it is, call functions within the 
*    if-statement block; if it isn't, use infile.close() within the else statement
*    block and use cout to inform user an error occurred opening the file
* 
* ************************************after main*********************************
* 
* 9: define GetBowlingData: use an ifstream variable and nested for loops to read
*	 from "BowlingScores.txt" and to populate the "names" and "scores" arrays; 
*    "names" will be assigned a new name with each iteration of the outer for loop,
*    and "scores" will be populated with each iteration of the inner for loop
* 
* 10: define GetAverageScore: declare a double variable "sum" and initialize it to 
*    zero; using a nested for loop, iterate over each player in the outer loop and
*    iterate over each player's score in the inner for loop. within the inner for 
*    loop, increment "sum" with each iteration; after the inner for loop, divide
*    "sum" by "scoresCount" and assign it to the corresponding index of 
*    "averageScore" and then set "sum" back to zero
* 
* 11: define PrettyPrintResults: use a nested for loop to print result; outer for
*     loop should print names before inner for loop and average score after inner
*     for loop; the inner for loop should iterate over each player's scores and 
*     print them
* 
* 12: define PrintTitle: use a series of cout statements to print to screen the 
*     program's title; each line will be part of a multiline ascii-art text
* 
* 13: define ScrollTitle: use the "thread" function "this_thread::sleep_for()"
*     along with the "chrono" function "milliseconds()" to pause the program;
*     the delay in program execution followed by a call to the "iomanip" function
*     "system("cls") followed by a called to cout will produce an animation effect;
*     use this to print bottom line from PrintTitle, and then after pausing and 
*     clearing the screen, print the bottom line from PrintTitle and the next line;
*     each subsequent cout statement after pausing and clearing the screen should
*     print one extra line from PrintTitle till the top line has been printed, which
*     will produce a scrolling effect in the program's title sequence
* 
* 14: define TitleSequence: create an animation for title sequence; for the initial 
*     image, use ascii art from the ASCII Art Archives, and then modify the art to 
*     produce each subsequent image for the animation. The animation effect uses the 
*     same idea as Step 12, in which the thread and chrono functions are used in 
*     conjuction with the iomanip function to clear the screen
* 
* *********************************within main*********************************** 
* 15: call functions at the appropriate places with main
* 
*******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

//Step 1
const int playerCount = 10;
const int scoresCount = 4;

//Step 2
void GetBowlingData(string filename,const int playerCount, const int scoresCount, string names[], int scores[][::scoresCount]);
void GetAverageScore(const int playerCount, const int scoresCount, int scores[][::scoresCount], double averageScore[]);
void PrintTitle();
void ScrollTitle();
void PrettyPrintResults(const int playerCount, const int scoresCount, string names[], int scores[][::scoresCount], double averageScore[]);
void TitleSequence();

//Step 3
int main(int argc, char* argv[])
{
	//Step 4
	string names[playerCount];
	int scores[playerCount][scoresCount];
	double averageScore[playerCount];

	//Step 5
	ifstream infile;
	string filename = " ";
	string filenameExt = ".txt";

	//Step 6
	if (argc > 1)
		filename = argv[1];
	else
	{
		cout << "Initial image of bowling stick figure by Joan G. Stark." << endl;
		system("pause");
		system("cls");
		cout << "Enter the name of the text file: ";
		cin >> filename;
	}

	//Step 7
	if (filename.find(".txt") == string::npos)
	{
		cout << "No extension. Appending .txt extension..." << endl;
		system("pause");
		system("cls");
		filename = filename + filenameExt;
	}

	infile.open(filename);
	//Step 8
	if (infile)
		{
			infile.close();

			//Step 15
			ScrollTitle();
			TitleSequence();
			system("pause");
			system("cls");
			PrintTitle();
			GetBowlingData(filename, playerCount, scoresCount, names, scores);
			GetAverageScore(playerCount, scoresCount, scores, averageScore);
			PrettyPrintResults(playerCount,scoresCount, names, scores, averageScore);
			system("pause");
		}

	else
		{
			infile.close();
			std::cout << "Error encountered opening file. Check file name and file directory." << endl;
			std::system("pause");
		}

	
	return 0;
}

//Step 9
void GetBowlingData(string filename, const int playerCount, const int scoresCount, string names[], int scores[][::scoresCount])
{
	

	ifstream infile;
	infile.open(filename);
	

	string readName = "";
	int readScore = 0;

	

	for (int name = 0; name < playerCount; name++)
	{
		infile >> readName;
		names[name] = readName;

		for (int file_score = 0; file_score < scoresCount; file_score++)
		{
			infile >> readScore;
			scores[name][file_score] = readScore;
		}
		
	}

	

}

//Step 10
void GetAverageScore(const int playerCount, const int scoresCount, int scores[][::scoresCount], double averageScore[])
{
	double sum = 0.0;

	for (int i = 0; i < playerCount; i++)
	{
		for (int j = 0; j < scoresCount; j++)
			sum = sum + scores[i][j];

		averageScore[i] = sum / scoresCount;//because sum is a double, this statement yields floating-point division
		sum = 0.0;
	}
		
}

//Step 12
void PrintTitle()
{
	cout << setw(98) << setfill('=') << ' ' << setfill(' ') << endl;
	cout << "      ____                   _  _                    _____                                  " << endl;
	cout << "     |  _ \\                 | |(_)                  / ____|                                 " << endl;
	cout << "     | |_) |  ___ __      __| | _  _ __    __ _    | (___    ___   ___   _ __   ___   ___   " << endl;
	cout << "     |  _ <  / _ \\\\ \\ /\\ / /| || || '_ \\  / _` |    \\___ \\  / __| / _ \\ | '__| / _ \\ / __|" << endl;
	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;
}

//Step 13
void ScrollTitle()
{
	int sleepTime = 150;

	//print the bottom line of the title
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));//pauses program for 150 milliseconds
	system("cls");//clears screen; 
	/*When program is paused briefly and then the screen is cleared and updated with the next image, it produces the illusion
	 of movement*/


	//Now the bottom line and the next line up are printed
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	//now the bottom line and the next two lines up are printed
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");


	//and the sequence continues, adding a new line every time, till all ten lines are printed and the title appears to scroll down
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	cout << "     |  _ <  / _ \\\\ \\ /\\ / /| || || '_ \\  / _` |    \\___ \\  / __| / _ \\ | '__| / _ \\ / __|" << endl;
	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	
	cout << "     | |_) |  ___ __      __| | _  _ __    __ _    | (___    ___   ___   _ __   ___   ___   " << endl;
	cout << "     |  _ <  / _ \\\\ \\ /\\ / /| || || '_ \\  / _` |    \\___ \\  / __| / _ \\ | '__| / _ \\ / __|" << endl;
	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	
	
	cout << "     |  _ \\                 | |(_)                  / ____|                                 " << endl;
	cout << "     | |_) |  ___ __      __| | _  _ __    __ _    | (___    ___   ___   _ __   ___   ___   " << endl;
	cout << "     |  _ <  / _ \\\\ \\ /\\ / /| || || '_ \\  / _` |    \\___ \\  / __| / _ \\ | '__| / _ \\ / __|" << endl;
	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	
	cout << "      ____                   _  _                    _____                                  " << endl;
	cout << "     |  _ \\                 | |(_)                  / ____|                                 " << endl;
	cout << "     | |_) |  ___ __      __| | _  _ __    __ _    | (___    ___   ___   _ __   ___   ___   " << endl;
	cout << "     |  _ <  / _ \\\\ \\ /\\ / /| || || '_ \\  / _` |    \\___ \\  / __| / _ \\ | '__| / _ \\ / __|" << endl;
	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	cout << setw(98) << setfill('=') << ' ' << setfill(' ') << endl;
	cout << "      ____                   _  _                    _____                                  " << endl;
	cout << "     |  _ \\                 | |(_)                  / ____|                                 " << endl;
	cout << "     | |_) |  ___ __      __| | _  _ __    __ _    | (___    ___   ___   _ __   ___   ___   " << endl;
	cout << "     |  _ <  / _ \\\\ \\ /\\ / /| || || '_ \\  / _` |    \\___ \\  / __| / _ \\ | '__| / _ \\ / __|" << endl;
	cout << "     | |_) || (_) |\\ V  V / | || || | | || (_| |    ____) || (__ | (_) || |   |  __/ \\__ \\" << endl;
	cout << "     |____/  \\___/  \\_/\\_/  |_||_||_| |_| \\__, |   |_____/  \\___| \\___/ |_|    \\___| |___/  " << endl;
	cout << "                                           __/ |                                            " << endl;
	cout << "                                          |___/                                             " << endl;
	cout << setw(98) << setfill('=') << ' ' << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");
	


}

//Step 11
void PrettyPrintResults(const int playerCount, const int scoresCount, string names[], int scores[][::scoresCount], double averageScore[])
{
	int rowWidth = 97;
	int cellWidth = 15;

	cout << fixed << setprecision(2) << showpoint;
	cout << setw(rowWidth) << setfill('=') << '=' << setfill(' ') << endl;

	cout << setw(1) << '|' << setw(cellWidth) << "Name" << setw(1) << '|'
		<< setw(cellWidth) << "Score 1" << setw(1) << '|' << setw(cellWidth) << "Score 2"
		<< setw(1) << '|' << setw(cellWidth) << "Score 3" << setw(1) << '|' << setw(cellWidth)
		<< "Score 4" << setw(1) << '|' << setw(cellWidth) << "Average Score" << setw(1) << '|' << endl;

	cout << setw(rowWidth) << setfill('=') << '=' << setfill(' ') << endl;

	for (int i = 0; i < playerCount; i++)
	{

		cout << setw(1) << '|' << setw(cellWidth) << names[i] << setw(1) << '|';;

		for (int j = 0; j < scoresCount; j++)
			cout << setw(cellWidth) << scores[i][j] << setw(1) << '|';
		
		cout << setw(cellWidth) << averageScore[i] << setw(1) << "|" << endl;
		cout << setw(rowWidth) << setfill('=') << '=' << setfill(' ') << endl;
	}
	

}

//Step 14
void TitleSequence()
{
	int sleepTime = 150;

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\      __ " << endl;
	cout << "           /  \\____/  \\ " << endl;
	cout << "          |\\       \\__/ " << endl;
	cout << "          | \\                                                  ((()" << endl;
	cout << "         /   /                                                 ///\\" << endl;
	cout << "________/___/__________________________________________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\         " << endl;
	cout << "           /  \\____   __" << endl;
	cout << "          |\\         /  \\" << endl;
	cout << "          | \\        \\__/                                      ((()" << endl;
	cout << "         /   /                                                 ///\\" << endl;
	cout << "________/___/__________________________________________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();
	

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\         " << endl;
	cout << "           /  \\____     " << endl;
	cout << "          |\\             __" << endl;
	cout << "          | \\           /  \\                                   ((()" << endl;
	cout << "         /   /          \\__/                                   ///\\" << endl;
	cout << "________/___/__________________________________________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                __                                ((()" << endl;
	cout << "         /   /         -=   /  \\                               ///\\" << endl;
	cout << "________/___/_______-=______\\__/_______________________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                     __                           ((()" << endl;
	cout << "         /   /           -=      /  \\                          ///\\" << endl;
	cout << "________/___/_______________-=___\\__/__________________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                          __                      ((()" << endl;
	cout << "         /   /                   -=   /  \\                     ///\\" << endl;
	cout << "________/___/_________________-=______\\__/_____________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                               __                 ((()" << endl;
	cout << "         /   /                     -=      /  \\                ///\\" << endl;
	cout << "________/___/_________________________-=___\\__/________________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                                    __            ((()" << endl;
	cout << "         /   /                             -=   /  \\           ///\\" << endl;
	cout << "________/___/___________________________-=______\\__/___________\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                                         __       ((()" << endl;
	cout << "         /   /                               -=      /  \\      ///\\" << endl;
	cout << "________/___/___________________________________-=___\\__/______\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                                              __  ((()" << endl;
	cout << "         /   /                                       -=   /  \\ ///\\" << endl;
	cout << "________/___/_____________________________________-=______\\__/_\\\\\\/" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();


	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                                                  *''*" << endl;
	cout << "         /   /                                                *_\\/_* " << endl;
	cout << "________/___/_________________________________________________* /\\ *" << endl;
	cout << "                                                               *..*     " << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                                                  .''." << endl;
	cout << "         /   /                                                :_\\/_:" << endl;
	cout << "________/___/_________________________________________________: /\\ :" << endl;
	cout << "                                                               '..'     " << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

	PrintTitle();

	cout << "            .-." << endl;
	cout << "           /   \\" << endl;
	cout << "        ___\\___/" << endl;
	cout << "       \\    /\\" << endl;
	cout << "           /  \\____" << endl;
	cout << "          |\\" << endl;
	cout << "          | \\                                                .'.:.'." << endl;
	cout << "         /   /                                               -=:o:=-" << endl;
	cout << "________/___/________________________________________________'.':'.'" << endl;

	this_thread::sleep_for(chrono::milliseconds(sleepTime));
	system("cls");

}








	


		                



       

