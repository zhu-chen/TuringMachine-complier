#include <bits/stdc++.h>
using namespace std;

//settings
const string FILENAME="Turing";
vector<char> alphabet={'B','0','1','+','=','#'};

void write(string q_pre,char char_pre,char char_next,bool direction,string q_next);
void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next);
void movuntil(string q_pre,string target,bool direction,string q_next);
void movstep(string q_pre,int step,bool direction,string q_next);

void work(){ //write your code here
/* test code 
    write("q0",'B','B',1,"q1");
    movuntil("q1",'+',1,0,"q2");
    movstep("q2",4,1,"q3");
*/
    movuntil("q0",'=',1,0,"qadd_1_00");
    //the begin of first step
    write("qadd_1_00",'0','#',0,"qadd_2_00");
    write("qadd_1_00",'1','#',0,"qadd_2_01");
    write("qadd_1_01",'0','#',0,"qadd_2_01");
    write("qadd_1_01",'1','#',0,"qadd_2_10");
    //add the first number
    movstep("qadd_2_00",4,0,"qadd_3_00");
    movstep("qadd_2_01",4,0,"qadd_3_01");
    movstep("qadd_2_10",4,0,"qadd_3_10");
    //move to the second number
    write("qadd_3_00",'0','#',0,"qadd_4_00");
    write("qadd_3_00",'1','#',0,"qadd_4_01");
    write("qadd_3_01",'0','#',0,"qadd_4_01");
    write("qadd_3_01",'1','#',0,"qadd_4_10");
    write("qadd_3_10",'0','#',0,"qadd_4_10");
    write("qadd_3_10",'1','#',0,"qadd_4_11");
    //add the second number
    movstep("qadd_4_00",12,1,"qadd_5_00");
    movstep("qadd_4_01",12,1,"qadd_5_01");
    movstep("qadd_4_10",12,1,"qadd_5_10");
    movstep("qadd_4_11",12,1,"qadd_5_11");
    //move to the end
    write("qadd_5_00",'B','0',0,"qadd_6_00");
    write("qadd_5_01",'B','1',0,"qadd_6_00");
    write("qadd_5_10",'B','0',0,"qadd_6_01");
    write("qadd_5_11",'B','1',0,"qadd_6_01");
    //print the result and calculate the carry
    movuntil("qadd_6_00",'+',0,1,"qadd_0_00");
    movuntil("qadd_6_01",'+',0,1,"qadd_0_01");
    //move to the begin of the first number
    movuntil("qadd_0_00",'#',1,0,"qadd_1_00");
    movuntil("qadd_0_01",'#',1,0,"qadd_1_01");
    //calculate the next digit  
    write("qadd_1_00",'+','+',1,"qadd_7_00");
    write("qadd_1_01",'+','+',1,"qadd_7_01");
    //check the last digit
    movuntil("qadd_7_00",'=',1,1,"qadd_8_00");
    movuntil("qadd_7_01",'=',1,1,"qadd_8_01");
    //move to the last digit
    write("qadd_8_00",'B','0',1,"qa");
    write("qadd_8_01",'B','1',1,"qa");
    //print the result of the last digit and end
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

void movuntil(string q_pre,char target,bool direction,bool direction_next,string q_next){
    for(int i=0;i<alphabet.size();i++){
        if(alphabet[i]==target){
            write(q_pre,alphabet[i],alphabet[i],direction_next,q_next);
        }else{
            write(q_pre,alphabet[i],alphabet[i],direction,q_pre);
        }
    }
}

void movuntil(string q_pre,string target,bool direction,bool direction_next,string q_next){
    for(int i=0;i<alphabet.size();i++){
        if(target.find(alphabet[i])!=string::npos){
            write(q_pre,alphabet[i],alphabet[i],direction_next,q_next);
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