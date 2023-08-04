#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		~AAnimal();

		AAnimal &		operator=( AAnimal const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************* AANIMAL_H */