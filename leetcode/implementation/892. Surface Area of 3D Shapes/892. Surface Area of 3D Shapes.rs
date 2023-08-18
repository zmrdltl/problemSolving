impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut ans = 0;
        let dr: [i32; 4] = [0, 0, 1, -1];
        let dc: [i32; 4] = [1, -1, 0, 0];
        for r in 0..n {
            for c in 0..n {
                for dir in 0..4 {
                    let nr = r as i32 + dr[dir];
                    let nc = c as i32 + dc[dir];
                    if nr < 0 || nr >= n as i32 || nc < 0 || nc >= n as i32 {
                        ans += grid[r][c];
                        continue;
                    }
                    if grid[r][c] > grid[nr as usize][nc as usize] {
                        ans += grid[r][c] - grid[nr as usize][nc as usize];
                    }
                }
                if grid[r][c] > 0 {
                    ans += 2;
                }
            }
        }
        return ans;
    }
}
