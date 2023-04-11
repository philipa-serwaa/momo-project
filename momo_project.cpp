#include <iostream>
using namespace std;

float balance = 1000;
string storedpin = "0000";
string userpin;

void display_menu(){
	//display menu
	cout << endl;
	cout << "Welcome to our Mobile Money" << endl << endl;
	cout << "Main Menu" << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Manage Pin" << endl;
	cout << "3. Send Money" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
}

void check_balance(){
	int entries = 0;
	while(entries < 3){
		cout << "Enter your pin: ";
		cin >> userpin;
		if (userpin == storedpin){
			cout << "Your account balance is : GHC" << balance << endl;
			entries = 3;
		}
		else{
			cout << "Wrong pin!" << endl;
			entries++;
		}
	}
		
}

void manage_pin(){
	int option;
	cout << "1. Change Pin" << endl;
	cout << "2. Reset Pin" << endl;
	cin >> option;
	
	if(option == 1){
		//change pin
		cout << "Enter Old PIN" << endl;
		cin >> userpin;
		if(userpin == storedpin){
			cout << "Enter New PIN" << endl;
			cin >> storedpin;
			cout << "PIN change successful" << endl;
		}
		else{
			cout << "Wrong Password!" << endl;
		}
	}
	else if(option == 2){
		cout << "You are resetting your PIN to default. Press 1 to continue or 0 to cancel" << endl;
		cin >> option;
		if(option == 1){
			storedpin = "0000";
			cout << "PIN reset successful" << endl;
		}
		else if (option == 0){
			cout << "PIN reset cancelled" << endl;
		}
		else{
			cout << "Invalid Entry" << endl;
		}
	}
	else{
		cout << "Invalid Entry" << endl;
	}
	
}

void send_money(){
	string number, number2;
	float amount;
	cout << "Enter receiver number" << endl;
	cin >> number;
	cout << "Confirm number" << endl;
	cin >> number2;
	if(number == number2){
		// matching numbers...proceed with transaction
		cout << "Enter amount" << endl;
		cin >> amount;
		if(amount > balance){
			cout << "Insufficient Balance" << endl;
		}
		else{
			//loop pin entry
			int entries = 0;
			while(entries < 3){
				cout << "You are transferring GHC" << amount << " to " << number << ". Enter your PIN to confirm." << endl;
				cin >> userpin;
				if(userpin == storedpin){
					balance = balance - amount;
					cout << "You have transferred GHC" << amount << " to " << number << " Your new balance is GHC" << balance << endl;
					entries = 3;
				} 
				else{
					cout << "Incorrect PIN!" << endl;
					entries++;
				}
			}
			
		}
	}
	else{
		//mismatching numbers...halt transaction
		cout << "The numbers you have provided do not match. Please check and try again." << endl;
	}
	
}
int main() {
	bool run = true;
	
	while(run == true){
		//display main menu
		display_menu();
	
		int option;	
		cin >> option;
		if (option == 1){
			//check Balance	
			check_balance();
		}
		else if(option == 2){
			//manage pin
			manage_pin();
	
		}
		else if(option == 3){
			//send money
			send_money();
		}
		else if(option == 0){
			// end program
			cout << "Thank you for using our service." << endl << "Goodbye!" <<endl;
			run = false;
		}
		else{
			//wrong option
			cout << "Wrong input, try again." << endl;
		}
	}

	return 0;
}



