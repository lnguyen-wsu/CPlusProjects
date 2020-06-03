// CS560 - Project - Algorithm A - 2D MAXIMA
// Luan Nguyen - Y383P299
// Detail : Find the maximal set of given points Set based on Algorithm as MergeSort

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>       // read the info from the file
#include <fstream>
#include <sstream>             // conversion string to int
#include <stdio.h>             // cut line into smaller segments 

// using vector to store all the array of of points
using namespace std;
struct Points{
    float x_coor;
    float y_coor;
    bool maximal;
    int where = 1001;  // default is 1000 
    Points operator = (const Points & param);
};
// have to build overloading operator =
Points Points:: operator = (const Points & param){
    x_coor = param.x_coor;
    y_coor = param.y_coor;
    maximal = param.maximal;
    where = param.where;
    return *this;
}

//Print functions
void print_A (Points [], int , int , int);
void print_B (Points [], int , int , int);
void print_final (int [], int [], int [], int[], int);
// declaration of member functions
void get_input();
Points convert_func (string line);
float stringToFloat (string);
// Part1 : member of Mergesort
void MergeSort (Points [], int , int);
void Merge (Points [], int, int , int );
void mergeSort (Points [], int , int, int& , int&);
void merge (Points [], int, int , int, int&, int &);
// Part 2 : Finding the Maxima
void get_maxima (Points [], int,int[], int[], int);
// sub_member function
Points split (const string s);
// main function
int main(){
    get_input();
    return 0;
}
// members functions
void get_input (){
    // 1st read the input file and get info to each array of points
    // cant not use Points[0] -> we must assign POint[0]= 0
    // then use index as exact value 
    //  have to change it into array instead of vector of Points container
    Points list [1001] ={};         // assign the size of array with size 1001 cuz index 0 will not be used
    string line;
    ifstream myfile ("points1.txt");
    // this is only for checking
    int arr_sc[10];                     // tracking sortcount for all 10 sets  
    int arr_st[10];                     // tracking sortTime for all 10 sets
    int arr_maxtime[10];                // tracking maxtime for all 10 sets
    int arr_maxcount[10];               // tracking maxcount for all 10 set
    int track_count = 0;
    int tracking  = 0;                  // used to check the number 1000
    int index = 0;                      // index of each points
    int set_number = 1;
    if(myfile.is_open()){
        // we should put the case in here, use the tracking number to track all the number
        // case special is number with 1000
        // Note: we should build for each case  
        // line is not number 1000
        while(getline (myfile, line)){
            // this line must be single number 1000 as input file
            if ( line == "1000" && tracking == 0 ){
                tracking = 1;
                index = 1;
            }
            // this one for every end of list of Points
            else if (line == "1000" && tracking != 0){
                cout << "********************************"<< endl;
                cout << "Set Number ::::::::::::" << set_number << endl;
                index = 1;
                //MergeSort (list,index,1000);
                int SortCount = 0;
                int SortTime = 0;
                mergeSort (list, index,1000, SortCount, SortTime);
                // make the array to keep tracking each sortCount and SortTime 
                arr_sc[track_count]= SortCount;
                arr_st[track_count]=SortTime;
                print_A (list,1000, SortCount, SortTime);
                get_maxima (list,1000,arr_maxtime, arr_maxcount, track_count);
                track_count ++;
                set_number ++;
            }
            else{
                list[index] = split(line);
                list[index].where = index;
                index++;
            }
        }
        myfile.close();
    }
    cout <<"***************************************" <<endl;
    cout << "Set Number ::::::::::::" << set_number << endl;
    int SortCount = 0;
    int SortTime = 0;
    mergeSort (list, 1,1000, SortCount, SortTime);
    // make the array to keep tracking each sortCount and SortTime 
    arr_sc[track_count]= SortCount;
    arr_st[track_count]= SortTime;
    print_A (list,1000,SortCount, SortTime);
    get_maxima (list, 1000, arr_maxtime, arr_maxcount, track_count);
    print_final(arr_sc, arr_st, arr_maxcount, arr_maxtime, track_count);
}
float stringToFloat (string line){
    stringstream geek(line);
    float x = 0.0000;
    geek>>x;
    return x;
}
Points split (const string str){
    string word;
    vector <string> list;
    stringstream iss (str);
    while (iss >> word)
       list.push_back(word);
    Points temp;
    temp.x_coor = stringToFloat(list[0]);
    temp.y_coor = stringToFloat(list[1]);
    temp.where = 0;
    temp.maximal = false;
    return temp;
}
// test version 1
void MergeSort (Points array [], int p, int r){
    if (p >= r ) return ;
    int q = (p+r)/2;
    MergeSort (array, p, q);
    MergeSort (array , q + 1, r);
    Merge (array, p, q,r);
}
void Merge (Points array [], int p , int q , int r){
    int n1 = q - p + 1;
    int n2 = r -q ;
    Points Left [n1 + 1];
    Points Right [n2 + 1];
    for (int i = 1 ;  i <= n1 ; i++ ){
        Left [i] = array [p + i -1];
    }
    for (int i = 1; i <= n2 ; i++){
        Right[i] = array[q + i];
    }

    Left [n1 + 1].x_coor = 2;
    Left [n2 + 1].x_coor = 2;
    int i =1;
    int j =1;
    
    for (int k = p; k <= r; k++){
        if (Left[i].x_coor <= Right[j].x_coor){
            array[k] = Left[i];
            array[k].where = k;
            i++;
        }else{
            array[k] = Right[j];
            array[k].where = k;
            j++;
        }
    }
}
// test version 2
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r]
void merge(Points arr[], int l, int m, int r,int& SortCount, int &SortTime) 
{  
    int n1 = m - l + 1; 
    int n2 =  r - m;  
    //create temp arrays 
    Points Left[n1];
    Points Right[n2];
    SortTime ++;
    // Copy data to temp arrays Left[] and Right[] 
    for (int i = 0; i < n1; i++){ 
        Left[i] = arr[l + i];
        SortTime ++;
    }
    for (int j = 0; j < n2; j++){ 
        Right[j] = arr[m + 1+ j];
        SortTime ++;
    }
    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (Left[i].x_coor <= Right[j].x_coor) 
        { 
            arr[k] = Left[i];
            i++; 
        } 
        else
        { 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
        SortTime ++;
        SortCount ++;
    }  
    while (i < n1) 
    { 
        arr[k] = Left[i]; 
        i++; 
        k++; 
        SortTime ++;
    }  
    while (j < n2) 
    { 
        arr[k] = Right[j];
        j++; 
        k++;
        SortTime ++;
    } 
} 
  
// l is for left index and r is right index of the 
//   sub-array of arr to be sorted 
void mergeSort(Points arr[], int l, int r, int &SortCount, int &SortTime) 
{ 
    if (l<r){ 
    // Same as (l+r)/2, but avoids overflow for 
    // large l and h 
        int m = l+(r-l)/2; 
    // Sort first and second halves 
        mergeSort(arr, l, m, SortCount, SortTime); 
        mergeSort(arr, m+1, r, SortCount, SortTime);
        merge(arr, l, m, r,SortCount, SortTime);
    }
}
void print_A (Points list [], int last, int SortCount , int SortTime){
    cout << "This is result of List " << endl; 
    cout << "Size of List:  " << last << endl;
    cout << "SortCount: " << " " << SortCount << "  and " 
         << "   SortTime:  "  << " " << SortTime <<endl;
}
void print_B (Points list [], int MaxNumA, int MaxCountA, int MaxTimeA ){
    //cout << " This is the result of this set of Points " <<endl;
    cout << "MaxCountA:  " << MaxCountA << "   and  "
         << "  MaxTimeA:  "  << MaxTimeA << endl;
    cout << "MaxNum A:  " << MaxNumA << endl;
    cout << "List of Maximal Points in the Set of Maxima ::::::  " << endl;
    cout << "Maximal Points ( x , y  )   at postion ---------------" <<endl;
    for ( int i = MaxNumA -1; i >= 0 ; i-- ){
        cout << "Point (  "   
             << list[i].x_coor
             << " , "      
             << list[i].y_coor << "  ) " 
             << " at  " << list[i].where << endl;
    }
}
void print_final (int arr_sc[], int arr_st[], int maxct [], int maxt [] , int size){
    //int num = 0;
    cout << endl;
    cout<< "***************************************************************" <<endl;
    cout << "THIS IS RESULT FOR 10 ITERATION " <<endl;
    cout << "Iteration " << "    " << "Sort Count" << "    "
         << "SortTime"  << "    " << "MaxCountA" << "    "
         << "MaxTimeA"   << "    " << "Sort Time + Max Countt A" << endl;
    for (int i = 0; i<= size ; i++){
        cout << i << "                "
             << arr_sc[i]<< "         " << arr_st[i]<< "       "
             << maxct[i] << "             " << maxt[i]  << "            "
             << arr_sc[i] + maxct[i] << endl;
    }
}
void get_maxima (Points list[], int size, int arr1 [], int arr2[], int track){
    int MaxTimeA = 0;
    float y_max = 0;
    Points S [1000];
    int MaxNumA = 0;             // use for tracking the size of Set Maxima 
    int MaxCountA = 999;
    for (int i = 1000;  i >= 1 ; i--){
        ++ MaxTimeA ;
        if (list[i].y_coor > y_max){
            S[MaxNumA] = list[i];
            list[i].maximal = true;
            y_max = S[MaxNumA].y_coor;
            MaxNumA ++;
        }
    }
    --MaxTimeA;
    arr1[track] = MaxTimeA;
    arr2[track] = MaxCountA;
    print_B (S, MaxNumA,MaxCountA, MaxTimeA );
}
