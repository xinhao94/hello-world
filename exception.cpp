#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

// Customized exception class should publicly inherent class exception
// or one of its child classes
class InsufficientFunds : public exception{
    private:
        unsigned accountNumber;
    public:
        explicit InsufficientFunds(unsigned num) : accountNumber(num){}
        unsigned getAccountNumber(void) const{
            return accountNumber;
        }
        // The "what" method should be overridden
        virtual const char * what() const throw(){
            return "The requested account does not have enough fund.";
        }
};

class InvalidAccountNumber : public exception{
    private:
        unsigned accountNumber;
    public:
        explicit InvalidAccountNumber(unsigned num) : accountNumber(num){}
        unsigned getAccountNumber(void) const{
            return accountNumber;
        }
        // The "what" method should be overridden
        virtual const char * what() const throw(){
            return "The requested account number is invalid.";
        }
};

class Check{
    private:
        unsigned accountNumber;
        double amount;
        bool isCashed;
    public:
        Check() : accountNumber(0), amount(0), isCashed(false){}
        Check(unsigned actNum, double amt): accountNumber(actNum), amount(amt), isCashed(false){}
        unsigned getAccountNumber(void) const{
            return accountNumber;
        }
        double getAmount(void) const{
            return amount;
        }
        void markAsCashed(void){
            isCashed = true;
            amount = 0;
        }
        void refectForFunds(void){
            amount = 0;
        }
};

class BankAccount{
    private:
        static vector<BankAccount *> allAccounts;
        static unsigned nextAccountNumber;
        unsigned accountNumber;
        double balance;
    public:
        // Constructor without parameter
        BankAccount(): balance(0), accountNumber(nextAccountNumber){
            nextAccountNumber++;
            allAccounts.push_back(this);
        }
        // Constructor with parameter
        explicit BankAccount(double initBalance): balance(initBalance), accountNumber(nextAccountNumber){
            nextAccountNumber++;
            allAccounts.push_back(this);
        }
        unsigned long getAccountNumber() const{
            return accountNumber;
        }
        void printAllAccounts(void){
            vector<BankAccount *>::const_iterator it = allAccounts.begin();
            while(it != allAccounts.end()){
                BankAccount * currentAccount = *it;
                cout<<*currentAccount<<endl;
                ++it;
            }    
        }
        void withdraw(double amount){
            if(balance < amount){
                throw InsufficientFunds(accountNumber);
            }
            else{
                balance -= amount;
            }
        }
        vector<BankAccount *>::iterator getAccountByNumber(unsigned actNum){
            vector<BankAccount *>::iterator it = allAccounts.begin();
            while(it != allAccounts.end()){
                BankAccount * currAccount = *it;
                if(currAccount->accountNumber == actNum){
                    return it;
                }
                else{
                    ++it;
                }
            }
            return allAccounts.end();
        }
        void cashCheck(Check * c){
            unsigned actNum = c->getAccountNumber();
            vector<BankAccount *>::iterator it = getAccountByNumber(actNum);
            double amount = c->getAmount();
            try{
                if(it == allAccounts.end()){
                    throw InvalidAccountNumber(actNum);
                }
                else{
                    BankAccount * b = *it;
                    try{
                        b->withdraw(amount);
                        c->markAsCashed();
                        cout<<"Check for Account No. "<<actNum<<" is accepted!"<<endl;
                    }
                    // Use const reference to avoid copying
                    catch(const InsufficientFunds & isfE){
                        c->refectForFunds();
                        cout<<"Check for Account No. "<<isfE.getAccountNumber()<<" is rejected!"<<endl;
                        cout<<isfE.what()<<endl;
                    }
                }
            }
            // Use const reference to avoid copying
            catch(const InvalidAccountNumber & ivaE){
                cout<<"Account No. "<<ivaE.getAccountNumber()<<" is invalid!"<<endl;
                cout<<ivaE.what()<<endl;
            }
        }
        friend ostream & operator<<(ostream & os, const BankAccount & obj);
};
unsigned BankAccount::nextAccountNumber = 1;
vector<BankAccount *> BankAccount::allAccounts;
ostream & operator<<(ostream & os, const BankAccount & obj){
    os<<"Account No. "<<obj.accountNumber<<", balance: "<<obj.balance;
    return os;
}


int main(){
    BankAccount acct1(100);
    BankAccount acct2(200);
    BankAccount acct3(300);
    BankAccount acct4(400);
    BankAccount acct5(500);
    BankAccount acct6(600);
    Check ck1(4, 300);
    acct4.cashCheck(&ck1);
    Check ck2(5, 600);
    acct5.cashCheck(&ck2);
    Check ck3(7, 100);
    acct6.cashCheck(&ck3);
    return EXIT_SUCCESS;
}
