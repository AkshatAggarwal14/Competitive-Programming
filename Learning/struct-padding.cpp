// #pragma pack(1) //! <- this packs all structures in program
/**
 * Structures are user defined data type which are defined from primitive data types
 * todo:
 * ? 1. defining structure
 * ? 2. size of a structure
 * ? 3. Declaring a structure
 * ? 4. Accessing members
 * 
 * *This is created inside stack frame of main function
*/

#include <iostream>
using namespace std;

// definition
struct Rectangle {
    int length;   //4 bytes
    int breadth;  //4 bytes
};                //8 bytes

struct complex {    //a+ib or real+i(imaginary)
    int real;       //4 bytes
    int imaginary;  //4 bytes
};                  //8 bytes

struct Student {
    int roll;          //4 bytes
    char name[25];     //25 bytes <- +3 here
    char dept[10];     //10 bytes
    char address[50];  //50 bytes
};                     //89 + 3 bytes

//! but here struct padding increases the size to 92
//! name makes odd so +3 to make even

struct A {
    char c;       //1 byte
    short int s;  //2 byte
};                //! size is 3+1 = 4 byte

// structure B
struct B {
    short int s;  //2 bytes
    char c;       //1 byte
    int i;        //4 bytes
};                //! 8 bytes size

// structure C
struct C {
    char c;    //1 <-padding of 7 as it reads 8 bytes at a time for double var
    double d;  //8
    int s;     //4 <-padding of 4
};             //! 24

// structure D
struct D {
    double d;  //8
    int s;     //4
    char c;    //1 <- padding of 3
};             //! 16
//! Descending order is best for minimum padding

struct X {
    short s; /* 2 bytes */
             /* 2 padding bytes */
    int i;   /* 4 bytes */
    char c;  /* 1 byte */
             /* 3 padding bytes */
};

struct Y {
    int i;   /* 4 bytes */
    char c;  /* 1 byte */
             /* 1 padding byte */
    short s; /* 2 bytes */
};

struct Z {
    int i;                  /* 4 bytes */
    short s;                /* 2 bytes */
    char c;                 /* 1 byte */
                            /* 1 padding byte */
} __attribute__((packed));  //! <- used to pack the structure with original size

#define sz(x) cout << "sizeof(" << #x << ") = " << sizeof(x) << endl

int main() {
    // Rectangle R;            //declaration
    Rectangle R = {10, 5};  //declare as well as initialise

    R.length = 15;  //dot operator is used to access the member
    R.breadth = 10;

    cout << "Area of rectangle is " << R.length * R.breadth << endl;
    // cout << sizeof(int);
    sz(Rectangle);
    sz(complex);
    sz(Student);
    sz(A);
    sz(B);
    sz(C);
    sz(D);
    sz(X);
    sz(Y);
    sz(Z);
    return 0;
}