#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream webfile;
    string filename = "/home/luhast/public_html/index.html";
    webfile.open(filename.c_str());
    
    
webfile << "<!DOCTYPE html>" << endl
        << "<head>" << endl
        <<  " <meta charset=\"UTF-8\">" << endl
        <<  " <title>The website 2!</title>" << endl
        << "</head>" << endl
        << "<body>" << endl
        << "  <h1>Lucas's Website 2!</h1>" << endl
	
        << "  <p>UNA: <a href=\"https://www.una.edu\"> Click Here </a>.</p>" << endl	

	<< "</body>" << endl
	<< "</html>" << endl;

webfile.close();
return 0;
}
