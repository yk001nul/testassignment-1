#include "stdafx.h"
#include "ModelImp.h"

//Realize interface from IModel
//using new operator.
//Client code need to delete the
//object manually
IModel* getModel()
{
	return new ModelImp();
}


ModelImp::ModelImp()
{
}

ModelImp::~ModelImp()
{
	for (unsigned int i=0; i < m_tasks.size(); ++i)
		m_tasks[i].clear();
	m_tasks.clear();
}

void ModelImp::createTask(const char* i_description)
{
	m_tasks.push_back(std::string(i_description));
}

int ModelImp::readTask(unsigned int i_taskIndex, char* o_description, unsigned int i_bufsize)
{
	if (i_taskIndex >= 0 && i_taskIndex < m_tasks.size())
	{
		strcat_s(o_description,i_bufsize,m_tasks[i_taskIndex].c_str());
		return 0;
	}
	else
	{
		return 1;
	}
}

int ModelImp::updateTask(unsigned int i_taskIndex, const char* i_new_description)
{
	if (i_taskIndex >= 0 && i_taskIndex < m_tasks.size())
	{
		m_tasks[i_taskIndex].replace(m_tasks[i_taskIndex].begin(), m_tasks[i_taskIndex].end(),i_new_description);
		return 0;
	}
	else
	{
		return 1;
	}
}

int ModelImp::deleteTask(unsigned int i_taskIndex)
{
	if (i_taskIndex >= 0 && i_taskIndex < m_tasks.size())
	{
		m_tasks.erase(m_tasks.begin()+i_taskIndex);
		return 0;
	}
	else
	{
		return 1;
	}
}

void ModelImp::getTaskCount(unsigned int& o_size)
{
	o_size = m_tasks.size();
}