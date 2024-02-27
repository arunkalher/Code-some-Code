
// struc [struc_name]{
//     //data_type d1;
//     //data_type d2;
// }
// [struct_variable(optional)];

// #include<stdio.h>
// #include<string.h>
// struct Student{
//     int roll;
//     char name[20];
// }Shyam;
// struct Student Mohan;
// global variables- Shyam,Mohan

// int main()
// {   
//     struct Student Rahul;
//     Rahul.roll=10;
//     Rahul.name[0]='R';
//     Rahul.name[1]='\0';
//     printf("%d",Rahul.roll); // 10
//     printf("%s",Rahul.name); // R
// }

// int main()
// {   
//     struct Student Rahul;
//     Rahul.roll=10;
//     strcpy(Rahul.name,"Rahul");
//     printf("%d",Rahul.roll); // 10
//     printf("%s",Rahul.name); // Rahul
// }

// int main()
// {
// Mohan.roll=1;
// printf("%d",Mohan.roll); // 1
// }

// struct Point
// {
//    int x = 0;  // COMPILER ERROR:  cannot initialize members here
//    int y = 0;  // COMPILER ERROR:  cannot initialize members here
// };


// ### Initialization using Assignment Operator

// int main()
// {
// Rahul.roll=10;
// }


// ### Initialization using Initializer List


#include<stdio.h>
#include<string.h>
struct Point
{
   int x ;  
   int y ;  
   char quadrant[10];
};

// int main()
// {   
//     struct Point p1={1,2};
//     printf("%d,%d",p1.x,p1.y);    //1,1

// }


// int main()
// {   
//     struct Point p1;
//     p1={1,2}; //error
//     printf("%d,%d",p1.x,p1.y);   

// }

int main()
{   
    struct Point p1={.y=2,.x=1};
    strcpy(p1.quadrant,"first");
    printf("%d,%d",p1.x,p1.y);    //1,2

}
