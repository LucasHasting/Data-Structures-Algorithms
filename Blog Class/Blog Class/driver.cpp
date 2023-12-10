/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignment: 3
 * Date: 1/29/2023
 * Program Description: Create a blog class, add blogs to it and display them, and create a website with them
 * File: Blog.cpp
*/

//Includes the Blog class
#include "Blog.cpp"

//function prototypes
void menu(Blog *&blog, int &numBlogs); //displays a menu for the user
void addBlog(Blog *&blog, int &numBlogs, istream &is = cin, bool displayOut = true); //adds a blog to the blog array
void displayBlogs(Blog *blog, int numBlogs); //displays the blogs in the dynamic array
void blogCopy(Blog *blog1, Blog *&blog2, int numBlogs); //copy the left blog to the right blog
void valiDate(istream &is, int &Count, string DMY, int restrict); //Input validation for the date
void outputSeperator(string seperator, int num); //seperates output
void sort(Blog *&blog, int numBlogs); //sorts the array using selection sort
void save(Blog *blog, int numBlogs); //saves the array to data.txt
void load(Blog *&blog, int &numBlogs); //loads the array from data.txt
void indexMaker(Blog *&blog, int numBlogs); //makes the index.html file
void websiteMaker(Blog *blog, int numBlogs); //makes each individual website

//constant variables
const int SEPERATOR_SIZE = 80;
const int MIN_CHOICE = 0;
const int MAX_CHOICE = 4;

//main driver
int main()
{
    //create a null blog pointer to be used as the dynamic array
    Blog *blog = nullptr;

    //number of current blogs
    int numBlogs = 0;

    //loads the data into the array
    load(blog, numBlogs);

    //displays the menu
    menu(blog, numBlogs);
    
    //saves array to a data file
    save(blog, numBlogs);

    //creates index.html file
    indexMaker(blog, numBlogs);

    //makes each blog their own website
    websiteMaker(blog, numBlogs);
    
    //deletes the dynamic array
    delete [] blog;

    //end
    return 0;
}

/*
 * Function Name: menu
 * Function Description: Displays a menu for the user
 * Incoming: blog, numBlogs
 * Outgoing: blog, numBlogs
 * Return: None
*/
void menu(Blog *&blog, int &numBlogs)
{
    int option = 0;
    do {
	//seperate output
	outputSeperator("-", SEPERATOR_SIZE);

	//format output
        cout << setw(15)
	     << "Add Blog: " << "1" << endl

	     << setw(15)
	     << "Display Blogs: " << "2" << endl

	     << setw(15)
	     << "Save: " << "3" << endl

	     << setw(15)
	     << "Load: " << "4" << endl

	     << setw(15)
	     << "Quit: " << "0"
	     << endl << endl

	     << "Enter: ";

	//input option
	cin >> option;

	//seperate output
	outputSeperator("-", SEPERATOR_SIZE);

    } while (option < MIN_CHOICE || option > MAX_CHOICE);

    //Calls functions based on the option chosen by the user in the menu
    switch(option) {
        case 1:
	    addBlog(blog, numBlogs);
	    menu(blog, numBlogs);
	    break;
	case 2:
	    displayBlogs(blog, numBlogs);
	    menu(blog, numBlogs);
	    break;
	case 3:
	    //saves array to a data file
    	    save(blog, numBlogs);

	    //creates index.html file
    	    indexMaker(blog, numBlogs);

    	    //makes each blog their own website
    	    websiteMaker(blog, numBlogs);

    	    cout << "Save Complete" << endl;
	    menu(blog, numBlogs);
	    break;
	case 4:
	    load(blog, numBlogs);
	    cout << "Load Complete" << endl;
	    menu(blog, numBlogs);
	    break;
	default:
	    break;
    }

    //end
    return;
}

/*
 * Function Name: addBlog
 * Function Description: Adds a blog to a blog array
 * Incoming: blog, numBlogs
 * Outgoing: blog, numBlogs
 * Return: None
 * Reference for .rdbuf(): https://stackoverflow.com/questions/30184998/how-to-disable-cout-output-in-the-runtime
*/
void addBlog(Blog *&blog, int &numBlogs, istream &is, bool displayOut)
{
    //save the stream buffer pointer
    streambuf *buff = cout.rdbuf();

    //if the displayOut variable is False,
    //it will set the read buffer pointer to nullptr to not display any output
    if (!displayOut)
        cout.rdbuf(nullptr);

    //declare temp blog pointer to be a temporary array
    Blog *temp = nullptr;

    //initilize local variables
    string firstName = "", lastName = "", content = "";
    int month = 0, day = 0, year = 0;

    //set the size of temp
    temp = new Blog[numBlogs + 1];

    //if blog is not empty copy blog to temp
    if (blog != nullptr)
        blogCopy(blog, temp, numBlogs);

    //ask the user for inputs
    cout << "First Name: ";
    is >> firstName;

    cout << "Last Name: ";
    is >> lastName;

    //Validate the date input
    valiDate(is, month, "Month", 12);
    valiDate(is, day, "Day", 31);
    valiDate(is, year, "Year", 2023);

    //prevents the getline from being skipped
    is.ignore();

    //get content
    cout << "Content: ";
    getline(is, content);

    //set the new temp
    temp[numBlogs].setBlog(firstName, lastName, content, month, day, year);

    //delete blog
    if (blog != nullptr)
        delete [] blog;

    //set blog to the temp blog
    blog = temp;

    //add a blog to numBlogs
    numBlogs++;

    //if the displayOut variable is False,
    //it will set the read buffer pointer to the stream buffer that was saved,
    //so the output will be displayed after the function is called
    if (!displayOut)
        cout.rdbuf(buff);

    //end
    return;
}

/*
 * Function Name: displayBlogs
 * Function Description: Displays the blogs in the dynamic array
 * Incoming: blog, numBlogs
 * Outgoing: None
 * Return: None
*/
void displayBlogs(Blog *blog, int numBlogs)
{
    //display the top row
    cout << left << setw(12) << "Date" << setw(24) << "Author" << setw(5) << "Content" << endl;

    for (int i = 0; i < numBlogs; i++)
    {
	//display the date
        cout << setfill('0') << setw(2) << right << blog[i].getMonth() << "-" << setw(2)
		<< blog[i].getDay() << "-" << setw(4) << blog[i].getYear() << setfill(' ');

	//display the author's first and last name
	cout << "  ";
       	cout << left << setw(10) << blog[i].getAuthorFirst() ;
        cout << "  ";
	cout <<	setw(10) << blog[i].getAuthorLast();

	//display the content
	cout << "  ";
	cout << setw(5) << left << blog[i].getContent() << endl;
    }

    //end
    return;
}

/*
 * Function Name: blogCopy
 * Function Description: Copy the left blog to the right blog
 * Incoming: blog1, blog2, numBlogs
 * Outgoing: blog2
 * Return: None
*/
void blogCopy(Blog *blog1, Blog *&blog2, int numBlogs)
{
    for (int i = 0; i < numBlogs; i++)
        blog2[i] = blog1[i];

    //end
    return;
}

/*
 * Function Name: valiDate
 * Function Description: Input validation for the date
 * Incoming: Count, DMY, restrict
 * Outgoing: Count
 * Return: None
*/
void valiDate(istream &is, int &Count, string DMY, int restrict)
{
    do{
        cout << DMY << ": ";
	is >> Count;
    } while (Count < 0 || Count > restrict);

    //end
    return;
}

/*
 * Function Name: outputSeperator
 * Function Description: Seperates output
 * Incoming: seperator, num
 * Outgoing: None
 * Return: None
*/
void outputSeperator(string seperator, int num)
{
    for (int i = 0; i < num; i++)
	cout << seperator;
    cout << endl;

    //end
    return;
}

/*
 * Function Name: sort
 * Function Description: Sorts the array using selection sort
 * Incoming: blog, numblogs
 * Outgoing: blog
 * Return: None
 * Reference: Class Code (sorting code sheet)
*/
void sort(Blog *&blog, int numBlogs)
{
    Blog temp;
    int minIndex = 0;

    for (int i = 0; i < numBlogs - 1; i++)
    {
	//change the minIndex if there is a blog object < another
        minIndex = i;
	for (int j = i + 1; j < numBlogs; j++)
	    if (blog[j] < blog[minIndex])
	       minIndex = j;

	//swap positions i and minIndex
	temp = blog[i];
	blog[i] = blog[minIndex];
	blog[minIndex] = temp;
    }

    //end
    return;
}

/*
 * Function Name: save
 * Function Description: Saves the array to data.txt
 * Incoming: blog, numBlogs
 * Outgoing: None
 * Return: None
*/
void save(Blog *blog, int numBlogs)
{
  //create ofstream file
  ofstream outFile;
  string File = "/home/luhast/public_html/data.txt";
  outFile.open(File.c_str());

  //write the array to the ofstream file
  for (int i = 0; i < numBlogs; i++)
     outFile << blog[i].getAuthorFirst() << " "
	     << blog[i].getAuthorLast() << " "
	     << blog[i].getMonth() << " "
	     << blog[i].getDay() << " "
	     << blog[i].getYear() << endl
	     << blog[i].getContent() << endl;

  //close the file
  outFile.close();

  //end
  return;
}

/*
 * Function Name: load
 * Function Description: Loads the array from data.txt
 * Incoming: blog, numBlogs
 * Outgoing: blog, numBlogs
 * Return: None
 * Reference for .peek(): https://java2blog.com/cpp-count-lines-in-file/
*/
void load(Blog *&blog, int &numBlogs)
{
    //open ifstream file
    ifstream inFile;
    string File = "/home/luhast/public_html/data.txt";
    inFile.open(File.c_str());

    //add every blog in the ifstream file to the array
    while(inFile.peek()!=EOF)
	addBlog(blog, numBlogs, inFile, false);

    //close the file
    inFile.close();

    //end
    return;
}

/*
 * Function Name: indexMaker
 * Function Description: Makes the index.html file
 * Incoming: blog, numBlogs
 * Outgoing: blog
 * Return: None
*/
void indexMaker(Blog *&blog, int numBlogs)
{
  //sort the array before creating the index file
  sort(blog, numBlogs);

  //create the ofstream (index.html) file
  ofstream outFile;
  string File = "/home/luhast/public_html/index.html";
  outFile.open(File.c_str());

  //write to the html file
  outFile << "<!DOCTYPE html>" << endl
          << "<html>" << endl
          << "  <head>" << endl
          << "    <title>Super Blog</title>" << endl
          << "  </head>" << endl
          << "  <body>" << endl
          << "    <center>" << endl
          << "      <h1>The CS 355 Super Blog</h1>" << endl;

  	//add each author and date writeen as it's own paragraph line
        for (int i = 0; i < numBlogs; i++)
        {
            string AuthorCombined = blog[i].getAuthorFirst() + blog[i].getAuthorLast();
            string Author = blog[i].getAuthorFirst() + " " + blog[i].getAuthorLast();
            outFile << "      <p>Blog Written by <a href=\"http://cs.csis.work/~luhast/website/" << AuthorCombined << ".html\"" << ">"
            << Author << ".</a> Date: " << blog[i].getMonth() << "/" << blog[i].getDay() << "/" << blog[i].getYear() << "</p>" << endl;
        }

  //finish writing to the outfile
  outFile << "    </center>" << endl
          << "  </body>" << endl
          << "</html>" << endl;

  //close the file
  outFile.close();

  //end
  return;
}

/*
 * Function Name: websiteMaker
 * Function Description: Makes each individual website
 * Incoming: blog, numBlogs
 * Outgoing: None
 * Return: None
*/
void websiteMaker(Blog *blog, int numBlogs)
{
  for (int i = 0; i < numBlogs; i++)
  {
    //get author's name for the filename and the blog title
    string AuthorCombined = blog[i].getAuthorFirst() + blog[i].getAuthorLast();
    string Author = blog[i].getAuthorFirst() + " " + blog[i].getAuthorLast();

    //create the ofstream (website/author.html) file
    ofstream outFile;
    string File = "/home/luhast/public_html/website/" + AuthorCombined + ".html";
    outFile.open(File.c_str());

    //write the html file
    outFile << "<!DOCTYPE html>" << endl
            << "<html>" << endl
            << "  <head>" << endl
            << "    <title>" + Author + "'s Blog</title>" << endl
            << "  </head>" << endl
            << "  <body>" << endl
            << "    <center>" << endl
            << "      <h1>" << Author << "'s Blog</h1>" << endl
            << "      <p>Date: "<< blog[i].getMonth() << "/" << blog[i].getDay() << "/" << blog[i].getYear() << "</p>" << endl
            << "      <p>" << blog[i].getContent() << "</p>" << endl
            << "    </center>" << endl
            << "  </body>" << endl
            << "</html>" << endl;

    //close the file
    outFile.close();
  }

  //end
  return;
}
