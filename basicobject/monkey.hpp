#include "../object.hpp"
#include "importedobj.hpp"
class monkey: public  ImportedObj{
public:
    monkey():ImportedObj("monkey.obj"){};
};
