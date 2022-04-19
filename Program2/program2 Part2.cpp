#include<iostream>
#include<string>
#include<windows.h>
#include<stdio.h>
using namespace std;

struct huffmanTree
{
	int parent;
	int lchild;
	int rchild;
	int weight;
	string flag;
};

struct minnode
{
	char ch;
	int ch_num;
};

void coding(int length, huffmanTree tree[], int n, int& a, int& b)
{
	int i;
	int r, s;
	r = s = length;
	for (i = 0; i < n;i++)
	{
		if ((tree[i].weight < r) && (tree[i].parent == -1))
		{
			r = tree[i].weight;
			a = i;
		}
	}
	for (i = 0; i < n; i++)
	{
		if ((tree[i].weight < s) && (i != a) && (tree[i].parent == -1))
		{
			s = tree[i].weight;
			b = i;
		}
	}
}
void frequent(string str)
{
	int length = str.length();     /*長度*/
	minnode* node = new minnode[length];     /*宣告最0節點*/
	int i, j;
	for (i = 0; i < length; i++)     /*初始化頻度*/
	{
		node[i].ch_num = 0;
	}
	int char_type_num = 0;  /*初始化為0種字元*/
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < char_type_num; j++)
		{
			if (str[i] == node[j].ch || (node[j].ch >= 'a' && node[j].ch <= 'z' && str[i] + 32 == node[j].ch))
			{
				break;
			}
		}
		if (j < char_type_num)
		{
			node[j].ch_num++;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				node[j].ch = str[i] + 32;
			}
			else
			{
				node[j].ch = str[i];
			}
			node[j].ch_num++;
			char_type_num++;
        }
	}

	/*按照頻度從小到大排列*/
	for (i = 0; i < char_type_num; i++)
	{
		for (j = i; j < char_type_num; j++)
		{
			if (node[j].ch_num < node[j + 1].ch_num)  /*如果前一個小於後面一個 兩者交換*/
			{
				int temp;
				char ch_temp;
				temp = node[j].ch_num;
				ch_temp = node[j].ch;
				node[j].ch_num = node[j + 1].ch;
				node[j].ch = node[j + 1].ch;
				node[j].ch_num = temp;
				node[j].ch = ch_temp;
			}
		}
	}

	huffmanTree* huff = new huffmanTree[2 * char_type_num - 1];  /*位於確定char_type_num*/
	huffmanTree temp;
	string* code = new string[2 * char_type_num - 1];
	for (i = 0; i < 2 * char_type_num - 1; i++)    /*節點初始化*/
	{
		huff[i].parent = -1;
		huff[i].lchild = -1;
		huff[i].rchild = -1;
		huff[i].flag = -1;
	}
	for (j = 0; j < char_type_num; j++)   /*將排序後的第0個節點權重值賦予樹節點*/
	{
		huff[j].weight = node[j].ch_num;
	}
	int min1, min2;
	for (int k = char_type_num; k < 2 * char_type_num - 1; k++)   /*賦予0級以上的節點值*/
	{
		coding(length, huff, k, min1, min2);
		huff[min1].parent = k;
		huff[min2].parent = k;
		huff[min1].flag = "0";
		huff[min2].flag = "1";
		huff[k].lchild = min1;
		huff[k].rchild = min2;
		huff[k].weight = huff[min1].weight + huff[min2].weight;
	}
	for (i = 0; i < char_type_num; i++) {
		temp = huff[i];
		while (1) {
			code[i] = temp.flag + code[i];
			temp = huff[temp.parent];
			if (temp.parent == -1)break;
		}
	}
	cout << "encoding result: ";
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < char_type_num; j++)
		{
			if (str[i] == node[j].ch)
				cout << code[j];
		}
	}
    cout << endl<<"code list {" << endl;
	    for (i = 0; i < char_type_num; i++)
		{
		    cout << node[i].ch << ": " << code[i] << endl;
	    }
    cout << "}" << endl;
	/*釋放記憶體*/
	delete[] node;
	node = NULL;
	delete[] huff;
	huff = NULL;
	delete[] code;
	code = NULL;
}
int main(void)
{
	int length = 0;    /*字串長度*/
	string str;        /*目標字串*/
	cout << "Enter characters: ";
	cin >> str;
	frequent(str);    /*求各個字串頻度*/
	cout << endl;
	cout << "decoding result: "<<str;
	return 0;
}
