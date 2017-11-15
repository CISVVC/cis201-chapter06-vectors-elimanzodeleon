/*
/ file: main.cpp
/ developer: elias manzo-de leon
/ email: manzoe@student.vvc.edu
/ description: this program will allow a user to enter transactions(purchases/withdrawals and deposits) and will output a statement will all transactions, interest earned and daily balance
*/

#include<iostream>
#include<vector>
#include<string>

class Transaction {
	public:
		Transaction();
		void read();
		int get_day();
		double get_amount();	
		void print() const;
	private:
		int day;
		double amount;
		double balance;
		double interest_amt;
		std::string description;
};

Transaction::Transaction() {
	day = 0;
	amount = 0.0;
}

void Transaction::read() {
	std::cout << "day: ";
	std::cin >> day;
	std::cout << "amount: ";
	std::cin >> amount;
	std::cin.ignore();
	std::cout << "description: ";
	std::getline(std::cin,description);
	balance += amount;
	interest_amt += (balance * 0.005);
}
	
void Transaction::print() const {
	std::cout << "day " << day;
	std::cout << "\tamount " << amount;
	std::cout << "\tdescription " << description;
	std::cout << "\tbalance " << balance; 
	std::cout << "\ttotal interest earned " << interest_amt << std::endl;
}

void print_transactions(const std::vector<Transaction> t) {
	for(int i=0; i<t.size(); i++) {
		t[i].print();
	}
}

int main() {
	std::vector<Transaction> transaction;
	bool more = true;

	while(more) {
		Transaction t;
		t.read();
		transaction.push_back(t);
		std::cout << "Enter another transaction? (y/n) ";
		char response;
		std::cin >> response;
		if(response != 'y' && response != 'Y') {
			more = false;
		}
	}
	print_transactions(transaction);
	return 0;
}






