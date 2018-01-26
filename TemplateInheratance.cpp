/*

Inheratance does not work in template (Directly )??


prog.cpp: In instantiation of ‘void LogMessage<T>::sendsecureLog(T&) [with T = CompanyZ]’:
prog.cpp:102:21:   required from here
prog.cpp:84:16: error: ‘sendsecure’ was not declared in this scope, and no declarations were found by argument-dependent lookup at the point of instantiation [-fpermissive]
sendsecure(company);
~~~~~~~~~~^~~~~~~~~
prog.cpp:84:16: note: declarations in dependent base ‘MessageSend<CompanyZ>’ are not found by unqualified lookup
prog.cpp:84:16: note: use ‘this->sendsecure’ instead

*/ 


/*
Fix to this problem in two ways :
1. First,you can preface calls to base class functions with “this->”.
2. explicitly specify that the function being called is in the base class. (MsgSender<Company>::sendClear(paramneter)).
 ( another way ,  you can employ a using declaration. (using MsgSender<Company>::sendClear )  , but i am getting error).

Question Come : How these will support the virtual pointer concept .



*/


#include<iostream>

using namespace std;
class CompanyA {

public: 

	void sendSecureMessage() {

		std::cout << "secure message : A " << std::endl;
	}

	void sendUnSecureMessage() {

		std::cout << "Un secure message : A " << std::endl;
	}
};

class CompanyB {

public:

	void sendSecureMessage() {

		std::cout << "secure message : B " << std::endl;
	}
	void sendUnSecureMessage() {

		std::cout << "Un secure message : B " << std::endl;
	}
};

class Companyc {

public:

	void sendSecureMessage() {

		std::cout << "secure message : c " << std::endl;
	}

	void sendUnSecureMessage() {

		std::cout << "Un secure message : C " << std::endl;
	}
};

class CompanyZ {

public:

	void sendSecureMessage() {

		std::cout << "secure message : Z " << std::endl;
	}

	void sendUnSecureMessage() {

		std::cout << "Un secure message : Z " << std::endl;
	}
};
 
template <typename T>
class MessageSend
{
public:
	void sendsecure(T& company) {

		company.sendSecureMessage();
	}

	void sendUnsecure(T &company) {

		company.sendUnSecureMessage();
	}

};

template <>
class MessageSend <CompanyZ>
{
public:
	void sendsecure(CompanyZ& company) {

		company.sendSecureMessage();
	}
		
};

template<typename T>
class LogMessage : public MessageSend<T>
{
   public: 
	   void sendsecureLog(T& company) {

		   cout << " Log start " << endl;
		   this->sendsecure(company);
	   }

	   void sendUnsecurelog(T &company) {

		   cout << " Log start " << endl;
		   this->sendUnsecure(company);
	   }


};


int main() {

	CompanyZ a;
	LogMessage<CompanyZ> msg;

	msg.sendsecureLog(a);
	//msg.sendUnsecurelog(a);
}





