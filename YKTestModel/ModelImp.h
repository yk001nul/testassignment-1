#pragma once
#include "IModel.h"
#include <vector>
//Author Yussairi
//
//The actual implementation of a Model 
class ModelImp: public IModel
{
private:
	std::vector<std::string> m_tasks;
public:
	ModelImp();
	~ModelImp();
	void createTask(const char* i_description);
	int readTask(unsigned int i_taskIndex, char* o_description, unsigned int i_bufsize);
	int updateTask(unsigned int i_taskIndex, const char* i_new_description);
	int deleteTask(unsigned int i_taskIndex);
	void getTaskCount(unsigned int& o_size);
};

