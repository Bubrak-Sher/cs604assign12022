#include <iostream>
#include <fstream>
#include <stdio.h>   
#include <string>


using namespace std;

int main () {
	string uName, uPass;
	//system("clear && figlet Scorpio - B . S");
	cout << "\t\t***Welcome***\n";
	cout << "User Name: ";
	cin >> uName;
	if(uName == "scar")
	{
		cout << "\nSuccess";
		cout << "\n\nUser Password: ";
		cin >> uPass;
		if(uPass == "scorpio")
		{
			cout << "\nSuccess";
		}
		else{exit(0);}
	}
	

	if (uName == "scar" && uPass == "scorpio")
	{
		string choice;
		int run;
		string vuid, pid, campid, status, fileName, campName;
		while(run)
		{
			//system("clear && figlet Scorpio - B . S");
			cout << "\n\t\t[CS604 Assignment 1 Fall 2022 by Scorpio]\n";
			cout << "\n1. Make New Assignment";
			// cout << "\n2. Take First SS";
			// cout << "\n3. Take Second SS";
			cout << "\n0. Exit";

			cout << "\n\nEnter Your Choice: ";
			cin >> choice;
			cin.ignore();

			if(choice == "1")
			{
				// char campName[100] = {0};
				//system("clear && figlet Scorpio - B . S");
				cout << "\n\tEnter Your Detail: \n";
				cout << "\nEnter Your VUID: ";
				cin >> vuid;
				fileName = vuid + ".c";
				
				
				cout << "Enter Campus ID:(ex: VLHR02): ";
				cin >> campid;

				cout << "Enter Campus Name:(ex: VU Ferozpor Road Campus): ";
				cin.ignore();
				getline(cin, campName);
				cin.clear();

				cout << "Enter Name of Variable(ex: proid): ";
				cin >> pid;
				cout << "Enter Name of Variable(ex: stat): ";
				cin >> status;
				
				ofstream myfile(fileName, ios::trunc);

				string a = "# include <sys/wait.h>\n# include <stdlib.h>\n# include <unistd.h>\n# include <stdio.h>\n\nint main(){\n";
				string b = "\tint " + pid+"," +status+";";
				string c = "\n\t" + pid + " = fork();\n\tif("+pid +" == -1){\n\t\tprintf(\"Fork Failed!\");\n\t\texit(1);\n\t}";
				string d = "\n\tif("+ pid +" == 0){\n\t\tprintf(\"\\nIn Child Process\\n\");";
				string e = "\n\t\tprintf(\"VU ID \");";
				string f = "\n\t\tprintf(\""+vuid+"\");\n\t\tprintf(\"\\n\\nCampus Id "+campid+"\\n\");";
				string g = "\n\t}else{\n\t\twait(&" + status +");\n\t\tprintf(\"\\nIn Parent Process\\n\");";
				string h = "\n\t\tprintf(\""+ campName +"\\n\");\n\t}\n\treturn 0;\n}";
				myfile << a << b << c << d << e;
				myfile << f << g << h;
				myfile.close();
				cout << "\nScorpio : Success!\n";
			}
			// else if(choice == "2")
			// {

			// 	system("ls");
			// 	getchar();
			// }
			// else if(choice == "3")
			// {
			// 	string cid = vuid + ".c";
			// 	system("gnome-terminal gcc bc200414288.c -o bc200414288.out && ./bc200414288.out");

			// }
			else if (choice == "0")
			{
				run = 0;
			}
		}
	}
	else
	{
		exit(0);
	}
	
  return 0;
}