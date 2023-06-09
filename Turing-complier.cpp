#include <bits/stdc++.h>
using namespace std;

//settings
const string FILENAME="Turing";
vector<char> alphabet={'B','0','1','+','=','#'};

void write(string q_pre,char char_pre,char char_next,bool direction,string q_next);
void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next,char target_next='Z');
void movuntil(string q_pre,string target,bool direction,bool direction_next,string q_next,char target_next='Z');
void movstep(string q_pre,int step,bool direction,string q_next);

void work(){ //write your code here

}

/*
complier
direction:1 R 0 L
*/

int main(){
    freopen((FILENAME+".out").c_str(),"w",stdout);
    work();
    return 0;
}

void write(string q_pre,char char_pre,char char_next,bool direction,string q_next){
    cout<<q_pre<<","<<char_pre<<","<<char_next<<","<<(direction?'R':'L')<<","<<q_next<<endl;
}

void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next,char target_next){
    for(int i=0;i<alphabet.size();i++){
        if(alphabet[i]==target){
            write(q_pre,alphabet[i],(target_next=='Z')?alphabet[i]:target_next,direction_next,q_next);
        }else{
            write(q_pre,alphabet[i],alphabet[i],direction,q_pre);
        }
    }
}

void movuntil(string q_pre,string target,bool direction,bool direction_next,string q_next,char target_next){
    for(int i=0;i<alphabet.size();i++){
        if(target.find(alphabet[i])!=string::npos){
            write(q_pre,alphabet[i],(target_next=='Z')?alphabet[i]:target_next,direction_next,q_next);
        }else{
            write(q_pre,alphabet[i],alphabet[i],direction,q_pre);
        }
    }
}

void movstep(string q_pre,int step,bool direction,string q_next){
    for(int i=0;i<alphabet.size();i++){
        write(q_pre,alphabet[i],alphabet[i],direction,q_pre+"_step"+(char)(step-1+'0'));
    }
    for(int i=step-2;i;i--){
        for(int j=0;j<alphabet.size();j++){
            write(q_pre+"_step"+(char)(i+1+'0'),alphabet[j],alphabet[j],direction,q_pre+"_step"+(char)(i+'0'));
        }
    }
    for(int i=0;i<alphabet.size();i++){
        write(q_pre+"_step1",alphabet[i],alphabet[i],direction,q_next);
    }
}