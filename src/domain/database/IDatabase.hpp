#ifndef IDATABASE_HPP
#define IDATABASE_HPP

class IDatabase  {
public :
    virtual ~IDatabase() = default;

    virtual int open() = 0;
    virtual int close() const = 0;
    virtual int execute(const char* sql_query) const = 0;
};

#endif //IDATABASE_HPP
