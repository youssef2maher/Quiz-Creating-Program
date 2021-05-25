

/* Youssef Maher Maher  20180350 */

/* youssefmaher.yh@gmail.com */

/* Youssef Bahgat Fekry 20180339*/



#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* This section is for design. */

//This function makes a break line.
void e(){cout<<endl;}

//This function is for making a tap;
void t() {cout<<"       ";}

//This function is for making a horizontal line.
void HorLine ()
{for (int i=0; i<55 ;i++){cout << "--";}}

/* This function prints the main  menu
 and receive the user name. */
void mainmenu(string user)
{

    e();cout<<" Welcome "<< user <<", please choose from the following questions: "<<endl;e();
    cout<<"     [1] Go to administration menu"<<endl;e();
    cout<<"     [2] Update your name"<<endl;e();
    cout<<"     [3] Start a new quiz"<<endl;e();
    cout<<"     [4] Display your scores statistics"<<endl;e();
    cout<<"     [5] Display all your scores"<<endl;e();
    cout<<"     [6] Exit"<<endl;e();
    cout << "Your choice : ";
}

//This function prints the administration menu.
void adminmenu()
{
    cout<<" Welcome to the administration menu, please choose from the following options:"<<endl;e();
    cout<<"     [1] View all questions"<<endl;e();
    cout<<"     [2] Add new question"<<endl;e();
    cout<<"     [3] Load questions from file"<<endl;e();
    cout<<"     [4] Go back to main menu"<<endl;e();
    cout << "Your Choice : ";
}

// This is a structure stores the questions.
struct Question
{
    char qus[1000]; //To hold the question.
    string ans[4]; //To hold the four choice.

};

/*This structure stores the number of correct and wrong
 answers of each quiz*/
struct Quiz
{
    int cr_ans = 0;
    int rn_ans = 0;
};


int main()
{

    srand(time(0));

    int num_qus = 0; //To count the number of questions in the array of the structure.
    int num_quz = 0; //To count the number of quizzes have been taken.
    Question point[1000]; //Array of Question structure.
    Quiz test[1000];
    string nam="USER";
    int opt;

    start:
    mainmenu(nam);
    cin >> opt; e();



    //This if displays the administration menu.
    if (opt==1){
        adminmenu();
        int opta;
        cin >> opta;



        //This if for view all questions option.
        if (opta == 1){

        /* This option displays all questions the user has. */
            do {
                e();cout << "Number of questions available : " << num_qus <<endl;e();
                cout << "Question List : " << endl;e();
                cout << "---------------" <<endl; e();

                //To announce the user about having no questions to be displayed.
                if (num_qus == 0) {

                    e();cout << "You don't have enough questions, Please add or load questions." <<endl;e();
                     cout << "Press [z] to back: ";
                     char z;    cin >> z;
                     if (z = 'z') {goto start;}
                }

                    else{

                    //Starting to display the questions.
                    int Ques_count=1;

                    for (int l = 0; l < num_qus ;l++){

                        char Choice_count = 'A';
                        cout << " [" << Ques_count << "] " << point[l].qus <<endl;e();
                        for (int k = 0; k < 4; k++) {cout << "       [" << char(Choice_count+k) << "] " << point[l].ans[k];}
                        Ques_count++;
                        e(); e();
                    }

                    cout << "The first choice is the right one." <<endl;e();

                    //Giving the user the delete option or go back to the main menu.
                    if (num_qus > 0){
                        cout << "Press [d], then a question number to delete it " <<endl;
                        cout << "Press [z] to back " <<endl;e();
                        cout << "Your Choice: ";
                        char z;  cin >> z;

                        //To check about the input the user entered.
                        while (z != 'd' && z != 'z') {cout << "Enter valid character: "; cin >> z;}

                        if (z == 'd'){
                            int del;  cin >> del;
                            while (del > num_qus) {cout << "Enter valid number: ";  cin >> del;}
                            for (int i = del-1; i < num_qus; i++){point[i] = point[i+1];}
                            num_qus--;
                        }

                        else if (z == 'z') {goto start;}
                    }

                    else {
                         cout << "Press [z] to back: ";
                         char z;    cin >> z;
                         if (z = 'z') {goto start;}
                    }
                }

            }while (true);
        }



        if (opta == 2){

                /* Here, the user can add question */

                char y;
                do {

                e();cout << "Write the question: " <<endl;e();
                cin.ignore();
                cin.getline(point[num_qus].qus, 1000);e();
                cout << "Write the four choices, considering the correct answer is the first one. " <<endl;e();
                cout << "Each question is following by [Enter button]: " <<endl;e();
                for (int m = 0; m < 4; m++) {getline (cin, point[num_qus].ans[m]);}

                num_qus++;

                e();cout << "If you want to add another question, Press [Y] " <<endl;
                cout << "If you don't, Press [N]" <<endl;e();
                cin >> y;

                }while (y == 'y' || y == 'Y');

                cout << "Press [z] to back: ";
                char z;    cin >> z;
                if (z = 'z') {goto start;}
        }



        if (opta == 3){

            /* The user can load a file of questions from here. */

            e();cout << "Enter the name of the file you want to load: ";
            char filnam[100];   cin >> filnam;

            ifstream newfil;
            newfil.open(filnam);

            //To get the questions and the choices of each question from the file.
            while(!newfil.eof()){
                int i = num_qus;
                newfil.getline(point[i].qus, 1000);
                for (int m = 0; m < 4; m++)
                    {getline (newfil, point[i].ans[m]);}
                i++;  num_qus++;
            }


            cout << "Press [z] to back: ";
            char z;    cin >> z;
            if (z = 'z') {goto start;}
        }



        if (opta == 4){
            goto start;
        }


    }



    /* This section allow the user to modify the using name in the program. */

    if (opt==2){

        cout<<"Enter your name: "<<endl;e();
        cin.ignore();
        getline(cin, nam);

        cout << "Press [z] to back: ";
        char z;    cin >> z;
        if (z = 'z') {goto start;}

    }



    /* Here, the questions of the quiz is being displayed randomly with their choices. */

    if (opt==3)
    {
        //To check if there are enough questions.
        if (num_qus > 4){

            int Ques_count=1; int rep[1000];
            char rt_ans, usr_ans;
            int numcr_ans = 0, numrn_ans = 0;

            for (int l = 0; l < 5 ;l++){

                //To generate random numbers for the questions without repeating any one.
                int rnd; bool ck;
                do {
                    rnd = rand()%num_qus;
                    ck = true;
                    for (int j = 0; j < l; j++)
                    {if (rnd == rep[j]) {ck = false; break;}}
                }while (!ck);
                rep[l] = rnd;

                //To display each question.
                cout << " [" << Ques_count << "] " << point[rnd].qus <<endl;e();

                int crep[4]; char Choice_count = 'A';
                for (int k = 0; k < 4; k++) {

                    //To generate random numbers for the choices without repeating any one.
                    int crnd; bool cck;
                    do {
                        crnd = rand()%4;
                        cck = true;
                        for (int j = 0; j < k; j++)
                        {if (crnd == crep[j]) {cck = false; break;}}
                    }while (!cck);
                    crep[k] = crnd;

                    //TO display the choices of the question.
                    cout << "       [" << char(Choice_count+k) << "] " << point[rnd].ans[crnd];
                    if (crnd == 0) {rt_ans = Choice_count+k;} //To maintain the right answer.
                }

                //Here, the user will write his answer.
                e();e(); cout << "Enter your answer: ";       cin >> usr_ans;

                //Checking if the user answer is right or wrong.
                if (usr_ans == rt_ans || usr_ans == rt_ans+32)
                    {e();cout << "Right Answer" <<endl; numcr_ans++;}
                else
                    {e();cout << "Wrong Answer, The right answer is: " << rt_ans <<endl; numrn_ans++;}


                Ques_count++; e(); e();
            }

            test[num_quz].cr_ans = numcr_ans;
            test[num_quz].rn_ans = numrn_ans;

            //Displaying the right and wrong answers.
            e();cout << "Number of Right answers: " << test[num_quz].cr_ans <<endl;e();
            cout << "Number of Wrong answers: " << test[num_quz].rn_ans <<endl;
        }

        else {
            cout << "You don't have enough questions, Press [z] if you want to go back to the main menu." <<endl;
            char z;    cin >> z;
            if (z = 'z') {goto start;}
        }

        num_quz++; //TO write down the number of quizzes have been taken.

         cout << "Press [z] to back: ";
        char z;    cin >> z;
        if (z = 'z') {goto start;}
    }



    if (opt == 4){

        /* This section displays the user score statistics. */

        if (num_quz < 2) {

            e();cout << "You have to take another quiz to display your score statistics." <<endl;e();
        }

        else {
            cout << " your score statistics:" <<endl;e();
            t();cout << "-Number of quizzes taken: " << num_quz <<endl;e();

            int srt[1000],x; float avg = 0;
            for (int i = 0; i < num_quz; i++){
                    srt[i] = test[i].cr_ans;
            }

            //To sort the array to determine the highest and lowest score;
            for (int l = 0; l < num_quz-1; l++){

                for (int i = 0; i < num_quz; i++){

                    if (srt[i] < srt[i-1])
                    {
                        x = srt[i-1];
                        srt[i-1] = srt[i];
                        srt[i] = x;
                    }
                }
            }

            //To calculate the highest and lowest score.
            t();cout << "-Highest score: " << srt[num_quz-1] << "/5" <<endl;e();
            t();cout << "-Lowest score: " << srt[0] << "/5" <<endl;e();

            for (int i = 0; i < num_quz; i++){
                avg += srt[i];
            }

            //To calculate the average score.
            t();cout << "-Average score: " << avg/num_quz << "/5" <<endl;e();
        }

        cout << "Press [z] to back: ";
        char z;    cin >> z;
        if (z = 'z') {goto start;}

    }



    if (opt == 5){

        /* Here, all user scores are displayed, including the number of quizzes
        and the number of right and wrong answers in each. */

        cout << " Your all scores: " <<endl;
        cout << " _________________" <<endl;e();

            cout << "  Total Quizzes that have been finished: " << num_quz <<endl;e();

            for (int i = 0; i < num_quz; i++){
                cout << "       Test number " << i+1 << " score >>>>    " << "Correct: " << test[i].cr_ans << "    Wrong: " << test[i].rn_ans<<endl;e();
            }

         cout << "Press [z] to back: ";
        char z;    cin >> z;
        if (z = 'z') {goto start;}
    }



    /* That exists if the user chose to exit the program. */
    if (opt==6){
        return 0;
    }


}
