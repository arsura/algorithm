#include <iostream>
#include <string>

using namespace std;

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    string str1 = "PIYAPONGSATORN";
    string str2 = "WATTHANACHAI";
    int LCS[100][100];

    string temp;

    cout << str1 << ", " << str2 << endl;

//    for (int i = str1.length() - 1; i >= 0; --i) {
//        temp += str1[i];
//    }
//    str1 = temp;
//    temp.clear();
//
//    for (int i = str2.length() - 1; i >= 0; --i) {
//        temp += str2[i];
//    }
//    str2 = temp;
//    temp.clear();

    cout << endl;

    for (int i = 0; i <= str2.length(); ++i) {
        for (int j = 0; j <= str1.length(); ++j) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            }
            else if (str2[i - 1] == str1[j - 1]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else {
                LCS[i][j] = Max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    for (int j = 0; j < str1.length(); ++j) {
        if (j == 0) cout << "    ";
        cout << str1[j] << " ";
    }
    cout << endl;

    for (int i = 0; i < str2.length() + 1; ++i) {
        if (i == 0) cout << "  ";
        else cout << str2[i - 1] << " ";
        for (int j = 0; j < str1.length() + 1; ++j) {
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;


    char strLCS[100];
    int index = LCS[str2.length()][str1.length()];
    int k = str2.length();
    int l = str1.length();
    while (k > 0 && l > 0) {
        if (str2[k - 1] == str1[l - 1]) {
            strLCS[index - 1] = str2[k - 1];
            k--;
            l--;
            index--;
        }
        else if (LCS[k - 1][l] > LCS[k][l - 1]) k--;
        else l--;
    }

    cout << strLCS << endl;

}












