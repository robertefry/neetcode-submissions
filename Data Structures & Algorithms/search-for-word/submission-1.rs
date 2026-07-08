
use std::collections::*;

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool
    {
        fn backtrack(
            board: &Vec<Vec<char>>,
            x: usize,
            y: usize,
            word: &[char],
            i: usize,
            visited: &mut HashSet<(usize,usize)>,
        ) -> bool
        {
            if i >= word.len() {
                return true;
            }
            if x >= board.len() || y >= board[x].len() || board[x][y] != word[i] {
                return false;
            }

            if visited.contains(&(x,y)) {
                return false;
            }
            visited.insert((x,y));

            let found = false
                || backtrack(board, x-1, y, word, i+1, visited)
                || backtrack(board, x+1, y, word, i+1, visited)
                || backtrack(board, x, y-1, word, i+1, visited)
                || backtrack(board, x, y+1, word, i+1, visited)
                ;

            if !found {
                visited.remove(&(x,y));
            }
            return found;
        }

        let word: Vec<_> = word.chars().collect();
        let mut visited = HashSet::new();

        for x in 0..board.len() { for y in 0..board[x].len() {
            if backtrack(&board, x, y, &word, 0, &mut visited) {
                return true;
            }
        }}
        return false;
    }
}
