
#include "leetcode.hpp"

class Solution {
public:
  using Position = pair<size_t, size_t>;

  int cost(vector<vector<int>> & dp, size_t S, size_t Mi, vector<Position> const & Ms, vector<Position> const & Os, vector<vector<int>> & ds, size_t T, vector<vector<int>> const & min_MOM) {
    int & ans = dp[S][Mi];
    if (ans != -2) return ans;

    if (Mi == 0) {
      return ans = ds[S][T];
    }

    ans = numeric_limits<int>::max();
    for (size_t i = 0; i < Ms.size(); ++i) {
      if (Mi & (size_t(1) << i)) {
        int tmp1 = cost(dp, i, Mi & ~(size_t(1) << i), Ms, Os, ds, T, min_MOM);
        if (tmp1 == -1) continue;
        int tmp2 = min_MOM[S][i];
        if (tmp2 == -1) continue;
        ans = min(ans, tmp1 + tmp2);
      }
    }
    if (ans == numeric_limits<int>::max()) ans = -1;

    return ans;
  }

  int minimalSteps(vector<string> & maze) {
    Position S;
    vector<Position> Ms;
    vector<Position> Os;
    Position T;
    for (size_t i = 0; i < maze.size(); ++i)
      for (size_t j = 0; j < maze[i].size(); ++j) {
        if (maze[i][j] == 'S') S = { i, j };
        if (maze[i][j] == 'M') Ms.push_back({ i, j });
        if (maze[i][j] == 'O') Os.push_back({ i, j });
        if (maze[i][j] == 'T') T = { i, j };
      }

    Os.push_back(T);
    Ms.push_back(S);

    vector<vector<int>> ds(Ms.size(), vector<int>(Os.size()));
    for (size_t j = 0; j < Os.size(); ++j) {
      auto & O = Os[j];

      vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), -1));
      queue<Position> q;
      q.push(O);
      distance[O.first][O.second] = 0;
      while (!q.empty()) {
        auto e = q.front();
        q.pop();

        for (auto dp : vector<pair<int, int>>{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }) {
          Position p = { e.first + dp.first, e.second + dp.second };
          if (0 <= p.first && p.first < maze.size() && 0 <= p.second && p.second < maze[0].size() && distance[p.first][p.second] == -1 && maze[p.first][p.second] != '#') {
            distance[p.first][p.second] = distance[e.first][e.second] + 1;
            q.push(p);
          }
        }
      }

      for (size_t i = 0; i < Ms.size(); ++i) ds[i][j] = distance[Ms[i].first][Ms[i].second];
    }

    Os.pop_back();

    vector<vector<int>> min_MOM(Ms.size(), vector<int>(Ms.size()));
    for (size_t i1 = 0; i1 < Ms.size(); ++i1)
      for (size_t i2 = 0; i2 < Ms.size(); ++i2) {
        int ans = numeric_limits<int>::max();
        for (size_t j = 0; j < Os.size(); ++j) {
          if (ds[i1][j] != -1 && ds[i2][j] != -1) ans = min(ans, ds[i1][j] + ds[i2][j]);
        }
        min_MOM[i1][i2] = ans == numeric_limits<int>::max() ? -1 : ans;
      }

    Ms.pop_back();

    cerr << "before dp" << endl;

    vector<vector<int>> dp(Ms.size() + 1, vector<int>(size_t(1) << Ms.size(), -2));
    int ans = cost(dp, Ms.size(), (size_t(1) << Ms.size()) - 1, Ms, Os, ds, Os.size(), min_MOM);
    cerr << "after dp" << endl;

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::minimalSteps);
    check(16, { "S#O", "M..", "M.T" });
    check(-1, { "S#O", "M.#", "M.T" });
    check(17, { "S#O", "M.T", "M.." });
    check(22, { "S##O", "..MT", "M..M" });
    check(8, { "S#O", "M.M", "O.T" });
    check(95, { "MMMMM", "MS#MM", "MM#TO" });
    check(484, {
                 "...#............#.....#.#.#...###...................#....#.........#...##........#..................",
                 "...O......##..............#......#.........#...........#...#....#.........#.........................",
                 "..#.#.........#....#........##..............#...................#........O.#...#.........#....#.....",
                 ".....#......#..#.#..#........##...........#.....#..................#........#....#..#...............",
                 ".#........................#...#...#..#..................................#........#.....#............",
                 ".........##......#........##.......#....................#..........O...........#.#.#......#........#",
                 "......#....#.......#.......#..#..................#.#............#............#..............#.......",
                 "............#..#......#.........#........#......#......#....#.............................#.........",
                 "#.#.##....................#...................................#...............#..#..#............#..",
                 "..................................................##.#........#...#..................#......#O.....#",
                 "#.............M................#..#.......................##.....#..........#..............#.#......",
                 "O....#.....#............#...##..........#.......#......#...................#........#...............",
                 "O.........................#.#....#..#............................#..........#.......#..........#....",
                 ".....O.........#.#..........#..........#.................#........##............#....#.......#......",
                 "#......#....#..............#....#............#............#.#.#....#................................",
                 "............##..#.....................#.......##..#.#.#........................................#....",
                 "...........#.......#...#..#............##..#.........#..#..#..#.........#..#.....#...........##.....",
                 "........#......#..#.#...O.....#....#....#............#..........#......#.....................#......",
                 "..#.....#..........#....##.#.....................#.#............##...#........##..........#O...#....",
                 "........#....#.#..........#..#..................................#..#....#...#.....#.....#.........#.",
                 ".#.........#.....................#..#.....#............#.....#.#.........#.......................#..",
                 ".....#............................#......##....#....................................#.#........#..#.",
                 ".#....#.#.........#............#.......................#.......................#.........#......#...",
                 ".......#..........#......................#..#..........#......O.......#..#....#...........O.........",
                 ".#O........M....#.##......O.....#......#.#..#...........#..#...#..#..............................#..",
                 "....................O...M..........#..........#...#.........#.............#...........#.#...........",
                 "#...#.#.....#........#......#.....#...........#...............#.##.....................#..#.........",
                 ".....#................#...................##.......#..#.............##...#..#.......................",
                 ".....##..........................##............#.............#..........#.#..................#......",
                 ".#.....................##.#......#.#.#..........#.#....#................#........#......#...#...#..#",
                 ".........#..........#.........O..............#.....M.................#.....#....#...................",
                 "...........#......#......##..........#....#.....#..........M...........#....#....##.......#.........",
                 "##...................................................#.....#.......##.#.............................",
                 "..........#........##..........#..................#......M.#.#.#.........#..........................",
                 "....#..#..M#.....M.....#..........M...........#.#............................#......................",
                 "..#......#..........#......#..#...##..................#..#...#...................#.......#...#..###.",
                 "..................#..#.#.................T..................#.............#..................#......",
                 "........#.#...#............#.................#...##.#......#..............#.........................",
                 "....#.............#.##.#.........#..##......#.#.#..................................................#",
                 "..#.......#.............#.#....#.#.......................#.....#..........#................#........",
                 "....#.......................#....#.............#....#....#..........##........#..............#......",
                 "#..................#.....O................#....#.#......#.........#......#......................#...",
                 "..........#...........#.......O.......##...........#.....................#.........................#",
                 "..#................................#.............................#.........#...........#............",
                 "..........#.....#.......#..................#............#.........#...#.........O.....#.............",
                 "#...#.............#....#........#......#..#........#..........#.............................#.#.....",
                 ".......#..........#........O#....#...#.........#...........................................#........",
                 ".....##.....#...#..#..#...#....................#......#..#......#...##......O.........#....##.......",
                 "................#.....#.........#.............................O.......#............................#",
                 ".........#.#.................#.....#....#.........#....#............................................",
                 "...#.#...........................#.......#......#............#.#......................###.....O..#..",
                 "...................#.#.#......#.......#...............................#......#....#....#............",
                 "#.#......#....#........#.#..#.#..........##...##.................#..........#.....................#.",
                 ".#....#.......................................#.....#..........#.....M#..........#.....#............",
                 "........#.....................#.#............#...............#.#..O.......#...................#.....",
                 "....#............................#.......#....#.................................................#...",
                 "..................#.#.......#..........#.....#.......#..............#...............#...............",
                 ".........................##.........#......#...............#.O..................##............#.....",
                 "..##......#..#........#.....................#....#......#.................#...........##.......#....",
                 "#..#..#............###..#...............#....#........#..........#..#...........#...............#O..",
                 "#..............................#...............#.#....#..#..#..#......#.......#.##............#.....",
                 "#.......S.......##.....#...........................###.#...........................#.#............#.",
                 ".................................#...........#...........#..........#.....#..#.#...#............#...",
                 "...........#....##.....#.............#..#...................................##....................#.",
                 "M.#....................#.#...O...............................M......O..................#....#.......",
                 "....M#.####........#......................................................#........#................",
                 "......#.#..................#................................................##....#.................",
                 "...#.............................................###..#...#........................#..#.......#.#...",
                 "........#.............O#..#.#....................#..#..#..........#....#.....#......#...#.......#...",
                 ".#..##..................#........#..........#........#....#.........##O...............#.....#.......",
                 "#.....#.#.#........#.......##....................#..........#.............#...#...#....##........#.#",
                 "................#.........#...........#.....#.......##....#..............#..........................",
                 "......O........#................##......#.#..................#.........#.............##.............",
                 ".#....#.#.........#...#...............#...........##.....#...........#..........M....#............#.",
                 "..............#...............O.......#......................#....................#...O..#..........",
                 "................#...#.#...#....................#.......#...#..............O.........................",
                 ".#................................##.............#...#.#.....#.#................#..#...#............",
                 ".....#..............#...............#...............................................................",
                 ".......................#....................##..#................#......................#..#.....#..",
                 ".........#..#....................#.............#..#......................#.......#..................",
                 "#..#........#....................................#.....#..............#..........#......#.#.......#.",
                 ".#......................#.....#......#........#....#...#......O#....#.........#....##...............",
                 "...........................#.....#...#.........#..#......#.....M......#....#...#............##...O##",
                 ".......................#...##............#.........#..............#....#....#..#...#.....#.#........",
                 ".#....#.......................#.....#O...#.............................#............#...............",
                 "...#.#..............#....M..............#.#.......#...#...#...#..........#........................##",
                 ".....#................#.#........#......#....................#.....#................................",
                 "....O.....#..................#.#..O...#.........#.......#.#..............#.....#.............#....#.",
                 ".......#..#.#..##......#...................#...............#.#.......#.........#....#......#..#....#",
                 ".....#.............#...#.......#.#.#........##.....#.#.....#....#......#.#...#................#.....",
                 "...............#..........#.#.##...................#.......................#.......##.....#..#.#....",
                 ".................#......#............................#...#...##........................#............",
                 "#........#........#..........#...#........#.#..#..............#...#.#.....#.#.#.#...................",
                 ".........#.#.......###.......#..........#.......#..........................................#........",
                 ".#..................#.....#......##.#...........#..........#.....#..................#............#.#",
                 "..................................................#.........#..#.#.....##....#...........#..........",
                 "......#...........#......#.......#...#.....................#.#............##................#....#..",
                 ".#..........................#........#........#.......#........#...#...........###...........#......",
                 "#...#...#.......#...................................##........O.........#.....#......#...#..........",
                 "#.......#.....#.#....#...#................O...................#..................#.......##.........",
               });
  }
  return 0;
}

Settings;
