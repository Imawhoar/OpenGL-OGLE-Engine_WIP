#pragma once

template<typename T>
class TSingleton
{
private:
	TSingleton() {}
protected:
	virtual ~TSingleton() {}

public:
	TSingleton(TSingleton const&) = delete;
	void operator=(TSingleton const&) = delete;

	static TSingleton& Instance()
	{
		static TSingleton singleton;
		return singleton;
	}
};