#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount{
    private:
        static unsigned long nextAccountNumber;
        unsigned long accountNumber;
        double balance;
        double interestRate;
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
            cout<<"BankAccount No. "<<accountNumber<<" was created!"<<endl;
            nextAccountNumber++;
        }
        // Constructor with parameter
        explicit BankAccount(double initBalance): balance(initBalance), accountNumber(nextAccountNumber){
            cout<<"BankAccount No. "<<accountNumber<<" was created!"<<endl;
            nextAccountNumber++;
        }
        // Since polymorphism is utilized, the destructor should be declared as virtual
        virtual ~BankAccount(){}
        void accrueInterest(double fractionOfYear){
            balance += balance * interestRate * fractionOfYear; 
        }
};
unsigned long BankAccount::nextAccountNumber = 1;

class Stock{
    private:
        string name;
        double price;
    public:
        double getStockPrice() const{
            return price;
        }
        string getStockName() const{
            return name;
        }
};

class InvestmentAccount : public BankAccount{
    private:
        vector<pair<Stock *, double> > stocks;
        unsigned tradesThisMonth;
    public:
        // Constructor without parameter
        InvestmentAccount() : tradesThisMonth(0){
            cout<<"InvestmentAccount No. "<<getAccountNumber()<<" was created!"<<endl;
        }
        // Constructor with parameter
        explicit InvestmentAccount(double balance) : BankAccount(balance), tradesThisMonth(0){
            cout<<"InvestmentAccount No. "<<getAccountNumber()<<" was created!"<<endl;
        }
        // Since polymorphism is utilized, the destructor should be declared as virtual
        virtual ~InvestmentAccount(){}
        unsigned getTradesThisMonth() const{
            return tradesThisMonth;
        }
        // This overridden method will be dynamically despatched by declaring as "virtual"
        virtual bool buyStock(Stock * s, double numShares){
            double cost = getCost(s) * numShares;
            double balance = getBalance();
            if(cost<=balance){
                balance -= cost;
                tradesThisMonth += 1;
                return true;
            }
            else{
                return false;
            }
        }
        void sellStock(Stock * s, double numShares);
        double getMarketValue() const;
        double getCost(Stock * s) const{
            return s->getStockPrice();
        }
};

class MarginAccount : public InvestmentAccount{
    private:
        double marginLimit;
        double marginUsed;
    public:
        // Constructor without parameter
        MarginAccount() : marginLimit(5000.0), marginUsed(0){
            cout<<"MarginAccount No. "<<getAccountNumber()<<" was created!"<<endl;
        }
        // Constructor with parameter
        MarginAccount(double balance, double margin) : InvestmentAccount(balance), 
                                            marginLimit(margin), marginUsed(0){
            cout<<"MarginAccount No. "<<getAccountNumber()<<" was created!"<<endl;
        }
        // This overridden method will be dynamically despatched by declaring as "virtual"
        virtual bool buyStock(Stock * s, double numShares){
            double cost = getCost(s) * numShares;
            double borrowAmount = 0;
            double balance = getBalance();
            if(balance < cost){
                borrowAmount = cost - balance;
                if(marginUsed+borrowAmount < marginLimit){
                    balance += borrowAmount;
                    marginUsed -= borrowAmount;
                }
                else{
                    return false;
                }
            }
            // In order to use method of parent class, fully qualified name
            // need to be used.
            if(InvestmentAccount::buyStock(s, numShares)){
                return true;
            }
            else{
                balance -= borrowAmount;
                marginUsed -= borrowAmount;
                return false;
            }
        }
        void sellStock(Stock whichStock, double numShares);
};

class Bank{
    private:
        vector<BankAccount *> allAccounts;
    public:
        InvestmentAccount * createInvestmentAccount(double balance){
            InvestmentAccount * newAccount = new InvestmentAccount(balance);
            // Subtype polymorphism is utilized here
            // Yet it can only be utilized via pointers/references
            allAccounts.push_back(newAccount);
            return newAccount;
        }
        void accrueInterestOnAllAccounts(double fractionOfYear){
            vector<BankAccount *>::iterator it = allAccounts.begin();
            while(it != allAccounts.end()){
                BankAccount * currentAccount = *it;
                // Use of polymorphism here: all elements share this method
                // in spite of their actual account type
                currentAccount->accrueInterest(fractionOfYear);
                ++it;
            }
        }
};

int main(){
    size_t length = 3;
    vector<BankAccount> bankVec(length);
    vector<InvestmentAccount> investVec(length);
    vector<MarginAccount> marginVec(length);
    Bank obj;
    obj.createInvestmentAccount(100);
    return EXIT_SUCCESS;
}
