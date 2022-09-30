#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#pragma region 建立顺序存储的线性表

#define MAX 30
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)

typedef struct {
	int data[MAX];
	int length;
}List;

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

//给定一个List，传入List的大小，要逆转的起始位置
void Reserve(List& list, int start, int end, int size) {
	if (end <= start || end >= size) {
		return;
	}
	int mid = (start + end) / 2;
	_rep(i, 0, mid - start) {
		swap(list.data[start + i], list.data[end - i]);
	}
}

void PrintList(List list) {
	_for(i, 0, list.length) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

#pragma endregion

//P18.5
//从顺序表中删除其值在给定值s与t之间(包含s和t, 要求s < t)的所有元素,
//如果s或t不合理或顺序表为空, 则显示出错信息并退出运行

void DeleteS_T(List& list, int S, int T) {
	if (S >= T || !list.length)
		return;

	for (int i = 0; i < list.length; i++) {
		if (list.data[i] >= S && list.data[i] <= T) {
			for (int j = i + 1; j < list.length; j++) {
				list.data[j - 1] = list.data[j];
			}
			//要重新回退一个位置，重新检测，否则会跳过某些数字
			if (i)
				i -= 1;
			list.length -= 1;
		}
	}
}

//方法2：从前向后扫描顺序表L，用k记录下元素值在s到t之间元素的个数（初始时k=0）。
//对于当前扫描的元素，若其值不在s到1之间，则前移k个位置；
//否则执行k++。由于这样每个不在s到t之间的元素仅移动一次，因此算法效率高。
bool Del s t2（SqList ＆L，ElemType s，ElemType t）｛
int i，j；
if （s>=t！L.length==0）
return false；
for（i=0；i<L.length＆＆L.data［i］<s；i++）；//寻找值大于等于s的第一个元素
if（i>=L.length）
return false；
//所有元素值均小于s，返回
for（j=i；j<L.length＆＆L.data［j］<=t；j++）；//寻找值大于t的第一个元素
for（；j<L.length；i++，j++）
L.data［i］=L.data［j］；
//前移，填补被删元素位置
L.length=i；
return true；
｝

int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,9,5,11,5,24,14,44 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	DeleteS_T(list, 4, 11);
	PrintList(list);
}
