#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> s;

    s.push("Amazon.com");
    s.push("Instagram.com");
    s.push("Netflix.com");
    s.push("Google.com");

    // Safe check before viewing the current page
    if (!s.empty()) {
        cout << "Current page: " << s.top() << endl;
    }

    // First Back
    if (!s.empty()) s.pop();  
    
    // Second Back
    if (!s.empty()) s.pop();  

    // Safe check before viewing the history page after popping
    if (!s.empty()) {
        cout << "After pressing Back twice: " << s.top() << endl;
    } else {
        cout << "No history available (Home Page)\n";
    }

    return 0;
}
