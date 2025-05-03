// Flight representation using adjustency matrix
#include <iostream> 
using namespace std;

class Flights{

int n;

string cities [10];

int time[5][5];

public:

void getData(){
    cout << "Enter number of cities:";

    cin >> this->n;

    cout << "Enter the city names: " << endl;

    for (int i = 0; i < n; ++i)

        cin >> cities[i];

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; ++j)
        {

            cout << "Enter the time taken from " << cities[i] << " to"<<cities[j]<<" : ";
            cin>>time[i][j];
            time[j][i]=time[i][j];
        }
    }

}



void display(){
    cout << endl
         << endl;

    cout << "Chart for time taken from one city to another: " << endl;

    for (int i = 0; i < n; i++)
    {

        cout << "\t" << cities[i];
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {

        cout << cities[i];

        for (int j = 0; j < n; ++j)
        {
            cout << "\t" << time[i][j];
        }

        cout << endl;
    }

}
}
;
int main()
{
    Flights f;
    f.getData();
    f.display();

    return;
}