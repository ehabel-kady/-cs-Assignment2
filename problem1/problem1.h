/*
this file contain the source code of the problem
it contains three classes, the first class contains the required details needed for the students, their id and their location.
the second class contains the seats number and the classroom where the seat is occupied.
the last class wrap-up the first two classes and contains the required methods for processing the data needed and carry up the needed processes.
*/
#include <stdint.h>
class student
{
    private:
        //initializing two variables for the id and curret location of the student.
        uint8_t id;
        uint8_t location;
    public:
        //constructor
        student(){}
        //setters and getters for the class data members
        void setid(int sid){id = sid;}
        void setlocation(int loc){location = loc;}
        uint8_t getid(){return id;}
        uint8_t getlocation(){return location;}
};
class seats
{
    private:
        //initializing variables that hold the seat number, the room where the seat is occupied
        //and a bool variable to check whether the seat is occupied or not
        uint8_t seatnum;
        bool occupied;
        uint8_t roomnum;
    public:
        //constructor
        seats(){}
        //setters and getters for the class data memebers
        void setseat(int seat){seatnum = seat;}
        void setocc(bool seat){occupied = seat;}
        void setroom(int x){roomnum = x;}
        uint8_t getroom(){return roomnum;}
        uint8_t getseat(){return seatnum;}
        bool getocc(){return occupied;}
};

//wrap-up class that contains the instances of both classes
class general
{
    private:
        //creating instances of the first two classes
        student students[256];
        seats seat[256];
    public:
        //constructor
        general()
        {
            //looping over the instances of bothe classes and intializing their values with zero
            for(int i = 0; i < 256; i++)
            {
                students[i].setid(i);
                students[i].setlocation(0);
                seat[i].setseat(i);
                seat[i].setroom(0);
                seat[i].setocc(0);
            }
        }
        //method that reserves the seat for the student and specify a particular room that the student will be in
        void reserve(int room, int id)
        {
            seat[id].setocc(1);
            students[id].setlocation(room);
            seat[id].setroom(room);
        }
        //method that removes the students from the classroom he was in
        void avail(int room, int id)
        {
            seat[id].setocc(0);
            students[id].setlocation(0);
        }
        //checking the available seats in a particualar room
        uint8_t check_available(int room)
        {
            uint8_t count = 0;
            for(int i = 0; i < 256; i++)
            {
                if(seat[i].getroom() != room) count++;
            }
            return count;
        }
        //method that returns the current location of the student
        int location_inquiry(int id)
        {
            return students[id].getlocation();
        }
        //method that checks whether a specific seat is occupied in  a specific room or not
        bool check_occupied(int id, int room)
        {
            if (seat[id].getroom() == room) return 1;
            else return 0;
        }
};