#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define ElemType string
#define INF 0x3f3f3f3f
typedef char** HuffCode;

int N;

typedef struct huffNode {
    double weight;                
    int lchild, rchild, parent;    
} HTNode, * HuffTree;


void select(const HuffTree& HT, int n, int& s1, int& s2);


void reverseChars(char* chs, int len);
‹æ•¸
void createHT(HuffTree& HT, HuffCode& HC, double* w, int n);


void showHuffCode(ElemType data[], HuffCode HC);


int getWPL(HuffTree& HT, int idx, int depth);

int main() {
    N = 26;  

    ElemType data[N] = {"0", "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    double w[N] = { 0,7,2,2,3,11,2,2,6,6,1,1,4,3,7,9,2,1,6,6,8,4,1,2,1,2,1 };

    HuffTree HT;
    HuffCode HC;

    createHT(HT, HC, w, N);

    showHuffCode(data, HC);

    printf("\n");

    cout << "The weighted path length of the HuffmanTree is " << getWPL(HT, N * 2 - 1, 0) << "\n\n";

    system("pause");
    return 0;
}

void select(const HuffTree& HT, int n, int& s1, int& s2) {
    s1 = s2 = 0;
    double min1 = INF;    
    double min2 = INF;   

    for (int i = 1; i <= n; i++) {

        if (HT[i].parent == 0) {

            if (HT[i].weight < min1) {
 
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            }
            else if ((HT[i].weight >= min1) && (HT[i].weight < min2)) {
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}

void reverseChars(char* chs, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = chs[i];
        chs[i] = chs[len - 1 - i];
        chs[len - 1 - i] = temp;
    }
}

void createHT(HuffTree& HT, HuffCode& HC, double* w, int n) {
    int s1, s2, m = 2 * n - 1;               
    char* code;                       
    HT = new HTNode[m + 1];                    

    for (int i = 1; i <= n; i++) {
        HT[i] = { w[i], 0, 0, 0 };
    }

    for (int i = n + 1; i <= m; i++) {
        HT[i] = { 0, 0, 0, 0 };
    }

    for (int i = n + 1; i <= m; i++) {
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    HC = new char* [n];
    code = new char[n];


    for (int i = 1; i <= n; i++) {
        int k = i, f = HT[k].parent, j = 0;
        while (f != 0) {
            if (HT[f].lchild == k) {
                code[j] = '0';
            }
            else if (HT[f].rchild == k) {
                code[j] = '1';
            }
            k = HT[k].parent;
            f = HT[k].parent;
            j++;
        }
        code[j] = '\0';
        reverseChars(code, j);
        HC[i] = new char[n];
        strcpy(HC[i], code);
    }
}

void showHuffCode(ElemType data[], HuffCode HC) {
    cout << "code list{" << endl;
    for (int i = 1; i <= N; i++) {
        cout << data[i] << ": " << HC[i] << "\n";
    }
    cout << "}" << endl;
}

int getWPL(HuffTree& HT, int idx, int depth) {
    if (HT[idx].lchild == 0 && HT[idx].rchild == 0) {
        return HT[idx].weight * depth;
    }
    return getWPL(HT, HT[idx].lchild, depth + 1) + getWPL(HT, HT[idx].rchild, depth + 1);
}
