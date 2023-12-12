#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "src/dbnode/include/dbnode/dbnodeOperator.h"
using namespace std;
void split(string& s, char delimiter, vector<int>& elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delimiter)) {
        int itemVal = stoi(item, nullptr, 10);
        elems.push_back(itemVal);
    }
}
int main() {
    string line;
    do {
        getline(cin, line);
    } while (line[0] != '=');
    do {
        // Input the val
        getline(cin, line);
        dbNode* head_ref = new dbNode();
        int tag = 1;
        string line;
        string coord;
        vector<int> lineElement;
        vector<int> coordElement;
        getline(cin, line);
        split(line, ' ', lineElement);
        cin.clear();
        for (auto i : lineElement) {
            pushNew(&head_ref, i, tag);
            cout << i << ' ';
            tag++;
        }

        // Rearrange
        getline(cin, coord);
        split(coord, ' ', coordElement);
        cout << endl;
        cout << "C: ";
        cin.clear();
        dbNode* nDBlink = new dbNode();
        dbNode* temp = head_ref;
        dbNode* newNodeHead = nDBlink;
        for (auto change : coordElement) {
            dbNode* extracted = extract(&head_ref, change);
            nDBlink->next = extracted;
            extracted->prev = nDBlink;
            nDBlink = extracted;
        }
        nDBlink->next = head_ref;
        head_ref->prev = nDBlink;
        newNodeHead = newNodeHead->next;
        while (newNodeHead->next != NULL) {
            cout << newNodeHead->data << " ";
            newNodeHead = newNodeHead->next;
        }
        cout << '\n'
             << endl;
    } while (line[0] != '*');
}