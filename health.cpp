#include <iostream>
#include <fstream>
#include <string> 

using namespace std; 

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class User {
    private:
        int age, weight, height;
        string gender;
        double bmi, bmr;
        int calories;
        
        double calculateBmi() {
            return (weight * 703.0) / (height * height);
        }
        
        double calculateBmr() {
            if (gender == "M") {
                return 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
            } else {
                return 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
            }
        }
        
        int calculateCalories() {
            return bmr * 1.2;
        }
        
    public:
        void setUserDetails(int a, int w, int h, string g) {
            age = a;
            weight = w;
            height = h;
            gender = g;
            bmi = calculateBmi();
            bmr = calculateBmr();
            calories = calculateCalories();
        }
        
        void displayUserDetails() {
            cout << "Age: " << age << endl;
            cout << "Weight: " << weight << " pounds" << endl;
            cout << "Height: " << height << " inches" << endl;
            cout << "Gender: " << gender << endl;
            cout << "BMI: " << fixed << setprecision(2) << bmi << endl;
            cout << "BMR: " << fixed << setprecision(2) << bmr << endl;
            cout << "Recommended Daily Calorie Intake: " << calories << " calories" << endl;
        }
        
        void recommendExercise() {
            srand(time(NULL));
            int minutes = rand() % 60 + 30;
            cout << "Your recommended exercise program for today is:" << endl;
            cout << "- Jogging or brisk walking for " << minutes << " minutes" << endl;
            cout << "- 3 sets of push-ups (10 reps each)" << endl;
            cout << "- 3 sets of squats (10 reps each)" << endl;
            cout << "- 3 sets of lunges (10 reps each)" << endl;
            cout << "- Stretching for 5 minutes" << endl;
        }
};
//Select whether you would like to register or login
//IF you select login brings your username and password 
//If you get password wrong say "Incorrect password try again" and "3-1 attempts remaining"
//If you get it right then take them to their credentials 
//if they wanna select to register than allow them to 


    bool isLoggedIn ()
    {
        string username , password, un , pw ;

        cout << "Enter Username: "; cin >> username;
        cout << "Enter Password: "; cin >> password;

        ifstream read("data\\" + username + ".txt");
        getline(read, un);
        getline(read, pw);

        if(un == username && pw == password)
        {
            return true ; 
        }
        else
        {
            return false; 
        }
    }


int main()
{
    system("clear");

    int choice;

    cout << "1) Register\n2: Login\nYour Choice: ";
    cin >> choice; 
    
    if(choice == 1)
    {
        system("clear");

        string username, password; 

        cout << "Select a Username: ";
        cin >> username;
        cout << "Select a Password: ";
        cin >> password;

        system("clear");

        ofstream file;
        file.open ("data\\" + username + ".txt"); 
        file << username << endl << password;
        file.close();


        main();

    }
    else if (choice == 2)
    {
        bool status = isLoggedIn(); 

        if(!status)
        {
            cout << "False Login" << endl; 
            
            return 0; 

        }
        else
        {
            cout << "Successfully Logged in !" << endl; 
            system("CLEAR");

                // Set up variables for user input
    int age, weight, height;
    string gender;
    cout << "Welcome to the Healthy Habits app! Let's get started." << endl;
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter your weight (in pounds): ";
    cin >> weight;
    cout << "Please enter your height (in inches): ";
    cin >> height;
    cout << "Please enter your gender (M/F): ";
    cin >> gender;
    
    User user;
    user.setUserDetails(age, weight, height, gender);
    
    // Display user details
    cout << endl << "Your details are:" << endl;
    user.displayUserDetails();
    
    // Recommend exercise program
    cout << endl;
    user.recommendExercise();
    
    // Encourage healthy habits
    cout << endl << "Remember to stay hydrated, get enough sleep, and eat a balanced diet." << endl;
    cout << "Good luck on your health journey!" << endl;

    return 0;
}

        }
    }
    
