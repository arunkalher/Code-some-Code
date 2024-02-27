#  Passing Array to Functions in C-


### Arrays in C are always passed to the function as pointers pointing to the first element of the array.

## Syntax -
### return_type foo ( array_type array_name[size], ...);
### return_type foo ( array_type array_name[], ...);
### return_type foo ( array_type* array_name, ...);



#### But passing an array to function results in array decay due to which the array loses information about its size. It means that the size of the array or the number of elements of the array cannot be determined anymore.


```C
#include<stdio.h>
#include<string.h>

void utility(int arr[])
{   
    // Warning 'sizeof' on array function
    // parameter 'arr' will return size of 'int *' 
    // size lost
     printf("%d",sizeof(arr)/sizeof(arr[0])); // 1
}
int main()
{
    int arr[5]={1,2,3,4,5}; 
    // or int arr[]={1,2,3,4,5}
    // - compiler must be C99 compatible;
    printf("%d",sizeof(arr)/sizeof(arr[0])); //5
    utility(arr);

}
```
```C
void utility(int *arr)
{   
     
    // size lost
     printf("%d",sizeof(arr)/sizeof(arr[0])); // 1
}

```
```C
void utility(int arr[5])
{   
    // Warning 'sizeof' on array function 
    // parameter 'arr' will return size of 'int *' 
    // size lost
     printf("%d",sizeof(arr)/sizeof(arr[0])); // 1
   
}
```

```C
void utility(int arr[7])
{   
    // Warning 'sizeof' on array function
    // parameter 'arr' will return size of 'int *' 
    // size lost
     printf("%d",sizeof(arr)/sizeof(arr[0])); // 1
     printf("%d",arr[5]); // garbage
}

```
```C
void utility(int arr[3])
{   
    // Warning 'sizeof' on array function 
    // parameter 'arr' will return size of 'int *' 
    // size lost
     printf("%d",sizeof(arr)/sizeof(arr[0])); // 1
     printf("%d",arr[4]); // still be 5
   
}

```

### We need to pass size also so that in the calling function we can know the size of array.
```C
void utility(int* arr, int N)
{  
    for(int i=0;i<N;i++)
    printf("%d ",arr[i]);
   
}
int main()
{
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    utility(arr,size);
}

```
```C
void utility(char str[])  
// or char* str or char* [any number] 
//- warning in 0 - although we shoudn't use these
{
  

    printf("%d",strlen(str)); //4
    int i = 0;
    while (str[i] != '\0') {
        printf("%c ", str[i]);
        i++;
    }
    // D e m o
}
 
// Driver program
int main()
{
    char arr[] = "Demo";
 
    utility(arr);
 
    return 0;
}
```

### Passing 2D Array

```C
void print(int arr[][4])  
// error- int arr[3][] or int arr[][]
{
    int i, j;
    for (i = 0; i < R; i++)
      for (j = 0; j < C; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    // int arr[][] = {{1, 2, 3,4}, { 5, 6,7,8}, { 9,0,1,2}}; 
    // Eror - declaration of 'arr' as multidimensional 
    //array must have bounds for all dimensions except the first
    int arr[][4] = {{1, 2, 3,4}, { 5, 6,7,8}, { 9,0,1,2}};
    print(arr);
    return 0;
}
```

### Why - declaration of 'arr' as multidimensional array must have bounds for all dimensions except the first ?

#### In 1D array we can skip bounds for array.
#### Treat 2D as 1D array of arrays ( instead of array of elements), so we can skip first bound. But like in 1D array, compiler need to know type of array ( int, char) to determine size of one block ( also so that indexing or pointer arithmetic can work ) , same way in 2D array we need to specify second bound.
#### Same expanation for multi D arrays.
### Some other ways to pass 2D array    
```C
#include <stdio.h>
void print(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", *((arr+i*n) + j));
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
 
    // We can also use "print(&arr[0][0], m, n);"
    // and "print((int *)arr[0], m, n);"
    print((int *)arr, m, n);
    return 0;
}
```

```C
#include <stdio.h>
 
// n must be passed before the 2D array
void print(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print(m, n, arr);
    return 0;
}

```


```C
#include <stdio.h>
const int N = 3;
 
void print(int arr[][N], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < N; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr, 3);
    return 0;
}
```



```C
#include <stdio.h>
const int M = 4;
 
 
void print(int (*arr)[M], int N)
{
 
    for (int i = 0; i < N; i++)
    {
    for (int j = 0; j < M; j++)
    {
        printf("%d ", arr[i][j]);
    }}
}
 
int main()
{
    int arr[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    print(arr,3);
    return 0;
}

```