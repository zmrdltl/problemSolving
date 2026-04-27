use std::collections::VecDeque;

impl Solution {
    const U: i32 = 1;
    const R: i32 = 2;
    const D: i32 = 4;
    const L: i32 = 8;

    fn mask(x: i32) -> i32 {
        match x {
            1 => Self::L | Self::R,
            2 => Self::U | Self::D,
            3 => Self::L | Self::D,
            4 => Self::R | Self::D,
            5 => Self::L | Self::U,
            6 => Self::R | Self::U,
            _ => 0,
        }
    }

    pub fn has_valid_path(grid: Vec<Vec<i32>>) -> bool {
        let r_len = grid.len();
        let c_len = grid[0].len();

        // (행, 열, 현재 방향, 반대 방향)
        let dirs = [
            (-1, 0, Self::U, Self::D),
            (0, 1, Self::R, Self::L),
            (1, 0, Self::D, Self::U),
            (0, -1, Self::L, Self::R),
        ];

        let mut visited = vec![vec![false; c_len]; r_len];
        visited[0][0] = true;

        let mut q = VecDeque::new();
        q.push_back((0usize, 0usize));

        while let Some((r, c)) = q.pop_front() {
            if r == r_len - 1 && c == c_len - 1 {
                return true;
            }

            for &(dr, dc, cur_dir, opp_dir) in &dirs {
                let nr = r as i32 + dr;
                let nc = c as i32 + dc;

                if nr < 0 || nr >= r_len as i32 || nc < 0 || nc >= c_len as i32 {
                    continue;
                }
                let nr = nr as usize;
                let nc = nc as usize;

                if visited[nr][nc] {
                    continue;
                };

                if Self::mask(grid[r][c]) & cur_dir != 0 && Self::mask(grid[nr][nc]) & opp_dir != 0
                {
                    visited[nr][nc] = true;
                    q.push_back((nr, nc));
                }
            }
        }

        false
    }
}
