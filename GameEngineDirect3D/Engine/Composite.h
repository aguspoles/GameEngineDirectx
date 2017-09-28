#pragma once
#include <vector>
#include "Component.h"
#include "Transform.h"

using namespace std;

class ENGINE_API Composite : public Component
{
private:
	Transform* _transform;
	vector<Component*> _components;

	template<class T> void GetComponentsInParent(vector<T*>*);
	template<class T> void GetComponentsInChildren(vector<T*>*);
protected:
	virtual void UpdateComposite() = 0;
	virtual void RenderComposite() = 0;
public:
	Composite();
	~Composite();

	void Add(Component* component);
	void Remove(Component* component);
	void Update() override final;
	void Render() override final;
	template<class T> T* GetComponent();
	template<class T> T* GetComponentInChildren();
	template<class T> T* GetComponentInParent();
	template<class T> vector<T*>* GetComponentsInParent();
	template<class T> vector<T*>* GetComponentsInChildren();

	Transform* GetTransform();
};

template<class T>
inline T* Composite::GetComponent()
{
	for (size_t i = 0; i < _components.size(); i++)
	{
		T* comp = dynamic_cast<T*>(_components[i]);
		if (comp != nullptr) return comp;
	}

	return nullptr;
}

template<class T>
inline T * Composite::GetComponentInChildren()
{
	T* comp = dynamic_cast<T*>(this);
	if (comp) return comp;

	for (size_t i = 0; i < _components.size(); i++)
	{
		Component* child = _components[i];
		Composite* compositeChild = dynamic_cast<Composite*>(child);
		if (compositeChild)
		{
			T* childComp = compositeChild->GetComponentInChildren<T>();
			if (childComp) return childComp;
		}
		else
		{
			T* childComp = dynamic_cast<T*>(child);
			if (childComp) return childComp;
		}
	}

	return nullptr;
}

template<class T>
inline T * Composite::GetComponentInParent()
{
	T* comp = dynamic_cast<T*>(this);

	//Verifico si yo soy el tipo que esta buscando
	if (comp != nullptr)
	{
		return comp;
	}
	//Si no verifico si tengo padre para preguntarle a el
	else if (GetParent() != nullptr)
	{
		return GetParent()->GetComponentInParent<T>();
	}
	//Si no no esta lo que se esta buscando
	else
	{
		return nullptr;
	}
}

template<class T>
inline vector<T*>* Composite::GetComponentsInParent()
{
	vector<T*>* vec = new vector<T*>();
	GetComponentsInParent<T*>(vec);
	return vec;
}

template<class T>
inline vector<T*>* Composite::GetComponentsInChildren()
{
	vector<T*>* vec = new vector<T*>();
	GetComponentsInChildren<T*>(vec);
	return vec;
}

template<class T>
inline void Composite::GetComponentsInParent(vector<T*>* vec)
{
	T* comp = dynamic_cast<T*>(this);
	if (comp) vec->push_back(comp);
	if (GetParent()) GetParent()->GetComponentsInParent(vec);
}

template<class T>
inline void Composite::GetComponentsInChildren(vector<T*>* vec)
{
	T* comp = dynamic_cast<T*>(this);
	if (comp) vec->push_back(comp);
	if (GetChildren()) GetChildren()->GetComponentsInChildren(vec);
}


/*
template<class T>
inline vector<T*>* Composite::GetComponentsInParent()
{
vector<T*>* vec = new vector<T*>();
Composite* current = this;
while (current)
{
T* comp = dynamic_cast<T*>(current);
if (comp) vec->push_back(comp);
current = current->GetParent();
}
return vec;
}*/