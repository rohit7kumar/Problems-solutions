#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

const int NumberOfRows = 6;
const int NumberOfColumns = 2;
int main()
{ 
    ifstream FileStream{ "input.txt" };

    // And check, if it could be opened
    if (FileStream) {

        // Define 2D array to hold all data and initialize it with all 0
        char array2D[NumberOfRows][NumberOfColumns]{};

        // Read the rows and columns from the source file
        for (int row = 0; row < NumberOfRows; ++row)
            for (int col = 0; col < NumberOfColumns; ++col)
                FileStream >> array2D[row][col];

                
        // Debug output
        for (int row = 0; row < NumberOfRows; ++row) {
            for (int col = 0; col < NumberOfColumns; ++col)  std::cout << array2D[row][col] << ' ';
            std::cout << '\n';
        }
    }
    else cerr << "\nError: Could not open source file\n\n";

    
    ofstream outfile;
    outfile.open("output1.txt");
    if(outfile.is_open())
    {
        int v,e;
        cin>>v>>e;
        vector<int> g[v+1];
        for(int i=0;i<e;i++)
        {
           int x,y;
           cin>>x>>y;
           g[x].push_back(y);
           g[y].push_back(x);
        }

        for(int i=1;i<=v;i++)
        {
            cout<<i<<"--> ";
            for(int j=0;j<g[i].size();j++)
            {
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
       
        outfile.close();
    }
     
 cout<<"Error\n";
    return 0;
}
