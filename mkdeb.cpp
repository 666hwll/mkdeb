#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

struct package {
    std::string projectname = "";
    std::string cpu_architecture = "";
    std::string maintainer = "";
    std::string description = "";
    std::string executionHandle = "";
    std::string path_to_icon = "";
    unsigned int IsTerminalonly = 0;
    unsigned int IsNotifiengatStartup = 0;
    std::string boolOptions[2] = {"false", "false"};
    std::string version_number = "0.0.1";
    std::string categories_for_desktop[13] = {"AudioVideo", "Audio", "Video", "Development", "Education", "Game", "Graphics", "Network", "Office", "Science", "Settings", "System", "Utility"};
    int user_index_for_categories_for_desktop = -1;
};

int main()
{   
    package p1;

    std::cout << "\nWhat is the name of the project? ";
    std::cin >> p1.projectname;
    std::cin.ignore();

    std::cout << "\nWhat cpu-architecture is the project utilizing? ";
    std::cin >> p1.cpu_architecture;
    std::cin.ignore();

    std::cout << "\n Who is maintaining this project? ";
    std::cin >> p1.maintainer;
    std::cin.ignore();

    std::cout << "\nHow would you describe the project? ";
    std::getline(std::cin, p1.description);
    std::cin.ignore();

    std::cout << "\nWhat is the version number, you want to utilize? ";
    std::getline(std::cin, p1.version_number);
    std::cin.ignore();

    std::cout << "\nWhat do you type in to execute the programm? ";
    std::cin >> p1.executionHandle;
    std::cin.ignore();

    std::cout << "\nType in the path to the icon? If you don't need an icon, type in \'0\' ";
    std::cin >> p1.path_to_icon;
    if(p1.path_to_icon == "0") {
        p1.path_to_icon = "system";
    }
    std::cin.ignore();

    std::cout << "\nIs it supposed to run in the terminal (1/0)? ";
    std::cin >> p1.IsTerminalonly;
    std::cin.ignore();
    if(p1.IsTerminalonly == 1) {
        p1.boolOptions[0] = "true";
    }

    std::cout << "\nNotify at startup (1/0)? ";
    std::cin >> p1.IsNotifiengatStartup;
    std::cin.ignore();
    if(p1.IsNotifiengatStartup == 1) {
        p1.boolOptions[1] = "true";
    }

    std::cout << "In which of these categories is your programm? Type in the number of the element for your choice\n";
    for(int i = 0; i < 13; i++) {

        std::cout << i << " . = " << p1.categories_for_desktop[i] << "\n";
    }
    std::cout << ">>\t";
    do    
    {
        std::cin >> p1.user_index_for_categories_for_desktop;
    } while(p1.user_index_for_categories_for_desktop < -1 || p1.user_index_for_categories_for_desktop > 13);

    std::cout << "Done. Now the directories are being created ...\n";

    std::filesystem::create_directories("debianrel");
    std::filesystem::create_directory("debianrel/DEBIAN");
    std::filesystem::create_directories("debianrel/usr");
    std::filesystem::create_directory("debianrel/usr/bin");
    std::filesystem::create_directory("debianrel/usr/share");
    std::filesystem::create_directory("debianrel/usr/share/applications");

    std::cout << "Finished.\n";

    std::ofstream ControlFile("debianrel/DEBIAN/control");
    ControlFile << "Package: " << p1.projectname << "\nVersion: " << p1.version_number << "\nArchitecture: " << p1.cpu_architecture << "\nMaintainer: " << p1.maintainer << "\nDescription: " << p1.description;
    ControlFile.close();

    std::ofstream DesktopFile("debianrel/usr/share/applications/" + p1.projectname + ".desktop");
    DesktopFile << "[Desktop Entry]\nEncoding=UTF-8\nName=" << p1.projectname <<"\nComment=" << p1.description << "\nExec=" << p1.executionHandle << "\nIcon=" << p1.path_to_icon <<"\nTerminal=" << p1.boolOptions[0] <<"\nStartupNotify=" << p1.boolOptions[1] <<"\nType=Application\nCategories=" << p1.categories_for_desktop[p1.user_index_for_categories_for_desktop];
    DesktopFile.close();

}
