
#include <iostream>
using namespace std;
#include <conio.h>

#include <string>
#include <cstring>
#include <windows.h> 
#include <iomanip> 

//constants
char A_TO_Z_EXCERSISE_STR[] = "abcdefghijklmnopqrstuvwxyz.,";



//universal functions
void screenCleaner() {
	system("cls");
}

void loadFiles() {
	//loads .DAT file it stores statistics
}

void mainMenu() {
	cout << "***MAIN MENU***" << endl;
	cout << "<1> Play" << endl;
	cout << "<2> Statistics" << endl;
	cout << "<3> About" << endl;
	cout << "<4> Quit" << endl;
;
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
	//A_TO_Z_EXCERSISE_STR

	screenCleaner();
	
	HANDLE hConsole;
	int k;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	int index = 0;
	char user_input;
	int reverse_text = 0;

	char new_string[29] = "abcdefghijklmnopqrstuvwxyz.,";
	char reverse[29] = ",.zyxwvutsrqponmlkjihgfedcba";
	char current_practise_string[29];

	strncpy(current_practise_string, new_string, 29);

	cout << "Type '!' to exit"<< endl;
	cout << new_string << "\n";

	string user_string{""};

	float correct_letter = 0.0;
	float mistakes = 0.0;
	float total_lenght = 0.0;

	while (true)
	{
		user_input = char(_getch());
		//only accept characters from set number to set number and no backspace or related
		//timer
		//add sleep where nothing happens for a few second after stats are shown.

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
		if (index == 28) {
			//every 3 time it reverse it 
			screenCleaner();

			user_string.clear();
			index = 0;
			reverse_text++;

			if (reverse_text == 1) { //debug logic
				strncpy(current_practise_string, reverse, 29);
				//reverse_text = 0;

				//ending (before timer implementation)
				float total_lenght = mistakes + correct_letter;
				

				cout << "lenght " << total_lenght <<endl;
				cout << "mistakes " << mistakes << endl;
				cout << "correct  " << correct_letter << endl;

				
				float WPM = total_lenght/ 5 / 0.5;
				float accuracy = ((total_lenght - mistakes) / total_lenght) * 100;
				cout << std::fixed << setprecision(2) << "WPM: " << WPM << endl;
				cout << "Accuracy: " << accuracy;
				return;
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
			break;
		case 50://2
			//stats
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
		default:
			break;
		}
	}
}