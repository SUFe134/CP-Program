class SavingsAccount(double balance){

    private: double savingsBalance; static double annualInterestRate;

    public: SavingsAccount(double balance){ savingsBalance = balance; } void calculateMonthlyInterest(){

        savingsBalance += (savingsBalance * annualInterestRate) / 12;

    }
    static void modifyInterestRate(double newRate){

        annualInterestRate = newRate;

    }
    double getBalance() const{
        return savingsBalance;

    }
    }

    int main() { double A, B; int N;
        cin >> A >> B >> N; // Create two accounts SavingsAccount saver1(A), saver2(B); for (int i = 0; i < N; i++) { double rate; cin >> rate; // Set new annual interest rate SavingsAccount::modifyInterestRate(rate); // Calculate interest saver1.calculateMonthlyInterest(); saver2.calculateMonthlyInterest();

        // Output the current balance, rounded to two decimal places
        cout << fixed << setprecision(2) << saver1.getBalance() << " " << saver2.getBalance() << endl;
    }

    return 0;
    }