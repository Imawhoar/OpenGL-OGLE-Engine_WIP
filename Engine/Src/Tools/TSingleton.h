#include <memory>

template < typename T >
class TSingleton {
public:
    static T& Instance() {
        static const std::unique_ptr<T> instance{ new T{} };
        return *instance;
    }

    TSingleton(const TSingleton&) = delete;
    TSingleton& operator= (const TSingleton) = delete;

protected:
    TSingleton() {};
    virtual ~TSingleton() {}
};

