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
    std::string path_to_icon = "";
    unsigned int IsTerminalonly = 0;
    unsigned int IsNotifiengatStartup = 0;
    std::string boolOptions[] = {"false", "false"};
    std::string version_number = "0.0.1";
    std::string categories_for_desktop[12] = {"AudioVideo", "Audio", "Video", "Development", "Education", "Game", "Graphics", "Network", "Office", "Science", "Settings", "System", "Utility"};
    int user_index_for_categories_for_desktop = -1;

    std::cout << "\nWhat is the name of the project? ";
    std::cin >> projectname;
    std::cin.ignore();

    std::cout << "\nWhat architecture is the project utilizing? ";
    std::cin >> arch;
    std::cin.ignore();

    std::cout << "\nHow would you describe the project? ";
    std::getline(std::cin, description);
    std::cin.ignore();

    std::cout << "\nWhat is the version number, you want to utilize? ";
    std::getline(std::cin, version_number);
    std::cin.ignore();

    std::cout << "\nWhat do you type in to execute the programm? ";
    std::cin >> executionHandle;
    std::cin.ignore();

    std::cout << "\nType in the path to the icon? If you don't need an icon, type in \'system\' ";
    std::cin >> path_to_icon;
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

    std::cout << "In which of these categories is your programm? Type in the number of the element for your choice\n" << categories_for_desktop << "\n >>";
        do {
            std::cin >> user_index_for_categories_for_desktop;
        } while(-1 < (user_index_for_categories_for_desktop + 1) <= 13);


    std::filesystem::create_directories("debianrel");
    std::filesystem::create_directory("debianrel/DEBIAN");
    std::filesystem::create_directories("debianrel/usr");
    std::filesystem::create_directory("debianrel/usr/bin");
    std::filesystem::create_directory("debianrel/usr/share");
    std::filesystem::create_directory("debianrel/usr/share/applications");



    std::ofstream ControlFile("debianrel/DEBIAN/control");
    ControlFile << "Package: " << projectname << "\nVersion: " << version_number << "\nArchitecture: " << arch << "\nMaintainer: " << "$USER" << "\nDescription: " << description;
    ControlFile.close();

    std::ofstream DesktopFile("debianrel/usr/share/applications/" + projectname + ".desktop");
    DesktopFile << "[Desktop Entry]\nEncoding=UTF-8\nName=" << projectname <<"\nComment=" << description << "\nExec=" << executionHandle << "\nIcon= " << path_to_icon <<"\nTerminal=" << boolOptions[0] <<"\nStartupNotify=" << boolOptions[1] <<"\nType=Application\nCategories= " << categories_for_desktop[user_index_for_categories_for_desktop - 1];
    DesktopFile.close();

}
