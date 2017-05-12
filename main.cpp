#include "Test.h"
#include <iostream>
using namespace std;

void printtree(vector<int> min_heap){
    for (std::vector<int>::const_iterator i = min_heap.begin(); i != min_heap.end(); ++i)
    std::cout << *i << ' ';
}

bool odd(int n){
    if ( n % 2 == 0)
        return false;
    else
        return true;

}
bool orderr(vector<int> min_heap,int current)
{
    int left = current*2 + 1;
    int right = current*2 + 2;

    if(current >= min_heap.size()){
        return true;}

    if(left<min_heap.size() && min_heap[current]>min_heap[left]){
        int temp = min_heap[current];
        min_heap[current]=min_heap[left];
        min_heap[current]= temp;

        }

    if(right<min_heap.size() && min_heap[current]>min_heap[right]){
        int temp = min_heap[current];
        min_heap[current]=min_heap[right];
        min_heap[right]= temp;
        }
        return orderr(min_heap, left) && orderr(min_heap, right);
}
vector<int> order(vector<int> min_heap)
{
    int i = 0;
    while(i<=min_heap.size())
    {
        int left = 2*i+1;
        int right = 2*i+2;

        if(left< min_heap.size()){
                if(min_heap[i]>min_heap[left]){
                    int temp = min_heap[i];
                    min_heap[i]=min_heap[left];
                    min_heap[left]= temp;
                }
        }
        if(right < min_heap.size()){
            if(min_heap[i]>min_heap[right]){
                    int temp = min_heap[i];
                    min_heap[i]=min_heap[right];
                    min_heap[right]= temp;
            }
        }
        //odd(left);
        //odd(right);
        i++;
    }


    return min_heap;
}
vector<int> order2(vector<int> min_heap)
{
    int i = min_heap.size();
    while(i >= 0)
    {
        int left = (i-1)/2;
        int right =(i-2)/2;



        if(odd(i)){
            if((left > 0)){
                if(min_heap[i]<min_heap[left]){
                    int temp = min_heap[i];
                    min_heap[i]=min_heap[left];
                    min_heap[left]= temp;
                }
            }
        }
        if(odd(i)==false){
            if((right > 0)){
                if(min_heap[i]<min_heap[right]){
                    int temp = min_heap[i];
                    min_heap[i]=min_heap[right];
                    min_heap[right]= temp;
                    }
            }
        }
        i--;
    }


    return min_heap;
}
vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    int i = 0;
    while(i < min_heap.size())
    {
        if(min_heap[i]==replaced_value){
            min_heap[i] = replacement;
        }
        i++;
    }


    //while(!isMinHeapm(min_heap,0))
           printtree(min_heap);
            min_heap = order(min_heap);
            min_heap = order(min_heap);
            //orderr(this.min_heap,0);
            //min_heap =order2(min_heap);
            printtree(min_heap);
        return min_heap;

}






int main ()
{
    test();
    return 0;
}
