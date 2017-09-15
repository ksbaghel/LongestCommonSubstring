// LongestCommonSubstring.cpp : Defines the entry point for the console application.
/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int max(int a, int b)
{
	return a > b ? a : b;
}

int LongestCommonSubString(string s1, int N1, string s2, int N2)
{
	//in substring matching characters has to be contiguous unline subsequence where only order matters
	vector<vector<int> > LCSuff(N1 + 1, vector<int>(N2 + 1, 0)); //length of Longest Common Suffix ending at (i,j)
	int maxLCS = 0;
	for (int i = 0; i <= N1; i++)
	{
		for (int j = 0; j <= N2; j++)
		{
			if (i == 0 || j == 0)
			{
				LCSuff[i][j] = 0;
			}
			else if (s1[i - 1] == s2[j - 1])
			{
				LCSuff[i][j] = 1 + LCSuff[i - 1][j - 1];
			}
			else {
				LCSuff[i][j] = 0;
			}
			maxLCS = max(maxLCS, LCSuff[i][j]);
		}
	}

	return maxLCS;
}

int LongestCommonSubSequence(string s1, int N1, string s2, int N2)
{
	/*
	LCS[s1(0..x) s2(0...y)] = 1 + LCS[s1(0...x-1), s2(0...y-1)] if(s1[x] == s2[y])
	else                    = max (LCS[(s1(0...x), s2(0...y-1)], LCS[s1(0...x-1), s2(0...y)]);
	*/
	vector<vector<int> > LCS(N1 + 1, vector<int>(N2 + 1, 0));

	for (int i = 0; i <= N1; i++)
	{
		for (int j = 0; j <= N2; j++)
		{
			if (i == 0 || j == 0)
			{
				LCS[i][j] = 0;
			}
			else if (s1[i - 1] == s2[j - 1])
			{
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	return LCS[N1][N2];
}

int main()
{
	int N1, N2;
	//cin >> N1 >> N2;

	string s1, s2;
	cin >> s1 >> s2;

	N1 = s1.length();
	N2 = s2.length();

	cout << "LongestCommonSubSequence : " << LongestCommonSubSequence(s1, N1, s2, N2) << endl;
	cout << "LongestCommonSubString : " << LongestCommonSubString(s1, N1, s2, N2) << endl;
    return 0;
}

