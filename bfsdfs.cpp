//bfs dfs over adjucenty matrix 
#include<iostream>
using namespace std;
#include<queue>
#include<stack>

void bfs(int mat[6][6], int source){

    bool visited[6]={false};
    queue<int> bfsQ;
    
    visited[source]=true;
    bfsQ.push(source);

    cout<<"BFS Traversal : ";
    while(!bfsQ.empty()){
        int node = bfsQ.front();
        bfsQ.pop();
        cout<<node<<" ";

        for(int i = 0; i<6; ++i){
            if(mat[node][i]==1 && !visited[i]){
                visited[i]=true;
                bfsQ.push(i);
            }
        }
    }   
    cout<<endl;
}

void dfs(int mat[6][6], int start) {
    bool visited[6] = {false};
    stack<int> dfsS;

    dfsS.push(start);

    cout << "DFS Traversal: ";
    while (!dfsS.empty()) {
        int node = dfsS.top();
        dfsS.pop();

            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;
            }

            for (int i = 6 - 1; i >= 0; i--) {
                if (mat[node][i] == 1 && !visited[i]) {
                    dfsS.push(i);
                }
            }
    }
    cout << endl;
}

void printMatrix(int mat[6][6]) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int choice;
    int adjm[6][6] = {{0,1,1,1,0,0}, 
                      {1,0,0,0,1,1},
                      {1,0,0,0,0,0},
                      {1,0,0,0,0,0},
                      {0,1,0,0,0,0},
                      {0,1,0,0,0,0}};
    
    int source = 0;
    do{
        cout<<"Select the Operation :"<<endl
            <<"1.BFS"<<endl
            <<"2.DSF"<<endl
            <<"3.Print"<<endl
            <<"4.Exit"<<endl;
        cout<<"Enter Your Choice :";
        cin>>choice;

        switch (choice)
        {
        case 1:
            bfs(adjm, source);
            break;
        case 2:
            dfs(adjm, source);
            break;
        case 3:
            printMatrix(adjm);
            break;
        case 4:
             cout<<"Work Done!"<<endl;
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }while(choice!=4);
    return 0;
}