class student
{
    private:
        int id;
        int location;
    public:
        student(){}
        void setid(int sid){id = sid;}
        void setlocation(int loc){location = loc;}
        int getid(){return id;}
        int getlocation(){return location;}
};
class seats
{
    private:
        int seatnum;
        bool occupied;
        int roomnum;
    public:
        seats(){}
        void setseat(int seat){seatnum = seat;}
        void setocc(bool seat){occupied = seat;}
        void setroom(int x){roomnum = x;}
        int getroom(){return roomnum;}
        int getseat(){return seatnum;}
        bool getocc(){return occupied;}
};

/*class classroom
{
    private:
        int classnum;
    public:
        classroom(){}
        void setclassnum(int num){classnum = num;}
        int getclass(){return classnum;}
};*/

class general
{
    private:
        student students[256];
        seats seat[256];
        //classroom classes[8];
    public:
        general()
        {
            for(int i = 0; i < 256; i++)
            {
                students[i].setid(i);
                students[i].setlocation(0);
                seat[i].setseat(i);
                seat[i].setroom(0);
                seat[i].setocc(0);
            }
        }
        void reserve(int room, int id)
        {
            seat[id].setocc(1);
            students[id].setlocation(room);
            seat[id].setroom(room);
        }
        void avail(int room, int id)
        {
            seat[id].setocc(0);
            students[id].setlocation(0);
        }
        int check_available(int room)
        {
            int count = 0;
            for(int i = 0; i < 256; i++)
            {
                if(seat[i].getroom() != room) count++;
            }
            return count;
        }
        int location_inquiry(int id)
        {
            return students[id].getlocation();
        }
        bool check_occupied(int id, int room)
        {
            if (seat[id].getroom() == room) return 1;
            else return 0;
        }
};