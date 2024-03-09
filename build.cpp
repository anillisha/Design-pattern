#include <iostream>

using namespace std;

class product{
    private:
      string _name;
      int _number;
    public:
     void _setName(string _sName)
     {
        _name=_sName;
     }

     

     void _setVal(int _i32tVal)
     {
        _number=_i32tVal;
     }

     void _GetDetails(void)
     {
        cout<< " My product Details:"<< _name << " Price:" << _number << endl;
     }
};


class builder {
  public:
   builder() {cout <<  " I am builder\n";} 
   virtual ~builder() {}
   product _getProduct(){return product_obj;}
   
   virtual void buildPartA(int orderValue) = 0;
   virtual void buildPartB(int orderValue) = 0;
   virtual void buildPartC(int orderValue) = 0;

  protected:
   product product_obj;
}; 

class concreateBuilder1:public builder{
    public:
    void buildPartA(int orderValue){
        product_obj._setName("  Dal Makhani \n");
        product_obj._setVal(orderValue);
    }

    void buildPartB(int orderValue){
        product_obj._setName("SamosaChat \n");
        product_obj._setVal(orderValue);
    }    

    void buildPartC(int val){
        product_obj._setName("---Not Value Added--- \n");
        product_obj._setVal(0);
    }
};

class concreateBuilder2:public builder{
    public:
      void buildPartA(int orderValue){
            product_obj._setName("  Jal Jeera\n");
            product_obj._setVal(orderValue);
      }

       void buildPartB(int orderValue){
            product_obj._setName("  Lassi \n");
            product_obj._setVal(orderValue);
      }

      void buildPartC(int orderValue){
            product_obj._setName("  Lemon soda \n");
            product_obj._setVal(orderValue);
      }
};


class Director {
    public:
        Director() { std::cout << "Director" << std::endl; }
        ~Director() {
            if (builder_obj) {
                delete builder_obj;
                    }
        }  

        void setBuilder(builder *b_obj){
            if (builder_obj) {
                delete builder_obj;
            }
            builder_obj = b_obj;
        }
        
        product getProduct(){
            return builder_obj->_getProduct();
        }

        void construct(){
            builder_obj->buildPartA(10);
            builder_obj->buildPartB(11);
            //builder_obj->buildPartC(15);
        }

 private:
   builder *builder_obj= nullptr;
};

int main(){
    Director Dobj;
    Dobj.setBuilder(new concreateBuilder1);
    Dobj.construct();

    product EatingPro = Dobj.getProduct() ;
    EatingPro._GetDetails();

    Dobj.setBuilder(new concreateBuilder2);
    Dobj.construct();
    
    product DrinkingPro = Dobj.getProduct() ;
    DrinkingPro._GetDetails();

    return 0;
}