int coordToIndex(int x, int y, int ySize) {
	return x * ySize + y;
}

int* ixToCoord(int ix, int ySize) {
	int* coord = (int*)calloc(2, sizeof(int));
	coord[0] = ix / ySize;
	coord[1] = ix % ySize;
	return coord;
}

int closedIsland(int** grid, int gridSize, int* gridColSize){
	int visited[10000];
	memset(visited, 0, 10000 * sizeof(int));

	int dir[4][2] = {{0, 1},
								{0, -1},
								{1, 0},
								{-1, 0}};
	
	int res = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			int ix = coordToIndex(i, j, *gridColSize);

			if (visited[ix] || grid[i][j] == 1)
				continue;

			int queue[10000];
			int front = 0;
			int rear = -1;
			
			// push back
			rear++;
			queue[rear] = ix;

			visited[ix] = 1;
			
			int normal = 1;
			while (rear >= front) {
				// pop front
				int cur = queue[front];
				front++;

				int* xy = ixToCoord(cur, *gridColSize);
				int x = xy[0];
				int y = xy[1];
				free(xy);
			
				for (int d = 0; d < 4; d++) {
					int nx = x + dir[d][0];
					int ny = y + dir[d][1];
					int nix = coordToIndex(nx, ny, *gridColSize);

					if (nx < 0 || nx == gridSize ||
						ny < 0 || ny == (*gridColSize)) {
						// touch boundary -> not closed
						// do not break while loop
						// keep visit all land in this island
						// otherwise, the island will be partially marked as visited
						// this will transform island from open to closed
						normal = 0; 
						continue;
					}
					else if (visited[nix] || grid[nx][ny] == 1) {
						continue;
					}

					// push back unvisited land children
					rear++;
					queue[rear] = nix;
					visited[nix] = 1; 
				}
			}
			if (normal) {
				res++;
			}
		}
	}
	return res;
}

