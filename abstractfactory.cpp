#include <iostream>
#include <string>

using namespace std;


class AbstractMsgA{
    public:
        AbstractMsgA(){cout << "\n I am AbstractMsgA \n";}
        virtual ~AbstractMsgA(){"\n I am AbstractMsgA Out \n";}
        virtual void encoder()=0;
        virtual void decoder()=0;
};

class AbstractMsgB{
    public:
        AbstractMsgB(){cout << "\n I am AbstractMsgB \n";}
        virtual ~AbstractMsgB(){"\n I am AbstractMsgB Out \n";}
        virtual void encoder()=0;
        virtual void decoder()=0;
};

class MessageA1: public AbstractMsgA{
    public:
        MessageA1(){"  I am Message A1 product --- \n";}
        virtual ~MessageA1(){"  I am Message A1 product out--- \n";}
         void encoder(){
            cout << "I am Encode of MessageA1 \n";

         }
         void decoder(){
            cout << "I am Decoder of MessageA1 \n";
         }
};

class MessageA2: public AbstractMsgA{

    public:
        MessageA2(){"  I am Message A2 product --- \n";}
        virtual ~MessageA2(){"  I am Message A2 product out--- \n";}
         void encoder(){
            cout << "I am Encode of MessageA2 \n";

         }
         void decoder(){
            cout << "I am Decoder of MessageA2 \n";
         }

};


class MessageB1: public AbstractMsgB{
    public:
        MessageB1(){"  I am Message B1 product --- \n";}
        virtual ~MessageB1(){"  I am Message B1 product out--- \n";}
         void encoder(){
            cout << "I am Encode of MessageB1 \n";

         }
         void decoder(){
            cout << "I am Decoder of MessageB1 \n";
         }
};

class MessageB2: public AbstractMsgB{

    public:
        MessageB2(){"  I am Message B2 product --- \n";}
        virtual ~MessageB2(){"  I am Message B2 product out--- \n";}
         void encoder(){
            cout << "I am Encode of MessageB2 \n";

         }
         void decoder(){
            cout << "I am Decoder of MessageB2 \n";
         }

};

class Wrapper_Msg{
    public:
        Wrapper_Msg(){"\n I am Absratct message --\n";}
        virtual ~Wrapper_Msg(){"\n I am Absratct message Out---\n";}
        virtual AbstractMsgA* createWrapperA()=0;
        virtual AbstractMsgB* createWrapperB()=0;
};

class concreatewrapper1:public Wrapper_Msg{
  public:
    concreatewrapper1(){cout << "i am concreatewrapper1\n";}
    virtual ~concreatewrapper1(){cout << "i am concreatewrapper1 out\n";}
    AbstractMsgA* createWrapperA(){
        return new MessageA1;
    }
    AbstractMsgB* createWrapperB(){
         return new MessageB1;
    }

};

class concreatewrapper2:public Wrapper_Msg{
  public:
    concreatewrapper2(){cout << "i am concreatewrapper2\n";}
    virtual ~concreatewrapper2(){cout << "i am concreatewrapper2 out\n";}
    AbstractMsgA* createWrapperA(){
        return new MessageA2;
    }
    AbstractMsgB* createWrapperB(){
         return new MessageB2;
    }

};


int main(){

    Wrapper_Msg *wrapper1_obj = new concreatewrapper1;
    AbstractMsgA *AMsg_obj= wrapper1_obj->createWrapperA();
    AMsg_obj->encoder();
    AMsg_obj->decoder();
    AbstractMsgB *BMsg_obj= wrapper1_obj->createWrapperB();
    BMsg_obj->encoder();
    BMsg_obj->decoder();

    delete AMsg_obj;
    delete wrapper1_obj;

    Wrapper_Msg *wrapper2_obj = new concreatewrapper2;
    AbstractMsgA *aMsg_obj= wrapper2_obj->createWrapperA();
    aMsg_obj->encoder();
    aMsg_obj->decoder();
    AbstractMsgB *bMsg_obj= wrapper2_obj->createWrapperB();
    bMsg_obj->encoder();
    bMsg_obj->decoder();
    
    delete bMsg_obj;
    delete wrapper2_obj;

    return 0;
}