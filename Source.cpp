
#include <iostream>

using namespace std;
#include <conio.h>

#include <fstream>
#include <string>
#include <cstring>
#include <windows.h> 
#include <iomanip> 



#include <chrono>
using namespace std::chrono;
#include <iostream>
#include <future>

//constants
char A_TO_Z_EXCERSISE_STR[] = "abcdefghijklmnopqrstuvwxyz.,";

int timer_finished = 0;

bool fntimer() {
	int seconds = 10; //DEBUG VALUE
	for (int i = 0; i < seconds; ++i)
	{
		//cout << i << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	timer_finished = 1;
	return true;
}



//universal functions
void screenCleaner() {
	system("cls");
}

void writeStatInFile() {
	//loads .DAT file it stores statistics

	ofstream stats("stats.dat");

	cout << "kdl 50 87";
	
	stats.close();
}

//Showing Stats
void separateStringFromStats(string stat) {
	vector<string> res;
	int pos = 0;

	while (pos < stat.size()) {
		pos = stat.find(" ");
		
		res.push_back(stat.substr(0, pos));
		
		stat.erase(0, pos + 1);	
	}
	//TODO fix the loop to not skip the last one
	//it skips the last one 
	res.push_back(stat);

	cout << res[0] << "		";
	cout << res[1] << "	";
	cout << res[2] << "%" << endl;




}

void readFileAndDisplay() {
	string myText;

	ifstream stats("stats.dat");

	screenCleaner();

	cout << "Initials	";
	cout << "WPM	";
	cout << "Accuracy" << endl;


	while (getline(stats, myText)) {
		 separateStringFromStats(myText);
	}

	stats.close();
}



void mainMenu() {
	cout << "***MAIN MENU***" << endl;
	cout << "<1> Play" << endl;
	cout << "<2> Statistics" << endl;
	cout << "<3> About" << endl;
	cout << "<4> Quit" << endl;
;
}



void display_stats_end_game(float correct, float mistakes) {
	//TODO WPM TO USE TIME(60 sec)

	float total_lenght = correct + mistakes;
	cout << "lenght " << total_lenght << endl;
	cout << "mistakes " << mistakes << endl;
	cout << "correct  " << correct << endl;

	// 1 - minute
	// 5 - by formula
	float WPM = (total_lenght / 5 ) / 1; 
	float accuracy = ((total_lenght - mistakes) / total_lenght) * 100;
	cout << std::fixed << setprecision(2) << "WPM: " << WPM << endl;
	cout << "Accuracy: " << accuracy;
}

void createUser() {
	//creating user
}

int listLesson() {
	//shows the list of lessons available
	return 0;
}

void beginSession() {
	//start session
}


//  <1> SELECT USER 
int userSelectMenu() {
	// It is for selecting the name of users 
	//which are already defined in the source code.
	return 0;
}

int listUser() {
	//lists the users in the .DAT file
	return 0;
}

// <2> STATISTICS
void statistics() {

}

// <3> VIEW USER RECORDS
void user_records() {

}

// <4> ABOUT
void about() {
	screenCleaner();
	cout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer suscipit suscipit velit, vel ultrices elit varius in. Aenean consectetur urna vitae fermentum faucibus. Fusce sagittis euismod ex, vitae rhoncus mauris interdum vel. Integer non ipsum et velit dignissim dignissim et at dui. Phasellus commodo augue sit amet felis dignissim, at lacinia diam fermentum. Suspendisse malesuada ut lacus vitae pretium. Mauris vitae augue nunc. In lorem nisl, feugiat vel mi nec, mollis aliquam nisl. Vestibulum justo arcu, ultricies at pretium ac, pellentesque vitae ipsum. Cras id nisl vel libero aliquet gravida. Curabitur ut elit ullamcorper, vehicula nisl placerat, mattis sapien." << endl;
	cout << "Press any button to go back to the menu ..." << endl;
	_getch();
	screenCleaner();
	mainMenu();
}
// <5> QUIT
void quit() {

}

void a_to_z() {
	//abcdefghijklmnopqrstuvwxyz., #space or enter#
	// is reversed every 3 times

	screenCleaner();
	
	HANDLE hConsole;
	int k;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	int index = 0;
	char user_input;
	int reverse_text = 0;

	//swtiche between them every 3 times they are completed
	char new_string[29] = "abcdefghijklmnopqrstuvwxyz.,";
	char reverse[29] = ",.zyxwvutsrqponmlkjihgfedcba";
	char current_practise_string[29];

	strncpy(current_practise_string, new_string, 29);

	cout << "Type '!' to exit"<< endl;
	cout << new_string << "\n";

	string user_string{""};

	float correct_letter = 0.0;
	float mistakes = 0.0;
	
	auto r = std::async(std::launch::async, fntimer);
	
		
	while (true)
	{	

	

		if (timer_finished == 1) {
			cout << "\nGame over" << endl;
			display_stats_end_game(correct_letter, mistakes);
			Sleep(2);
			
			cout << "Do you want to save the score";
			while (true) {
				user_input = char(_getch());

				cout << user_input;
				if (user_input == 'y') {
					cout << "It works";
				}
			}
		

			break;
		}


		
		//only accept characters from set number to set number and no backspace or related
		user_input = char(_getch());

		if (user_input == current_practise_string[index]) {

			user_string += user_input;

			k = 2;//green
			SetConsoleTextAttribute(hConsole, k);
			cout << user_string[index];
			correct_letter++;
		}

		else if (user_input == '!') {
			screenCleaner();
			mainMenu();
			return;
		}

		else {
			user_string += user_input;

			k = 4;//red
			SetConsoleTextAttribute(hConsole, k);
			cout << user_string[index];

			mistakes++;
		}


		user_input = NULL;
		index++;
		k = 15;//white
		SetConsoleTextAttribute(hConsole, k);


		//RESET GAME
		if (index == 28) { // DEBUG change to array.lenght
			//every 3 time it reverse it 
			screenCleaner();

			user_string.clear();
			index = 0;
			reverse_text++;

			if (reverse_text == 1) { //debug logic
				strncpy(current_practise_string, reverse, 29);
				reverse_text = 0;
			}
			cout << "Type '!' to exit" << endl;
			cout << current_practise_string << endl;

			}
	}

}


int main() {
	int user_input;
	mainMenu();
	while (true) {
		

		user_input = _getch();

		switch (user_input)
		{
		case 49://1
			//start game
			a_to_z();
			cout << "MAIN MENU" << endl;
			break;
		case 50://2
			//stats
			readFileAndDisplay();
			break;
		case 51://3
			//about
			about();
			break;
		case 52://4
			//quit
			cout << "Thank you for playing ";
			return 0;
			break;
		case 53://5 DEBUG MENU TESTING FUNCTIONS
			//loadFile();
			//readFile();
			break;
		default:
			break;
		}
	}
}