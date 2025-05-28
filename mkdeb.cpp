#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


int main()
{   
    

  
    std::string projectname = "";
    std::string arch = "";
    std::string description = "";
    std::string executionHandle = "";
    unsigned int IsTerminalonly = 0;
    unsigned int IsNotifiengatStartup = 0;
    std::string boolOptions[] = {"false", "false"};

    std::cout << "\nWhat is the name of the project? ";
    std::cin >> projectname;
    std::cin.ignore();

    std::cout << "\nWhat architecture is the project utilizing? ";
    std::cin >> arch;
    std::cin.ignore();

    std::cout << "\nHow would you describe the project? ";
    std::getline(std::cin, description);
    std::cin.ignore();

    std::cout << "\nWhat do you type in to execute the programm? ";
    std::cin >> executionHandle;
    std::cin.ignore();

    std::cout << "\nIs it supposed to run in the terminal (1/0)? ";
    std::cin >> IsTerminalonly;
    std::cin.ignore();
    if(IsTerminalonly == 1) {
        boolOptions[0] = "true";
    }
   

    std::cout << "\nNotify at startup (1/0)? ";
    std::cin >> IsNotifiengatStartup;
    std::cin.ignore();
    if(IsNotifiengatStartup == 1) {
        boolOptions[1] = "true";
    }

    std::filesystem::create_directories("debianrel");
    std::filesystem::create_directory("debianrel/DEBIAN");
    std::filesystem::create_directories("debianrel/usr");
    std::filesystem::create_directory("debianrel/usr/bin");
    std::filesystem::create_directory("debianrel/usr/share");
    std::filesystem::create_directory("debianrel/usr/share/applications");



    std::ofstream ControlFile("debianrel/DEBIAN/control");
    ControlFile << "Package: " << projectname << "\nVersion: 0.0.1" << "\nArchitecture: " << arch << "\nMaintainer: " << "$USER" << "\nDescription: " << description;
    ControlFile.close();

    std::ofstream DesktopFile("debianrel/usr/share/applications/" + projectname + ".desktop");
    DesktopFile << "[Desktop Entry]\nEncoding=UTF-8\nName=" << projectname <<"\nComment=" << description << "\nExec=" << executionHandle << "\nIcon=system\nTerminal=" << boolOptions[0] <<"\nStartupNotify=" << boolOptions[1] <<"\nType=Application\nCategories=Utility";
    DesktopFile.close();

}
