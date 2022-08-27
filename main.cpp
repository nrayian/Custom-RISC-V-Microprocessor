#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <stdio.h>

using namespace std;

string toBinary(int num, int noOfBits){
    string s="";
    for(int i=0;i<noOfBits;i++){
        if ((num & (1<<i))!=0){
            s+="1";
        }
        else {
            s+="0";
        }
    }
    reverse(s.begin(),s.end());

    return s;
}
/*char *input_file(){
    string line;
    char *instruction;
    ifstream myfile ("input.txt");
    if (myfile.is_open())
    {
        //for(int a=p;a<=p;a++){
            while(getline(myfile, line)){
            instruction=const_cast<char*>(line.c_str());
            R_type(instruction);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return instruction;
}*/
R_type(char *instruction){
    cout << "v2.0 raw!" << endl;

    string opcode,reg1,reg2,reg3;
    string op,rd,rs,rt;
    char *ins;
    ins=instruction;

    //char *ins=const_cast<char*>(line.c_str());
    for(int i=0;i<strlen(ins);i++){
        if(ins[i]==' '){
            break;
        }
        else{
            opcode.push_back(ins[i]);
            continue;
        }
    }
    int j=3;
    if(opcode=="lw"||opcode=="sw"){
        j=j-1;
    }
    for(int i=j;i<strlen(ins);i++){
        if(ins[i]==','){
            j=8;
            break;
        }
        else if(ins[i]==' '){continue;}
        else{
            reg3.push_back(ins[i]);
            continue;
            }
    }
    if(opcode=="lw"||opcode=="sw"){
        j=j-1;
    }
    cout<<reg3<<endl;
    for(int i=j;i<strlen(ins);i++){
        if(ins[i]==','){
            j=12;
            break;
        }
        else{
            reg1.push_back(ins[i]);
            continue;
        }
    }
    if(opcode=="lw"||opcode=="sw"){
        j=j-1;
    }
    cout<<reg1<<endl;
    for(int i=j;i<strlen(ins);i++){
        if(ins[i]==','){
            break;
        }
        else{
            reg2.push_back(ins[i]);
            j++;
            continue;
        }
    }
    cout<<reg2<<endl;

    if(opcode=="add"){
        op=toBinary(0,3);
    }
    else if(opcode=="lw"){
        op=toBinary(2,3);
    }
    else if(opcode=="sw"){
        op=toBinary(3,3);
    }
    else{
        op=toBinary(1,3);
    }
    cout<<op;

    if(reg1=="$t0"){
        rs=toBinary(0,1);
    }
    else{
        rs=toBinary(1,1);
    }
    cout<<rs;
    if(reg2=="$t0"){
        rt=toBinary(0,2);
    }
    else if(reg2=="$t1"){
        rt=toBinary(1,2);
    }
    else if(reg2=="$t2"){
        rt=toBinary(2,2);
    }
    else{
        rt=toBinary(3,2);
    }
    cout<<rt;

    if(reg3=="$t0"){
        rd=toBinary(0,4);
    }
    else if(reg3=="$t1"){
        rd=toBinary(1,4);
    }
    else if(reg3=="$t2"){
        rd=toBinary(2,4);
    }
    else if(reg3=="$t3"){
        rd=toBinary(3,4);
    }
    else if(reg3=="$t4"){
        rd=toBinary(4,4);
    }
    else if(reg3=="$t5"){
        rd=toBinary(5,4);
    }
    else if(reg3=="$t6"){
        rd=toBinary(6,4);
    }
    else if(reg3=="$t7"){
        rd=toBinary(7,4);
    }
    else if(reg3=="$t8"){
        rd=toBinary(8,4);
    }
    else{
        rd=toBinary(9,4);
    }
    cout<<rd;
    cout<<endl;
    string ifu;

    for(int i=0;i<op.length();i++){
        ifu.push_back(op[i]);
    }
    for(int i=0;i<rs.length();i++){
        ifu.push_back(rs[i]);
    }
    for(int i=0;i<rt.length();i++){
        ifu.push_back(rt[i]);
    }
    for(int i=0;i<rd.length();i++){
        ifu.push_back(rd[i]);
    }
    cout<<ifu;
    cout<<endl;

    long int longint=0;
    int len=ifu.size();
    for(int i=0;i<len;i++)
    {
        longint+=( ifu[len-i-1]-48) * pow(2,i);
    }
    cout<<setbase(16);
    cout<<longint;
    cout<<endl;
    ofstream outfile ("output.txt",ios::app);
    int i;
    //foutput.open ("apnd.txt",ios::app);
    if (outfile.is_open())
    {
        outfile <<setbase(16);
        outfile <<longint;
        outfile << endl;
        outfile.close();
    }
    else cout << "Unable to open file";

}
int main()
{
    cout << "v2.0 raw!" << endl;

    string line;
    char *instruction;
    ofstream outfile ("output.txt");
    int i;
    if (outfile.is_open())
    {
        outfile <<"v2.0 raw"<< endl;
    }
    else cout << "Unable to open file";
    ifstream myfile ("input.txt");
    if (myfile.is_open())
    {
            while(getline(myfile, line)){
            instruction=const_cast<char*>(line.c_str());
            R_type(instruction);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    return 0;
}
