/*
Q1.Every compiler has intermediate code representation phase. Given the set of expression:a+b+c*d/e+f.
Write a C program that can find the quadruples ofthe given expressionfor intermediate code representation.


Name:Karn Kumar Singh
Roll No:1906181
course code:CSL5404


*/
#include <iostream>
#include <string>
using namespace std;
string inttostring(int n)
{
    string ans = "";
    while (n)
    {
        ans += char('0' + n % 10);
        n /= 10;
    }
    string t = "";
    for (int i = ans.size() - 1; i > -1; i--)
    {
        t += ans[i];
    }
    return t;
}
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    cout << "\nThe set of expression: a+b+c*d/e+f\n"
         << endl;
    cout << "Enter value of a,b,c,d,e and f for above expression:";
    cout << "\na:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;
    cout << "d:";
    cin >> d;
    cout << "e:";
    cin >> e;
    cout << "f:";
    cin >> f;
    int res1 = c * d;
    int res3 = a + b;
    int res2 = res1 / e;
    int res4 = res3 + res2;
    int res5 = res4 + f;
    int ans = 0;
    ans = res5;
    cout << "\nQuadraple format representation of given expression is:\n";
    cout << "\nOperator\tArg1\tArg2\tResult" << endl;
    string result[6][4];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = "";

            result[0][0] = "*";
            result[0][1] = "c=" + inttostring(c);
            result[0][2] = "d=" + inttostring(d);
            result[0][3] = "t1=" + inttostring(res1);

            result[1][0] = "/";
            result[1][1] = "t1=" + inttostring(res1);
            result[1][2] = "e=" + inttostring(e);
            result[1][3] = "t2=" + inttostring(res2);

            result[2][0] = "+";
            result[2][1] = "a=" + inttostring(a);
            result[2][2] = "b=" + inttostring(b);
            result[2][3] = "t3=" + inttostring(res3);

            result[3][0] = "+";
            result[3][1] = "t3=" + inttostring(res3);
            result[3][2] = "t2=" + inttostring(res2);
            result[3][3] = "t4=" + inttostring(res3 + res2);

            result[4][0] = "+";
            result[4][1] = "t4=" + inttostring(res4);
            result[4][2] = "f=" + inttostring(f);
            result[4][3] = "t5=" + inttostring(res4 + f);

            result[5][0] = "=";
            result[5][1] = "t5=" + inttostring(res5);
            result[5][2] = "";
            result[5][3] = inttostring(res5);
        }
    }
    int answer = res5;
    for (int i = 0; i < 6; i++)
    {
        cout << "   " << result[i][0] << "      \t " << result[i][1] << " \t " << result[i][2] << " \t " << result[i][3] << endl;
    }
    cout << "\nResult of above expression  is: " << answer << endl;
}