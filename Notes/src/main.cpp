//
// Created by volie on 29.11.2021.
//

#include <iostream>
#include "Note.h"
#include "ListNote.h"
#include "TextNote.h"
#include "NoteDirector.h"
#include <vector>

using namespace std;

int main() {
    NoteDirector Notes;

    TextNote note1("Zakupy");
    ListNote note2("Auta");
    cout << "Podaj pierwsza notatke:\n";
    string line1, line2;
    getline(cin, line1);
    cout << "Podaj druga notatke:\n";
    getline(cin, line2);
    note1.setContent(line1);
    note2.setContent(line2);
    cout << note1.getContent() << endl;
    cout << note2.getContent() << endl;
    Notes.addNote(note1.getContent());
    Notes.addNote(note2.getContent());

    Notes.clearNotesList();

    return 0;
}