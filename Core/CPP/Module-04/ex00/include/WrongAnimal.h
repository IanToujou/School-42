#ifndef WRONGANIMAL_H

# define WRONGANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	explicit WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	virtual ~WrongAnimal();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif