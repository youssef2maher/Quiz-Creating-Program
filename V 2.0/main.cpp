#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<vector>

using namespace std;


                        /*My Functions*/
void e(){cout << endl;}

void print_line()
{
    for (int i = 0; i < 40; i++){
        cout << "-";
    }
}

void print_small_line()
{
    for(int i = 0; i < 25; i++){
        cout << "-";
    }
}

void print_long_line()
{
    for(int i = 0; i < 100; i++){
        cout << "-";
    }
}

void print_slong_line()
{
    for(int i = 0; i < 80; i++){
        cout << "-";
    }
}

/* This function turns the LowerCase strings to UpperCase ones*/

void LowerCase(string &str)
{
    for (int i = 0; i < 20; i++){
        str[i] = tolower(str[i]);
    }
}




/* This function generates a random number
but first it checks if the number was repeated before or not
if not, it returns its value.
there is a global array which stores the generated numbers
to not be generated again.
this array is global to appear in the random function and the class.*/
int rep[4];
int rnd_num(int num_quest, int loop)
{
    int rnd; bool ck;
        do {
            rnd = rand()%num_quest;
            ck = true;
            for (int j = 0; j < loop; j++)
            {if (rnd == rep[j]) {ck = false; break;}}
        }while (!ck);
        rep[loop] = rnd;

    return rnd;
}


            /*My Classes*/



int counter=-1,num_of_users=0,NumberOfPlayer=0,playercount;


class User
{
public:

    //This functions sets the user_name, password, first and last name;
    virtual void adduser(string U,string P,string F,string L){};

    //This function prints the main menu for each player and admin.
    virtual int PrintMenu(){};


    /*This function is used to view all the accounts*/

    void ViewUsers(User **users)
    {
        cout <<"\t Existing Users in the System :-\n\n\t";
        print_slong_line();e();
        cout <<"\t First Name \t\t Last Name \t\t UserName\t\t Role \n\t";
            print_slong_line(); cout<<"\n\t";  print_slong_line();e();
        for(int i=0;i<num_of_users;i++)
        {
            cout<< "\t " <<users[i]->FristName<<"\t\t\t "<<users[i]->LastName<<"\t\t\t "<<users[i]->UserName<<"\t\t "<<users[i]->Role<<endl;
            cout<<"\t";print_slong_line();e();
        }
    }



    //This function updates the first and last name of the same account.

    void updatenames(User **users)
    {
        cout<<"\t Enter the first name: ";
        cin>>FristName;
        users[counter]->FristName=FristName;
        cout<<"\n\t Enter the last name: ";
        cin>>LastName;
        users[counter]->LastName=LastName;
    }


    //This overloaded operator function checks if the user is already used or not.

    bool operator==(User *U)
    {
        if (UserName==U->UserName)
             return true;
        else return false;
    }

    string Role;


protected:

    string UserName,Password,FristName,LastName;

private:

    //this function is used to log in or switch the account.
    friend void switchaccs(User **users);

};






class Player :public User
{
public:

    //This function prints the main menu of the player and takes his option.

     int PrintMenu()
    {
         cout<<"\n\n\n\t\t== WelCome "<<FristName<<" "<<LastName<<" (PLAYER)==" << "\n\n  please choose from the following options:\n\n"
             <<"\t[1] Switch accounts\n\n"
             <<"\t[2] Update your name\n\n"
             <<"\t[3] Start a new quiz\n\n"
             <<"\t[4] Display your scores statistics\n\n"
             <<"\t[5] Display all your scores\n\n"
             <<"\t[6] Display details of your last 2 quizzes\n\n"
             <<"\t[7] Exit the program\n\n"
             <<"My choice: _";
             int choice;
             do{
                cin >> choice;
                cout << endl <<endl;
             }while(choice > 7);
             return choice;
    }



    void adduser(string U,string P,string F,string L)
        {
        UserName=U,Password=P,FristName=F,LastName=L,Role="player";
        num_of_users++;
        ++NumberOfPlayer;
        }

private:
};






class Admin :public User
{
public :

    //This function prints the main menu of the admin and takes his option.

    int PrintMenu()
    {
         cout<<"\n\n\n\t\t== WelCome "<<FristName<<" "<<LastName<<" (ADMIN)==" << "\n\n  please choose from the following options:\n\n"
             <<"\t[1] Switch Accounts\n\n"
             <<"\t[2] Update your Name\n\n"
             <<"\t[3] View All Users \n\n"
             <<"\t[4] Add New User\n\n"
             <<"\t[5] View All Questions\n\n"
             <<"\t[6] Add New Question\n\n"
             <<"\t[7] Load Questions from a File\n\n"
             <<"\t[8] Exit the Program\n\n"
             <<"\t\tMy choice: _";
             int choice = 0;
             do{
                cin >> choice;
                cout << endl <<endl;
             }while(choice > 8);
             return choice;

    }


    void adduser(string U,string P,string F,string L)
        {
        UserName=U,Password=P,FristName=F,LastName=L,Role="Admin";
        num_of_users++;
        }

};



/*This function used to log in or to switch accounts by checking if its user_name is excited. if it is excited then
it check on its password. if it is correct, it logs into this account, if not, option will appear to tell user if he\she wants to
re-enter user name or password*/

void switchaccs(User **users)
    {
        string name,pass;
        char again;
        User u;
        int notdefine;
        cout<<"  \tUser Name: ";
        cin>>name;
        for(int i=0;i<num_of_users;i++)
        {
            if (name==users[i]->UserName)
            {
                notdefine=0;
                cout <<"  \n\tPassword: ";
                cin>>pass;
                if(pass==users[i]->Password)
                {
                    counter=i;

                }
                else {cout<<"\n\t InCorrect Password  :( \n\n"
                          <<"       Do you want to Re-Enter the Password again?\t (Y or N): ";
                     do{cin>>again;} while(again != 'y' && again != 'n' && again != 'Y' && again != 'N');
                     if (again=='y' || again=='Y')
                        i--;
                     }
            }
        }

        if(notdefine!=0)
        {
            cout<<"\n\t Non-Existing Account   :/ \n\n"
                <<"       Do you want to R-Enter the User Name again?\t (Y or N): ";
            do{cin>>again;} while(again != 'y' && again != 'n' && again != 'Y' && again != 'N');
            cout<<endl;
            if (again =='y' || again=='Y')
                switchaccs(users);
            else ;
        }
    }




class Answer
{

public:
    void mcq_answer(char &ans)
    {
        do {
            cout << "\t Answer: ";    cin >> ans;
            ans = tolower(ans);
        } while (ans != 'a' && ans != 'b' && ans != 'c' && ans != 'd');
    }

    void tf_answer(char ans[5] = "NON")
    {

        cout << "\t Answer: ";

            cin >> ans;
            for (int i = 0; i < strlen(ans); i++){
                ans[i] = tolower(ans[i]);

            }
    }

    void cq_answer(char ans[100] = "NON")
    {

        cout << "\t Answer: ";    cin >> ans;
        ans[0] = toupper(ans[0]);
        for (unsigned int i = 1; i < strlen(ans); i++)
            {ans[i] = tolower(ans[i]);}
    }


};


/*This is an ID counter, and I made it global to appear
in the whole code and no to change its value*/
int ID = 0;
//this variables was made to get the the grades and the number of right answer
int grades_counter=0,mcq_rightans=0,cq_rightans=0,tf_rightans=0;


/*That class takes a question from the user
and gives it a unique ID
as well as displaying each of them.*/
class Question
{
protected:

    string question;
    int unique_ID = 0;
    // these vectors will store the grades of the student
    vector<int>grades;vector<int>mcq_right;vector<int>cq_right;vector<int>tf_right;vector<int>sum_m_c_t;
public:

    int quiznum = 0;
    Answer Y;
    int mcq_num = 0, tf_num = 0, cq_num = 0;

    //This function takes the question from the user.
    void set_question()
    {
        cout << "Enter the question: ";
        cin.ignore();
        getline(cin, question);e();

    }

    //This function takes a question for a file.
    void load_question(ifstream *f)
    {
        getline(*f, question);
    }

    //This function displays the question.
    void display_question()
        {cout << question ;}

    //This function gives a unique ID for the question.
    int get_ID()
    {
        unique_ID = ++ID;
        return unique_ID;
    }

    //This function displays the ID of the question.
    int display_ID()
        {return unique_ID;}


    bool operator==(Question q)
    {
        if (question == q.question){return true;}
        else {return false;}
    }


    friend void setgrades(vector<int>grades,vector<int>mcq_right,vector<int>cq_right,vector<int>tf_right);
    friend class Quiz;

};



class MCQ : public Question
{
private:

public:
    string choice[4], ans;   char user_ans;  char right_choice = 'N';
    bool right_ans = false , wrong_ans = false;

    //This function takes the choices from the user, including the right one.
    void set_choices()
    {
        cout << "Enter the choices considering the first choice is the right one:" <<endl;e();
        for (int i = 0; i < 4; i++)
            {getline(cin, choice[i]);e();}
    }

    //This function load the choices from a file.
    void load_choices(ifstream *f)
    {
        for (int i = 0; i < 4; i++)
            {getline(*f, choice[i]);}
    }

    //This function displays the choices.
    int rnd[4];
    void display_choices()
    {
        char choice_num = 'A';

        for (int i = 0; i < 4; i++){
            rnd[i] = rnd_num(4,i);
            cout << "(" << choice_num << ") " << choice[rnd[i]] << "     ";choice_num++;
            if (rnd [i]== 0){right_choice = char(i+97);
            }
        }
    }

    void display_choices_norand()
    {
        char choice_num = 'A';
        for (int i = 0; i < 4; i++){
            cout << "(" << choice_num << ") " << choice[i] << "     ";choice_num++;
            }
    }

    void answer()
    {
        Y.mcq_answer(user_ans);
        if (user_ans == right_choice){right_ans = true; cout <<endl << "\t  Correct!! :)"<<endl<<endl; grades_counter+=2; mcq_rightans++;}
        else{
                wrong_ans = true;
                cout <<endl<< "\t  Wrong!! :("<<endl<<endl;
                cout << "\t The Correct Answer is: " << (char)toupper(right_choice) <<endl<<endl;
        }
        if(user_ans=='a') ans =choice[rnd[0]];
        else if(user_ans=='b') ans=choice[rnd[1]];
        else if (user_ans=='c') ans =choice[rnd[2]];
        else ans=choice[rnd[3]];
    }
};




class TF : public Question
{
private:

public:

    string t_f = "NoN";
    char user_ans[5];
    bool right_ans = false , wrong_ans = false;

    //This function take the status of the statement, if true of false.
    void true_or_false()
    {
        cout << "Enter the status of the statement:"<<endl<<endl;
        cout << "[true] for true, [false] for false: ";
        cin >> t_f;e();
    }

    //This function takes the status of the statemendefault_playert from a file.
    void load_true_or_false(ifstream *f)
        {getline(*f, t_f);}

    //This function returns T or F.
    string get_t_f()
        {return t_f;}

    //This function displays the status of the statement.
    void display_status()
        {cout << t_f ;}

    void answer()
    {
        Y.tf_answer(user_ans);
        if (user_ans == t_f){right_ans = true; cout <<endl << "\t  Correct!! :)"<<endl<<endl; grades_counter++; tf_rightans++;}
        else{wrong_ans = true; cout <<endl<< "\t  Wrong!! :("<<endl<<endl;}
    }

};



class CQ : public Question
{
private:
    string MissWord;
public:

    bool right_ans = false , wrong_ans = false;
    char user_ans[100];


    //This function takes the missing word from the sentence.
    void missing_word()
    {
        cout << "Enter the Missing Word: ";
        cin >> MissWord;
    }

    //This function loads the missing word from a file.
    void load_missing_word(ifstream *f)
        {getline(*f, MissWord);}

    string get_missing_word()
        {return MissWord;}

    //This function displays the missing word.
    void display_missing_word()
        {cout << MissWord;}

    void answer()
    {
        Y.cq_answer(user_ans);
        if (user_ans == MissWord){right_ans = true; cout <<endl << "\t  Correct!! :)"<<endl<<endl; grades_counter+=3; cq_rightans++;}
        else{wrong_ans = true; cout <<endl<< "\t  Wrong!! :("<<endl<<endl;}
    }

};

struct last_2quiz
{
    string quiz_question[12];
    string choice[12];
    string mcq_player_ans[16];
    bool right_or_wrong[12];
    string correct[4],TorF[4];
    vector<int>G,MC,TF,C;
    int num_quiz=0;

};



/*This class displays a constant number of questions as a quiz to the user
each question displays in random way */
class Quiz
{
private:

public:

    Question S;
    string ques[6],mc[8],mcq[2],tf[2],c[2],ans[2],bo[2];
    bool po[6];

    void mcq_quest(MCQ arr1[1000], int nq)
    {
        cout << "\t MCQ Questions:-" <<endl;
        cout << "\t =============== ";
        cout << endl <<endl;
        int rand[2] ={-1,-1};
        for (int i = 0; i < 2; i++){
            rand[i]= rnd_num(nq,i);
            if(rand[0]!=rand[1]){
            cout << "(" << i+1 << ") ";
            arr1[rand[i]].display_question();
            cout << endl <<endl;
            cout << "\t";   arr1[rand[i]].display_choices();e();e();
            arr1[rand[i]].answer();

            mcq[i]=arr1[rand[i]].ans;
            ques[i] = arr1[rand[i]].question;
            po[i]=arr1[rand[i]].right_ans;

            for(int y=0;y<4;y++)
                mc[y+(4*i)]=arr1[rand[i]].choice[y];}
            else --i;


        }
        print_long_line(); cout << endl <<endl;


    }



    void tf_quest(TF arr2[1000],int nq)
    {
        cout << "\t True or False Questions:-" <<endl;
        cout << "\t ========================= ";
        cout << endl <<endl;
        int rand[2] ={-1,-1};
        for (int i = 0; i < 2; i++){
            rand[i] = rnd_num(nq,i);
            if(rand[0]!=rand[1]){
            cout << "(" << i+1 << ") ";
            arr2[rand[i]].display_question();e();e();
            arr2[rand[i]].answer();

            tf[i]=arr2[rand[i]].user_ans;

            ques[i+2] = arr2[rand[i]].question;
            po[i+2]=arr2[rand[i]].right_ans;
            bo[i]=arr2[rand[i]].t_f;
            }
            else --i;

        }
        print_long_line(); cout << endl <<endl;
    }



    void cq_quest(CQ arr3[1000],int nq)
    {
        cout << "\t Complete Questions:-" <<endl;
        cout << "\t ==================== ";e();e();
        int rand [2]= {-1,-1};
        for (int i = 0, n = 1; i < 2; i++, n++){
            rand[i] = rnd_num(nq,i);
            if(rand[0]!=rand[1]){
            cout << "(" << n << ") ";
            arr3[rand[i]].display_question();e();e();
            arr3[rand[i]].answer();

            c[i]=arr3[rand[i]].user_ans;
            ques[i+4] = arr3[rand[i]].question;
            po[i+4] =arr3[rand[i]].right_ans;
            ans[i]=arr3[rand[i]].get_missing_word();}
            else --i;

        }
    }


    void setgrades()
    {
        //vector<int>grades,vector<int>mcq_right,vector<int>cq_right,vector<int>tf_right
       // Question s;
        S.grades.push_back(grades_counter);
        S.mcq_right.push_back(mcq_rightans);
        S.cq_right.push_back(cq_rightans);
        S.tf_right.push_back(tf_rightans);
        grades_counter=0;mcq_rightans=0;cq_rightans=0;tf_rightans=0;
    }
     vector<int> getG()
   {
       return S.grades;
   }
    vector<int> getM()
    {
        return S.mcq_right;
    }
    vector<int> getT()
    {
        return S.tf_right;
    }
    vector<int> getC()
    {
        return S.cq_right;
    }
    void error_msg()
    {
        cout << "\n\t\t *** You don't have enough questions *** \n\n" <<endl<<endl;
    }


};

 void statistics(int quizn,last_2quiz q);
 void viewallscores(int quizn, last_2quiz q);

int main()
{

        srand(time(NULL));

        Question S;      MCQ A[1000],a;   TF B[1000],b;    CQ C[1000],c;    Quiz Z;
        int mcq_counter = 0;    int tf_counter = 0;     int cq_counter = 0;     bool unique_qus = true;

       vector<last_2quiz> Q;
       Q.push_back(last_2quiz());

        cout <<"\n\n\t\t\t - - - - - - - - - - - - - - -\n";
        cout <<"\t\t\t- - - - - - - - - - - - - - -\n";
        cout <<endl<<"\t\t\t WELCOME TO QUIZ GAME V2.0.\n\n";
        cout <<"\t\t\t- - - - - - - - - - - - - - -\n";
        cout <<"\t\t\t - - - - - - - - - - - - - - - \n\n";

        User *users[num_of_users];

        users[0]=new Player();
        users[0]->adduser("default_player","player","user","user");
        users[1]=new Admin();
        users[1]->adduser("default_admin","admin","user","user");

        cout << "\n\n\n\t\t --Enter Your Account-- \n\n";
        cout << "   For Default Admin {User: default_admin, Pass: admin}\n\n";
        cout << "   For Default Player {User: default_player, Pass: player}\n\n";

        while(true){
        switchaccs(users);
        playercount=counter;
            for(int i=0;i<counter;i++)
                if (users[i]->Role=="Admin")
                    --playercount;
        if(counter==0||counter==1) break;

        else cout<<"\n\t    ***you must log in to proceed*** \n\n";
        }




        Start:

        if (users[counter]->Role == "Admin"){

        int option = users[counter]->PrintMenu();

        //This if condition switches the account.
        if (option == 1){

            cout << "\n\n\t\t == Switch Accounts == \n\n";

            switchaccs(users);
            playercount=counter;
            for(int i=0;i<counter;i++)
                if (users[i]->Role=="Admin")
                    --playercount;

        }


        //This if condition updates the user first and last name.
        if (option == 2){

            cout << "\n\n\t\t == Update your Name == \n\n";

            users[counter]->updatenames(users);
        }


        if (option == 3){

            cout << "\n\n\t\t == View all Users == \n\n\n";

            users[counter]->ViewUsers(users);
        }


        if (option == 4)
        {

            cout << "\n\t\t\t == Add New User == \n\n";
            string R,U,P,F,L;

                while (true){
                cout<<"\n\t Choose a Role \t \"Admin\" or \"Player\" : ";
                cin>>R;     LowerCase(R);
                cin.clear();
                cin.sync();

                if(R=="admin")
                {
                    Admin a;
                    char k='k',y='y';
                    while(k=='k'){
                            y='y';
                    cout<<"\n\n\t Enter User Name :_ ";
                    cin>>U;
                    cin.clear();
                    cin.sync();
                    cout<<"\n\t Enter Password :_ ";
                    cin>>P;
                    cin.clear();
                    cin.sync();
                    cout<<"\n\t Enter First Name :_ ";
                    cin>>F;
                    cin.clear();
                    cin.sync();
                    cout<<"\n\t Enter Last Name :_ ";
                    cin>>L;
                    cin.clear();
                    cin.sync();
                    a.adduser(U,P,F,L);

                     for(int i=0;i<num_of_users-1;i++)
                    {
                        if(a==users[i]){
                        cout<<"\n\n\t\t *** This User Name is already taken ***\n"
                            <<"\n     Press any Key to Re-Enter New User: ";
                        cin>>k;
                        k='k';
                        y='n';
                        --num_of_users;
                        break;
                        }
                    }
                    if(y=='y')
                    {
                        --num_of_users;
                        users[num_of_users]=new Admin;
                        users[num_of_users]->adduser(U,P,F,L);
                        cout<<"\n\n\t User has been added SuccessFully  ;)  \n";
                        break;
                    }

                }break;
                }
                else if(R=="player")
                {
                    Player a;
                    char k='k',y='y';
                    while(k=='k'){
                            y='y';
                    cout<<"\n\n\t Enter User Name :_ ";
                    cin>>U;
                    cin.clear();
                    cin.sync();
                    cout<<"\n\n\t Enter Password :_ ";
                    cin>>P;
                    cin.clear();
                    cin.sync();
                    cout<<"\n\n\t Enter First Name :_ ";
                    cin>>F;
                    cin.clear();
                    cin.sync();
                    cout<<"\n\n\t Enter Last Name :_ ";
                    cin>>L;
                    cin.clear();
                    cin.sync();
                    a.adduser(U,P,F,L);
                     for(int i=0;i<num_of_users-1;i++)
                    {
                        if(a==users[i]){
                        cout<<"\n\n\t\t *** This User Name is already taken ***\n"
                            <<"\n     Press any Key to Re-Enter New User: ";
                        cin>>k;
                        k='k';
                        y='n';
                        --num_of_users;
                        break;
                        }
                    }
                    if(y=='y')
                    {
                        --num_of_users;
                        users[num_of_users]=new Player;
                        users[num_of_users]->adduser(U,P,F,L);
                        cout<<"\n\n\t User has been added SuccessFully  ;)  \n";
                        Q.push_back(last_2quiz());
                        break;
                    }

                }break;
                }
                else{
                    cout<<"\n\t Please Enter either \"Admin\" or \"Player\" \n";
                }}

        }





        /* In this part, All the questions has been added or loaded will be viewed
        The user have an option to delete one question or more using them ID */


        if (option == 5){
            while(true){
            cout << "\t  - - - - - - - - - - - - - - - - - -" <<endl<<endl;
            cout << "\t  Number of all questions: " << mcq_counter + tf_counter + cq_counter;
            cout << "  Questions" <<endl<<endl << " ";
            cout << "\t  - - - - - - - - - - - - - - - - - -" <<endl<<endl<<endl;


            int quest_num = 1 ;
            cout << "  - - - - - - - - - - - - - - - - - -" <<endl<<endl;
            cout << "  Number of MCQ questions: " << mcq_counter << " Questions" <<endl<<endl <<" ";
            cout << "  - - - - - - - - - - - - - - - - - -" <<endl<<endl<<endl;

            cout << "\n\n\t\t *** The Correct Choice is the First One *** \n\n";

            for (int l = S.quiznum ; l < mcq_counter; l++){
                    cout << quest_num << ")";
                    cout << "ID:["<<A[l].display_ID()<< "] ";
                    A[l].display_question(); cout <<endl<<endl;
                    cout <<"\t";      A[l].display_choices_norand();
                    cout << endl <<endl; quest_num++;
            }


            cout <<endl << "  - - - - - - - - - - - - - - - - - -" <<endl<<endl;
            cout << " Number of TF questions: " << tf_counter << " Questions" <<endl<<endl<<" ";
            cout << "  - - - - - - - - - - - - - - - - - -" <<endl<<endl<<endl;

            for (int l = 0; l < tf_counter; l++){
                    cout << quest_num << ")";
                    cout << "ID:["<<B[l].display_ID() << "] ";
                    B[l].display_question();
                    cout << "   Answer:[";     B[l].display_status(); cout << "]";
                    cout << endl <<endl; quest_num++;
            }


            cout << endl<< "  - - - - - - - - - - - - - - - - - -" <<endl<<endl;
            cout << " Number of CQ questions: " << cq_counter << " Questions" <<endl<<endl<<" ";
            cout << "  - - - - - - - - - - - - - - - - - -" <<endl<<endl<<endl;

            for (int l = 0; l < cq_counter; l++){
                    cout << quest_num << ")";
                    cout << "ID:["<< C[l].display_ID()<< "] ";
                    C[l].display_question();
                    cout << "Answer:[";     C[l].display_missing_word(); cout << "]";
                    cout << endl <<endl;  quest_num++;
            }

            if (mcq_counter == 0 && tf_counter == 0 && cq_counter == 0){
                cout << "\n\t\t *** There is nothing to be viewed *** " <<endl<<endl;
                break;
            }


            else {
                    cout << " -Press [D] to Delete a Question \n\n -Press [B] to go back to main menu \n\n";
                    cout << " Your choice: ";
                    char ch;    cin >> ch;e();e();

                    int dn = 1;
                    switch(ch)
                    {
                    case 'd':
                    case 'D':
                        cout << " How Many questions will be Deleted: ";
                        int numq;       cin >> numq;e();e();

                        while(numq > (mcq_counter+cq_counter+tf_counter))
                            {cout<<" Enter a Valid Number: ";     cin >> numq;e();e();}

                        while(numq > 0){

                            cout<<" Enter the question number (" << dn <<") ID: ";
                            int id;   cin >> id;e();    bool not_id = false;

                            for(int i = 0; i < mcq_counter; i++)
                            {
                                if(A[i].display_ID()==id)
                                {
                                    for(int x = i; x < mcq_counter-1; x++)
                                    {
                                        a=A[x];
                                        A[x]=A[x+1];
                                        A[x+1]=a;
                                    }

                                    mcq_counter--;  not_id = true;
                                    cout<<endl<<"     Question has been Deleted ;)\n\n";
                                }
                            }


                            for(int i = 0; i < cq_counter; i++)
                            {
                                if(C[i].display_ID()==id)
                                {
                                    for(int x = i; x < cq_counter-1; x++)
                                    {
                                        c=C[x+1];
                                        C[x+1]=C[x];
                                        C[x]=c;
                                    }
                                    cq_counter--;   not_id = true;
                                    cout<<endl<<"     Question has been Deleted ;)\n\n";
                                }
                            }


                            for(int i = 0; i <tf_counter; i++)
                            {
                                if(B[i].display_ID()==id)
                                {
                                    for(int x = i; x < tf_counter-1; x++)
                                    {
                                        b=B[x+1];
                                        B[x+1]=B[x];
                                        B[x]=b;
                                    }
                                    tf_counter--;   not_id = true;
                                    cout<<endl<<"     Question has been Deleted ;)\n\n";
                                }
                            }

                            if (not_id)
                                {numq--;     dn++;}
                            else {cout << "     Not Matching ID!!! :(" <<endl<<endl;}
                        }

                        break;
                    case 'b':
                    case 'B':
                        goto Start;
                        break;
                    default:
                        cout<<" Your choice doesn't exist :/ \n\n";
                    }
                }
            }
        }







        /*In this part; First thing first, We allow the user to choose a type of question to be added
        Second thing second, The user enters the number of questions to be added
        Third thing the last_2quiz Q[2rd, The user Enter the question
        Last thing last, We check if the question is already existed before or not,
        if it is not, the user keep going and writes the answers of the questions. */


        if (option == 6)
        {

            cout << "\n\n\t\t == Add New Question == " <<endl;e();
            cout << "\t 1) MCQ " <<endl<<endl<< "\t 2) TF " <<endl<<endl<< "\t 3) COMPLETE "<<endl<<endl;
            int type;
            do{
                cout << "   Enter your Type: ";
                cin >> type;
                cout << endl <<endl;
            }while(type > 3);

            if (type == 1){

                cout << " How Many Questions : ";
                int num_added_ques;     cin >> num_added_ques;e();e();

                while(num_added_ques > 20){
                    cout << " Are you sure from that number [Y] or [N] : ";
                    char s;     cin >> s;e();e();

                    if (s == 'y' || s == 'Y'){break;}

                    else {cout << " How Many Questions : ";   cin >> num_added_ques;e();e();}

                }


                for (int i = 0; i < num_added_ques; i++){

                    A[mcq_counter].set_question();

                    for (int i = 0; i < mcq_counter; i++){
                        if (A[mcq_counter] == A[i])
                            {unique_qus = false; break;}
                    }

                    if (unique_qus){
                        A[mcq_counter].get_ID();
                        A[mcq_counter].set_choices();
                        mcq_counter++;
                    }

                    else {cout << endl << "     This Question has already been Created before :| " << endl << endl;}
                }

            }
            S.mcq_num = mcq_counter;



            if (type == 2){

                cout << " How Many Questions : ";
                int num_added_ques;     cin >> num_added_ques;e();e();

                while(num_added_ques > 20){
                    cout << " Are you sure from that number [Y] or [N] : ";
                    char s;     cin >> s;e();e();

                    if (s == 'y' || s == 'Y'){break;}

                    else {cout << " How Many Questions : ";   cin >> num_added_ques;e();e();}

                }


                for (int i = 0; i < num_added_ques; i++){

                    B[tf_counter].set_question();

                    for (int i = 0; i < tf_counter; i++){
                        if(B[tf_counter] == B[i])
                            {unique_qus = false; break;}
                    }

                    if(unique_qus){
                        B[tf_counter].get_ID();
                        B[tf_counter].true_or_false();
                        tf_counter++;
                    }

                    else {cout << endl << "     This Question has already been Created before :| " << endl << endl;}
                }
            }
            S.tf_num = tf_counter;



            if (type == 3){

                cout << " How Many Questions : ";
                int num_added_ques;     cin >> num_added_ques;e();e();

                while(num_added_ques > 20){
                    cout << " Are you sure from that number [Y] or [N] : ";
                    char s;     cin >> s;e();e();

                    if (s == 'y' || s == 'Y'){break;}

                    else {cout << " How Many Questions : ";   cin >> num_added_ques;e();e();}

                }


                for (int i = 0; i < num_added_ques; i++){

                    C[cq_counter].set_question();

                    for (int i = 0; i < cq_counter; i++){
                        if (C[cq_counter] == C[i])
                            {unique_qus = false; break;}
                    }

                    if(unique_qus){

                        C[cq_counter].get_ID();
                        C[cq_counter].missing_word();
                        cq_counter++;e();
                    }

                    else {cout << endl << "     This Question has already been Created before :| " << endl << endl;}
                }
            }
            S.cq_num = cq_counter;
        }








        /*In this part, At first, the user enters the file name which is going to be loaded,
        Then, we check if that file is already existed or not, if it is, we keep going loading that file,
        If an Error happened while loading the file, we just stop loading, and store all the questions
        which has been loaded before the Error */


        if (option == 7)
        {

            cout << " Enter the file name: ";
            char file_name[100];   cin >> file_name;

            ifstream file;
            file.open(file_name);

            while(!file){

                cout<<endl<<" File Doesn't Exist\n\n -Press [R] to Re-Enter the file name.\n\n -Press [B] to go back to Menu.\n\n";
                cout << " Enter your choice: ";
                char choi;      cin >> choi;e();e();

                switch(choi)
                {
                case 'r':
                case 'R':
                    cout << " Enter the file name: ";
                    cin >> file_name;   file.open(file_name);
                    break;
                case 'b':
                case 'B':
                    goto Start;
                    break;
                default:
                    cout<<" Your choice doesn't exist\n\n";
                }
            }


            string tfq = "NON";
            while(getline(file, tfq)){
                unique_qus=true;
                if (tfq == "MCQ"){

                    A[mcq_counter].load_question(&file);

                    for (int i = 0; i < mcq_counter; i++){
                        if (A[mcq_counter] == A[i])
                            {unique_qus = false; break;}
                    }

                    if (unique_qus){
                        A[mcq_counter].get_ID();
                        A[mcq_counter].load_choices(&file);
                    mcq_counter++;      S.mcq_num = mcq_counter;
                    }

                    else{
                        string useless;
                        getline(file, useless);
                        getline(file, useless);
                        getline(file, useless);
                        getline(file, useless);
                    }

                }

                else if (tfq == "TF"){

                    B[tf_counter].load_question(&file);

                   for (int i = 0; i < tf_counter; i++){
                        if(B[tf_counter] == B[i])
                            {unique_qus = false; break;}
                    }

                    if(unique_qus){
                        B[tf_counter].get_ID();
                        B[tf_counter].load_true_or_false(&file);
                        tf_counter++;       S.tf_num = tf_counter;
                    }

                    else{
                        string useless;
                        getline(file, useless);
                    }

                }

                else if (tfq == "COMPLETE"){

                    C[cq_counter].load_question(&file);

                   for (int i = 0; i < cq_counter; i++){
                        if (C[cq_counter] == C[i])
                            {unique_qus = false; break;}
                    }

                    if(unique_qus){

                        C[cq_counter].get_ID();
                        C[cq_counter].load_missing_word(&file);
                        cq_counter++;       S.cq_num = cq_counter;
                    }

                    else{
                        string useless;
                        getline(file, useless);
                    }

                }

                else {
                    cout <<endl<< "       ERROR!!! :0" <<endl;
                    file.close();
                }

            }

            cout << endl << "   The file has been LOADED ;)" <<endl<<endl;

        }


        if(option == 8)
        {
            exit(0);
        }

        }




        if (users[counter]->Role == "player")
        {


        int option = users[counter]->PrintMenu();

        //This if condition switches the account.
        if (option == 1){

            cout << "\n\n\t\t == Switch Accounts == \n\n";

            switchaccs(users);
            playercount=counter;
            for(int i=0;i<counter;i++)
                if (users[i]->Role=="Admin")
                    --playercount;

        }


        //This if condition updates the user first and last name.
        if (option == 2){

            cout << "\n\n\t\t == Update your Name == \n\n";

            users[counter]->updatenames(users);
        }






        /*In this part, The user will create a quiz, answer it and
        will be given each question correct answer */


        if (option == 3)
        {
            int corr=0;
            if (mcq_counter < 2 || tf_counter < 2 || cq_counter < 2)
                {Z.error_msg();}

            else{
                S.quiznum++;
                Z.mcq_quest(A,mcq_counter);
                Z.tf_quest(B,tf_counter);
                Z.cq_quest(C,cq_counter);
                Z.setgrades();
                vector<int>m=Z.getG();
                Q[playercount].num_quiz=S.quiznum;
                Q[playercount].G=m;
                Q[playercount].MC=Z.getM();
                Q[playercount].TF=Z.getT();
                Q[playercount].C=Z.getC();

                if(S.quiznum==1){
                for(int i=0;i<6;i++){
                    Q[playercount].quiz_question[i]=Z.ques[i];
                    Q[playercount].right_or_wrong[i]=Z.po[i];
                    if(i<2){
                        Q[playercount].choice[i]=Z.mcq[i];
                        for(int y=0;y<4;y++)
                            Q[playercount].mcq_player_ans[y+(i*4)]=Z.mc[y+(4*i)];}

                    else if(i<4){
                        Q[playercount].choice[i]=Z.tf[i-2];
                        Q[playercount].TorF[i-2]=Z.bo[i-2];
                    }
                    else{
                        Q[playercount].choice[i]=Z.c[i-4];
                        Q[playercount].correct[i-4]=Z.ans[i-4];
                        }
                if(Z.po[i]==1) ++corr;}

                }
                else if (S.quiznum==2){
                    for(int i=6;i<12;i++){
                        Q[playercount].quiz_question[i]=Z.ques[i-6];
                        Q[playercount].right_or_wrong[i]=Z.po[i-6];
                        if(i<8){
                        Q[playercount].choice[i]=Z.mcq[i-6];
                        for(int y=8;y<12;y++)

                            Q[playercount].mcq_player_ans[y+(4*(i-6))]=Z.mc[y+(4*(i-6)-8)];}
                            else if(i<10){
                                Q[playercount].choice[i]=Z.tf[i-8];
                                Q[playercount].TorF[i-6]=Z.bo[i-8];
                            }
                            else {Q[playercount].choice[i]=Z.c[i-10];
                            Q[playercount].correct[i-8]=Z.ans[i-10];}
                    if(Z.po[i-6]==1) ++corr;}
            }
            else{
                for(int i=0;i<6;i++)
                {
                    Q[playercount].quiz_question[i]=Q[playercount].quiz_question[i+6];
                    Q[playercount].right_or_wrong[i]=Q[playercount].right_or_wrong[i+6];
                    if(i<2){
                        Q[playercount].choice[i]=Q[playercount].choice[i+6];
                        for(int y=0;y<4;y++)
                            Q[playercount].mcq_player_ans[y+(i*4)]=Q[playercount].mcq_player_ans[y+(i*4)+8];}

                    else if(i<4){
                        Q[playercount].choice[i]=Q[playercount].choice[i+6];
                         Q[playercount].TorF[i-2]=Q[playercount].TorF[i];}
                    else{
                        Q[playercount].choice[i]=Q[playercount].choice[i+6];
                        Q[playercount].correct[i-4]=Q[playercount].correct[i-2];
                        }
                }
                for(int i=6;i<12;i++){
                        Q[playercount].quiz_question[i]=Z.ques[i-6];
                        Q[playercount].right_or_wrong[i]=Z.po[i-6];
                        if(i<8){
                        Q[playercount].choice[i]=Z.mcq[i-6];
                        for(int y=8;y<12;y++)

                            Q[playercount].mcq_player_ans[y+(4*(i-6))]=Z.mc[y+(4*(i-6)-8)];}
                            else if(i<10){
                                Q[playercount].choice[i]=Z.tf[i-8];
                                 Q[playercount].TorF[i-6]=Z.bo[i-8];}
                            else {Q[playercount].choice[i]=Z.c[i-10];
                            Q[playercount].correct[i-8]=Z.ans[i-10];}
                            if(Z.po[i-6]==1) ++corr;}
                }
                }

                if(mcq_counter >= 2 && tf_counter >= 2 && cq_counter >= 2){
                cout<<"\n\n\t\t Correct Answers : "<<corr<<endl
                    <<"\n\t\t Wrong Answers : "<<6-corr<<endl
                    <<"\n\t\t Your Grade : "<<Q[playercount].G[S.quiznum-1]<<"/12"<<endl;
                }

            }


       if (option == 4)
        {
            if(Q[playercount].num_quiz==0)
            {
                cout<<"You should enter a quiz first.\n";
            }
            else
            {
                statistics( Q[playercount].num_quiz,Q[playercount]);
            }
        }






        if (option == 5)
        {
            if(Q[playercount].num_quiz==0)
                cout<<"You should enter a quiz first.\n";
            else
            {
                viewallscores(Q[playercount].num_quiz,Q[playercount]);
            }
        }




        if (option == 6)
        {

            cout << "\n\n\t\t == Display the Last 2 Quizzes == \n\n";


            if(S.quiznum==0)
            {
                cout<<"\n\n\t\t *** You should take a quiz first ***\n";
            }
            else if(S.quiznum==1)
            {
                cout << "\n\t The Questions of the Quiz :-";
                cout << "\n\t ---------------------------- \n\n";

            for (int i = 0; i < 6; i++){
                    cout<<"\n\t"<<Q[playercount].quiz_question[i]<<endl<<endl;
                    if(i<2){
                            cout<<"\t";
                        for(int y=0;y<4;y++){
                            cout<<"\t";
                            if(y==0)    cout<<"*(a) ";
                            else if(y==1) cout<<"(b) ";
                            else if(y==2) cout<<"(c) ";
                            else cout <<"(d) ";


                            cout<<Q[playercount].mcq_player_ans[y+(4*i)];}
                        cout<<endl<<endl;}

                        cout<<"     The Player Answer : \t\""<<Q[playercount].choice[i]<<"\"\t The Answer was : ";
                        if(Q[playercount].right_or_wrong[i]==1) cout<<"correct \n\n";
                        else {cout<<"   Wrong, and the Correct Answer is : ";
                        if(i<2) cout<<Q[playercount].mcq_player_ans[4*i]<<endl<<endl;
                        else if(i<4)
                        {
                            if (Q[playercount].TorF[i-2]=="true") cout<<"True\n\n";
                            else cout<<"False\n\n";
                        }else  cout<<Q[playercount].correct[i-4]<<endl<<endl;
                        }

            }

            cout << "\n\n\t The Score of the Quiz:-\n";
            cout << "    \t ---------------------- \n";

            cout<<"\n\t\t The player Score is: ["<<Q[playercount].G[Q[playercount].num_quiz-1]<<"/12]"<<endl;
            cout<<"\n\t\t The player Score in MCQ Question is: ["<<Q[playercount].MC[Q[playercount].num_quiz-1]*2<<"/4]"<<endl;
            cout<<"\n\t\t The player Score in TF Question is: ["<<Q[playercount].TF[Q[playercount].num_quiz-1]<<"/2]"<<endl;
            cout<<"\n\t\t The player Score in Complete Question is: ["<<Q[playercount].C[Q[playercount].num_quiz-1]*3<<"/6]"<<endl;
            cout<<endl;

            }

            else{

            cout << "\n\t The Questions of the Quiz :-";
            cout << "\n\t ---------------------------- \n\n";

            for (int i = 0; i < 6; i++){
                    cout<<"\t"<<Q[playercount].quiz_question[i]<<endl<<endl;
                    if(i<2){
                            cout<<"\t";
                        for(int y=0;y<4;y++){
                            cout<<"\t";
                            if(y==0)    cout<<"*(a) ";
                            else if(y==1) cout<<"(b) ";
                            else if(y==2) cout<<"(c) ";
                            else cout <<"(d) ";


                        cout<<Q[playercount].mcq_player_ans[y+(4*i)];}
                        cout<<endl<<endl;}

                        cout<<"     The Player Answer : \t\""<<Q[playercount].choice[i]<<"\"\t The Answer was : ";
                        if(Q[playercount].right_or_wrong[i]==1) cout<<"correct \n\n";
                        else {cout<<"   Wrong, and the Correct Answer is : ";
                        if(i<2) cout<<Q[playercount].mcq_player_ans[4*i]<<endl<<endl;
                        else if(i<4)
                        {
                            if (Q[playercount].TorF[i-2]=="true") cout<<"True\n\n";
                            else cout<<"False\n\n";
                        }else  cout<<Q[playercount].correct[i-4]<<endl<<endl;
                        }

            }

            cout << "\n\n\t The Score of the Quiz:-\n";
            cout << "    \t ---------------------- \n";

            cout<<"\n\t\t The Player Score is: "<<Q[playercount].G[Q[playercount].num_quiz-2]<<"/12"<<endl;
            cout<<"\n\t\t The Player Score in MCQ Question is: "<<Q[playercount].MC[Q[playercount].num_quiz-2]*2<<"/4"<<endl;
            cout<<"\n\t\t The Player Score in TF Question is: "<<Q[playercount].TF[Q[playercount].num_quiz-2]<<"/2"<<endl;
            cout<<"\n\t\t The Player Score in Complete Question is: "<<Q[playercount].C[Q[playercount].num_quiz-2]*3<<"/6"<<endl;
            cout<<endl<<endl<<endl;

            cout<<"\nat the last quiz player had a quiz at these questions :\n\n";
            for(int i=6;i<12;i++)
            {
                    cout<<"\t"<<Q[playercount].quiz_question[i]<<endl<<endl;
                    if(i<8){
                            cout<<"\t";
                        for(int y=8;y<12;y++)
                        {
                                cout<<"\t";
                                if(y==8)  cout<<"*(a) ";
                                else if(y==9) cout<<"(b) ";
                                else if (y==10) cout<<"(c) ";
                                else cout<<"(d) ";

                            cout<<Q[playercount].mcq_player_ans[y+(4*(i-6))];}
                        cout<<endl<<endl;}
                        cout<<"     The Player Answer : \t\""<<Q[playercount].choice[i]<<"\"\t The Answer was : ";
                        if(Q[playercount].right_or_wrong[i]==1) cout<<"Correct \n\n";
                        else {cout<<"Wrong , and the Correct Answer is : ";
                        if(i<8) cout<<Q[playercount].mcq_player_ans[4*(i-6)]<<endl<<endl;
                        else if(i<10)
                        {
                            if (Q[playercount].TorF[i-6]=="true") cout<<"True\n\n";
                            else cout<<"False\n\n";
                        }else  cout<<Q[playercount].correct[i-8]<<endl<<endl;
                        }
                        }

                        cout << "\n\n\t The Score of the Quiz:-\n";
                        cout << "    \t ---------------------- \n";

                        cout<<"\n\t\t The Player Score is: "<<Q[playercount].G[Q[playercount].num_quiz-1]<<"/12"<<endl;
                        cout<<"\n\t\t The Player Score in MCQ Question is: "<<Q[playercount].MC[Q[playercount].num_quiz-1]*2<<"/4"<<endl;
                        cout<<"\n\t\t The Player Score in TF Question is: "<<Q[playercount].TF[Q[playercount].num_quiz-1]<<"/2"<<endl;
                        cout<<"\n\t\t The Player Score in Complete Question is: "<<Q[playercount].C[Q[playercount].num_quiz-1]*3<<"/6"<<endl;
                        cout<<endl<<endl;

            }


        }



        if(option == 7)
        {
            exit(0);
        }


        }


        cout << "\n   Press any Key : ";
        char z;     cin >> z;   goto Start;


        return 0;
}


 void statistics(int quizn,last_2quiz q)
    {

    cout << "\n\n\t\t == Display Score Statistics == \n\n";

    cout<<"\n\t Your Score Statistics per Quiz:\n";
    cout<<"\n\t Number of Quizzes taken: "<<quizn<<endl;
    int high=-1,low=100;
    double sum=0,summcq=0,sumcq=0,sumtf=0;
    for(int i=0;i<quizn;i++)
    {
        if(q.G[i]>=high)
            high=q.G[i];
        if(q.G[i]<=low)
            low=q.G[i];
        sum+=q.G[i];
        sumcq+=q.C[i];
        summcq+=q.MC[i];
        sumtf+=q.TF[i];
    }
    cout<<"\n\n\t\t Highest quiz score: "<<high<<"/12\n";
    cout<<"\n\t\t Lowest quiz score: "<<low<<"/12\n";
    cout<<"\n\t\t Average quiz score: "<<(sum/quizn)<<"/12\n";
    cout<<"\n\n\tYour score statistics per question type:\n";
    cout<<"\n\t\t Number of MC questions: "<<quizn*2<<endl;
    cout<<"\n\t\t Number of Complete questions: "<<quizn*2<<endl;
    cout<<"\n\t\t Number of T/F Questions: "<<quizn*2<<endl;
    cout<<"\n\t\t Average grade for MC questions: "<<(summcq/quizn)<<"/2\n";
    cout<<"\n\t\t Average grade for Complete questions: "<<(sumcq/quizn)<<"/1\n";
    cout<<"\n\t\t Average grade for T/F questions: "<<(sumtf/quizn)<<"/3\n";
    char cho;
    cout<<"\n\n     Press [B] to Go Back or [E] to Exit\n";
    cout<<"\n\t\t My choice: _"; cin>>cho;
    switch(cho)
    {
    case 'b':
    case 'B':
        break;
    case 'e':
    case 'E':
        exit(0);
        break;
    }
}


void viewallscores(int quizn,last_2quiz q)
{

    cout << "\n\n\t\t == Display All Scores == \n\n";

    cout<<"\n\t Number of quizzes taken : "<<quizn<<endl;
    for(int i=0;i<quizn;i++)
    {
        cout<<"\n\t\t Quiz no."<<i+1<<":"<<endl;
        cout<<"\n\t\t Number of Correct Answers: "<<q.MC[i]+q.C[i]+q.TF[i]<<endl;
        cout<<"\n\t\t Number of Wrong Answers: "<<6-(q.MC[i]+q.C[i]+q.TF[i])<<endl;
        cout<<"\n\t\t The Quiz Grade: "<<q.G[i]<<endl;
    }
}
