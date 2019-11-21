void createGraph(int adjMatrix[][3]);

void insert(int adjMatrix[][3],int vertex_from,int vertex_to, char player);

char checkRows(int adjMatrix[][3]);

char checkCols(int adjMatrix[][3]);

char checkLeftDiagonal(int adjMatrix[][3]);

char checkRightDiagonal(int adjMatrix[][3]);

int elementAt(int adjMatrix[][3], int vertex_from, int vertex_to);

void boardDisplay(char board[][5]);