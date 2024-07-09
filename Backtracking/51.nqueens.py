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