# The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
# Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
# Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

# Input: n = 4
# Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
# Example 2:
# Input: n = 1
# Output: [["Q"]]
 
# Constraints:
# 1 <= n <= 9

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        col = set()
        posDiagonal = set()
        negDiagonal = set()

        # pos = r+c, neg = r-c

        result = []
        
        #Initializing board
        board = [["."] * n for _ in range(n)]

        def backtrack(r):
            if r == n:
                boardcopy = ["".join(row) for row in board]
                result.append(boardcopy)
                return

            for c in range(n):
                if c in col or (r+c) in posDiagonal or (r-c) in negDiagonal:
                    continue
                col.add(c)
                posDiagonal.add(r+c)
                negDiagonal.add(r-c)
                board[r][c] = "Q"

                # incrementing rows
                backtrack(r+1)

                # making the board as starting state to backtrack
                col.remove(c)
                posDiagonal.remove(r+c)
                negDiagonal.remove(r-c)
                board[r][c] = "."

        backtrack(0)
        return result