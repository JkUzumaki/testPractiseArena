#include<vector>
#include<iostream>

class NewSample
{
public:
// Remove these comments to make it compilable
NewSample()
{}
NewSample(const NewSample & obj)
{}
NewSample & operator=(const NewSample & obj)
{}
};
int main()
{
std::vector<NewSample> vecOfNewSample(2);
// It will create 2 Objects using default constructor and insert them in vector.
std::cout<<"vecOfNewSample Size = "<<vecOfNewSample.size()<<std::endl;
std::cout<<"vecOfNewSample Capacity = "<<vecOfNewSample.capacity()<<std::endl;
std::vector<NewSample> vecOfNewSample_2;
vecOfNewSample_2.reserve(2);
// It will make the capacity of vector to contain 2 objects.
// ALthough size will remain 2.
std::cout<<"vecOfNewSample_2 Size = "<<vecOfNewSample_2.size()<<std::endl;
std::cout<<"vecOfNewSample_2 Capacity = "<<vecOfNewSample_2.capacity()<<std::endl;
return 0;
}
