#include <iostream>
#include <string>

class person {
private:
	double height;
	double weight;
	int age;
	double bmr;
	double tdee;
	int activityLevel;

public:
	std::string name;


	void setHeight(double x) {
		height = x * 30.48;
	}

	double getHeight() {
		return height;
	}

	void setWeight(double w) {
		weight = w * 0.453592;
	}

	double getWeight() {
		return weight;
	}

	void setAge(int a) {
		age = a;
	}

	int getAge() {
		return age;
	}

	void setBasalMetabolicRate() {
		bmr = 88.362 + (13.397 * getWeight()) + (4.799 * getHeight()) - (5.677 * getAge());
	}

	double getBasalMetabolicRate() {
		return bmr;
	}


	void setActivity(int i) {
		switch (i) {
		case 1:
			tdee = getBasalMetabolicRate() * 1.2;
			break;

		case 2:
			tdee = getBasalMetabolicRate() * 1.375;
			break;

		case 3:
			tdee = getBasalMetabolicRate() * 1.55;
			break;

		case 4:
			tdee = getBasalMetabolicRate() * 1.725;
			break;

		case 5:
			tdee = getBasalMetabolicRate() * 1.9;
			break;

		default:
			std::cout << "\nInvalid choice. Assuming sedentary.\n";
			tdee = getBasalMetabolicRate() * 1.2;
			break;
		}
	}
	double getTdee() {
		return tdee;
	}


};

void ActivityQuestions() {
	std::cout << "\nGreat, how active are you?\n\nOptions: \n" <<
		"1. Sedentary (little or no exercise)\n" <<
		"2. Lightly active(light exercise / sports 1 - 3 days / week)\n" <<
		"3. Moderately active (moderate exercise/sports 3-5 days/week)\n" <<
		"4. Very active (hard exercise/sports 6-7 days a week)\n" << std::endl;
}


int main()
{
	person p1;

	std::cout << "Hello!\tWelcome to the Easy Weight Loss calculator program!\n\nThis program will begin with a couple personal questions..." << std::endl;

	std::cout << "\nWhat is your name?" << std::endl;
	std::getline(std::cin, p1.name);

	std::cout << "What is your height? (ex. 5.8 / 6.1)" << std::endl;
	double height;
	std::cin >> height;
	p1.setHeight(height);

	std::cout << "What is your weight? (ex. 180.00 / 178.46)" << std::endl;
	double weight;
	std::cin >> weight;
	p1.setWeight(weight);

	std::cout << "What is your age?" << std::endl;
	int age;
	std::cin >> age;
	p1.setAge(age);
	std::cout << "\n\nThank you for that information!\n" << std::endl;

	//Preliminary Report Display:
	std::cout << "\t\tReport\t\t" << std::endl;
	std::cout << "\n\nName: " << p1.name << std::endl;
	std::cout << "\nHeight: " << height << " feet" << std::endl;
	std::cout << "\nWeight: " << weight << " pounds" << std::endl;
	std::cout << "\nAge: " << p1.getAge() << std::endl;

	p1.setBasalMetabolicRate();
	ActivityQuestions();

	int input;
	std::cin >> input;
	p1.setActivity(input);

	//Final Report Display:
	double calorieGoal = p1.getTdee() - 500;
	std::cout << "\t\tFinal Report\t\t" << std::endl;
	std::cout << "\nBasal Metabolic Rate: " << p1.getBasalMetabolicRate() << " (Needed calories for basic life sustaining functions)" <<
		"\nTotal Daily Energy Expenditure: " << p1.getTdee() << " (Amount of calories you burn every day)" <<
		"\n\nA healthy estimate for calorie intake is: " << calorieGoal << " calories a day to lose 1 pound a week. " << std::endl;

	return 0;
}