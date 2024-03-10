#include <iostream>
#include <string>

using namespace std;

class MsgHeaderPrototype{
    public:
        MsgHeaderPrototype(){cout << "MsgHeaderPrototype in ---\n";}
        virtual ~MsgHeaderPrototype(){cout << "MsgHeaderPrototype Out ---\n";}
        virtual MsgHeaderPrototype* clone()=0;
        virtual void Header()=0;
};

class message1:public MsgHeaderPrototype{
    public:
    message1(){cout << "I am Message1 in...\n";}
    ~message1(){cout << "I am Message1 out...\n";}
    MsgHeaderPrototype* clone(){ 
        return new message1;
    }

    void Header(){
        cout<< "I am Header1 Added";
    }
};


class message2:public MsgHeaderPrototype{
    public:
    message2(){cout << "I am Message1 in...\n";}
    ~message2(){cout << "I am Message1 out...\n";}
    MsgHeaderPrototype* clone(){ 
        return new message2;
    }

    void Header(){
        cout<< "I am Header2 Added";
    }
};

class client{
 public:
    client(){
        cout << " I am client \n";
    }
    ~client(){
        if(MsgHeaderPrototypeObj){
            delete MsgHeaderPrototypeObj;
        }
    }
     
    void setPrototypeWrapper(MsgHeaderPrototype *msgP){
         if(MsgHeaderPrototypeObj){
            delete MsgHeaderPrototypeObj;
        }
        MsgHeaderPrototypeObj=msgP;
    }

    MsgHeaderPrototype *clone(){
        if(!MsgHeaderPrototypeObj){
            return NULL;
        }
        return MsgHeaderPrototypeObj->clone();
    }

    private:
     MsgHeaderPrototype *MsgHeaderPrototypeObj;

};

int main(){
    client clientObj;
    clientObj.setPrototypeWrapper(new message1 );
    MsgHeaderPrototype *m1= clientObj.clone();
    m1->Header();

    clientObj.setPrototypeWrapper(new message2);
    MsgHeaderPrototype* m2= clientObj.clone();
    m1->Header();
    return 0;
}