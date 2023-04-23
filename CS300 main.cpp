#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Course{
    string courseNumber;
    string name;
    vector<string>prereq;
};

// function splitting sptring to list using delimiter
vector<string>tokenize(string s, string del = " "){
    vector <string> stringArray;
    int start = 0;
    int end = s.find(del);
    while (end != -1){
        stringArray.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    stringArray.push_back(s.substr(start, end - start));
    return stringArray;
}

//load and read the file

vector<Course>LoadDataStructure(){
    ifstream fin("abcu.txt",ios::in);
    vector<Course> courses;
    string line;
    while(1){
        getline(fin,line);
        if (line=="-1")
            break;
        Course course;
        vector<string> tokenizedInfo=tokenize(line,",");
        course.courseNumber=tokenizedInfo[0];
        course.name=tokenizedInfo[1];
        for(int i=2;i<tokenizedInfo.size();i++){
            course.prereq.push_back(tokenizedInfo[i]);
        }
        courses.push_back(course);
    }
    fin.close();
    return courses;
}

//print course info for given course

void printCourse(Course course){
    string courseNumber = course.courseNumber;
    string name= course.name;
    vector<string> prereq = course.prereq;
    cout <<"Course Number: "<< courseNumber<<endl;
    cout <<"Course Name: "<<name<<endl;
    cout <<"Prerequisites: ";
    for (int i=0;i<prereq.size();i++){
        cout << prereq[i]<<" ";
    }
    cout<<"\n\n";
}

//print course info for all courses 
void printCourseList(vector<Course> courses){
    int n = courses.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(courses[j].courseNumber > courses[j+1].courseNumber){
                swap(courses[j+1],courses[j]);
            }
        }
    }
    for (int i=0;i<n;i++){
        printCourse(courses[i]);
    }
}

//search through courses for given number
void searchCourse(vector<Course> courses){
    int n=courses.size();
    string courseNumber;
    int f=0;
    cout<<"Enter courseNumber: ";
    cin>> courseNumber;
    for (int i=0;i<n;i++){
        if(courses[i].courseNumber==courseNumber){
            f=1;
            printCourse(courses[i]);
            break;
        }
    } 
    if(f==0){
        cout<<"Course with that number not found" <<endl;
    }
}

int main(int argc, char **argv){
    vector<Course> courses;
    //menu
    cout<<"1.Load Data Structure"<<endl;
    cout<<"2.Print Course List"<<endl;
    cout<<"3.Print Course"<<endl;
    cout<<"4.Exit"<<endl;

    int choice;
    do{
        cout <<"\nEnter your choice";
        cin >> choice;
        switch(choice){
            case 1: courses=LoadDataStructure(); break;
            case 2: printCourseList(courses); break;
            case 3: searchCourse(courses); break;
            case 4: cout<< "Exit\n"; break;
            default: cout <<"Invalid choice\n";
        }
    }while(choice!=4);
    return 0;
}
