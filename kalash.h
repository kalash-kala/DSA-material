#ifndef KALASH_H
#define KALASH_H
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

class kalash
{
    public:

        kalash();

static long digits(long num){
    long tens=0;
    while(num!=0){
        num/=10;
        tens++;
    }
    return tens;
}
static int rev(int num){
int invert=0;
int number=num;
while(number!=0){
  invert*=10;
  invert=invert+number%10;
  number=number/10;
};
return invert;
}

static void calculator(){
    int a,b;
    string calci;
    cout << "calculator" <<endl;
    cout << "enter the value of" <<endl;
while(calci!="CLOSE"){
    cout << "a= ";
    cin >> a ;
    cout << "and"<<endl;
    cout << "b= ";
    cin >> b;
    cout <<"press 1 for multiplication"<<endl;
    cout <<"press 2 for division"<<endl;
    cout <<"press 3 for subtraction"<<endl;
    cout <<"press 4 for addition"<<endl;
    int i,x;
    cin >> i ;
    switch (i){
 case 1:
    x=a*b;
    cout<<x<<endl;
 break;
 case 2:
    x=a/b;
    cout<<x<<endl;
 break;
 case 3:
    x=a-b;
    cout<<x<<endl;
 break;
 case 4:
    x=a+b;
    cout<<x<<endl;
 break;
 default:
    cout <<"NOTHING"<<endl;
 break;};
cout<<"if you want to close calculator enter CLOSE"<<endl;
cout<<"else type any word"<<endl;
cin>>calci;
};
};
static void ci (){
float tci=0,ta=0,p,r,t=1,s;
cout<<"principle value=";
cin>>p;
cout<<"NOTE THAT THE RATE YOU ENTER IS PER ANNUM"<<endl;
cout<<"rate=";
cin>>r;
cout<<"enter the no. of years you want"<<endl;
cin>>s;
cout<<"How do you want to calculate the interest"<<endl;
cout<<endl;
cout<<"yearly"<<endl;
cout<<endl;
cout<<"half-yearly"<<endl;
cout<<endl;
cout<<"quarterly"<<endl;
string time;
cin>>time;
if(time=="half-yearly"){
r/=2;
s*=2;
}
if(time=="quarterly"){
r/=4;
s*=4;
}
    for (float v=1;v<=s;v++){
        float SI = p*r*t/100;

if(time=="half-yearly"){
        cout<<"the compound interest of "<<v/2<<" year is = "<<SI<<endl;
        cout<<endl;
        }
if(time=="quarterly"){
        cout<<"the compound interest of "<<v/4<<" year is = "<<SI<<endl;
        cout<<endl;
        }
if(time=="yearly"){
        cout<<"the compound interest of "<<v<<" year is = "<<SI<<endl;
        cout<<endl;
        }

        p+=SI;

        if(time=="half-yearly"){
        cout<<"the amount of "<<v/2<<" year is = "<<p<<endl;
        cout<<endl;
        }
        if(time=="quarterly"){
        cout<<"the amount of "<<v/4<<" year is = "<<p<<endl;
        cout<<endl;
        }
        if(time=="yearly"){
        cout<<"the amount of "<<v<<" year is = "<<p<<endl;
        cout<<endl;
        }
        tci+=SI;
        ta=p;
        };
    if(time=="half-yearly"){
        cout<<endl;
        cout<<"the total compound interest for "<<s/2<<" years is="<<tci<<endl;}
    if(time=="quarterly"){
        cout<<endl;
        cout<<"the total compound interest for "<<s/4<<" years is="<<tci<<endl;}
    if(time=="yearly"){
        cout<<endl;
        cout<<"the total compound interest for "<<s<<" years is="<<tci<<endl;}
        cout<<endl;
        cout<<"total amount is ="<<ta<<endl;
        };
static void display_multiples(){
int sum=0;
int pro=1;
int v;
cout<<"ENTER THE STARTING VALUE:"<<endl;
cin>>v;
int n;
cout<<"ENTER THE END VALUE:"<<endl;
cin>>n;
int k;
cout<<"ENTER THE NO. WHOSE MULTIPLES YOU WANT"<<endl;
cin>>k;
int c;
cout<<"press 1 to add the no. between them"<<endl;
cout<<"press 2 to multiply the no. between them"<<endl;
cin>>c;
int kalash;
    for(int x=v; x<=n; x++){
  if(x%k==0){
  kalash=x;
  if(c==1){
  sum+=kalash;
  }else if(c==2){
  pro*=kalash;
  };
  };
};
if(c==2)
    cout<<"the product of the numbers is "<<pro<<endl;
    else
    cout<<"the sum of the numbers is "<<sum<<endl;
};
static void adigits(){
int num=0;
int sum=0;
int nod=0;
int pro=1;
int val;
cout<<"ENTER THE NO."<<endl;
cin>>num;
cout<<"ENTER THE NO. OF DIGITS"<<endl;
cin>>nod;
cout<<"press 1 for adding the digits"<<endl;
cout<<"press 2 for multiplying the digits"<<endl;
cin>>val;
for(int l=1;l<=nod;l++){
if(val==1){
int mod= num%10;
sum+=mod;
num=num/10;
}else if(val==2){
int mod=num%10;
pro*=mod;
num=num/10;
};};
if(val==1)
cout<<"the sum of its digits is = "<<sum<<endl;
else
cout<<"the product of its digits is = "<<pro<<endl;
};
static void display(){int h,c;
long m;
cout<<"enter the starting no."<<endl;
cin>>c;
cout<<"enter the last no."<<endl;
cin>>m;
cout<<"press the no. whose multiples you want"<<endl;
cin>>h;
long y=1;
int x;
    for(x=c; x<=m; x++){
      if(x%h==0){
      cout<<y<<"  ---------  "<<x<<endl;
      y++;
};};};
static void fibonacci(){
int noe,x;
long third;
long first=0,second=1;
cout<<"enter the no. of elements you want"<<endl;
cin>>noe;
for(x=0;x<noe;x++){
if(x<=1){
cout<<x<<endl;
}
if(x>=2){
third=first+second;
first=second;
second=third;
cout<<third<<endl;
}
}
}
static void armstrong_number(){
int number,mod_number=0;
cout<<"enter the number"<<endl;
cin>>number;
int number_2=number;
int digits;
cout<<"enter the number of digits the number you have entered has"<<endl;
cin>>digits;
for(int x=1;x<=digits;x++){
int mod=number%10;
number/=10;
mod_number+=mod*mod*mod;
}
if(mod_number==number_2)
cout<<"the number "<<number_2<<" is an armstrong number"<<endl;
else
cout<<"the number "<<number_2<<" is not an armstrong number"<<endl;
}
static void palindrome_number(){
int number,number_2,invert=0;
cout<<"enter the number"<<endl;
cin>>number;
number_2=number;
while(number!=0){
  invert*=10;
  invert=invert+number%10;
  number=number/10;
}
if(invert==number_2)
cout<<"the number "<<number_2<<" is a palindrome number"<<endl;
else
cout<<"the number "<<number_2<<" is not a palindrome number"<<endl;
}
static void maximum(){
int noe,number;
cout<<"enter the no of elements you wish to enter"<<endl;
cin>>noe;
int arg[noe];
for(number=0;number<noe;number++){
    cout<<"enter the "<<number+1<<" elements"<<endl;
    cin>>arg[number];
    if(arg[0]<arg[number])
       arg[0]=arg[number];
}
cout<<"the largest no. in the following elements is = "<<arg[0]<<endl;
}
static void minimum(){
int noe,number;
cout<<"enter the no. of elements you wish to enter"<<endl;
cin>>noe;
int arg[noe];
for(number=0;number<noe;number++){
    cout<<"enter the "<<number+1<<" elements"<<endl;
    cin>>arg[number];
    if(arg[0]>arg[number])
    arg[0]=arg[number];
}
cout<<"the smallest no. in the following elements is = "<<arg[0]<<endl;
}
static void lcm(){
long first,second,product,mini,iii;
cout<<"enter the first no."<<endl;
cin>>first;
cout<<"enter the second no."<<endl;
cin>>second;
product=first*second;
mini=(first>second)?first:second;
for(iii=mini;iii<=product;iii++){
    if((iii%first==0)&&(iii%second==0)){
     cout<<"the lcm of "<<first<<" and "<<second<<" is "<<iii<<endl;
    break;}
}
}
static void hcf(){
long first,second,maxin,iii;
cout<<"enter the first no."<<endl;
cin>>first;
cout<<"enter the second no."<<endl;
cin>>second;
maxin=(first<second)?first:second;
for(iii=maxin;iii>=0;iii--){
    if((first%iii==0)&&(second%iii==0)){
        cout<<"the hcf of "<<first<<" and "<<second<<" is "<<iii<<endl;
        break;}
}
}
static void lcm2(){
int noe,lcm1,product=1;
cout<<"enter a number of elements"<<endl;
cin>>noe;
int arg[noe];
for(int i=0;i<noe;i++){
    cout<<"enter the "<<i<<" term"<<endl;
    cin>>arg[i];
    product*=arg[i];
    }
}
static void timepass(){
int num,num2,sum=0,i,
a=0;
cout<<"enter the number of elements"<<endl;
cin>>num;
    num2=1;
for(i=1;i<=num;i++){
    if(i%2==0){
        a=num2*-1;
        cout<<a<<" ";
        sum+=a;
    }
    else{
        a=num2*1;
        cout<<a<<" ";
        sum+=a;
    }
    num2+=2;
}
cout<<endl;
cout<<sum<<endl;
}
static void timepass2(){
int noe,iii,factorial=1;
double x;
cout<<"enter the number of elements"<<endl;
cin>>noe;
cout<<"enter the value for x"<<endl;
cin>>x;
for(iii=1;iii<=noe;iii++){
    for(int y=1;y<=(iii+1);y++){
        factorial*=y;
    }
    if(iii%2==0){
        x+= -(pow(x,iii)/factorial);
    }
    else{
        x+=(pow(x,iii)/factorial);
    }
}
cout<<"the sum is "<<x<<endl;
}
static void matrix(){
string opinion;
int row,column;

cout<<"enter the number of rows"<<endl;
cin>>row;
cout<<"enter the number of column"<<endl;
cin>>column;
cout<<"do you want to add of subtract"<<endl;
cin>>opinion;

int arg[row][column];
int arg2[row][column];

//storing the values of first matrix

cout<<"enter the elements of the first matrix"<<endl;
for(int i=1;i<=row;i++){
    for(int j=1;j<=column;j++){
        cin>>arg[i][j];
    }
}

cout<<endl;

//storing the values of second matrix

cout<<"enter the elements of the second matrix"<<endl;
for(int ii=1;ii<=row;ii++){
    for(int jj=1;jj<=column;jj++){
        cin>>arg2[ii][jj];
    }
}

int arg3[row][column];

//decision to take  whether to add or subtract

if(opinion=="add")
    cout<<"the sum of two matrices is = "<<endl;
else
    cout<<"the subtraction of 2 matrices is = "<<endl;
for(int iii=1;iii<=row;iii++){
    for(int jjj=1;jjj<=column;jjj++){
            if(opinion=="add"){
                arg3[iii][jjj]=arg[iii][jjj]+arg2[iii][jjj];
                cout<<arg3[iii][jjj]<<"        ";
            }
            else if(opinion=="subtract"){
                arg3[iii][jjj]=arg[iii][jjj]-arg2[iii][jjj];
                cout<<arg3[iii][jjj]<<"        ";
            }
    }
cout<<endl;
}
}
static void transpose_matrix(){
int row,column;

cout<<"enter the number of rows"<<endl;
cin>>row;
cout<<"enter the number of column"<<endl;
cin>>column;
int arg[row][column];

//loop for taking storing element values of multidimensional array

for(int ii=1;ii<=row;ii++){
    for(int jj=1;jj<=column;jj++){
        cin>>arg[ii][jj];
    }
}
cout<<endl;

//" swap " function to swap the value of of row and column

swap(row,column);

//loop for finding the transpose of the matrix entered

cout<<"the transpose of the matrix is "<<endl;
for(int iii=1;iii<=row;iii++){
    for(int jjj=1;jjj<=column;jjj++){
        cout<<arg[jjj][iii]<<" ";
    }
    cout<<endl;
}
}
static void multiply_matrix(){
int row,column,row2,column2,lll,kkk;

cout<<"enter the no. of rows of matrix 1"<<endl;
cin>>row;
cout<<"enter the no. of column of matrix 1"<<endl;
cin>>column;
int mat1[row][column];

cout<<endl;

cout<<"enter the no. of rows of matrix 2"<<endl;
cin>>row2;
cout<<"enter the no. of column of matrix 2"<<endl;
cin>>column2;
int mat2[row2][column2];

cout<<endl;

// storing the values of multidimensional arrays

cout<<"enter the element of matrix 1"<<endl;
for(kkk=1;kkk<=row;kkk++){
        cout<<"enter the elements of row "<<kkk<<endl;
    for(lll=1;lll<=column;lll++){
        cout<<"enter element"<<lll<<endl;
        cin>>mat1[kkk][lll];
    }
}

cout<<endl;

cout<<"enter the elements of matrix 2"<<endl;
for(kkk=1;kkk<=row2;kkk++){
        cout<<"enter the elements of row "<<kkk<<endl;
    for(lll=1;lll<=column2;lll++){
        cout<<"enter the element "<<lll<<endl;
        cin>>mat2[kkk][lll];
    }
}

// matrix can inly be multiplied if column of 1st matrix is = to row of 2nd matrix

if(column==row2){
    int mult[row][column2];
//initializing values of mult array to 0

for(kkk=1;kkk<=row;kkk++){
    for(lll=1;lll<=column2;lll++){
        mult[kkk][lll]=0;
    }
}

// multiplication of matrix

for(int iii=1;iii<=row;iii++){
    for(int jjj=1;jjj<=column2;jjj++){
        for(int hhh=1;hhh<=column;hhh++){
            mult[iii][jjj]+=mat1[iii][hhh]*mat2[hhh][jjj];
        }
    }
}

// displaying the output

for(kkk=1;kkk<=row;kkk++){
    for(lll=1;lll<=column2;lll++){
        cout<<" "<<mult[kkk][lll];
        }
    cout<<endl;
    }
}
}
static void automorphic_number_generator(){
int number,number2;
cout<<"enter the range of automorphic numbers you want"<<endl;
cin>>number;
cin>>number2;
cout<<"the automorphic numbers are"<<endl;
for(int iii=number;iii<=number2;iii++){
    int power=pow(10,digits(iii));
    if(iii*iii%power==iii){
        cout<<iii<<endl;
    }
}
}
static void number_name(){
float num2=0,hold=0,num=0;
int check[2]={-1,-1},unit_check=0,tens=0,digit=0;
string units_arg[10]={""," one"," two"," three"," four"," five"," six"," seven"," eight"," nine"};
string ten_arg[10]={" ten"," eleven"," twelve"," thirteen"," fourteen"," fifteen"," sixteen"," seventeen"," eighteen"," nineteen"};
string tens_arg[10]={"",""," twenty"," thirty"," forty"," fifty"," sixty"," seventy"," eighty"," ninety"};
cout<<"enter a number"<<endl;
cin>>num2;
hold=modf(num2,&num);
/** negative part**/
if(num<0){
    cout<<"minus";
    num*=-1;
    hold*=-1;
}
int inverse=rev(num);
/**positive part**/
for(int iii=digits(num);iii>=1;iii--){
    switch(iii){
case 2:
    tens=(int)num%10;
    break;
case 5:
    tens=((int)num/1000)%10;
    break;
case 8:
    tens=((int)num/1000000)%10;
    break;
case 11:
    tens=((int)num/1000000000)%10;
    break;
    }
        digit=inverse%10;
        unit_check=digit;

    if((iii==1)||(iii==4)||(iii==7)||(iii==10)){
            if(check[0]!=1){
        cout<<units_arg[digit];
    }
    }
    else if((iii==2)||(iii==5)||(iii==8)||(iii==11)){
        check[0]=digit;
        if(digit==1){
        cout<<ten_arg[tens];
        }else{
        cout<<tens_arg[digit];
        }
    }
    else if((iii==3)||(iii==6)||(iii==9)||(iii==12)){
            check[1]=digit;
            if(digit!=0){
            if(((inverse/10)%10==0)&&((inverse/10)%100==0)){
        cout<<units_arg[digit]<<" hundred";
        }else{
        cout<<units_arg[digit]<<" hundred and";
        }}
    }
        if(iii==4){
            if((unit_check!=0)||(check[0]!=0)||(check[1]!=0)){
            cout<<" thousand";
        }
        }
        if(iii==7){
            if((unit_check!=0)||(check[0]!=0)||(check[1]!=0)){
                cout<<" million";
            }
        }
        if(iii==10){
            if((unit_check!=0)||(check[0]!=0)||(check[1]!=0)){
                cout<<" billion";
            }
        }
        inverse/=10;
    }
    /**decimal part**/
    if(hold!=0){
    cout<<" point";
        float point=-1;
    while(point!=0){
        hold*=10;
        point=modf(hold,&num2);
    }
    inverse=rev((int)hold);
    while(inverse!=0){
        digit=inverse%10;
        if(digit==0){
            cout<<" zero";
        }else{
        cout<<units_arg[digit];}

        inverse/=10;
    }
}
    cout<<endl;
}
static void tidy_numbers(){
int num=0,digit=0,i=0;
cout<<"enter a number"<<endl;
cin>>num;
int reserve=num;
bool check;
while(num!=0){
    digit++;
    num/=10;
}int arg[digit];
for(i=0;i<digit;i++){
    arg[i]=reserve%10;
    reserve/=10;
}
for(i=0;i<digit-1;i++){
    if((arg[i]<=arg[i+1])&&(digit!=1)){
        check=false;
        break;
    }else{
        check=true;
    }
}
     if(digit==1){
        check=true;
    }
if(check){
    cout<<"tidy number"<<endl;
}else{
    cout<<"not tidy number"<<endl;
}
}
~kalash();
    protected:
    private:
};

#endif // KALASH_H
