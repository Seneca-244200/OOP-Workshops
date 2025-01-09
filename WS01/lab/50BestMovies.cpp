#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Movie {
   char m_title[128];
   int m_year;
   char m_rating[6];
   int m_duration;
   char m_genres[10][11];
   float m_consumerRating;
};

FILE* fptr;       
Movie movies[50];

bool loadMovies();
bool hasGenre(const Movie* mvp, const char genre[]);
void displayMovie(const Movie* mvp);
void displayMoviesWithGenre(const char genre[]);
bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);
void flushkeys();
bool yes();
void toLowerCase(char* des, const char* src);

int main() {
   bool done = false;
   char genre[128];
   loadMovies();
   cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
   while (!done) {
      cout << "Enter the movie genre to start the search: ";
      cin >> genre;
      flushkeys();
      displayMoviesWithGenre(genre);
      cout << "Do another search? (Y)es: ";
      done = !yes();
      cout << endl;
   }
   cout << "Goodbye!" << endl;
   return 0;
}

// flushes the keyboard
void flushkeys() {
   while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
   char ch = cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}

// copies src Cstring to des and converts all characters to lowercase
// at the same time.
void toLowerCase(char* des, const char* src) {
   int i = 0;
   while (src[i]) {
      des[i] = src[i];
      if (des[i] >= 'A' && des[i] <= 'Z') {
         des[i] += ('a' - 'A');
      }
      i++;
   }
   des[i] = 0;
}

// loads all the moves into the global array of structures.
bool loadMovies() {
   Movie mv;
   int mnum = 0; // number of movies read
   bool ok = true;
   if (openFile("movies.dat")) {
      while (ok && mnum < 50) {
         ok = readTitle(mv.m_title) &&
            readYear(&mv.m_year) &&
            readMovieRating(mv.m_rating) &&
            readDuration(&mv.m_duration) &&
            readGenres(mv.m_genres) &&
            readConsumerRating(&mv.m_consumerRating);
         if (ok) movies[mnum++] = mv;
      }
      closeFile();
   }
   return mnum == 50;
}

// returns true is the genre arg is substring of any of the
// genres of the target of the mvp (Movie*) argument
bool hasGenre(const Movie* mvp, const char genre[]) {
   int i = 0;
   char userGenre[11] = {};
   char movieGenre[11] = {};
   bool found = false;
   while (!found && mvp->m_genres[i][0]) {
      toLowerCase(userGenre, genre);
      toLowerCase(movieGenre, mvp->m_genres[i]);
      if (strstr(movieGenre, userGenre)) {
         found = true;
      }
      i++;
   }
   return found;
}
// displays the movie info
void displayMovie(const Movie* mvp) {
   int i = 1;
   cout << mvp->m_title << " [" << mvp->m_year << "], "
      << mvp->m_rating << ", duration: " << mvp->m_duration << " minutes, Rating: " << mvp->m_consumerRating << "/10" << endl << "    (" << mvp->m_genres[0];
   while (mvp->m_genres[i][0]) {
      cout << ", " << mvp->m_genres[i++];
   }
   cout << ")" << endl;
}

// displays all the movies containing the genre arg
void displayMoviesWithGenre(const char genre[]) {
   int i, j;
   for (i = 0, j = 1; i < 50; i++) {
      if (hasGenre(&movies[i], genre)) {
         cout << j++ << "- ";
         displayMovie(&movies[i]);
      }
   }
   if (j == 1) {
      cout << "No match found for: " << genre << endl;
   }
}

// opens the data file and returns true is successful
bool openFile(const char filename[]) {
   fptr = fopen(filename, "r");
   return fptr != NULL;
}

// closes the data file
void closeFile() {
   if (fptr) fclose(fptr);
}

// reads the title of the movie from the global fptr File pointer
// returns true if successful
bool readTitle(char title[]) {
   return fscanf(fptr, "%[^(](", title) == 1;
}

// reads the year of the movie from the global fptr File pointer
// returns true if successful
bool readYear(int* year) {
   return fscanf(fptr, "%d)", year) == 1;
}

// reads the year of the movie from the global fptr File pointer
// returns true if successful
bool readMovieRating(char rating[]) {
   return fscanf(fptr, " %[^|]|", rating) == 1;
}

// reads the duration of the movie from the global fptr File pointer
// returns true if successful
bool readDuration(int* duration) {
   return fscanf(fptr, "%d|", duration) == 1;
}

// reads the genras of the movie from the global fptr File pointer
// returns true if successful
bool readGenres(char genre[][11]) {
   char genres[256];
   int gi = 0; //genres index;
   int i = 0;// genre[i] index
   int j = 0;// genre[i][j] index
   bool res = fscanf(fptr, " %[^|]|", genres);
   if (res) { //spreading csv to array of strings
      res = false;
      while (genres[gi]) {
         if (genres[gi] != ',') {
            genre[i][j++] = genres[gi++];
            res = true;
         }
         else {
            genre[i][j] = '\0';
            i++;
            gi++;
            j = 0;
         }
      }
   }
   genre[i++][j] = '\0';
   genre[i][0] = '\0'; // NULL terminating the array of strings
   return res;
}

// reads the consumerRating of the movie from the global fptr File pointer
// returns true if successful
bool readConsumerRating(float* rating) {
   return fscanf(fptr, "%f\n", rating) == 1;
}