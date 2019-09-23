#include <bits/stdc++.h>

using namespace std;


/*
利用partition，解决两个问题。1. 快速排序。2. 找到数组中第k大的元素。
*/
int partition(vector<int> &a,int p, int r)
{
	int k = a[r];
	int i = p, j = r;
	while (i<j)
	{
		while (i<j && a[i]>k)i++;
		if (i < j) {
            a[j] = a[i];
            j--;
        }
		while (i<j && a[j]<k)j--;
		if (i < j) {
            a[i] = a[j];
            i++;
        }
	}
	a[i] = k;
	return i;
}



void quickSort(vector<int> &a,int p, int r)
{
	if (p < r)
	{
		int q = partition(a,p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

int selectK(vector<int> &a, int p, int r, int k)
{
	while (p <= r)
	{
		int q = partition(a, p, r);//partition是从大到小排序
		int key = q - p + 1;//q是a[p]到a[r]中第key大的元素的索引
		if (k == key){//找到
            return a[q];
		}
		else if (k < key){//在左边的第k大（不用改k）
            r = q-1;
        }else {//在右边的第(k-key)大
            p = q + 1;
            k = k - key;
        }
	}
}

int main(){
    vector<int> arr={5,1,6,7,9,2,3,8,4};
    //quickSort(arr,0,arr.size()-1);
    cout<<selectK(arr,0,arr.size()-1,5);
}
