#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************
struct Speaker {
    string name;
    string phoneNum;
    string topic;
    double fee;
};

void inputSpeakers(Speaker members[], int size, int& numSpeakers);
void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName);
void displayOneSpeakerInfo(Speaker members[], int numSpeakers, const string& speakerName);
void displayTopicSpeakers(Speaker members[], int numSpeakers, const string& topic);
void displayAllSpeakerInfo(Speaker members[], int numSpeakers);
bool isEmpty(const string& str);
bool testName(Speaker members[], int numSpeakers, const string& speakerName);
bool testTopic(Speaker members[], int numSpeakers, const string& topic);

//****************************************************************************************************

int main() {
    const int SIZE = 10;
    Speaker members[SIZE];
    int numSpeakers = 0;
    string speakerName,
        topic;
    bool nameTest,
        topicTest;
    char topicEntry;

    inputSpeakers(members, SIZE, numSpeakers);

    do {
        cout << "\n---------------------------------------------------------------" << endl;
        cout << "    Enter the name of the speaker you would like to update." << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Name: ";
        getline(cin, speakerName);
        nameTest = testName(members, numSpeakers, speakerName);
        if (nameTest == false) {
            cout << "\nSorry but the name does not exist." << endl;
        }
    } while (nameTest == false);
    updateSpeaker(members, numSpeakers, speakerName);

    do {
        cout << "\n---------------------------------------------------------------" << endl;
        cout << "   Enter the name of the speaker you would like to display." << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Name: ";
        getline(cin, speakerName);
        nameTest = testName(members, numSpeakers, speakerName);
        if (nameTest == false) {
            cout << "\nSorry but the name does not exist." << endl;
        }
    } while (nameTest == false);
    displayOneSpeakerInfo(members, numSpeakers, speakerName);

    do {
        cout << "\n---------------------------------------------------------------" << endl;
        cout << "     Enter the topic you would like to display names for." << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Topic: ";
        getline(cin, topic);
        topicTest = testTopic(members, numSpeakers, topic);
        if (topicTest == false) {
            cout << "\nSorry but nobody is speaking about this topic." << endl;
            cout << "\nDo you have another topic? (Y/N)" << endl;
            cin >> topicEntry;
            if (topicEntry == 'n' || topicEntry == 'N') {
                break;
            }
            cin.ignore();
        }
    } while (topicTest == false);
    displayTopicSpeakers(members, numSpeakers, topic);

    cin.get();
    cout << "\n\n-------------------------------------------------------------" << endl;
    cout << "\t\tSpeakers' Bureau Information" << endl;
    cout << "-------------------------------------------------------------" << endl;
    displayAllSpeakerInfo(members, numSpeakers);

    return 0;
}

//****************************************************************************************************

void inputSpeakers(Speaker members[], int size, int& numSpeakers) {
    char entry;
    for (int i = 0; i < size; ++i) {
        numSpeakers++;
        cout << "\n---------------------------------------------------------------" << endl;
        cout << "\tEnter the following information of speaker " << i + 1 << "." << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Name: ";
        getline(cin, members[i].name);
        while (isEmpty(members[i].name)) {
            cout << "\nSorry but the name could not be empty.\n"
                 << "\nName: ";
            getline(cin, members[i].name);
        }
        cout << "Telephone Number: ";
        getline(cin, members[i].phoneNum);
        while (isEmpty(members[i].phoneNum)) {
            cout << "\nSorry but the telephone number could not be empty.\n"
                 << "Telephone Number: ";
            getline(cin, members[i].phoneNum);
        }
        cout << "Topic: ";
        getline(cin, members[i].topic);
        while (isEmpty(members[i].topic)) {
            cout << "\nSorry but the topic could not be empty.\n"
                 << "Topic: ";
            getline(cin, members[i].topic);
        }
        cout << "Fee: ";
        cin >> members[i].fee;
        while (members[i].fee < 0) {
            cout << "\nSorry but the fees could not be negative.\n"
                 << "\nFee: ";
            cin >> members[i].fee;
        }
        cout << "Do you have another entry? (Y/N): " << endl;
        cin >> entry;
        if (entry == 'n' || entry == 'N') {
            cin.ignore();
            break;
        }
        cin.ignore();
    }
}

//****************************************************************************************************

void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName) {
    cout << "\n---------------------------------------------------------------" << endl;
    cout << "\tPlease enter the speaker's updated information. " << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            cout << "Name: ";
            getline(cin, members[i].name);
            while (isEmpty(members[i].name)) {
                cout << "\nSorry but the name could not be empty.\n"
                     << "\nName: ";
                getline(cin, members[i].name);
            }
            cout << "Telephone Number: ";
            getline(cin, members[i].phoneNum);
            while (isEmpty(members[i].phoneNum)) {
                cout << "\nSorry but the telephone number could not be empty.\n"
                     << "Telephone Number: ";
                getline(cin, members[i].phoneNum);
            }
            cout << "Topic: ";
            getline(cin, members[i].topic);
            while (isEmpty(members[i].topic)) {
                cout << "\nSorry but the topic could not be empty.\n"
                     << "Topic: ";
                getline(cin, members[i].topic);
            }
            cout << "Fee: ";
            cin >> members[i].fee;
            while (members[i].fee < 0) {
                cout << "\nSorry but the fees could not be negative.\n"
                     << "\nFee: ";
                cin >> members[i].fee;
            }
            cin.ignore();
        }
    }
}

//****************************************************************************************************

void displayOneSpeakerInfo(Speaker members[], int numSpeakers, const string& speakerName) {
    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            cout << "\nSpeaker " << i + 1 << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Name "
                 << " " << members[i].name << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Telephone Number "
                 << " "
                 << members[i].phoneNum << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Topic "
                 << " "
                 << members[i].topic << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Fee "
                 << " "
                 << members[i].fee << endl;
        }
    }
}

//****************************************************************************************************

void displayTopicSpeakers(Speaker members[], int numSpeakers, const string& topic) {
    for (int i = 0; i < numSpeakers; i++) {
        if (topic == members[i].topic) {
            cout << "\nSpeaker " << i + 1 << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Name "
                 << " "
                 << members[i].name << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Telephone Number "
                 << " "
                 << members[i].phoneNum << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Topic "
                 << " "
                 << members[i].topic << endl;
            cout << "\t" << setfill('.') << setw(30) << left << "Fee "
                 << " "
                 << members[i].fee << endl;
        }
    }
}

//****************************************************************************************************

void displayAllSpeakerInfo(Speaker members[], int numSpeakers) {
    for (int i = 0; i < numSpeakers; ++i) {
        cout << "\nSpeaker " << i + 1 << endl;
        cout << "\t" << setfill('.') << setw(30) << left << "Name "
             << " "
             << members[i].name << endl;
        cout << "\t" << setfill('.') << setw(30) << left << "Telephone Number "
             << " "
             << members[i].phoneNum << endl;
        cout << "\t" << setfill('.') << setw(30) << left << "Topic "
             << " "
             << members[i].topic << endl;
        cout << "\t" << setfill('.') << setw(30) << left << "Fee "
             << " "
             << members[i].fee << endl;
    }
}

//****************************************************************************************************

bool isEmpty(const string& str) {
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        if (!isspace(str[i])) {
            return false;
        }
    }
    return true;
}

//****************************************************************************************************

bool testName(Speaker members[], int numSpeakers, const string& speakerName) {
    bool nameFound = false;

    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            nameFound = true;
            break;
        }
    }
    return nameFound;
}

//****************************************************************************************************

bool testTopic(Speaker members[], int numSpeakers, const string& topic) {
    bool topicFound = false;

    for (int i = 0; i < numSpeakers; ++i) {
        if (topic == members[i].topic) {
            topicFound = true;
            break;
        }
    }
    return topicFound;
}

/*

---------------------------------------------------------------
        Enter the following information of speaker 1.
---------------------------------------------------------------
Name:

Sorry but the name could not be empty.

Name: Nicholas Ragland
Telephone Number: 314-219-9992
Topic: Art
Fee: 35
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 2.
---------------------------------------------------------------
Name: John Smith
Telephone Number: 314-111-1111
Topic: Art
Fee: 30
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 3.
---------------------------------------------------------------
Name: Olivia Davisson
Telephone Number: 314-222-2222
Topic: Computer Science
Fee: 40
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 4.
---------------------------------------------------------------
Name: Sam Smith
Telephone Number:

Sorry but the telephone number could not be empty.
Telephone Number: 314-219-3333
Topic:

Sorry but the topic could not be empty.
Topic: History
Fee: -12

Sorry but the fees could not be negative.

Fee: 23
Do you have another entry? (Y/N):
N

---------------------------------------------------------------
    Enter the name of the speaker you would like to update.
---------------------------------------------------------------
Name: Julia

Sorry but the name does not exist.

---------------------------------------------------------------
    Enter the name of the speaker you would like to update.
---------------------------------------------------------------
Name: Nicholas Ragland

---------------------------------------------------------------
        Please enter the speaker's updated information.
---------------------------------------------------------------
Telephone Number: 314-999-9999
Topic: Computer Science
Fee: 45

---------------------------------------------------------------
   Enter the name of the speaker you would like to display.
---------------------------------------------------------------
Name: James

Sorry but the name does not exist.

---------------------------------------------------------------
   Enter the name of the speaker you would like to display.
---------------------------------------------------------------
Name: Nicholas Ragland

Speaker 1
        Name ......................... Nicholas Ragland
        Telephone Number ............. 314-999-9999
        Topic ........................ Computer Science
        Fee .......................... 45

---------------------------------------------------------------
     Enter the topic you would like to display names for.
---------------------------------------------------------------
Topic: Poetry

Sorry but nobody is speaking about this topic.

Do you have another topic? (Y/N)
Y

---------------------------------------------------------------
     Enter the topic you would like to display names for.
---------------------------------------------------------------
Topic: Computer Science

Speaker 1
        Name ......................... Nicholas Ragland
        Telephone Number ............. 314-999-9999
        Topic ........................ Computer Science
        Fee .......................... 45

Speaker 3
        Name ......................... Olivia Davisson
        Telephone Number ............. 314-222-2222
        Topic ........................ Computer Science
        Fee .......................... 40



-------------------------------------------------------------
                Speakers' Bureau Information
-------------------------------------------------------------

Speaker 1
        Name ......................... Nicholas Ragland
        Telephone Number ............. 314-999-9999
        Topic ........................ Computer Science
        Fee .......................... 45

Speaker 2
        Name ......................... John Smith
        Telephone Number ............. 314-111-1111
        Topic ........................ Art
        Fee .......................... 30

Speaker 3
        Name ......................... Olivia Davisson
        Telephone Number ............. 314-222-2222
        Topic ........................ Computer Science
        Fee .......................... 40

Speaker 4
        Name ......................... Sam Smith
        Telephone Number ............. 314-219-3333
        Topic ........................ History
        Fee .......................... 23

*/