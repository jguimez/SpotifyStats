#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void display(vector<vector<string>> data, int n)
{
    cout << endl;
    for (int i = 0; i < data[n].size(); i++)
    { 
        cout << data[0][i] << "   :   " << data[n][i] << endl;
    }
    cout << endl;
}
void bubbleSort(vector<vector<string>>& data, int n)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << i;
        for (int j = 0; j < data.size(); j++)
        {
            if (data[i][n] > data[j][n])
            {
                iter_swap(data.begin() + i, data.begin() + j);
            }
        }
    }
}
void linearSearch(vector<vector<string>> data, int n, string search)
{
    auto start = high_resolution_clock::now();
    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (data[i][n] == search)
        {
            auto stop = high_resolution_clock::now();
            display(data,i);
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            return;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "No results found." << endl;
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

}
int binary(vector<vector<string>> data, int l, int r, int n, string search)
{
    int mid;
    if (r >= l)
    {
        mid = (l + r) / 2;
        if (data[mid][n] == search)
        {
            return mid + 1;
        }
        else if (data[mid][n] < search)
        {
            return binary(data, mid + 1, r, n, search);
        }
        else
        {
            return binary(data, l, mid - 1, n, search);
        }
    }
    return -1;
}
void binarySearch(vector<vector<string>> data, int n, string search)
{
    int index = binary(data, 0, data.size(), n, search);
    display(data, index);
}
vector<vector<string>> loadData(string filename)
{
    ifstream file(filename, std::ifstream::in);
    vector<vector<string>> data;
    string line;
    int index = 0;
    while (file.good())
    {
        data.push_back({});
        for (int i = 0; i < 18; i++)
        {
            getline(file, line, '\t');
            data[index].push_back(line);
        }
        getline(file, line, '\n');
        data[index].push_back(line);
        index++;
    }
    return data;
}

void Search(vector<vector<string>> data)
{
    string Schoice;
    string Schoice2;
    string search;
    cout << "Please choose what to search for:" << endl;
    cout << "1. name of song" << endl;
    cout << "2. artist's name" << endl;
    cout << "3. Go back to menu" << endl;
    getline(cin, Schoice, '\n');
    cout << "Use what method?" << endl;
    cout << "1. Linear Search" << endl;
    cout << "(The following will automatically sort the array unless it is already sorted by song name or song artist)" << endl;
    cout << "2. Binary Search" << endl;
    getline(cin, Schoice2, '\n');
    cout << "Enter keywords:" << endl;
    getline(cin, search, '\n');
    int choice = stoi(Schoice);
    int choice2 = stoi(Schoice2);
    switch (choice)
    {
        case 1:
            switch (choice2)
            {
            case 1:
                linearSearch(data, 14 , search);
                break;
            case 2:
                 bubbleSort(data, 14);
                 binarySearch(data, 14,search);
                 break;
            default:
                cout << "Error: Invalid choice of search. Going back to main menu." << endl;
                break;
            }
            break;
        case 2:
            switch (choice2)
            {
            case 1:
                linearSearch(data,3,search);
                break;
            case 2:
                bubbleSort(data, 3);
                binarySearch(data, 3, search);
                break;
            default:
                cout << "Error: Invalid choice of search. Going back to main menu." << endl;
                break;
            }
            break;
        case 3:
            cout << "Going back to main menu." << endl;
            break;
        default:
            cout << "Error : Invalid search. " << endl;
            break;
    }
}
void List(vector<vector<string>> data)
{
    cout << "How many should be listed?";
    string Scount;
    getline(cin, Scount, '\n');
    int count = stoi(Scount);
    for (int i = 1; i < count; i++)
    {
        display(data, i);
    }
}
void Sort(vector<vector<string>> data)
{
    string Schoice;
    string Schoice2;
    cout << "Please choose what to sort:" << endl;
    cout << "1. name of song" << endl;
    cout << "2. artist's name" << endl;
    cout << "3. Go back to menu" << endl;
    getline(cin, Schoice, '\n');
    cout << "Use what method?" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Merge Sort" << endl;
    getline(cin, Schoice2, '\n');
    int choice = stoi(Schoice);
    int choice2 = stoi(Schoice2);
    switch (choice)
    {
    case 1:
        switch (choice2)
        {
        case 1:
            bubbleSort(data, 14);
            break;
        case 2:
            
            break;
        default:
            cout << "Error: Invalid choice of sort. Going back to main menu." << endl;
            break;
        }
        break;
    case 2:
        switch (choice2)
        {
        case 1:
            bubbleSort(data, 3);
            break;
        case 2:
            
            break;
        default:
            cout << "Error: Invalid choice of sort. Going back to main menu." << endl;
            break;
        }
        break;
    case 3:
        cout << "Going back to main menu." << endl;
        break;
    default:
        cout << "Error : Invalid sort. " << endl;
        break;
    }
}
int main()
{
    cout << "Building Database..." << endl;

    auto data = loadData("archive/data.txt");

    cout << "Database Ready." << endl;
    string Schoice;
    int choice = 0;
    while (choice != 4)
    {
        cout << "Please choose an operation:" << endl;
        cout << "1. Search by..." << endl;
        cout << "2. List..." << endl;
        cout << "3. Exit" << endl;
        getline(cin, Schoice, '\n');
        choice = stoi(Schoice);
        switch (choice) {
        case 1:
            Search(data);
            break;
        case 2:
            List(data);
            break;
        case 3:
            cout << "Thanks for using SpotifyStats. Have a good day." << endl;
            break;
        default:
            cout << "Invalid choice. please try again" << endl;
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
