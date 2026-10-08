import java.util.Scanner;

public class AccountManagement {

    private int Accno;
    private String name;
    private long Phone_no;
    private float balance;

    public void createAccount() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your name: ");
        name = sc.nextLine();

        System.out.print("Enter your account number: ");
        Accno = sc.nextInt();

        System.out.print("Enter your balance amount: ");
        balance = sc.nextFloat();

        System.out.print("Enter your phone number: ");
        Phone_no = sc.nextLong();
    }

    public void deposit(float deposit_amount) {
        balance += deposit_amount;
        System.out.println(deposit_amount + " is deposited to your account.");
        System.out.println("Current balance: " + balance);
    }

    public void withdraw(float withdraw_amount) {
        if (withdraw_amount <= balance) {
            balance -= withdraw_amount;
            System.out.println(withdraw_amount + " is withdrawn from your account.");
            System.out.println("Current balance: " + balance);
        } else {
            System.out.println("You cannot withdraw because your balance is low: " + balance);
        }
    }

    public void printAccount() {
        System.out.println("\nAccount details:");
        System.out.println("Name: " + name);
        System.out.println("Account number: " + Accno);
        System.out.println("Balance amount: " + balance);
        System.out.println("Phone: " + Phone_no);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        AccountManagement account = new AccountManagement();

        account.createAccount();

        while (true) {
            System.out.println("\n--- Menu ---");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Print Account Details");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");

            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to deposit: ");
                    float depositAmount = sc.nextFloat();
                    account.deposit(depositAmount);
                    break;

                case 2:
                    System.out.print("Enter amount to withdraw: ");
                    float withdrawAmount = sc.nextFloat();
                    account.withdraw(withdrawAmount);
                    break;

                case 3:
                    account.printAccount();
                    break;

                case 4:
                    System.out.println("Exiting... Thank you!");
                    sc.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid option, please try again.");
                    break;
            }
        }
    }
  }
