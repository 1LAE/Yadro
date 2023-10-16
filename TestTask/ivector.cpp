# include <vector>

using namespace std;

template <typename T>
        class iVector : vector<T>{

            private:
                int ifrom;
            
            public:

                iVector(int from){
                    this->ifrom = from;
                }

                iVector(){
                    this->ifrom = 0;
                }

                iVector(int size, int from){
                    this->ifrom = from;
                    this->vector<T>::resize(size);
                }

                iVector(int size, T value, int from){
                    this->ifrom = from;
                    this->vector<T>::resize(size, value);
                }

                T& operator[](int i){
                    return this->at(i - (2 * this->ifrom));
                };

                void reshape(int new_from){
                    this->ifrom = new_from;
                }

                void resize(int count, T value){
                    for(int i = 0; i < count; i++)
                        this->push_back(value);
                }

                void push_back(T x){
                    this->vector<T>::push_back(x);
                }

                size_t size(){
                    return this->vector<T>::size();
                }

                typename vector<T>::iterator begin(){
                    return this->vector<T>::begin();
                }

                typename vector<T>::iterator end(){
                    return this->vector<T>::end();
                }    
        };