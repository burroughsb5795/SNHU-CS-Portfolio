#include<fstream>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<string, int> item_freq; //stores item and freq pairs
    ifstream input_file("input.txt"); //access input file
    ofstream output_file("frequency.dat"); //output to frequency file
    
    // reads items from input file and stores freq in map
    string item;
    while (input_file >> item){
        ++item_freq[item];
    }
    //prints item and freq to the output file
    for (auto i : item_freq) {
        output_file << i.first << ' ' << i.second << endl;
    }

    //menu
    int option;
    do {
        cout << "Menu:" << endl;
        cout << "1. Find frequency of an item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of all items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter a choice: ";
        cin >> option;
        switch (option) {
            // case 1 will ask for the item to search, search the item freq map and return how many times the input file contains that item
            case 1:{
                string item_to_search;
                cout << "Enter the the item to search: " << endl;
                cin >> item_to_search; 
                cout << item_to_search << " appears " << item_freq[item_to_search] << " times." << endl;
                break;
            }
            //case 2 prints the frequency of all items, using a loop to iterate through all of the input file
            case 2:{
                cout << "Item frequency" << endl;
                for (auto i : item_freq){
                    cout << i.first << " " << i.second << endl;
                }
                break;
            }
            // case 3 prints a * for every time an item appears in the input file
            case 3:{
                cout << "Item Histogram" << endl;
                for (auto i : item_freq) {
                    cout << i.first << " ";
                    for (int j = 0; j < i.second; j++){
                        cout << "*";
                    }
                    cout << endl;
                }
                break;
            }
            // case 4 breaks the loop if prompted to exit 
            case 4:{
                break;
            }
            // the default will check that an option is selected between 1 and 4 and break if this condition is not met
            default: {
                cout << "Invalid option, please choose from 1-4" << endl;
                break;
            }
        }
    } while (option != 4);

    return 0;
}