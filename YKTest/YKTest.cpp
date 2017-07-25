// YKTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "../YKTestModel/ModelImp.h"

//string literals
const char* menu_message="MENU\n====\n[1] Create task \n[2] Edit task \n[3] Delete task \n[4] List all tasks \n[5] Show menu again \n[6] Exit ";
const char* menuselect_message = "\nSelect an option [1-6] > ";
const char* newtask_message = "Please enter a description for new task: ";
const char* taskselect_message = "Please select a task: ";
const char* taskedit_message = "Please enter a description for edited task: ";
const char* taskeditsuccess_message = "Edit successful ";
const char* taskeditfailure_message = "Edit failed ";
const char* taskdeletesuccess_message = "Delete successful ";
const char* taskdeletefailure_message = "Delete failed ";
const char* taskempty_message = "No tasks created yet ";

//controllers

void createTaskControl(IModel*& i_model)
{
	std::string desc;	
	std::cin >> desc;
	i_model->createTask(desc.c_str());
	desc.clear();
}

void selectTaskControl(int& o_index)
{	
	std::cin >> o_index;	
}

void editDescriptionControl(std::string& o_desc)
{		
	std::cin >> o_desc;
}

int editTaskControl(IModel*& i_model, int i_index, std::string i_desc)
{	
	return i_model->updateTask(i_index, i_desc.c_str());	
}

int deleteTaskControl(IModel*& i_model, int i_index)
{
	return i_model->deleteTask(i_index);
}

//views

void listMenuView()
{	
	std::cout << menu_message << std::endl;
	
}

void createTaskView(IModel*& i_model)
{
	std::cout << newtask_message;
	createTaskControl(i_model);
}

void editTaskView(IModel*& i_model)
{
	int index=0;
	std::string desc;
	std::cout << taskselect_message;				
	selectTaskControl(index);
	std::cout << taskedit_message;				
	editDescriptionControl(desc);
	if (editTaskControl(i_model, index, desc)==0)
		std::cout << taskeditsuccess_message;
	else
		std::cout << taskeditfailure_message;
	desc.clear();
}

void deleteTaskView(IModel*& i_model)
{
	int index=0;
	std::string desc;
	std::cout << taskselect_message;				
	selectTaskControl(index);	
	if (deleteTaskControl(i_model, index)==0)
		std::cout << taskdeletesuccess_message;
	else
		std::cout << taskdeletefailure_message;
	desc.clear();
}

void listAllTaskView(IModel*& i_model)
{
	unsigned int taskcount=0;
	i_model->getTaskCount(taskcount);
	if (taskcount==0)
	{
		std::cout << taskempty_message << std::endl;
	}
	else
	{
		for (unsigned int i=0; i < taskcount; ++i)
		{
			unsigned int maxbuf=255;
			char stringbuf[255] = {};		
			i_model->readTask(i, stringbuf, maxbuf);
			std::cout << "[" << i << "] " << stringbuf << std::endl;
		}
	}
	
}

//application loop

void runLoop(IModel*& i_model)
{
	unsigned int input;
	int index=0;
	std::string desc;
	
	listMenuView();
	do
	{		
		std::cout << menuselect_message;
		std::cin >> input;
		switch (input)
		{
		case 1: createTaskView(i_model);
				break;
		case 2: editTaskView(i_model);
				break;
		case 3: deleteTaskView(i_model);
				break;
		case 4: listAllTaskView(i_model);
				break;
		case 5: listMenuView();
				break;
		case 6: //exit loop
				break;

		default: break;
		}
		
	}
	while (input < 6);
	
}

//main program

int _tmain(int argc, _TCHAR* argv[])
{
	//treat console as the view and controller for convenience
	IModel* p_model = getModel();

	runLoop(p_model);

	delete p_model;
	return 0;
}



