#pragma once

//Author Yussairi
//
//An interface to the actual implementation of a Model 
//that returns only the virtual pointer to the object
//using abstract creational pattern.
//Client code need only this header and the .lib/.a file
//of the dynamic library. As long as this header is not changed,
//client code does not need to be rebuilt
class IModel
{
public:
	
	virtual ~IModel(){};
	//create task with an unspaced text i_description
	virtual void createTask(const char* i_description)=0;
	//get the description of task at index i_taskindex, with string size capped at i_bufsize
	virtual int readTask(unsigned int i_taskIndex, char* o_description, unsigned int i_bufsize)=0;
	//update the description of task at index i_taskindex, using new text i_new_description
	virtual int updateTask(unsigned int i_taskIndex, const char* i_new_description)=0;
	//delete task at index i_taskindex
	virtual int deleteTask(unsigned int i_taskIndex)=0;
	//get the total number of tasks created so far
	virtual void getTaskCount(unsigned int& o_size)=0;
	 
};

//Export the creator/getter function
#ifndef WIN32
//for Unix-like platforms (gcc, clang, etc)
//Realize interface from IModel
//using new operator.
extern "C" __attribute__((visibility("default"))) IModel* getModel();
#else
//for Windows (msvc)
//Realize interface from IModel using new operator. 
//Use delete on object when no longer needed
extern "C" _declspec(dllexport) IModel* getModel();
#endif

