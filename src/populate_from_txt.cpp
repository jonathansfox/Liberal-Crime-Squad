

#include <includes.h>
#include <externs.h>
#include "common\\customMaps.h"

bool populate_from_txt(vector<string> & types, string fileName);

bool populate_from_txt(vector< vector<string> >& types, string fileName, int dimension);

extern vector<file_and_text_collection> text_file_collection;

bool initialize_txt();
bool initialize_txt() {
	bool loaded = true;
	for (file_and_text_collection f : text_file_collection) {
		if (f.superCollection) {
			loaded &= populate_from_txt(*f.super_collection, f.fileName, f.dimensions);

		}
		else {
			loaded &= populate_from_txt(*f.collection, f.fileName);
		}
	}
	return loaded;
}

// populate_from_text extracts plaintext and puts it in a two dimensional vector of strings.
// returns true if file loads, false if not.
static const int line_length = 2048;
bool populate_from_txt(vector< vector<string> >& types, const string fileName, const int dimension)
{
	bool success = false;
	ifstream txtFile;
	char currentLine[line_length];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << "Failed to load " + fileName + "!" << endl;
		getkey();
	}
	else {
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, line_length, '\n');
			const bool notComment = (currentLine[0] && currentLine[0] != '#');
			if (notComment) {
				vector<string> line;
				line.push_back(currentLine);

				for (int i = 0; i < dimension - 1 && !txtFile.eof(); i++) {
					// whether the line is not a comment, and is also the line whose contents are optional
					// Testing until obtain proper data from file
					txtFile.getline(currentLine, line_length, '\n');
					line.push_back(currentLine);
					if (currentLine[0] == '#') {
						cout << "Comment Found" << endl << currentLine << endl;
						getkey();

					}

				}
				types.push_back(line);
			}
		}
		success = true;
	}
	return success;
}

bool populate_from_txt(vector<string> & types, const string fileName)
{
	bool success = false;
	ifstream txtFile;
	char currentLine[line_length];
	txtFile.open(string(artdir) + fileName);
	if (txtFile.fail()) {
		cout << "Failed to load " + fileName + "!" << endl;
		getkey();
	}
	else {
		cout << endl;
		while (!txtFile.eof()) {
			txtFile.getline(currentLine, line_length, '\n');
			const bool notComment = (currentLine[0] && currentLine[0] != '#');
			if (notComment) {
				types.push_back(currentLine);
			}
		}
		success = true;
	}
	return success;
}


