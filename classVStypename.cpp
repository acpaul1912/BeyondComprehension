class vs typename::
   
   template<class T> class Widget; // uses “class”
   template<typename T> class Widget; // uses “typename”

   in c++ : There no difference in the above statement  , but there is a difference in advance template programming 
   (it varies from compiler to compiler ).

   Rules to apply the typename : 

   1.if the parser encounters a nested dependent name in a template, it assumes that the name is not a type unless you tell it otherwise.
     We do that by putting typename immediately in front of it

   Best Practice: The general rule is simple: anytime you refer to a nested dependent type name in a template,
   you must immediately precede it by the word  typename.
   
   Example: 

   template<typename C>
   void print2nd(const C& container)
   {
	   if (container.size() >= 2) {
	   C::const_iterator iter(container.begin()); // this name is assumed to not be a type

   }

   Apply rule One:



   template<typename C>
   void print2nd(const C& container)
   {
	   if (container.size() >= 2) {
	       typename C::const_iterator iter(container.begin()); // // this is valid C++

   }

  There is one exception to the above rule , is that typename must not precede nested dependent type names in a list of base classes 
	  or as a base class identifier in a member initialization list
  
  template<typename T>
  class Derived: public Base<T>::Nested { // base class list: typename not
  public: // allowed
  explicit Derived(int x): Base<T>::Nested(x) // base class identifier in mem.init. list: typename not allowed
  {
       typename Base<T>::Nested temp; // use of nested dependent type name 
   } 
 };
 

  Things to Remember
	✦ When declaring template parameters, class and typename are interchangeable.
	✦ Use typename to identify nested dependent type names, except in base class lists 
		or as a base class identifier in a member initialization list.
