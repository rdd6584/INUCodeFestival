#include <bits/stdc++.h>
#include <io.h>

/*
    Codeforces Polygon data to BOJ Stack data
    1. Make, two folders "./in", "./out"
    2. Make, a folder "./tests/" with data
    3. Run
*/

int main() {
    _finddata_t c_file;
    intptr_t hFile;
    char f_name[FILENAME_MAX] = "";

    hFile = _findfirst("./tests/*.a", &c_file);
    do {
        sscanf(c_file.name, "%[^(.a)]", f_name);
        char tmp[FILENAME_MAX] = "./tests/";
        char dir[FILENAME_MAX] = "./out/";
        strcat(dir, f_name);
        rename(strcat(tmp, c_file.name), strcat(dir, ".out"));
    } while (_findnext(hFile, &c_file) == 0);
    _findclose(hFile);


    hFile = _findfirst("./tests/*", &c_file);
    _findnext(hFile, &c_file);
    do {
        sscanf(c_file.name, "%s", f_name);
        char tmp[FILENAME_MAX] = "./tests/";
        char dir[FILENAME_MAX] = "./in/";
        strcat(dir, f_name);
        rename(strcat(tmp, c_file.name), strcat(dir, ".in"));
    } while (_findnext(hFile, &c_file) == 0);
    _findclose(hFile);

    return 0;
}
