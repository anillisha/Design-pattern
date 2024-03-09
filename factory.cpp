#include<iostream>
#include<string>

using namespace std;

class message{
  public:
    message(){
        cout<<"I am Message creater \n";
    }
    virtual void encoder() = 0;
    
    virtual void decoder() = 0;
    
};

class MessageA : public message {
  public: 
    MessageA(){
        cout<<"I am MessageA creater \n";
    }
    ~MessageA(){
        cout<<"I am MessageA creater Out....\n";
    }
    void encoder(){
       cout<<"I am MessageA encoder \n"; 
    }
    void decoder(){
        cout<< "I am messageA decoder\n";
    }
};

class MessageB : public message {
  public: 
    MessageB(){
        cout<<"I am MessageB creater \n";
    }
    ~MessageB(){
        cout<<"I am MessageB creater Out....\n";
    }

    void encoder(){
       cout<<"I am MessageB encoder \n"; 
    }
    void decoder(){
        cout<< "I am messageB decoder\n";
    }
};

class MsgWraper_Create{
    public:
        MsgWraper_Create(){ cout<<"I am MsgWraper_Create  \n";};
        ~MsgWraper_Create(){};
        virtual message* WrapperA()= 0;
        virtual message* WrapperB()= 0;
};


class WrapperrCreator:public MsgWraper_Create{
public:
  WrapperrCreator(){
    cout<<"I am WrapperrCreator  \n";
  }  

  ~WrapperrCreator(){ }
   message* WrapperA(){
        return new MessageA;
   }
   message* WrapperB(){
        return new MessageB;
   }

};

int main(){
    MsgWraper_Create *Msgobj= new WrapperrCreator;
    message *MsgAobj= Msgobj->WrapperA();
    MsgAobj->encoder();
    MsgAobj->decoder();

    message *MsgBobj= Msgobj->WrapperB();
    MsgBobj->encoder();
    MsgBobj->decoder();
    delete MsgBobj;
    delete MsgAobj;
    delete Msgobj;
    return 0;
}