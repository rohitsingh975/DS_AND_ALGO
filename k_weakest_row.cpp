#include <bits/stdc++.h>
using namespace std;

int numOnes( vector<int> row) {
    int lo = 0;
    int hi = row.size();

    while (lo < hi) {
        int mid = (lo + hi) / 2;

        if (row[mid] == 1)
            lo = mid + 1;
        else
            hi = mid;
    }

    return lo;
}

int main() {

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("Input.txt", "r", stdin);
    // for writing output to output1.txt
    freopen("Output.txt", "w", stdout);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr( N , vector<int> (M));

    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            cin >> arr[a][b];
        }
    }

    int score[N];
    int j;
    for (int i = 0; i < N; i++) {
        j = numOnes(arr[i]);
        score[i] = j * N + i;
    }

    sort(score, score + N);

    vector<int>ans(N);
    for (int i = 0; i < N; i++) {
        ans[i] = score[i] % N;
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";

    return 0;
}

/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
     if (a.first == b.first) 
        return a.second < b.second;
    return (a.first < b.first);
}

int main() {

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
        freopen("Input.txt", "r", stdin);
    // for writing output to output1.txt
        freopen("Output.txt", "w", stdout);
    #endif

        int N, M;
        cin >> N >> M;
        int arr[N][M];

        for(int a = 0; a < N; a++)
        {
            for(int b = 0; b < M; b++)
            {
                cin >> arr[a][b];
            }
        }

        int i = 0 , j = M - 1, count = 0;
        vector<pair<int,int>> v;
        while (i < N && j >= 0)
        {
            if (arr[i][j] == 1)
            {
                count = j + 1;
                v.push_back({count,i});
                i++;
                j = M - 1;
            }
            else
            {
                if(j == 0)
                {
                    v.push_back({0,i});
                    i++;
                    j = M - 1;
                }
                else
                {
                    j--;
                }
            }
        }

        sort(v.begin(), v.end(), sortbysec);

        int matsize = v.size();
        for(int i = 0; i < matsize; i++)
        {
             cout << v[i].second << " ";
        }

    return 0;
}*/