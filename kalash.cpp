#include "kalash.h"

kalash::kalash()
{
cout<<"welcome to my program"<<endl;
}

int main(){
    int u;
while(u!=-1){
    int z;
    string b="";
kalash kal;
cout<<"PASSWORD"<<endl;
cin >> z ;
while(b!="quit"){
    switch(z){
case 12341234:
        kalash::calculator();
    break;
case 67899876:
        kalash::ci();
    break;
case 13579:
        kalash::display_multiples();
        break;
case 56788765:
        kalash::adigits();
       break;
case 43211234:
        kalash::display();
       break;
case 23455432:
        kalash::fibonacci();
        break;
case 78900987:
        kalash::armstrong_number();
        break;
case 24680:
        kalash::palindrome_number();
    break;
case 00000:
        kalash::maximum();
    break;
case 00001:
        kalash::minimum();
    break;
case 00002:
        kalash::lcm();
    break;
case 00003:
        kalash::hcf();
    break;
case 00004:
    kalash::lcm2();
    break;
case 00005:
    kalash::timepass();
    break;
case 00006:
    kalash::timepass2();
    break;
case 00007:
    kalash::matrix();
    break;
case 12345:
    kalash::transpose_matrix();
    break;
case 123456:
    kalash::multiply_matrix();
    break;
case 1234567:
    kalash::automorphic_number_generator();
    break;
case 102938:
    kalash::number_name();
    break;
case 444444:
    kalash::tidy_numbers();
    break;
    default:
        cout <<"ACCESS DENIED"<<endl;
        break;
}
cout<<"type in quit to quit this program"<<endl;
cin>>b;
}
cout <<"if you want to CLOSE THE PROGRAM"<<endl;
cout <<"press any no.(leaving -1) if NO"<<endl;
cout <<"press -1 if YES"<<endl;
cin>>u;
return 0;
}
}


kalash::~kalash()
{
cout<<"thanks for using"<<endl;
}
