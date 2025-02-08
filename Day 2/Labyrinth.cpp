#include <bits/stdc++.h>
using namespace std;

string bfs(const vector<string>& lab, pair<int, int> start, pair<int, int> end, int n, int m)
{
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
	vector<vector<char>> moveDir(n, vector<char>(m, 0));
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;
	
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	char dchar[4] = {'U', 'D', 'L', 'R'};
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		if (cur == end)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visited[nx][ny] || lab[nx][ny] == '#')
				continue;
			q.push({nx, ny});
			visited[nx][ny] = true;
			parent[nx][ny] = cur;
			moveDir[nx][ny] = dchar[i];
		}
	}
	
	if (!visited[end.first][end.second])
		return "";
	
	string path;
	for (pair<int, int> cur = end; cur != start; cur = parent[cur.first][cur.second])
		path.push_back(moveDir[cur.first][cur.second]);
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
    vector<string> lab;
    int n, m;
    cin >> n >> m;
    
    lab.resize(n); // allocate space for labyrinth rows
    for (int i = 0; i < n; i++)
    {
        cin >> lab[i];
    }

    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lab[i][j] == 'A')
                start = {i, j};
            else if (lab[i][j] == 'B')
                end = {i, j};
        }
    }

    string path = bfs(lab, start, end, n, m);
    if (path == "")
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }
}