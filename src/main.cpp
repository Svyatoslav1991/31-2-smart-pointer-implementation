#include <iostream>
#include <dog.h>

int main() {
	std::cout << "\tTASK 31.2 SMART POINTER IMPLEMENTATION\n\n";

	try
	{
		shared_ptr_toy toy = make_shared_toy("bone");

		Dog dog1("Fluffy", toy, 5);
		Dog dog2("Snowball");

		dog2.copyLovelyToy(dog1);

		shared_ptr_toy retrievedToy;
		dog2.getToy(retrievedToy);

		std::cout << dog2.getName() << "'s toy is " << retrievedToy.getName() << "\n";

		dog2.dropToy();

		shared_ptr_toy emptyToy;
		dog2.getToy(emptyToy);

		std::cout << dog2.getName() << "'s toy is " << emptyToy.getName() << "\n\n";

		std::cout << "---------------------------------------------------------------------------\n\n";

		shared_ptr_toy ball = make_shared_toy("ball");
		shared_ptr_toy ball1 = make_shared_toy(ball);
		shared_ptr_toy ball2 = ball;
		shared_ptr_toy ball3(ball);

		std::cout << ball.getName() << " = " << ball.use_count() << "\n";

		ball1.reset();

		std::cout << ball.getName() << " = " << ball.use_count() << "\n";

		ball2.reset();

		std::cout << ball.getName() << " = " << ball.use_count() << "\n";

		ball3.reset();

		std::cout << ball.getName() << " = " << ball.use_count() << "\n";

		ball.reset();

		std::cout << ball.getName() << " = " << ball.use_count() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what();
	}
	catch (...)
	{
		std::cout << "Something went wrong\n";
	}

	return 0;
}