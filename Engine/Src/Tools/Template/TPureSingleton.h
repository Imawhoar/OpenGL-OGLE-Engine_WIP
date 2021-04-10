#include <memory>

namespace OGLE::Template {

    template < typename T >
    class TPureSingleton {
    public:
        static T& Instance() {
            static const std::unique_ptr<T> instance{ new T{} };
            return *instance;
        }

        TPureSingleton(const TPureSingleton&) = delete;
        TPureSingleton& operator= (const TPureSingleton) = delete;

    protected:
        TPureSingleton() {};
        virtual ~TPureSingleton() {}
    };

}