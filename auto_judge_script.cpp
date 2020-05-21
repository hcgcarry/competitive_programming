#include <iostream>
#include<string>
#include<vector>
#include<cctype>
#include<fstream>
//#include<stdio.h>
using namespace std;

//#define debug 0
#ifdef debug
    #define cout debugfile
    ofstream debugfile;
#endif
#define wrongAnswer "Wrong Answer"
#define Accepted "Accepted"
#define Presentation_Error "Presentation Error"

int main(void){
    #ifdef debug
        debugfile.open("auto_judge_output",ios::trunc | ios::out);
    #endif
    int count;
    int countLoop=0;
    while(cin>>count && count !=0){
        cin.ignore();
        countLoop++;
        string result="";
        string answer="";
        string team_answer="";
        string tmp;
        for(int i=0;i<count;i++){
            getline(cin,tmp);
            answer=answer + tmp;
            if(i!=count-1)answer=answer+ "\n";
            
        }
        
        int tmpint;
        cin >> tmpint;
        cin.ignore();

        //cout << "team_answer" << endl;
        for(int i=0;i<tmpint;i++){
            getline(cin,tmp);
            //team_answer.push_back(tmp);
            team_answer=team_answer + tmp;
            if(i!=tmpint-1)team_answer=team_answer + "\n";
            //cout << tmp << endl;
        }

        //cout << "answer[0]" << answer[0] << endl;
        //cout << "team_answer[0]" << team_answer[0] << endl;
        

        vector<char>answer_int_list;
        vector<char>team_answer_int_list;
        //cout << "answer_int_list: ";
        for(int j=0;j<answer.size();j++){
            char curChar=answer[j];
            if(isdigit(curChar)){
                answer_int_list.push_back(curChar);
                //cout << curChar;
            }
            
        }

        //cout << endl;
        //cout << "team_answer_int_list: ";
        for(int j=0;j<team_answer.size();j++){
            char curChar=team_answer[j];
            if(isdigit(curChar)){
                team_answer_int_list.push_back(curChar);
                //cout << curChar;
            }
        }
        int intlistnotequal=0;

        //cout << endl;
        //cout << "answer:" << answer <<  endl;
        //cout << "team_answer:" << team_answer <<  endl;
        
        if(answer == team_answer){
            result=Accepted;
        }
        else if(answer_int_list == team_answer_int_list){
            result= Presentation_Error;
        }
        else {
            result =wrongAnswer;
        }


        cout << "Run #" << countLoop << ": " << result << endl;
        //cout << countLoop << "-----------------------------------" <<endl;

    }


}