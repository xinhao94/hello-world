#include <iostream>
#include <vector>
using namespace std;

class BankAccount{
    private:
        static unsigned long nextAccountNumber;
        unsigned long accountNumber;
        double balance;
    public:
        unsigned long getAccountNumber() const{
            return accountNumber;
        }
        void deposit(double amount){
            balance += amount;
        }
        double withdraw(double desiredAmount){
            if(desiredAmount <= balance){
                balance -= desiredAmount;
                return desiredAmount;
            }
            else{
                double actualAmount = balance;
                balance = 0;
                return actualAmount;
            }
        }
        double getBalance() const{
            return balance;
        }
        // Constructor without parameter
        BankAccount(): balance(0), accountNumber(nextAccountNumber){
            cout<<"Account No. "<<accountNumber<<" was created!"<<endl;
            nextAccountNumber++;
        }
        // Constructor with parameter
        explicit BankAccount(double initBalance): balance(initBalance), accountNumber(nextAccountNumber){
            cout<<"Account No. "<<accountNumber<<" was created!"<<endl;
            nextAccountNumber++;
        }
};
unsigned long BankAccount::nextAccountNumber = 0;

int main(){
    size_t length = 10;
    vector<BankAccount> accountVec(length);
    return EXIT_SUCCESS;
}
