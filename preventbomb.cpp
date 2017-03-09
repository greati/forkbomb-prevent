#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <unistd.h>

using namespace std;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}

int main(int argn, char * args[]) {

    int maxproc = atoi(args[1]);
    std::string progname = args[0];
    std::string commandCur = "ps -u | grep " + progname + "* | wc -l";

    int current = stoi(exec(commandCur.c_str()));

    if (current >= maxproc) {

        cout << "Too many forks for this program!" << endl;
        return 0;
    }


    while (true) fork();

    /*
    std::string maxprocval = "";
    std::string currentprocnumber = "";
    bool showedonce = false;

    while (true) {
 
        maxprocval = exec("echo $MAXPROCVAL");

        if (maxprocval != "") {
            cout << "Maximum processes configured: " << maxprocval << endl;

            currentprocnumber = exec("ps -u | wc -l");

            if (!showedonce && stoi(currentprocnumber) > stoi(maxprocval)) {
                cout << "Process overflow! " << currentprocnumber << "/" << maxprocval << endl;
                showedonce = true;
            } else {
                showedonce = false;
            }

        } else {
            cout << "No maximum value configured." << endl;
        }
    
    }*/

    return 0;
}
